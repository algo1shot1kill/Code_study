-- 코드를 입력하세요
-- 자동차 종류가 '트럭'인 자동차의 대여 기록에 대해서
-- 대여 기록 별로 대여 금액(컬럼명: FEE)을 구하여
-- 대여 기록 ID와 대여 금액 리스트를 출력
-- 대여 금액을 기준으로 내림차순, 
-- 대여 금액이 같은 경우 대여 기록 ID를 기준으로 내림차순

WITH DURATION_TABLE AS (SELECT HISTORY_ID, CAR_ID, DATEDIFF(END_DATE, START_DATE)+1 AS PERIOD,
                                (CASE WHEN DATEDIFF(END_DATE, START_DATE)+1 >= 90 THEN "90일 이상"
                                WHEN DATEDIFF(END_DATE, START_DATE)+1 >= 30 THEN "30일 이상"
                                WHEN DATEDIFF(END_DATE, START_DATE)+1 >= 7 THEN "7일 이상"
                                END) AS DURATION_TYPE
                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY)

SELECT B.HISTORY_ID, CASE WHEN B.DURATION_TYPE IS NULL THEN ROUND(DAILY_FEE * PERIOD)
            ELSE ROUND((DAILY_FEE) * (1 - DISCOUNT_RATE / 100) * PERIOD) END AS FEE
FROM CAR_RENTAL_COMPANY_CAR A JOIN DURATION_TABLE B ON A.CAR_ID = B.CAR_ID AND A.CAR_TYPE = "트럭" LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN C ON B.DURATION_TYPE = C.DURATION_TYPE AND C.CAR_TYPE = "트럭"
ORDER BY 2 DESC, 1 DESC;
