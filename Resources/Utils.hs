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
    | x < 151 = 1
    | x < 251 = 2
    | x < 387 = 3
    | x < 495 = 4
    | x < 650 = 5
    | x < 722 = 6
    | x < 810 = 7
    | otherwise = 8

meteEnLista :: String -> Int -> IO Int
meteEnLista s i = do
    appendFile (show (calculaGen i) ++ ".txt") (s ++ "\n")
    putStrLn (show i)
    return (i + 1)
