#include <iostream>
#include <vector>
#include <fstream>
#include "projetcpp.h"
#include"headers.h"
using namespace std;


#include"headers.h"
#include <vector>
using namespace std;


void menuMedicament() {
    int choix;
    Medicament medicament;

    do {
        cout << "\n===== MENU MEDICAMENT =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de medicaments" << endl;
        cout << "2. Saisir et ajouter un nouveau medicament" << endl;
        cout << "3. Lire touts les medicament enregistrees" << endl;
        cout << "4. Modifier un medicament" << endl;
        cout << "5. Supprimer un medicament" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                fstream fichier;
                medicament.creer(fichier);
                cout << "Fichier 'Medicament.txt' cree/reinitialise avec succes.\n";
                fichier.close();
                break;
            }
            case 2: {
                cout << "Saisie de la commande:\n";
                cin >> medicament;
                medicament.enregistrer_fichier();
                cout << "Commande ajoutee dans 'Medicament.txt'.\n";
                break;
            }
            case 3: {
                cout << "Lecture des Medicaments:\n";
                medicament.lire_fichier();
                break;
            }
            case 4: {
                 int idMedicamentRecherche, newPrix, newQteStock;
                string newNom, pharToRemove;
                cout << "Entrer l'ID du medicament à modifier: ";
                cin >> idMedicamentRecherche;
                cout << "Entrer le nouveau nom du medicament: ";
                cin >> newNom;
                cout << "Entrer le nouveau prix du medicament: ";
                cin >> newPrix;
                cout << "Entrer la nouvelle quantité en stock: ";
                cin >> newQteStock;
                char ajouterPharmacien;
                cout << "Souhaitez-vous ajouter un pharmacien à ce medicament ? (o/n) ";
                cin >> ajouterPharmacien;
                Pharmacien* pharToAdd = nullptr;
                if (ajouterPharmacien == 'o' || ajouterPharmacien == 'O') {
                    pharToAdd = new Pharmacien();
                    cin >> *pharToAdd;
                }
                char supprimerPharmacien;
                cout << "Souhaitez-vous supprimer un pharmacien de ce medicament ? (o/n) ";
                cin >> supprimerPharmacien;
                if (supprimerPharmacien == 'o' || supprimerPharmacien == 'O') {
                    cout << "Entrer le nom du pharmacien à supprimer: ";
                    cin >> pharToRemove;
                }

            Medicament::modifierMedicament(idMedicamentRecherche, newNom, newPrix, newQteStock, pharToAdd, pharToRemove);
            break;
        }
                    case 5:{
                        int idMedicamentRecherche;
                        cout << "Entrer l'ID du medicament a supprimer: ";
                        cin >> idMedicamentRecherche;
                        Medicament::supprimerMedicament(idMedicamentRecherche);
                        break;
            }
            case 0:
                cout << "Retour au menu principal...\n";
                break;
            default:
                cout << "Choix invalide. Veuillez ressayer.\n";
        }
    } while (choix != 0);
}
void menuVitamine() {
    int choix;
    Vitamine vit;

    do {
        cout << "\n===== MENU VITAMINE =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de vitamines" << endl;
        cout << "2. Saisir et ajouter un nouveau vitamine" << endl;
        cout << "3. Lire touts les vitamines enregistrees" << endl;
        cout << "4. Modifier un vitamine" << endl;
        cout << "5. supprimer un vitamine" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                fstream fichier;
                vit.creer(fichier);
                cout << "Fichier 'Vitamine.txt' cree/reinitialise avec succes.\n";
                fichier.close();
                break;
            }
            case 2: {
                cout << "Saisie de la commande:\n";
                cin >> vit;
                vit.enregistrer_fichier();
                cout << "Commande ajoutee dans 'Vitamine.txt'.\n";
                break;
            }
            case 3: {
                cout << "Lecture des vitamines:\n";
                vit.lire_fichier();
                break;
            }
            case 4: {
                 int idMedicamentRecherche, newPrix, newQteStock;
                string newNom, pharToRemove;
                cout << "Entrer l'ID du vitamine à modifier: ";
                cin >> idMedicamentRecherche;
                cout << "Entrer le nouveau nom du vitamine: ";
                cin >> newNom;
                cout << "Entrer le nouveau prix du vitamine: ";
                cin >> newPrix;
                cout << "Entrer la nouvelle quantité en stock: ";
                cin >> newQteStock;
            Vitamine::modifierVitamine(idMedicamentRecherche, newNom, newPrix, newQteStock);
            break;
        }
        case 5: {
                int codeVitamineRecherche;
                cout << "Entrer le code du vitamine a supprimer: ";
                cin >> codeVitamineRecherche;
                Vitamine::supprimerVitamine(codeVitamineRecherche);
                break;
        }
            case 0:
                cout << "Retour au menu principal...\n";
                break;
            default:
                cout << "Choix invalide. Veuillez ressayer.\n";
        }
    } while (choix != 0);
}

