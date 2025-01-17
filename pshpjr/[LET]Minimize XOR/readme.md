[Minimize XOR](https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15)
---
## 문제 설명
---
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.

## 문제 유형

비트 조작

## 아이디어

1. 올라가면서 n1에 비트를 추가하거나 제거한다. 

### 실수한 포인트
- n1이 n2보다 항상 작다고 생각함. 반대의 경우 비트를 지우면 되는데 더하는 것만 생각함. 좀 더 생각해 볼 것
- 연산자 우선순위 때문에 한 번 틀림.
- 수도 코드 바탕으로 짜서 한 번에 맞아보고 싶다. 맨날 짜다 보면 다시 생각해야 함. 
- 이렇게 오래 걸릴 문제가 아님
