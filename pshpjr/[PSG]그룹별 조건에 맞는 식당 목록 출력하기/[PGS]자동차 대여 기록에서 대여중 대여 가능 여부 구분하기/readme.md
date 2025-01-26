[그룹별 조건에 맞는 식당 목록 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/131124)
---
## 문제 설명
---
다음은 고객의 정보를 담은 MEMBER_PROFILE테이블과 식당의 리뷰 정보를 담은 REST_REVIEW 테이블입니다. MEMBER_PROFILE 테이블은 다음과 같으며 MEMBER_ID, MEMBER_NAME, TLNO, GENDER, DATE_OF_BIRTH는 회원 ID, 회원 이름, 회원 연락처, 성별, 생년월일을 의미합니다.

Column name	Type	Nullable
MEMBER_ID	VARCHAR(100)	FALSE
MEMBER_NAME	VARCHAR(50)	FALSE
TLNO	VARCHAR(50)	TRUE
GENDER	VARCHAR(1)	TRUE
DATE_OF_BIRTH	DATE	TRUE
REST_REVIEW 테이블은 다음과 같으며 REVIEW_ID, REST_ID, MEMBER_ID, REVIEW_SCORE, REVIEW_TEXT,REVIEW_DATE는 각각 리뷰 ID, 식당 ID, 회원 ID, 점수, 리뷰 텍스트, 리뷰 작성일을 의미합니다.

Column name	Type	Nullable
REVIEW_ID	VARCHAR(10)	FALSE
REST_ID	VARCHAR(10)	TRUE
MEMBER_ID	VARCHAR(100)	TRUE
REVIEW_SCORE	NUMBER	TRUE
REVIEW_TEXT	VARCHAR(1000)	TRUE
REVIEW_DATE	DATE	TRUE
문제
MEMBER_PROFILE와 REST_REVIEW 테이블에서 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회하는 SQL문을 작성해주세요. 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력되도록 작성해주시고, 결과는 리뷰 작성일을 기준으로 오름차순, 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬해주세요.

## 문제 유형

JOIN

## 아이디어

1. 리뷰 젤 많은 애 찾아서 리뷰 남기고 걔랑 join하기

### 주의할 점
- dateformat 관련 제한사항 있었음. 
