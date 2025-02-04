-- 코드를 입력하세요
SELECT mp.MEMBER_NAME, rr.review_text, left(rr.review_date,10) as review_date
FROM REST_REVIEW as rr
JOIN MEMBER_PROFILE as mp
ON rr.member_id = mp.member_id
WHERE rr.member_Id = (
    SELECT member_id as count FROM REST_REVIEW GROUP BY member_id
    ORDER BY count(*) DESC LIMIT 1)
ORDER BY 3 ASC, 2 ASC;