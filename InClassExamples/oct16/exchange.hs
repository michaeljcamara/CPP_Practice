-- Bob Roos
-- Haskell demo functions

---------------------------------------------
-- Helper function: given a list of names, return a list of the first letters:
-- Example:
--     firsts ["abc","def","ghi"] == "adg" (or ['a','d','g'])
---------------------------------------------

firsts l = [head x | x <- l] 

---------------------------------------------
-- Helper function: given a list of names, return a list of "beheaded" names:
-- Example:
--     tails ["abc","def","ghi"] == ["bc","ef","hi"]
---------------------------------------------

tails l = [tail x | x <- l]  

---------------------------------------------
-- Helper function: given a list, return the list, rotated one place to the left:
-- Examples:
--     rotate [1,2,3,4] = [2,3,4,1]
--     rotate "abcde" = "bcdea"
---------------------------------------------

rotate l = tail l ++ [head l]

---------------------------------------------
-- Helper function: given two lists of the same length, "zip" them up
-- into a list of ordered pairs:
-- Example:
--     pairs "abc" [11,12,13] == [('a',11),('b',12),('c',13)]
---------------------------------------------

pairs l = zip (rotate (firsts l)) (tails l) 

---------------------------------------------
-- THE MAIN EVENT: Given a list of names, return a new list of names
-- in which the first letters of the original list have been rotated
-- onto the name to the left.
---------------------------------------------

exchange l = [fst x : snd x | x<- pairs l]
