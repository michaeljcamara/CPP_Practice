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
