#include "Suprema.h"
#include <iostream>

Suprema :: Suprema (String ident, String nom, Fecha fecNac, int cantPoderes): Bruja(ident,nom)
{
    cantidadPoderes = cantPoderes;
}


void Suprema :: setFechaNacimiento(Fecha fec)
{
    fechaNacimiento = fec;
}

Fecha Suprema :: getFechaNacimiento()
{
}

void Suprema :: setCantidadPoderes(int cantPoderes)
{
}

int Suprema :: getCantidadPoderes()
{
}

TipoBruja Suprema :: getTipo()
{
}

int Suprema::calcularPuntosDePoder(){

}

Suprema :: ~Suprema ()
{
}
