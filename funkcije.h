// funkcije.h

#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "klase.h"
#include "global.h"

using namespace std;

void pauza() {
    cout << endl;
    cout << "Program se nastavlja za 3 sekunde..." << endl;
    chrono::seconds delaySeconds(3);
    this_thread::sleep_for(delaySeconds);
}

int dodajKorisnika(Korisnik korisnik) {
    ofstream outputFile("korisnici.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    outputFile << korisnik.getId() << endl;
    outputFile << korisnik.getUsername() << endl;
    outputFile << korisnik.getPassword() << endl;
    outputFile << korisnik.getJMBG() << endl;
    outputFile << endl;

    outputFile.close();

    system("cls");
    cout << "Uspjesno ste dodali korisnika!";
    pauza();
    listaKorisnika.push_back(korisnik);
    brojUsera++;

    return 0;
}

int ucitajKorisnike() {
    string filename = "korisnici.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
    }

    int userId;
    string username, password, JMBG;
    int linija = 0;
    while (inputFile >> userId >> username >> password >> JMBG) {
        linija++;
        if (linija % 5 == 0) {
            linija = 0;
            continue;
        }
        Korisnik korisnik(userId, username, password, JMBG);
        listaKorisnika.push_back(korisnik);
        brojUsera++;
    }

    inputFile.close();

    return 0;
}

int prepisiKorisnike() {
    string filename = "korisnici.txt";

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    for (const auto& korisnik : listaKorisnika) {
        outputFile << korisnik.getId() << endl;
        outputFile << korisnik.getUsername() << endl;
        outputFile << korisnik.getPassword() << endl;
        outputFile << korisnik.getJMBG() << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

void uporediPassword(string* password, string* passwordConf) {
    while (true) {
        cout << "Unesite password:" << endl;
        cin >> *password;
        cout << "Potvrdite password:" << endl;
        cin >> *passwordConf;
        if (*password == *passwordConf) {
            break;
        }
        system("cls");
    }
}

void provjeriJMBG(string* JMBG) {
    while (true) {
        cout << "Unesite JMBG: " << endl;
        cin >> *JMBG;
        if (!(JMBG->length() == 12)) {
            system("cls");
            cout << "JMBG mora imati tacno 12 brojeva!" << endl;
            pauza();
        }
        bool allDigits = true;
        for (char c : *JMBG) {
            if (!isdigit(c)) {
                allDigits = false;
                break;
            }
        }
        if (!allDigits) {
            system("cls");
            cout << "JMBG se smije sastojati samo od brojeva!" << endl;
            pauza();
        }
        if (JMBG->length() == 12 && allDigits == true) {
            break;
        }
    }
}

void ispisiTekuceRacune() {
    cout << "Vasi tekuci racuni:" << endl;
    cout << endl;
    for (const auto& tekuci : listaTekucih) {
        tekuci.ispisiPodatkeTekuceg
    }
}

void prepisiTekuce() {
    string filename = "tekuci.txt";

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    for (const auto& tekuci : listaTekucih) {
        outputFile << tekuci.getBroj() << endl;
        outputFile << tekuci.getVlasnik() << endl;
        outputFile << tekuci.getStanje() << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

void ucitajTekuce() {
    string filename = "tekuci.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
    }

    string broj, vlasnik;
    double stanje;
    int linija = 0;
    while (inputFile >> broj >> vlasnik >> stanje) {
        linija++;
        if (linija % 5 == 0) {
            linija = 0;
            continue;
        }
        Tekuci tekuci(broj, vlasnik, stanje);
        listaTekucih.push_back(tekuci);
    }

    inputFile.close();

    return 0;
}

#endif // FUNKCIJE_H