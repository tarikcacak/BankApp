// banka.cpp

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "klase.h"
#include "funkcije.h"
#include "global.h"
#include "adminfun.h"

using namespace std;

int main() {
    ucitajKorisnike();
    ucitajRadnike();
    while (true) {
        system("cls");
        int option;
        cout << "1. Prijava" << endl;
        cout << "2. Registracija" << endl;
        cout << "3. Exit" << endl;
        cin >> option;
        if (option == 1) {
            string username;
            string password;
            cout << "Unesite svoj username:" << endl;
            cin >> username;
            cout << "Unesite svoj password:" << endl;
            cin >> password;
            if (username == "admin" && password == "admin") {
                while (true) {
                    int option;
                    bool logOff = false;
                    menuAdmin();
                    cin >> option;
                    switch (option) {
                        case 1:
                            if (!listaKorisnika.empty()) {
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
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7: 
                            logOff = true;
                            break;
                        default: 
                            cout << "Unjeli ste nepostojecu opciju!";
                            pauza();
                            break;
                    }
                    if (logOff) {
                        break;
                    }
                }
            } else {
                bool poklapanjeKorisnik = false;
                for (const auto& korisnik : listaKorisnika) {
                    if (korisnik.provjeriPodatke(username, password)) {
                        poklapanjeKorisnik = true;
                        break;
                    }
                }
                if (poklapanjeKorisnik) {
                    cout << "Uspjesno ste se prijavili" << endl;
                    pauza();
                } else {
                    cout << "Prijava neuspjesna" << endl;
                    pauza();
                }
            }
        } else if (option == 2) {
            string username;
            string password;
            string passwordConf;
            string JMBG;
            cout << "Unesite username:" << endl;
            cin >> username;
            uporediPassword(&password, &passwordConf);
            provjeriJMBG(&JMBG);
            Korisnik korisnik(
                brojUsera,
                username,
                password,
                JMBG
            );
            dodajKorisnika(korisnik);
        } else if (option == 3) {
            exit(0);
        } else {
            system("cls");
            cout << "Unjeli ste nepostojecu opciju!" << endl;
            pauza();
        }
    }

    return 0;
}