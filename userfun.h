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
#include <memory>
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
void platiRatu(string username);
void posaljiNovac(string username);
void transakcije(string username);

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
                posaljiNovac(username);
                break;
            case 5:
                transakcije(username);
                break;
            case 6:
                logOff = true;
                break;
            default:
                system("cls");
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
        if (logOff == true) {
            break;
        }
    }
}

void menuUser() {
    system("cls");
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
        system("cls");
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
                system("cls");
                cout << "Uspjesno ste kreirali tekuci racun!" << endl;
                cout << "Za ostale detalje odaberite opciju \"Pregled tekucih racuna\"" << endl;
                pauza();
                break;
            }
            case 2: {
                system("cls");
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
                        cout << endl;
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
                                system("cls");
                                cout << "Uspjesno ste izvrsili uplatu" << endl;
                                pauza();
                                pronaden = true;
                                break;
                            }
                        }
                        if (!pronaden) {
                            system("cls");
                            cout << "Nije pronaden racun s unesenim brojem!" << endl;
                            pauza();
                        }
                        break;
                    }
                    case 2:
                        continue;
                        break;
                    default:
                        system("cls");
                        cout << "Unjeli ste nepostojecu opciju!" << endl;
                        pauza();
                        break;
                }
            }
            case 3:
                napusti = true;
                break;
            default:
                system("cls");
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
        system("cls");
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
                system("cls");
                cout << "Uspjesno ste kreirali stedni racun!" << endl;
                cout << "Za ostale detalje odaberite opciju \"Pregled stednih racuna\"" << endl;
                pauza();
                break;
            }
            case 2: {
                system("cls");
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
                        cout << endl;
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
                                system("cls");
                                cout << "Uplata na stedni racun uspjesna!" << endl;
                                pauza();
                                break;
                            }
                        }
                        if (!pronaden) {
                            system("cls");
                            cout << "Nije pronaden racun s unesenim brojem!" << endl;
                            pauza();
                        }
                        break;
                    }
                    case 2:
                        continue;
                        break;
                    default:
                        system("cls");
                        cout << "Unjeli ste nepostojecu opciju!" << endl;
                        pauza();
                        break;
                }
            }
            case 3:
                napusti = true;
                break;
            default:
                system("cls");
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
    }
}

void userKredit(string username) {
    cout << username << endl;
    bool napusti = false;
    int opcije;
    while (!napusti) {
        system("cls");
        cout << "Opcije:" << endl;
        cout << "1. Pregled kredita" << endl;
        cout << "2. Digni kredit" << endl;
        cout << "3. Plati ratu" << endl;
        cout << "4. Nazad" << endl; 
        cout << "Odabir: " << endl;
        cin >> opcije;
        switch (opcije) {
            case 1: 
                system("cls");
                ispisiKredite(username);
                pritisniEnterZaNastavak();
                break;
            case 2: {
                digniKredit(username);
                break;
            }
            case 3:
                platiRatu(username);
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
    system("cls");
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
    cout << korisnik << endl;
    Kredit kredit(id, korisnik, ukupno, dug, placeno, rate);
    listaKredita.push_back(kredit);
    prepisiKredite();
    system("cls");
    cout << "Uspjesno ste digli kredit!" << endl;
    pauza();
}

void platiRatu(string username) {
    if (listaKredita.empty()) {
        system("cls");
        cout << "Nemate kredita!" << endl;
        pauza();
    } else {
        system("cls");
        ispisiKredite(username);
        string id;
        double rata;
        double noviDug;
        double placeno;
        cout << "Unesite ID kredita ciju ratu zelite uplatiti:" << endl;
        cin >> id;
        for (auto& kredit : listaKredita) {
            if (id == kredit.getId()) {
                rata = kredit.getUkupanKredit() / kredit.getBrojRata();
                cout << rata << endl;
                noviDug = kredit.getDug() - rata;
                cout << noviDug << endl;
                kredit.setDug(noviDug);
                placeno = kredit.getPlaceno();
                placeno += rata;
                kredit.setPlaceno(placeno);
                break;
            }
        }
        prepisiKredite();
        cout << endl;
        system("cls");
        cout << "Uspjesno ste platili ratu!" << endl;
        pauza();
    }
}

void posaljiNovac(string username) {
    shared_ptr<Tekuci> posiljaocObj = nullptr;
    shared_ptr<Tekuci> primaocObj = nullptr;
    string posiljaoc;
    string primaoc; 
    double iznos;
    double stanjePosiljaoc;
    double novoStanje;
    system("cls");
    cout << "Unesite tekuci racun sa kojeg saljete:" << endl;
    cin >> posiljaoc;
    for (auto& tekuciPos : listaTekucih) {
        if (posiljaoc == tekuciPos.getBroj()) {
            if (username == tekuciPos.getVlasnik()) {
                posiljaocObj = make_shared<Tekuci>(tekuciPos);
                stanjePosiljaoc = tekuciPos.getStanje();
                cout << "Unesite vrijednost koju zelite poslati:" << endl;
                cin >> iznos;
                cout << "Unesite racun na koji saljete:" << endl;
                cin >> primaoc;
                for (auto& tekuci : listaTekucih) {
                    if (primaoc == tekuci.getBroj()) {
                        novoStanje = stanjePosiljaoc - iznos;
                        cout << novoStanje << endl;
                        if (novoStanje < 0) {
                            system("cls");
                            cout << "Nemate dovoljno sredstava za transakciju!" << endl;
                            pauza();
                        } else {
                            cout << posiljaocObj->getStanje() << endl;
                            tekuciPos.setStanje(novoStanje);
                            prepisiTekuce();
                            cout << posiljaocObj->getStanje() << endl;
                            novoStanje = tekuci.getStanje() + iznos;
                            tekuci.setStanje(novoStanje);
                            prepisiTekuce();
                            primaocObj = make_shared<Tekuci>(tekuci);
                            Transakcija transakcija(posiljaocObj, primaocObj, iznos);
                            listaTransakcija.push_back(transakcija);
                            prepisiTransakcije();
                            system("cls");
                            cout << "Transakcija uspjesno izvrsena!" << endl;
                            pauza();
                        }
                        break;
                    }
                }
                break;
            } else {
                system("cls");
                cout << "Ovaj racun nije vas!" << endl;
                pauza();
                return;
            }
        }
    }
}

void transakcije(string username) {
    system("cls");
    ispisiTransakcije(username);
    cout << endl;
    pritisniEnterZaNastavak();
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