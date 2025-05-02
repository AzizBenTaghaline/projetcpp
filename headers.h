#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <fstream>
#include<map>
#include<algorithm>
#include<list>
#include <istream>
#include <iostream>
#include<vector>
#include"projetcpp.h"
#include <typeinfo>
using namespace std;
class Medicament {
protected:
    int idMedicament;
    string nomMedicament;
    int prix;
    int stock;
    string dateExpiration;
    vector<Pharmacien*> pharmaciens;
public:
    Medicament(int id=0, string nom="", int prix=0, int stock=0, string dateExp="01/01/2000"){
        idMedicament=id;
        nomMedicament=nom;
        prix=prix;
        stock=stock;
        dateExpiration=dateExp;
        if (prix < 0) {
            throw std::invalid_argument("Le prix ne peut pas etre negatif !");
        }
        };
    Medicament(Medicament const& med):
        idMedicament(med.idMedicament),nomMedicament(med.nomMedicament),prix(med.prix),stock(med.stock),dateExpiration(med.dateExpiration){
            Pharmacien* phar;
            for (unsigned int i=0;i<med.pharmaciens.size();i++){
                phar=new Pharmacien(*med.pharmaciens[i]);
                pharmaciens.push_back(phar);
        }
    }
    Medicament& operator=(const Medicament& med) {
        Pharmacien* phar;
    if (this != &med) {
        for(unsigned int i=0;i<pharmaciens.size();i++){
            delete pharmaciens[i];
        }
        pharmaciens.clear();
        for(unsigned int i=0;i<med.pharmaciens.size();i++){
            phar=new Pharmacien(*med.pharmaciens[i]);
            pharmaciens.push_back(phar);
        }
        idMedicament = med.idMedicament;
        nomMedicament = med.nomMedicament;
        prix = med.prix;
        stock = med.stock;
        dateExpiration = med.dateExpiration;
    }
    return *this;
}
    /*friend ostream& operator<<(ostream& os, const Medicament& m) {
    os<< "ID: " << m.idMedicament <<endl;
    os<< "Nom: " << m.nomMedicament << endl;
    os<< "Prix: " << m.prix <<endl;
    os<< "Stock: " << m.stock << endl;
    os<< "Date d'expiration: " << m.dateExpiration << endl;
    os << "Pharmaciens qui ont fabriqué ce medicament: " << endl;
    for (unsigned int i = 0; i < m.pharmaciens.size(); i++) {
        os<<"-Pharmacien(ne) "<< *m.pharmaciens[i] << endl;
    }
    return os;
}*/
friend ostream& operator<<(ostream& os, const Medicament& med) {
    os << med.idMedicament << " "
       << med.nomMedicament << " "
       << med.prix << " "
       << med.stock << " "
       << med.dateExpiration << " ";
    return os;
}

