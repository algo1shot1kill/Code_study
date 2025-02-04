# Write your MySQL query statement below
WITH fdr (managerId) AS (
    SELECT managerId FROM Employee
    GROUP BY managerId
    HAVING count(*) >= 5
)
SELECT name
FROM fdr
JOIN Employee ON fdr.managerId = Employee.id;

# 빠른 코드
# b 값을 기준으로 묶었으니까 맨 위에 있는 name은 걔 것이다?
SELECT b.name
FROM Employee a
JOIN Employee b ON a.managerId = b.id
GROUP BY b.id
HAVING COUNT(*) >= 5;