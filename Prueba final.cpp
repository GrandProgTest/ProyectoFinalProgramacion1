#include "pch.h"
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <vector>

using namespace System;
using namespace std;

/*------------------------- Structs -------------------------*/
struct jugador {
    int color;
    string nombre;
    char caracter;
    short contMovimientos;
    short cantidadFichas;
    short orden;
    bool ganador;
    int cantidadFichasTablero;
    int indiceMolino;
};

struct posicionFicha {
    int fila;
    int columna;
};

/*------------------------- Muestra -------------------------*/
void muestraInstrucciones() {
    Console::Clear();
    Console::ForegroundColor = ConsoleColor(11);
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "\t\t\t\t  _____           _                       _" << endl;
    cout << "\t\t\t\t  \\_   \\_ __  ___| |_ _ __ _   _  ___ ___(_) ___  _ __   ___  ___ " << endl;
    cout << "\t\t\t\t   / /\\/ '_ \\/ __| __| '__| | | |/ __/ __| |/ _ \\| '_ \\ / _ \\/ __|" << endl;
    cout << "\t\t\t\t/\\/ /_ | | | \\__ \\ |_| |  | |_| | (_| (__| | (_) | | | |  __/\\__ \\" << endl;
    cout << "\t\t\t\t\\____/ |_| |_|___/\\__|_|   \\__,_|\\___\\___|_|\\___/|_| |_|\\___||___/" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    cout << "Se comienza con un tablero vacío. Juegan dos jugadores que reciben cada uno nueve fichas de un color y se turnan para colocarlas en las intersecciones vacías. " << endl;
    cout << "Si un jugador es capaz de formar una fila de tres piezas a lo largo de una de las líneas del tablero, tiene un molino y puede eliminar una de las piezas de su oponente en el tablero; las piezas quitadas no podrán ser colocadas de nuevo. " << endl;
    cout << "Los jugadores deben eliminar cualquier otra pieza antes de eliminar una pieza de un molino formado. " << endl;
    cout << "Una vez que todas las dieciocho piezas se han colocado, los jugadores se turnan moviendo. " << endl;
    char c = _getch();
}

short muestraMenu() {
    Console::SetWindowSize(120, 30);
    short opcion;
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::Yellow;
    cout << endl;
    cout << "\t\t _____ _         _                              _      _                   _ _" << endl;
    cout << "\t\t|  ___| |       (_)                            | |    | |                 | (_)" << endl;
    cout << "\t\t| |__ | |        _ _   _  ___  __ _  ___     __| | ___| |  _ __ ___   ___ | |_ _ __   ___" << endl;
    cout << "\t\t|  __|| |       | | | | |/ _ \\/ _` |/ _ \\   / _` |/ _ \\ | | '_ ` _ \\ / _ \\| | | '_ \\ / _ \\" << endl;
    cout << "\t\t| |___| |____   | | |_| |  __/ (_| | (_) | | (_| |  __/ | | | | | | | (_) | | | | | | (_) |" << endl;
    cout << "\t\t\\____/\\_____/   | |\\__,_|\\___|\\__, |\\___/   \\__,_|\\___|_| |_| |_| |_|\\___/|_|_|_| |_|\\___/" << endl;
    cout << "\t\t               _/ |            __/ |" << endl;
    cout << "\t\t              |__/            |___/" << endl;
    Console::ForegroundColor = ConsoleColor::White;

    Console::ForegroundColor = ConsoleColor::Red;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t                                   _                         _                       " << endl;
    cout << "\t\t      /\\/\\   ___ _ __  _   _    __| | ___    ___  _ __   ___(_) ___  _ __   ___  ___  " << endl;
    cout << "\t\t     /    \\ / _ \\ '_ \\| | | |  / _` |/ _ \\  / _ \\| '_ \\ / __| |/ _ \\| '_ \\ / _ \\/ __|" << endl;
    cout << "\t\t    / /\\/\\ \\  __/ | | | |_| | | (_| |  __/ | (_) | |_) | (__| | (_) | | | |  __/\\__ \\" << endl;
    cout << "\t\t    \\/    \\/\\___|_| |_|\\__,_|  \\__,_|\\___|  \\___/| .__/ \\___|_|\\___/|_| |_|\\___||___/" << endl;
    cout << "\t\t                                                 |_|                                 " << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    cout << "1) Instruccciones" << endl;
    cout << "2) Iniciar juego" << endl;
    cout << "3) Salir" << endl;
    cout << endl;
    cout << "Seleccione una opción: "; cin >> opcion;

    return opcion;
}

void muestraColores() {
    for (int i = 1; i <= 14; i++)
    {
        Console::ForegroundColor = ConsoleColor(i);
        if (i == 7 || i == 8)
            continue;
        cout << "Color " << i << endl;
    }
    Console::ForegroundColor = ConsoleColor(15);
}

