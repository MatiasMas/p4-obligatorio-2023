#include "Especial.h"

Especial::Especial(String txt, int anio, String desc) : Hechizo(txt), descripcion(desc) {
    anioManifesto = anio;
}

void Especial::setAnioManifesto(int anio) {
    anioManifesto = anio;
}

int Especial::getAnioManifesto() {
    return anioManifesto;
}

void Especial::setDescripcion(String desc) {
    descripcion = desc;
}

String Especial::getDescripcion() {
    return descripcion;
}

TipoHechizo Especial::getTipo() {
    return TipoHechizo::ESPECIAL;
}

Especial::~Especial() {

}
