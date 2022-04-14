all: main; ./main

# Compiling and linking with Haskell requires some headers and libraries. Specifically,
# those that come with GHC. (If your Haskell code uses a Cabal package, there will be even
# more dependencies. The flags below just give you the minimal Haskell dependencies.)
# 
# In this case, we're compiling against the Homebrew GHC. Haskell Platform also comes with
# essentially the same files.
# 
# This needs to be less brittle. We're hard-coding system paths and library versions.
# Instead, we should search for the latest version of the required library. Consider
# using CMake, pkg-config, or ghc --print-libdir.
main: Main.cpp Algo.o; g++ \
  -I/usr/lib/ghc/include \
  -L/usr/lib/ghc/ghc \
  -L/usr/lib/ghc/base-4.13.0.0 \
  -lHSbase-4.13.0.0 \
  -L/usr/lib/ghc/ghc-prim-0.5.3 \
  -lHSghc-prim-0.5.3 \
  -L/usr/lib/ghc/integer-gmp-1.0.2.0 \
  -lHSinteger-gmp-1.0.2.0 \
  -lHSghc-prim-0.5.3 \
  -fno-stack-protector \
  -Wall \
  -fPIE \
  -o main Main.cpp Algo.o

Algo.o: Algo.hs; ghc -fforce-recomp -fPIE Algo.hs

.PHONY: clean
clean: ; rm -rf main && rm -rf *.o && rm -rf *.hi && rm -rf *_stub.h
