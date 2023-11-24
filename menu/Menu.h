#ifndef OBLIGATORIO2023AMS_MENU_H
#define OBLIGATORIO2023AMS_MENU_H

#include "../enums/TipoError.h"
#include "../fachada/CapaLogica.h"
#include "../clases/Hechizo.h"
#include "../clases/Especial.h"

class Menu {
    private:

    public:
        Menu();

        void mostrarMensajeDeError(TipoError error);

        void cargarDatosDePrueba(CapaLogica *fachada);
};

#endif
