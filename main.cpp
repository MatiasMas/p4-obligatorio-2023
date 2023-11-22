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
    Hechizo *hechizo1 = new Hechizo("Hechizo Nr 1");
    Hechizo *hechizo2 = new Hechizo("Hechizo Nr 2");
    Hechizo *hechizo3 = new Hechizo("Hechizo Nr 3");
//    Hechizo *hechizo4 = new Hechizo("Hechizo Nr 1");
//
    HechizosAprendidos *hechizosAprendidos = new HechizosAprendidos();
//
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
//
//    Iterador *iterador = hechizosAprendidos->listarHechizos();
//
//    String* myString = iterador->proximoObjeto();
//
//    myString->print();

//    String myString1 = String("Pepito");
//    String myString2 = String("Fulano");
//
//    String stringCombinado = String();
//
//    stringCombinado = myString1 + myString2;
//
//    std::cout << "", stringCombinado;

//    Hechizo *hechizo = new Hechizo("asd");
//
//    String* asdd = hechizo->generarString();
//
//    asdd->print();
}
