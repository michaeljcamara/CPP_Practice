-- Bob Roos
-- Shows the CORRECT way to google something! It's not typing it into Google,
-- it's replacing every occurrence of "oo" with "oogleoo".
--
-- Given a string of text, look for occurrences of "oo" and replace them
-- with "oogleoo". Thus, the word "balloon" becomes "balloogleoon" and the
-- word "book" becomes "boogleook".
--
-- Sample usage:
--      Prelude> :l google
--      [1 of 1] Compiling Main      ( google.hs, interpreted )
--      Ok, modules loaded: Main.
--      *Main> google "Ooo!, this is too, too cool!"
--      "oogleooo!, this is toogleoo, toogleoo coogleool!"
--      *Main> google "See you soon, toodle-oo!"
--      "See you soogleoon, toogleoodle-oogleoo!"

noun = "asd"

google s = 
           -- base case: can't do anything here
           if (length s) < 2 then 
              s

           -- See if first two letters are "oo"; if so, replace with
           -- "oogleoo" and recursively process rest of string:
           else if (take 2 s) `elem` ["oo","OO","Oo","oO"] then
                   "oogleoo" ++ google (drop 2 s)

           -- First two letters were not "oo", so keep the first letter and
           -- recursively process the rest of the string:
           else
              (take 1 s) ++ google (drop 1 s)
    
-- Michael Camara
-- Honor Code Pledge: This work is mine unless otherwise cited
-- CS220
-- Lab 6: Haskell


------------------------------------------------------------------------
-- Main Event! This will convert a given string into a series of "X"s and
-- "O"s.  Specifically, all lower case letters are turned into "X"s, upper-
-- case letters are turned into "O"s, and everything else is left unchanged.
-- Why send your valentine a confession of love when you can simply use
-- this hugsandkisses function to express your feelings, instead?
------------------------------------------------------------------------
hugsandkisses s = 
        if (length s) < 1 then
            s
        else
            (convert (head s)) ++ (test3 (tail s))

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
    if c `elem` ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] then
        1
    else if c `elem` ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'] then
        0
    else
        2
