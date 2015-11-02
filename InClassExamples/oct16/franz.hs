-- Bob Roos
-- In honor of one of the most famous lists, Franz Liszt.
-- Usage:
--    Prelude> :l franz
--    [1 of 1] Compiling Main             ( franz.hs, interpreted )
--    Ok, modules loaded: Main.
--    *Main> franz ["smith","roos","liszt","zappa","jones","obama"]
--    ["franz liszt","franz zappa"]

-------------------------------
-- Helper list: some famous composers:
-------------------------------

composers = ["bach","liszt","beethoven","haydn","zappa","joplin","glass"]

-------------------------------
-- Use "set comprehension" to add the name "franz" in front of each
-- name in the parameter s that belongs to the list "composers"; other
-- names are simply ignored.
-------------------------------
franz s = ["franz " ++ x | x <- s, x `elem` composers]
-- Explanation: for each string x in the parameter list s, if x appears
-- in the list of composers then concatenate the name "franz " to the front.
