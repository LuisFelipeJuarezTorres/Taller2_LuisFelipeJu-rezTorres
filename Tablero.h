#include <iostream>
#include <vector>
#include <limits>
using namespace std;


class Tablero {
private:
    char tablero[3][3];

public:
    
    Tablero();

    void reiniciarTab();

    void imprimirGato();

    bool HacerMovimi(int fila, int columna, char jugador);

    bool Tablerolleno();

    vector<pair<int, int>> movPosibles();

    int EstadoGato();

    void eliminarMovimiento(int fila, int columna);

    int minimax(Tablero& tablero, int profundidad, bool esMax);

    int minimaxPoda(Tablero& tablero, int profundidad, bool esMax, int alfa, int beta);

    pair<int, int> mejorMovimiento(Tablero& tablero, bool usarPoda);

    void DosJugadores(Tablero& tablero);

}; 