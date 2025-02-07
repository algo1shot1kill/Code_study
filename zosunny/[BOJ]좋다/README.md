## [BOJ] 좋다
[문제 링크](https://www.acmicpc.net/problem/1253)

---
### 제출일
2025년 1월 16일

---
### 문제 설명
<p>N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.</p>
<p>N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.</p>
<p>수의 위치가 다르면 값이 같아도 다른 수이다.</p>

### 입력 
<p>첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 A<sub>i</sub>가 N개 주어진다. (|A<sub>i</sub>| ≤ 1,000,000,000, A<sub>i</sub>는 정수)</p>

### 출력 
<p>좋은 수의 개수를 첫 번째 줄에 출력한다.</p>
---
### 사용 알고리즘
- 투포인터

---
### 아이디어
1. 배열 정렬
2. 모든 각각의 수에 대해 투포인터 탐색
3. s, e가 현재 탐색하는 수인 경우 제외하고
4. 좋다를 만족하는 수면 cnt++
5. s, e의 합이 탐색하는 수보다 작으면 s++;, 크면 e--;

---
### 유의점
1. s, e가 현재 탐색하는 수인 경우 제외 조건을 걸지 않아서 틀렸었음,, (s == i 면 s++;, e == i 면 e--;)
