# Write your MySQL query statement below
SELECT X, Y, Z, IF(IF(IF(IF(X + Y > Z, 1, 0), IF(Z + Y > X, 1, 0), 0), IF(X + Z > Y, 1, 0), 0), 'Yes', 'No') AS TRIANGLE
FROM TRIANGLE