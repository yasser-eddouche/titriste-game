#include <iostream>
#include <cstdlib>
#include <ctime>

// Enumération des formes et couleurs
enum class Forme { Carre, Losange, Rond, Triangle };
enum class Couleur { Bleu, Jaune, Rouge, Vert };

// Structure de la pièce
struct Piece {
    Forme forme;
    Couleur couleur;
    Piece* suivanteForme; // Pièce suivante avec la même forme
    Piece* precedenteForme; // Pièce précédente avec la même forme
    Piece* suivanteCouleur; // Pièce suivante avec la même couleur
    Piece* precedenteCouleur; // Pièce précédente avec la même couleur
};

// Classe du jeu Tetriste
class Tetriste {
private:
    Piece* plateauDeJeu;
    Piece* dernierePiece;
    Piece* piecesFormes[4]; // Tableau des listes de pièces par forme
    Piece* piecesCouleurs[4]; // Tableau des listes de pièces par couleur

    void insererPiece(Piece* nouvellePiece, Piece* position);
    void supprimerPiece(Piece* piece);
    void deplacerPiece(Piece* piece, bool versLaGauche);
    void afficherPlateauDeJeu();

public:
    Tetriste();
    ~Tetriste();
    void jouer();
};

// Constructeur de Tetriste
Tetriste::Tetriste() {
    plateauDeJeu = nullptr;
    dernierePiece = nullptr;

    // Initialisation des listes de pièces par forme et par couleur
    for (int i = 0; i < 4; ++i) {
        piecesFormes[i] = nullptr;
        piecesCouleurs[i] = nullptr;
    }
}

// Destructeur de Tetriste
Tetriste::~Tetriste() {
    // Libération de la mémoire des pièces
    Piece* current = plateauDeJeu;
    while (current != nullptr) {
        Piece* temp = current;
        current = current->suivanteForme;
        delete temp;
    }
}

// Méthode pour insérer une nouvelle pièce sur le plateau de jeu
void Tetriste::insererPiece(Piece* nouvellePiece, Piece* position) {
    if (position == nullptr) {
        // Insérer en fin de liste
        if (plateauDeJeu == nullptr) {
            plateauDeJeu = nouvellePiece;
            dernierePiece = nouvellePiece;
        } else {
            dernierePiece->suivanteForme = nouvellePiece;
            nouvellePiece->precedenteForme = dernierePiece;
            dernierePiece = nouvellePiece;
        }
    } else {
        // Insérer avant la position spécifiée
        if (position->precedenteForme != nullptr)
            position->precedenteForme->suivanteForme = nouvellePiece;
        else
            plateauDeJeu = nouvellePiece;

        nouvellePiece->precedenteForme = position->precedenteForme;
        nouvellePiece->suivanteForme = position;
        position->precedenteForme = nouvellePiece;
    }
}

// Méthode pour supprimer une pièce du plateau de jeu
void Tetriste::supprimerPiece(Piece* piece) {
    if (piece->precedenteForme != nullptr)
        piece->precedenteForme->suivanteForme = piece->suivanteForme;
    else
        plateauDeJeu = piece->suivanteForme;

    if (piece->suivanteForme != nullptr)
        piece->suivanteForme->precedenteForme = piece->precedenteForme;

    delete piece;
}

// Méthode pour déplacer une pièce vers la gauche ou la droite
void Tetriste::deplacerPiece(Piece* piece, bool versLaGauche) {
    if (versLaGauche) {
        if (piece->precedenteForme != nullptr) {
            supprimerPiece(piece);
            insererPiece(piece, piece->precedenteForme);
        }
    } else {
        if (piece->suivanteForme != nullptr) {
            supprimerPiece(piece);
            insererPiece(piece, piece->suivanteForme->suivanteForme);
        }
    }
}

// Méthode pour afficher le plateau de jeu
void Tetriste::afficherPlateauDeJeu() {
    Piece* current = plateauDeJeu;
    while (current != nullptr) {
        // Afficher la pièce avec sa couleur et sa forme
        switch (current->forme) {
            case Forme::Carre:
                std::cout << "\033[34m";
                break;
            case Forme::Losange:
                std::cout << "\033[31m";
                break;
            case Forme::Rond:
                std::cout << "\033[32m";
                break;
            case Forme::Triangle:
                std::cout << "\033[33m";
                break;
        }

        switch (current->couleur) {
            case Couleur::Bleu:
                std::cout << "B ";
                break;
            case Couleur::Jaune:
                std::cout << "J ";
                break;
            case Couleur::Rouge:
                std::cout << "R ";
                break;
            case Couleur::Vert:
                std::cout << "V ";
                break;
        }

        current = current->suivanteForme;
    }
    std::cout << std::endl;
}

// Méthode principale pour jouer au jeu Tetriste
void Tetriste::jouer() {
    srand(time(nullptr));

    // Boucle principale du jeu
    while (true) {
        // Générer une nouvelle pièce aléatoire
        Piece* nouvellePiece = new Piece;
        nouvellePiece->forme = static_cast<Forme>(rand() % 4);
        nouvellePiece->couleur = static_cast<Couleur>(rand() % 4);
        nouvellePiece->suivanteForme = nullptr;
        nouvellePiece->precedenteForme = nullptr;
        nouvellePiece->suivanteCouleur = nullptr;
        nouvellePiece->precedenteCouleur = nullptr;

        // Insérer la nouvelle pièce sur le plateau de jeu
        insererPiece(nouvellePiece, nullptr);

        // Afficher le plateau de jeu
        afficherPlateauDeJeu();

        // Attendre l'entrée du joueur pour la prochaine action
        std::cout << "Appuyez sur 'g' pour décaler à gauche, 'd' pour décaler à droite ou 'q' pour quitter : ";
        char action;
        std::cin >> action;

        // Gérer les actions du joueur
        switch (action) {
            case 'g':
                // Décaler la pièce actuelle à gauche
                deplacerPiece(dernierePiece, true);
                break;
            case 'd':
                // Décaler la pièce actuelle à droite
                deplacerPiece(dernierePiece, false);
                break;
            case 'q':
                // Quitter le jeu
                return;
            default:
                std::cout << "Commande invalide !" << std::endl;
        }
    }
}

// Fonction principale
int main() {
    Tetriste jeu;
    jeu.jouer();
    return 0;
}
