{-# LANGUAGE CPP                      #-}
{-# LANGUAGE ForeignFunctionInterface #-}
{-# OPTIONS_GHC -fno-warn-unused-top-binds #-}
module Algo (buscaGen) where
    import Foreign.C.String ( CString, peekCString, newCString )
    import Foreign.C.Types ( CInt(..) )
    import System.IO.Unsafe (unsafePerformIO)

    foreign export ccall buscaGen :: CInt -> CInt

    contains :: String -> [String] -> Bool 
    contains _ [] = False 
    contains n (x:xs) 
        | n == x = True 
        | otherwise = contains n xs

    buscaGenAux:: CInt -> IO CInt 
    buscaGenAux 9 = do return 0
    buscaGenAux g =  do 
        let gen = show g 
        let filename = "Resources/" ++ gen ++ ".txt"
        pokemonlist <- readFile filename 
        let filename2 = "Resources/escogidos.txt"
        pokemonlist2 <- readFile filename2
        let pokemons = words pokemonlist 
        let selected = words pokemonlist2
        let name = last(selected)
        let res = contains name pokemons
        if (res == False) then
            buscaGenAux (g + 1)
        else 
            return g

    buscaGen:: CInt -> CInt
    buscaGen g = unsafePerformIO (buscaGenAux g)
