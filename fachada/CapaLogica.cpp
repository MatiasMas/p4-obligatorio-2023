#include "CapaLogica.h"


void CapaLogica :: registrarBrujaSuprema (Suprema * sup, TipoError &error)
{
    error = TipoError::SIN_ERROR;
    String ident = sup->getIdentificador();
    if (brujas.member(ident))
        error = TipoError::BRUJA_SUPREMA_YA_EXISTE;
    else
        brujas.insert(sup);
}


void CapaLogica :: registrarBrujaComun (Comun * comun, String identSup, TipoError &error)
{
    error = TipoError::SIN_ERROR;
    String identComun = comun->getIdentificador();
    if (!brujas.member(identSup))
        error = TipoError::BRUJA_SUPREMA_NO_EXISTE;
    else if(brujas.member(identComun))
        error = TipoError::BRUJA_COMUN_YA_EXISTE;
    else
        brujas.insertBrujaComun(comun,identSup);
}

