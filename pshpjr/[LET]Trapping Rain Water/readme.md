[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/)
---
## 문제 설명
---
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

## 문제 유형

스택

## 아이디어

1. 임의의 두 막대 사이가 전부 자기보다 작다면 (min(왼h, 오h) - 작은 애들 중 가장 큰 애) * 거리 만큼은 전부 물이다. 
2. 넷마블 막대 쌓는 문제 리버스 버전이구나
### 주의할 점
- 히스토그램도 그렇고 스택에서 값 하나 빼고, 걔가 왼쪽, 오른쪽은 지금 값, 뺀 값 이렇게 세 개 가지고 뭔가 하는 듯.
- 뺀 애 위로 얼마나 쌓이나 생각했었는데, 왼쪽으로 얼마나 물인지 보는 거임. 
- 어렵다. GPT한테 힌트 달라고 함