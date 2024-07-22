# Write your MySQL query statement below
SELECT A.REP AS EMPLOYEE_ID, B.NAME, A.REPORTS_COUNT, A.AVERAGE_AGE
FROM
(SELECT REPORTS_TO AS REP, COUNT(REPORTS_TO) AS REPORTS_COUNT, ROUND(AVG(AGE), 0) AS AVERAGE_AGE
FROM EMPLOYEES
WHERE REPORTS_TO IS NOT NULL
GROUP BY REPORTS_TO) A
LEFT JOIN EMPLOYEES B
ON A.REP = B.EMPLOYEE_ID
ORDER BY A.REP