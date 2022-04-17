all: Algo haskell_wrapper Main Trubbish

Main: Main 
	g++ -c -O Main.cpp -I/usr/lib/ghc/include -D __GLASGOW_HASKELL__
Algo: Algo
	ghc Algo.hs 
haskell_wrapper: haskell_wrapper
	g++ -c -O haskell_wrapper.c -I/usr/lib/ghc/include 
Trubbish: Trubbish 
	ghc -no-hs-main Algo.o Main.o haskell_wrapper.o -lstdc++ -o trubbish

clean: 
	rm *.hi *.o *_stub.h
