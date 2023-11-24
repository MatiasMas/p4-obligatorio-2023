#include "CapaLogica.h"

CapaLogica::CapaLogica() {
}

void CapaLogica::registrarBrujaSuprema(Suprema *sup, TipoError &error) {
    error = TipoError::SIN_ERROR;

    String ident = sup->getIdentificador();

    if (brujas.member(ident)) {
        error = TipoError::BRUJA_YA_EXISTE;
    } else {
        brujas.insert(sup);
    }
}

void CapaLogica::registrarBrujaComun(Comun *comun, String identSup, TipoError &error) {
    error = TipoError::SIN_ERROR;

    if (!brujas.member(identSup)) {
        error = TipoError::BRUJA_NO_EXISTE;
    } else if (brujas.find(identSup)->getTipo() != TipoBruja::SUPREMA) {
        error = TipoError::BRUJA_NO_ES_SUPREMA;
    } else if (brujas.member(comun->getIdentificador())) {
        error = TipoError::BRUJA_COMUN_YA_EXISTE;
    } else {
        brujas.insertBrujaComun(comun, identSup);
    }
}

Iterador *CapaLogica::listarBrujasAlfabeticamente(TipoError &error) {
    Iterador *iterador = nullptr;
    error = TipoError::SIN_ERROR;

    if (brujas.empty()) {
        error = TipoError::DICCIONARIO_BRUJAS_VACIO;
    } else {
        iterador = brujas.listarBrujas();
    }

    return iterador;
}

Bruja *CapaLogica::listarDetallesBruja(String identSup, int &puntosDePoder, TipoError &error) {
    Bruja *bruja = nullptr;
    error = TipoError::SIN_ERROR;

    if (brujas.empty()) {
        error = TipoError::DICCIONARIO_BRUJAS_VACIO;
    } else if (!brujas.member(identSup)) {
        error = TipoError::BRUJA_NO_EXISTE;
    } else {
        bruja = brujas.listarDetallesBruja(identSup, puntosDePoder);
    }

    return bruja;
}

Bruja *CapaLogica::listarBrujaSupremaMasAntigua(TipoError &error) {
    Bruja *bruja = nullptr;
    error = TipoError::SIN_ERROR;

    if (brujas.empty()) {
        error = TipoError::DICCIONARIO_BRUJAS_VACIO;
    } else {
        bruja = brujas.listarBrujaSupremaMasAntigua();
    }

    return bruja;
}

void CapaLogica::registrarHechizoEnBruja(String ident, Hechizo *hechizo, TipoError &error) {
    error = TipoError::SIN_ERROR;

    Bruja *bruja = brujas.find(ident);
    HechizosAprendidos *hechizosAprendidos = bruja->getHechizosAprendidos();
    bool lleno = hechizosAprendidos->estaLleno();

    if (!brujas.member(ident))
        error = TipoError::BRUJA_NO_EXISTE;
    else if (lleno)
        error = TipoError::MAXIMO_HECHIZOS_ALCANZADO;
    else
        brujas.find(ident)->insertarHechizo(hechizo);
}

int CapaLogica::cantidadHechizosEspecialesEnAnio(String ident, int anio, TipoError &error) {
    int cantidadHechizos = 0;
    error = TipoError::SIN_ERROR;

    if (!brujas.member(ident)) {
        error = TipoError::BRUJA_NO_EXISTE;
    } else if (brujas.find(ident)->getHechizosAprendidos()->esVacia()) {
        error = TipoError::NO_HAY_HECHIZOS_REGISTRADOS;
    } else {
        cantidadHechizos = brujas.cantidadHechizosEspecialesDesarrolladosEnAnio(ident, anio);
    }

    return cantidadHechizos;
}

Hechizo *CapaLogica::listarHechizo(String ident, int numHechizo, TipoError &error) {
    Hechizo *hechizo = nullptr;
    error = TipoError::SIN_ERROR;

    if (brujas.empty())
        error = TipoError::DICCIONARIO_BRUJAS_VACIO;
    else if (!brujas.member(ident))
        error = TipoError::BRUJA_NO_EXISTE;
    else if (!brujas.find(ident)->getHechizosAprendidos()->existeHechizo(numHechizo))
        error = TipoError::HECHIZO_NO_EXISTE;
    else
        hechizo = brujas.find(ident)->getHechizosAprendidos()->ksimo(numHechizo - 1);

    return hechizo;
}