class Solution {
    //value, y,x;
    using cell = pair<int,int>;
    queue<cell> q;

    vector<pair<int,int>> delta = {{0,-1},{-1,0},{0,1},{1,0}};

    void findNext(vector<vector<int>>& isWater,int y, int x)
    {
        int v = isWater[y][x];

        for(auto d : delta)
        {
            auto ny = y + d.first;
            auto nx = x + d.second;

            if(ny <0 || ny >= isWater.size() || nx < 0 || nx >= isWater[0].size())
            {
                continue;
            }

            if(isWater[ny][nx] == -1)
            {
                isWater[ny][nx] = v+1;
                q.push({ny,nx});
            }
        }
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        for(int i = 0; i<isWater.size();i++)
        {
            for(int j = 0; j < isWater[0].size();j++)
            {
                if(isWater[i][j] == 1)
                {
                    isWater[i][j] = 0;
                    q.push({i,j});
                }
                else
                {
                    isWater[i][j] = -1;
                }
            }
        }

        while(!q.empty())
        {
            auto [y,x] = q.front();
            q.pop();
            findNext(isWater,y,x);
        }
        return isWater;
    }
};