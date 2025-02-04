class Solution {

    /*
    0~n까지 해당 인덱스에서 아래로 내려간다고 하자. 그러면 그때부터는 앞으로만 가야 함
    2번째 봇은 첫 줄 sum(grid[0][i+1],grid[0][n-1]), sum(grid[1][0], grid[1,i-1]); 
    
    
    */
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = accumulate(grid[0].begin()+1,grid[0].end(),0ll);
        long long bottom = 0;

        long long ret = top;
        auto n = grid[0].size();
        for(int i = 1; i<n;i++)
        {
            top -= grid[0][i];
            bottom += grid[1][i-1];
            auto curMax = max(top,bottom);
            ret = min(curMax,ret);
        }

        return ret;
    }
};