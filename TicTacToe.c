#include <stdio.h>
#include <stdlib.h>

char jugador1, jugador2, jugadorEnTurno;
int turnos, ganador = 0, eleccion;
int tablero[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void Menu() {
    printf("Bienvenido al juego de Tic Tac Toe\n");
    printf("1. X\n");
    printf("2. O\n");
    printf("Ingresa tu eleccion: ");
    scanf("%d", &eleccion);
    if (eleccion == 1) {
        jugador1 = 'X';
        jugador2 = 'O';
    } else {
        jugador1 = 'O';
        jugador2 = 'X';
    }
}

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

void DibujarTablero() {
    printf(" %c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);
}

void IngresaJugada() {
    int fila, columna;
    printf("Jugador %c, ingresa tu jugada (fila y columna): ", jugadorEnTurno);
    scanf("%d %d", &fila, &columna);
    fila--;
    columna--;
    if (tablero[fila][columna] == ' ') {
        tablero[fila][columna] = jugadorEnTurno;
        turnos++;
        if (jugadorEnTurno == jugador1) {
            jugadorEnTurno = jugador2;
        } else {
            jugadorEnTurno = jugador1;
        }
    } else {
        printf("La casilla ya esta ocupada\n");
    }
}

int VerificarGanador() {
    int i;
    for (i = 0; i < 3; i++) {
        if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') ||
            (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') ||
            (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') ||
            (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')) {
            ganador = 1;
        }
    }

    if (ganador == 1) {
        DibujarTablero();
        printf("Hay un ganador\n");
    }

    if (turnos == 9) {
        DibujarTablero();
        printf("Empate\n");
    }
    return ganador;
}

int main() {

    Menu();
    SortearTurnoInicial();
    while (ganador == 0) {
        DibujarTablero();
        IngresaJugada();
        VerificarGanador();
    }
}
