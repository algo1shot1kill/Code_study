[Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/?envType=study-plan-v2&envId=top-sql-50)
---
## 문제 설명
---
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
 

Write a solution to find managers with at least five direct reports.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |
+------+

## 문제 유형

조인?

## 아이디어

1. 시키는데로 하기

### 실수한 포인트
- 최적화된 답 이해가 안 갔었는데, 어떻게 group by 한 후에 다른 컬럼 값을 쓸 수 있지? 였음
- mysql만 가능한데, 다른 컬럼 값 가지고 오면 group 중에 아무거나 하나 튀어나온다고 함
- 지금 같은 경우 group으로 묶어도 b 테이블은 전부 같은 데이터라 상관 없음.  
