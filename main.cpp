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
    Pharmacien e("Durand", "Claire", 5000,0);
    e=e+t1;
    e=e+t2;
    fstream f;
    e.creer(f);
    e.enregistrer_fichier();
    Pharmacien e2;
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
