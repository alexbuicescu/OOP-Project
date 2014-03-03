#ifndef LISTAMAGAZIN_H_INCLUDED
#define LISTAMAGAZIN_H_INCLUDED

#include "Aliment.h"

class Lista_Smechera
{
private:
    Aliment *lista_mea[1000];
    int size_of_list;
public:

    Lista_Smechera()
    {
        size_of_list = 0;
    }

    ~Lista_Smechera()
    {
        clear_list();
        size_of_list = 0;
    }

    void add_in_list(Aliment *_aliment)
    {
        lista_mea[size_of_list] = _aliment;
        size_of_list++;
    }

    Aliment* getFromLista(int indice_aliment)
    {
        return lista_mea[indice_aliment];
    }

    int get_size_of_list()
    {
        return size_of_list;
    }

    void remove_from_list(Aliment *_aliment)
    {
        for(int i = 0; i < size_of_list; i++)
        {
            if(lista_mea[i] == _aliment)
            {
                delete lista_mea[i];
                lista_mea[i] = lista_mea[--size_of_list];
                break;
            }
        }
    }

    void clear_list()
    {
        for(int i = 0; i < size_of_list; i++)
        {
            delete lista_mea[i];
        }
    }
};


#endif // LISTAMAGAZIN_H_INCLUDED
