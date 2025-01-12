## [PGS] 자동차 대여 기록 별 대어 금액 구하기
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/151141)

---
### 제출일
2025년 1월 12일

---
### 문제 설명
<h5>문제</h5>
<p><code>CAR_RENTAL_COMPANY_CAR</code> 테이블과 <code>CAR_RENTAL_COMPANY_RENTAL_HISTORY</code> 테이블과 <code>CAR_RENTAL_COMPANY_DISCOUNT_PLAN</code> 테이블에서 자동차 종류가 '트럭'인 자동차의 대여 기록에 대해서 대여 기록 별로 대여 금액(컬럼명: <code>FEE</code>)을 구하여 대여 기록 ID와 대여 금액 리스트를 출력하는 SQL문을 작성해주세요. 결과는 대여 금액을 기준으로 내림차순 정렬하고, 대여 금액이 같은 경우 대여 기록 ID를 기준으로 내림차순 정렬해주세요.</p>
<hr>
<h5>예시</h5>
<p>예를 들어 <code>CAR_RENTAL_COMPANY_CAR</code> 테이블과 <code>CAR_RENTAL_COMPANY_RENTAL_HISTORY</code> 테이블과 <code>CAR_RENTAL_COMPANY_DISCOUNT_PLAN</code> 테이블이 다음과 같다면</p>
<table class="table">
        <thead><tr>
<th>CAR_ID</th>
<th>CAR_TYPE</th>
<th>DAILY_FEE</th>
<th>OPTIONS</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>트럭</td>
<td>26000</td>
<td>가죽시트,열선시트,후방카메라</td>
</tr>
<tr>
<td>2</td>
<td>SUV</td>
<td>14000</td>
<td>스마트키,네비게이션,열선시트</td>
</tr>
<tr>
<td>3</td>
<td>트럭</td>
<td>32000</td>
<td>주차감지센서,후방카메라,가죽시트</td>
</tr>
</tbody>
      </table><table class="table">
        <thead><tr>
<th>HISTORY_ID</th>
<th>CAR_ID</th>
<th>START_DATE</th>
<th>END_DATE</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>1</td>
<td>2022-07-27</td>
<td>2022-08-02</td>
</tr>
<tr>
<td>2</td>
<td>1</td>
<td>2022-08-03</td>
<td>2022-08-04</td>
</tr>
<tr>
<td>3</td>
<td>2</td>
<td>2022-08-05</td>
<td>2022-08-05</td>
</tr>
<tr>
<td>4</td>
<td>2</td>
<td>2022-08-09</td>
<td>2022-08-12</td>
</tr>
<tr>
<td>5</td>
<td>3</td>
<td>2022-09-16</td>
<td>2022-10-15</td>
</tr>
</tbody>
      </table><table class="table">
        <thead><tr>
<th>PLAN_ID</th>
<th>CAR_TYPE</th>
<th>DURATION_TYPE</th>
<th>DISCOUNT_RATE</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>트럭</td>
<td>7일 이상</td>
<td>5%</td>
</tr>
<tr>
<td>2</td>
<td>트럭</td>
<td>30일 이상</td>
<td>7%</td>
</tr>
<tr>
<td>3</td>
<td>트럭</td>
<td>90일 이상</td>
<td>10%</td>
</tr>
<tr>
<td>4</td>
<td>세단</td>
<td>7일 이상</td>
<td>5%</td>
</tr>
<tr>
<td>5</td>
<td>세단</td>
<td>30일 이상</td>
<td>10%</td>
</tr>
<tr>
<td>6</td>
<td>세단</td>
<td>90일 이상</td>
<td>15%</td>
</tr>
</tbody>
      </table>
<p>자동차 종류가 '트럭' 인 자동차의 대여 기록에 대해서 대여 기간을 구하면,</p>
<ul>
<li>대여 기록 ID가 1인 경우, 7일</li>
<li>대여 기록 ID가 2인 경우, 2일</li>
<li>대여 기록 ID가 5인 경우, 30일입니다.</li>
</ul>
<p>대여 기간 별로 일일 대여 요금에 알맞은 할인율을 곱하여 금액을 구하면 다음과 같습니다.</p>
<ul>
<li>대여 기록 ID가 1인 경우, 일일 대여 금액 26,000원에서 5% 할인율을 적용하고 7일을 곱하면 총 대여 금액은 172,900원</li>
<li>대여 기록 ID가 2인 경우, 일일 대여 금액 26,000원에 2일을 곱하면 총 대여 금액은 52,000원</li>
<li>대여 기록 ID가 5인 경우, 일일 대여 금액 32,000원에서 7% 할인율을 적용하고 30일을 곱하면 총 대여 금액은 892,800원이 되므로, 대여 금액을 기준으로 내림차순 정렬 및 대여 기록 ID를 기준으로 내림차순 정렬하면 다음과 같아야 합니다.</li>
</ul>
<table class="table">
        <thead><tr>
<th>HISTORY_ID</th>
<th>FEE</th>
</tr>
</thead>
        <tbody><tr>
<td>5</td>
<td>892800</td>
</tr>
<tr>
<td>1</td>
<td>172900</td>
</tr>
<tr>
<td>2</td>
<td>52000</td>
</tr>
</tbody>
      </table>
<hr>
<h5>주의사항</h5>
<p><code>FEE</code>의 경우 예시처럼 정수부분만 출력되어야 합니다.</p>

---
### 아이디어
- 날짜의 차를 구하는 DATEDIFF ex. DATEDIFF(END_DATE, START_DATE)
- WITH로 날짜별 DURATION_TYPE을 가지는 가상 테이블 생성
- 기간이 7일 이하여도 할인율은 적용안되지만 값이 도출되어야 하므로 LEFT JOIN
