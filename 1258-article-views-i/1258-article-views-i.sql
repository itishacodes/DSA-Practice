# Write your MySQL query statement below

SELECT DISTINCT author_id AS id
# id repeat na ho isliye i am using DISTINCT keyword
# AS keyword is used to rename the column
FROM Views
WHERE author_id = viewer_id
ORDER BY id
# ORDER BY keyword is used to make it in ascending order

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna