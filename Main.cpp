#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#ifdef __GLASGOW_HASKELL__
#include "Algo_stub.h"
#endif

class Pokemon
{
public:
    Pokemon(std::string n, std::string t1, std::string t2, int g, int p, int a);
    ~Pokemon();
    std::string getN();
    std::string getT1();
    std::string getT2();
    int getG();
    int getP();
    int getA();
    bool equals(Pokemon p);
    static Pokemon stringToPokemon(char n[]);

private:
    std::string _n;
    std::string _t1;
    std::string _t2;
    int _g;
    int _p;
    int _a;
};

#ifndef __GLASGOW_HASKELL__
int buscaGen(std::string n, int g)
{
    int i = 1;
    for (i; i < 2; ++i)
    {
        std::ifstream d;
        std::string f = "Resources/" + std::to_string(i) + ".txt";
        std::cout << f << std::endl;
        d.open(f);
    leer:
        if (d.eof())
        {
            goto fin;
        }
        std::string n1;
        d >> n1;
        if (n == n1)
        {
            goto rnum;
        }
        goto leer;
    }
fin:
    return 0;
rnum:
    return i;
}
#endif

Pokemon::Pokemon(std::string n, std::string t1, std::string t2, int g, int p, int a)
{
    _n = n;
    _t1 = t1;
    _t2 = t2;
    _g = g;
    _p = p;
    _a = a;
}

Pokemon::~Pokemon()
{
}

int Pokemon::getA()
{
    return _a;
}

int Pokemon::getG()
{
    return _g;
}

std::string Pokemon::getN()
{
    return _n;
}

int Pokemon::getP()
{
    return _p;
}

std::string Pokemon::getT1()
{
    return _t1;
}

std::string Pokemon::getT2()
{
    return _t2;
}

bool Pokemon::equals(Pokemon p)
{
    if (_n == p.getN())
    {
        if (_t1 == p.getT1())
        {
            if (_t2 == p.getT2())
            {
                if (_g == p.getG())
                {
                    if (_p == p.getP())
                    {
                        if (_a == p.getA())
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}

Pokemon Pokemon::stringToPokemon(char n[])
{
    int g = buscaGen(n, 1);
    if (g == 0)
    {
        return Pokemon("", "", "", 0, 0, 0);
    }
    std::string na(n);
    std::string f = "/resources/" + std::to_string(g) + "/" + na + ".txt";
    std::ifstream d;
    d.open(f);
    if (!d)
    {
        return Pokemon("", "", "", 0, 0, 0);
    }
    else
    {
        std::string n, t1, t2;
        int g = 0, p = 0, a = 0;
        d >> n;
        d >> t1;
        d >> t2;
        d >> g;
        d >> p;
        d >> a;

        return Pokemon(n, t1, t2, g, p, a);
    }
}

int main()
{
#ifdef __GLASGOW_HASKELL__
    int argc = 2;
    char *argv[] = {(char *)"+RTS", (char *)"-A32m", NULL};
    char **pargv = argv;

    // Initialize Haskell runtime
    hs_init(&argc, &pargv);
#endif
    int seguirJugando = 0;
    while (seguirJugando == 0)
    {
        Pokemon p = Pokemon("chimchar", "Fuego", "Ninguno", 4, 1, 1);
        int averiguado = 0;
    adivina:
        std::cout << "Introduce un pokemon: ";
        std::string g;
        std::cin >> g;
        char a[g.length() + 1];
        strcpy(a, g.c_str());
        Pokemon p1 = Pokemon::stringToPokemon(a);
        if (!p1.equals(p))
        {
            goto adivina;
        }
    }
#ifdef __GLASGOW_HASKELL__
    hs_exit();
#endif
    return 0;
}
