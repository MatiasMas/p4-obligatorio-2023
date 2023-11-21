//
// Created by User on 14/11/2023.
//

#ifndef OBLIGATORIO2023AMS_BRUJA_H
#define OBLIGATORIO2023AMS_BRUJA_H


#include "../datos/String.h"
#include "../colecciones/HechizosAprendidos.h"
#include "Hechizo.h"
#include "../colecciones/Iterador.h"
#include "../enums/TipoBruja.h"

class Bruja : public Objeto {
    private:
        String identificador;
        String nombre;
        HechizosAprendidos hechizosAprendidos;

    public:
        Bruja(String ident, String nom);

        String getIdentificador();

        String getNombre();

        void setNombre(String nom);

        void insertarHechizo(Hechizo hech);

        Iterador listarHechizosAprendidos();

        virtual TipoBruja getTipo() = 0;

        virtual int calcularPuntosDePoder() = 0;

        virtual ~Bruja();
};


#endif //OBLIGATORIO2023AMS_BRUJA_H
