#ifndef OBLIGATORIO2023AMS_CAPALOGICA_H
#define OBLIGATORIO2023AMS_CAPALOGICA_H

#include "../colecciones/Brujas.h"
#include "../clases/Suprema.h"
#include "../clases/Comun.h"
#include "../enums/TipoError.h"

class CapaLogica
{

private:
    Brujas brujas;

public:

    void registrarBrujaSuprema (Suprema *, TipoError &);

    void registrarBrujaComun (Comun *, String , TipoError &);

    void registrarHechizoEnBruja(String, Hechizo *, TipoError &);

};


#endif
