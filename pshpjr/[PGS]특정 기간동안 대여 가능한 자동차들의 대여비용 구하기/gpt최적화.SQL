SELECT 
    CC.car_id,
    CC.car_type,
    ROUND(30 * CC.daily_fee * (1 - DP.discount_rate/100), 0) AS FEE
FROM 
    CAR_RENTAL_COMPANY_CAR CC
JOIN 
    CAR_RENTAL_COMPANY_DISCOUNT_PLAN DP 
      ON DP.car_type = CC.car_type 
     AND DP.duration_type LIKE '30%'
WHERE 
    CC.car_type IN ('세단', 'SUV')
    AND NOT EXISTS (
         SELECT 1 
         FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY RH
         WHERE RH.car_id = CC.car_id
           AND (
                RH.start_date BETWEEN '2022-11-01' AND '2022-11-30'
             OR RH.end_date   BETWEEN '2022-11-01' AND '2022-11-30'
             OR (RH.start_date < '2022-11-01' AND RH.end_date > '2022-11-30')
           )
    )
    AND (30 * CC.daily_fee * (1 - DP.discount_rate/100)) < 2000000
    AND (30 * CC.daily_fee * (1 - DP.discount_rate/100)) >= 500000
ORDER BY 
    FEE DESC,
    CC.car_type ASC,
    CC.car_id DESC;



-- 아예 다른 버전

WITH candidate_cars AS (
    SELECT 
         CC.car_id,
         CC.car_type,
         CC.daily_fee,
         DP.discount_rate,
         ROUND(30 * CC.daily_fee * (1 - DP.discount_rate/100), 0) AS fee_calculated
    FROM CAR_RENTAL_COMPANY_CAR CC
    JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN DP
      ON DP.car_type = CC.car_type
     AND DP.duration_type LIKE '30%'
    WHERE CC.car_type IN ('세단', 'SUV')
      -- 30일 대여 금액 범위 조건 적용
      AND FLOOR(30 * CC.daily_fee * (1 - DP.discount_rate/100)) BETWEEN 500000 AND 1999999
)

SELECT
    c.car_id,
    c.car_type,
    c.fee_calculated AS FEE
FROM candidate_cars c
LEFT JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY RH
    ON RH.car_id = c.car_id 
    AND (
         RH.start_date BETWEEN '2022-11-01' AND '2022-11-30'
      OR RH.end_date   BETWEEN '2022-11-01' AND '2022-11-30'
      OR (RH.start_date < '2022-11-01' AND RH.end_date > '2022-11-30')
    )
-- 대여 이력이 존재하지 않는 경우만 선택
WHERE RH.car_id IS NULL
ORDER BY 
    FEE      DESC,
    car_type ASC,
    car_id   DESC;

