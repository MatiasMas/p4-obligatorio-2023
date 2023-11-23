#ifndef OBLIGATORIO2023AMS_BRUJAS_H
#define OBLIGATORIO2023AMS_BRUJAS_H

#include "../clases/Bruja.h"
#include "../colecciones/Iterador.h"
#include "stdio.h"
#include "../clases/Comun.h"

class Brujas {
    private:
        struct Nodo {
            Bruja *info;
            Nodo *hizq;
            Nodo *hder;
        };
        Nodo *ABB;

        bool perteneceEnArbol(Nodo *a, String ident);

        void insertEnArbol(Nodo *&a, Bruja *bruja);

        Bruja *obtenerEnArbol(Nodo *a, String ident);

        void cargarIterador(Nodo *a, Iterador *&iterador);

        void destruirArbol(Nodo *&a);

        void buscarBrujaMasAntiguaRecursivo(Nodo *abb, String &identSup, Fecha &fechaMasAntigua);

    public:
        Brujas();

        bool member(String ident);

        void insert(Bruja *bruja);

        Bruja *find(String ident);

        bool empty();

        void insertBrujaComun(Comun *comun, String identSup);

        Iterador* listarBrujas();

        Bruja* listarDetallesBruja(String idBruja, int &puntosDePoder);

        Bruja* listarBrujaSupremaMasAntigua();

        ~Brujas();
};

#endif
