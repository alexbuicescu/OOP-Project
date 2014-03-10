#include "Magazin.h"

Magazin::Magazin()
{
	lista_cumparaturi_client = new Lista_Smechera();
	lista_produse_din_stoc = new Lista_Smechera();
}

Magazin::~Magazin()
{
	delete lista_produse_din_stoc;
	delete lista_cumparaturi_client;
}

void Magazin::add_in_stoc(Aliment *_aliment)
{
	lista_produse_din_stoc->add_in_list(_aliment);
}

void Magazin::add_in_lista_client(Aliment *_aliment)
{
	lista_cumparaturi_client->add_in_list(_aliment);
	setPretTotalClient(_aliment->getAlimentPriceByQuantity());
}

Aliment* Magazin::getAlimentFromStock(int indice_aliment)
{
	return lista_produse_din_stoc->getFromLista(indice_aliment);
}

int Magazin::size_of_lista_stoc()
{
	return lista_produse_din_stoc->get_size_of_list();
}

int Magazin::size_of_lista_client()
{
	return lista_cumparaturi_client->get_size_of_list();
}

void Magazin::Sell_all_items_from_list()
{
	///parcurg toate alimentele din lista clientului si maresc cantitatea vanduta pentru alimentul corespunzator lui din stoc
	for(int i = 0; i < size_of_lista_client(); i++)
	{
		int indice_stoc = lista_cumparaturi_client->getFromLista(i)->getIndiceAlimentDinStoc();
		double cantitate_dorita = lista_cumparaturi_client->getFromLista(i)->getQuantity();

		lista_produse_din_stoc->getFromLista(indice_stoc)->setSoldQuantity(cantitate_dorita);

		cantitate_totala_alimente_vandute += cantitate_dorita;
		pret_total_alimente_vandute += (double)(lista_cumparaturi_client->getFromLista(i)->getAlimentPrice() * cantitate_dorita);
		cost_total_alimente_vandute += (double)(lista_cumparaturi_client->getFromLista(i)->getAlimentCost() * cantitate_dorita);
	}
	lista_cumparaturi_client->clear_list();
}

void Magazin::Remove_all_items_from_list_stoc()
{
	lista_produse_din_stoc->clear_list();
}

void Magazin::Remove_all_items_from_list_client()
{
	pret_total_alimente_client = 0;
	lista_cumparaturi_client->clear_list();
}

void Magazin::setPretTotalClient(double _pret_total_alimente_client)
{
	pret_total_alimente_client += _pret_total_alimente_client;
}

double Magazin::getPretTotalClient()
{
	return pret_total_alimente_client;
}

void Magazin::inchide_ziua()
{
	std::ifstream fin("Baza de date/numar de zile.txt");

	int numar_de_zile = 0;
	fin >> numar_de_zile;

	mkdir(ToString("Baza de date/Ziua " + ToString(numar_de_zile + 1)).c_str());
	std::ofstream fout(ToString("Baza de date/Ziua " + ToString(numar_de_zile + 1) + "/db.txt").c_str());

	///trec incasarile totale la inceputul fisierului
	fout << cantitate_totala_alimente_vandute << ' ' << pret_total_alimente_vandute << ' ' << cost_total_alimente_vandute << ' ' <<
	     pret_total_alimente_vandute - cost_total_alimente_vandute << '\n';

	for(int i = 0; i < size_of_lista_stoc(); i++)
	{
		std::string nume_aliment = lista_produse_din_stoc->getNumeAlimentComplet(i);
		double pret_aliment = lista_produse_din_stoc->getFromLista(i)->getAlimentPrice();
		double cost_aliment = lista_produse_din_stoc->getFromLista(i)->getAlimentCost();
		double cantitate_aliment = lista_produse_din_stoc->getFromLista(i)->getSoldQuantity();

		fout << nume_aliment << ' ' << pret_aliment << ' ' << cost_aliment << ' ' << cantitate_aliment << '\n';
	}

	std::ofstream fout2("Baza de date/numar de zile.txt");
	fout2 << numar_de_zile + 1 << '\n';
}

///in proprietati[0] se va afla mereu cantitatea dorita
void Magazin::get_proprietati_aliment(char aliment[], std::vector<std::string> &prop)
{
	std::string proprietate = "";
	int k = 0;
	///vad care este prima pozitie pe care nu se afla un spatiu pentru a fi sigur ca incep cu un cuvant si nu cu spatii
	for(k = 0; k < strlen(aliment); k++)
	{
		if(aliment[k] != ' ')
		{
			break;
		}
	}

	for(int i = k; i < strlen(aliment); i++)
	{
		///cat timp nu e spatiu construieste proprietatea noua, iar la spatiu o adauga in lista de proprietati
		///cand ajunge la ultimul caracter, verific daca e spatiu, iar daca nu e, continui construirea proprietatii
		if(aliment[i] != ' ')
		{
			if(i != strlen(aliment) - 1)
			{
				proprietate += aliment[i]; ///change to .append TO-DO!!!
				continue;
			}
			else
				if(i == strlen(aliment) - 1)
				{
					proprietate += aliment[i]; ///change to .append TO-DO!!!
				}
		}
		if(proprietate != "")
		{
			prop.push_back(proprietate);
		}
		proprietate = "";
	}
}
