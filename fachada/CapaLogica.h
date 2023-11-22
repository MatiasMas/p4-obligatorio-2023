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
    //en varios lados muestra que en la fachada pasa los objetos, pero en al solucion del practio 4, ejercicio 5, lo pasa como puntero
    void registrarBrujaSuprema (Suprema *, TipoError &);
    void registrarBrujaComun (Comun *, String , TipoError &);

};


#endif
