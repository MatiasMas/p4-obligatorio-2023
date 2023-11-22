#include "Brujas.h"

Brujas :: Brujas ()
{
    ABB = NULL;
}


void Brujas :: destruirArbol (Nodo * &a)
{
    if (a != NULL)
    {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
        delete (a->info);
        delete (a);
        a = NULL;
    }
}

void Brujas :: insertEnArbol (Nodo * &a, Bruja * bruja)
{

    if (a == NULL)
    {
        a = new Nodo;
        a -> info = bruja;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else
    {
        String ident1,ident2;

        if (bruja->getIdentificador() < a->info->getIdentificador())
            insertEnArbol(a->hizq,bruja);
        else
            insertEnArbol(a->hder,bruja);

    }

}

void Brujas :: insert (Bruja * bruja)
{
    insertEnArbol (ABB, bruja);
}


void Brujas::insertBrujaComun(Comun *comun, String identSup)
{
    Bruja *sup = obtenerEnArbol(ABB, identSup);
    comun->setSuprema((Suprema *)sup);
    insertEnArbol (ABB, comun);
}

bool Brujas :: perteneceEnArbol (Nodo * a, String ident)
{
    bool encontre = false;
    while (!encontre && a != NULL)
        if (ident == a->info->getIdentificador())
            encontre = true;
        else if (ident < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    return encontre;
}

Bruja * Brujas::obtenerEnArbol (Nodo * a, String ident)
{
    while (!(ident == a->info->getIdentificador()))
        if (ident < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    return (a->info);
}


bool Brujas :: member (String ident)
{
    return perteneceEnArbol(ABB, ident);
}

Bruja * Brujas :: find (String ident)
{
    return obtenerEnArbol (ABB, ident);
}


Brujas :: ~Brujas ()
{
    destruirArbol(ABB);
}
