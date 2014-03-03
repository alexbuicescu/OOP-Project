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
        delete lista_cumparaturi_client;
    }

    void add_in_stoc(Aliment *_aliment)
    {
        lista_produse_din_stoc->add_in_list(_aliment);
    }

    void Sell_all_items_from_list()
    {

    }

    void Remove_all_items_from_list()
    {

    }
};


#endif // MAGAZIN_H_INCLUDED