void muestraLogo() {

    Console::Clear();

    Console::ForegroundColor = ConsoleColor(12);
    cout <<
        "                      .==                         \n"
        "                    .+##                          \n"
        "         .         +###*                          \n"
        "       -=         *#####                 =-       \n"
        "     :#=         =######=                 =#:     \n"
        "    +#+          ########+.                =#+    \n"
        "   ##          .##########+.               ##.  \n"
        "  ##=          .############+.             =##  \n"
        " +###:           #############:            :###+ \n"
        ":####:           :##############.           :####:\n"
        "+####-            :#############           -####+\n"
        "#####*             .*############.          #####\n"
        "######-              :##########:         -######\n"
        "######:               .########.        :######\n"
        "=#######=                +######+        -#######+\n"
        ".########.               #####*       .########.\n"
        " +#########+:             +###      :+#########= \n"
        "  ##########=.          ##-    .=##########*  \n"
        "   #############=-:..  ==.:-=#############*   \n"
        "    =########################################=    \n"
        "     :####################################:     \n"
        "       :################################:       \n"
        "         .=############################=.         \n"
        "            .=####################=.            \n";

    cout << "\nExigete innova, UPC" << endl;
    cout << endl; cout << endl; cout << endl;

    Console::ForegroundColor = ConsoleColor::White;
    cout << "Hecho por:           " << endl;
    cout << "-Nicole Hidalgo Mossto (u202122634)" << endl;
    cout << "-Paolo César Guillén (u202124343)" << endl;

    cout << "Presione una tecla para continuar:";
    Console::CursorVisible = false;
    char c = _getch();

}

void muestraGanador(struct jugador jugador) {
    Console::Clear();
    Console::SetWindowSize(200, 30);
    Console::ForegroundColor = ConsoleColor::Blue;
    cout << "" << endl;
    cout << "" << endl;
    cout << "                                                                                                                                         ...:::^^^    .^7?JJJYY555PPPPGGGGGGGGGBBBBBBBP~" << endl;
    cout << "                                                                    .....:^.                                    ....:::^^^~!!!77???JJYYY555PPPPGP?!!7J5GGGGGGGGGGGGGGGGGGGGGGGGGGGG#&G^" << endl;
    cout << "                                                            .:::::?:::::.!G:            ...:::^^^^~~!777???JJJJYY55PPPPPPPP5YYYPGGGGGGGGGGPPPPGBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#&J." << endl;
    cout << "                                                            .....:P~.....JP!!!77??????YYYYYYYYYJJPP5?777?5GY~~^^^^~?P!^^:?5::.^GGPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGGGGGGGGGPPB&B~" << endl;
    cout << "                                                :^^^~~!!77??!.....57.....P577!JGY!^:::^?Y::::::..57......:JJ...::...7J...~7...YBPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGP5YJ?JG&5:" << endl;
    cout << "                                         . ...^YJJJYYY55555J....  J~....^B?...7P:..:^...!~~...:!?J...^7...^J...7?...^G~......~BPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGPP5YJ??777Y##7" << endl;
    cout << "                                       .       :5Y?JJJYYYYY5Y: .. 7^ .. 7B?...!? ..!?^~~?G5:..:GG! . ~J ..:? . :^...JBY......5GPPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPP5YJJ?7777777?P&G^" << endl;
    cout << "                                     .         .Y5?JJJJYYYYY5~    ^.    YG?.. ~! . ~PYYYYP5:  .PP~ . ^J . :?       7BPP7    !BP5PPPPPPPPPPPPPPPPPPPPPPPPPP5YJ??777777???JY5#&J" << endl;
    cout << "                                   .            J5????JJJYYYY7         .GP?   ~7   ~7   ^G5:  .PP7   :7   ~J   ::  .YP5Y.   YG55555555PPPPPPPPPPPPPP5YYJ?7777???JYY55PPPGB&B~" << endl;
    cout << "                                 .              !Y?7??JJJJJYY?         ~B5?   ^5   .:   JGY.   5PY~      :PJ ..!?   ^P55^:::5P55555555555PPPPP55YJ??77??JJY55PPPPPPPPPPG#&5." << endl;
    cout << "                          .....77               ~5?77??JJJJJJJ.        ?GY?   ^G?^:..:~YB5Y~~!!P5YY?777?YPPYY55P5JY55P55Y5PPP5555555555555YYJ???JJYY55PPPPPPPPPPPPPPPPG&#7" << endl;
    cout << "                    .....!^....::^?!..:!........~GY7777???JJJJ~:       PPYJ?YY5PYJ??????77?J5555YYYY55555YYYYYYYYYYYYYYYYYY5Y5555555YYYJJJYYY555PPPPPPPPPPPPPPPPPPPPPB&P^" << endl;
    cout << "                   .::::.:.....  7#Y!7PP:.......^BP???????????JJ55555555YJJYYYJY!:::.......:~JYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5555YYYYYYYYYY5555555555555PPPPPPPPPPPG#&J" << endl;
    cout << "                  .:::::::.....^YPB5JJJ?^.......:GB???JJJJJJJJJ???JJJJJJJJJJJJJJ~.....^:.....^5JYYJJJYYYYYYJYYJ???JY?77777YY?!!!?55Y~^^^::^5555555555555555PPPPPPPB&B~" << endl;
    cout << "                   :^^:::~5:::.~B5JJJJJJ~::::::::5#J?JJJJJJJJJJJJJJJJJJJJJJJJJJJ~.....5?......P57~^^^~7J7^^^~Y^:::5Y:.....Y5!...7GYJ.....^!G555555555555555555P5P#&Y." << endl;
    cout << "                    ^~^^:^Y^:::::.YBYJJJ7::::::::J&Y?JJJJJJJJJJJJJJJJJJJJJJJJJJJ~.....PJ ... :G!...:...!J...:J...?BJ......?P!...?GYJ...:??5P5555555555555555555G&#!" << endl;
    cout << "                   ::^^^^^:::::::.Y@5JYY?^^^^^^^:7@PJJJJJJJJJ??????????????????J~ ....!:....:55...:J...:P!...:..^GP~..::. ^G! . 7GYJ....  ?PY5555555555555555PB&P:" << endl;
    cout << "                   :~^^^^^^^^^^:7GB&PYYYJ^^^^^^^^!&BJJJJJJJJJ??????????????????J^          ~GG7 ..:J....PY: ... JBJ:  ^~  .P7   7BYJ.  .7?5GY555555555555555P##?" << endl;
    cout << "                   ^!!^^^^7J^^^^?@GJJ????~^^^^^^^^#&JJJJJJJJ????????????????????^    .:    .YJ~   :J   .P5!    ^G57.       ??   :!^!.   ::~5YYYY55555555555G&G~" << endl;
    cout << "                 ^?5P5~7YYPB?YGBB#P?JJYYY!^^^^^^^^G@YJJJJJJJJ???????????????????^     J.    :57   .!   ~BY?:   ?BJ~   ^~   :?      !:.....~G5YYYY55555555P#&Y." << endl;
    cout << "               :?YYJJ??YP5YYJY5YYYYYYYYYY!^~!?J5PG#&YJJJJJJJ????????????????????:     57     ~Y~.    .~PG??^...JG?!!??PP^!7?5?YYY55P55PPPPPPYYYYYYYY5555G&B!" << endl;
    cout << "             :!777777???JYY55555555YYYYYYJJB#BBGP5YJJJJJJJJJ????????????????????!!JJJJGY:~!77?PY7??JY5G5???7?555Y??JYYYJJ5555YYY555555PPPPPPGGGGBBBBBBB#&P:" << endl;
    cout << "           :!7??JY55555555555555555YYYYYYYYYYJJJJJJJJJJY55J????????????????????7??JJJJ???Y5YYYJJ?JYYYYYYYY5555PPPPGGGGGBBBBBBBBBGGGGGPPP55YYJJ??777!!~~^^" << endl;
    cout << "          :^7PBBBGPPP55555555555555YYYYYYYYYYJJJJJY5PB##PJ?????????JJJJJJYYYYY5555PPPPGGGGGGGBBBBBGGGGGPPP555YYJJ??77!!~~~^^:::...." << endl;
    cout << "           ^77J5P555555555555555555555555555555PG##BPJ!~~YGGBBBBBBBBBGGGGGPPP55YYJJ???77!!~~^^^:::..." << endl;
    cout << "           :7JPGGGGGGGBBBBBBBBBBBBBBBBBBBGGGPPPPY7^.    :!!!~~^^^:::...." << endl;
    cout << "" << endl;
    char c = _getch();
    Console::Clear();
    Console::SetWindowSize(100, 25);
    Console::ForegroundColor = ConsoleColor::Yellow;
    cout << "\t  _______      ___      .__   __.      ___           _______.___________. _______    " << endl;
    cout << "\t /  _____|    /   \\     |  \\ |  |     /   \\         /       |           ||   ____|   " << endl;
    cout << "\t|  |  __     /  ^  \\    |   \\|  |    /  ^  \\       |   (----`---|  |----`|  |__      " << endl;
    cout << "\t|  | |_ |   /  /_\\  \\   |  . `  |   /  /_\\  \\       \\   \\       |  |     |   __|     " << endl;
    cout << "\t|  |__| |  /  _____  \\  |  |\\   |  /  _____  \\  .----)   |      |  |     |  |____    " << endl;
    cout << "\t \\______| /__/     \\__\\ |__| \\__| /__/     \\__\\ |_______/       |__|     |_______|   " << endl;
    cout << endl;
    cout << "______________________________________________________________________________________________________________" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    Console::ForegroundColor = ConsoleColor(jugador.color);
    cout << "\t\t\t\t     ,--------------------------." << endl;
    cout << "\t\t\t\t    /                            \\" << endl;
    cout << "\t\t\t\t    |                            |" << endl;
    cout << "\t\t\t\t    |                            |" << endl;
    cout << "\t\t\t\t    |                            |" << endl;
    cout << "\t\t\t\t    \\                            /" << endl;
    cout << "\t\t\t\t     `--------------------------'" << endl;
    Console::SetCursorPosition(48, 14);
    Console::ForegroundColor = ConsoleColor::White;
    cout << jugador.nombre;

    char u = _getch();

}

void muestraTablero(char** matriz, struct jugador jugadorA, struct jugador jugadorB) {
    Console::Clear();
    Console::ForegroundColor = ConsoleColor(jugadorA.color);
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t         Turno de " << jugadorA.nombre << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(20, 3);
    cout << jugadorA.nombre << endl;
    Console::SetCursorPosition(20, 4);
    cout << "Movimientos: " << jugadorA.contMovimientos << endl;
    Console::SetCursorPosition(20, 5);
    cout << "Cantidad de fichas : " << jugadorA.cantidadFichas << endl;

    cout << endl;
    Console::SetCursorPosition(83, 3);
    cout << jugadorB.nombre << endl;
    Console::SetCursorPosition(83, 4);
    cout << "Movimientos: " << jugadorB.contMovimientos << endl;
    Console::SetCursorPosition(83, 5);
    cout << "Cantidad de fichas: " << jugadorB.cantidadFichas << endl;
    Console::SetCursorPosition(0, 6);

    cout << endl;
    cout << "        \t\t\t\t\t    ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::BackgroundColor = ConsoleColor::Yellow;
    cout << "                    1 1 1" << endl;
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Black;
    cout << "        \t\t\t\t\t    ";
    Console::ForegroundColor = ConsoleColor::Black;
    Console::BackgroundColor = ConsoleColor::Yellow;
    cout << "0 1 2 3 4 5 6 7 8 9 0 1 2" << endl;
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Black;
    cout << endl;

    for (int i = 0; i < 13; i++)
    {
        cout << "        \t\t\t\t\t";
        Console::ForegroundColor = ConsoleColor::Black;
        Console::BackgroundColor = ConsoleColor::Yellow;

        if (i < 10) {
            cout << i << " ";
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::BackgroundColor = ConsoleColor::Black;
            cout << "  ";
        }

        else {
            cout << i;
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::BackgroundColor = ConsoleColor::Black;
            cout << "  ";
        }

        for (int k = 0; k < 13; k++)
        {
            if (matriz[i][k] == jugadorA.caracter)
            {
                Console::ForegroundColor = ConsoleColor(jugadorA.color);
                cout << matriz[i][k] << " ";
            }
            else if (matriz[i][k] == jugadorB.caracter) {
                Console::ForegroundColor = ConsoleColor(jugadorB.color);
                cout << matriz[i][k] << " ";
            }
            else {
                Console::ForegroundColor = ConsoleColor(8);
                cout << matriz[i][k] << " ";
            }

        }
        Console::ForegroundColor = ConsoleColor(15);
        cout << endl;
    }
}

/*------------------------- Verifica -------------------------*/
bool verificaIndiceRepetido(int ind, vector <int >* indices) {
    bool resp = false;
    for (size_t k = 0; k < indices->size(); k++) {
        if (ind == indices->at(k))
            resp = true;
    }
    return resp;
}

bool verificaMolino(struct jugador* jugador, char** matriz, vector <int >* indices) {
    bool respuesta = false;
    int indice;
    int molinos[20][6] = {
        {0,0,0,6,0,12},
        {2,2,2,6,2,10},
        {4,4,4,6,4,8},
        {8,4,8,6,8,8},
        {10,2,10,6,10,10},
        {12,0,12,6,12,12},
        {0,0,6,0,12,0},
        {2,2,6,2,10,2},
        {4,4,6,4,8,4},
        {4,8,6,8,8,8},
        {2,10,6,10,10,10},
        {0,12,6,12,12,12},
        {6,0,6,2,6,4},
        {6,8,6,10,6,12},
        {0,6,2,6,4,6},
        {8,6,10,6,12,6},
        {0,0,2,2,4,4},
        {4,8,2,10,0,12},
        {8,8,10,10,12,12},
        {8,4,10,2,12,0},
    };

    for (int i = 0; i < 20; i++)
    {

        if (matriz[molinos[i][0]][molinos[i][1]] == jugador->caracter
            && matriz[molinos[i][2]][molinos[i][3]] == jugador->caracter
            && matriz[molinos[i][4]][molinos[i][5]] == jugador->caracter)
        {
            if (indices->size() == 0)
            {
                respuesta = true;
                indices->push_back(i);
            }
            else
            {
                if (!verificaIndiceRepetido(i, indices)) {
                    respuesta = true;
                    indices->push_back(i);
                }
            }
        }
    }
    return respuesta;
}

bool verificaLibreDerecha(struct posicionFicha posicionA, struct posicionFicha* posicionB,
    char** matriz, struct jugador jugadorA, struct jugador jugadorB) {
    bool respuesta = false;

    for (int i = posicionA.columna + 1; i < 13; i++)
    {
        if (posicionA.columna == 4 && posicionA.fila == 6) {
            respuesta = false;
            break;
        }
        else
        {
            if (matriz[posicionA.fila][i] == 'o') {
                respuesta = true;
                posicionB->fila = posicionA.fila;
                posicionB->columna = i;
                break;
            }

            if (matriz[posicionA.fila][i] == jugadorA.caracter) {
                respuesta = false;
                break;
            }

            if (matriz[posicionA.fila][i] == jugadorB.caracter) {
                respuesta = false;
                break;
            }
        }

    }
    return respuesta;
}

bool verificaLibreIzquierda(struct posicionFicha posicionA, struct posicionFicha* posicionB,
    char** matriz, struct jugador jugadorA, struct jugador jugadorB) {
    bool respuesta = false;
    for (int i = posicionA.columna - 1; i >= 0; i--)
    {
        if (posicionA.columna == 8 && posicionA.fila == 6) {
            respuesta = false;
            break;
        }
        else {
            if (matriz[posicionA.fila][i] == 'o') {
                posicionB->fila = posicionA.fila;
                posicionB->columna = i;
                respuesta = true;
                break;
            }

            if (matriz[posicionA.fila][i] == jugadorA.caracter) {
                respuesta = false;
                break;
            }

            if (matriz[posicionA.fila][i] == jugadorB.caracter) {
                respuesta = false;
                break;
            }
        }
    }
    return respuesta;

}

bool verificaLibreArriba(struct posicionFicha posicionA, struct posicionFicha* posicionB,
    char** matriz, struct jugador jugadorA, struct jugador jugadorB) {
    bool respuesta = false;
    for (int i = posicionA.fila - 1; i >= 0; i--)
    {
        if (posicionA.fila == 8 && posicionA.columna == 6) {
            respuesta = false;
            break;
        }
        else {
            if (matriz[i][posicionA.columna] == 'o') {
                posicionB->fila = i;
                posicionB->columna = posicionA.columna;
                respuesta = true;
                break;
            }

            if (matriz[i][posicionA.columna] == jugadorA.caracter) {
                respuesta = false;
                break;
            }

            if (matriz[i][posicionA.columna] == jugadorB.caracter) {
                respuesta = false;
                break;
            }

        }

    }
    return respuesta;
}

bool verificaLibreAbajo(struct posicionFicha posicionA, struct posicionFicha* posicionB,
    char** matriz, struct jugador jugadorA, struct jugador jugadorB) {
    bool respuesta = false;
    for (int i = posicionA.fila + 1; i <= 12; i++)
    {
        if (posicionA.fila == 4 && posicionA.columna == 6)
        {
            respuesta = false;
            break;
        }
        else
        {
            if (matriz[i][posicionA.columna] == 'o') {
                posicionB->fila = i;
                posicionB->columna = posicionA.columna;
                respuesta = true;
                break;
            }

            if (matriz[i][posicionA.columna] == jugadorA.caracter) {
                respuesta = false;
                break;
            }


            if (matriz[i][posicionA.columna] == jugadorB.caracter) {
                respuesta = false;
                break;
            }
        }

    }
    return respuesta;
}

bool verificaMovimiento(struct posicionFicha posicionA, struct posicionFicha* posicionB,
    char** matriz, struct jugador jugadorA, struct jugador jugadorB, short direccion)
{
    bool respuesta = false;
    if (direccion == 1 || direccion == 2)
    {
        if (posicionA.fila == 0) {
            if (direccion == 2)
                respuesta = verificaLibreAbajo(posicionA, posicionB, matriz, jugadorA, jugadorB);
            if (direccion == 1)
                respuesta = false;
        }

        if (posicionA.fila == 12) {
            if (direccion == 1)
                respuesta = verificaLibreArriba(posicionA, posicionB, matriz, jugadorA, jugadorB);
            if (direccion == 2)
                respuesta = false;
        }
        else
        {
            if (direccion == 1)
                respuesta = verificaLibreArriba(posicionA, posicionB, matriz, jugadorA, jugadorB);
            if (direccion == 2)
                respuesta = verificaLibreAbajo(posicionA, posicionB, matriz, jugadorA, jugadorB);
        }
    }

    if (direccion == 3 || direccion == 4)
    {
        if (posicionA.columna == 0) {
            if (direccion == 4)
                respuesta = verificaLibreDerecha(posicionA, posicionB, matriz, jugadorA, jugadorB);
            if (direccion == 3)
                respuesta = false;
        }
        else if (posicionA.columna == 12) {
            if (direccion == 3)
                respuesta = verificaLibreIzquierda(posicionA, posicionB, matriz, jugadorA, jugadorB);
            if (direccion == 4)
                respuesta = false;
        }
        else {
            if (direccion == 4)
                respuesta = verificaLibreDerecha(posicionA, posicionB, matriz, jugadorA, jugadorB);
            if (direccion == 3)
                respuesta = verificaLibreIzquierda(posicionA, posicionB, matriz, jugadorA, jugadorB);
        }
    }
    return respuesta;
}

bool verificaMovilidad(char** matriz, struct jugador* jugadorA, struct jugador* jugadorB) {
    bool respuesta = true;
    int contadorFalsos = 0;
    struct posicionFicha posicionA;
    struct posicionFicha posicionB;
    int posiciones[24][2] = {
        {0,0},
        {0,6},
        {0,12},
        {2,2},
        {2,6},
        {2,10},
        {4,4},
        {4,6},
        {4,8},
        {6,0},
        {6,2},
        {6,4},
        {6,8},
        {6,10},
        {6,12},
        {8,4},
        {8,6},
        {8,8},
        {10,2},
        {10,6},
        {10,10},
        {12,0},
        {12,6},
        {12,12},
    };
    for (int i = 0; i < 24; i++)
    {
        if (jugadorA->caracter == matriz[posiciones[i][0]][posiciones[i][1]]) {
            posicionA.fila = posiciones[i][0];
            posicionA.columna = posiciones[i][1];
            if (verificaMovimiento(posicionA, &posicionB, matriz, *jugadorA, *jugadorB, 1) == false &&
                verificaMovimiento(posicionA, &posicionB, matriz, *jugadorA, *jugadorB, 2) == false &&
                verificaMovimiento(posicionA, &posicionB, matriz, *jugadorA, *jugadorB, 3) == false &&
                verificaMovimiento(posicionA, &posicionB, matriz, *jugadorA, *jugadorB, 4) == false)
            {
                contadorFalsos++;
            }
        }
    }

    if (contadorFalsos == jugadorA->cantidadFichasTablero)
        respuesta = false;
    return respuesta;
}

bool verificaFin(char** matriz, struct jugador* jugador1, struct jugador* jugador2) {
    bool respuesta = false;
    if (jugador1->cantidadFichas == 2 || verificaMovilidad(matriz, jugador1, jugador2) == false) {
        jugador2->ganador = true;
        respuesta = true;
    }

    if (jugador2->cantidadFichas == 2 || verificaMovilidad(matriz, jugador2, jugador1) == false) {
        jugador1->ganador = true;
        respuesta = true;
    }

    if (jugador1->cantidadFichasTablero == 0)
        respuesta = false;

    if (jugador2->cantidadFichasTablero == 0)
        respuesta = false;

    return respuesta;
};


/*------------------------- Matriz -------------------------*/

void mueveFicha(struct posicionFicha* posicionB, char** matriz, struct jugador* jugadorA, struct jugador* jugadorB) {
    Console::Clear();
    int direccion;
    struct posicionFicha posicionA;
    muestraTablero(matriz, *jugadorA, *jugadorB);
    do {
        cout << "\t\t\t\t\t      Seleccione la ficha a mover: " << endl;
        do
        {
            cout << "\t\t\t\t\t\t      Índice de la fila: ";
            cin >> posicionA.fila;
        } while (posicionA.fila < 0 || posicionA.fila>12);

        do
        {
            cout << "\t\t\t\t\t\t      Índice de la columna: ";
            cin >> posicionA.columna;
        } while (posicionA.columna < 0 || posicionA.columna>12);

    } while (matriz[posicionA.fila][posicionA.columna] != jugadorA->caracter ||
        (verificaMovimiento(posicionA, posicionB, matriz, *jugadorA, *jugadorB, 1) == false &&
            verificaMovimiento(posicionA, posicionB, matriz, *jugadorA, *jugadorB, 2) == false &&
            verificaMovimiento(posicionA, posicionB, matriz, *jugadorA, *jugadorB, 3) == false &&
            verificaMovimiento(posicionA, posicionB, matriz, *jugadorA, *jugadorB, 4) == false));
    cout << "Seleccione la dirección" << endl;

    do
    {
        cout << "1: Arriba" << endl;
        cout << "2: Abajo" << endl;
        cout << "3: Izquierda" << endl;
        cout << "4: Derecha" << endl;
        cout << "Opción: ";
        cin >> direccion;
    } while (direccion < 1 || direccion > 4 || verificaMovimiento(posicionA, posicionB, matriz, *jugadorA, *jugadorB, direccion) == false);
    cout << "El movimiento es válido" << endl;

    char c = _getch();
    jugadorA->contMovimientos++;
    matriz[posicionA.fila][posicionA.columna] = 'o';
    matriz[posicionB->fila][posicionB->columna] = jugadorA->caracter;
}

void mueveFichaVuelo(struct posicionFicha* posicionB, char** matriz, struct jugador* jugadorA, struct jugador* jugadorB) {
    Console::Clear();
    int direccion;
    struct posicionFicha posicionA;
    muestraTablero(matriz, *jugadorA, *jugadorB);
    do {
        cout << "\t\t\t\t\t      Seleccione la ficha a mover: " << endl;
        do
        {
            cout << "\t\t\t\t\t\t      Índice de la fila: ";
            cin >> posicionA.fila;
        } while (posicionA.fila < 0 || posicionA.fila>12);

        do
        {
            cout << "\t\t\t\t\t\t      Índice de la columna: ";
            cin >> posicionA.columna;
        } while (posicionA.columna < 0 || posicionA.columna>12);

    } while (matriz[posicionA.fila][posicionA.columna] != jugadorA->caracter);

    do {
        cout << endl;
        cout << "\t\t\t\t\t      Ingrese los índices de la posición: " << endl;
        do
        {
            cout << "\t\t\t\t\t\t      Índice de la fila: ";
            cin >> posicionB->fila;
        } while (posicionB->fila < 0 || posicionB->fila>12);

        do
        {
            cout << "\t\t\t\t\t\t      Índice de la columna: ";
            cin >> posicionB->columna;
        } while (posicionB->columna < 0 || posicionB->columna>12);

    } while (matriz[posicionB->fila][posicionB->columna] != 'o');


    jugadorA->contMovimientos++;
    matriz[posicionA.fila][posicionA.columna] = 'o';
    matriz[posicionB->fila][posicionB->columna] = jugadorA->caracter;
}

