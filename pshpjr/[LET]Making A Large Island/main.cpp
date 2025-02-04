class Solution {
public:
    //전체를 돌면서 섬들을 찾고, 크기를 전부 저장한다. 
    //maxElem에 최대값을 저장한다. 
    //저장 후 전체를 돌면서, 섬을 만나면 dfs로 두 칸 탐색해서 나와 다른 섬을 찾는다.
    //  하나의 다리로 두 개 이상의 섬을 연결할 수 있을 수 있다. (십자 모양)
    //  만드는 다리에 같은 섬이 여러 번 연결될 수 있는데, dfs는 이걸 모른다. 
    //  bfs로 수정.
    //  한 다리는 최대 3개 섬이랑 연결 가능하니까 bfs + 튜플 
    //두 섬의 합을 max와 비교한다. 
    int largestIsland(vector<vector<int>>& grid) {
        grid_ = std::move(grid);
        findAllIsland();

        int ret = *max_element(islandSizes.begin(), islandSizes.end());

        for(int i = 0; i< grid_.size();i++)
        {
            for(int j = 0; j< grid_[0].size();j++)
            {
                if(isValid(i,j) && grid_[i][j] != 0)
                {
                    ret = max(ret,findNearbyIsland(i,j));
                }
            }
        }
        ret = max(ret,1);
        return ret;
    }

    //해당 위치에서 다리를 만들 경우 생기는 가장 큰 섬의 크기를 리턴
    int findNearbyIsland(int y, int x)
    {
        auto& Grid = grid_;
        int cur = Grid[y][x];
        int ret = islandSizes[cur];

        //해당 위치 주위의 빈 공간을 추가
        for(auto [dy,dx] : delta)
        {
            int ny = dy + y;
            int nx = dx + x;
            if(isValid(ny, nx) && Grid[ny][nx] != cur)
            {
                q.push({ny,nx});
            }
        }
        //다리를 놓을 가능성이 없다면 그냥 지금 섬의 크기 리턴
        if(q.empty())
        {
            return ret;
        }
        //다리 만들 수 있으면 크기 1 늘어남. 
        ret+=1;
        //빈 공간들에서 사방을 탐색하며 해당 위치에 다리를 놨을 때 연결되는 섬이 있는지 확인
        int lgstIsland = 0;
        while(!q.empty())
        {
            auto [y,x] = q.front(); q.pop();
            set<int> islands;
            for(auto [dy,dx] : delta)
            {
                int ny = dy + y;
                int nx = dx + x;
                //다른 섬을 만나면
                if(isValid(ny, nx) && Grid[ny][nx] != cur && Grid[ny][nx] != 0)
                {
                    islands.insert(Grid[ny][nx]);
                }
            }

            int sum = 0;
            for(auto i : islands)
            {
                sum += islandSizes[i];
            }
            lgstIsland = max(lgstIsland, sum);
        }
        return ret + lgstIsland;
    }

    void findAllIsland(){
        auto& Grid = grid_;
        int islandCount = 2; //섬이 1로 칠해지니까 2부터 시작
        function<int(int,int)> dfs = 
        [&](int y, int x)
        {
            int ret = 1;
            for(auto [dy,dx] : delta)
            {
                int ny = dy + y;
                int nx = dx + x;
                if(isValid(ny, nx) && Grid[ny][nx] != 0 && Grid[ny][nx] != islandCount)
                {
                    Grid[ny][nx] = islandCount;
                    ret += dfs(ny,nx);
                }
            }
            return ret;
        };

        for(int i = 0; i<Grid.size();i++)
        {
            for(int j = 0; j<Grid[0].size();j++)
            {
                if(Grid[i][j] == 1)
                {
                    Grid[i][j] = islandCount;
                    islandSizes.push_back(dfs(i,j));
                    ++islandCount;
                }
            }
        }        
    }

    // 섬인가?
    bool isValid(int y, int x)
    {
        return 0<=y && y < grid_.size() && 0<=x && x< grid_[0].size();
    }
    vector<vector<int>> grid_;
    vector<int> islandSizes = {0,0};
    queue<pair<int,int>> q;
    vector<pair<int,int>> delta = {{0,-1},{-1,0},{0,1},{1,0}};
    set<int> connected;
};