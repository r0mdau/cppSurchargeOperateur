#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED

class ZFraction
{
    private:
        int m_numerateur;
        int m_denominateur;

    public:
        ZFraction(int numerateur=0, int denominateur=1);
        ZFraction(ZFraction const &origin);
        ~ZFraction();
        ZFraction& operator+=(ZFraction const &a);
        ZFraction& operator-=(ZFraction const &a);
        ZFraction& operator*=(ZFraction const &a);
        ZFraction& operator/=(ZFraction const &a);
        int getNumerateur() const;
        int getDenominateur() const;
        void afficher(std::ostream &flux) const;

};

bool operator>(ZFraction const &a, ZFraction const &b);
bool operator<(ZFraction const &a, ZFraction const &b);
std::ostream& operator<<(std::ostream &flux, ZFraction const& a);
ZFraction operator+(ZFraction const &a, ZFraction const &b);
ZFraction operator-(ZFraction const &a, ZFraction const &b);
bool operator==(ZFraction const &a, ZFraction const &b);
ZFraction operator*(ZFraction const &a, ZFraction const &b);
ZFraction operator/(ZFraction const &a, ZFraction const &b);

#endif // ZFRACTION_H_INCLUDED
