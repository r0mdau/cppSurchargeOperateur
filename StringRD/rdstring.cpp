#include <iostream>
#include "rdstring.h"

using namespace std;

rdstring::rdstring()
{
}

rdstring::rdstring(const char* p_chaine)
{
    for(taille=0; p_chaine[taille]!='\0'; taille++)
        ;
    chaine = new char[taille+1];
    for(int i(0); i<=taille; i++)
    {
        chaine[i]=p_chaine[i];
    }
}

rdstring::rdstring(const rdstring &origin)
{
    chaine = new char;
    taille=origin.getTaille();
    for(int i(0); i<=taille; i++)
        chaine[i]=origin.getChar(i);
}

int rdstring::getTaille() const
{
    return taille;
}

rdstring::~rdstring()
{
    delete chaine;
}

char rdstring::getChar(int i) const
{
    return chaine[i];
}

void rdstring::afficher(ostream &flux) const
{
    for(int i(0); i<taille; i++)
        flux<<chaine[i];
    flux<<endl;
}

/*operator const char *()
{
    return chaine;
}*/

ostream& operator<<(ostream &flux, rdstring const& a)
{
    a.afficher(flux);
    return flux;
}

rdstring& rdstring::operator=(char const *a)
{
    reinit(a);
    return *this;
}


rdstring& rdstring::operator+=(rdstring const &a)
{
    char * pi;
    copier(pi);

    chaine = new char[a.getTaille()+taille];

    for(int i(0); pi[i]!='\0'; i++)
        chaine[i]=pi[i];
    for(int i(0); a.getChar(i)!='\0'; i++)
        chaine[i+taille]=a.getChar(i);
    taille+=a.getTaille();

    return *this;
}

rdstring operator+(rdstring const &a, rdstring const& b)
{
    rdstring copie(a);
    copie+=b;
    return copie;
}

rdstring& rdstring::operator=(rdstring const &a)
{
    taille=a.getTaille();
    for(int i(0); i<=taille; i++)
        chaine[i]=a.getChar(i);
    return *this;
}

void rdstring::reinit(char const *a)
{
    taille=0;
    for(int i(0); a[i]!='\0'; i++)
    {
        chaine[i]=a[i];
        ++taille;
    }
}

char rdstring::operator[](int const a)
{
    return getChar(a-1);
}

bool rdstring::empty() const
{
    return (chaine=="");
}

bool rdstring::operator==(rdstring const &a)
{
    if(taille==a.getTaille())
    {
        for(int i(0); i<=a.getTaille(); i++)
            if(getChar(i)!=a.getChar(i))
                return false;
        return true;
    }
    else return false;


}

bool rdstring::operator>=(rdstring const &a)
{
    return (taille>=a.getTaille());
}
bool rdstring::operator<=(rdstring const &a)
{
    return (taille<=a.getTaille());
}
bool rdstring::operator<(rdstring const &a)
{
    return (taille<a.getTaille());
}
bool rdstring::operator>(rdstring const &a)
{
    return (taille>a.getTaille());
}

void rdstring::clear()
{
    taille=1;
    delete chaine;
    chaine= new char[taille];
}

void rdstring::copier(char* &pi)
{
    pi=new char[taille];

    for(int i(0); i<=taille; i++)
        pi[i]=chaine[i];
}

void rdstring::erase(int it, int si)
{
    if(it<=taille && it+si<=taille)
    {
        int y=0;
        char * pi;
        copier(pi);
        delete chaine;
        chaine=new char[taille-si];
        for(int i=0; i<=taille; i++)
        {
            if(i<it || i>it+si) chaine[i-y]=pi[i];
            else ++y;
        }
        taille-=si;
        delete pi;
    }
    else cout<<"Mauvaises dimensions dans la fonction erase."<<endl;
}
