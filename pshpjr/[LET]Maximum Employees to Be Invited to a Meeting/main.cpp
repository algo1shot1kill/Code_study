class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        /*순회하면서 가장 긴 사이클을 찾는다. dfs로
        사이클이 생겼을 때 dfs 깊이를 각각 저장
        가장 긴 사이클 / 가장 긴 안 사이클 2개 비교
        
        1. 사이클의 크기를 어떻게 알아내지?
         사이클이 생기면, 깊이를 저장
         더 갈 곳이 없으면 깊이를 저장        
        */
        vector<vector<int>> reverseGraph(favorite.size());
        for(int i = 0; i< favorite.size();i++)
        {
            reverseGraph[favorite[i]].push_back(i);
        }
        int maxCycle = 0;

        vector<pair<int,int>> twoCycles;

//0 : nonVisit, 1 : visiting , 2: visited
        vector<char> state(favorite.size());
        vector<int> depth(favorite.size());

        function<void(int,int)> dfs
        = [&](int c, int d)
        {
            state[c] = 1;
            depth[c] = d;
            auto next = favorite[c];

            if(state[next] == 0)
            {
                dfs(next,d+1);
            }
            else if(state[next] == 1)
            {
                auto cycleDepth = d - depth[next] +1;
                if(cycleDepth == 2)
                {
                    twoCycles.push_back({c,next});
                }
                else
                {
                    maxCycle = max(maxCycle,cycleDepth);
                }
            }

            state[c] = 2;
        };

        function<int(int,int,int)> maxDepth
        = [&](int c,int d,int b)
        {
            if(reverseGraph[c].size() == 0)
            {
                return d;
            }

            int m = 0;

            for(auto n : reverseGraph[c])
            {
                if(n == b)
                {
                    continue;
                }

                m = max(m,maxDepth(n,d+1,b));
            }
            return m;
        };


        for(int i = 0; i < reverseGraph.size();i++)
        {
            if(state[i] == 0)
            {
                dfs(i,0);
            }
        }

        int cycleSum = 0;
        for(auto [a,b]: twoCycles)
        {
            cycleSum += maxDepth(a,0,b) + maxDepth(b,0,a) + 2;
        }
        maxCycle = max(maxCycle,cycleSum);
        return maxCycle;
    }
};