#include <iostream>
#include "zfraction.h"

using namespace std;

ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
}

ZFraction::ZFraction(ZFraction const &origin) : m_numerateur(origin.getNumerateur()), m_denominateur(origin.getDenominateur())
{
}

ZFraction::~ZFraction()
{
}

int ZFraction::getNumerateur() const
{
    return m_numerateur;
}

int ZFraction::getDenominateur() const
{
    return m_denominateur;
}

bool operator<(ZFraction const &a, ZFraction const &b)
{
    return (b.getNumerateur()*a.getDenominateur() > a.getNumerateur()*b.getDenominateur());
}

bool operator>(ZFraction const &a, ZFraction const &b)
{
    return (b.getNumerateur()*a.getDenominateur() < a.getNumerateur()*b.getDenominateur());
}

ZFraction& ZFraction::operator+=(ZFraction const &a)
{
    if(m_denominateur==a.getDenominateur())
        m_numerateur+=a.getNumerateur();
    else
    {
        m_denominateur*=a.getDenominateur();
        m_numerateur=m_numerateur*a.getDenominateur() + a.getNumerateur()*m_denominateur;
    }
    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const &a)
{
    m_numerateur*=a.getNumerateur();
    m_denominateur*=a.getDenominateur();
    return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const &a)
{
    m_numerateur=m_numerateur*a.getDenominateur() - m_denominateur*a.getNumerateur();
    m_denominateur*=a.getDenominateur();
    return *this;
}

ZFraction operator-(ZFraction const &a, ZFraction const &b)
{
    ZFraction copie(a);
    copie-=b;
    return copie;
}

ZFraction operator+(ZFraction const &a, ZFraction const &b)
{
    ZFraction copie(a);
    copie+=b;
    return copie;
}

ostream& operator<<(ostream &flux, ZFraction const& a)
{
    a.afficher(flux);
    return flux;
}

void ZFraction::afficher(ostream &flux) const
{
    flux << m_numerateur<<"/"<<m_denominateur;
}

bool operator==(ZFraction const &a, ZFraction const &b)
{
    return (a.getNumerateur()==b.getNumerateur() && a.getDenominateur()==b.getDenominateur());
}

ZFraction operator*(ZFraction const &a, ZFraction const &b)
{
    ZFraction copie(a);
    copie*=b;
    return copie;
}

ZFraction& ZFraction::operator/=(ZFraction const &a)
{
    m_numerateur*=a.getDenominateur();
    m_denominateur*=a.getNumerateur();
    return *this;
}

ZFraction operator/(ZFraction const &a, ZFraction const &b)
{
    ZFraction copie(a);
    copie/=b;
    return copie;
}
