#ifndef OBLIGATORIO2023AMS_HECHIZO_H
#define OBLIGATORIO2023AMS_HECHIZO_H

#include "../datos/String.h"
#include "../enums/TipoHechizo.h"
#include "Objeto.h"

class Hechizo : public Objeto {
    private:
        int numero;
        String texto;

    public:
        Hechizo(int num, String txt);

        void setNumero(int num);

        int getNumero();

        void setTexto(String txt);

        String getTexto();

        virtual TipoHechizo getTipo();

        ~Hechizo();
};


#endif
