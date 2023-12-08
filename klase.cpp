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

// Stedni 

Stedni::Stedni() {}

Stedni::Stedni(const string& broj, const string& vlasnik, double stanje) {
    this->broj = broj;
    this->vlasnik = vlasnik;
    this->stanje = stanje;
}

string Stedni::getBroj() const {
    return broj;
}

string Stedni::getVlasnik() const {
    return vlasnik;
}

double Stedni::getStanje() const {
    return stanje;
}

void Stedni::setStanje(double novoStanje) {
    stanje = novoStanje;
}

void Stedni::ispisiPodatkeStednog() const {
    
    cout << "Broj: " << broj << endl;
    cout << "Vlasnik: " << vlasnik << endl;
    cout << "Stanje: " << stanje << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}

// kredit

Kredit::Kredit() {}

Kredit::Kredit(const string& id, const string& korisnik, double ukupanKredit, double dug, double placeno, int brojRata) {
    this->id = id;
    this->korisnik = korisnik;
    this->ukupanKredit = ukupanKredit;
    this->dug = dug;
    this->placeno = placeno;
    this->brojRata = brojRata;
}

string Kredit::getId() const {
    return id;
}

string Kredit::getKorisnik() const {
    return korisnik;
}

double Kredit::getUkupanKredit() const {
    return ukupanKredit;
}

double Kredit::getDug() const {
    return dug;
}

double Kredit::getPlaceno() const {
    return placeno;
}

int Kredit::getBrojRata() const {
    return brojRata;
}

void Kredit::setDug(double noviDug) {
    dug = noviDug;
}

void Kredit::setPlaceno(double novoPlaceno) {
    placeno = novoPlaceno;
}

void Kredit::setBrojRata(int noviBrojRata) {
    brojRata = noviBrojRata;
}

void Kredit::ispisiPodatkeKredita() const {

    cout << "ID: " << id << endl;
    cout << "Korisnik: " << korisnik << endl;
    cout << "Ukupan kredit: " << ukupanKredit << endl;
    cout << "Dug: " << dug << endl;
    cout << "Placeno: " << placeno << endl;
    cout << "Broj rata: " << brojRata << endl;
    cout << "--------------------------" << endl;
    cout << endl;

}