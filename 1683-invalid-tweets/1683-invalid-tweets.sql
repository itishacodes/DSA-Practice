# Write your MySQL query statement below

SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15
# CHAR_LENGTH function is used to return the length


# LENGTH() -> returns length in bytes
# CHAR_LENGTH -> returns length in char

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna