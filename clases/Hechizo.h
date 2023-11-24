#ifndef OBLIGATORIO2023AMS_HECHIZO_H
#define OBLIGATORIO2023AMS_HECHIZO_H

#include "../datos/String.h"
#include "../enums/TipoHechizo.h"

class Hechizo {
    private:
        int numero;
        String texto;

    public:
        Hechizo(String txt);

        void setNumero(int num);

        int getNumero();

        void setTexto(String txt);

        String getTexto();

        virtual TipoHechizo getTipo();

        virtual String generarString();

        ~Hechizo();
};

#endif
