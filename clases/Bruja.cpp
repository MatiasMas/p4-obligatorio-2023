#include "Bruja.h"
#include <iostream>

Bruja::Bruja(String ident, String nom) : identificador(ident), nombre(nom) {

}

String Bruja::getIdentificador() {
    return identificador;
}

String Bruja::getNombre() {
    return nombre;
}

void Bruja::insertarHechizo(Hechizo hech) {

}

Iterador Bruja::listarHechizosAprendidos() {
    return Iterador();
}

Bruja::~Bruja() {

}
