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

    cout << "test" << endl;

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

#endif // FUNKCIJE_H