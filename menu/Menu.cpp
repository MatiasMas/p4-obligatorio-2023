#include <iostream>
#include "Menu.h"

using namespace std;

void Menu::mostrarMensajeDeError(TipoError error) {
    switch (error) {
        case TipoError::BRUJA_NO_EXISTE:
            cout << "\nNo existe una bruja con ese identificador." << endl << "\n";
            break;
        case TipoError::SIN_ERROR:
            cout << "\nLa operacion fue un exito." << endl << "\n";
            break;
        case TipoError::BRUJA_YA_EXISTE:
            cout << "\nYa existe una bruja con dicho identificador." << endl << "\n";
            break;
        case TipoError::BRUJA_SUPREMA_YA_EXISTE:
            cout << "\nYa existe una bruja suprema con ese identificador." << endl << "\n";
            break;
        case TipoError::BRUJA_SUPREMA_NO_EXISTE:
            cout << "\nNo existe una bruja suprema con ese identificador." << endl << "\n";
            break;
        case TipoError::BRUJA_COMUN_YA_EXISTE:
            cout << "\nUna bruja comun con ese identificador ya existe." << endl << "\n";
            break;
        case TipoError::BRUJA_NO_ES_SUPREMA:
            cout << "\nLa bruja encontrada con ese identificador no es suprema." << endl << "\n";
            break;
        case TipoError::MAXIMO_HECHIZOS_ALCANZADO:
            cout << "\nNo se pudo agregar el hechizo, el numero maximo fue alcanzado." << endl << "\n";
            break;
        case TipoError::DICCIONARIO_BRUJAS_VACIO:
            cout << "\nNo hay brujas registradas en el aquelarre." << endl << "\n";
            break;
        case TipoError::NO_HAY_HECHIZOS_REGISTRADOS:
            cout << "\nEsa bruja no tiene hechizos registrados." << endl << "\n";
            break;
        case TipoError::HECHIZO_NO_EXISTE:
            cout << "\nNo existe un hechizo con ese numero." << endl << "\n";
            break;
        case TipoError::FECHA_NO_VALIDA:
            cout << "\nLa fecha ingresada no es valida." << endl << "\n";
            break;
        case TipoError::OPCION_NO_VALIDA:
            cout << "\nLa opcion ingresada no es valida." << endl << "\n";
            break;
    }
}

void Menu::cargarDatosDePrueba(CapaLogica *fachada){
     TipoError error;
     //una suprema sin una comun asociada
     Suprema *sup = new Suprema("1","Suprema id:1",Fecha(10,10,1950),3);
     fachada->registrarBrujaSuprema(sup,error);


     //una suprema con una comun asociada
     Suprema *sup2 = new Suprema("2","Suprema id:2",Fecha(11,7,1800),2);
     fachada->registrarBrujaSuprema(sup2,error);
     Comun *com = new Comun("3","Comun id:3 de Suprema id:2","region 1",true,NULL);
     fachada->registrarBrujaComun(com,sup2->getIdentificador(),error);

     //una suprema con una dos comunes asociada
     Suprema *sup4 = new Suprema("4","Suprema id:4",Fecha(9,5,1758),1);
     fachada->registrarBrujaSuprema(sup4,error);
     Comun *com5 = new Comun("5","Comun id:5 de Suprema id:4","region 2",true,NULL);
     fachada->registrarBrujaComun(com5,sup4->getIdentificador(),error);
     Comun *com6 = new Comun("6","Comun id:6 de Suprema id:4","SALEM",true,NULL);
     fachada->registrarBrujaComun(com6,sup4->getIdentificador(),error);

     //agrego hechizos comunes a las brujas
     Hechizo *hechizo1 = new Hechizo("Hechizo comun 1");
     Hechizo *hechizo2 = new Hechizo("Hechizo comun 2");
     Hechizo *hechizo3 = new Hechizo("Hechizo comun 3");
     Hechizo *hechizo4 = new Hechizo("Hechizo comun 4");

     Especial *especial1 = new Especial("Especial 1",1990,"Hechizo especial 1");
     Especial *especial2 = new Especial("Especial 2",1989,"Hechizo especial 2");
     Especial *especial3 = new Especial("Especial 3",1650,"Hechizo especial 3");
     Especial *especial4 = new Especial("Especial 4",1901,"Hechizo especial 4");

     //un hechizo en suprema 1
     fachada->registrarHechizoEnBruja(sup->getIdentificador(),hechizo1,error);

     //un hechizo de cada tipo a suprmea 2
     fachada->registrarHechizoEnBruja(sup2->getIdentificador(),hechizo2,error);
     fachada->registrarHechizoEnBruja(sup2->getIdentificador(),especial1,error);

     //un hechizo a comun 1
     fachada->registrarHechizoEnBruja(com->getIdentificador(),hechizo1,error);

     //un hechizo de cada tipo en comun 5
     fachada->registrarHechizoEnBruja(com5->getIdentificador(),hechizo3,error);
     fachada->registrarHechizoEnBruja(com5->getIdentificador(),especial2,error);
}
Menu::Menu() {

}
