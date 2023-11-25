// userfun.h

#ifndef USERFUN_H
#define USERFUN_H

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "klase.h"
#include "global.h"
#include "funkcije.h"

using namespace std;

void menuUser();
string generisiNasumicniRacun();
void userTekuci(string username);
string kreirajTekuciRacun();

void userLogika(string username) {
    while (true) {
        int option; 
        bool logOff = false;
        menuUser();
        cin >> option;
        switch (option) {
            case 1:
                userTekuci(username);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
    }
}

void menuUser() {
    cout << "Opcije:" << endl;
    cout << "1. Tekuci racuni" << endl;
    cout << "2. Stedni racuni" << endl;
    cout << "3. Krediti" << endl;
    cout << "4. Posalji novac" << endl;
    cout << "5. Transakcije" << endl;
    cout << "6. Odjava" << endl;
    cout << "Odabir: " << endl;
}

void userTekuci(string username) {
    bool napusti = false;
    while (true) {
        int opcija;
        cout << "Opcije:" << endl;
        cout << "1. Kreiraj tekuci racun" << endl;
        cout << "2. Pregled tekucih racuna" << endl;
        cout << "3. Nazad" << endl;
        cout << "Odabir: ";
        cin >> opcija;
        switch (opcija) {
            case 1: {
                    string broj = kreirajTekuciRacun();
                    string vlasnik = username;
                    double stanje = 0.0;
                    prepisiTekuce();
                    cout << "Uspjesno ste kreirali tekuci racun!" << endl;
                    cout << "Za ostale detalje odaberite opciju \"Pregled tekucih racuna\"" << endl;
                    pauza();
                }
                break;
            case 2: {
                int daNe;
                ispisiTekuceRacune();
                cout << "Da li zelite izvrsiti uplatu na neki racun?" << endl;
                cout << "1. Da" << endl;
                cout << "2. Ne" << endl;
                cout << "Odabir: ";
                cin >> daNe;
                bool ne = false;
                while (true) {
                    switch (daNe) {
                        case 1: {
                                string tekuciBroj;
                                cout << "Unesit broj tekuceg racuna za uplatu:" << endl;
                                cin >> tekuciBroj;
                                for (auto& tekuci : listaTekucih) {
                                    if (tekuciBroj == tekuci.getBroj()) {
                                        double stari = tekuci.getStanje();
                                        double iznos;
                                        cout << "Unesite iznos za uplatu:" << endl;
                                        cin >> iznos;
                                        double novi = iznos + stari;
                                        tekuci.setStanje(novi);
                                        prepisiTekuce();
                                    }
                                }
                            break;
                        }
                        case 2:
                            ne = true;
                            break;
                        default:
                            cout << "Unjeli ste nepostojecu opciju!" << endl;
                            pauza();
                            break;
                    }
                }
                if (ne)
                    break;
                break;
                }
            case 3:
                napusti = true;
                break;
            default:
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
        if (napusti)
            break;
    }
}

string kreirajTekuciRacun() {
    string tekuciRacun;
    while (true) {
        bool nemaIsti = false;
        tekuciRacun = generisiNasumicniRacun();
        for (const auto& tekuci : listaTekucih) {
            if (tekuci.getBroj() == tekuciRacun) {
                break;
            } else {
                nemaIsti = true;
            }
        }
        if (nemaIsti)
            break;
    }
    return tekuciRacun;
}

string generisiNasumicniRacun() {
    srand(static_cast<unsigned>(time(nullptr)));

    string nasumicniBrojevi;
    for (int i = 0; i < 16; i++) {
        int nasumicniBroj = rand() % 10;
        nasumicniBrojevi += to_string(nasumicniBroj);
    }

    return nasumicniBrojevi;
}

#endif // USERFUN_H