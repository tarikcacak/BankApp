// adminfun.h

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

void ispisiKorisnike();
void urediKorisnika(int selectedId);
void menuAdmin();
int dodajRadnika(Radnik radnik);
void urediRadnika(int selectedId);
int prepisiRadnike();
void kreirajUrediRadnika();
void tekuciRacuni();
void stedniRacuni();
void krediti();
void transakcije();

void adminLogika() {
    while (true) {
        int option;
        bool logOff = false;
        menuAdmin();
        cin >> option;
        switch (option) {
            case 1:
                if (!listaKorisnika.empty()) {
                    system("cls");
                    ispisiKorisnike();
                    int idKorisnika;
                    cin >> idKorisnika;
                    urediKorisnika(idKorisnika);
                } else {
                    system("cls");
                    cout << "Lista korisnika je prazna!" << endl;
                    pauza();
                }
                break;
            case 2:
                kreirajUrediRadnika();
                break;
            case 3: 
                tekuciRacuni();
                break;
            case 4:
                stedniRacuni();
                break;
            case 5:
                krediti();
                break;
            case 6:
                transakcije();
                break;
            case 7: 
                logOff = true;
                break;
            default: 
                cout << "Unjeli ste nepostojecu opciju!" << endl;
                pauza();
                break;
        }
        if (logOff) {
            break;
        }
    }
}

