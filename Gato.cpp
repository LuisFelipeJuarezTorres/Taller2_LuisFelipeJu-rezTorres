#include "Tablero.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Gato{

    private:
    Tablero tableroJuego;
    int opcion;

    public:
    
    void Jugar(){
        cout << "Hola!!!\n";
        cout << ">>>>>>>>>>>>>JUEGO DEL GATO<<<<<<<<<<<<<<\n";
        cout << "Opciones del Gato:\n";
        cout << "1-) ^-^ Juego dos jugadores\n";
        cout << "2-) ^-^ Jugar contra una Ia - Minimax sin poda\n";
        cout << "3-) ^-^ Jugar contra una Ia - Minimax con poda alfa--beta\n";
        cin >> opcion;

        if (opcion == 1) {
            tableroJuego.DosJugadores(tableroJuego);
        } else if (opcion == 2 || opcion == 3) {
            bool usarPoda = (opcion == 3);
            tableroJuego.imprimirGato();
            bool turnoJugador = true;

            while (true) {
                if (tableroJuego.Tablerolleno() || tableroJuego.EstadoGato() != 0) break;

                if (turnoJugador) {
                    int fila, columna;
                    cout << "Tu turno -O-. Ingrese fila y columna: ";
                    cin >> fila >> columna;
                    if (!tableroJuego.HacerMovimi(fila, columna, 'O')) {
                        cout << "Movimiento inválido. Intenta de nuevo.\n";
                        continue;
                    }
                } else {
                    cout << "Turno de la inteligencia artificial -X-\n";
                    pair<int, int> movimiento = tableroJuego.mejorMovimiento(tableroJuego, usarPoda);
                    tableroJuego.HacerMovimi(movimiento.first, movimiento.second, 'X');
                }

                tableroJuego.imprimirGato();
                turnoJugador = !turnoJugador;
            }

            int resultado = tableroJuego.EstadoGato();
            if (resultado == 10) cout << "*^-^* La Ia -X- gana!!! No te desanimes, sigue jugando.\n";
            else if (resultado == -10) cout << "*^-^* Tú -O- ganas!!! Felicidades!!!\n";
            else cout << "*^-^* Empate!!! Sigue jugando.\n";

            } else {
                cout << " :( Opción incorrecta.\n";
            }
    }
   
};

int main(){

    Gato gato;
    gato.Jugar();


    return 0;

}