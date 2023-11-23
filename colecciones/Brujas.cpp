#include "Brujas.h"

Brujas::Brujas() {
    ABB = NULL;
}


void Brujas::destruirArbol(Nodo *&a) {
    if (a != NULL) {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
        delete (a->info);
        delete (a);
        a = NULL;
    }
}

void Brujas::insertEnArbol(Nodo *&a, Bruja *bruja) {

    if (a == NULL) {
        a = new Nodo;
        a->info = bruja;
        a->hizq = NULL;
        a->hder = NULL;
    } else {
        String ident1, ident2;

        if (bruja->getIdentificador() < a->info->getIdentificador())
            insertEnArbol(a->hizq, bruja);
        else
            insertEnArbol(a->hder, bruja);
    }
}

void Brujas::insert(Bruja *bruja) {
    insertEnArbol(ABB, bruja);
}

void Brujas::insertBrujaComun(Comun *comun, String identSup) {
    Bruja *sup = find(identSup);
    comun->setSuprema((Suprema *) sup);

    insert(comun);
}

bool Brujas::perteneceEnArbol(Nodo *a, String ident) {
    bool encontre = false;
    while (!encontre && a != NULL)
        if (ident == a->info->getIdentificador())
            encontre = true;
        else if (ident < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    return encontre;
}

Bruja *Brujas::obtenerEnArbol(Nodo *a, String ident) {
    while (!(ident == a->info->getIdentificador()))
        if (ident < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    return (a->info);
}

bool Brujas::member(String ident) {
    return perteneceEnArbol(ABB, ident);
}

Bruja *Brujas::find(String ident) {
    return obtenerEnArbol(ABB, ident);
}

Brujas::~Brujas() {
    destruirArbol(ABB);
}

bool Brujas::empty() {
    return ABB == nullptr;
}

void Brujas::cargarIterador(Nodo *a, Iterador *&iterador) {
    if (a != nullptr) {
        cargarIterador(a->hizq, iterador);

        iterador->insertar(new String(a->info->generarString()));

        cargarIterador(a->hder, iterador);
    }
}

Iterador *Brujas::listarBrujas() {
    Iterador *iterador = new Iterador();

    cargarIterador(ABB, iterador);

    return iterador;
}

Bruja *Brujas::listarDetallesBruja(String idBruja, int &puntosDePoder) {
    Bruja *bruja = find(idBruja);

    puntosDePoder = bruja->calcularPuntosDePoder();

    return bruja;
}

Bruja *Brujas::listarBrujaSupremaMasAntigua() {
    String identSup;
    Fecha fechaMasAntigua;

    buscarBrujaMasAntiguaRecursivo(ABB, identSup, fechaMasAntigua);
    Bruja *supremaMasAntigua = find(identSup);

    return supremaMasAntigua;
}

void Brujas::buscarBrujaMasAntiguaRecursivo(Brujas::Nodo *abb, String &identSup, Fecha &fechaMasAntigua) {
    if (abb != nullptr) {

        if (abb->info->getTipo() == TipoBruja::SUPREMA) {
            if (((Suprema *)abb->info)->getFechaNacimiento() < fechaMasAntigua){
                fechaMasAntigua = ((Suprema *)abb->info)->getFechaNacimiento();
                identSup = abb->info->getIdentificador();
            }
        }

        buscarBrujaMasAntiguaRecursivo(abb->hizq, identSup, fechaMasAntigua);
        buscarBrujaMasAntiguaRecursivo(abb->hder, identSup, fechaMasAntigua);
    }
}

int Brujas::cantidadHechizosEspecialesDesarrolladosEnAnio(String ident, int anio) {
    Bruja *bruja = find(ident);

    return bruja->cantidadEspecialesEnAnio(anio);
}
