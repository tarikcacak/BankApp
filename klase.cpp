// klase.cpp

#include "klase.h"

// Korisnik

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

// Radnik

Radnik::Radnik() {}

Radnik::Radnik(int radnikId, const string& username, const string& password, const string& JMBG) {
    this->id = radnikId;
    this->username = username;
    this->password = password;
    this->JMBG = JMBG;
}

int Radnik::getId() const {
    return id;
}

string Radnik::getUsername() const {
    return username;
}

string Radnik::getPassword() const {
    return password;
}

string Radnik::getJMBG() const {
    return JMBG;
}

void Radnik::setId(int radnikId) {
    id = radnikId;
}

void Radnik::setUsername(const string& newUsername) {
    username = newUsername;
}

void Radnik::setPassword(const string& newPassword) {
    password = newPassword;
}

void Radnik::setJMBG(const string& newJMBG) {
    JMBG = newJMBG;
}

void Radnik::ispisiPodatkeRadnika() const {
    cout << "Radnik ID: " << id << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "JMBG: " << JMBG << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}

bool Radnik::provjeriPodatke(const string& inputUsername, const string& inputPassword) const {
    return (username == inputUsername) && (password == inputPassword);
}

// Tekuci 

Tekuci::Tekuci() {}

Tekuci::Tekuci(const string& broj, const string& vlasnik, double stanje) {
    this->broj = broj;
    this->vlasnik = vlasnik;
    this->stanje = stanje;
}

string Tekuci::getBroj() const {
    return broj;
}

string Tekuci::getVlasnik() const {
    return vlasnik;
}

double Tekuci::getStanje() const {
    return stanje;
}

void Tekuci::setStanje(double novoStanje) {
    stanje = novoStanje;
}

void Tekuci::ispisiPodatkeTekuceg() const {
    cout << "Broj: " << broj << endl;
    cout << "Vlasnik: " << vlasnik << endl;
    cout << "Stanje: " << stanje << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}