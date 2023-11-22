#ifndef TIPOERROR_H
#define TIPOERROR_H

enum class TipoError : int {
    SIN_ERROR,
    BRUJA_NO_EXISTE,
    BRUJA_YA_EXISTE,
    BRUJA_SUPREMA_YA_EXISTE,
    BRUJA_SUPREMA_NO_EXISTE,
    BRUJA_COMUN_YA_EXISTE,
    BRUJA_NO_ES_SUPREMA,
    MAXIMO_HECHIZOS_ALCANZADO,
    DICCIONARIO_BRUJAS_VACIO
};

#endif // TIPOERROR_H
