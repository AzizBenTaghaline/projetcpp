#include <iostream>
#include <vector>
#include <fstream>
#include "projetcpp.h"  // Assure-toi d'avoir les bons headers selon ton organisation

using namespace std;

int main() {
    string c,c2;
    Test* t1 = new TestEnvironnement("ENV01", 14, 22,44);
    Test* t2 = new TestPurete("PURE01", 1, 99,69);
    Test* t3 = new TestMicroBiologique("MICRO01", 5);
    Employe e("Durand", "Claire", 5000,0);
    cout<<e;
    fstream f;
    e.creer(f);
    f<<&e;
    Employe e2;
    e2.lire_fichier();
    cout<<&e2;
    /*
    p.enregistrer_fichier();
    Pharmacien p2("Durand", "Claire", 5000,2);
    p2.lire_fichier();
    cout << "\nPharmacien lu depuis le fichier :\n";
    cout<<p2;*/
    return 0;
}
