#ifndef OBLIGATORIO2023AMS_ESPECIAL_H
#define OBLIGATORIO2023AMS_ESPECIAL_H

#include "Hechizo.h"

class Especial : public Hechizo {
    private:
        int anioManifesto;
        String descripcion;

    public:
        Especial(String txt, int anio, String desc);

        void setAnioManifesto(int anio);

        int getAnioManifesto();

        void setDescripcion(String desc);

        String getDescripcion();

        String generarString();

        TipoHechizo getTipo();

        ~Especial();
};

#endif
