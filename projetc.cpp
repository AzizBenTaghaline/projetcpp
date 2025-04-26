#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <istream>

using namespace std;
#include "projetcpp.h"

int Employe::nombreEmployes = 0;
//vector<Employe> Employe::listeEmployes;

Employe::Employe(string n, string p, int s,int nc) {
    this->nom = n;
    this->prenom = p;
    this->salaire = s;
    nombreEmployes++;
    this->nombreCompetences = nc;
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
}}
ostream& operator<<(ostream& out, Employe& e )
{ out<< "Nom: " << e.nom << ", Prénom: " << e.prenom << ", Salaire: " << e.salaire << " DT" << "Le nombre des competences:"<<e.nombreCompetences<<endl;
 for (int i = 0; i < e.nombreCompetences; ++i) {
        out << "  - Compétence " << i + 1 << ": " << e.competences[i] << endl;}
return out;
}
ostream& operator<<(ostream& out,Test& t )
{ out<<t.codeTest <<endl;
return out;
}
Employe::~Employe() {
    nombreEmployes--;
    delete[] competences;
}
Employe&Employe::operator=(const Employe& e)
{
if (this != &e)
{
delete[] competences;
nom=e.nom;
prenom=e.prenom;
salaire=e.salaire;
nombreCompetences=e.nombreCompetences;
competences =new string[nombreCompetences];
for(unsigned int i=0;i<nombreCompetences;i++){
competences[i]=e.competences[i];}
}
return *this; }

string & Employe :: operator[](int i)
{if((i<0)||(i>=nombreCompetences)){
        Exception_Indice e(i);
        throw e;}
return(competences[i]);
}

Test::Test(string c){
    this->codeTest=c;}

Test::~Test() {}

Test::Test(const Test* T){
    codeTest=T->codeTest;}

Responsable::Responsable(string n, string p, int s,int nc, string d) : Employe(n, p, s,nc) {
    this->departement = d;
}

Responsable::~Responsable() {}

ostream& operator<<(ostream& out, Responsable& r )
{   Employe* e=&r;
    out<<*e<<", Le departement:"<<r.departement<<endl;
return out;}

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
}}

Pharmacien Pharmacien::operator+(const Test* t) {
    Pharmacien P = *this;

    Test* newTest;

    if (auto env = dynamic_cast<const TestEnvironnement*>(t)) {
        newTest = new TestEnvironnement(*env);
    } else if (auto pur = dynamic_cast<const TestPurete*>(t)) {
        newTest = new TestPurete(*pur);
    } else if (auto micro = dynamic_cast<const TestMicroBiologique*>(t)) {
        newTest = new TestMicroBiologique(*micro);
    }
    P.tabTests.push_back(newTest);
    return P;
}

/*void Pharmacien::afficherTests() {
    cout << "Tests effectués par " << nom << " :" << endl;
    for (Test* test : tabTests) {
        cout << "- Code: " << test->getCodeTest() << endl;
    }
}*/

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
    }
    return x;
}

ostream & operator<<(ostream &out, Pharmacien& P)
{   Employe* e=&P;
    out<<*e;
    for (int i=0; i<P.tabTests.size(); i++){
    if (typeid(*P.tabTests[i])==typeid(TestEnvironnement))
    out<<static_cast<TestEnvironnement&>(*P.tabTests[i])<<endl;
    else if (typeid(*P.tabTests[i])==typeid(TestMicroBiologique))
    out<<static_cast<TestMicroBiologique&>(*P.tabTests[i])<<endl;
    else if (typeid(*P.tabTests[i])==typeid(TestPurete))
    out<<static_cast<TestPurete&>(*P.tabTests[i])<<endl;}
    return out;}

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

Test* & Pharmacien :: operator[](int a){
    return(tabTests[a]);}

