-- Michael Camara
-- Honor Code Pledge: This work is mine unless otherwise cited
-- CS220
-- Lab 6: Haskell


------------------------------------------------------------------------
--List Main Event! This simple function will take the i-th element of a list
--and essentially "pull" it to the front.  It will maintain the ordering
--of the list and close the gap left by the element that was pulled
--
--Example usage:
--Input: [1, 2, 3, 4, 5, 6] 4
--Output: [5, 1, 2, 3, 4, 6]
------------------------------------------------------------------------
pulltofront l i =
          (l !! i) : ( (take i l) ++ (drop (i+1) l))
 

------------------------------------------------------------------------

------------------------------------------------------------------------
-- String Main Event! This will convert a given string into a series of "X"s and
-- "O"s.  Specifically, all lower case letters are turned into "X"s, upper-
-- case letters are turned into "O"s, and everything else is left unchanged.
-- Why send your valentine a confession of love when you can simply use
-- this hugsandkisses function to express your feelings, instead?
--
-- Example usage:
-- Input: hugsandkisses "Haskell is the BEST programming language Ever!"
-- Output: "OXXXXXX XX XXX OOOO XXXXXXXXXXX XXXXXXXX OXXX!"
--
------------------------------------------------------------------------
hugsandkisses s = 
        if (length s) < 1 then
            s
        else
            (convert (head s)) ++ (hugsandkisses (tail s))

------------------------------------------------------------------------
-- Helper function: This will convert a character into an "X" or "O" based
-- on whether it is uppercase or lowercase.  Relies on the isLowerCase
-- function.
------------------------------------------------------------------------
convert c = 
    if((isLowerCase c) == 1) then
        "X"
    else if ((isLowerCase c) == 0) then
        "O"
    else
        [c]

------------------------------------------------------------------------
-- Helper function: This will determine if a given char is lowercase
-- (returns 1), uppercase (returns 0), or neither (returns 2).
------------------------------------------------------------------------
isLowerCase c =
    if c `elem` ['a'..'z'] then
        1
    else if c `elem` ['A'..'Z'] then
        0
    else
        2

------------------------------------------------------------------------
--
--
--


