#include <iostream>
#include "duree.h"

using namespace std;

Duree::Duree(int heure, int minute, int seconde) : m_heure(heure), m_minute(minute), m_seconde(seconde)
{
}

Duree::Duree(Duree const &origin) : m_heure(origin.getHeure()), m_minute(origin.getMinute()), m_seconde(origin.getSeconde())
{
}

Duree operator+(Duree const &a, Duree const &b)
{
    Duree copie(a);
    Duree copie_b(b);
    copie+=copie_b;
    return copie;
}

Duree& Duree::operator+=(Duree const &a)
{
    m_seconde += a.getSeconde();
    m_minute+=m_seconde/60;
    m_seconde %=60;

    m_minute += a.getMinute();
    m_heure+=m_minute/60;
    m_minute %=60;

    m_heure+=a.getHeure();

    return *this;
}

Duree& Duree::operator-=(Duree const& a)
{
    m_minute-=a.getMinute();
    if(m_minute < 0) m_minute*=-1;
    m_seconde-=a.getSeconde();
    if(m_seconde < 0) m_seconde*=-1;
    m_heure-=a.getHeure();
    if(m_heure < 0) m_heure*=-1;
}

Duree operator-(Duree const &a, Duree const &b)
{
    Duree copie(a);
    copie-=b;
    return copie;
}

void Duree::afficher(ostream &flux) const
{
    flux<<"h:m:s  "<<m_heure<<":"<<m_minute<<":"<<m_seconde<<endl;
}

ostream& operator<<(ostream &flux, Duree const& a)
{
    a.afficher(flux);
    return flux;
}

int Duree::getSeconde()  const
{
    return (int const) m_seconde;
}
int Duree::getMinute() const
{
    return (int const) m_minute;
}
int Duree::getHeure() const
{
    return (int const) m_heure;
}

bool operator==(Duree const &a, Duree const &b)
{
    return (a.getMinute() == b.getMinute() && a.getHeure() == b.getHeure() && a.getSeconde()==b.getSeconde());
}

bool operator!=(Duree const &a, Duree const &b)
{
    if(a==b) return false;
    else return true;
}
