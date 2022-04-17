#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <vector>
//#define __GLASGOW_HASKELL__
#ifdef __GLASGOW_HASKELL__
#include "haskell_wrapper.h"
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
    for (i; i < 9; ++i)
    {
        std::ifstream d;
        std::string f = "Resources/" + std::to_string(i) + ".txt";
        d.open(f);
    leer:
        if (d.eof())
        {
        }
        else
        {

            std::string n1;
            d >> n1;
            if (n == n1)
            {
                goto rnum;
            }
            goto leer;
        }
    }

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
    correctName = _n == p.getN() ? "y" : "n";
    correctT1 = _t1 == p.getT1() ? "y" : "n";
    correctT2 = _t2 == p.getT2() ? "y" : "n";
    correctG = _g == p.getG() ? "y" : "n";
    correctP = _p == p.getP() ? "y" : "n";
    correctA = _a == p.getA() ? "y" : "n";
    if (correctName == "y")
    {
        if (correctT1 == "y")
        {
            if (correctT2 == "y")
            {
                if (correctG == "y")
                {
                    if (correctP == "y")
                    {
                        if (correctA == "y")
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
    std::string info = "GEN  |  Type1  | Type2  | Weight  | Height\n  ";
    std::string gen = "";
    std::string t1 = "a";
    std::string t2 = "a";
    std::string pe = "";
    std::string a = "";
    if (_g == p.getG())
        gen = "\u2705";
    else
        gen = p.getG() > _g ? "\u25b2" : "\u25bc";
    if (_p == p.getP())
        pe = "\u2705";
    else
        pe = p.getP() > _p ? "\u25b2" : "\u25bc";

    if (_a == p.getA())
        a = "\u2705";
    else
        a = p.getA() > _a ? "\u25b2" : "\u25bc";
    if (_t1 != p.getT1())
    {
        if (_t1 != p.getT2())
        {
            t1 = "\u274c";
        }
        else
            t1 = "\u2194";
    }
    else
        t1 = gen = "\u2705";

    if (_t2 != p.getT2())
    {
        if (_t2 != p.getT1())
        {
            t2 = "\u274c";
        }
        else
            t2 = "\u2194";
    }
    else
        t2 = gen = "\u2705";
    std::cout << "Fallaste\n"
              << info << gen << "  |    " << t1 << "    |    " << t2 << "   |    " << pe << "    |    " << a << std::endl;
    return false;
}

Pokemon Pokemon::stringToPokemon(std::string n)
{
#ifndef __GLASGOW_HASKELL__
    int g = buscaGen(n, 1);
#else
    int g = buscaGenWrapper(1);
#endif
    if (g == 0)
    {
        return Pokemon(n, "", "", 0, 0, 0);
    }
    std::string na(n);
    std::string f = "Resources/" + std::to_string(g) + "/" + na + ".txt";
    std::ifstream d;
    d.open(f);
    if (!d)
    {
        return Pokemon(n, "", "", 0, 0, 0);
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
        d.close();
        return Pokemon(n, t1, t2, g, p * 0.1, a * 0.1);
    }
}

std::string getRandPokemon()
{
    std::srand(time(NULL));
    std::ifstream f;
    f.open("Resources/pokedex.txt");
genera:
    int n = rand() % 1066 + 0;
    int i = 0;
    std::string s;
coge:
    f >> s;
    i++;
    if (n == i)
    {
        goto devuelve;
    }
    else
    {
        goto coge;
    }
devuelve:
    std::ifstream d;
    d.open("Resources/escogidos.txt");
    std::string a;
    while (!d.eof())
    {
        if (a == s)
        {
            goto genera;
        }
        else
        {
            d.close();
            std::ofstream a;
            a.open("Resources/escogidos.txt", std::ios_base::app);
            a << s;
            a << "\n";
            a.close();
            goto returnBien;
        }
    }
returnBien:
    f.close();
    // std::cout << s << std::endl;
    return s;
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
partidanueva:
    Pokemon p = Pokemon::stringToPokemon(getRandPokemon());
    int intentosRestantes = 10;
    int averiguado = 0;
adivina:
    std::cout << "Te quedan ";
    std::cout << intentosRestantes;
    std::cout << " intentos \n";
    std::cout << "Introduce un pokemon: ";
    std::string g;
    std::cin >> g;
    Pokemon p1 = Pokemon::stringToPokemon(g);
#ifdef __DEBUG__
    std::cout << p1.getN() << std::endl;
#endif

    if (!p1.equals(p))
    {
        int randa = rand();
        if ((intentosRestantes = intentosRestantes - (randa % 2 + 1)) > 0)
        {
            if (intentosRestantes <= 5)
            {
                struct Help
                {
                    std::string a;
                    std::string b;
                    std::string c;
                };
                Help help;
                help.a = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";
                help.b = "https://www.tiktok.com/@xime.the.remix/video/7080719647410048261?lang=es&u=6794154085656364038&is_copy_url=1&is_from_webapp=v1";
                help.c = "https://youtu.be/kTwLPu7-qY0?t=37";
                std::cout << "¿Pareces tener dificultades quieres ayuda?(Y/N):";
                char c;
                std::cin >> c;
                if (std::tolower(c) == 'y')
                {
                    switch ((rand() % 3))
                    {
                    case 0:
#ifdef _WIN32
                        ShellExecute(0, 0, help.a.c_str(), 0, 0, SW_SHOWNORMAL);
#endif
                        break;
                    case 1:
#ifdef _WIN32
                        ShellExecute(0, 0, help.b.c_str(), 0, 0, SW_SHOWNORMAL);
#endif
                        break;

                    case 2:
#ifdef _WIN32
                        ShellExecute(0, 0, help.c.c_str(), 0, 0, SW_SHOWNORMAL);
#endif
                        break;

                    default:
                        break;
                    }
                }
            }
            goto adivina;
        }
        else
        {
            std::cout << "HAS PERDIDO, el pokemon era: " << p.getN() << std::endl;
            goto partidanueva;
        }
    }
    else
    {
        std::cout << "HAS GANADO\n";
        goto partidanueva;
    }
#ifdef __GLASGOW_HASKELL__
    hs_exit();
#endif
    return 0;
}
