#ifndef LISTAMAGAZIN_H_INCLUDED
#define LISTAMAGAZIN_H_INCLUDED

#include "Aliment.h"

class Lista_Smechera
{
private:
    Aliment *lista_mea[1000];
    int size_of_list;
public:

    Lista_Smechera();

    ~Lista_Smechera();

    void add_in_list(Aliment *_aliment);

    Aliment* getFromLista(int indice_aliment);

    int get_size_of_list();

    ///must change the way it removes elments because order is important
    void remove_from_list(Aliment *_aliment);

    void remove_from_list(int _indice);

    void clear_list();

	///returneaza nuemele alimentului din stoc corespunzator alimentului din lista clientului
	std::string getNumeAlimentComplet(int _indice_aliment);
};


#endif // LISTAMAGAZIN_H_INCLUDED
