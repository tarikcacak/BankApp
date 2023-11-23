// adminFunkcije.h

#ifndef ADMINFUN_H
#define ADMINFUN_H

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <iterator>
#include <algorithm>
#include "klase.h"
#include "global.h"
#include "funkcije.h"

using namespace std;

void menuAdmin() {
    cout << "Opcije: " << endl;
    cout << "1. Uredi korisnika" << endl;
    cout << "2. Kreiraj/uredi radnika" << endl;
    cout << "3. Tekuci racuni" << endl;
    cout << "4. Stedni racuni" << endl;
    cout << "5. Krediti" << endl;
    cout << "6. Transakcije" << endl;
    cout << "7. Odjava" << endl;
    cout << "Odabir: ";
}

void ispisiKorisnike() {
    cout << "Korisnici: " << endl;
    cout << endl;
    for (const auto& korisnik : listaKorisnika) {
        korisnik.ispisiKorisnickePodatke();
    }
    cout << endl;
    cout << "Unesite ID korisnika kojeg zelite urediti: ";
}

void urediKorisnika(int selectedId) {
    int opcija;
    int napusti = 0;
    const Korisnik* odabrani = nullptr;
    while (true) {
        for (const auto& korisnik : listaKorisnika) {
            if (korisnik.getId() == selectedId) {
                cout << "Podaci korisnika: " << korisnik.getUsername() << endl;
                cout << "User ID: " << korisnik.getId() << endl;
                cout << "1. Username: " << korisnik.getUsername() << endl;
                cout << "2. Password: " << korisnik.getPassword() << endl;
                cout << "3. JMBG: " << korisnik.getJMBG() << endl;
                cout << "--------------------------" << endl;
                cout << "Sta zelite urediti: ";
                napusti = 1;
                odabrani = &korisnik;
                break;
            }
        }
        if (selectedId > brojUsera) {
            system("cls");
            cout << "Unjeli ste ID nepostojeceg korisnika!" << endl;
            pauza();
            break;
        }
        if (napusti == 1) {
            break;
        }
    }
    cin >> opcija;
    string noviUsername = "";
    string noviPassword = "";
    string noviJMBG = "";
    switch (opcija) {
        case 1:
            system("cls");
            cout << "Unesite novi username:" << endl;
            cin >> noviUsername;
            const_cast<Korisnik*>(odabrani)->setUsername(noviUsername);
            prepisiKorisnike();
            break;
        case 2: 
            system("cls");
            cout << "Unesite novi password:" << endl;
            cin >> noviPassword;
            const_cast<Korisnik*>(odabrani)->setUsername(noviUsername);
            prepisiKorisnike();
            break;
        case 3: 
            system("cls");
            cout << "Unesite novi JMBG:" << endl;
            cin >> noviJMBG;
            const_cast<Korisnik*>(odabrani)->setUsername(noviUsername);
            prepisiKorisnike();
            break;
        default:
            system("cls");
            cout << "Odabrali ste nepostojecu opciju!" << endl;
            pauza();
            break;
    }
}

void kreirajUrediRadnika() {
    int odabir;
    cout << "Opcije:" << endl;
    cout << "1. Kreiraj radnika" << endl;
    cout << "2. Uredi radnika" << endl;
    switch (odabir) {
        case 1: {
            system("cls");
            string username;
            string password;
            string passwordConf;
            string JMBG;
            cout << "Unesite username radnika:" << endl;
            cin >> username;
            uporediPassword(&password, &passwordConf);
            provjeriJMBG(&JMBG);
            break;
        }
        case 2: {
            break;
        }
        default: {
            system("cls");
            cout << "Odabrali ste nepostojecu opciju!";
            pauza();
        }
    }
}

int dodajRadnika(Radnik radnik) {
    ofstream outputFile("radnici.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    outputFile << radnik.getId() << endl;
    outputFile << radnik.getUsername() << endl;
    outputFile << radnik.getJMBG() << endl;
    outputFile << endl;

    outputFile.close();

    system("cls");
    cout << "Uspjesno ste dodali radnika!";
    pauza();
    listaRadnika.push_back(radnik);
    brojRadnika++;

    return 0;
}

int ucitajRadnike() {
    string filename = "radnici.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
    }

    int radnikId;
    string ime, prezime, JMBG;
    int linija = 0;
    while (inputFile >> radnikId >> ime >> prezime >> JMBG) {
        linija++;
        if (linija % 5 == 0) {
            linija = 0;
            continue;
        }
        Radnik radnik(radnikId, ime, prezime, JMBG);
        listaRadnika.push_back(radnik);
        brojRadnika++;
    }

    inputFile.close();

    return 0;
}

int prepisiRadnike() {
    string filename = "radnici.txt";

    cout << "test" << endl;

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    for (const auto& radnik : listaRadnika) {
        outputFile << radnik.getId() << endl;
        outputFile << radnik.getUsername() << endl;
        outputFile << radnik.getJMBG() << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

#endif // ADMINFUN_H