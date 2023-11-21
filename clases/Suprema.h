#ifndef OBLIGATORIO2023AMS_SUPREMA_H
#define OBLIGATORIO2023AMS_SUPREMA_H

#include "../datos/Fecha.h"
#include "Bruja.h"

class Suprema : public Bruja {
    private:
        Fecha fechaNacimiento;
        int cantidadPoderes;

    public:
        Suprema(String ident, String nom, Fecha fecNac, int cantPoderes);

        void setFechaNacimiento(Fecha fec);

        Fecha getFechaNacimiento();

        void setCantidadPoderes(int cantPoderes);

        int getCantidadPoderes();

        int calcularPuntosDePoder();

        TipoBruja getTipo();

        ~Suprema();
};


#endif