    /*friend istream& operator>>(istream& is, Medicament& m) {
    cout<< "Entrer l'ID: ";
    is>> m.idMedicament;
    cout<< "Entrer le nom: ";
    is>> m.nomMedicament;
    cout<< "Entrer le prix: ";
    is>> m.prix;
    cout<< "Entrer le stock: ";
    is>> m.stock;
    cout<< "Entrer la date d'expiration: ";
    is>> m.dateExpiration;
    int nbPharmaciens;
    cout<< "Combien de pharmaciens voulez-vous ajouter ? ";
    is >> nbPharmaciens;
    for (int i = 0; i < nbPharmaciens; i++) {
        Pharmacien* phar = new Pharmacien();
        is >> *phar;
        m.pharmaciens.push_back(phar);
    }
    return is;
}*/
// À mettre dans Medicament
friend istream& operator>>(istream& is, Medicament& med) {
    cout<<"Entrer l'ID du medicament: ";
    is >> med.idMedicament;
    cout<<"Entrer le nom du medicament: ";
    is >> med.nomMedicament;
    cout<<"Entrer le prix du medicament: ";
    is >> med.prix;
     if (med.prix < 0) {
            throw std::invalid_argument("Le prix ne peut pas etre negatif !");
        }
    cout<<"Entrer le stock du medicament: ";
    is>> med.stock;
    cout<<"Entrer la date d'expiration du medicament: ";
    is>> med.dateExpiration;
    return is;
}
friend istream& operator>>(istream& is, Medicament* med) {
    is >> med->idMedicament
       >> med->nomMedicament
       >> med->prix
       >> med->stock
       >> med->dateExpiration;
    if (med->idMedicament<=0 || med->prix <= 0 || med->nomMedicament.empty()) {
        cout << "" << endl;
        return is;}
    cout << "ID: " << med->idMedicament << endl;
    cout << "Nom: " << med->nomMedicament << endl;
    cout << "Prix: " << med->prix << endl;
    cout << "Stock: " << med->stock << endl;
    cout << "Date Expiration: " << med->dateExpiration << endl;
    return is;
}
friend ostream& operator<<(ostream& os, Medicament* m) {
    os << m->getIdMedicament() << " "
       << m->getNomMedicament() << " "
       << m->getPrixMedicament() << " "
       << m->getStockMedicament() << " "
       << m->getDateExpiration() << " ";
    return os;
}
void creer(fstream &f){
    f.open("Medicament.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

void enregistrer_fichier() {
    fstream f("Medicament.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}
void lire_fichier(vector<Medicament*>* medicaments = nullptr) {
    fstream fi("Medicament.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Medicament* med = new Medicament();
        fi >> med;
        if (medicaments) {
            medicaments->push_back(med);
        } else {
            delete med;
    }}
    fi.close();
};
static void enregistrerMedicamentsDansFichierDepuisTableau(vector<Medicament*>& medicaments) {
    fstream f("Medicament.txt", ios::out | ios::trunc);
    if (!f) {
        cout << "Erreur lors de l'ouverture du fichier pour réécriture!" << endl;
        return;
    }

    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        f << medicaments[i];
    }

    f.close();
    cout << "Fichier mis à jour avec succès!" << endl;
}
static void chargerMedicamentsDansTableauDepuisFichier(vector<Medicament*>& medicaments) {
    fstream fi("Medicament.txt", ios::in);
    if (!fi) {
        cout << "Erreur lors de l'ouverture du fichier!" << endl;
        return;
    }
    Medicament* med;
    while (fi >> med) {
        medicaments.push_back(med);
    }
    fi.close();
}
static void modifierMedicament(int idMedicamentRecherche, const string& newNom, int newPrix, int newQteStock, Pharmacien* pharToAdd = nullptr, const string& pharToRemove = "") {
    Medicament med1;
    vector<Medicament*> medicaments;
    med1.lire_fichier(&medicaments);

    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        if (medicaments[i]->idMedicament == idMedicamentRecherche) {
            medicaments[i]->nomMedicament = newNom;
            medicaments[i]->prix = newPrix;
            medicaments[i]->stock = newQteStock;

            cout << "Medicament modifié avec succès!" << endl;

            if (pharToAdd != nullptr) {
                medicaments[i]->ajouterPharmacienAMedicament(pharToAdd);
                cout << "Pharmacien ajouté au médicament." << endl;
            }
            if (!pharToRemove.empty()) {
                medicaments[i]->supprimerPharmaciendeMedicament(pharToRemove);
            }

            Medicament::enregistrerMedicamentsDansFichierDepuisTableau(medicaments);
            return;
        }
    }
    cout << "Medicament non trouvé." << endl;
}

static void supprimerMedicament(int idMedicamentASupprimer) {
    Medicament med;
    vector<Medicament*> medicaments;
    med.lire_fichier(&medicaments);

    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        if (medicaments[i]->idMedicament == idMedicamentASupprimer) {
            delete medicaments[i];
            medicaments.erase(medicaments.begin() + i);
            cout << "Medicament supprimé avec succès!" << endl;

            Medicament::enregistrerMedicamentsDansFichierDepuisTableau(medicaments);
            return;
        }
    }
    cout << "Medicament non trouvé." << endl;
}

    void ajouterPharmacienAMedicament(Pharmacien* phar){
        pharmaciens.push_back(phar);
    }
    void supprimerPharmaciendeMedicament(const string& nomPharmacien) {
    bool found = false;
    for (unsigned int i = 0; i < pharmaciens.size(); ++i) {
        if (pharmaciens[i]->getNom() == nomPharmacien) {
            pharmaciens.erase(pharmaciens.begin() + i);
            found = true;
            cout << "Pharmaciens " << nomPharmacien << " supprimé du medicament." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Pharmacien non trouvé dans le medicament." << endl;
    }
}
    void afficherPharmacien() {
        if (pharmaciens.empty()) {
            cout << "Aucun pharmacien associe a ce medicament" << endl;
        } else {
            for (unsigned int i = 0; i < pharmaciens.size(); ++i) {
                cout << "Pharmacien " << i + 1 << " : " << pharmaciens[i]->getNom() << ", "
                     << pharmaciens[i]->getPrenom() << endl;
            }
        }
    }

    void afficherMedInfo() {
        cout << "ID: " << idMedicament << ", Nom: " << nomMedicament<< ", Prix: " << prix << ", Stock: " << stock<< ", Expiration: "<<dateExpiration<<endl;
    }
    virtual void modifierMedInfo(string nom, int prix, int stock, string dateExp) {
        nomMedicament=nom;
        this->prix=prix;
        this->stock=stock;
        dateExpiration=dateExp;
    }
    virtual ~Medicament(){
    for (unsigned int i=0;i<pharmaciens.size();i++)
            delete pharmaciens[i];
    }
    int getIdMedicament(){
        return idMedicament;
    }
    void setIdMedicament(int id){
        idMedicament=id;
    }
    string getNomMedicament() const {
        return nomMedicament;
    }
    void setNomMedicament(const string nom){
        nomMedicament=nom;
    }
    int getPrixMedicament(){
        return prix;
    }
    void setPrixdMedicament(int prix){
        this->prix=prix;
    }
    int getStockMedicament(){
        return stock;
    }
    void setStockdMedicament(int stock){
        this->stock=stock;
    }
    string getDateExpiration(){
        return dateExpiration;
    }
    void setDateExpiration(string dateExpiration){
        this->dateExpiration=dateExpiration;
    }
     virtual bool estEnStock(){
        return stock > 0;
    }
    virtual void miseAJourStock(int quantite){
        if (stock - quantite >= 0) {
            stock -= quantite;
        } else {
            cout << "Stock insuffisant !" << endl;
        }
    }
    bool estPerime(string dateActuelle){
        return dateExpiration < dateActuelle;
    }
};

class Antibiotique : virtual public Medicament {
    string spectreAction;
public:
    Antibiotique(int id, string nom, float p, int s, string date, string spectre)
        : Medicament(id, nom, p, s, date) {
            spectreAction=spectre;
        }
    friend ostream& operator<<(ostream& os, const Antibiotique& antiB) {
    os << static_cast<const Medicament&>(antiB);
    os << "Spectre: " << antiB.spectreAction << endl;
    return os;
}
    friend istream& operator>>(istream& is, Antibiotique& antiB) {
    is >> static_cast<Medicament&>(antiB);
    cout << "Entrez Spectre: ";
    is >> antiB.spectreAction;
    return is;
}
    void afficherMedInfo(){
        Medicament::afficherMedInfo();
        cout << spectreAction << endl;
    };
    void modifierMedInfo(string nom, float prix, int stock, string dateExp,string spectre){
        Medicament::modifierMedInfo(nom, prix, stock, dateExp);
        spectreAction=spectre;
    }
    ~Antibiotique(){};
    string getSpectre(){return spectreAction;};
    void setSpectre(string spectre){spectreAction=spectre;};
};

class AntiInflammatoire : virtual public Medicament {
    bool estSteroidien;
public:
    AntiInflammatoire(int id, string nom, float p, int s, string date, bool steroidien)
        : Medicament(id, nom, p, s, date){
            estSteroidien=steroidien;
        };
    /*friend ostream& operator<<(ostream& os, const AntiInflammatoire& antiI) {
        os << static_cast<const Medicament&>(antiI);
        os << "Spectre: " << antiI.spectre << endl;
        return os;
}
    friend istream& operator>>(istream& is, AntiInflammatoire& antiI) {
        is >> static_cast<Medicament&>(antiI);
        cout << "Entrez Spectre: ";
        is >> antiI.spectre;
        return is;
}*/
    void afficherMedInfo(){
        Medicament::afficherMedInfo();
        cout << estSteroidien << endl;
    };
    void modifierMedInfo(string nom, float prix, int stock, string dateExp,bool steroidien){
        Medicament::modifierMedInfo(nom, prix, stock, dateExp);
        estSteroidien=steroidien;
    }
    ~AntiInflammatoire(){};
};

class MedicamentCombine : public Antibiotique, public AntiInflammatoire {
private:
    map<string, string> principesActifs;
public:
    MedicamentCombine(int id, const string& nom, float p, int s, const string& date, const string& spectre, bool steroidien)
        : Medicament(id, nom, p, s, date),
          Antibiotique(id, nom, p, s, date, spectre),
          AntiInflammatoire(id, nom, p, s, date, steroidien)
    {}
MedicamentCombine()
    : Medicament(0, "Inconnu", 0.0, 0, "01/01/2000"),
      Antibiotique(0, "Inconnu", 0.0, 0, "01/01/2000", "Spectre inconnu"),
      AntiInflammatoire(0, "Inconnu", 0.0, 0, "01/01/2000", false)
{}

    virtual ~MedicamentCombine() {}

    void ajouterPrincipeActif() {
    string nom, description;
    int nbMeds;
    cout << "Entrer le nombre de principes actifs a ajouter :" << endl;
    cin >> nbMeds;
    cin.ignore();

    for (unsigned int i = 0; i < nbMeds; i++) {
        cout << "Entrer le nom du medicament :" << endl;
        getline(cin, nom);

        cout << "Entrer la description du medicament :" << endl;
        getline(cin, description);

        principesActifs[nom] = description;
    }
}
    void supprimerPrincipeActif(const string& nom) {
        principesActifs.erase(nom);
    }

    void afficherPrincipesActifs() const {
        if (principesActifs.empty()) {
            cout << "Aucun principe actif." << endl;
            return;
        }
        for (const auto& p : principesActifs) {
            cout << "Principe Actif: " << p.first << " => Description: " << p.second << endl;
        }
    }
    const map<string, string>& getPrincipesActifs() const {
        return principesActifs;
    }
    void afficherParTailleNom() const {
    vector<pair<string, string>> temp(principesActifs.begin(), principesActifs.end());

    sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.first.size() < b.first.size();
    });

    for (const auto& p : temp) {
        cout << p.first << " - " << p.second << endl;
    }
}
void rechercherPrincipeActifParMotCle(const string& motCle) const {
    bool trouve = false;
    for (const auto& p : principesActifs) {
        if (p.first.find(motCle) != string::npos) {
            cout << "Trouve: " << p.first << " - " << p.second << endl;
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucun principe actif correspondant au mot-cle: " << motCle << endl;
    }
}

};



class Vitamine : public Medicament {
    vector<string*> typesSupplementaires;
public:
    Vitamine(int id, string nom, float p, int s, string date)
    : Medicament(id, nom, p, s, date) {}
    Vitamine() : Medicament() {}

friend ostream& operator<<(ostream& os, const Vitamine& vit) {
    os << static_cast<const Medicament&>(vit) << " ";
    return os;
}

friend istream& operator>>(istream& is, Vitamine& vit) {
    is >> static_cast<Medicament&>(vit);
    return is;
}

friend istream& operator>>(istream& is, Vitamine* vit) {
    is >> static_cast<Medicament&>(*vit);
    if (vit->getIdMedicament()<=0 || vit->getPrixMedicament() <= 0 || vit->getNomMedicament().empty()) {
        cout << "" << endl;
        return is;}

    cout << "\nLecture Vitamine :" << endl;
    cout << "ID: " << vit->getIdMedicament() << endl;
    cout << "Nom: " << vit->getNomMedicament() << endl;
    cout << "Prix: " << vit->getPrixMedicament() << endl;
    cout << "Stock: " << vit->getStockMedicament() << endl;
    cout << "Date Expiration: " << vit->getDateExpiration() << endl;

    return is;
}
friend ostream& operator<<(ostream& os, const Vitamine* v) {
    os << static_cast<const Medicament&>(*v) << " ";
    os << v->typesSupplementaires.size() << " ";
    return os;
}
void creer(fstream &f){
    f.open("Vitamine.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

void enregistrer_fichier() {
    fstream f("Vitamine.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}
void lire_fichier(vector<Vitamine*>* vitamines = nullptr) {
    fstream fi("Vitamine.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Vitamine* vit = new Vitamine();
        fi >> vit;
        if (vitamines) {
            vitamines->push_back(vit);
        } else {
            delete vit;
    }}
    fi.close();
};
static void enregistrerVitaminesDansFichierDepuisTableau(vector<Vitamine*>& vitamines) {
    fstream f("Vitamine.txt", ios::out | ios::trunc);
    if (!f) {
        cout << "Erreur lors de l'ouverture du fichier pour réécriture!" << endl;
        return;
    }

    for (unsigned int i = 0; i < vitamines.size(); ++i) {
        f << vitamines[i];
    }

    f.close();
    cout << "Fichier mis à jour avec succès!" << endl;
}
static void chargerVitaminesDansTableauDepuisFichier(vector<Vitamine*>& vitamines) {
    fstream fi("Vitamine.txt", ios::in);
    if (!fi) {
        cout << "Erreur lors de l'ouverture du fichier!" << endl;
        return;
    }
    Vitamine* vit;
    while (fi >> vit) {
        vitamines.push_back(vit);
    }
    fi.close();
}
static void modifierVitamine(int idMedicamentRecherche, const string& newNom, int newPrix, int newQteStock, Pharmacien* pharToAdd = nullptr, const string& pharToRemove = "") {
    Vitamine vit;
    vector<Vitamine*> vitamines;
    vit.lire_fichier(&vitamines);

    for (unsigned int i = 0; i < vitamines.size(); ++i) {
            if (vitamines[i]->getIdMedicament() == idMedicamentRecherche){
            vitamines[i]->setNomMedicament(newNom);
            vitamines[i]->setPrixdMedicament(newPrix);
            vitamines[i]->setStockdMedicament(newQteStock);

            cout << "Vitamine modifie avec succes!" << endl;

            Vitamine::enregistrerVitaminesDansFichierDepuisTableau(vitamines);
            return;
        }
    }
    cout << "Vitamine non trouve." << endl;
}

static void supprimerVitamine(int idMedicamentASupprimer) {
    Vitamine vit;
    vector<Vitamine*> vitamines;
    vit.lire_fichier(&vitamines);

    for (unsigned int i = 0; i < vitamines.size(); ++i) {
        if (vitamines[i]->getIdMedicament() == idMedicamentASupprimer){
            delete vitamines[i];
            vitamines.erase(vitamines.begin() + i);
            cout << "Vitamine supprime avec succes!" << endl;

            Vitamine::enregistrerVitaminesDansFichierDepuisTableau(vitamines);
            return;
        }
    }
    cout << "Vitamine non trouve." << endl;
};
Vitamine operator+(const Vitamine& other) const {
    Vitamine resultat = *this;

    resultat.setNomMedicament(this->getNomMedicament() + "_" + other.getNomMedicament());

    for (auto typePtr : other.typesSupplementaires) {
        if (typePtr) {
            resultat.typesSupplementaires.push_back(new string(*typePtr));
        }
    }

    return resultat;
}

    void afficherMedInfo() {
        Medicament::afficherMedInfo();
        for (unsigned int i=0; i<typesSupplementaires.size();i++) {
            cout << *typesSupplementaires[i];
        }
}
    void modifierMedInfo(string nom, float prix, int stock, string dateExp) {
        Medicament::modifierMedInfo(nom, prix, stock, dateExp);
}
    void ajoutertypeSupplementaire(string* typeSupp) {
        typesSupplementaires.push_back(typeSupp);
}
    void supprimertypeSupp(string* typeSupp) {
    for (int i = 0; i < typesSupplementaires.size(); i++) {
        if (*typesSupplementaires[i] == *typeSupp) {
            delete typesSupplementaires[i];
            typesSupplementaires.erase(typesSupplementaires.begin() + i);
            break;
        }
    }
}
    ~Vitamine() {
    for (int i = 0; i < typesSupplementaires.size(); ++i) {
        delete typesSupplementaires[i];
    }
}
};
class Commande{
    string codeCommande;
    int qteCommande;
    string dateCommande;
    vector<Medicament*> medicaments;

public:
    Commande(string code, int qteCmd, string dateCmd){
        codeCommande=code;
        qteCommande=qteCmd;
        dateCommande=dateCmd;
    };
    Commande() : codeCommande(""), qteCommande(0), dateCommande("") {}
    Commande(const Commande& c): codeCommande(c.codeCommande),qteCommande(c.qteCommande),dateCommande(c.dateCommande){
        for (unsigned int i=0;i<c.medicaments.size();i++){
                Medicament* med;
            if (typeid(*c.medicaments[i])==typeid(Medicament))
                med=new Medicament(*c.medicaments[i]);
            else if (typeid(*c.medicaments[i])==typeid(Antibiotique))
                med=new Antibiotique(dynamic_cast<const Antibiotique&>(*c.medicaments[i]));
            else if (typeid(*c.medicaments[i])==typeid(AntiInflammatoire))
                med=new AntiInflammatoire(dynamic_cast<const AntiInflammatoire&>(*c.medicaments[i]));
            else if (typeid(*c.medicaments[i])==typeid(Vitamine))
                med=new Vitamine(dynamic_cast<const Vitamine&>(*c.medicaments[i]));
            medicaments.push_back(med);
}
    }
string getCodeCommande() const { return codeCommande; }
    string getDateCommande() const { return dateCommande; }
    int getQteCommande() const { return qteCommande; }

friend ostream& operator<<(ostream& os, const Commande& cmd) {
    os << "Code commande: " << cmd.codeCommande << endl;
    os << "Quantité commande: " << cmd.qteCommande << endl;
    os << "Date commande: " << cmd.dateCommande << endl;
    os << "Nombre total de médicaments: " << cmd.medicaments.size() << endl;

    for (unsigned int i = 0; i < cmd.medicaments.size(); ++i) {
        os << "\tMédicament " << i + 1 << ":\n";
        os << *cmd.medicaments[i];
    }
    return os;
}
friend ostream& operator<<(ostream& os, const Commande* cmd) {
    os << cmd->codeCommande << " ";
    os << cmd->qteCommande << " ";
    os << cmd->dateCommande << " ";
    os << cmd->medicaments.size() << "\n";

    for (unsigned int i = 0; i < cmd->medicaments.size(); ++i) {
        os << *cmd->medicaments[i]<<"\n";
    }
    return os;
}
friend istream& operator>>(istream& is, Commande& cmd) {
    cout << "Entrer le code commande: ";
    is >> cmd.codeCommande;
    cout << "Entrer la quantité: ";
    is >> cmd.qteCommande;
    cout << "Entrer la date: ";
    is >> cmd.dateCommande;
    int nbMeds;
    cout << "Combien de medicaments dans cette commande ? ";
    is >> nbMeds;
    cmd.medicaments.clear();
    for (int i = 0; i < nbMeds; ++i) {
        cout << "*Saisie du medicament num*" << i + 1 << " :" << endl;
        Medicament* m = new Medicament();
        is >> *m;
        cmd.medicaments.push_back(m);
    }
    return is;
}
friend istream& operator>>(istream& is, Commande* cmd) {
    int nbMeds;
    is >> cmd->codeCommande >> cmd->qteCommande >> cmd->dateCommande >> nbMeds;
    cmd->medicaments.clear();
    if (cmd->codeCommande.empty() || cmd->qteCommande <= 0 || cmd->dateCommande.empty()) {
        cout << "" << endl;
        return is;
    }
    cout << "Code Commande: " << cmd->codeCommande << "\n";
    cout << "Quantite: " << cmd->qteCommande << endl;
    cout << "Date de commande: " << cmd->dateCommande << endl;
    cout<<"***************************************\n";

    for (unsigned int i = 0; i < nbMeds; i++) {
        Medicament* m = new Medicament();
        is >> m;
        cmd->medicaments.push_back(m);
        cout<<"----------------------------\n";
    }
        cout<<"***************************************\n";
    return is;
}
    Commande operator+(const Commande& other) const {
    Commande resultat = *this;
    for (unsigned int i=0;i<other.medicaments.size();i++) {
        resultat.ajouterMedicamentACommande(other.medicaments[i]);
    }
    return resultat;
}

    Medicament*& operator[](int index) {
    if (index < 0 || index >= medicaments.size()) {
        throw out_of_range("Indice invalide!");
    }
    return medicaments[index];
}
void creer(fstream &f){
    f.open("Commande.txt", ios ::in | ios ::out |ios ::trunc) ;
    if( ! f.is_open()) {exit(-1);}}

void enregistrer_fichier() {
    fstream f("Commande.txt", ios::out | ios::app);
    if (!f.is_open()) {
        cout << "\nErreur fichier Commande ";
        return;
    }
    f << this;
    f.close();
}
void lire_fichier(vector<Commande*>* commandes = nullptr) {
    fstream fi("Commande.txt", ios::in);
    if (!fi.is_open()) {
        cout << "\nErreur fichier Commande";
        return;
    }
    while (!fi.eof()) {
        Commande* cmd = new Commande();
        fi >> cmd;
        if (commandes) {
            commandes->push_back(cmd);
        } else {
            delete cmd;
    }}
    fi.close();
};

static void enregistrerCommandesDansFichierDepuisTableau(vector<Commande*>& commandes) {
    fstream f("Commande.txt", ios::out | ios::trunc);
    if (!f) {
        cout << "Erreur lors de l'ouverture du fichier pour réécriture!" << endl;
        return;
    }

    for (unsigned int i = 0; i < commandes.size(); ++i) {
        f << commandes[i];
    }

    f.close();
    cout << "Fichier mis à jour avec succès!" << endl;
}
static void chargerCommandesDansTableauDepuisFichier(vector<Commande*>& commandes) {
    fstream fi("Commande.txt", ios::in);
    if (!fi) {
        cout << "Erreur lors de l'ouverture du fichier!" << endl;
        return;
    }

    Commande* cmd;
    while (fi >> cmd) {
        commandes.push_back(cmd);
    }
    fi.close();
}
    static void modifierCommande(const string& codeCommandeRecherche, const string& newCode, const string& newDate, int newQteCommande, Medicament* medToAdd = nullptr, const string& medToRemove = "") {
    Commande cmd1;
    vector<Commande*> commandes;
    cmd1.lire_fichier(&commandes);
    for (unsigned int i = 0; i < commandes.size(); ++i) {
        if (commandes[i]->codeCommande == codeCommandeRecherche) {
            commandes[i]->codeCommande = newCode;
            commandes[i]->dateCommande = newDate;
            commandes[i]->qteCommande = newQteCommande;
            cout << "Commande modifiée avec succès!" << endl;

            if (medToAdd != nullptr) {
                commandes[i]->ajouterMedicamentACommande(medToAdd);
                cout << "Médicament ajouté à la commande." << endl;
            }

            if (!medToRemove.empty()) {
                commandes[i]->supprimerMedicamentDeCommande(medToRemove);
            }
            Commande::enregistrerCommandesDansFichierDepuisTableau(commandes);
            return;
        }
    }
    cout << "Commande non trouvée." << endl;
}
static void supprimerCommande(const string& codeCommandeASupprimer) {
    Commande cmd1;
    vector<Commande*> commandes;
    cmd1.lire_fichier(&commandes);

    for (unsigned int i = 0; i < commandes.size(); ++i) {
        if (commandes[i]->codeCommande == codeCommandeASupprimer) {
            delete commandes[i];
            commandes.erase(commandes.begin() + i);
            cout << "Commande supprimée avec succès!" << endl;

            Commande::enregistrerCommandesDansFichierDepuisTableau(commandes);
            return;
        }
    }
    cout << "Commande non trouvée." << endl;
}

    ~Commande(){
        for (unsigned int i=0;i<medicaments.size();i++)
            delete medicaments[i];
    };
    void afficherCommande(){
      cout<<codeCommande<<endl;
      cout<<qteCommande<<endl;
      cout<<dateCommande<<endl;
      for (unsigned int i=0;i<medicaments.size();i++)
        cout<<medicaments[i]->getIdMedicament()<<"\t"<<medicaments[i]->getNomMedicament()<<"\t"<<medicaments[i]->getPrixMedicament()<<"\t"<<medicaments[i]->getDateExpiration()<<"\t"<<endl;
    };
    void ajouterMedicamentACommande(Medicament* med){
        medicaments.push_back(med);
    }
    void supprimerMedicamentDeCommande(const string& nomMedicament) {
    bool found = false;
    for (unsigned int i = 0; i < medicaments.size(); ++i) {
        if (medicaments[i]->getNomMedicament() == nomMedicament) {
            medicaments.erase(medicaments.begin() + i);
            found = true;
            cout << "Médicament " << nomMedicament << " supprimé de la commande." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Médicament non trouvé dans la commande." << endl;
    }
}
    string getCodeCommande()  { return codeCommande; }
    string getDateCommande()  { return dateCommande; }
    int getQteCommande()  { return qteCommande; }

    float calculerMontantTotal(){
        float s=0;
        for (unsigned int i=0;i<medicaments.size();i++)
            s+=medicaments[i]->getPrixMedicament();
        return s;
    };
    bool verifierMedicamentDansCommande(const string& nom){
        for (unsigned int i = 0; i < medicaments.size(); i++){
            if (medicaments[i]->getNomMedicament() == nom){
                return true;
            }
        }
        return false;
    }
    int nombreDeMedicamentsDansCommande() const {
        return medicaments.size();
    }
};
class Client {
private:
    string nomClient;
    string prenomClient;
    string CINClient;
    string numTel;
    string emailClient;
    list<Commande> commandes;

public:
    Client(string nom, string prenom, string CIN, string tel, string email)
        : nomClient(nom), prenomClient(prenom), CINClient(CIN), numTel(tel), emailClient(email) {}

    void ajouterCommande(const Commande& cmd) {
        commandes.push_back(cmd);
    }
    void afficherClient() const {
        cout << "Client : " << prenomClient << " " << nomClient << endl;
        cout << "CIN : " << CINClient << ", Téléphone : " << numTel << ", Email : " << emailClient << endl;
        cout << "--- Commandes ---" << endl;
        for (const Commande& cmd : commandes) {
            cout<<cmd;
        }
        cout << endl;
    }
    Commande* trouverCommandeParCode(const string& code) {
        auto it = find_if(commandes.begin(), commandes.end(),
            [&code](const Commande& cmd) {
                return cmd.getCodeCommande() == code;
            });
        if (it != commandes.end()) {
            return &(*it);
        } else {
            cout << "Commande avec le code " << code << " non trouvée." << std::endl;
            return nullptr;
        }
    }

    bool supprimerCommandeParCode(const string& code) {
        auto it = find_if(commandes.begin(), commandes.end(),
            [&code](const Commande& cmd) {
                return cmd.getCodeCommande() == code;
            });
        if (it != commandes.end()) {
            commandes.erase(it);
            cout << "Commande " << code << " supprimée avec succès." << endl;
            return true;
        } else {
            cout << "Commande avec le code " << code << " non trouvée." << endl;
            return false;
        }
    }

};

#endif // HEADERS_H_INCLUDED
