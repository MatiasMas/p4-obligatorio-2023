#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"
#include "fachada/CapaLogica.h"
#include "clases/Suprema.h"


void pruebaAltaBurjaSuprema(){

     CapaLogica fachada;
     TipoError error;
     Suprema *sup = new Suprema("1","nom",Fecha(),3);
     Suprema *sup2 = new Suprema("1","nom",Fecha(),3);

     fachada.registrarBrujaSuprema(sup,error);

    if(error == BRUJA_SUPREMA_YA_EXISTE){
        printf("\nla bruja suprema ya existe");
    }else{
        printf("\nla bruja suprema se dio de alta");
    }

    //prueba de que no me deja ingresarla con el mismo identificador en el arbol
     fachada.registrarBrujaSuprema(sup2,error);

     if(error == BRUJA_SUPREMA_YA_EXISTE){
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

    if(error == BRUJA_SUPREMA_YA_EXISTE){
        printf("\nla bruja sumprema ya existe");
    }else{
        printf("\nla bruja se dio de alta");
    }

    String identSup = sup->getIdentificador();
    fachada.registrarBrujaComun(com,identSup,error);

     if(error != SIN_ERROR){
        printf("\nerror");
        printf("%d",error);
    }else{
        printf("\nla bruja comun se dio de alta");
    }

    //prueba de asociar una bruja comun con otra bruja, debe dar error
    String identCom2 = com2->getIdentificador();
    fachada.registrarBrujaComun(com,identCom2,error);

     if(error != SIN_ERROR){
        printf("\nerror");
        printf("%d",error);
    }else{
        printf("\nla bruja comun se dio de alta");
    }

}

int main() {

    /*****test de alta de bruja superma******/

    pruebaAltaBurjaSuprema();

   /*****test de alta de bruja comun******/
    pruebaAltaBurjaComun();

    Hechizo *hechizo1 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo2 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo3 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo4 = new Hechizo("Hechizo Nr 1");

    HechizosAprendidos *hechizosAprendidos = new HechizosAprendidos();

    hechizosAprendidos->insBack(hechizo1);
    hechizosAprendidos->insBack(hechizo2);
    hechizosAprendidos->insBack(hechizo3);

//    cout << "Hello, World!";
//
//    if (!hechizosAprendidos->esVacia()) {
//        cout << "Es vacio " << hechizosAprendidos->largoHechizos() ;
//
//    }

//idsuprema, datos de la bruja comun

/*
si el id existe (existe(arbol))
    Suprema * suprema = retrieveArbol(idsuprema)
    Comun brujaComun = new Comun(datos de la bruja comun, *suprema)

    arbol.insert(comun)
*/

//    Hechizo* hechizoBuscado = hechizosAprendidos->ksimo(2);

//    Iterador *iterador = hechizosAprendidos->listarHechizos();

//    String myString1 = String("Pepito");
//    String myString2 = String("Fulano");
//
//    String stringCombinado = String();
//
//    stringCombinado = myString1 + myString2;
//
//    std::cout << "", stringCombinado;

    String datos = String("");

    int i = 42;

    std::string str = std::to_string(i);

    const char* cstr = str.c_str();

    String asdsd = String(cstr);

    datos = datos + "Tipo: Hechizo Comun, " + "Numero: " + asdsd;

    datos.print();

}
