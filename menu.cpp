#include <iostream>
#include <cstdlib>
#include <ctime>
#include "casino.h"

using namespace std;

int main () {
   
    int opcion;
    char continuar = 'Y';
    float saldo = 600.0f;

    system("chcp 65001 > nul");
    srand(time(0)); // una sola vez, sirve para los tres juegos

    while (continuar == 'Y' || continuar == 'y') {
        cout << "\nSaldo Actual: $" << saldo << endl;
        cout << "=======================" << endl;
        cout << "||    CASINO - MENU   ||" << endl;
        cout << "=======================" << endl;
        cout << "||  1. Tragamonedas   ||" << endl;
        cout << "||  2. Ruleta         ||" << endl;
        cout << "||  3. Blackjack      ||" << endl;
        cout << "||  0. Salir          ||" << endl;
        cout << "=======================" << endl;

        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugarTragamonedas(saldo);
                break;
            case 2:
                jugarRuleta(saldo);
                break;
            case 3:
                jugarBlackjack(saldo);
                break;
            case 0:
                cout << "\nRetirando tus fondos... Saliendo del casino.\n";
                continuar = 'N';
                break;
            default:
                cout << "\nOpcion no valida. Por favor, ingresa un numero del 0 al 3.\n";
                break;
        }

        if (opcion != 0) {
            cout << "\nDeseas jugar nuevamente? (Y - Si / N - No): ";
            cin >> continuar; 
        }
    }

    cout << "\nGracias por jugar. Tu saldo final es: $" << saldo << endl;
    return 0;
}