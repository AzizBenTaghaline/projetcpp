#include <iostream>
#include <vector>
#include <fstream>
#include "projetcpp.h"  // Assure-toi d'avoir les bons headers selon ton organisation

using namespace std;

int main() {
    Test* t1 = new TestEnvironnement("ENV01", 14, 22,44);
    Test* t2 = new TestPurete("PURE01", 1, 99,69);
    Test* t3 = new TestMicroBiologique("MICRO01", 5);
    Pharmacien p("Durand", "Claire", 5000,2);
    fstream f;
    p.creer(f);
    cin>>p;
    f<<&p;
    //f.clear();
    //f.seekg(0);
    Pharmacien p2;
    f>>&p2;
    cout<<&p2;
    /*
    cout << "Pharmacien sauvegardé dans le fichier.\n";
    p.enregistrer_fichier();
    Pharmacien p2("Durand", "Claire", 5000,2);
    p2.lire_fichier();
    cout << "\nPharmacien lu depuis le fichier :\n";
    cout<<p2;*/
    return 0;
}
