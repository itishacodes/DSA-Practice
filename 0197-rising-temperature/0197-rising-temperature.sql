# Write your MySQL query statement below

SELECT w1.id
FROM Weather w1, Weather w2
# INNER JOIN returns intersection/common part of both the tables
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1
# DATEDIFF returns the difference between 2 dates
AND w1.temperature > w2.temperature

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna