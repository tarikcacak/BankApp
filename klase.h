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
        bool provjeriPodatke(const string& inputUsername const string& inputPassword) const;

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

#endif // KLASE_H