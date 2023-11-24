#include <iostream>
#include "Menu.h"

using namespace std;

void Menu::mostrarMensajeDeError(TipoError error) {
    switch (error) {
        case TipoError::BRUJA_NO_EXISTE:
            cout << "\nNo existe una bruja con ese identificador." << endl << "\n";
            break;
        case TipoError::SIN_ERROR:
            cout << "\nLa operacion fue un exito." << endl << "\n";
            break;
        case TipoError::BRUJA_YA_EXISTE:
            cout << "\nYa existe una bruja con dicho identificador." << endl << "\n";
            break;
        case TipoError::BRUJA_SUPREMA_YA_EXISTE:
            cout << "\nYa existe una bruja suprema con ese identificador." << endl << "\n";
            break;
        case TipoError::BRUJA_SUPREMA_NO_EXISTE:
            cout << "\nNo existe una bruja suprema con ese identificador." << endl << "\n";
            break;
        case TipoError::BRUJA_COMUN_YA_EXISTE:
            cout << "\nUna bruja comun con ese identificador ya existe." << endl << "\n";
            break;
        case TipoError::BRUJA_NO_ES_SUPREMA:
            cout << "\nLa bruja encontrada con ese identificador no es suprema." << endl << "\n";
            break;
        case TipoError::MAXIMO_HECHIZOS_ALCANZADO:
            cout << "\nNo se pudo agregar el hechizo, el numero maximo fue alcanzado." << endl << "\n";
            break;
        case TipoError::DICCIONARIO_BRUJAS_VACIO:
            cout << "\nNo hay brujas registradas en el aquelarre." << endl << "\n";
            break;
        case TipoError::NO_HAY_HECHIZOS_REGISTRADOS:
            cout << "\nEsa bruja no tiene hechizos registrados." << endl << "\n";
            break;
        case TipoError::HECHIZO_NO_EXISTE:
            cout << "\nNo existe un hechizo con ese numero." << endl << "\n";
            break;
        case TipoError::FECHA_NO_VALIDA:
            cout << "\nLa fecha ingresada no es valida." << endl << "\n";
            break;
        case TipoError::OPCION_NO_VALIDA:
            cout << "\nLa opcion ingresada no es valida." << endl << "\n";
            break;
    }
}

Menu::Menu() {

}
