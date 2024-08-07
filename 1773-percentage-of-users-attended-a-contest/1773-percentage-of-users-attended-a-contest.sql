# Write your MySQL query statement below
SELECT R.CONTEST_ID, ROUND(COUNT(DISTINCT R.USER_ID) / COUNT(DISTINCT U.USER_ID) * 100, 2) AS PERCENTAGE
FROM USERS U
CROSS JOIN REGISTER R
GROUP BY R.CONTEST_ID
ORDER BY PERCENTAGE DESC, CONTEST_ID;