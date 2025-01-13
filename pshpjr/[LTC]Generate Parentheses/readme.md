[Generate Parentheses](https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/794/)
---
## 문제 설명
---
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

## 문제 유형

백트래킹

## 아이디어

1. 처음에는 모든 경우의 수 다 만들어서 check 함수 통과하는 애들만 넣을 생각
2. check 함수 처음에는 스택으로 구현
3. 열린 개수만 알면 되겠다 싶어서 열린 개수만 저장하게 수정
4. 어떻게 모든 경우의 수를 다 만들지? -> 재귀 함수에 남은 open, close를 넘겨줘야 함
5. 어짜피 넘겨줄거면 well-formed한 거 바로 만들 수 있다

### 주의할 점
- 지금 구현은 string자체를 넘겨주는데, bitset 써서 좀 더 최적화 가능할듯 (N <= 8)
