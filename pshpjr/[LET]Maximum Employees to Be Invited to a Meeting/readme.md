[Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/?envType=daily-question&envId=2025-01-26)
---
## 문제 설명
---
A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

## 문제 유형

dfs

## 아이디어

1. 모든 사이클을 찾는다. 
2. 크기가 3 이상인 경우에는 그 사이클만 선택할 수 있다. 
3. 크기가 2 인 사이클은 연결되는 가지도 추가할 수 있다. 
4. 노드당 연결할 수 있는 가지 중 가장 긴 것들 + 2가 크기 2인 사이클로 만들 수 있는 최장 관계
5. 4에서 구한 것들의 합. 4에서 구한 애들은 여러 개 선택해도 문제가 없다. 
6. 2와 5중 더 큰값값

### 실수한 포인트
- 풀이 안 보면 못 풀었을 듯. 사이클까진 생각했는데, 2짜리 처리할 생각이 안 났음
- 사이클을 엄청 비효율적으로 찾았음. 진입 차수로 사이클 구하는 거 옛날에 풀었었는데, 왜 생각 못함?
- 진입차수 0인 애들부터 쭉 처리하면 사이클도 찾고, 사이클에 있는 애들로 들어오는 가지 수도 구해짐
  - 이 때 depth[next] = max(depth[next],myDegree+1);
  - 아래처럼 while로 밀면서 사이클 찾기. 이 문제의 그래프는 사이클 1개와 가지로 연결된 그래프들의 묶음임.
```cpp
    while (inDegree[current] != 0) {
        inDegree[current] = 0;  // Mark as visited
        cycleLength++;
        current = favorite[current];
    }

```
