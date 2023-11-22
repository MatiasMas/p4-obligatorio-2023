#include "Bruja.h"
#include <iostream>

Bruja::Bruja(String ident, String nom) : identificador(ident), nombre(nom), hechizosAprendidos() {
}

String Bruja::getIdentificador() {
    return identificador;
}

String Bruja::getNombre() {
    return nombre;
}

void Bruja::setNombre(String nom) {
    nombre = nom;
}

void Bruja::insertarHechizo(Hechizo *hech) {
    hechizosAprendidos.insBack(hech);
}

Iterador *Bruja::listarHechizosAprendidos() {
    Iterador *iterador = hechizosAprendidos.listarHechizos();

    return iterador;
}

String Bruja::generarStringHechizos() {
    String hechizos, result;

    Iterador *iterador = hechizosAprendidos.listarHechizos();

    while (iterador->hayMasObjetos()) {
        String *objActual = iterador->proximoObjeto();

        hechizos = hechizos + "{" + *objActual + "}";
    }

    result = result + "[ " + hechizos + " ]";

    return result;
}

String Bruja::generarString() {
    String datos;
    String tipoBruja;

    switch (getTipo()) {
        case TipoBruja::SUPREMA:
            tipoBruja = "Suprema";
            break;
        case TipoBruja::COMUN:
            tipoBruja = "Comun";
            break;
    }

    datos = datos + "Tipo Bruja: " + tipoBruja + ", Identificador: " + getIdentificador() + ", Nombre: " + getNombre() + ", Hechizos: " + generarStringHechizos();

    return datos;
}

Bruja::~Bruja() {
}