#ifndef OBLIGATORIO2023AMS_HECHIZOSAPRENDIDOS_H
#define OBLIGATORIO2023AMS_HECHIZOSAPRENDIDOS_H

#include "../clases/Hechizo.h"
#include "Iterador.h"

const int CANT = 20;

class HechizosAprendidos {
    private:
        struct Hechizos {
            Hechizo arre[CANT];
            int tope;
        };
        Hechizos hechizos;

    public:
        HechizosAprendidos();

        void insBack(Hechizo hech);

        bool esVacia();

        int largoHechizos();

        bool estaLleno();

        Hechizo ksimo();

        void listarHechizos(Iterador &iter);

        bool existeHechizo(int hechizoNum);
};


#endif
