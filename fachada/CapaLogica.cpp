#include "CapaLogica.h"


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
    Bruja * bruja = nullptr;
    error = TipoError::SIN_ERROR;

    if (!brujas.member(identSup)) {
        error = TipoError::BRUJA_NO_EXISTE;
    } else {
        bruja = brujas.listarDetallesBruja(identSup, puntosDePoder);
    }

    return bruja;
}

Bruja *CapaLogica::listarBrujaSupremaMasAntigua(TipoError &error) {
    Bruja * bruja = nullptr;
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

    if (!brujas.member(ident))
        error = TipoError::BRUJA_NO_EXISTE;
    else if (brujas.find(ident)->getHechizosAprendidos().estaLleno())
        error = TipoError::MAXIMO_HECHIZOS_ALCANZADO;
    else
        brujas.find(ident)->insertarHechizo(hechizo);
}

