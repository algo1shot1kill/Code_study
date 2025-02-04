#include <ranges>

struct DisjointSet {
  DisjointSet* parent = this;
  int size = 1;
};

DisjointSet& find(DisjointSet& x) {
  auto px = &x;
  while (px != px->parent) {
    tie(px, px->parent) = make_pair(px->parent, px->parent->parent);
  }
  return *px;
}

void unify(DisjointSet& x, DisjointSet& y) {
  auto px = &find(x);
  auto py = &find(y);
  if (px == py) return;
  if (py->size > px->size) swap(px, py);
  px->size += py->size;
  py->parent = px;
}


/*
그래프로 보고, 각 자리의 유니온 파인드 진행
-> 자동으로 연결되지 않은 애들이 구별됨
일반적인 배열이 아니라 포인터 형태 사용.
-> 배열 사용도 가능하겠지만, 코드가 복잡해진다. 


 */

class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = size(grid);
    //전부 1인 경우. 
    if (ranges::all_of(grid | views::join, identity{})) return n * n;


    auto nodes = vector<vector<DisjointSet>>(n);
    for (auto& row : nodes) row.resize(n);
    //views::enumerate 하면 index , value 형태의 튜플을 리턴. 
    for (auto [i, row] : grid | views::enumerate) {
      for (auto [j, cell] : row | views::enumerate) {
        if (!cell) continue;
        //좌상단에서 우하단으로 가므로, 섬을 판별할 때 오른쪽이랑 아래만 보면 됨. 
        if (i < n - 1 && grid[i + 1][j]) unify(nodes[i][j], nodes[i + 1][j]);
        if (j < n - 1 && grid[i][j + 1]) unify(nodes[i][j], nodes[i][j + 1]);
      }
    }

    //set 쓰는 거 보다 vector 쓰는 게 더 빠를지도
    //매번 순차 탐색 후 있는지 확인함. 
    auto cc_nodes = vector<DisjointSet*>{};
    auto push_unique_node = [&cc_nodes](DisjointSet& node) {
      auto pnode = &node;
      if (!ranges::contains(cc_nodes, pnode)) cc_nodes.push_back(pnode);
    };

    auto max_size = 1;
    for (auto [i, row] : grid | views::enumerate) {
      for (auto [j, cell] : row | views::enumerate) {
        //빈 공간의 상하좌우를 탐색하는 형태. 이게 더 효율적이다.
        if (cell) continue;
        // cout << "at (" << i << ", " << j << ")\n";
        cc_nodes.clear();
        if (i > 0 && grid[i - 1][j]) push_unique_node(find(nodes[i - 1][j]));
        if (i < n - 1 && grid[i + 1][j]) push_unique_node(find(nodes[i + 1][j]));
        if (j > 0 && grid[i][j - 1]) push_unique_node(find(nodes[i][j - 1]));
        if (j < n - 1 && grid[i][j + 1]) push_unique_node(find(nodes[i][j + 1]));
        auto size_if_joined = 1;
        for (auto pnode : cc_nodes) size_if_joined += pnode->size;
        // cout << "size_if_joined: " << size_if_joined << '\n';
        if (size_if_joined > max_size) max_size = size_if_joined;
      }
    }
    return max_size;
  }
};