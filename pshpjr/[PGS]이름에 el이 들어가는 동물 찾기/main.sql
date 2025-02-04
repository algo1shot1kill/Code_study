-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS 
WHERE name LIKE '%EL%' AND animal_type = 'Dog'
ORDER BY 2;