#ifndef OBLIGATORIO2023AMS_ITERADOR_H
#define OBLIGATORIO2023AMS_ITERADOR_H


#include "../clases/Objeto.h"

class Iterador {
    private:
        struct Nodo {
            Objeto *info;
            Nodo *sig;
        };
        Nodo *prim;
        Nodo *ulti;
        Nodo *actual;

    public:
        Iterador();

        void insertar(Objeto *);

        bool hayMasObjetos();

        Objeto *proximoObjeto();
        ~Iterador();
};


#endif
