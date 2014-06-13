#ifndef RDSTRING_H_INCLUDED
#define RDSTRING_H_INCLUDED

class rdstring
{
    private:
        char* chaine;
        int taille;

        void reinit(char const *a);

    public:
        rdstring();
        rdstring(const char* p_chaine);
        rdstring(rdstring const &origin);
        ~rdstring();
        void afficher(std::ostream &flux) const;
        char getChar(int i) const;
        int getTaille() const;
        bool empty() const;
        void clear();
        void erase(int it, int si);
        void copier(char* &pi);

        rdstring& operator+=(rdstring const &a);
        bool operator==(rdstring const &a);
        bool operator>=(rdstring const &a);
        bool operator<=(rdstring const &a);
        bool operator<(rdstring const &a);
        bool operator>(rdstring const &a);
        rdstring& operator=(rdstring const &a);
        rdstring& operator=(char const *a);
        char operator[](int const a);
};

//operator const char *();
std::ostream& operator<<(std::ostream &flux, rdstring const& a);
rdstring operator+(rdstring const &a, rdstring const& b);

#endif // RDSTRING_H_INCLUDED
