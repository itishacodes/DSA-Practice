# Write your MySQL query statement below
SELECT 
    name
FROM
    Customer
WHERE
    COALESCE(referee_id, 0) != 2 
# can also write this on last line
# referee_id is null OR referee_id != 2
# COALESCE is used instead of ISNULL. This is the standard SQL function for handling NULLs.

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna