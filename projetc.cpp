#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include "projetcpp.h"

int Employe::nombreEmployes = 0;
//vector<Employe> Employe::listeEmployes;

Employe::Employe(string n, string p, int s,int nc) {
    this->nom = n;
    this->prenom = p;
    this->salaire = s;
    nombreEmployes++;
    this->nombreCompetences = 0;
    this->competences = new string[10];

    //listeEmployes.push_back(*this);
}
Employe::Employe(const Employe&e){
    nom=e.nom;
    prenom=e.prenom;
    salaire=e.salaire;
    nombreEmployes++;
    nombreCompetences=e.nombreCompetences;
    competences =new string[nombreCompetences];
    for(unsigned int i=0;i<nombreCompetences;i++){
    competences[i]=e.competences[i];
}
}
void Employe::afficherDetails() {
    cout << "Nom: " << nom << ", Prénom: " << prenom << ", Salaire: " << salaire << " DT" << endl;
}
Employe::~Employe() {
    nombreEmployes--;
    delete[] competences;
}
/*void Employe::ajouterEmploye(const Employe& emp) {
    listeEmployes.push_back(emp);
}

void Employe::afficherEmployes() {
    for (const auto& emp : listeEmployes) {
        emp.afficherDetails();
    }
}

void Employe::supprimerEmploye(int index) {
    if (index >= 0 && index < listeEmployes.size()) {
        listeEmployes[index] = listeEmployes.back();
        listeEmployes.pop_back();
    }
}*/
Test::Test(string c){
    this->codeTest=c;}

Test::~Test() {}

Responsable::Responsable(string n, string p, int s,int nc, string d) : Employe(n, p, s,nc) {
    this->departement = d;
}

Responsable::~Responsable() {}

void Responsable::afficherDetails() {
    Employe::afficherDetails();
    cout << "Poste: Responsable" << endl;
}

Pharmacien::Pharmacien(string n, string p, int s,int nc) : Employe(n, p, s,nc) {}

Pharmacien::Pharmacien (const Pharmacien& P): Employe(P.nom, P.prenom, P.salaire, P.nombreCompetences)
{
Test *T;
for (unsigned int i=0;i<P.tabTests.size();i++)
{
if (typeid(*P.tabTests[i])==typeid(Test)) {
T=new Test(*P.tabTests[i]);
}
else if (typeid(*P.tabTests[i])==typeid(TestEnvironnement)) {
T=new TestEnvironnement(static_cast<const TestEnvironnement&>(*P.tabTests[i]));
}
else if (typeid(*P.tabTests[i])==typeid(TestMicroBiologique)) {
T=new TestMicroBiologique(static_cast<const TestMicroBiologique&>(*P.tabTests[i]));
}
else if (typeid(*P.tabTests[i])==typeid(TestPurete)) {
T=new TestPurete(static_cast<const TestPurete&>(*P.tabTests[i]));
}
tabTests.push_back(T);
}
}
void Pharmacien::ajouterTest(const Test& T) {
    Test* t;
    if (typeid(T) == typeid(TestEnvironnement)) {
        t = new TestEnvironnement(dynamic_cast<const TestEnvironnement&>(T));
    } else if (typeid(T) == typeid(TestMicroBiologique)) {
        t = new TestMicroBiologique(dynamic_cast<const TestMicroBiologique&>(T));
    } else if (typeid(T) == typeid(TestPurete)) {

        t = new TestPurete(dynamic_cast<const TestPurete&>(T));
    }

    tabTests.push_back(t);
}

void Pharmacien::afficherTests() {
    cout << "Tests effectués par " << nom << " :" << endl;
    for (Test* test : tabTests) {
        cout << "- Code: " << test->getCodeTest() << endl;
    }
}

Pharmacien::~Pharmacien() {
for (unsigned int i=0;i<tabTests.size();i++){
    delete(tabTests[i]);}
}

int Pharmacien::rechercher(string code){
    int x=-1;
    for(unsigned int i=0;i<tabTests.size();i++){
            if (tabTests[i]->getCodeTest()==code){
                x=i;
            }
    return x;
    }
}

void Pharmacien::afficherDetails() {
    Employe::afficherDetails();
    cout << "Poste: Pharmacien" << endl;
}

void Pharmacien::supprimerTest(string code){
    int i = rechercher(code);
    if (i != -1) {
        delete tabTests[i];
        tabTests.erase(tabTests.begin() + i);
    }
}

void Pharmacien::modifierTest(string code, Test* nouveauTest) {
    for (unsigned int i = 0; i < tabTests.size(); i++) {
        if (rechercher(code)!=-1) {
            delete tabTests[i];
            tabTests[i] = nouveauTest;
            cout << "Test modifié : " << code << endl;
        }
    }
}

TestEnvironnement::TestEnvironnement(string code, int t, int h, int p) : Test(code) {
    this->temperature = t;
    this->humidite = h;
    this->pression = p;
}

TestPurete::TestPurete(string code, int p, int v, int d) : Test(code) {
    this->pH = p;
    this->viscosite = v;
    this->densite = d;
}

TestMicroBiologique::TestMicroBiologique(string code, int pb) : Test(code) {
    this->pourcentageBacterie = pb;
}

Stagiaire::Stagiaire(string n, string p, string ci, string m, int s, int nc, int d): Etudiant(n, p, ci, m), Employe(n, p, s, nc) {
    this->dureeStage = d;
}


Stagiaire::~Stagiaire() {}

Etudiant::Etudiant(string n, string p, string cin, string m) {
    this->nom = n;
    this->prenom = p;
    this->CIN = cin;
    this->mention = m;
}
Etudiant::~Etudiant() {}

string Employe::getNom() {
    return nom;
}

void Employe::setNom(string n) {
    nom = n;
}

string Employe::getPrenom() {
    return prenom;
}

void Employe::setPrenom(string p) {
    prenom = p;
}

int Employe::getSalaire() {
    return salaire;
}

void Employe::setSalaire(int s) {
    salaire = s;
}
string Etudiant::getNom() {
    return nom;
}

void Etudiant::setNom(string n) {
    nom = n;
}

string Etudiant::getPrenom() {
    return prenom;
}

void Etudiant::setPrenom(string p) {
    prenom = p;
}

string Etudiant::getCIN() {
    return CIN;
}

void Etudiant::setCIN(string cin) {
    CIN = cin;
}

string Etudiant::getMention() {
    return mention;
}

void Etudiant::setMention(string m) {
    mention = m;
}

int Stagiaire::getDureeStage() {
    return dureeStage;
}

void Stagiaire::setDureeStage(int d) {
    dureeStage = d;
}string Test::getCodeTest() {
    return codeTest;
}

void Test::setCodeTest(string code) {
    codeTest = code;
}string Responsable::getDepartement() {
    return departement;
}

void Responsable::setDepartement(string d) {
    departement = d;
}
void Employe::augmenterSalaire(int pourcentage) {
    salaire += salaire * pourcentage / 100;
}

int Employe::obtenirSalaire() {
    return salaire;
}
int Employe::obtenirNombreEmployes() {
    return nombreEmployes;
}

void TestEnvironnement::verifierConditions() {
    if (temperature > 50 || humidite > 80 || pression < 900) {
        cout << "Alerte : Conditions environnementales non conformes !" << endl;
    } else {
        cout << "Conditions environnementales normales." << endl;
    }
}

void TestPurete::estConforme() {
    if (pH >= 6 && pH <= 8 && viscosite < 10 && densite > 0.9) {
        cout << "Le test de pureté est conforme." << endl;
    } else {
        cout << "Le test de pureté n'est pas conforme." << endl;
    }
}
void Etudiant::postulerStage() {
    if (mention == "Excellent" || mention == "Très Bien") {
        cout << "Félicitations ! Votre candidature pour un stage a été acceptée immédiatement." << endl;
    } else {
        cout << "Votre candidature nécessite une lettre de motivation pour être évaluée." << endl;
    }
}
void TestMicroBiologique::controleSterilite() {
    if (pourcentageBacterie < 5) {
        cout << "Le test microbiologique est conforme : échantillon stérile." << endl;
    } else {
        cout << "Le test microbiologique est non conforme : présence excessive de bactéries !" << endl;
    }
}

