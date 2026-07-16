# Write your MySQL query statement below

SELECT eu.unique_id AS unique_id, e.name AS name
FROM Employees e
LEFT JOIN EmployeeUNI eu
# LEFT JOIN is used when 
ON e.id = eu.id 
# joining condition


-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna