#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{

    srand(time(0));

    // simbolos y sus nombres
    string simbolos[7] = {"C", "L", "N", "B", "E", "D", "7"};
    string nombres[7] = {"Cereza", "Limon", "Naranja", "Campana", "Estrella", "Diamante", "Siete"};

    int rodillos[4];

    float saldo = 600;
    int apuesta = 10;
    int premio = 0;
    int multi = 0;
    char continuar = 'Y'; // si quiere jugar
    int i;

    // menu
    cout << "+==============================+" << endl;
    cout << "|   TRAGAMONEDAS 7777          |" << endl;
    cout << "|  Apuesta por giro: " << apuesta << " cred   |" << endl;
    cout << "+==============================+" << endl;
    cout << "|         Tabla de pagos       |" << endl;
    cout << "| 4x Siete    (7) ->  x100 apu |" << endl;
    cout << "| 4x Diamante (D) ->  x75  apu |" << endl;
    cout << "| 4x Estrella (E) ->  x50  apu |" << endl;
    cout << "| 4x Campana  (B) ->  x30  apu |" << endl;
    cout << "| 4x Naranja  (N) ->  x20  apu |" << endl;
    cout << "| 4x Limon    (L) ->  x15  apu |" << endl;
    cout << "| 4x Cereza   (C) ->  x10  apu |" << endl;
    cout << "| 3 iguales       ->  x5   apu |" << endl;
    cout << "| 2 iguales       ->  x2   apu |" << endl;
    cout << "+==============================+" << endl;
    cout << "Creditos: " << saldo << endl;

    while (saldo >= apuesta && (continuar == 'Y' || continuar == 'y'))
    {

        cout << endl;
        cout << "Creditos: " << saldo << endl;
        cout << "Quieres jugar? (Y = si, N = no): ";
        cin >> continuar;

        if (continuar == 'Y' || continuar == 'y')
        {

            saldo = saldo - apuesta;

            // saco los 4 numeros
            for (i = 0; i < 4; i++)
            {
                rodillos[i] = rand() % 7;
            }

            // muestro los rodillos
            cout << "[ ";
            for (i = 0; i < 4; i++)
            {
                cout << simbolos[rodillos[i]] << " ";
            }
            cout << "]" << endl;

            premio = 0;
            multi = 0;

            // hay que  ver si los 4 son iguales
            if (rodillos[0] == rodillos[1] && rodillos[1] == rodillos[2] && rodillos[2] == rodillos[3])
            {

                // el multiplicador depende del simbolo
                switch (rodillos[0])
                {
                case 0:
                    multi = 10;
                    break;
                case 1:
                    multi = 15;
                    break;
                case 2:
                    multi = 20;
                    break;
                case 3:
                    multi = 30;
                    break;
                case 4:
                    multi = 50;
                    break;
                case 5:
                    multi = 75;
                    break;
                case 6:
                    multi = 100;
                    break;
                }
                premio = apuesta * multi;
                cout << "GANASTE!! 4 " << nombres[rodillos[0]] << " iguales" << endl;
            }
            // hay que  ver si hay 3 iguales (varios casos) puta madre
            else if (rodillos[0] == rodillos[1] && rodillos[1] == rodillos[2])
            {
                premio = apuesta * 5;
                cout << "3 iguales" << endl;
            }
            else if (rodillos[1] == rodillos[2] && rodillos[2] == rodillos[3])
            {
                premio = apuesta * 5;
                cout << "3 iguales" << endl;
            }
            else if (rodillos[0] == rodillos[1] && rodillos[1] == rodillos[3])
            {
                premio = apuesta * 5;
                cout << "3 iguales" << endl;
            }
            else if (rodillos[0] == rodillos[2] && rodillos[2] == rodillos[3])
            {
                premio = apuesta * 5;
                cout << "3 iguales" << endl;
            }
            // hay que  ver si hay 2 iguales (todos los pares posibles)
            else if (rodillos[0] == rodillos[1])
            {
                premio = apuesta * 2;
                cout << "2 iguales" << endl;
            }
            else if (rodillos[1] == rodillos[2])
            {
                premio = apuesta * 2;
                cout << "2 iguales" << endl;
            }
            else if (rodillos[2] == rodillos[3])
            {
                premio = apuesta * 2;
                cout << "2 iguales" << endl;
            }
            else if (rodillos[0] == rodillos[2])
            {
                premio = apuesta * 2;
                cout << "2 iguales" << endl;
            }
            else if (rodillos[0] == rodillos[3])
            {
                premio = apuesta * 2;
                cout << "2 iguales" << endl;
            }
            else if (rodillos[1] == rodillos[3])
            {
                premio = apuesta * 2;
                cout << "2 iguales" << endl;
            }
            else
            {
                premio = 0;
                cout << "No ganaste nada" << endl;
            }

            saldo = saldo + premio;
            cout << "Premio: " << premio << endl;
            cout << "Te quedan: " << saldo << endl;
        }
    }

    cout << endl;
    cout << "============================" << endl;
    if (saldo < apuesta)
    {
        cout << "Te quedaste sin saldo" << endl;
    }
    else
    {
        cout << "Saliste del juego" << endl;
    }
    cout << "Creditos finales: " << saldo << endl;
    cout << "============================" << endl;

    return 0;
}
