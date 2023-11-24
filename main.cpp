#include <iostream>
#include "enums/TipoHechizo.h"
#include "clases/Hechizo.h"
#include "colecciones/HechizosAprendidos.h"
#include "fachada/CapaLogica.h"
#include "clases/Suprema.h"
#include "clases/Especial.h"
#include "clases/Comun.h"
#include "menu/Menu.h"

using namespace std;

int main() {
    CapaLogica *capaLogica = new CapaLogica();
    String opcionMenu, identificador, nombre, dia, mes, anio, cantPoderes, regionOrigen, vuelaEscoba, idSuprema, textoHechizo, esHechizoEspecial, descripcionHechizo, numHechizo;
    bool boolAux;
    int puntosPoder;
    TipoError error;
    Menu menu;

    do {
        cout << "Por favor selecciona una opcion a continuacion: \n -1) Cargar datos de prueba \n 1) Registrar Bruja Suprema\n 2) Registrar Bruja Comun\n 3) Listar Brujas Alfabeticamente\n 4) Listar detalles de Bruja\n 5) Listar Bruja Suprema mas antigua\n 6) Registrar Hechizo en Bruja\n 7) Listar Hechizo segun su numero\n 8) Listar cantidad de hechizos especiales en un anio dado\n 9) Salir\n" << endl;
        opcionMenu.scan();

        if (opcionMenu == "-1") {
            menu.cargarDatosDePrueba(capaLogica);
            cout << "\nDatos cargados correctamente." << endl << "\n";
        } else if (opcionMenu == "1") {
            cout << "\nIngrese identificador para la bruja:" << endl;
            identificador.scan();

            cout << "\nIngrese nombre para la bruja:" << endl;
            nombre.scan();

            cout << "\nIngrese dia de nacimiento de la bruja:" << endl;
            dia.scan();

            cout << "\nIngrese mes de nacimiento de la bruja:" << endl;
            mes.scan();

            cout << "\nIngrese anio de nacimiento de la bruja:" << endl;
            anio.scan();

            int diaInt = dia.convertirStringAInt();
            int mesInt = mes.convertirStringAInt();
            int anioInt = anio.convertirStringAInt();
            int cantPoderesInt = cantPoderes.convertirStringAInt();

            Fecha fecNac = Fecha(diaInt, mesInt, anioInt);

            if (!fecNac.esValida()) {
                menu.mostrarMensajeDeError(TipoError::FECHA_NO_VALIDA);
            } else {
                cout << "\nIngrese cantidad de poderes de la bruja:" << endl;
                cantPoderes.scan();

                Suprema *suprema = new Suprema(identificador, nombre, fecNac, cantPoderesInt);

                capaLogica->registrarBrujaSuprema(suprema, error);

                menu.mostrarMensajeDeError(error);
            }

        } else if (opcionMenu == "2") {

            cout << "\nIngrese identificador para la bruja:" << endl;
            identificador.scan();

            cout << "\nIngrese nombre para la bruja:" << endl;
            nombre.scan();

            cout << "\nIngrese region de origen de la bruja:" << endl;
            regionOrigen.scan();

            cout << "\nConfirme si la bruja vuela, SI o NO:" << endl;
            vuelaEscoba.scan();

            if (vuelaEscoba == "SI" || vuelaEscoba == "si" || vuelaEscoba == "Si") {
                boolAux = true;
            } else if (vuelaEscoba == "NO" || vuelaEscoba == "no" || vuelaEscoba == "No") {
                boolAux = false;
            } else {
                menu.mostrarMensajeDeError(TipoError::OPCION_NO_VALIDA);
                continue;
            }

            cout << "\nIngrese identificador de la Bruja Suprema que supervisa:" << endl;
            idSuprema.scan();

            Comun *comun = new Comun(identificador, nombre, regionOrigen, boolAux, nullptr);

            capaLogica->registrarBrujaComun(comun, idSuprema, error);

            menu.mostrarMensajeDeError(error);

        } else if (opcionMenu == "3") {

            Iterador *iterador = capaLogica->listarBrujasAlfabeticamente(error);

            cout << "\n";

            if (iterador == nullptr) {
                menu.mostrarMensajeDeError(error);
            } else {
                while (iterador->hayMasObjetos()) {
                    iterador->proximoObjeto()->print();
                    cout << "--------------------------------------------------------\n";
                }
            }

            cout << "\n";

        } else if (opcionMenu == "4") {

            cout << "\nIngrese identificador de la bruja que quiere los detalles:" << endl;
            identificador.scan();

            Bruja *bruja = capaLogica->listarDetallesBruja(identificador, puntosPoder, error);

            if (bruja == nullptr) {
                menu.mostrarMensajeDeError(error);
            } else {
                bruja->generarString().print();

                cout << "\nLos puntos de poder de la bruja son: " << puntosPoder << endl << "\n";
            }

        } else if (opcionMenu == "5") {

            Bruja *bruja = capaLogica->listarBrujaSupremaMasAntigua(error);

            if (bruja == nullptr) {
                menu.mostrarMensajeDeError(error);
            } else {
                bruja->generarString().print();
            }

        } else if (opcionMenu == "6") {
            Hechizo *hechizo;

            cout << "\nIngrese identificador de la bruja a la que le quiere asignar el hechizo:" << endl;
            identificador.scan();

            cout << "\nIngrese texto del hechizo:" << endl;
            textoHechizo.scan();

            cout << "\nEl hechizo es especial? SI o NO:" << endl;
            esHechizoEspecial.scan();

            if (esHechizoEspecial == "SI" || esHechizoEspecial == "si" || esHechizoEspecial == "Si") {
                boolAux = true;
            } else if (esHechizoEspecial == "NO" || esHechizoEspecial == "no" || esHechizoEspecial == "No") {
                boolAux = false;
            } else {
                menu.mostrarMensajeDeError(TipoError::OPCION_NO_VALIDA);
                continue;
            }

            if (boolAux) {
                cout << "\nIngrese anio de manifiesto del hechizo:" << endl;
                anio.scan();

                cout << "\nIngrese una descripcion del hechizo especial:" << endl;
                descripcionHechizo.scan();

                int anioInt = anio.convertirStringAInt();

                hechizo = new Especial(textoHechizo, anioInt, descripcionHechizo);
            } else {
                hechizo = new Hechizo(textoHechizo);
            }

            capaLogica->registrarHechizoEnBruja(identificador, hechizo, error);

            menu.mostrarMensajeDeError(error);

        } else if (opcionMenu == "7") {

            cout << "\nIngrese identificador de la bruja:" << endl;
            identificador.scan();

            cout << "\nIngrese el numero del hechizo que quiere listar:" << endl;
            numHechizo.scan();

            int numHechizoInt = numHechizo.convertirStringAInt();

            Hechizo *hechizo = capaLogica->listarHechizo(identificador, numHechizoInt, error);

            if (hechizo == nullptr) {
                menu.mostrarMensajeDeError(error);
            } else {
                hechizo->generarString().print();
            }

        } else if (opcionMenu == "8") {

            cout << "\nIngrese identificador de la bruja:" << endl;
            identificador.scan();

            cout << "\nIngrese el anio para el que quiere contabilizar los hechizos:" << endl;
            anio.scan();

            int anioInt = anio.convertirStringAInt();

            int cantidadEspeciales = capaLogica->cantidadHechizosEspecialesEnAnio(identificador, anioInt, error);

            if (cantidadEspeciales == 0) {
                menu.mostrarMensajeDeError(error);
            } else {
                cout << "\nEl numero de hechizos especiales de la bruja es: " << cantidadEspeciales << endl;
            }

        } else if (opcionMenu == "9") {
            cout << "\nQue tenga un buen dia." << endl;

        } else {
            cout << "\nSelecciona una opcion valida que aparezca en el menu.\n" << endl;
        }

    } while (!(opcionMenu == String("9")));
}
