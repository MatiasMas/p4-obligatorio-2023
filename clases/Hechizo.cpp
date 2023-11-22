#include "Hechizo.h"
#include <string>

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
    return TipoHechizo::HECHIZO;
}

Hechizo::~Hechizo() {

}

void Hechizo::setNumero(int num) {
    numero = num;
}

String Hechizo::generarString() {
    String datos;

    String num;
    num = num.convertirIntAString(getNumero());

    datos = datos + "Tipo: Hechizo Comun, " + "Numero: " + num + ", Texto: " + texto;

    return datos;
}
