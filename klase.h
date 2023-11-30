// klase.h

#ifndef KLASE_H
#define KLASE_H

#include <iostream>
#include <string>

using namespace std;

class Korisnik {
    public:
        Korisnik();
        Korisnik(int userId, const string& username, const string& password, const string& JMBG);

        void ispisiKorisnickePodatke() const;
        bool provjeriPodatke(const string& inputUsername, const string& inputPassword) const;

        // getteri
        int getId() const;
        string getUsername() const;
        string getPassword() const;
        string getJMBG() const;

        // setteri
        void setId(int userId);
        void setUsername(const string& newUsername);
        void setPassword(const string& newPassword);
        void setJMBG(const string& newJMBG);

    private:
        int id;
        string username;
        string password;
        string JMBG;
};

class Radnik {
    public:
        Radnik();
        Radnik(int userId, const string& username, const string& password, const string& JMBG);

        void ispisiPodatkeRadnika() const;
        bool provjeriPodatke(const string& inputUsername, const string& inputPassword) const;

        // getteri
        int getId() const;
        string getUsername() const;
        string getPassword() const;
        string getJMBG() const;

        // setteri
        void setId(int userId);
        void setUsername(const string& newUsername);
        void setPassword(const string& newPassword);
        void setJMBG(const string& newJMBG);

    private:
        int id;
        string username;
        string password;
        string JMBG;
};

class Tekuci {
    public:
        Tekuci();
        Tekuci(const string& broj, const string& vlasnik, double stanje);

        void ispisiPodatkeTekuceg() const;

        // getteri
        string getBroj() const;
        string getVlasnik() const;
        double getStanje() const;

        // setteri
        void setStanje(double novoStanje);
    
    private:
        string broj;
        string vlasnik;
        double stanje;
};

class Stedni {
    public:
        Stedni();
        Stedni(const string& broj, const string& vlasnik, double stanje);

        void ispisiPodatkeStednog() const;

        // getteri
        string getBroj() const;
        string getVlasnik() const;
        double getStanje() const;

        // setteri
        void setStanje(double novoStanje);

    private: 
        string broj;
        string vlasnik;
        double stanje;
};

class Kredit {
    public:
        Kredit();
        Kredit(const string& id, const string& korisnik, double ukupanKredit, double dug, double placeno, int brojRata);

        void ispisiPodatkeKredita() const;

        // getteri
        string getId() const;
        string getKorisnik() const;
        double getUkupanKredit() const;
        double getDug() const;
        double getPlaceno() const;
        int getBrojRata() const;

        // setteri
        void setDug(double noviDug);
        void setPlaceno(double novoPlaceno);
        void setBrojRata(int noviBrojRata);
    
    private:
        string id;
        string korisnik;
        double ukupanKredit;
        double dug;
        double placeno;
        double brojRata;
};

#endif // KLASE_H