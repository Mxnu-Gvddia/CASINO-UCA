#include <iostream>
#include <cstdlib> // Necesaria para rand y srand
#include <ctime>   // Necesaria para time
#include <windows.h>
using namespace std;
// Variables
int saldo = 1000, Apuesta, Numero, Numeroganador;
char continuar1 = 'S', tipo_apuesta, opcionColor, ColorGanador;
// Funciones
void ColoryNumero();
void Cargando();
void LimpiarPantalla();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0)); // Es una semilla que cambia cada vez que incia el programa y se usa time (El reloj de la computadora), para que esto funcione debemos utilizar la libreria <cstdlib> Necesaria para rand() y srand() y <ctime> Necesaria para time()
    // Se usa para que el numero rand que genere sea diferente siempre que incie el programa

    while (continuar1 == 'S' || continuar1 == 's')
    {
        system("cls"); // Para limpiar la pantalla de texto viejo, asi cada que incia el programa, elimina el texto anterior y se ve mas limpio
        cout << "══════════════════════════════════════\n";
        cout << "        BIENVENIDO A LA RULETA\n";
        cout << "══════════════════════════════════════\n";
        cout << endl;
        cout << "┌──────────────────────────────\n";
        cout << "│ 💰 Saldo actual: $" << saldo << endl;
        cout << "└──────────────────────────────\n";

        {
            do
            {
                cout << "➜ Ingrese la cantidad a apostar: " << endl;
                cin >> Apuesta;
                if (Apuesta > saldo || Apuesta <= 0)
                {
                    cout << endl;
                    cout << "Apuesta inválida. Intente de nuevo." << endl;
                }
            } while (Apuesta > saldo || Apuesta <= 0);
            cout << endl;
            cout << "Apuesta válida. Continuando" << endl;
            Cargando();
            LimpiarPantalla();
        }
        cout << endl;
        cout << "╔════════════════════╗\n";
        cout << "║   TIPO DE APUESTA  ║\n";
        cout << "╠════════════════════╣\n";
        cout << "║ 1 ► Color          ║\n";
        cout << "║ 2 ► Número         ║\n";
        cout << "╚════════════════════╝\n";

        cout << "➜ Ingrese su opción: \n";
        cin >> tipo_apuesta;
        LimpiarPantalla();
        switch (tipo_apuesta)
        {
        case '1':
        {
            do
            {
                cout << endl;
                cout << "╔════════════════════════════════════════════╗\n";
                cout << "║        ¿A QUÉ COLOR DESEA APOSTAR?         ║\n";
                cout << "╠════════════════════════════════════════════╣\n";
                cout << "║  [1] ♦ ROJO                                ║\n";
                cout << "║  [2] ♠ NEGRO                               ║\n";
                cout << "║  [3] ♣ VERDE                               ║\n";
                cout << "╚════════════════════════════════════════════╝\n";

                cout << "➜ Ingrese su elección: ";
                cin >> opcionColor;

                if (opcionColor != '1' && opcionColor != '2' && opcionColor != '3')
                {
                    cout << endl;
                    cout << "Error. Color Invalido\n";
                }
            } while (opcionColor != '1' && opcionColor != '2' && opcionColor != '3');

            if (opcionColor == '1')
            {
                cout << endl;
                cout << "Has apostado al ♦ ROJO ♦.\n";
            }
            else if (opcionColor == '2')
            {
                cout << endl;
                cout << "Has apostado al ♠ NEGRO ♠.\n";
            }
            else
            {
                cout << endl;
                cout << "Has apostado al ♣ VERDE ♣.\n";
            }
            cout<<"Girando la ruleta";
            Cargando();
            LimpiarPantalla();
            ColoryNumero();
        }
        break;
        case '2':
        {
            do
            {
                cout << endl;
                cout << "╔════════════════════════════════════════════╗\n";
                cout << "║            🎰 APUESTA POR NÚMERO 🎰        ║\n";
                cout << "╠════════════════════════════════════════════╣\n";
                cout << "║  0   1   2   3   4   5   6                 ║\n";
                cout << "║  7   8   9  10  11  12  13                 ║\n";
                cout << "║ 14  15  16  17  18  19  20                 ║\n";
                cout << "║ 21  22  23  24  25  26  27                 ║\n";
                cout << "║ 28  29  30  31  32  33  34                 ║\n";
                cout << "║ 35  36                                     ║\n";
                cout << "╠════════════════════════════════════════════╣\n";
                cout << "║ Ingrese el número (0-36):                  ║\n";
                cout << "╚════════════════════════════════════════════╝\n";
                cout << "➜ ";
                cin >> Numero;
                if (Numero > 36 || Numero < 0)
                {
                    cout << endl;
                    cout << "Error. Numero Invalido\n";
                }

            } while (Numero > 36 || Numero < 0);
            cout<<"Girando la ruleta";
            Cargando();
            cout<<endl;
            LimpiarPantalla();
            ColoryNumero();
            break;
        default:
            cout << endl;
            cout << "La variable ingresada es incorrecta.\n";
        }
        break;
        }
        cout << endl;
        cout << "┌──────────────────────────────\n";
        cout << "│ 💰 Saldo actual: $" << saldo << endl;
        cout << "└──────────────────────────────\n";

        if (saldo > 0)
        {
            cout << endl;
            cout << "Desea voler a apostar? (S/N): " << endl;
            cin >> continuar1;
            LimpiarPantalla();
        }
        else
        {
            cout << endl;
            cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            cout << "             GAME OVER" << endl;
            cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            cout<<endl;
            return 0;
        }
    }
}
void ColoryNumero()
{
    Numeroganador = rand() % 37;
    if (Numeroganador == 0)
    {
        ColorGanador = '3'; // Verde
    }
    else if (Numeroganador % 2 == 0)
    {
        ColorGanador = '1'; // Rojo (Pares)
    }
    else
    {
        ColorGanador = '2'; // Negro (Impares)
    }
    switch (tipo_apuesta)
    {
    case '1':
        if (opcionColor == ColorGanador)
        {
            saldo += Apuesta * 2;
            cout << endl;
            cout << "***********************************\n";
            cout << "*** ¡¡¡ FELICIDADES GANASTE !!! ***\n";
            cout << "***********************************\n";

            cout << endl;
            cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
            cout << "El color ganador es: ";
            if (ColorGanador == '1')
            {
                cout << "♦ ROJO ♦\n";
            }
            else if (ColorGanador == '2')
            {
                cout << "♠ NEGRO ♠\n";
            }
            else
            {
                cout << "♣ VERDE ♣\n";
            }
            cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";

            cout << endl;
            cout << "┌──────────────────────────────\n";
            cout << "│ 💵 Lo ganado: " << Apuesta * 2 << endl;
            cout << "└──────────────────────────────\n";
        }
        else
        {
            saldo -= Apuesta;
            cout << endl;
            cout << "El color por el que apostaste no fue le ganador.\n";
            cout << endl;
            cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
            cout << "El color ganador fue: ";
            if (ColorGanador == '1')
            {
                cout << "♦ ROJO ♦" << endl;
            }
            else if (ColorGanador == '2')
            {
                cout << "♠ NEGRO ♠" << endl;
            }
            else
            {
                cout << "♣ VERDE ♣" << endl;
            }
            cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";

        }
        break;
    case '2':
        if (Numero == Numeroganador)
        {
            saldo += Apuesta * 35;
            cout << endl;
            cout << "***********************************\n";
            cout << "*** ¡¡¡ FELICIDADES GANASTE !!! ***\n";
            cout << "***********************************\n";

            cout << endl;
            cout << "══════════════════════\n";
            cout << "     GIRÓ GANADOR...     \n";
            cout << "           " << Numeroganador << endl;
            cout << "══════════════════════\n";

            cout << endl;
            cout << "┌──────────────────────────────\n";
            cout << "│ 💵 Lo ganado: " << Apuesta * 35 << endl;
            cout << "└──────────────────────────────\n";
        }
        else
        {
            saldo -= Apuesta;
            cout << endl;
            cout << "El numero por el que apostaste no fue le ganador.\n";
            cout << endl;
            cout << "══════════════════════\n";
            cout << "     GIRÓ GANADOR...     \n";
            cout << "           " << Numeroganador << endl;
            cout << "══════════════════════\n";
        }
        break;

    default:
        break;
    }
}
void Cargando()
{
    for (int i = 0; i < 6; i++)
    {
    cout << ".";
    Sleep(500);
    }
}
void LimpiarPantalla()
{
    Sleep(1000); // Espera 1 segundo
    system("cls"); // Limpia la consola
}