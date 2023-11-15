//
// Created by User on 14/11/2023.
//

#include "Comun.h"

Comun::Comun(String ident, String nom, String reg, bool vuela, Suprema *sup) : Bruja(ident, nom), regionOrigen(reg), suprema(sup)  {

}

String Comun::getRegionOrigen() {
    return String();
}

void Comun::setRegionOrigen(String) {

}

bool Comun::getVuelaEscoba() {
    return false;
}

void Comun::setVuelaEscoba(bool) {

}

Suprema *Comun::getSuprema() {
    return nullptr;
}

void Comun::setSuprema(Suprema *) {

}

TipoBruja Comun::getTipo() {
    return TipoBruja();
}

int Comun::calcularPuntosDePoder() {
    return 0;
}

Comun::~Comun() {

}