void menuCommande() {
    int choix;
    Commande commande;
    do {
        cout << "\n===== MENU COMMANDE =====" << endl;
        cout << "1. Creer/Reinitialiser le fichier de commandes" << endl;
        cout << "2. Saisir et ajouter une nouvelle commande" << endl;
        cout << "3. Lire toutes les commandes enregistrees" << endl;
        cout << "4. Modifier une commande" << endl;
        cout << "5. Supprimer une commande" << endl;
        cout << "0. Retour au menu principal" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                fstream fichier;
                commande.creer(fichier);
                cout << "Fichier 'Commande.txt' cree/reinitialise avec succes.\n";
                fichier.close();
                break;
            }
            case 2: {
                cout << "Saisie de la commande:\n";
                cin >> commande;
                commande.enregistrer_fichier();
                cout << "Commande ajoutee dans 'Commande.txt'.\n";
                break;
            }
            case 3: {
                cout << "Lecture des commandes:\n";
                commande.lire_fichier();
                break;
            }
            case 4: {
                string codeCommandeRecherche, newCode, newDate, medToRemove;
                int newQteCommande;
                cout << "Entrer le code de la commande à modifier: ";
                cin >> codeCommandeRecherche;
                cout << "Entrer le nouveau code commande: ";
                cin >> newCode;
                cout << "Entrer la nouvelle date commande: ";
                cin >> newDate;
                cout << "Entrer la nouvelle quantité: ";
                cin >> newQteCommande;
                char ajouterMed;
                cout << "Souhaitez-vous ajouter un médicament à cette commande ? (o/n) ";
                cin >> ajouterMed;
                Medicament* medToAdd = nullptr;
                if (ajouterMed == 'o' || ajouterMed == 'O') {
                }

                char supprimerMed;
                cout << "Souhaitez-vous supprimer un médicament de cette commande ? (o/n) ";
                cin >> supprimerMed;
                if (supprimerMed == 'o' || supprimerMed == 'O') {
                    cout << "Entrer le nom du médicament à supprimer: ";
                    cin >> medToRemove;
                }

                Commande::modifierCommande(codeCommandeRecherche, newCode, newDate, newQteCommande, medToAdd, medToRemove);
                break;
            }
            case 5:{
                string codeCommandeRecherche;
                cout << "Entrer le code de la commande a supprimer: ";
                cin >> codeCommandeRecherche;
                Commande::supprimerCommande(codeCommandeRecherche);
                break;
            }
            case 0:
                cout << "Retour au menu principal...\n";
                break;
            default:
                cout << "Choix invalide. Veuillez ressayer.\n";
        }
    } while (choix != 0);
}
void menuHazem() {
    int choix;

do {
    cout << "=== Menu Principal ===" << endl;
    cout << "1 - Surcharge" << endl;
    cout << "2 - Fichiers" << endl;
    cout << "3 - Exception" << endl;
    cout << "4 - STL" << endl;
    cout << "0 - Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case 1: {
            int sousChoix;
            do {
                cout << "--- Surcharge d'operateurs ---" << endl;
                cout << "1 - operator <<" << endl;
                cout << "2 - operator >>" << endl;
                cout << "3 - operator +" << endl;
                cout << "0 - Retour" << endl;
                cout << "Votre choix : ";
                cin >> sousChoix;

                switch (sousChoix) {
                    case 1: {
                        cout << "Vous avez choisi operator <<." << endl;
                        Medicament m(1, "Sanofi", 0, 0, "10/10/2025");
                        cout << m << endl;
                        break;
                    }
                    case 2: {
                        cout << "Vous avez choisi operator >>." << endl;
                        Medicament m;
                        cout << "Entrez les informations du medicament :" << endl;
                        cin >> m;
                        cout << "Vous avez saisi :" << endl;
                        cout << m << endl;
                        break;
                    }
                    case 3: {
                        cout << "Vous avez choisi operator +." << endl;
                        Vitamine m1;
                        cin >> m1;
                         int nbTypes;
    cout << "Combien de types supplementaires voulez-vous ajouter ? ";
    cin >> nbTypes;
    cin.ignore();
    for (int i = 0; i < nbTypes; ++i) {
        string type;
        cout << "Entrez le type supplementaire #" << (i+1) << ": ";
        getline(cin, type);
        m1.ajoutertypeSupplementaire(&type);
    }
                        Vitamine m2;
                        cin >> m2;
    cout << "Combien de types supplementaires voulez-vous ajouter ? ";
    cin >> nbTypes;
    cin.ignore();

    for (int i = 0; i < nbTypes; ++i) {
        string type;
        cout << "Entrez le type supplementaire #" << (i+1) << ": ";
        getline(cin, type);
        m2.ajoutertypeSupplementaire(&type);
    }
                        Vitamine m3 = m1 + m2;
                        cout << "Nouveau Vitamine :" << endl;
                        m3.afficherMedInfo();
                        break;
                    }
                    case 0:
                        cout << "Retour au menu principal..." << endl;
                        break;
                    default:
                        cout << "Sous-choix invalide, veuillez réessayer." << endl;
                        break;
                }
                cout << endl;
            } while (sousChoix != 0);
            break;
        }

        case 2: {
            int sousChoixFichiers;
            do {
                cout << "--- Gestion des Fichiers ---" << endl;
                cout << "1 - Commandes" << endl;
                cout << "2 - Medicaments" << endl;
                cout << "3 - Vitamines" << endl;
                cout << "0 - Retour" << endl;
                cout << "Votre choix : ";
                cin >> sousChoixFichiers;

                switch (sousChoixFichiers) {
                    case 1: {
                        menuCommande();
                        break;
                    }
                    case 2: {
                        menuMedicament();
                        break;
                    }
                    case 3: {
                        menuVitamine();
                        break;
                    }
                    case 0:
                        cout << "Retour au menu principal..." << endl;
                        break;
                    default:
                        cout << "Sous-choix invalide, veuillez réessayer." << endl;
                        break;
                }
                cout << endl;
            } while (sousChoixFichiers != 0);
            break;
        }

        case 3: {
            cout << "Vous avez choisi Exception." << endl;
            try {
                cout << "Creation d'un medicament valide :" << endl;
                Medicament m1;
                cin >> m1;
                cout << m1 << endl;

                cout << "\nCreation d'un medicament avec prix negatif :" << endl;
                Medicament m2;
                cin >> m2;
                cout << m2 << endl;
            } catch (const invalid_argument& e) {
                cout << "Exception attrapee : " << e.what() << endl;
            }
            break;
        }

        case 4: {
            int choixSTL;
            do {
                cout << "--- Menu STL ---" << endl;
                cout << "1 - Affichage du List" << endl;
                cout << "2 - Map || Algorithme" << endl;
                cout << "0 - Retour" << endl;
                cout << "Votre choix : ";
                cin >> choixSTL;

                switch (choixSTL) {
                    case 1: {
                        cout << "Affichage List..." << endl;
                        Client c1("Barkallah", "Hazem", "C123456", "0601020304", "Hazem@gmailcom");
                        c1.ajouterCommande(Commande("CMD001", 10, "10/10/2025"));
                        c1.ajouterCommande(Commande("CMD002", 20, "10/10/2025"));
                        c1.afficherClient();
                        break;
                    }
                    case 2: {
                        MedicamentCombine med;
                        int choixAlgo;
                        do {
                            cout << "\n--- Menu Algorithme ---" << endl;
                            cout << "1. Ajouter un principe actif" << endl;
                            cout << "2. Afficher tous les principes actifs" << endl;
                            cout << "3. Supprimer un principe actif" << endl;
                            cout << "4. Trier les principes actifs" << endl;
                            cout << "5. Rechercher un principe actif" << endl;
                            cout << "0. Retour" << endl;
                            cout << "Votre choix : ";
                            cin >> choixAlgo;
                            cin.ignore();

                            switch (choixAlgo) {
                                case 1: {
                                    med.ajouterPrincipeActif();
                                    break;
                                }
                                case 2: {
                                    med.afficherPrincipesActifs();
                                    break;
                                }
                                case 3: {
                                    string nom;
                                    cout << "Entrer le nom du principe actif a supprimer : ";
                                    getline(cin, nom);
                                    med.supprimerPrincipeActif(nom);
                                    break;
                                }
                                case 4: {
                                    med.afficherParTailleNom();
                                    break;
                                }
                                case 5: {
                                    string nom;
                                    cout << "Entrer le nom du principe actif a rechercher : ";
                                    getline(cin, nom);
                                    med.rechercherPrincipeActifParMotCle(nom);
                                    break;
                                }
                                case 0:
                                    cout << "Retour au menu STL..." << endl;
                                    break;
                                default:
                                    cout << "Choix invalide, veuillez reessayer !" << endl;
                                    break;
                            }
                        } while (choixAlgo != 0);
                        break;
                    }
                    case 0:
                        cout << "Retour au menu principal..." << endl;
                        break;
                    default:
                        cout << "Choix invalide, veuillez reessayer." << endl;
                        break;
                }
                cout << endl;
            } while (choixSTL != 0);
            break;
        }

        case 0:
            cout << "Au revoir !" << endl;
            break;

        default:
            cout << "Choix invalide, veuillez reessayer." << endl;
            break;
    }

    cout << endl;

} while (choix != 0);
};

















