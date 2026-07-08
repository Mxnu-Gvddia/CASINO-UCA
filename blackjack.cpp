#include <iostream>
#include <cstdlib>
#include <ctime>
#include "casino.h"
using namespace std;

const int MAX_CARTAS = 12;

int generarCarta()
{
  return (rand() % 13) + 1;
}

int calcularValorMano(int cartas[], int cantidad)
{
  int total = 0;
  int ases = 0;

  for (int i = 0; i < cantidad; i++)
  {
    int carta = cartas[i];
    int valor;

    if (carta == 1)
    {
      valor = 11;
      ases++;
    }
    else if (carta > 10)
    {
      valor = 10;
    }
    else
    {
      valor = carta;
    }
    total += valor;
  }

  while (total > 21 && ases > 0)
  {
    total -= 10;
    ases--;
  }

  return total;
}

void mostrarCarta(int carta)
{
  switch (carta)
  {
  case 1:
    cout << "As";
    break;
  case 11:
    cout << "J";
    break;
  case 12:
    cout << "Q";
    break;
  case 13:
    cout << "K";
    break;
  default:
    cout << carta;
    break;
  }
}

void mostrarMano(int cartas[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    mostrarCarta(cartas[i]);
    if (i < cantidad - 1)
      cout << " - ";
  }
}

// Antes era int main(). Ahora recibe el saldo del casino por referencia.
void jugarBlackjack(float& saldo)
{
  int puntos = (int)saldo;
  char continuarJugando;

  cout << "=================================================\n";
  cout << "|  BIENVENIDO AL CASINO - JUEGO 21 (BLACKJACK)  |\n";
  cout << "=================================================\n";
  cout << "Tienes " << puntos << " fichas para jugar.\n\n";

  do
  {
    int jugador[MAX_CARTAS];
    int dealer[MAX_CARTAS];
    int nJugador = 0;
    int nDealer = 0;
    int apuesta;

    do
    {
      cout << "Fichas disponibles: " << puntos << "\n";
      cout << "Ingresa tu apuesta: ";
      cin >> apuesta;

      if (apuesta <= 0 || apuesta > puntos)
      {
        cout << "Apuesta invalida. Debe ser mayor a 0 y no superar tus fichas.\n";
      }
    } while (apuesta <= 0 || apuesta > puntos);

    for (int i = 0; i < 2; i++)
    {
      jugador[nJugador++] = generarCarta();
      dealer[nDealer++] = generarCarta();
    }

    cout << "\nTu mano: ";
    mostrarMano(jugador, nJugador);
    cout << " (Total: " << calcularValorMano(jugador, nJugador) << ")\n";

    cout << "Mano del dealer: ";
    mostrarCarta(dealer[0]);
    cout << " y una carta oculta\n\n";

    bool sePlanto = false;
    while (!sePlanto && calcularValorMano(jugador, nJugador) < 21)
    {
      int opcion;
      cout << "1. Pedir carta\n2. Plantarse\nElige una opcion: ";
      cin >> opcion;

      switch (opcion)
      {
      case 1:
      {
        jugador[nJugador++] = generarCarta();
        cout << "Carta recibida: ";
        mostrarCarta(jugador[nJugador - 1]);
        cout << "\nTu mano: ";
        mostrarMano(jugador, nJugador);
        cout << " (Total: " << calcularValorMano(jugador, nJugador) << ")\n\n";
        break;
      }
      case 2:
        sePlanto = true;
        cout << "Te plantaste con " << calcularValorMano(jugador, nJugador) << " puntos.\n\n";
        break;
      default:
        cout << "Opcion invalida, intenta de nuevo.\n";
        break;
      }
    }

    int totalJugador = calcularValorMano(jugador, nJugador);

    if (totalJugador <= 21)
    {
      cout << "Turno del dealer...\n";
      while (calcularValorMano(dealer, nDealer) < 17)
      {
        dealer[nDealer++] = generarCarta();
      }
    }

    int totalDealer = calcularValorMano(dealer, nDealer);

    cout << "\nMano final del dealer: ";
    mostrarMano(dealer, nDealer);
    cout << " (Total: " << totalDealer << ")\n";
    cout << "Tu mano final: ";
    mostrarMano(jugador, nJugador);
    cout << " (Total: " << totalJugador << ")\n\n";

    if (totalJugador > 21)
    {
      cout << "Te pasaste de 21. PERDISTE la ronda.\n";
      puntos -= apuesta;
    }
    else if (totalDealer > 21 || totalJugador > totalDealer)
    {
      cout << "GANASTE la ronda!\n";
      puntos += apuesta; 
    }
    else if (totalJugador == totalDealer)
    {
      cout << "Empate. Se te devuelve la apuesta.\n";
    }
    else
    {
      cout << "PERDISTE la ronda.\n";
      puntos -= apuesta;
    }

    cout << "\nFichas actuales: " << puntos << "\n";

    if (puntos <= 0)
    {
      cout << "\nTe quedaste sin fichas. Fin del juego.\n";
      break;
    }

    cout << "\nDeseas continuar jugando? (S/N): ";
    cin >> continuarJugando;
    cout << "\n------------------------------------------\n\n";

  } while (continuarJugando == 'S' || continuarJugando == 's');

  cout << "\n";
  cout << "======================================\n";
  cout << "|  Puntuacion final: " << puntos << " fichas       |\n";
  cout << "|  Gracias por jugar. Hasta luego!   | \n";
  cout << "======================================\n";

  saldo = puntos; // guardo el dinero de vuelta al casino
}
