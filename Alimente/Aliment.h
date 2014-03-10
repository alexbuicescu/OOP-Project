#ifndef ALIMENT_H_INCLUDED
#define ALIMENT_H_INCLUDED

//#include "Magazin.h"
#include <sstream>
#include <stdlib.h>
#include <fstream>

template <class T>
std::string ToString(const T &value_to_convert)
{
	std::ostringstream os;

	os << value_to_convert;

	return std::string(os.str());
}

class Aliment
{
private:
    ///price - este pretul alimentului
    ///askedQuantity - este cantitatea pe care o cere cumparatorul inainte sa se decida
    ///soldQuantity - este cantitatea pe care magazionerul o vinde cumparatorului
	double price = 0, cost = 0;

    ///unitate_de_masa - reprezinta modalitatea prin care se vinde alimentul (la bucata, kg, volum, etc.)
    std::string unitate_de_masa = "", nume_aliment = "";
    std::string proprietati_complet = "";

    ///pentru fiecare aliment din lista clientului, retinem carui aliment din stoc ii corespunde
    int indice_aliment_din_stoc = -1;

protected:
    double askedQuantity = 0, soldQuantity = 0;

public:
    ///initializez cu 0 toate datele mele
	Aliment();

	~Aliment();

	void setAlimentPrice(double _price);
	double getAlimentPrice();

	void setAlimentCost(double _cost);
	double getAlimentCost();

	virtual void setQuantity(double _cantitate);
	double getQuantity();

    void setNumeAliment(std::string _nume_aliment);
	std::string getNumeAliment();

	void setSoldQuantity(double _soldQuantity);
	double getSoldQuantity();

	void setProprietatiComplet(std::string _proprietati_complet);
	std::string get_proprietati_complet();

	void setUnitateDeMasa(std::string _unitate_de_masa);
	std::string getUnitateDeMasa();

	void setIndiceAlimentDinStoc(int _indice_aliment_din_stoc);
	int getIndiceAlimentDinStoc();

	///retin care este cantitatea ceruta de cumparator, si returnez pretul pentru aceasta cantitate
	double getAlimentPriceByQuantity();

	void set_most_profitable_price(int _indice_aliment_din_stoc, double product_price, double product_cost);
};

#endif // ALIMENT_H_INCLUDED
