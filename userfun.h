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

string generisiNasumicniId();
string generisiNasumicniRacun();
void menuUser();
void userLogika(string username);
string kreirajKreditId();
void userTekuci(string username);
string kreirajRacun();
void userStedni(string username);
void userKredit(string username);
void digniKredit(string username);

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
                userStedni(username);
                break;
            case 3:
                userKredit(username);
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
    int opcija;
    while (!napusti) {
        cout << "Opcije:" << endl;
        cout << "1. Kreiraj tekuci racun" << endl;
        cout << "2. Pregled tekucih racuna" << endl;
        cout << "3. Nazad" << endl;
        cout << "Odabir: ";
        cin >> opcija;
        string broj;
        string vlasnik;
        double stanje = 0.0;
        switch (opcija) {
            case 1: {
                broj = kreirajRacun();
                vlasnik = username;
                Tekuci tekuci = Tekuci(
                    broj, 
                    vlasnik, 
                    stanje
                );
                listaTekucih.push_back(tekuci);
                prepisiTekuce();
                cout << "Uspjesno ste kreirali tekuci racun!" << endl;
                cout << "Za ostale detalje odaberite opciju \"Pregled tekucih racuna\"" << endl;
                pauza();
                break;
            }
            case 2: {
                ispisiTekuceRacune(username);
                cout << "Da li zelite izvrsiti uplatu na neki racun?" << endl;
                cout << "1. Da" << endl;
                cout << "2. Ne" << endl;
                cout << "Odabir: ";
                int daNe;
                cin >> daNe;
                switch (daNe) {
                    case 1: {
                        string tekuciBroj;
                        cout << "Unesite broj tekuceg racuna za uplatu:" << endl;
                        cin >> tekuciBroj;
                        bool pronaden = false;
                        for (auto& tekuci : listaTekucih) {
                            if (tekuciBroj == tekuci.getBroj()) {
                                double stari = tekuci.getStanje();
                                double iznos;
                                cout << "Unesite iznos za uplatu:" << endl;
                                cin >> iznos;
                                double novi = iznos + stari;
                                tekuci.setStanje(novi);
                                prepisiTekuce();
                                pronaden = true;
                                break;
                            }
                        }
                        if (!pronaden) {
                            cout << "Nije pronaden racun s unesenim brojem!" << endl;
                            pauza();
                        }
                        break;
                    }
                    case 2:
                        continue;
                        break;
                    default:
                        cout << "Unjeli ste nepostojecu opciju!" << endl;
                        pauza();
                        break;
                }
            }
            case 3:
                napusti = true;
                break;
            default:
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
    }
}

void userStedni(string username) {
    bool napusti = false;
    int opcija;
    while (!napusti) {
        cout << "Opcije:" << endl;
        cout << "1. Kreiraj stedni racun" << endl;
        cout << "2. Pregled stednih racuna" << endl;
        cout << "3. Nazad" << endl;
        cout << "Odabir: ";
        cin >> opcija;
        string broj;
        string vlasnik;
        double stanje = 0.0;
        switch (opcija) {
            case 1: {
                broj = kreirajRacun();
                vlasnik = username;
                Stedni stedni = Stedni(
                    broj,
                    vlasnik,
                    stanje
                );
                listaStednih.push_back(stedni);
                prepisiStedne();
                cout << "Uspjesno ste kreirali stedni racun!" << endl;
                cout << "Za ostale detalje odaberite opciju \"Pregled stednih racuna\"" << endl;
                pauza();
                break;
            }
            case 2: {
                ispisiStedneRacune(username);
                cout << "Da li zelite izvrsiti uplatu na neki racun?" << endl;
                cout << "1. Da" << endl; 
                cout << "2. Ne" << endl;
                cout << "Odabir: ";
                int daNe;
                cin >> daNe;
                switch (daNe) {
                    case 1: {
                        string stedniBroj;
                        cout << "Unesite broj stednog racuna za uplatu:" << endl;
                        cin >> stedniBroj;
                        bool pronaden = false;
                        for (auto& stedni : listaStednih)  {
                            if (stedniBroj == stedni.getBroj()) {
                                double stari = stedni.getStanje();
                                double iznos;
                                cout << "Unesite iznos za uplatu:" << endl;
                                cin >> iznos;
                                double novi = iznos + stari;
                                stedni.setStanje(novi);
                                prepisiStedne();
                                pronaden = true;
                                break;
                            }
                        }
                        if (!pronaden) {
                            cout << "Nije pronaden racun s unesenim brojem!" << endl;
                            pauza();
                        }
                        break;
                    }
                    case 2:
                        continue;
                        break;
                    default:
                        cout << "Unjeli ste nepostojecu opciju!" << endl;
                        pauza();
                        break;
                }
            }
            case 3:
                napusti = true;
                break;
            default:
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
    }
}

void userKredit(string username) {
    bool napusti = false;
    int opcije;
    while (!napusti) {
        cout << "Opcije:" << endl;
        cout << "1. Pregled kredita" << endl;
        cout << "2. Digni kredit" << endl;
        cout << "3. Plati ratu" << endl;
        cout << "4. Nazad" << endl; 
        cout << "Odabir: " << endl;
        cin >> opcije;
        switch (opcije) {
            case 1: 
                ispisiKredite(username);
                break;
            case 2: {
                cout << "Entering digniKredit function..." << endl;
                digniKredit(username);
                break;
            }
            case 3:
                break;
            case 4:
                napusti = true;
                break;
            default:
                cout << "Odabrali ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
    }
}

void digniKredit(string username) {
    string id, korisnik;
    double ukupno;
    double dug;
    double placeno = 0;
    int rate;
    korisnik = username;
    id = kreirajKreditId();
    cout << "Unesite kolicinu za dizanje kredita:" << endl;
    cin >> ukupno;
    cout << "Unesite broj mjeseci na kolko zelite odplatiti kredi:" << endl;
    cin >> rate;
    dug = ukupno;
    Kredit kredit(id, korisnik, ukupno, dug, placeno, rate);
    listaKredita.push_back(kredit);
    prepisiKredite();
    cout << "Uspjesno ste digli kredit!" << endl;
    pauza();
}

string kreirajKreditId() {
    string kreditId;
    while (true) {
        kreditId = generisiNasumicniId();
        bool nemaIsti = true;
        for (const auto& kredit : listaKredita) {
            if (kredit.getId() == kreditId) {
                nemaIsti = false;
                break;
            }
        }
        if (nemaIsti)
            break;
    }
    return kreditId;
}

string kreirajRacun() {
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

string generisiNasumicniId() {
    srand(static_cast<unsigned>(time(nullptr)));

    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const int idDuzina = 10;

    string nasumicniId;
    for (int i = 0; i < idDuzina; i++) {
        char nasumicniZnak = characters[rand() % characters.length()];
        nasumicniId += nasumicniZnak;
    }

    return nasumicniId;
}

#endif // USERFUN_H