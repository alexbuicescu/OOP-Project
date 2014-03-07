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

	double getAlimentPrice()
	{
	    return price;
	}

	void setAlimentCost(double _cost)
	{
	    cost = _cost;
	}

	double getAlimentCost()
	{
	    return cost;
	}

	virtual void setQuantity(double _cantitate)
	{
	    askedQuantity = _cantitate;
	}

	double getQuantity()
	{
	    return askedQuantity;
	}

    void setNumeAliment(std::string _nume_aliment)
    {
        nume_aliment = _nume_aliment;
    }

	std::string getNumeAliment()
	{
	    return nume_aliment;
	}

	void setSoldQuantity(double _soldQuantity)
	{
	    soldQuantity += _soldQuantity;
	}

	double getSoldQuantity()
	{
	    return soldQuantity;
	}

	void setProprietatiComplet(std::string _proprietati_complet)
	{
	    ///inlocuiesc mai intai toate spatiile cu _
	    for(int i = 0; i < _proprietati_complet.size(); i++)
        {
            if(_proprietati_complet[i] == ' ')
            {
                _proprietati_complet[i] = '_';
            }
        }

	    proprietati_complet = _proprietati_complet;
	}

	std::string get_proprietati_complet()
	{
	    return proprietati_complet;
	}

	void setUnitateDeMasa(std::string _unitate_de_masa)
	{
	    unitate_de_masa = _unitate_de_masa;
	}

	std::string getUnitateDeMasa()
	{
	    return unitate_de_masa;
	}

	void setIndiceAlimentDinStoc(int _indice_aliment_din_stoc)
	{
        indice_aliment_din_stoc = _indice_aliment_din_stoc;
	}

	int getIndiceAlimentDinStoc()
	{
	    return indice_aliment_din_stoc;
	}

	///retin care este cantitatea ceruta de cumparator, si returnez pretul pentru aceasta cantitate
	double getAlimentPriceByQuantity()
	{
	    return (double) askedQuantity * price;
	}

	void set_most_profitable_price(int _indice_aliment_din_stoc, double product_price, double product_cost)
	{
	    if(getAlimentPrice() != -1)
        {
            if(getAlimentPrice() - getAlimentCost() < product_price - product_cost)
            {
                setAlimentPrice(product_price);
                setAlimentCost(product_cost);
                setIndiceAlimentDinStoc(_indice_aliment_din_stoc);
            }
        }
        else
        {
            setAlimentPrice(product_price);
            setAlimentCost(product_cost);
            setIndiceAlimentDinStoc(_indice_aliment_din_stoc);
        }
	}
};

#endif // ALIMENT_H_INCLUDED
