//
// Created by User on 14/11/2023.
//

#ifndef OBLIGATORIO2023AMS_COMUN_H
#define OBLIGATORIO2023AMS_COMUN_H


#include "Bruja.h"
#include "Suprema.h"

class Comun : public Bruja {
    private:
        String regionOrigen;
        bool vuelaEscoba;
        Suprema *suprema;

    public:
        Comun(String ident, String nom, String reg, bool vuela, Suprema *sup);

        String getRegionOrigen();

        void setRegionOrigen(String reg);

        bool getVuelaEscoba();

        void setVuelaEscoba(bool vuela);

        Suprema *getSuprema();

        void setSuprema(Suprema *sup);

        TipoBruja getTipo();

        int calcularPuntosDePoder();

        ~Comun();
};


#endif //OBLIGATORIO2023AMS_COMUN_H
