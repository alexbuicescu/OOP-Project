#include "ListaMagazin.h"


Lista_Smechera::Lista_Smechera()
{
	size_of_list = 0;
}

Lista_Smechera::~Lista_Smechera()
{
	clear_list();
	size_of_list = 0;
}

void Lista_Smechera::add_in_list(Aliment *_aliment)
{
	lista_mea[size_of_list] = _aliment;
	size_of_list++;
}

Aliment* Lista_Smechera::getFromLista(int indice_aliment)
{
	return lista_mea[indice_aliment];
}

int Lista_Smechera::get_size_of_list()
{
	return size_of_list;
}

///must change the way it removes elments because order is important
void Lista_Smechera::remove_from_list(Aliment *_aliment)
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

void Lista_Smechera::remove_from_list(int _indice)
{
	if(size_of_list)
	{
		delete lista_mea[_indice];
		lista_mea[_indice] = lista_mea[--size_of_list];
	}
}

void Lista_Smechera::clear_list()
{
	for(int i = 0; i < size_of_list; i++)
	{
		delete lista_mea[i];
	}
	size_of_list = 0;
}

///returneaza nuemele alimentului din stoc corespunzator alimentului din lista clientului
std::string Lista_Smechera::getNumeAlimentComplet(int _indice_aliment)
{
	std::string nume = "";
	nume = getFromLista(_indice_aliment)->getNumeAliment() + "_" + getFromLista(_indice_aliment)->get_proprietati_complet();
	return nume;
}
