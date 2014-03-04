#ifndef MAGAZIN_H_INCLUDED
#define MAGAZIN_H_INCLUDED

#include "ListaMagazin.h"

class Magazin
{
private:
	Lista_Smechera *lista_cumparaturi_client;
    Lista_Smechera *lista_produse_din_stoc;
public:

    Magazin()
    {
        lista_cumparaturi_client = new Lista_Smechera();
        lista_produse_din_stoc = new Lista_Smechera();
    }

    ~Magazin()
    {
        delete lista_produse_din_stoc;
        delete lista_cumparaturi_client;
    }

    void add_in_stoc(Aliment *_aliment)
    {
        lista_produse_din_stoc->add_in_list(_aliment);
    }

    Aliment* getAlimentFromStock(int indice_aliment)
    {
        return lista_produse_din_stoc->getFromLista(indice_aliment);
    }

    int size_of_lista_stoc()
    {
        return lista_produse_din_stoc->get_size_of_list();
    }

    int size_of_lista_client()
    {
        return lista_cumparaturi_client->get_size_of_list();
    }

    void Sell_all_items_from_list()
    {

    }

    void Remove_all_items_from_list()
    {

    }
};


#endif // MAGAZIN_H_INCLUDED
