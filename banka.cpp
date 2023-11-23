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
    while (true) {
        system("cls");
        int option;
        cout << "1. Prijava" << endl;
        cout << "2. Registracija" << endl;
        cout << "3. Exit" << endl;
        cout << "Broj usera: " << brojUsera << endl;
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
                    
                    menuAdmin();
                    cin >> option;
                    switch (option) {
                        case 1:
                            ispisiKorisnike();
                            int idKorisnika;
                            cin >> idKorisnika;
                            urediKorisnika(idKorisnika);
                            break;
                        case 2:
                            
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
                            break;
                        default: 
                            cout << "Unjeli ste nepostojecu opciju!"
                            pauza();
                            break;
                    }
                }
            } else {
                bool poklapanjeKorisnik = false;
                for (const auto& korisnik : listaKorisnika) {
                    if (korisnik.provjeriPodatke(username, password)) {
                        poklapanje = true;
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
            while (true) {
                cout << "Unesite password:" << endl;
                cin >> password;
                cout << "Potvrdite password:" << endl;
                cin >> passwordConf;
                if (password == passwordConf) {
                    break;
                }
                system("cls");
            }
            while (true) {
                cout << "Unesite svoj JMBG: " << endl;
                cin >> JMBG;
                if (!(JMBG.length() == 12)) {
                    system("cls");
                    cout << "JMBG mora imati tacno 12 brojeva!" << endl;
                    pauza();
                }
                bool allDigits = true;
                for (char c : JMBG) {
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
                if (JMBG.length() == 12 && allDigits == true) {
                    break;
                }
            }
            Korisnik korisnik(
                brojUsera + 1,
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