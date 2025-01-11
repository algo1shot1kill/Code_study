SELECT 
    CC.car_id
    , CC.car_type
    , ROUND( 30* daily_fee * (1 - discount_rate/100),0) as FEE
FROM (
    SELECT *
        FROM CAR_RENTAL_COMPANY_CAR
        WHERE (car_type IN ("세단", "SUV")) 
            AND car_id NOT IN (
                    SELECT CAR_ID
                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    WHERE (START_DATE BETWEEN '2022-11-01' AND '2022-11-30'
                        OR END_DATE BETWEEN '2022-11-01' AND '2022-11-30') 
                        OR (start_date < '2022-11-01' AND end_date > '2022-11-30'))
) AS CC
JOIN (SELECT * 
        FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN 
        WHERE (car_type IN ("세단","SUV")) 
            AND duration_type LIKE "30%") as DP 
ON DP.car_type = CC.car_type
WHERE 30* daily_fee * (1 - discount_rate/100) < 2000000 
    AND 30* daily_fee * (1 - discount_rate/100) >= 500000
ORDER BY FEE DESC, car_type ASC, car_id DESC;