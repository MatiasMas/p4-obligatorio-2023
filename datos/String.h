#ifndef OBLIGATORIO2023AMS_STRING_H
#define OBLIGATORIO2023AMS_STRING_H


const int MAX = 80;

class String {
    private:
        char *cadena;

    public:
        String(); // Constructor por defecto

        String(char *); // Constructor com�n

        String(const String &);//Constructor de copia

        ~String(); // Destructor

        String operator=(const String &);//Operador de asignacion

        bool operator==(String);//Operador de comparacion

        bool operator<(String);//Comparacion alfabetica

        String operator+(String); //Concatenacion de dos strings

        void scan();// lee un string desde la entrada est�ndar

        void print();// muestra un string en la salida est�ndar
};


#endif //OBLIGATORIO2023AMS_STRING_H
