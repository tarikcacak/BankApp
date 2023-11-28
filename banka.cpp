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
#include "userfun.h"

using namespace std;

int main() {
    ucitajKorisnike();
    ucitajRadnike();
    ucitajTekuce();
    ucitajStedne();
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
                adminLogika();
            } else {
                bool poklapanjeKorisnik = false;
                bool poklapanjeRadnik = false; 
                for (const auto& korisnik : listaKorisnika) {
                    if (korisnik.provjeriPodatke(username, password)) {
                        poklapanjeKorisnik = true;
                        break;
                    }
                }
                for (const auto& radnik : listaRadnika) {
                    if (radnik.provjeriPodatke(username, password)) {
                        poklapanjeRadnik = true;
                        break;
                    }
                }
                if (poklapanjeKorisnik) {
                    userLogika(username);
                } else if (poklapanjeRadnik) {
                    adminLogika();
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