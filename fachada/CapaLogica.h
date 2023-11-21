#ifndef OBLIGATORIO2023AMS_CAPALOGICA_H
#define OBLIGATORIO2023AMS_CAPALOGICA_H

#include "../colecciones/Brujas.h"
#include "../clases/Suprema.h"
#include "../enums/TipoError.h"

class CapaLogica
{

private:
    Brujas brujas;

public:
    void altaBrujaSuprema (Suprema *, TipoError &);

};


#endif
