#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"
#include "fachada/CapaLogica.h"
#include "clases/Suprema.h"
#include "clases/Especial.h"
#include "clases/Comun.h"

void pruebaAltaBurjaSuprema(){

     CapaLogica fachada;
     TipoError error;
     Suprema *sup = new Suprema("1","nom",Fecha(),3);
     Suprema *sup2 = new Suprema("1","nom",Fecha(),3);

     fachada.registrarBrujaSuprema(sup,error);

    if(error == TipoError::BRUJA_SUPREMA_YA_EXISTE){
            printf("\nla burja ya existe");
    }else{
        printf("\nla burja se dio de alta");
    }

    //prueba de que no me deja ingresarla con el mismo identificador en el arbol
     fachada.registrarBrujaSuprema(sup2,error);

     if(error == TipoError::BRUJA_SUPREMA_YA_EXISTE){
            printf("\nla burja ya existe");
    }else{
        printf("\nla burja se dio de alta");
    }

}

int main() {

    /*****test de alta de bruja superma******/
//    pruebaAltaBurjaSuprema();
//
    Hechizo *hechizo1 = new Hechizo("Texto Comun 1");
    Hechizo *hechizo2 = new Hechizo("Texto Comun 2");
//    Hechizo *hechizo3 = new Hechizo("Hechizo Nr 3");
//    Hechizo *hechizo4 = new Hechizo("Hechizo Nr 1");

    Especial* especial1 = new Especial("Texto Especial 1", 2023, "Descripcion Especial 1");
    Especial* especial2 = new Especial("Texto Especial 2", 2022, "Descripcion Especial 2");


    Suprema* suprema = new Suprema("Suprema 1", "Nombre Suprema", Fecha(20,3,1990), 5);

    suprema->insertarHechizo(hechizo1);
    suprema->insertarHechizo(hechizo2);
    suprema->insertarHechizo(especial1);
    suprema->insertarHechizo(especial2);

    suprema->generarString().print();

    Comun* comun = new Comun("Comun 1", "Nombre Comun", "Antartida", true, suprema);

    comun->insertarHechizo(hechizo1);
    comun->generarString().print();
}
