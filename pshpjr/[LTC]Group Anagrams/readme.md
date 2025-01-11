[Group Anagrams](https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/778/)
---
## 문제 설명
---
Given an array of strings strs, group the anagrams together. You can return the answer in **any order**.  

## Examples
### 1
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

### 2
Input: strs = [""]

Output: [[""]]

### 3
Input: strs = ["a"]

Output: [["a"]]

## 문제 유형

정렬?

## 아이디어

1. 주어진 문자열을 정렬한 값을 키로 HashMap에 저장
2. 10000 * 100개의 문자열. 비용은 정렬에 nlogn + 해싱 함수
3. 문자열 길이나 입력이 작아서 충분해 보임

### 주의할 점
- 문자열 해싱은 문자열 길이에 비례해서 증가함. 만약 문자열이 엄청 긴 입력이라면, 시간 초과 가능성  
- 근데 방법이 있나?
- 알파벳 카운팅한 배열을 키로 쓸 순 있을 것 같은데, 이게 더 빠를지는 모르겠음