void menuAziz() {
    int choix;

    do {
        cout << "=== Menu Principal ===" << endl;
        cout << "1 - Surcharge" << endl;
        cout << "2 - Fichiers" << endl;
        cout << "3 - Exception" << endl;
        cout << "4 - STL" << endl;
        cout << "0 - Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
    int sousChoix;
    do {
        cout << "--- Surcharge d'operateurs ---" << endl;
        cout << "1 - operator <<" << endl;
        cout << "2 - operator >>" << endl;
        cout << "3 - operator +" << endl;
        cout << "0 - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> sousChoix;

        switch (sousChoix) {
            case 1:{
                cout << "Vous avez choisi operator <<." << endl;
    Employe emp("Dupont", "Jean", 3000, 0);
    emp.ajouterCompetence("Communication");
    emp.ajouterCompetence("Gestion");
    cout << "Affichage Employe :" << endl;
    cout << emp << endl;
    Responsable resp("Durand", "Sophie", 5000, 0, "R&D");
    cout << "Affichage Responsable :" << endl;
    cout << resp << endl;
    Test t1("T1234");
    cout << "Affichage Test :" << endl;
    cout << t1 << endl;
    Pharmacien ph("Martin", "Luc", 4000, 0);
    Test* te = new Test("T5678");
    ph = ph + te;  // Ajouter un test
    cout << "Affichage Pharmacien :" << endl;
    cout << ph << endl;
    Etudiant etu("Leclerc", "Marie", "CIN12345", "Bien");
    etu.ajouterNote("Maths", 15.5);
    etu.ajouterNote("Physique", 14);
    cout << "Affichage Etudiant :" << endl;
    cout << etu << endl;
    Stagiaire stag("Bernard", "Paul", "CIN67890", "Très Bien", 1000, 0, 6);
    stag.ajouterCompetence("Communication");
    stag.ajouterProjet("Projet Pharmaceutique");
    stag.ajouterProjet("Étude de marché");
    cout << "Affichage Stagiaire :" << endl;
    cout << stag << endl;
    delete te;}
                break;
            case 2:{
                cout << "Vous avez choisi operator >>." << endl;
                   cout << "======== Test Employe ========" << endl;
    Employe emp;
    cout << "Entrez les informations de l'employé :" << endl;
    cin >> emp;
    cout << "Vous avez saisi :" << endl << emp;
    cout << "======== Test Responsable ========" << endl;
    Responsable resp("", "", 0, 0, "");
    cout << "Entrez les informations du responsable :" << endl;
    cin >> resp;
    cout << "Vous avez saisi :" << endl << resp;

    cout << "======== Test Pharmacien ========" << endl;
    Pharmacien ph;
    cout << "Entrez les informations du pharmacien :" << endl;
    cin >> ph;
    cout << "Vous avez saisi :" << endl << ph;
    cout << "======== Test Test ========" << endl;
    Test t;
    cout << "Entrez les informations du test :" << endl;
    cin >> t;
    cout << "Vous avez saisi :" << endl << t;

    cout << "======== Test Etudiant ========" << endl;
    Etudiant etu("", "", "", "");
    cout << "Entrez les informations de l'étudiant :" << endl;
    cin >> etu;
    cout << "Vous avez saisi :" << endl << etu;

    cout << "======== Test Stagiaire ========" << endl;
    Stagiaire stag("", "", "", "", 0, 0, 0);
    cout << "Entrez les informations du stagiaire :" << endl;
    cin >> stag;
    cout << "Vous avez saisi :" << endl << stag;}
                break;
            case 3:{
                cout << "Vous avez choisi operator +." << endl;
                 cout << "======== Test Pharmacien + Test* ========" << endl;
    Pharmacien ph("Martin", "Luc", 4000, 0);
    cout << "Avant l'ajout de tests :" << endl;
    cout << ph << endl;
    Test* t2 = new TestEnvironnement("ENV001", 22, 50, 1012);
    ph = ph + t2;
    cout << "Après l'ajout de tests :" << endl;
    cout << ph << endl;
    delete t2;}

                break;
            case 0:
                cout << "Retour au menu principal..." << endl;
                break;
            default:
                cout << "Sous-choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (sousChoix != 0);

    break;
}

case 2: {
    int sousChoixFichiers;
    do {
        cout << "--- Gestion des Fichiers ---" << endl;
        cout << "1 - Pharmacien" << endl;
        cout << "2 - Employe" << endl;
        cout << "0 - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> sousChoixFichiers;

        switch (sousChoixFichiers) {
            case 1: {
    int choixPharmacien;
    do {
        cout << "--- Gestion Fichier Pharmacien ---" << endl;
        cout << "1 - Afficher" << endl;
        cout << "2 - Ajouter" << endl;
        cout << "3 - Modifier" << endl;
        cout << "4 - Supprimer" << endl;
        cout << "0 - Retour" << endl;
        cout << "Votre choix : ";
        cin >> choixPharmacien;

        switch (choixPharmacien) {
            case 1:{
            cout << "Affichage des pharmaciens..." << endl;
            fstream f;
            cout << "===== Test Pharmacien - enregistrer_fichier() =====" << endl;
            Pharmacien p1;
            cin>>p1;
            p1.creer(f);
            p1.enregistrer_fichier();
            cout << "Pharmacien enregistré avec succès dans le fichier !" << endl;
            cout << "\n===== Test Pharmacien - lire_fichier() =====" << endl;
            Pharmacien* p2=new Pharmacien("","",0,0);
            p2->lire_fichier();
            cout << "Pharmacien lu depuis le fichier :" << endl;
            cout << p2;
                break;}
            case 2:{
                    int n;
                    cout << "Donner le nombre de pharmaciens : ";
                    cin >> n;
                    vector<Pharmacien> pharmaciens;
                    for (int i = 0; i < n; ++i) {
                    Pharmacien p;
                    cout << "Saisie du pharmacien #" << (i + 1) << " :" << endl;
                    cin >> p;
                    pharmaciens.push_back(p);}
                    ofstream fichier("Pharmacien.txt", ios::out);
                    if (!fichier) {
                        cerr << "Erreur d'ouverture du fichier !" << endl;
                        return ;}
                    for (auto& pharmacien : pharmaciens) {
                        fichier << pharmacien << endl;}
                    fichier.close();
                    cout << "\nTous les pharmaciens ont été enregistrés dans le fichier avec succès !" << endl;
                break;}
            case 3:{
                cout << "Modification d'un pharmacien" << endl;
                int n;
                cout << "Donner le nombre de pharmaciens : ";
                cin >> n;
                vector<Pharmacien> pharmaciens;
                for (int i = 0; i < n; ++i) {
                    Pharmacien p;
                    cout << "Saisie du pharmacien #" << (i + 1) << " :" << endl;
                    cin >> p;
                    pharmaciens.push_back(p);}
                cout << "\nListe des pharmaciens saisis :" << endl;
                for (size_t i = 0; i < pharmaciens.size(); ++i) {
                cout << "Pharmacien #" << (i + 1) << " :" << endl;
                cout << pharmaciens[i] << endl;}
                string nomModif;
                cout << "\nDonner le nom du pharmacien à modifier : ";
                cin >> nomModif;
                bool trouve = false;
                for (auto& pharmacien : pharmaciens) {
                if (pharmacien.getNom() == nomModif) {
                        cout << "Pharmacien trouvé. Entrez les nouvelles informations :" << endl;
                        cin >> pharmacien; // Remplacer les données avec cin (car operator>> est surchargé)
                trouve = true;
                break;}}
                if (!trouve) {
                    cout << "Aucun pharmacien trouvé avec ce nom." << endl;}
                else {
                ofstream fichier("Pharmacien.txt", ios::out);
                if (!fichier) {
                    cerr << "Erreur d'ouverture du fichier !" << endl;
                return ;}
                for (auto& pharmacien : pharmaciens) {
                        fichier << pharmacien << endl;}
                fichier.close();
                cout << "\nFichier mis à jour après modification." << endl;}
                break;}
            case 4:{
                cout << "Suppression d'un pharmacien" << endl;
                int n;
                cout << "Donner le nombre de pharmaciens : ";
                cin >> n;
                vector<Pharmacien> pharmaciens;
                for (int i = 0; i < n; ++i) {
                Pharmacien p;
                cout << "Saisie du pharmacien #" << (i + 1) << " :" << endl;
                cin >> p;
                pharmaciens.push_back(p);}
                cout << "\nListe des pharmaciens saisis :" << endl;
                for (size_t i = 0; i < pharmaciens.size(); ++i) {
                cout << "Pharmacien #" << (i + 1) << " :" << endl;
                cout << pharmaciens[i] << endl;}
                string nomSupp;
                cout << "\nDonner le nom du pharmacien à supprimer : ";
                cin >> nomSupp;
                auto it = pharmaciens.begin();
                while (it != pharmaciens.end()) {
                if (it->getNom() == nomSupp) {
                    it = pharmaciens.erase(it);
                    cout << "Pharmacien supprimé avec succès !" << endl;}
                else {++it;}}
                ofstream fichier("Pharmacien.txt", ios::out);
                if (!fichier) {
                    cerr << "Erreur d'ouverture du fichier !" << endl;
                return ;}
                for (auto& pharmacien : pharmaciens) {
                fichier << pharmacien << endl;}
                fichier.close();
                cout << "\nFichier mis à jour après suppression." << endl;
                break;}
            case 0:
                cout << "Retour au menu précédent..." << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (choixPharmacien != 0);

    break;
}

            case 2:{
    int choixEmploye;
    do {
        cout << "--- Gestion Fichier Employe ---" << endl;
        cout << "1 - Afficher" << endl;
        cout << "2 - Ajouter" << endl;
        cout << "3 - Modifier" << endl;
        cout << "4 - Supprimer" << endl;
        cout << "0 - Retour" << endl;
        cout << "Votre choix : ";
        cin >> choixEmploye;

        switch (choixEmploye) {
            case 1:{
                cout << "Affichage des employes..." << endl;
                fstream f;
                cout << "===== Test Employe - enregistrer_fichier() =====" << endl;
            Employe p1;
            cin>>p1;
            p1.creer(f);
            p1.enregistrer_fichier();
            cout << "Employe enregistré avec succès dans le fichier !" << endl;
            cout << "\n===== Test Employe - lire_fichier() =====" << endl;
            Employe* p2=new Employe("","",0,0);
            p2->lire_fichier();
            cout << "Employe lu depuis le fichier :" << endl;
            cout << p2;
                break;}
            case 2:{
                cout << "Ajout d'un employe" << endl;
                {
                    int n;
                    cout << "Donner le nombre de employes : ";
                    cin >> n;
                    vector<Employe> employes;
                    for (int i = 0; i < n; ++i) {
                    Employe p;
                    cout << "Saisie du pharmacien #" << (i + 1) << " :" << endl;
                    cin >> p;
                    employes.push_back(p);}
                    ofstream fichier("Employe.txt", ios::out);
                    if (!fichier) {
                        cerr << "Erreur d'ouverture du fichier !" << endl;
                        return ;}
                    for (auto& employe : employes) {
                        fichier << employe << endl;}
                    fichier.close();
                    cout << "\nTous les employes ont été enregistrés dans le fichier avec succès !" << endl;
                break;}
                break;}
            case 3:{
                cout << "Modification d'un employe" << endl;
                int n;
                cout << "Donner le nombre de employes : ";
                cin >> n;
                vector<Employe> employes;
                for (int i = 0; i < n; ++i) {
                    Employe p;
                    cout << "Saisie du employe #" << (i + 1) << " :" << endl;
                    cin >> p;
                    employes.push_back(p);}
                cout << "\nListe des employes saisis :" << endl;
                for (size_t i = 0; i < employes.size(); ++i) {
                cout << "Employe #" << (i + 1) << " :" << endl;
                cout << employes[i] << endl;}
                string nomModif;
                cout << "\nDonner le nom du employe à modifier : ";
                cin >> nomModif;
                bool trouve = false;
                for (auto& employe : employes) {
                if (employe.getNom() == nomModif) {
                        cout << "Employe trouvé. Entrez les nouvelles informations :" << endl;
                        cin >> employe;
                trouve = true;
                break;}}
                if (!trouve) {
                    cout << "Aucun employe trouvé avec ce nom." << endl;}
                else {
                ofstream fichier("Employe.txt", ios::out);
                if (!fichier) {
                    cerr << "Erreur d'ouverture du fichier !" << endl;
                return ;}
                for (auto& employe : employes) {
                        fichier << employe << endl;}
                fichier.close();
                cout << "\nFichier mis à jour après modification." << endl;}
                break;}
            case 4:{
                cout << "Suppression d'un employe" << endl;
                int n;
                cout << "Donner le nombre de employes : ";
                cin >> n;
                vector<Employe> employes;
                for (int i = 0; i < n; ++i) {
                Employe p;
                cout << "Saisie du employe #" << (i + 1) << " :" << endl;
                cin >> p;
                employes.push_back(p);}
                cout << "\nListe des employes saisis :" << endl;
                for (size_t i = 0; i < employes.size(); ++i) {
                cout << "Employe #" << (i + 1) << " :" << endl;
                cout << employes[i] << endl;}
                string nomSupp;
                cout << "\nDonner le nom du employe à supprimer : ";
                cin >> nomSupp;
                auto it = employes.begin();
                while (it != employes.end()) {
                if (it->getNom() == nomSupp) {
                    it = employes.erase(it);
                    cout << "Employe supprimé avec succès !" << endl;}
                else {++it;}}
                ofstream fichier("Employe.txt", ios::out);
                if (!fichier) {
                    cerr << "Erreur d'ouverture du fichier !" << endl;
                return;}
                for (auto& employe : employes) {
                fichier << employe << endl;}
                fichier.close();
                cout << "\nFichier mis à jour après suppression." << endl;
                break;}
            case 0:
                cout << "Retour au menu précédent..." << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (choixEmploye != 0);

    break;
}
            case 0:
                cout << "Retour au menu principal..." << endl;
                break;
            default:
                cout << "Sous-choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (sousChoixFichiers != 0);

    break;
}

            case 3:{
    cout << "Vous avez choisi Exception." << endl;
    cout << "======== Test des Exceptions ========" << endl;
    Employe emp("Dupont", "Jean", 3000, 0);
    emp.ajouterCompetence("Marketing");
    emp.ajouterCompetence("Management");
    try {
        cout << "Tentative d'acces a une competence existante (indice 0) :" << endl;
        cout << emp[0] << endl;

        cout << "Tentative d'acces a un indice invalide (indice 5) :" << endl;
        cout << emp[5] << endl;
    }
    catch (Employe::Exception_Indice e) {
        cerr << "Exception attrapee : Indice " << e.indice << " invalide !" << endl;
    }
                break;}
            case 4:{
                int sousChoixType;
    do {
        cout << "--- Gestion STL ---" << endl;
        cout << "1 - List" << endl;
        cout << "2 - Map" << endl;
        cout << "0 - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> sousChoixType;

        switch (sousChoixType) {
            case 1: {
        cout << "======== Test Affichage et Ajout de Projets dans Stagiaire ========" << endl;
    Stagiaire stagiaire("Durand", "Alice", "CIN123", "Biologie", 1200, 0, 6);
    stagiaire.ajouterProjet("Developpement d'une nouvelle formule chimique");
    stagiaire.ajouterProjet("Projet de recherche en biologie");
    cout << "\nListe des projets du stagiaire :" << endl;
    stagiaire.afficherProjets();
    break;}

            case 2:{ int choixMap;
    do {
        cout << "--- Menu Map ---" << endl;
        cout << "1 - Afficher et Ajouter" << endl;
        cout << "2 - Algorithmes" << endl;
        cout << "0 - Retour" << endl;
        cout << "Votre choix : ";
        cin >> choixMap;

        switch (choixMap) {
            case 1:{
                cout << "Affichage et Ajout..." << endl;
                cout << "======== Test Ajout et Affichage de la Map de Notes ========" << endl;
    Etudiant etu("Durand", "Alice", "CIN123", "Sciences");
    etu.ajouterNote("Mathématiques", 15.5);
    etu.ajouterNote("Physique", 17.0);
    etu.ajouterNote("SVT", 19.0);
    cout << "\nNotes de l'étudiant :" << endl;
    etu.afficherNotes();
    break;}
            case 2: {
    int choixAlgo;
    do {
        cout << "--- Menu Algorithmes STL ---" << endl;
        cout << "1 - Accumulate" << endl;
        cout << "2 - Find" << endl;
        cout << "0 - Retour" << endl;
        cout << "Votre choix : ";
        cin >> choixAlgo;

        switch (choixAlgo) {
            case 1:{
                cout << "Utilisation de l'algorithme accumulate..." << endl;
                Etudiant etu("Durand", "Alice", "CIN123", "Sciences");
                etu.ajouterNote("Mathématiques", 15.5);
                etu.ajouterNote("Physique", 17.0);
                etu.ajouterNote("SVT", 19.0);
                float moyenne = etu.calculerMoyenne();
                cout << "La moyenne des notes de l'étudiant est : " << moyenne << endl;

                break;}
            case 2:{
                cout << "Utilisation de l'algorithme find..." << endl;
                Etudiant etu("Durand", "Alice", "CIN123", "Sciences");
                etu.ajouterNote("Mathématiques", 15.5);
                etu.ajouterNote("Physique", 17.0);
                etu.ajouterNote("SVT", 19.0);
                float noteTrouvee;
                string matiere;
                etu.afficherNotes();
                cout<<"La Saisie de la note 'Physique':";
                cin>>noteTrouvee;
                bool trouve = etu.rechercherNote("Physique", noteTrouvee);
                if (trouve) {
                    cout << "La note de la matière 'Physique' est : " << noteTrouvee << endl;}
                else {
                    cout << "La matière 'Physique' n'a pas été trouvée." << endl;}
                cout<<"La Saisie d'une matiere inexistante:";
                cin>>matiere;
                    trouve = etu.rechercherNote(matiere, noteTrouvee);
                if (trouve) {
                    cout << "La note de la matière 'Chimie' est : " << noteTrouvee << endl;}
                else {
                    cout << "La matière "<<matiere<<" n'a pas ete trouvée." << endl;}
                break;}
            case 0:
                cout << "Retour au menu précédent..." << endl;
                break;

            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;}

        cout << endl;
    } while (choixAlgo != 0);
    break;
}

                break;
            case 0:

                cout << "Retour au menu précédent..." << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (choixMap != 0);

    break;
}

            case 0:
                cout << "Retour au menu principal..." << endl;
                break;
            default:
                cout << "Sous-choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (sousChoixType != 0);

    break;
} // STL

            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
                break;
        }

        cout << endl;
    } while (choix != 0);
}

int main() {
    int choix;
    do {
        cout << "\n=== Menu Principal ===\n";
        cout << "1. Aller au sous-menu Hazem\n";
        cout << "2. Aller au sous-menu Aziz\n";
        cout << "0. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                menuHazem();
                break;
            case 2:
                menuAziz();
                break;
            case 0:
                cout << "Fin du programme.\n";
                break;
            default:
                cout << "Choix invalide.\n";
        }
    } while (choix != 0);

    return 0;
}

