#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#ifdef __GLASGOW_HASKELL__
#include "haskell_wrapper.h"
#endif

// https://stackoverflow.com/questions/3859340/calling-haskell-from-c-code

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
    static Pokemon stringToPokemon(std::string n);

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
    std::string correctName;
    std::string correctT1;
    std::string correctT2;
    std::string correctG;
    std::string correctP;
    std::string correctA;
    correctName=_n == p.getN()?"YEP":"Has perdido y lo que sigue"
    correctT1=_n == p.getT1()?"YEP":"Has perdido y lo que sigue"
    correctT2=_n == p.getT2()?"YEP":"Has perdido y lo que sigue"
    correctG=_n == p.getG()?"YEP":"Has perdido y lo que sigue"
    correctP=_n == p.getP()?"YEP":"Has perdido y lo que sigue"
    correctA=_n == p.getA()?"YEP":"Has perdido y lo que sigue"
    if (correctName=="YEP")
    {
        if (correctT1=="YEP")
        {
            if (correctT2=="YEP")
            {
                if (correctG=="YEP")
                {
                    if (correctP=="YEP")
                    {
                        if (correctA=="YEP")
                        {
                            return true;
                        }
                        else
                        {
                            goto stop;
                        }
                    }
                    else
                    {
                        goto stop;
                    }
                }
                else
                {
                    goto stop;
                }
            }
            else
            {
                goto stop;
            }
        }
        else
        {
            goto stop;
        }
    }
    else
    {
        goto stop;
    }
    stop:
    std::cout<<"Fallaste wei\n";
    return false;
}

Pokemon Pokemon::stringToPokemon(std::string n)
{
#ifndef __GLASGOW_HASKELL__
    int g = buscaGen(n, 1);
#else
    int g = buscaGenWrapper(static_cast<void *>(&n), 1);
#endif
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
        std::string n;
        std::string t1;
        std::string t2;
        int g = 0;
        int p = 0;
        int a = 0;
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
        Pokemon p1 = Pokemon::stringToPokemon(g);
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
