#include "Suprema.h"
#include <iostream>

Suprema::Suprema(String ident, String nom, Fecha fecNac, int cantPoderes) : Bruja(ident, nom), fechaNacimiento(fecNac) {
    cantidadPoderes = cantPoderes;
}

void Suprema::setFechaNacimiento(Fecha fec) {
    fechaNacimiento = fec;
}

Fecha Suprema::getFechaNacimiento() {
    return fechaNacimiento;
}

void Suprema::setCantidadPoderes(int cantPoderes) {
    cantidadPoderes = cantPoderes;
}

int Suprema::getCantidadPoderes() {
    return cantidadPoderes;
}

TipoBruja Suprema::getTipo() {
    return TipoBruja::SUPREMA;
}

int Suprema::calcularPuntosDePoder() {
    HechizosAprendidos* hechizosAprendidos = getHechizosAprendidos();
    int cantidadEspeciales = hechizosAprendidos->cantidadEspeciales();
    int cantidadComunes = hechizosAprendidos->largoHechizos() - cantidadEspeciales;
    int anioNacimiento = fechaNacimiento.getAnio();

    int cantidadPuntos = (cantidadComunes * 2) + (cantidadEspeciales * 4) + cantidadPoderes;

    if (anioNacimiento < 1900) cantidadPuntos = cantidadPuntos + 5;

    return cantidadPuntos;
}

String Suprema::generarString() {
    String datos = Bruja::generarString();

    String cantPoderes;
    cantPoderes = cantPoderes.convertirIntAString(getCantidadPoderes());

    datos = datos + ", Fecha Nacimiento: " + fechaNacimiento.generarString() + ", Cantidad Poderes: " + cantPoderes;

    return datos;
}

Suprema::~Suprema() {
}
