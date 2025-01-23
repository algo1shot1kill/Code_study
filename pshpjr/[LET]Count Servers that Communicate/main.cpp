class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        /*좌상단부터 가로 세로 쭉 이동하면서 1을 만나면 find flag 키고, 해당 위치 값도 1 증가
        find true 일 경우 나도 1 추가
        더 줄일 방법이 있나?

        모든 배열을 순회한다.
        각 위치에서 나 빼고 1 이상인 값을 찾는다.
        찾았다면 1증가, find true

        */
        auto check = [grid](int y, int x){
            for(int i = 0; i< grid[0].size();i++)
            {
                if(grid[y][i] > 0 && x != i)
                {
                    return true;
                }
            }

            for(int i = 0; i< grid.size();i++)
            {
                if(grid[i][x] > 0 && y != i)
                {
                    return true;
                }
            }
            return false;
        };

        int ret = 0;
        for(int i =0; i< grid.size();i++)
        {
            for(int j = 0; j< grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                {
                    continue;
                }

                if(check(i,j))
                {
                    ret++;
                }
            }
        }

        return ret;
    }

    
};