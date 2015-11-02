-- Bob Roos

-- unlucky: Haskell function to take a number and replace all of
--     the "unlucky" digits with "lucky" digits. The user gets
--     to specify which digit is unlucky and which is lucky

-- Sample run:
--    % ghci
--     ...
--    Prelude> :l unlucky
--    [1 of 1] Compiling Main     ( unlucky.hs, interpreted )
--    Ok, modules loaded: Main.
--    *Main> unlucky 4 2 44390232544
--    22390232522
--    *Main> unlucky 0 9 83000
--    83999
--    *Main> unlucky 3 2 7775
--    7775


-----------
-- Helper function:
-- "split" recursively splits an integer into a list of digits.
-----------
split x = 
   -- base case: x is already a digit, so just make a list out of it:
   if x < 10 then 
      [x]   
   else 
       -- divide by 10, append the remainder to the list and split the quotient:
      (x `mod` 10) : split (x `quot` 10)

-----------
-- Helper function:
-- "rejoin" recursively converts a list of digits into an integer.
-----------
rejoin l = 
   -- base case: list just has a single digit, so return that digit:
   if length l == 1 then 
      l !! 0
   else 
      -- recursively rejoin all but the last digit in the list, then
      -- multiply that by 10 and add the final digit:
      10 * rejoin (tail l) + (head l)

-----------
-- Helper function:
-- "subst" replaces unlucky digits "un" with lucky ones "lu" in a
--    list dl of digits:
-----------
subst un lu dl =
  -- Base case: list is empty, so just return empty list:
   if length dl == 0 then 
      []
   else
     -- If the first element is unlucky, replace it with lucky,
     -- otherwise leave it alone; recursively examine rest of list:
      (if head dl == un then lu else (head dl)) : subst un lu (tail dl)

-----------
-- "unlucky" replaces unlucky digits "un" with lucky ones "lu" in an
--    integer n by splitting n into a list of digits, replacing unlucky
--    numbers with lucky ones, and then rejoining the list into an integer:
-----------
unlucky un lu n =
   rejoin (subst un lu (split n))
