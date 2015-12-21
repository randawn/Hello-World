
-- haskell
-- wc -l -w -c

main = interact wordCount
    --where lineCount input = show (length (lines input)) ++ "\n"
    where wordCount input = show (length (words input)) ++ "\n"
    --where charCount input = show (length input) ++ "\n"


