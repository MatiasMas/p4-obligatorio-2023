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

        bool perteneceEnArbol(Nodo *, String);

        void insertEnArbol(Nodo *&, Bruja *);

        Bruja *obtenerEnArbol(Nodo *, String);

        void cargarIterador(Nodo *, Iterador &);

        void destruirArbol(Nodo *&);

    public:
        Brujas();

        bool member(String);

        void insert(Bruja *);

        Bruja *find(String);

        void listarBrujas(Iterador &);

         void insertBrujaComun(Comun *, String);

        ~Brujas();
};

#endif
