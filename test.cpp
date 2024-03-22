#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

enum class Color { Bleu, Jaune, Rouge, Vert };
enum class Shape { Carre, Losange, Rond, Triangle };

class Piece {
private:
    Color color;
    Shape shape;
public:
    Piece(Color c, Shape s) : color(c), shape(s) {}

    Color getColor() const { return color; }
    Shape getShape() const { return shape; }
};

class Board {
private:
    std::vector<Piece> pieces;
public:
    void addPiece(const Piece& piece) {
        pieces.push_back(piece);
    }

    void removeConsecutive() {
        int size = pieces.size();
        if (size < 3) return;

        for (int i = 2; i < size; ++i) {
            if ((pieces[i].getColor() == pieces[i-1].getColor() && pieces[i].getColor() == pieces[i-2].getColor()) ||
                (pieces[i].getShape() == pieces[i-1].getShape() && pieces[i].getShape() == pieces[i-2].getShape())) {
                pieces.erase(pieces.begin() + i - 2, pieces.begin() + i + 1);
                size = pieces.size();
                i -= 2;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Board& board) {
        for (const auto& piece : board.pieces) {
            os << "(";
            switch (piece.getColor()) {
                case Color::Bleu:
                    os << "Bleu, ";
                    break;
                case Color::Jaune:
                    os << "Jaune, ";
                    break;
                case Color::Rouge:
                    os << "Rouge, ";
                    break;
                case Color::Vert:
                    os << "Vert, ";
                    break;
            }
            switch (piece.getShape()) {
                case Shape::Carre:
                    os << "Carre) ";
                    break;
                case Shape::Losange:
                    os << "Losange) ";
                    break;
                case Shape::Rond:
                    os << "Rond) ";
                    break;
                case Shape::Triangle:
                    os << "Triangle) ";
                    break;
            }
        }
        return os;
    }
};

class Game {
private:
    Board board;
public:
    void play() {
        std::srand(std::time(nullptr));

        for (int i = 0; i < 10; ++i) { // 10 iterations pour cet exemple
            Color color = static_cast<Color>(std::rand() % 4);
            Shape shape = static_cast<Shape>(std::rand() % 4);
            Piece piece(color, shape);
            board.addPiece(piece);
            board.removeConsecutive();
            std::cout << "Étape " << i+1 << ": " << board << std::endl;
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
