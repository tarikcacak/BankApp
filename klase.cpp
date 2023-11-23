// klase.cpp

#include "klase.h"

Korisnik::Korisnik() {}

Korisnik::Korisnik(int userId, const string& username, const string& password, const string& JMBG) {
    this->id = userId;
    this->username = username;
    this->password = password;
    this->JMBG = JMBG;
}

int Korisnik::getId() const {
    return id;
}

string Korisnik::getUsername() const {
    return username;
}

string Korisnik::getPassword() const {
    return password;
}

string Korisnik::getJMBG() const {
    return JMBG;
}

void Korisnik::setId(int userId) {
    id = userId;
}

void Korisnik::setUsername(const string& newUsername) {
    username = newUsername;
}

void Korisnik::setPassword(const string& newPassword) {
    password = newPassword;
}

void Korisnik::setJMBG(const string& newJMBG) {
    JMBG = newJMBG;
}

void Korisnik::ispisiKorisnickePodatke() const {
    cout << "User ID: " << id << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "JMBG: " << JMBG << endl;
    cout << "--------------------------" << endl;
}

bool Korisnik::provjeriPodatke(const string& inputUsername, const string& inputPassword) const {
    return (username == inputUsername) && (password == inputPassword);
}

Radink::Radnik() {}

Radnik::Radnik(int radnikId, const string& ime, const string& prezime, const string& JMBG) {
    this->id = radnikId;
    this->ime = ime;
    this->prezime = prezime;
    this->JMBG = JMBG;
}

int Radnik::getId() const {
    return id;
}

string Radnik::getIme() const {
    return ime;
}

string Radnik::getPrezime() const {
    return prezime;
}

string Radnik::getJMBG() const {
    return JMBG;
}

void Radnik::setId(int radnikId) {
    id = radnikId;
}

void Radnik::setIme(const string& novoIme) {
    ime = novoIme;
}

void Radnik::setPrezime(const string& novoPrezime) {
    prezime = novoPrezime;
}

void Radnik::setJMBG(const string& newJMBG) {
    JMBG = newJMBG;
}

void Radnik::ispisiPodatke() const {
    cout << "Radnik ID: " << id << endl;
    cout << "Ime: " << ime << endl;
    cout << "Prezime: " << prezime << endl;
    cout << "JMBG: " << JMBG << endl;
    cout << "--------------------------" << endl;
}