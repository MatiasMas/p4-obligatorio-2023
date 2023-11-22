#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"
#include "fachada/CapaLogica.h"
#include "clases/Suprema.h"
#include "clases/Especial.h"
#include "clases/Comun.h"


void pruebaAltaBurjaComun(){

     CapaLogica fachada;
     TipoError error;
     Suprema *sup = new Suprema("2","suprema",Fecha(),3);
     Comun *com = new Comun("3","Comun","salem",false,NULL);
    Comun *com2 = new Comun("4","Comun 2","salem",false,NULL);

     fachada.registrarBrujaSuprema(sup,error);

    if(error == TipoError::BRUJA_SUPREMA_YA_EXISTE){
        printf("\nla bruja sumprema ya existe");
    }else{
        printf("\nla bruja se dio de alta");
    }

    String identSup = sup->getIdentificador();
    fachada.registrarBrujaComun(com,identSup,error);

     if(error != TipoError::SIN_ERROR){
        printf("\nerror");
        printf("%d",error);
    }else{
        printf("\nla bruja comun se dio de alta");
    }

    //prueba de asociar una bruja comun con otra bruja, debe dar error
    String identCom2 = com2->getIdentificador();
    fachada.registrarBrujaComun(com,identCom2,error);

     if(error != TipoError::SIN_ERROR){
        printf("\nerror");
        printf("%d",error);
    }else{
        printf("\nla bruja comun se dio de alta");
    }

}

int main() {

    /*****test de alta de bruja superma******/
//    pruebaAltaBurjaSuprema();
//
    Hechizo *hechizo1 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo2 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo3 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo4 = new Hechizo("Hechizo Nr 1");

    HechizosAprendidos *hechizosAprendidos = new HechizosAprendidos();

    hechizosAprendidos->insBack(hechizo1);
    hechizosAprendidos->insBack(hechizo2);
    hechizosAprendidos->insBack(hechizo3);

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
