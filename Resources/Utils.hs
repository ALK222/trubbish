module Resources.Utils where

organiza :: IO()
organiza = do
    f <- readFile "Resources/pokedex.txt"
    let i = 0
    ordenaLista (words f) i

ordenaLista :: [String] -> Int -> IO b
ordenaLista (x : xs) i = do
    i <- meteEnLista x i
    ordenaLista xs i


calculaGen:: Int -> Int
calculaGen x
    | x < 199 = 1
    | x < 310 = 2
    | x < 475 = 3
    | x < 599 = 4
    | x < 775 = 5
    | x < 863 = 6
    | x < 962 = 7
    | otherwise = 8

meteEnLista :: String -> Int -> IO Int
meteEnLista s i = do
    appendFile (show (calculaGen i) ++ ".txt") (s ++ "\n")
    putStrLn (show i)
    return (i + 1)