Pharmacien& Pharmacien::operator=(const Pharmacien& P)
{
Test *T;
if (this != &P)
{
for (unsigned int i=0;i<tabTests.size();i++)
{
delete tabTests[i];
}
tabTests.clear();
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
return *this; }

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
ostream& operator<<(ostream& out, Etudiant& e ){
{ out<< "Nom: " << e.nom << ", Prénom: " << e.prenom << ", CIN: " << e.CIN << " DT" << ", La mention:"<<e.mention<<endl;
    map<string, float>::iterator it;
    for (it =e.notes.begin(); it !=e.notes.end(); ++it) {
    out << "Matière : " << it->first << " | Note : " << it->second << endl;
    }
}

return out;}
ostream& operator<<(ostream& out, TestEnvironnement& te )
{   Test* t=&te;
    out<<*t<<te.temperature<<endl<<te.humidite<<endl<<te.pression;
return out;}

ostream& operator<<(ostream& out, TestMicroBiologique& tm )
{   Test* t=&tm;
    out<<*t<<tm.pourcentageBacterie;
return out;}

ostream& operator<<(ostream& out, TestPurete& tp )
{   Test* t=&tp;
    out<<*t<<tp.pH<<endl<<tp.viscosite<<endl<<tp.densite;
return out;}
ostream& operator<<(ostream& out, Stagiaire& s)
{
    Employe* e = &s;
    Etudiant* etu = &s;
    out << *e;
    out << *etu;
    out << "Durée du stage : " << s.dureeStage<< " jours" << endl;
    return out;
}

istream& operator>>(istream& in, Employe& e) {
    cout << "Nom: ";
    in >> e.nom;
    cout << "Prénom: ";
    in >> e.prenom;
    cout << "Salaire: ";
    in >> e.salaire;
    cout << "Nombre de compétences: ";
    in >> e.nombreCompetences;
    delete[] e.competences;
    e.competences = new string[e.nombreCompetences];
    for (int i = 0; i < e.nombreCompetences; ++i) {
        cout << "Compétence " << i + 1 << ": ";
        in >> e.competences[i];
    }
    return in;
}
istream& operator>>(istream& in, Test& t) {
    cout << "Code du test: ";
    in >> t.codeTest;
    return in;
}
istream& operator>>(istream& in, Responsable& r) {
    Employe* e=&r;
    in >>*e;
    cout << "Département: ";
    in >> r.departement;
    return in;
}



istream& operator>>(istream& in, Pharmacien& P)
{
    Employe* e = &P;
    in >> *e;
    char rep;
    int choix;
    do {
        cout << "Entrer un choix (1: Environnement, 2: Microbiologique, 3: Pureté): ";
        cin >> choix;
        if (choix == 1) {
            TestEnvironnement* T = new TestEnvironnement("",0,0,0);
            in >> *T;
            P.tabTests.push_back(T);
        }
        else if (choix == 2) {
            TestMicroBiologique* T = new TestMicroBiologique("",0);
            in >> *T;
            P.tabTests.push_back(T);
        }
        else if (choix == 3) {
            TestPurete* T = new TestPurete("",0,0,0);
            in >> *T;
            P.tabTests.push_back(T);
        }
        else {
            cout << "Choix invalide !" << endl;
        }

        cout << "Ajouter un autre test ? (o/n): ";
        in >> rep;
    } while (rep == 'o' || rep == 'O');

    return in;
}





istream& operator>>(istream& in, TestEnvironnement& te) {
    Test* t=&te;
    in >>*t;
    cout << "Température: ";
    in >> te.temperature;
    cout << "Humidité: ";
    in >> te.humidite;
    cout << "Pression: ";
    in >> te.pression;
    return in;
}
istream& operator>>(istream& in, TestMicroBiologique& tm) {
    Test* t=&tm;
    in >>*t;
    cout << "Pourcentage de bactéries: ";
    in >> tm.pourcentageBacterie;
    return in;
}
istream& operator>>(istream& in, TestPurete& tp) {
    Test* t=&tp;
    in>>*t;
    cout << "pH: ";
    in >> tp.pH;
    cout << "Viscosité: ";
    in >> tp.viscosite;
    cout << "Densité: ";
    in >> tp.densite;
    return in;
}
istream& operator>>(istream& in, Etudiant& e) {
    cout << "Nom: ";
    in >> e.nom;
    cout << "Prénom: ";
    in >> e.prenom;
    cout << "CIN: ";
    in >> e.CIN;
    cout << "Mention: ";
    in >> e.mention;
    return in;
}
istream& operator>>(istream& in, Stagiaire& s) {
    Employe* e = &s;
    Etudiant* etu = &s;
    in >> *e;
    in >> *etu;
    cout << "Durée du stage (en jours): ";
    in >> s.dureeStage;
    return in;
}
void Pharmacien::creer(fstream &f){
    f.open("Pharmacien.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

istream& operator>>(istream& in, Pharmacien* P){
    int choix;
    in.seekg(0);
    Employe* e = P;
    in >> e;
    while(1) {
        in >> choix;
        if(in.eof() )break;
        if (choix == 1) {
            TestEnvironnement* T = new TestEnvironnement("",0,0,0);
            in >> *T;
            P->tabTests.push_back(T);}
        else if (choix == 2) {
            TestMicroBiologique* T = new TestMicroBiologique("",0);
            in >> *T;
            P->tabTests.push_back(T);}
        else if (choix == 3) {
            TestPurete* T = new TestPurete("",0,0,0);
            in >> *T;
            P->tabTests.push_back(T);}}
    return in;
}
void Pharmacien::lire_fichier(){
    fstream fi("Pharmacien.txt");
    if (!fi) cout<<"\n erreur fichier Pharmacien ";
    fi>>this;
    fi.close(); }
ostream & operator<<(ostream &out, Pharmacien * P)
{
cout<< "Nom: ";
out<<P->nom<<endl;
cout<<"Prénom: ";
out<< P->prenom<<endl;
cout<<"Salaire: ";
out<< P->salaire<<endl;
cout<<"Le nombre des competences:";
out<<P->nombreCompetences<<endl;
for (int i = 0; i < P->nombreCompetences; ++i) {
        cout << "  - Compétence " << i + 1 << ": ";
        out<< P->competences[i] << endl;}
for (int i=0; i<P->tabTests.size(); i++){
    if (typeid(*P->tabTests[i])==typeid(TestEnvironnement)){
    cout << "- Test TestEnvironnement " ;
    out <<"1" << endl;
    TestEnvironnement& t = static_cast<TestEnvironnement&>(*P->tabTests[i]);
    cout << "Code: " ;
    out<< t.getCodeTest() << endl;
    cout << "Temperature: " ;
    out<< t.getTemperature() << endl;
    cout << "Humidite: " ;
    out<< t.getHumidite() << endl;
    cout << "Pression: " ;
    out<< t.getPression() << endl;}
    else if (typeid(*P->tabTests[i])==typeid(TestMicroBiologique)){
    cout << "  - Test MicroBiologique " ;
    out<<"2"<<endl;
    TestMicroBiologique& t = static_cast<TestMicroBiologique&>(*P->tabTests[i]);
    cout << "Code: " ;
    out<< t.getCodeTest() << endl;
    cout << "Pourcentage de bactéries: " ;
    out<< t.getPourcentageBacterie() << endl;}

    else if (typeid(*P->tabTests[i])==typeid(TestPurete)){
    cout << "- Test Purete " ;
    out<<"3"<<endl;
    TestPurete& t = static_cast<TestPurete&>(*P->tabTests[i]);
    cout << "Code: " ;
    out<< t.getCodeTest() << endl;
    cout << "pH: " ;
    out<< t.getPH() << endl;
    cout << "Viscosité: " ;
    out<< t.getViscosite() << endl;
    cout << "Densité: " ;
    out<< t.getDensite() << endl;}
}

return out;}

void Pharmacien::enregistrer_fichier(){

    fstream f("Pharmacien.txt");
    if (!f) {cout<<"\n erreur fichier Pharmacien"; }
    f<<this;
    f.close();}

void Etudiant::ajouterNote(string matiere, float note) {
    notes[matiere] = note;
}

void Etudiant::afficherNotes() {
    for (const auto& pair : notes) {
        cout << "Matière : " << pair.first << " | Note : " << pair.second << endl;
    }
}
float Etudiant::calculerMoyenne() {
    if (notes.empty()) return 0.0;

    float somme = accumulate(notes.begin(), notes.end(), 0.0f,[](float total, const pair<string, float>& note) {
            return total + note.second;
        });

    return somme / notes.size();
}

bool Etudiant::rechercherNote(string matiere, float& noteTrouvee) {
    map<string, float>::iterator it = notes.find(matiere);
    if (it != notes.end()) {
        noteTrouvee = it->second;
        return true;
    } else {
        return false;
    }
}

void Employe::creer(fstream &f){
    f.open("Employe.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

void Employe::lire_fichier(){
    fstream fi("Employe.txt");
    if (!fi) cout<<"\n erreur fichier Employe ";
    fi>>this;
    fi.close(); }

void Employe::enregistrer_fichier(){

    fstream f("Employe.txt");
    if (!f) {cout<<"\n erreur fichier Employe"; }
    f<<this;
    f.close();}

ostream& operator<<(ostream& out, Employe* e )
{ cout<<endl<< "Nom: ";
out<<e->nom<<endl;
cout<<"Prénom: ";
out<< e->prenom<<endl;
cout<<"Salaire: ";
out<< e->salaire<<endl;
cout<<"Le nombre des competences:";
out<<e->nombreCompetences<<endl;
for (int i = 0; i < e->nombreCompetences; ++i) {
        cout << "  - Compétence " << i + 1 << ": ";
        out<< e->competences[i] << endl;}
return out;
}

istream& operator>>(istream& in, Employe* e) {
    in >> e->nom;
    in >> e->prenom;
    in >> e->salaire;
    in >> e->nombreCompetences;
    delete[] e->competences;
    e->competences = new string[e->nombreCompetences];
    for (int i = 0; i < e->nombreCompetences; ++i) {
        in >> e->competences[i];
    }
    return in;
}