void llenaMatriz(char** matriz) {
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if ((j % 2 == 0) && j != 6 && ((i > j && i < 12 - j) || (i > 12 - j && i < j)))
                matriz[i][j] = 124;
            else if ((i % 2 == 0) && i != 6 && ((j > i && j < 12 - i) || (j > 12 - i && j < i)))
                matriz[i][j] = '-';
            else if (i == 6 && ((j > 0 && j < 4) || (j > 8 && j < 12)))
                matriz[i][j] = '-';
            else if (j == 6 && ((i > 0 && i < 4) || (i > 8 && i < 12)))
                matriz[i][j] = 124;
            else
                matriz[i][j] = ' ';

            if ((i == 6 || j == 6) && j % 2 == 0 && i % 2 == 0 && i != j)
                matriz[i][j] = 'o';
            else if ((i == j || j == 12 - i) && i % 2 == 0 && i != 6 && j != 6)
                matriz[i][j] = 'o';
        }
    }
}

void colocaFicha(char** matriz, struct jugador* jugadorA, struct jugador* jugadorB) {
    struct posicionFicha posicion;
    muestraTablero(matriz, *jugadorA, *jugadorB);

    do {
        cout << endl;
        cout << "\t\t\t\t\t      Ingrese los índices de la posición: " << endl;
        do
        {
            cout << "\t\t\t\t\t\t      Índice de la fila: ";
            cin >> posicion.fila;
        } while (posicion.fila < 0 || posicion.fila>12);

        do
        {
            cout << "\t\t\t\t\t\t      Índice de la columna: ";
            cin >> posicion.columna;
        } while (posicion.columna < 0 || posicion.columna>12);

    } while (matriz[posicion.fila][posicion.columna] != 'o');

    matriz[posicion.fila][posicion.columna] = jugadorA->caracter;
    jugadorA->contMovimientos++;
    jugadorA->cantidadFichasTablero++;
}

void capturaFicha(char** matriz, struct jugador* jugadorA, struct jugador* jugadorB) {
    Console::Clear();
    struct posicionFicha posicion;
    muestraTablero(matriz, *jugadorA, *jugadorB);
    do {
        cout << endl;
        cout << "\t\t\t\t\t      Seleccione la ficha a capturar: " << endl;
        do
        {
            cout << "\t\t\t\t\t\t      Índice de la fila: ";
            cin >> posicion.fila;
        } while (posicion.fila < 0 || posicion.fila>12);

        do
        {
            cout << "\t\t\t\t\t\t      Índice de la columna: ";
            cin >> posicion.columna;
        } while (posicion.columna < 0 || posicion.columna>12);

    } while (matriz[posicion.fila][posicion.columna] != jugadorB->caracter);
    matriz[posicion.fila][posicion.columna] = 'o';
    jugadorB->cantidadFichas--;
    jugadorB->cantidadFichasTablero--;
}




/*------------------------- Jugadores -------------------------*/

void registrarJugador(struct jugador* jugadorA, struct jugador* jugadorB) {
    Console::Clear();
    cout << "\n\t\t\t\t\t\t\tRegistro del jugador" << endl;
    cout << "Ingrese el nombre: ";
    cin >> jugadorA->nombre;

    do
    {
        cout << "Ingrese el caracter: ";
        cin >> jugadorA->caracter;
    } while (jugadorA->caracter == 'o' || jugadorA->caracter == '-' || jugadorA->caracter == jugadorB->caracter);

    do
    {
        cout << "Ingrese el color: " << endl;
        muestraColores();
        cin >> jugadorA->color;
    } while (jugadorA->color < 1 || jugadorA->color > 14 ||
        jugadorA->color == 7 || jugadorA->color == 8 || jugadorA->color == jugadorB->color);


}

void determinarOrden(struct jugador* jugadorA, struct jugador* jugadorB) {
    int x = 0;
    char a = ' ';
    string nombre = "";

    srand(time(NULL));
    Console::Clear();
    jugadorA->orden = 1 + rand() % (2 + 1 - 1);
    if (jugadorA->orden == 1)
        jugadorB->orden = 2;

    if (jugadorA->orden == 2)
        jugadorB->orden = 1;

    if (jugadorB->orden == 1) {
        x = jugadorA->color;
        jugadorA->color = jugadorB->color;
        jugadorB->color = x;

        nombre = jugadorA->nombre;
        jugadorA->nombre = jugadorB->nombre;
        jugadorB->nombre = nombre;


        a = jugadorA->caracter;
        jugadorA->caracter = jugadorB->caracter;
        jugadorB->caracter = a;
    }

    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t      Orden" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "¡" << jugadorA->nombre << " comenzará el juego!";
    char c = _getch();
}


