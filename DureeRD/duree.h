#ifndef DUREE_H_INCLUDED
#define DUREE_H_INCLUDED
#include <iostream>s

class Duree
{
    private:
        int m_heure;
        int m_minute;
        int m_seconde;

    public:
        Duree(int heure=0, int minute=0, int seconde=0);
        Duree(Duree const &origin);
        Duree& operator+=(Duree const& a);
        Duree& operator-=(Duree const& a);
        int getSeconde() const;
        int getMinute() const;
        int getHeure() const;
        void afficher(std::ostream &flux) const;

};

Duree operator+(Duree const &a, Duree const &b);
Duree operator-(Duree const &a, Duree const &b);
bool operator==(Duree const &a, Duree const &b);
bool operator!=(Duree const &a, Duree const &b);
std::ostream& operator<<(std::ostream &flux, Duree const& a);

#endif // DUREE_H_INCLUDED
