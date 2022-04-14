#include <iostream>
#include <fstream>
#include <cstring>
#include "Algo_stub.h"

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
    std::string f = "/resources/" + g;
    std::string na(n);
    f += "/" + na + ".txt";
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
        d >> n, t1, t2, g, p, a;

        return Pokemon(n, t1, t2, g, p, a);
    }
}

int main(int argc, char **argv)
{
    hs_init(&argc, &argv);
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
    hs_exit();
    return 0;
}
