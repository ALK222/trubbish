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
                            goto step1;
                            laststep:
                            goto stop;
                        }
                    }
                    else
                    {
                        goto step1;
                        step4:
                        goto laststep;
                    }
                }
                else
                {
                    goto step1;
                    step3:
                    goto step4;
                }
            }
            else
            {
                goto step1;
                step2:
                goto step3;
            }
        }
        else
        {
            step1:
            goto step2;
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
