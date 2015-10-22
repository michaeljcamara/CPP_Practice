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
------------------------------------------------------------------------

------------------------------------------------------------------------
--Numbers Main Event! This function will take a single positive integer as
--input.  If the integer is small (<= 20) then the factorial will be
--computer.  Otherwise, if it is even then the sum of the first x even
--numbers will be taken.  If it is odd, then the sum of the first x
--odd numbers will be taken. (For some reason if I replace the sum with
--product for the set of evens or odds, the result is negative! Unsure why 
--this is the case...)
--------------------------------------------------------------------------

sillymath x =
    if (x <= 20) then
        product [1..x]
    else if (x `mod` 2 == 0) then
        sum (take x [n | n <- [2..], n `mod` 2 == 0])
    else if (x `mod` 2 == 1) then
        sum (take x [n | n <- [1..], n `mod` 2 == 1])
    else
        0
