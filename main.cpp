#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"
#include "fachada/CapaLogica.h"
#include "clases/Suprema.h"
#include "clases/Especial.h"
#include "clases/Comun.h"

using namespace std;

int main() {
    CapaLogica *capaLogica = new CapaLogica();
    String opcionMenu, identificador, nombre, dia, mes, anio, cantPoderes, regionOrigen, vuelaEscoba, idSuprema, textoHechizo, esHechizoEspecial, descripcionHechizo, numHechizo;
    bool boolAux;
    int puntosPoder;
    TipoError error;

    do {
        cout << "Por favor selecciona una opcion a continuacion: \n 1) Registrar Bruja Suprema\n 2) Registrar Bruja Comun\n 3) Listar Brujas Alfabeticamente\n 4) Listar detalles de Bruja\n 5) Listar Bruja Suprema mas antigua\n 6) Registrar Hechizo en Bruja\n 7) Listar Hechizo segun su numero\n 8) Listar cantidad de hechizos especiales en un anio dado\n 9) Salir\n" << endl;
        opcionMenu.scan();

        if (opcionMenu == "1") {
            cout << "Ingrese identificador para la bruja:" << endl;
            identificador.scan();

            cout << "Ingrese nombre para la bruja:" << endl;
            nombre.scan();

            cout << "Ingrese dia de nacimiento de la bruja:" << endl;
            dia.scan();

            cout << "Ingrese mes de nacimiento de la bruja:" << endl;
            mes.scan();

            cout << "Ingrese anio de nacimiento de la bruja:" << endl;
            anio.scan();

            cout << "Ingrese cantidad de poderes de la bruja:" << endl;
            cantPoderes.scan();

            int diaInt = dia.convertirStringAInt();
            int mesInt = mes.convertirStringAInt();
            int anioInt = anio.convertirStringAInt();
            int cantPoderesInt = cantPoderes.convertirStringAInt();

            Fecha fecNac = Fecha(diaInt, mesInt, anioInt);

//            if (!fecNac.esValida()) return -10; ->> No anda bien el metodo

            Suprema* suprema = new Suprema(identificador, nombre, fecNac, cantPoderesInt);

            capaLogica->registrarBrujaSuprema(suprema, error);

        } else if (opcionMenu == "2") {

            cout << "Ingrese identificador para la bruja:" << endl;
            identificador.scan();

            cout << "Ingrese nombre para la bruja:" << endl;
            nombre.scan();

            cout << "Ingrese region de origen de la bruja:" << endl;
            regionOrigen.scan();

            cout << "Confirme si la bruja vuela, SI o NO:" << endl;
            vuelaEscoba.scan();

            cout << "Ingrese identificador de la Bruja Suprema que supervisa:" << endl;
            idSuprema.scan();

              if (vuelaEscoba == "SI"  ||  vuelaEscoba == "si"  ||  vuelaEscoba == "Si" ) {
                boolAux = true;
            } else if (vuelaEscoba == "NO"  ||  vuelaEscoba == "no"  ||  vuelaEscoba == "No" ) {
                boolAux = false;
            } else {
                return -20;
            }

            Comun* comun = new Comun(identificador, nombre, regionOrigen, boolAux, nullptr);

            capaLogica->registrarBrujaComun(comun, idSuprema, error);

        } else if (opcionMenu == "3") {

            Iterador* iterador = capaLogica->listarBrujasAlfabeticamente(error);

            if (iterador == nullptr) return -30;

            while(iterador->hayMasObjetos())
                    iterador->proximoObjeto()->print();


        } else if (opcionMenu == "4") {

            cout << "Ingrese identificador de la bruja que quiere los detalles:" << endl;
            identificador.scan();

            Bruja* bruja = capaLogica->listarDetallesBruja(identificador, puntosPoder, error);

            if (bruja == nullptr) return -40;

            bruja->generarString().print();

        } else if (opcionMenu == "5") {

            Bruja* bruja = capaLogica->listarBrujaSupremaMasAntigua(error);

            if (bruja == nullptr) return -50;

            bruja->generarString().print();

        } else if (opcionMenu == "6") {
            Hechizo* hechizo;

            cout << "Ingrese identificador de la bruja a la que le quiere asignar el hechizo:" << endl;
            identificador.scan();

            cout << "Ingrese texto del hechizo:" << endl;
            textoHechizo.scan();

            cout << "El hechizo es especial? SI o NO:" << endl;
            esHechizoEspecial.scan();

            if (esHechizoEspecial == "SI" ||  esHechizoEspecial== "si"  ||  esHechizoEspecial == "Si" ) {
                boolAux = true;
            } else if (esHechizoEspecial == "NO" ||  esHechizoEspecial== "no"  ||  esHechizoEspecial == "No" ) {
                boolAux = false;
            } else {
                return -60;
            }


            if (boolAux) {
                cout << "Ingrese anio de manifiesto del hechizo:" << endl;
                anio.scan();

                cout << "Ingrese una descripcion del hechizo especial:" << endl;
                descripcionHechizo.scan();

                int anioInt = anio.convertirStringAInt();

                hechizo = new Especial(textoHechizo, anioInt, descripcionHechizo);
            } else {
                hechizo = new Hechizo(textoHechizo);
            }

            capaLogica->registrarHechizoEnBruja(identificador, hechizo, error);

        } else if (opcionMenu == "7") {

            cout << "Ingrese identificador de la bruja:" << endl;
            identificador.scan();

            cout << "Ingrese el numero del hechizo que quiere listar:" << endl;
            numHechizo.scan();

            int numHechizoInt = numHechizo.convertirStringAInt();

            Hechizo* hechizo = capaLogica->listarHechizo(identificador, numHechizoInt, error);

            if (hechizo == nullptr) return -70;

            hechizo->generarString().print();

        } else if (opcionMenu == "8") {

            cout << "Ingrese identificador de la bruja:" << endl;
            identificador.scan();

            cout << "Ingrese el anio para el que quiere contabilizar los hechizos:" << endl;
            anio.scan();

            int anioInt = anio.convertirStringAInt();

            int cantidadEspeciales = capaLogica->cantidadHechizosEspecialesEnAnio(identificador, anioInt, error);

            if (cantidadEspeciales == 0) return -80;

            cout << "El numero de hechizos especiales de la bruja es: " << cantidadEspeciales << endl;
        } else if (opcionMenu == "9") {
            cout << "\nQue tenga un buen dia." << endl;

        } else {
            cout << "\nSelecciona una opcion valida que aparezca en el menu.\n" << endl;
        }

    } while (!(opcionMenu == String("9")));
}
