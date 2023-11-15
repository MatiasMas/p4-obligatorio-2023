//
// Created by User on 14/11/2023.
//

#ifndef OBLIGATORIO2023AMS_FECHA_H
#define OBLIGATORIO2023AMS_FECHA_H


class Fecha {
    private:
        int dd, mm, aa;

        void incrementar();

    public:
        //Constructor por defecto
        Fecha();

        //Constructor com�n
        Fecha(int, int, int);

        //Constructor de copia
        Fecha(const Fecha &);

        //Selectoras del tipo fecha
        int getDia();

        int getMes();

        int getAnio();

        //Compara por menor 2 fechas
        bool operator<(Fecha);

        //Compara por igualdad 2 fechas
        bool operator==(Fecha);

        //Devuelve la fecha incrementada en n dias
        Fecha operator+(int);

        //Operador prefijo de incremento
        Fecha operator++();

        //Operador postfijo de incremento
        Fecha operator++(int);

        //Devuelve la diferencia en d�as entre 2 fechas
        int operator-(Fecha);

        //Validacion de la fecha
        bool esValida();
};


#endif //OBLIGATORIO2023AMS_FECHA_H
