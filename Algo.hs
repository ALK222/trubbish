module Algo where
    permutations :: [a] -> [[a]]
    permutations []       = [[]]
    permutations (x : xs) = concat [intercalado x ys | ys <- permutations xs]


    intercalado :: a -> [a] -> [[a]]
    intercalado x []       = [[x]]
    intercalado x (y : ys) = (x : y : ys) : [y : zs | zs <- intercalado x ys]

    buscaOrdenado :: (Eq a, Ord a) => [[a]] -> [a]
    buscaOrdenado [[]]       = []
    buscaOrdenado []         = []
    buscaOrdenado (xs : xss) = if esOrdenado xs then xs else buscaOrdenado xss

    esOrdenado :: (Eq a, Ord a) => [a] -> Bool
    esOrdenado [] = True
    esOrdenado (x : xs)
        | x >= head xs = esOrdenado xs
        | x < head xs = False
    esOrdenado _ = True
