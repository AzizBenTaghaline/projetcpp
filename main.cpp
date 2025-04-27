#include <iostream>
#include <vector>
#include <fstream>
#include "projetcpp.h"
using namespace std;

int main() {
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
            case 1: { // Pharmacien
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
            case 1:
                cout << "Affichage des pharmaciens..." << endl;
                // fonction afficherPharmaciens();
                break;
            case 2:
                cout << "Ajout d'un pharmacien" << endl;
                // fonction ajouterPharmacienAvecOperator();
                break;
            case 3:
                cout << "Modification d'un pharmacien" << endl;
                // fonction modiferPharmacien();
                break;
            case 4:
                cout << "Suppression d'un pharmacien" << endl;
                // fonction supprimerPharmacien();
                break;
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

            case 2:{ // Employe
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
            case 1:
                cout << "Affichage des employes..." << endl;
                // fonction afficherPharmaciens();
                break;
            case 2:
                cout << "Ajout d'un employe" << endl;
                // fonction ajouterPharmacienAvecOperator();
                break;
            case 3:
                cout << "Modification d'un employe" << endl;
                // fonction modiferPharmacien();
                break;
            case 4:
                cout << "Suppression d'un employe" << endl;
                // fonction supprimerPharmacien();
                break;
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
            case 2: { // Algorithmes
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
                bool trouve = etu.rechercherNote("Physique", noteTrouvee);
                if (trouve) {
                    cout << "La note de la matière 'Physique' est : " << noteTrouvee << endl;}
                else {
                    cout << "La matière 'Physique' n'a pas été trouvée." << endl;}
                trouve = etu.rechercherNote("Chimie", noteTrouvee);
                if (trouve) {
                    cout << "La note de la matière 'Chimie' est : " << noteTrouvee << endl;}
                else {
                    cout << "La matière 'Chimie' n'a pas été trouvée." << endl;}
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

    return 0;
}
