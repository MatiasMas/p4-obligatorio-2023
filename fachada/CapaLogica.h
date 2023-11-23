#ifndef OBLIGATORIO2023AMS_CAPALOGICA_H
#define OBLIGATORIO2023AMS_CAPALOGICA_H

#include "../colecciones/Brujas.h"
#include "../clases/Suprema.h"
#include "../clases/Comun.h"
#include "../enums/TipoError.h"

class CapaLogica {

    private:
        Brujas brujas;

    public:
        //en varios lados muestra que en la fachada pasa los objetos, pero en al solucion del practio 4, ejercicio 5, lo pasa como puntero
        //R1 = Alta de bruja Suprema
        void registrarBrujaSuprema(Suprema *sup, TipoError &error);

        //R2 = Alta de bruja Comun
        void registrarBrujaComun(Comun *comun, String identSup, TipoError &error);

        //R3 = Listar todas las brujas alfabeticamente
        Iterador *listarBrujasAlfabeticamente(TipoError &error);

        //R4 = Listar detalles de una bruja en particular junto con sus puntos de poder
        Bruja *listarDetallesBruja(String identSup, int &puntosDePoder, TipoError &error);

        //R5 = Listar detalles de la bruja suprema mas antigua del aquelarre
        Bruja *listarBrujaSupremaMasAntigua(TipoError &error);

        //R6 = Registrar nuevo hechizo en una bruja
        void registrarHechizoEnBruja(String ident, Hechizo *hechizo, TipoError &error);

        //R8 = Listar cantidad de hechizos especiales manifestados en un anio en particular
        int cantidadHechizosEspecialesEnAnio(String ident, int anio, TipoError &error);
};


#endif
