
## [PGS] 잔챙이 잡은 수 구하기
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/293258)

---
### 제출일
2025년 1월 19일

---
### 문제 설명
<p>잡은 물고기 중 길이가 10cm 이하인 물고기의 수를 출력하는 SQL 문을 작성해주세요.</p>

<p>물고기의 수를 나타내는 컬럼 명은 FISH_COUNT로 해주세요.</p>

<hr>

<h5>예시</h5>

<p>예를 들어 <code>FISH_INFO</code> 테이블이 다음과 같다면</p>
<table class="table">
        <thead><tr>
<th>ID</th>
<th>FISH_TYPE</th>
<th>LENGTH</th>
<th>TIME</th>
</tr>
</thead>
        <tbody><tr>
<td>0</td>
<td>0</td>
<td>13.37</td>
<td>2021/12/04</td>
</tr>
<tr>
<td>1</td>
<td>0</td>
<td>50</td>
<td>2020/03/07</td>
</tr>
<tr>
<td>2</td>
<td>0</td>
<td>40</td>
<td>2020/03/07</td>
</tr>
<tr>
<td>3</td>
<td>1</td>
<td>43.33</td>
<td>2022/03/09</td>
</tr>
<tr>
<td>4</td>
<td>1</td>
<td>NULL</td>
<td>2022/04/08</td>
</tr>
<tr>
<td>5</td>
<td>2</td>
<td>NULL</td>
<td>2020/04/28</td>
</tr>
</tbody>
      </table>
<p>물고기 ID가 4, 5인 물고기들의 길이가 NULL, 즉 10cm 이하이므로 총 2마리 입니다. 따라서 결과는 다음과 같습니다. </p>
<table class="table">
        <thead><tr>
<th>FISH_COUNT</th>
</tr>
</thead>
        <tbody><tr>
<td>2</td>
</tr>
</tbody>
      </table>

---
### 아이디어
- COUNT()와 IS NULL
