#include "Bruja.h"
#include "Especial.h"

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

HechizosAprendidos *Bruja::getHechizosAprendidos() {
    return &hechizosAprendidos;
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

int Bruja::cantidadEspecialesEnAnio(int anio) {
    int cantidadEspeciales = 0;

    for (int i = 0; i < hechizosAprendidos.largoHechizos(); ++i) {
        if (hechizosAprendidos.ksimo(i)->getTipo() == TipoHechizo::ESPECIAL) {
            if (((Especial *) hechizosAprendidos.ksimo(i))->getAnioManifesto() == anio) {
                cantidadEspeciales++;
            }
        }
    }

    return cantidadEspeciales;
}