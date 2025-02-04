class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //0 미방분 1 방문 중 2 방문
        vector<char> state(graph.size());
        vector<bool> hasCycle(graph.size());

        function<bool(int)> dfs = [&](int cur)
        {
            state[cur] = 1;
            for(auto next : graph[cur])
            {
                if(state[next] == 1)
                {
                    hasCycle[next] = true;
                    hasCycle[cur] = true;

                    return true;
                }
                else if(state[next] == 0)
                {
                    if(dfs(next))
                    {
                        hasCycle[cur] = true;
                        return true;
                    }
                }
                else if(hasCycle[next])
                {
                    hasCycle[cur] = true;
                    return true;
                }
            }
            state[cur] = 2;
            return false;
        };

        for(int i = 0; i< hasCycle.size();i++)
        {
            if(state[i] != 2)
            {
                dfs(i);
            }
        }

        vector<int> ret;
        for(int i = 0; i< hasCycle.size();i++)
        {
            if(!hasCycle[i])
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};