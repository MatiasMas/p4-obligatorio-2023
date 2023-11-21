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
    return TipoHechizo::HECHIZO;
}

Hechizo::~Hechizo() {

}

void Hechizo::setNumero(int num) {
    numero = num;
}
