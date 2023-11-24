#include "Hechizo.h"

Hechizo::Hechizo(String txt) : texto(txt) {
    numero = 0;
}

int Hechizo::getNumero() {
    return numero;
}

void Hechizo::setTexto(String txt) {
    texto = txt;
}

String Hechizo::getTexto() {
    return texto;
}

TipoHechizo Hechizo::getTipo() {
    return TipoHechizo::COMUN;
}

Hechizo::~Hechizo() {

}

void Hechizo::setNumero(int num) {
    numero = num;
}

String Hechizo::generarString() {
    String datos;
    String tipoHechizo;

    switch (getTipo()) {
        case TipoHechizo::COMUN:
            tipoHechizo = "Comun";
            break;
        case TipoHechizo::ESPECIAL:
            tipoHechizo = "Especial";
            break;
    }

    String num;
    num = num.convertirIntAString(getNumero());

    datos = datos + "Tipo Hechizo: " + tipoHechizo + ", Numero: " + num + ", Texto: " + texto;

    return datos;
}