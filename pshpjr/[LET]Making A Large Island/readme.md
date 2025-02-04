[Making A Large Island](https://leetcode.com/problems/making-a-large-island/description/?envType=daily-question&envId=2025-01-31)
---
## 문제 설명
---
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.

 
## 문제 유형

그래프 / dfs

## 아이디어

1. 0주변부터 퍼져나가면서 탐색
2. 각각의 섬 주변을 깊이 2까지 탐색해서 섬이랑 만나는지 확인

### 실수한 포인트
- 전부 0인 케이스 생각 못 함. 전부 1인거 추가할 때 왜 안 넣었지
- disjointSet 쓰는 최적화된 해법도 참조할 것. 
