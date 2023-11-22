//
// Created by User on 14/11/2023.
//

#include "HechizosAprendidos.h"

HechizosAprendidos::HechizosAprendidos() {
    hechizos.tope = 0;
}

void HechizosAprendidos::insBack(Hechizo *hech) {
    int pos = hechizos.tope;

    hech->setNumero(pos + 1);
    hechizos.arre[pos] = hech;

    hechizos.tope++;
}

bool HechizosAprendidos::esVacia() {
    return hechizos.tope == 0;
}

int HechizosAprendidos::largoHechizos() {
    return hechizos.tope;
}

bool HechizosAprendidos::estaLleno() {
    return hechizos.tope == CANT;
}

Hechizo *HechizosAprendidos::ksimo(int k) {
    return hechizos.arre[k];
}

Iterador *HechizosAprendidos::listarHechizos() {
    Iterador *iterador = new Iterador();

    for (int i = 0; i < hechizos.tope; ++i) {
        String* strAux = new String(hechizos.arre[i]->generarString());

        iterador->insertar(strAux);
    }

    return iterador;
}

bool HechizosAprendidos::existeHechizo(int hechizoNum) {
    bool existe = false;

    if (!esVacia()) {
        if (hechizos.tope > hechizoNum && hechizoNum >= 0) {
            existe = true;
        }
    }

    return existe;
}

HechizosAprendidos::~HechizosAprendidos() {
    for (int i = 0; i < hechizos.tope; ++i) {
        delete hechizos.arre[i];
        hechizos.arre[i] = nullptr;
    }
}