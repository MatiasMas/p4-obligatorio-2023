//
// Created by User on 14/11/2023.
//

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
        Iterador();/// constructor por defecto

        void insertar(Objeto *); /// inserta un due�o en el iterador

        bool hayMasObjetos();/// determina si quedan due�os por visitar en el iterador

        Objeto *proximoObjeto();/// retorna el proximo duenio por visitar en el iterador

        ~Iterador();/// destructor
};


#endif //OBLIGATORIO2023AMS_ITERADOR_H
