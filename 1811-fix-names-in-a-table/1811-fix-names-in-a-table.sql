# Write your MySQL query statement below
SELECT USER_ID, CONCAT(UPPER(SUBSTR(NAME, 1, 1)), LOWER(SUBSTR(NAME, 2, CHAR_LENGTH(NAME) - 1))) AS NAME
FROM USERS
ORDER BY USER_ID