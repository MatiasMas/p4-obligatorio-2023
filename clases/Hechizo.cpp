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
    String datos = String("");

    int i = 42;

    std::string str = std::to_string(i);

    const char* cstr = str.c_str();

    String asdsd = String(cstr);

//    String asdsa = "" + std::to_string(numero);

    datos = datos + "Tipo: Hechizo Comun, " + "Numero: " + asdsd;

    return datos;

}
