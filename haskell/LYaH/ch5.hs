
maximum' :: (Ord a) => [a] -> a
maximum' [] = error "max of []"
maximum' [x] = x
maximum' (x:xs)
    | x > tailMax = x
    | otherwise = tailMax
    where tailMax = maximum' xs

replicate' :: (Num x, Ord x) => x -> a -> [a]
replicate' x a
    | x <= 0 = []
    | otherwise = a:replicate' (x-1) a

take' :: (Num x, Ord x) => x -> [a] -> [a]
take' _ [] = []
take' n (x:xs)
    | n <= 0 = []
    | otherwise = x:take' (n-1) xs

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]
repeat' :: a -> [a]
repeat' x = x:repeat' x

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (x,y):(zip' xs ys)

elem' :: (Eq a) => a -> [a] -> Bool
elem' x [] = False
elem' x (y:ys)
    | x==y = True
    | otherwise = x `elem'` ys

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let xinit = quicksort [ i | i <-xs, i<=x]
        xtail = quicksort [ i | i <-xs, i>x]
    in xinit ++ [x] ++ xtail

