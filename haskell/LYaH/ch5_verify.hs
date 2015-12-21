maximum [1..10]
replicate 3 5
take 3 [1..10]
reverse [1..10]
take 2 (repeat 1)
zip [1..3] ['a'..'c']
elem 'x' ['a'..'z']

:l ch5.hs
maximum' [1..10]
replicate' 3 5
take' 3 [1..10]
reverse' [1..10]
take' 2 (repeat' 'a')
zip' [1..3] ['a'..'c']
elem' 'x' ['a'..'z']

quicksort [10,9..1]
quicksort "the quick brown fox jumps over the lazy dog"
