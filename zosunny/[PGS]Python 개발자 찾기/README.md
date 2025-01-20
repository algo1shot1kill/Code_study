## [PGS] Python 개발자 찾기
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/276013)

---
### 제출일
2025년 1월 18일

---
### 문제 설명
<p><code>DEVELOPER_INFOS</code> 테이블에서 Python 스킬을 가진 개발자의 정보를 조회하려 합니다. Python 스킬을 가진 개발자의 ID, 이메일, 이름, 성을 조회하는 SQL 문을 작성해 주세요. </p>

<p>결과는 ID를 기준으로 오름차순 정렬해 주세요.</p>

<hr>

<h5>예시</h5>

<p>예를 들어 <code>DEVELOPER_INFOS</code> 테이블이 다음과 같다면</p>
<table class="table">
        <thead><tr>
<th>ID</th>
<th>FIRST_NAME</th>
<th>LAST_NAME</th>
<th>EMAIL</th>
<th>SKILL_1</th>
<th>SKILL_2</th>
<th>SKILL_3</th>
</tr>
</thead>
        <tbody><tr>
<td>D165</td>
<td>Jerami</td>
<td>Edwards</td>
<td><code>jerami_edwards@grepp.co</code></td>
<td>Java</td>
<td>JavaScript</td>
<td>Python</td>
</tr>
<tr>
<td>D161</td>
<td>Carsen</td>
<td>Garza</td>
<td><code>carsen_garza@grepp.co</code></td>
<td>React</td>
<td></td>
<td></td>
</tr>
<tr>
<td>D164</td>
<td>Kelly</td>
<td>Grant</td>
<td><code>kelly_grant@grepp.co</code></td>
<td>C#</td>
<td></td>
<td></td>
</tr>
<tr>
<td>D163</td>
<td>Luka</td>
<td>Cory</td>
<td><code>luka_cory@grepp.co</code></td>
<td>Node.js</td>
<td></td>
<td></td>
</tr>
<tr>
<td>D162</td>
<td>Cade</td>
<td>Cunningham</td>
<td><code>cade_cunningham@grepp.co</code></td>
<td>Vue</td>
<td>C++</td>
<td>Python</td>
</tr>
</tbody>
      </table>
<p>다음과 같이 Python 스킬을 가진 개발자의 정보가 결과에 나와야 합니다.</p>
<table class="table">
        <thead><tr>
<th>ID</th>
<th>EMAIL</th>
<th>FIRST_NAME</th>
<th>LAST_NAME</th>
</tr>
</thead>
        <tbody><tr>
<td>D162</td>
<td><code>cade_cunningham@grepp.co</code></td>
<td>Cade</td>
<td>Cunningham</td>
</tr>
<tr>
<td>D165</td>
<td><code>jerami_edwards@grepp.co</code></td>
<td>Jerami</td>
<td>Edwards</td>
</tr>
</tbody>
      </table>

---
### 아이디어
- 그냥 OR로 조건
