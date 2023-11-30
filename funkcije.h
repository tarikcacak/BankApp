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

void ispisiTekuceRacune(string username) {
    int counter = 0;
    cout << "Vasi tekuci racuni:" << endl;
    cout << endl;
    for (const auto& tekuci : listaTekucih) {
        if (username == tekuci.getVlasnik()) {
            tekuci.ispisiPodatkeTekuceg();
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Nemate tekucih racunar!" << endl;
        pauza();
    }
}

int prepisiTekuce() {
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

void ispisiStedneRacune(string username) {
    int counter = 0;
    cout << "Vasi stedni racuni:" << endl;
    cout << endl;
    for (const auto& stedni : listaStednih) {
        if (username == stedni.getVlasnik()) {
            stedni.ispisiPodatkeStednog();
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Nemate stednih racuna!" << endl;
        pauza();
    }
}

void ispisiKredite(string username) {
    int counter = 0;
    cout << "Vasi krediti:" << endl;
    cout << endl;
    for (const auto& kredit : listaKredita) {
        if (username == kredit.getKorisnik()) {
            kredit.ispisiPodatkeKredita();
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Nemate kredita!" << endl;
        pauza();
    }
}

int prepisiStedne() {
    string filename = "stedni.txt";

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    for (const auto& stedni : listaStednih) {
        outputFile << stedni.getBroj() << endl;
        outputFile << stedni.getVlasnik() << endl;
        outputFile << stedni.getStanje() << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

int ucitajTekuce() {
    string filename = "tekuci.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }

    string broj, vlasnik;
    double stanje;
    int linija = 0;
    while (inputFile >> broj >> vlasnik >> stanje) {
        linija++;
        if (linija % 4 == 0) {
            linija = 0;
            continue;
        }
        Tekuci tekuci(broj, vlasnik, stanje);
        listaTekucih.push_back(tekuci);
    }

    inputFile.close();

    return 0;
}

int ucitajStedne() {
    string filename = "stedni.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }

    string broj, vlasnik;
    double stanje;
    int linija = 0;
    while (inputFile >> broj >> vlasnik >> stanje) {
        linija++;
        if (linija % 4 == 0) {
            linija = 0;
            continue;
        }
        Stedni stedni(broj, vlasnik, stanje);
        listaStednih.push_back(stedni);
    }

    inputFile.close();

    return 0;
}

int prepisiKredite() {
    string filename = "krediti.txt";

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    for (const auto& kredit : listaKredita) {
        outputFile << kredit.getId() << endl;
        outputFile << kredit.getKorisnik() << endl;
        outputFile << kredit.getUkupanKredit() << endl;
        outputFile << kredit.getDug() << endl;
        outputFile << kredit.getPlaceno() << endl;
        outputFile << kredit.getBrojRata() << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

int ucitajKredite() {
    string filename = "krediti.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }

    string id, korisnik;
    double ukupanKredit, dug, placeno;
    int brojRata;
    int linija = 0;
    while (inputFile >> id >> korisnik >> ukupanKredit >> dug >> placeno >> brojRata) {
        linija++;
        if (linija % 7 == 0) {
            linija = 0;
            continue;
        }
        Kredit kredit(id, korisnik, ukupanKredit, dug, placeno, brojRata);
        listaKredita.push_back(kredit);
    } 

    inputFile.close();

    return 0;
}

#endif // FUNKCIJE_H