-- Bob Roos
-- "hearts" -- given an integer n, create a string of zero or
-- more hearts ("<3" is a sideways heart). The number of hearts
-- in the string is equal to the number of digits in n that are
-- less than 3. For instance,
--
--     Prelude> :l hearts
--     [1 of 1] Compiling Main    ( hearts.hs, interpreted )
--     Ok, modules loaded: Main.
--     *Main> hearts 1234
--     "<3<3"
--     *Main> hearts 9
--     ""
--     *Main> hearts 888393
--     ""
--     *Main> hearts 11001210
--     "<3<3<3<3<3<3<3<3"

-----------
-- hearts: see comments above for description
-----------
hearts n =
   -- base case: a single digit less than 3 produces a heart:
   if n < 3 then 
      "<3"
   -- base case: a single digit greater than or equal to 3 produces empty string:
   else if n < 10 then
      ""
   else
     -- create heart string for all but the last digit, then
     -- add one more heart if the last digit is < 3:

      hearts (n `quot` 10) ++ (if (n `mod` 10) < 3 then "<3" else "")
