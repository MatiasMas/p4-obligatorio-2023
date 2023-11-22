#include "CapaLogica.h"


void CapaLogica::registrarBrujaSuprema(Suprema *sup, TipoError &error) {
    error = TipoError::SIN_ERROR;

    String ident = sup->getIdentificador();

    if (brujas.member(ident)) {
        error = TipoError::BRUJA_SUPREMA_YA_EXISTE;
    } else {
        brujas.insert(sup);
    }
}
