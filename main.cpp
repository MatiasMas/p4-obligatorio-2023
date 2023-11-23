#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"
#include "fachada/CapaLogica.h"
#include "clases/Suprema.h"
#include "clases/Especial.h"
#include "clases/Comun.h"

using namespace std;

void pruebaAltaBurjaSuprema() {
    CapaLogica fachada;
    TipoError error;
    Suprema *sup = new Suprema("1", "nom", Fecha(), 3);
    Suprema *sup2 = new Suprema("1", "nom", Fecha(), 3);
    fachada.registrarBrujaSuprema(sup, error);
    if (error == TipoError::BRUJA_SUPREMA_YA_EXISTE) {
        printf("\nla bruja suprema ya existe");
    } else {
        printf("\nla bruja suprema se dio de alta");
    }
    //prueba de que no me deja ingresarla con el mismo identificador en el arbol
    fachada.registrarBrujaSuprema(sup2, error);
    if (error == TipoError::BRUJA_SUPREMA_YA_EXISTE) {
        printf("\nla bruja suprema ya existe");
    } else {
        printf("\nla bruja suprema se dio de alta");
    }
}

void pruebaAltaBurjaComun() {

    CapaLogica fachada;
    TipoError error;
    Suprema *sup = new Suprema("2", "suprema", Fecha(), 3);
    Comun *com = new Comun("3", "Comun", "salem", false, NULL);
    Comun *com2 = new Comun("4", "Comun 2", "salem", false, NULL);

    fachada.registrarBrujaSuprema(sup, error);

    if (error == TipoError::BRUJA_SUPREMA_YA_EXISTE) {
        printf("\nla bruja sumprema ya existe");
    } else {
        printf("\nla bruja se dio de alta");
    }

    String identSup = sup->getIdentificador();
    fachada.registrarBrujaComun(com, identSup, error);

    if (error != TipoError::SIN_ERROR) {
        printf("\nerror");
        printf("%d", error);
    } else {
        printf("\nla bruja comun se dio de alta");
    }

    //prueba de asociar una bruja comun con otra bruja, debe dar error
    String identCom2 = com2->getIdentificador();
    fachada.registrarBrujaComun(com, identCom2, error);

    if (error != TipoError::SIN_ERROR) {
        printf("\nerror");
        printf("%d", error);
    } else {
        printf("\nla bruja comun se dio de alta");
    }

}

void pruebaRegistrarHechizoEnBruja() {
    CapaLogica fachada;
    TipoError error;
    Suprema *sup3 = new Suprema("5", "suprema 3", Fecha(), 3);
    Hechizo *hechizo = new Hechizo("Hechizo prueba");


    fachada.registrarBrujaSuprema(sup3, error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(), hechizo, error);

    if (error != TipoError::SIN_ERROR) {
        printf("\nError en registrar hechizo");
        printf("codigo de error:%d", error);
    } else {
        printf("\nEl hechizo se registro correctamente en la bruja");
    }

}

void pruebalistarDetallesHechizo() {
    CapaLogica fachada;
    TipoError error;
    Hechizo *hechizo;
    Suprema *sup4 = new Suprema("6", "suprema 6", Fecha(), 3);
    Hechizo *hechizo2 = new Hechizo("Hechizo prueba2");
    Hechizo *hechizo3 = new Hechizo("Hechizo prueba3");
    Hechizo *hechizo4 = new Hechizo("Hechizo prueba4");


    sup4->insertarHechizo(hechizo2);
    sup4->insertarHechizo(hechizo3);
    sup4->insertarHechizo(hechizo4);

    sup4->generarString().print();

    fachada.registrarBrujaSuprema(sup4, error);

    printf("\nllego aca 1");
    hechizo = fachada.listarHechizo(sup4->getIdentificador(), 1, error);
    printf("\nllego aca 2");

    if (error != TipoError::SIN_ERROR) {
        printf("\nError en listar hechizo");
        printf("codigo de error:%d", error);
    } else {
        printf("\nllego aca 6");
        hechizo->generarString().print();
    }
}

int main() {
//    CapaLogica *capaLogica = new CapaLogica();
//    String opcionMenu;
//    String aux;
//
//    do {
//        cout << "Por favor selecciona una opcion a continuacion: \n 1) Registrar Bruja Suprema\n 2) Registrar Bruja Comun\n 3) Listar Brujas Alfabeticamente\n 4) Listar detalles de Bruja\n 5) Listar Bruja Suprema mas antigua\n 6) Registrar Hechizo en Bruja\n 7) Listar Hechizo segun su numero\n 8) Listar cantidad de hechizos especiales en un anio dado\n 9) Salir\n" << endl;
//        opcionMenu.scan();
//
//        if (opcionMenu == "1") {
//
//
//            Suprema* suprema = new Suprema();
//
//            capaLogica->registrarBrujaSuprema()
//
//
//        } else if (opcionMenu == "2") {
//            printf("2");
//        } else if (opcionMenu == "3") {
//            printf("3");
//
//        } else if (opcionMenu == "4") {
//            printf("4");
//
//        } else if (opcionMenu == "5") {
//            printf("5");
//
//        } else if (opcionMenu == "6") {
//            printf("6");
//
//        } else if (opcionMenu == "7") {
//            printf("7");
//
//        } else if (opcionMenu == "8") {
//            printf("8");
//
//        } else if (opcionMenu == "9") {
//            cout << "\nQue tenga un buen dia." << endl;
//
//        } else {
//            cout << "\nSelecciona una opcion valida que aparezca en el menu.\n" << endl;
//        }
//
//    } while (!(opcionMenu == String("9")));

    CapaLogica fachada;
    TipoError error;
    Suprema *sup3 = new Suprema("5","suprema 3",Fecha(),3);
    Hechizo *hechizo = new Hechizo("Hechizo prueba");
    Hechizo *hechizo2 = new Hechizo("Hechizo prueba2");
    Hechizo *hechizo3 = new Hechizo("Hechizo prueba3");
    Hechizo *hechizo4 = new Hechizo("Hechizo prueba4");
    Hechizo *hechizo5 = new Hechizo("Hechizo prueba5");
    Hechizo *hechizo6 = new Hechizo("Hechizo prueba6");
    Hechizo *hechizo7 = new Hechizo("Hechizo prueba7");
    Hechizo *hechizo8 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo9 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo10 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo11 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo12 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo13= new Hechizo("Hechizo prueba8");
    Hechizo *hechizo14 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo15 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo16 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo17 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo18 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo19 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo20 = new Hechizo("Hechizo prueba8");
    Hechizo *hechizo21 = new Hechizo("Hechizo prueba8");


    fachada.registrarBrujaSuprema(sup3,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo2,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo3,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo4,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo5,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo6,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo7,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo8,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo9,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo10,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo11,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo12,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo13,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo14,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo15,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo16,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo17,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo18,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo19,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo20,error);

    fachada.registrarHechizoEnBruja(sup3->getIdentificador(),hechizo21,error);

}
