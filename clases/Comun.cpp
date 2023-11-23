//
// Created by User on 14/11/2023.
//

#include "Comun.h"

Comun::Comun(String ident, String nom, String reg, bool vuela, Suprema *sup) : Bruja(ident, nom), regionOrigen(reg), suprema(sup)  {
    vuelaEscoba = vuela;
}

String Comun::getRegionOrigen() {
    return regionOrigen;
}

void Comun::setRegionOrigen(String reg) {
    regionOrigen = reg;
}

bool Comun::getVuelaEscoba() {
    return vuelaEscoba;
}

void Comun::setVuelaEscoba(bool vuela) {
    vuelaEscoba = vuela;
}

Suprema *Comun::getSuprema() {
    return suprema;
}

void Comun::setSuprema(Suprema *sup) {
    suprema = sup;
}

TipoBruja Comun::getTipo() {
    return TipoBruja::COMUN;
}

int Comun::calcularPuntosDePoder() {
    HechizosAprendidos* hechizosAprendidos = getHechizosAprendidos();
    int cantidadEspeciales = hechizosAprendidos->cantidadEspeciales();
    int cantidadComunes = hechizosAprendidos->largoHechizos() - cantidadEspeciales;

    int cantidadPuntos = (cantidadComunes * 1) + (cantidadEspeciales * 2);

    if (regionOrigen == "SALEM"){
        cantidadPuntos++;
    }

    return cantidadPuntos;
}

String Comun::generarString() {
    String datos = Bruja::generarString();
    String vuelaEnEscoba;

    if(vuelaEscoba)
        vuelaEnEscoba = "Si";
    else
        vuelaEnEscoba = "No";

    datos = datos + ", Region Origen: " + regionOrigen + ", Vuela Escoba: " + vuelaEnEscoba + ", Maestra Suprema: " + suprema->generarString();

    return datos;
}

Comun::~Comun() {
}