/*------------------------- Juego -------------------------*/
void Procesar_Fin()
{
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::Red;
    Console::BackgroundColor = ConsoleColor::Yellow;
    cout << "Gracias por Jugar...";

    Console::CursorVisible = false;
}

void IniciaJuego()
{
    vector <int> indices;
    //declaracion de variables
    struct jugador jugador1;
    struct jugador jugador2;

    struct posicionFicha posicionB;

    short direccion;

    jugador1.contMovimientos = 0;
    jugador2.contMovimientos = 0;

    jugador1.cantidadFichas = 9;
    jugador2.cantidadFichas = 9;

    jugador1.cantidadFichasTablero = 0;
    jugador2.cantidadFichasTablero = 0;

    jugador2.caracter = '-';
    jugador2.color = -1;

    char** matriz;
    matriz = new char* [13];

    for (int i = 0; i < 13; i++)
        matriz[i] = new char[13];

    llenaMatriz(matriz);

    registrarJugador(&jugador1, &jugador2);
    registrarJugador(&jugador2, &jugador1);

    determinarOrden(&jugador1, &jugador2);

    do
    {
        //Inicio de la fase 1

        for (int i = 0; i < 9; i++)
        {
            colocaFicha(matriz, &jugador1, &jugador2);

            if (verificaMolino(&jugador1, matriz, &indices)) {
                cout << "¡" << jugador1.nombre << " formó un molino!" << endl;
                char c = _getch();
                capturaFicha(matriz, &jugador1, &jugador2);
            }

            colocaFicha(matriz, &jugador2, &jugador1);
            if (verificaMolino(&jugador2, matriz, &indices)) {
                cout << "¡" << jugador2.nombre << " formó un molino!" << endl;
                char c = _getch();
                capturaFicha(matriz, &jugador2, &jugador1);
            }

        }

        if (verificaFin(matriz, &jugador1, &jugador2))
            break;

        //Inicio de la fase 2
        do
        {
            Console::Clear();

            if (jugador1.cantidadFichas > 3)
            {
                mueveFicha(&posicionB, matriz, &jugador1, &jugador2);
                if (verificaMolino(&jugador1, matriz, &indices)) {
                    cout << "¡" << jugador1.nombre << " formó un molino!" << endl;
                    char c = _getch();
                    capturaFicha(matriz, &jugador1, &jugador2);
                }
            }
            else
            {
                mueveFichaVuelo(&posicionB, matriz, &jugador1, &jugador2);
                if (verificaMolino(&jugador1, matriz, &indices)) {
                    cout << "¡" << jugador1.nombre << " formó un molino!" << endl;
                    char c = _getch();
                    capturaFicha(matriz, &jugador1, &jugador2);
                }
            }

            if (verificaFin(matriz, &jugador1, &jugador2))
                break;

            if (jugador2.cantidadFichas > 3) {
                mueveFicha(&posicionB, matriz, &jugador2, &jugador1);
                if (verificaMolino(&jugador2, matriz, &indices)) {
                    cout << "¡" << jugador2.nombre << " formó un molino!" << endl;
                    char c = _getch();
                    capturaFicha(matriz, &jugador2, &jugador1);
                }
            }
            else
            {
                mueveFichaVuelo(&posicionB, matriz, &jugador2, &jugador1);
                if (verificaMolino(&jugador1, matriz, &indices)) {
                    cout << "¡" << jugador1.nombre << " formó un molino!" << endl;
                    char c = _getch();
                    capturaFicha(matriz, &jugador1, &jugador2);
                }
            }

            if (verificaFin(matriz, &jugador1, &jugador2))
                break;

        } while (true);

        if (verificaFin(matriz, &jugador1, &jugador2))
            break;
    } while (true);

    if (jugador1.ganador == true)
        muestraGanador(jugador1);

    if (jugador2.ganador == true)
        muestraGanador(jugador2);

    for (int i = 0; i < 13; i++) {
        delete[] matriz[i];
    }

    delete[] matriz;
}

void ProcesarOpcion(short opc)
{
    Console::Clear();
    switch (opc)
    {
    case 1: muestraInstrucciones();
        break;
    case 2: IniciaJuego();
        break;
    case 3: Procesar_Fin();
        break;
    default:
        cout << "Ingresar Opción válida";
    }
}

/*------------------------- Main-------------------------*/

int main()
{
    setlocale(LC_ALL, "spanish");

    //Declaracion de variables

    short opc;


    //Inicio del programa
    muestraLogo();
    do {
        opc = muestraMenu();
        ProcesarOpcion(opc);
    } while (opc != 3);


    char g = _getch();
    return 0;
}
