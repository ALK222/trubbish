{-# LANGUAGE CPP                      #-}
{-# LANGUAGE ForeignFunctionInterface #-}
{-# OPTIONS_GHC -fno-warn-unused-top-binds #-}
module Algo (buscaGen) where
    import Foreign.C.String ( CString, peekCString, newCString )
    import Foreign.C.Types ( CInt(..) )
    import System.IO.Unsafe (unsafePerformIO)

    foreign export ccall buscaGen :: CString -> CInt -> CInt

    buscaGen:: CString -> CInt -> CInt
    buscaGen _ 9 = 0
    buscaGen n g =
        if (not res) then (buscaGen n (g + 1)) else g
        where
            gen = show g
            fileName = "Resources/" ++ gen ++ ".txt"
            pokemonList = unsafePerformIO (readFile fileName)
            pokemons = words pokemonList
            name = unsafePerformIO (peekCString n)
            res = name `elem` pokemons
