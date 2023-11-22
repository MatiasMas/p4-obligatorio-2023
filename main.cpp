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
        printf("\nla bruja suprema ya existe");
    }else{
        printf("\nla bruja suprema se dio de alta");
    }
    //prueba de que no me deja ingresarla con el mismo identificador en el arbol
     fachada.registrarBrujaSuprema(sup2,error);
     if(error == TipoError::BRUJA_SUPREMA_YA_EXISTE){
        printf("\nla bruja suprema ya existe");
    }else{
        printf("\nla bruja suprema se dio de alta");
    }
}

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

void pruebaRegistrarHechizoEnBruja(){
    CapaLogica fachada;
    TipoError error;
    Suprema *sup3 = new Suprema("5","suprema 3",Fecha(),3);
    Hechizo *hechizo = new Hechizo("Hechizo prueba");


    fachada.registrarBrujaSuprema(sup3,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo,error);

    if(error != TipoError::SIN_ERROR){
        printf("\nError en registrar hechizo");
        printf("codigo de error:%d",error);
    }else{
        printf("\nEl hechizo se registro correctamente en la bruja");
    }

}

void pruebalistarDetallesHechizo(){
    CapaLogica fachada;
    TipoError error;
    Hechizo *hechizo;
    Suprema *sup4 = new Suprema("6","suprema 6",Fecha(),3);
    Hechizo *hechizo2 = new Hechizo("Hechizo prueba2");
    Hechizo *hechizo3 = new Hechizo("Hechizo prueba3");
    Hechizo *hechizo4 = new Hechizo("Hechizo prueba4");


   sup4->insertarHechizo(hechizo2);
   sup4->insertarHechizo(hechizo3);
   sup4->insertarHechizo(hechizo4);

   sup4->generarString().print();

    fachada.registrarBrujaSuprema(sup4,error);

    printf("\nllego aca 1");
    hechizo = fachada.listarHechizo(sup4->getIdentificador(),1,error);
    printf("\nllego aca 2");

    if(error != TipoError::SIN_ERROR){
        printf("\nError en listar hechizo");
        printf("codigo de error:%d",error);
    }else{
        printf("\nllego aca 6");
        hechizo->generarString().print();
    }
}

int main() {

//    /*****test de alta de bruja superma******/
//    pruebaAltaBurjaSuprema();
//
//     /*****test de alta de bruja superma******/
//    pruebaAltaBurjaComun();
//
//    /*****test de alta de hechizo en bruja******/
//    pruebaRegistrarHechizoEnBruja();

    pruebalistarDetallesHechizo();

//    Hechizo *hechizo1 = new Hechizo("Hechizo Nr 1");
//    Hechizo *hechizo2 = new Hechizo("Hechizo Nr 1");
//    Hechizo *hechizo3 = new Hechizo("Hechizo Nr 1");
//    Hechizo *hechizo4 = new Hechizo("Hechizo Nr 1");
//
//    HechizosAprendidos *hechizosAprendidos = new HechizosAprendidos();
//
//    hechizosAprendidos->insBack(hechizo1);
//    hechizosAprendidos->insBack(hechizo2);
//    hechizosAprendidos->insBack(hechizo3);
//
//    Especial* especial1 = new Especial("Texto Especial 1", 2023, "Descripcion Especial 1");
//    Especial* especial2 = new Especial("Texto Especial 2", 2022, "Descripcion Especial 2");
//
//
//    Suprema* suprema = new Suprema("Suprema 1", "Nombre Suprema", Fecha(20,3,1990), 5);
//
//    suprema->insertarHechizo(hechizo1);
//    suprema->insertarHechizo(hechizo2);
//    suprema->insertarHechizo(especial1);
//    suprema->insertarHechizo(especial2);
//
//    suprema->generarString().print();
//
//    Comun* comun = new Comun("Comun 1", "Nombre Comun", "Antartida", true, suprema);
//
//    comun->insertarHechizo(hechizo1);
//    comun->generarString().print();
}
