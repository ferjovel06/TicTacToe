#include <stdio.h>
#include <stdlib.h>

#define TAMANO 3

char jugador1, jugador2, jugadorEnTurno;
int turnos, ganador = 0, eleccion, fila, columna;
char tablero[TAMANO][TAMANO] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void Menu();
void ElegirFicha(int eleccion);
void SortearTurnoInicial();
void DibujarTablero();
void IngresaJugada();
int VerificarGanador();
int MostrarMesajeInicial();
void ImprimirSaltoDeLinea();
void ImprimirFilas(int i);
void ImprimirColumnas(int j);
void CambiarJugadorEnTurno();
void ComprobarJugadaValida(int fila, int columna);
void ComprobarTablero();

int main() {

    Menu();
    SortearTurnoInicial();
    while (ganador == 0) {
        DibujarTablero();
        IngresaJugada();
        VerificarGanador();
    }
}

/* Menu
 * Muestra el menu de seleccion de ficha
 * y asigna las fichas a los jugadores
 */
void Menu() {
    eleccion = MostrarMesajeInicial();
    ElegirFicha(eleccion);
}

int MostrarMesajeInicial() {
    printf("Bienvenido al juego de Tic Tac Toe\n");
    printf("1. X\n");
    printf("2. O\n");
    printf("Ingresa tu eleccion: ");
    scanf("%d", &eleccion);
    return eleccion;
}

void ElegirFicha(int eleccion) {
    if (eleccion == 1) {
        jugador1 = 'X';
        jugador2 = 'O';
    } else {
        jugador1 = 'O';
        jugador2 = 'X';
    }
}

/* SortearTurnoInicial
 * Sortea quien inicia el juego
 * y asigna el jugador en turno
 */
void SortearTurnoInicial() {
    printf("Sorteando quien inicia el juego...\n");
    if (rand() % 2 == 0) {
        jugadorEnTurno = jugador1;
        printf("El jugador 1 (%c) inicia el juego\n", jugador1);
    } else {
        jugadorEnTurno = jugador2;
        printf("El jugador 2 (%c) inicia el juego\n", jugador2);
    }
}

/* DibujarTablero
 * Dibuja el tablero de juego
 */
void DibujarTablero() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf(" %c", tablero[i][j]);
            ImprimirColumnas(j);
        }
        ImprimirFilas(i);

    }
    ImprimirSaltoDeLinea();
}

void ImprimirSaltoDeLinea() {
    printf("\n");
}

void ImprimirFilas(int i) {
    if(i < 2) {
        printf("\n---|---|---\n");
    }
}

void ImprimirColumnas(int j) {
    if (j < 2) {
        printf(" |");
    }
}

/* IngresaJugada
 * Pide al jugador en turno que ingrese su jugada
 * y verifica si la casilla esta ocupada
 * y si la jugada es valida
 */
void IngresaJugada() {
    int fila, columna;
    printf("Jugador %c, ingresa tu jugada (fila y columna): ", jugadorEnTurno);
    scanf("%d %d", &fila, &columna);
    fila--;
    columna--;
    ComprobarJugadaValida(fila, columna);
}

void CambiarJugadorEnTurno() {
    if (jugadorEnTurno == jugador1) {
        jugadorEnTurno = jugador2;
    } else {
        jugadorEnTurno = jugador1;
    }
}

void ComprobarJugadaValida(int fila, int columna) {
    if (tablero[fila][columna] == ' ') {
        tablero[fila][columna] = jugadorEnTurno;
        turnos++;
        CambiarJugadorEnTurno();
    } else if (fila < 0 || fila > 2 || columna < 0 || columna > 2) {
        printf("Jugada invalida\n");
    } else {
        printf("Casilla ocupada\n");
    }
}

/* VerificarGanador
 * Verifica si hay un ganador
 * o si hay un empate e imprime el resultado
 */
int VerificarGanador() {
    ComprobarTablero();

    if (ganador == 1) {
        DibujarTablero();
        printf("Hay un ganador\n");
    }

    if (turnos == 9 && ganador == 0) {
        DibujarTablero();
        printf("Empate\n");
    }
    return ganador;
}

void ComprobarTablero() {
    int i;
    for (i = 0; i < 3; i++) {
        if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') ||
            (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') ||
            (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') ||
            (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')) {
            ganador = 1;
        }
    }
}
