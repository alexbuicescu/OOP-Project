#ifndef MAGAZIN_H_INCLUDED
#define MAGAZIN_H_INCLUDED

#include "ListaMagazin.h"
#include <direct.h>
#include <fstream>
#include <vector>
#include <cstring>

class Magazin
{
private:
	Lista_Smechera *lista_cumparaturi_client;
    Lista_Smechera *lista_produse_din_stoc;

    double cantitate_totala_alimente_vandute = 0;
    double cost_total_alimente_vandute = 0;
    double pret_total_alimente_vandute = 0;

    double pret_total_alimente_client = 0;
public:

    Magazin();

    ~Magazin();

    void add_in_stoc(Aliment *_aliment);

    void add_in_lista_client(Aliment *_aliment);

    Aliment* getAlimentFromStock(int indice_aliment);

    int size_of_lista_stoc();

    int size_of_lista_client();

    void Sell_all_items_from_list();

    void Remove_all_items_from_list_stoc();

    void Remove_all_items_from_list_client();

    void setPretTotalClient(double _pret_total_alimente_client);

    double getPretTotalClient();

    void inchide_ziua();

    ///in proprietati[0] se va afla mereu cantitatea dorita
    void get_proprietati_aliment(char aliment[], std::vector<std::string> &prop);

};


#endif // MAGAZIN_H_INCLUDED
