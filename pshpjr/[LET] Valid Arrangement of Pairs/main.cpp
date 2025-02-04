class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //패어를 방향 엣지로 생각하고 인접 리스트를 만듬.
        //이 때 숫자 범위가 크고, 페어의 개수는 작으니까 맵을 씀
        for(auto& v : pairs)
        {
            outDegree[v[0]]++;
            inDegree[v[1]]++;
            graph[v[0]].push_back(v[1]);
        }

        //유클리드 경로 탐색 알고리즘을 사용
        //시작 노드 탐색
        int start = 0;

        for (const auto& [key, value] : graph) {
            if (outDegree[key] - inDegree[key] == 1) {
                start = key;
                break;
            }

            if (outDegree[key] > 0)
                start = key;
        }

        stack<int> st;
        vector<int> seq;
        st.push(start);

        while(!st.empty())
        {
            int cur = st.top();

            if(graph[cur].empty())
            {
                st.pop();
                seq.push_back(cur);
                continue;
            }

            int next = graph[cur].back();
            graph[cur].pop_back();
            st.push(next);
        }

        reverse(seq.begin(),seq.end());

        vector<vector<int>> ret;
        int iter = seq.size()-1;
        for(int i = 0; i< iter; i++)
        {
            ret.push_back({seq[i],seq[i+1]});
        }

        return ret;
    }

    unordered_map<int,vector<int>> graph;
    unordered_map<int,int> inDegree;
    unordered_map<int,int> outDegree;
};

/*각 인덱스의 페어를 노드로 두고, 시작값 노드, 끝값 노드랑 연결됨. 방향 있음. 
a로 시작하는 노드들 / b로 끝나는 노드들 만들고
인접 리스트로 만들고

ㄴㄴ

각 페어를 엣지로 보고 처리

오일러 경로와 해밀턴 경로
오일러 경로는 쉽게 풀 수 있지만, 해밀턴 경로는 np 완전 문제
*/