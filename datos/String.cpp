#include "String.h"
#include <iostream>
#include <cstring>

using namespace std;

///CONSTRUCTOR POR DEFECTO
String::String() {
    cadena = new char[1];
    cadena[0] = '\0';
}

///CONSTRUCTOR COMUN
String::String(const char *cad) {
    int largo = strlen(cad);
    cadena = new char[largo + 1];
    strcpy(cadena, cad);
}

///CONSTRUCTOR DE COPIA
String::String(const String &otro) {
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena, otro.cadena);
}

///DESTRUCTOR
String::~String() {
    delete[] cadena;
}

///OPERADOR DE ASIGNACION
String String::operator=(const String &otro) {
    if (this != &otro) {
        delete[] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char[largo + 1];
        strcpy(cadena, otro.cadena);
    }
    return (*this);
}

/// == OPERADOR DE COMPARACION
bool String::operator==(String otro) {
    return (bool)(strcmp(cadena, otro.cadena) == 0);
}

/// <  COMPARACION ALFABETICA
bool String::operator<(String otro) {
    return (bool)(strcmp(cadena, otro.cadena) < 0);

}

///CONCATENA DOS STRINGS
String String::operator+(String otro) {
    String aux;
    int largo1 = strlen(cadena);
    int largo2 = strlen(otro.cadena);

    aux.cadena = new char[largo1 + largo2 + 1];

    strcpy(aux.cadena, cadena);
    strcat(aux.cadena, otro.cadena);

    return aux;
}

///SCAN LO QUE SE INGRESA POR TECLADO
void String::scan() {
    char aux[MAX];
    char c = cin.get();
    int i = 0;
    while (c != '\n' && i < MAX - 1) {
        aux[i] = c;
        i++;
        c = cin.get();
    }
    aux[i] = '\0';
    cadena = new char[i + 1];
    strcpy(cadena, aux);
}

///IMPRIME POR PANTALLA EL STRING
void String::print() {
    cout << cadena;
}