void menuAdmin() {
    system("cls");
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

void ispisiRadnike() {
    cout << "Radnici: " << endl;
    cout << endl;
    for (const auto& radnik : listaRadnika) {
        radnik.ispisiPodatkeRadnika();
    }
    cout << endl;
    cout << "Unesite ID radnika kojeg zelite urediti: ";
}

void urediKorisnika(int selectedId) {
    int opcija;
    int napusti = 0;
    const Korisnik* odabrani = nullptr;
    while (true) {
        for (const auto& korisnik : listaKorisnika) {
            if (korisnik.getId() == selectedId) {
                system("cls");
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
            system("cls");
            cout << "Username uspjesno promjenjen!" << endl;
            pauza();
            break;
        case 2: 
            system("cls");
            cout << "Unesite novi password:" << endl;
            cin >> noviPassword;
            const_cast<Korisnik*>(odabrani)->setPassword(noviPassword);
            prepisiKorisnike();
            system("cls");
            cout << "Password uspjesno promjenjen!" << endl;
            pauza();
            break;
        case 3: 
            system("cls");
            cout << "Unesite novi JMBG:" << endl;
            cin >> noviJMBG;
            const_cast<Korisnik*>(odabrani)->setJMBG(noviJMBG);
            prepisiKorisnike();
            system("cls");
            cout << "JMBG uspjesno promjenjen!" << endl;
            pauza();
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
    system("cls");
    cout << "Opcije:" << endl;
    cout << "1. Kreiraj radnika" << endl;
    cout << "2. Uredi radnika" << endl;
    cin >> odabir;
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
            Radnik radink(
                brojRadnika,
                username,
                password,
                JMBG
            );
            dodajRadnika(radink);
            break;
        }
        case 2: {
            if (!listaRadnika.empty()) {
                system("cls");
                ispisiRadnike();
                int idRadnika;
                cin >> idRadnika;
                urediRadnika(idRadnika);
            } else {
                system("cls");
                cout << "Lista radnika je prazna!" << endl;
                pauza();
            }
            break;
        }
        default: {
            system("cls");
            cout << "Odabrali ste nepostojecu opciju!" << endl;;
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
    outputFile << radnik.getPassword() << endl;
    outputFile << radnik.getJMBG() << endl;
    
    outputFile << endl;

    outputFile.close();

    system("cls");
    cout << "Uspjesno ste dodali radnika!" << endl;
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
    string username, password, JMBG;
    int linija = 0;
    while (inputFile >> radnikId >> username >> password >> JMBG) {
        linija++;
        if (linija % 5 == 0) {
            linija = 0;
            continue;
        }
        Radnik radnik(radnikId, username, password, JMBG);
        listaRadnika.push_back(radnik);
        brojRadnika++;
    }

    inputFile.close();

    return 0;
}

int prepisiRadnike() {
    string filename = "radnici.txt";

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }
    for (const auto& radnik : listaRadnika) {
        outputFile << radnik.getId() << endl;
        outputFile << radnik.getUsername() << endl;
        outputFile << radnik.getPassword() << endl;
        outputFile << radnik.getJMBG() << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

void urediRadnika(int slectedId) {
    int opcija;
    int napusti = 0;
    const Radnik* odabrani = nullptr;
    while (true) {
        for (const auto& radnik : listaRadnika) {
            if (radnik.getId() == slectedId) {
                system("cls");
                cout << "Podaci radnika: " << radnik.getUsername() << endl;
                cout << "Worker ID: " << radnik.getId() << endl;
                cout << "1. Username: " << radnik.getUsername() << endl;
                cout << "2. Password: " << radnik.getPassword() << endl;
                cout << "3. JMBG: " << radnik.getJMBG() << endl;
                cout << "--------------------------" << endl;
                cout << "Sta zelite urediti: ";
                napusti = 1;
                odabrani = &radnik;
                break;
            }
        }
        if (slectedId > brojRadnika) {
        system("cls");
        cout << "Unijeli ste ID nepostojećeg korisnika" << endl;
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
            const_cast<Radnik*>(odabrani)->setUsername(noviUsername);
            prepisiRadnike();
            cout << "Uspjesno promjenjen username!" << endl;
            pauza();
            break;
        case 2: 
            system("cls");
            cout << "Unesite novi password:" << endl;
            cin >> noviPassword;
            const_cast<Radnik*>(odabrani)->setPassword(noviPassword);
            prepisiRadnike();
            cout << "Uspjesno promjenjen password!" << endl;
            pauza();
            break;
        case 3: 
            system("cls");
            cout << "Unesite novi JMBG:" << endl;
            cin >> noviJMBG;
            const_cast<Radnik*>(odabrani)->setJMBG(noviJMBG);
            prepisiRadnike();
            cout << "Uspjesno promjenjen JMBG!" << endl;
            pauza();
            break;
        default:
            system("cls");
            cout << "Odabrali ste nepostojecu opciju!" << endl;
            pauza();
            break;
    }
}

void tekuciRacuni() {
    int opcija;
    string broj;
    system("cls");
    cout << "Tekuci racuni:" << endl;
    cout << endl;
    for (auto& tekuci : listaTekucih) {
        tekuci.ispisiPodatkeTekuceg();
    }
    while (true) {
        cout << "Da li zelite izbrisati neki tekuci racun:" << endl;
        cout << "1.Da" << endl;
        cout << "2.Ne" << endl;
        cin >> opcija;
        if (opcija == 1) {
            cout << "Unesite broj racuna koji zelite izbrisati:" << endl;
            cin >> broj;
            for (auto it = listaTekucih.begin(); it != listaTekucih.end(); ++it) {
                if (it->getBroj() == broj) {
                    listaTekucih.erase(it);
                    prepisiTekuce();
                    system("cls");
                    cout << "Tekuci racun: " << broj << " je uspjesno izbrisan!" << endl;
                    pauza();
                    return;
                }
            }
        } else if (opcija == 2) {
            return;
        } else {
            system("cls");
            cout << "Unjeli ste nepostojecu opciju!" << endl;
            pauza();
        }
    }
}

void stedniRacuni() {
    int opcija;
    string broj;
    system("cls");
    cout << "Stedni racuni:" << endl;
    cout << endl;
    for (auto& stedni : listaStednih) {
        stedni.ispisiPodatkeStednog();
    }
    while (true) {
        cout << "Da li zelite izbrisati neki stedni racun:" << endl;
        cout << "1.Da" << endl;
        cout << "2.Ne" << endl;
        cin >> opcija;
        if (opcija == 1) {
            cout << "Unesite broj racuna koji zelite izbrisati:" << endl;
            cin >> broj;
            for (auto it = listaStednih.begin(); it != listaStednih.end(); ++it) {
                if (it->getBroj() == broj) {
                    listaStednih.erase(it);
                    prepisiStedne();
                    system("cls");
                    cout << "Stedni racun: " << broj << " je uspjesno izbrisan!" << endl;
                    pauza();
                    return;
                }
            }
        } else if (opcija == 2) {
            return;
        } else {
            system("cls");
            cout << "Unjeli ste nepostojecu opciju!" << endl;
            pauza();
        }
    }
}

void krediti() {
    int opcija;
    string id;
    system("cls");
    cout << "Krediti:" << endl;
    cout << endl;
    for (auto& kredit : listaKredita) {
        kredit.ispisiPodatkeKredita();
    }
    while (true) {
        cout << "Da li zelite zavrsiti neki kredit:" << endl;
        cout << "1.Da" << endl;
        cout << "2.Ne" << endl;
        cin >> opcija;
        if (opcija == 1) {
            cout << endl;
            cout << "Unesite ID kredita:" << endl;
            cin >> id;
            for (auto it = listaKredita.begin(); it != listaKredita.end(); ++it) {
                if (it->getId() == id) {
                    listaKredita.erase(it);
                    prepisiKredite();
                    system("cls");
                    cout << "Kredit s ID: " << id << " je uspjesno zavrsen!" << endl;
                    pauza();
                    return;
                }
            }
        } else if (opcija == 2) {
            return;
        } else {
            cout << "Unjeli ste nepostojecu opciju!" << endl;
            pauza();
        }
    }
}

void transakcije() {
    system("cls");
    cout << "Transakcije:" << endl;
    cout << endl;
    if (listaTransakcija.empty()) {
        cout << "Lista transakcija je prazna!" << endl;
    } else {
        for (auto& transakcija : listaTransakcija) {
            transakcija.ispisiPodatkeTransakcije();
        }
    }
    cout << endl;
    pritisniEnterZaNastavak();
    cout.flush();
}

#endif // ADMINFUN_H