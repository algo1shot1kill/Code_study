[Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23)
---
## 문제 설명
---
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 

Example 1:



Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
Example 2:



Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
Example 3:



Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
 


## 문제 유형

완전탐색


## 아이디어

1. 쭉 돌면서 각 위치의 서버가 연결되어 있는지 확인 후 카운팅

### 실수한 포인트

주석으로 작성할 때 자기 자신 무시나, 서버 없는 그리드 무시 같은 처리를 생각하지 못함