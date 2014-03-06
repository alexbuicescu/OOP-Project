#ifndef ALIMENT_H_INCLUDED
#define ALIMENT_H_INCLUDED

#include "Magazin.h"
#include <sstream>

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
	double price = 0, askedQuantity = 0, soldQuantity = 0, cost = 0;

protected:
    ///unitate_de_masa - reprezinta modalitatea prin care se vinde alimentul (la bucata, kg, volum, etc.)
    std::string unitate_de_masa = "", nume_aliment = "";
    std::string proprietati_complet = "";

public:
    ///initializez cu 0 toate datele mele
	Aliment()
	{
		price = 0;
		askedQuantity = 0;
		soldQuantity = 0;
		unitate_de_masa = "";
	}

	~Aliment()
	{

	}

	void setAlimentPrice(double _price)
	{
	    price = _price;
	}

	void setAlimentCost(double _cost)
	{
	    cost = _cost;
	}

	void setQuantity(double _cantitate)
	{
	    askedQuantity = _cantitate;
	}

    ///returnez pretul alimentului
	double getAlimentPrice()
	{
	    return price;
	}

	///retin care este cantitatea ceruta de cumparator, si returnez pretul pentru aceasta cantitate
	double getAlimentPriceByQuantity()
	{
	    return (double) askedQuantity * price;
	}

	std::string getNumeAliment()
	{
	    return nume_aliment;
	}

	double getAlimentCost()
	{
	    return cost;
	}

	void set_most_profitable_price(double product_price, double product_cost)
	{
	    if(getAlimentPrice() != -1)
        {
            if(getAlimentPrice() - getAlimentCost() < product_price - product_cost)
            {
                setAlimentPrice(product_price);
                setAlimentCost(product_cost);
            }
        }
        else
        {
            setAlimentPrice(product_price);
            setAlimentCost(product_cost);
        }
	}

	std::string get_proprietati_complet()
	{
	    return proprietati_complet;
	}
};

#endif // ALIMENT_H_INCLUDED
