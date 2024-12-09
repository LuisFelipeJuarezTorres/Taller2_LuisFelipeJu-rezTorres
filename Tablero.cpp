#include <iostream>
#include <vector>
#include <limits>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    reiniciarTab();
}

void Tablero::reiniciarTab() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void Tablero::eliminarMovimiento(int fila, int columna) {
        tablero[fila][columna] = ' ';
    }

void Tablero::imprimirGato() {
    cout << "   0 -  1 - 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j];
            if (j < 2) cout << " ||";
        }
        cout << "\n";
        if (i < 2) cout << "  ---||---||---\n";
    }
}

bool Tablero::HacerMovimi(int fila, int columna, char jugador) {
    if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3 || tablero[fila][columna] != ' ')
        return false;
    tablero[fila][columna] = jugador;
    return true;
}

bool Tablero::Tablerolleno() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') return false;
        }
    }
    return true;
}

vector<pair<int, int>> Tablero::movPosibles() {
    vector<pair<int, int>> movimientos;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                movimientos.emplace_back(i, j);
            }
        }
    }
    return movimientos;
}

int Tablero::EstadoGato() {
    
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            if (tablero[i][0] == 'X') return 10;
            if (tablero[i][0] == 'O') return -10;
        }
    }

    
    for (int i = 0; i < 3; i++) {
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            if (tablero[0][i] == 'X') return 10;
            if (tablero[0][i] == 'O') return -10;
        }
    }

    
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        if (tablero[0][0] == 'X') return 10;
        if (tablero[0][0] == 'O') return -10;
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        if (tablero[0][2] == 'X') return 10;
        if (tablero[0][2] == 'O') return -10;
    }

    
    return 0;
}

int Tablero::minimax(Tablero& tablero, int profundidad, bool esMax) {
    int puntaje = tablero.EstadoGato();
    if (puntaje != 0 || tablero.Tablerolleno()) return puntaje;

    if (esMax) {
        int mejor = numeric_limits<int>::min();
        for (auto movimiento : tablero.movPosibles()) {
            tablero.HacerMovimi(movimiento.first, movimiento.second, 'X');
            mejor = max(mejor, minimax(tablero, profundidad + 1, false));
            tablero.eliminarMovimiento(movimiento.first, movimiento.second);
        }
        return mejor;
    } else {
        int mejor = numeric_limits<int>::max();
        for (auto movimiento : tablero.movPosibles()) {
            tablero.HacerMovimi(movimiento.first, movimiento.second, 'O');
            mejor = min(mejor, minimax(tablero, profundidad + 1, true));
            tablero.eliminarMovimiento(movimiento.first, movimiento.second);
        }
        return mejor;
    }
}


int Tablero::minimaxPoda(Tablero& tablero, int profundidad, bool esMax, int alfa, int beta) {
    int puntaje = tablero.EstadoGato();
    if (puntaje != 0 || tablero.Tablerolleno()) return puntaje;

    if (esMax) {
        int mejor = numeric_limits<int>::min();
        for (auto movimiento : tablero.movPosibles()) {
            tablero.HacerMovimi(movimiento.first, movimiento.second, 'X');
            mejor = max(mejor, minimaxPoda(tablero, profundidad + 1, false, alfa, beta));
            tablero.eliminarMovimiento(movimiento.first, movimiento.second);
            alfa = max(alfa, mejor);
            if (beta <= alfa) break; 
        }
        return mejor;
    } else {
        int mejor = numeric_limits<int>::max();
        for (auto movimiento : tablero.movPosibles()) {
            tablero.HacerMovimi(movimiento.first, movimiento.second, 'O');
            mejor = min(mejor, minimaxPoda(tablero, profundidad + 1, true, alfa, beta));
            tablero.eliminarMovimiento(movimiento.first, movimiento.second);
            beta = min(beta, mejor);
            if (beta <= alfa) break; 
        }
        return mejor;
    }
}


pair<int, int> Tablero::mejorMovimiento(Tablero& tablero, bool usarPoda) {
    int mejorValor = numeric_limits<int>::min();
    pair<int, int> mejorMovimiento = {-1, -1};

    for (auto movimiento : tablero.movPosibles()) {
        tablero.HacerMovimi(movimiento.first, movimiento.second, 'X');
        int valor = usarPoda
        ? minimaxPoda(tablero, 0, false, numeric_limits<int>::min(), numeric_limits<int>::max())
        : minimax(tablero, 0, false);
        tablero.eliminarMovimiento(movimiento.first, movimiento.second);

        if (valor > mejorValor) {
            mejorValor = valor;
            mejorMovimiento = movimiento;
        }
    }
    return mejorMovimiento;
}



void Tablero::DosJugadores(Tablero& tablero) {
    cout << "Juego Gato entre 2 personas. Comienzen!!!\n";
    tablero.imprimirGato();

    char jugadorActual = 'O';
    while (true) {
        if (tablero.Tablerolleno() || tablero.EstadoGato() != 0) break;

        int fila, columna;
        cout << "Turno del jugador (" << jugadorActual << "). Ingresa fila y columna: ";
        cin >> fila >> columna;

        if (!tablero.HacerMovimi(fila, columna, jugadorActual)) {
            cout << "Movimiento inválido. Intenta de nuevo.\n";
            continue;
        }

        tablero.imprimirGato();
        jugadorActual = (jugadorActual == 'O') ? 'X' : 'O';
    }

    int resultado = tablero.EstadoGato();
    if (resultado == 10) cout << "El jugador -X- gana!!!\n";
    else if (resultado == -10) cout << "El jugador -O- gana!!!\n";
    else cout << "Empate!!! Felicidades a los dos.\n";
}


