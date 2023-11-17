#ifndef OBLIGATORIO2023AMS_ESPECIAL_H
#define OBLIGATORIO2023AMS_ESPECIAL_H

#include "Hechizo.h"

class Especial : public Hechizo
{
private:
    int anioManifesto;
    String descripcion;
public:
    Especial(int num,String txt, int anio, String desc);
    void setAnioManifesto(int anio);
    int getAnioManifesto();
    void setDescripcion(String desc);
    String getDescripcion();
    TipoHechizo getTipo();
    ~Especial();


};


#endif
