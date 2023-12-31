#include "Iterador.h"

Iterador::Iterador() {
    prim = nullptr;
    ulti = nullptr;
    actual = nullptr;
}

void Iterador::insertar(String *due) {
    Nodo *nuevo = new Nodo;
    nuevo->info = due;
    nuevo->sig = nullptr;

    if (prim == nullptr) {
        prim = nuevo;
        ulti = nuevo;
        actual = nuevo;
    } else {
        ulti->sig = nuevo;
        ulti = ulti->sig;
    }
}

bool Iterador::hayMasObjetos() {
    return (bool) (actual != nullptr);
}

String *Iterador::proximoObjeto() {
    String *resu = actual->info;
    actual = actual->sig;

    return resu;
}

Iterador::~Iterador() {
    Nodo *aux = prim;

    while (aux != nullptr) {
        prim = prim->sig;
        delete aux;
        aux = prim;
    }
}