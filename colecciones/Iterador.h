#ifndef OBLIGATORIO2023AMS_ITERADOR_H
#define OBLIGATORIO2023AMS_ITERADOR_H


#include "../datos/String.h"

class Iterador {
    private:
        struct Nodo {
            String *info;
            Nodo *sig;
        };
        Nodo *prim;
        Nodo *ulti;
        Nodo *actual;

    public:
        Iterador();

        void insertar(String *);

        bool hayMasObjetos();

        String *proximoObjeto();

        ~Iterador();
};


#endif
