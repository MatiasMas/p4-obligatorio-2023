#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"

using namespace std;

int main() {

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

//    Hechizo* hechizoBuscado = hechizosAprendidos->ksimo(2);


    Iterador *iterador = hechizosAprendidos->listarHechizos();


    cout << "Hello, World!";

}
