class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        
        priority_queue<int> fishGroup;

        for(int i = 0; i<grid.size();i++)
        {
            for (int j = 0; j<grid[0].size();j++)
            {
                if(grid[i][j] != 0)
                {
                    fishGroup.push(calculateCatchableFish(i,j,grid));
                }
            }
        }

        return fishGroup.size() == 0? 0 :fishGroup.top();
    }

    vector<pair<int,int>> delta = {{0,-1},{-1,0},{0,1},{1,0}};

    int calculateCatchableFish(int y, int x,vector<vector<int>>& grid)
    {
        int sum = grid[y][x];
        grid[y][x] = 0;

        for(auto [dy,dx] : delta)
        {
            int cy = y+dy;
            int cx = x+dx;

            if(cy<0 || cy >= grid.size() || cx<0 || cx >=grid[0].size())
            {
                continue;
            }
            
            if(grid[cy][cx] == 0)
            {
                continue;
            }
            sum += calculateCatchableFish(cy,cx,grid);
        }
        return sum;
    }
};