
#include <vector>
#include <iostream>
using namespace std;

// //각 블럭을 회전, 대칭 회전한 모든 모양의 오프셋을 배열에 넣는다. 
// //좌상단부터 탐색한다.

// //ret = 0;
// //for i :N
// // for j : M
// //  for offset : offsets
// //    sum = 0;
// //    for [y,x] : offset
// //      if(valid(i+y,j+x))
// //        sum+= map[i+y][j+x];
// //      else
// //        sum = -1;
// //        break
// //    ret = max(ret, sum);

int N;
int M;

bool valid(int y, int x)
{
    return (0<= y && y < N) && (0<= x && x < M);
}

// //오프셋은 그림에 보이는 기준으로 좌하단을 원점으로 잡고 시계방향으로 회전한다. 좌상단이 0,0
vector<vector<pair<int, int>>> offsets = {
    // I-Shape
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},   // Original
     {{0, 0}, {1, 0}, {2, 0}, {3, 0}},   // 90 
     {{0, 0}, {0, -1}, {0, -2}, {0, -3}},   // 180 
     {{0, 0}, {-1, 0}, {-2, 0}, {-3, 0}},  // 270 

    // O-Shape
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},   // Original

    // L-Shape
    {{0, 0}, {-1, 0}, {-2, 0}, {0, 1}},   // Original
     {{0, 0}, {1, 0}, {0, 1}, {0, 2}},  // 90 degrees
     {{0, 0}, {0, -1}, {1, 0}, {2, 0}},   // 180 degrees
     {{0, 0}, {-1, 0}, {0, -1}, {0, -2}},  // 270 degrees

    // J-Shape
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}},   // Original
     {{0, 0}, {1, 0}, {1, 1}, {1, 2}},   // 90 degrees
     {{0, 0}, {0, -1}, {1, -1}, {2, -1}},   // 180 degrees
     {{0, 0}, {-1, 0}, {-1, -1}, {-1, -2}},  // 270 degrees

    // S-Shape
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},   // Original
     {{0, 0}, {0, -1}, {1, -1}, {1, -2}},   // 90 degrees
     {{0, 0}, {-1, 0}, {-1, -1}, {-2, -1}},   // 180 degrees (same as original)
     {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},  // 270 degrees (same as 90 degrees)

    // Z-Shape
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},   // Original
     {{0, 0}, {0, -1}, {-1, -1}, {-1, -2}},   // 90 degrees
     {{0, 0}, {-1, 0}, {-1, 1}, {-2, 1}},   // 180 degrees (same as original)
     {{0, 0}, {0, 1}, {1, 1}, {1, 2}},  // 270 degrees (same as 90 degrees)

    // T-Shape
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},   // Original
     {{0, 0}, {1, 0}, {2, 0}, {1, -1}},   // 90 degrees
     {{0, 0}, {0, -1}, {0, -2}, {-1, -1}},   // 180 degrees
     {{0, 0}, {-1, 0}, {-2, 0}, {-1, 1}}   // 270 degrees
};


int main ()
{
    cin >> N >> M;
    vector<vector<int>> map(N,vector<int>(M));

    for( auto& v : map)
    {
        for(auto& cell : v)
        {
            cin >> cell;
        }
    }

    int ret = 0;
    for(int i = 0; i< N;i++)
    {
        for (int j = 0; j< M;j ++)
        {
            for(auto& offset : offsets)
            {
                int sum = 0;
                for(auto delta : offset)
                {
                    auto [y,x] = delta;

                    if(valid(i+y, j+x))
                    {
                        sum += map[i+y][j+x];
                    }
                    else
                    {
                        sum = -1;
                        break;
                    }
                }
                ret = std::max(ret,sum);
            }
        }
    }

    return ret;


}
