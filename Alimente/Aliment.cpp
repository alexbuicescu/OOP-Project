#include "Aliment.h"
#include "Values.h"

Aliment::Aliment()
{
	price = 0;
	askedQuantity = 0;
	soldQuantity = 0;
	unitate_de_masa = "";
}

Aliment::~Aliment()
{

}

void Aliment::setAlimentPrice(double _price)
{
	price = _price;
}

double Aliment::getAlimentPrice()
{
	return price;
}

void Aliment::setAlimentCost(double _cost)
{
	cost = _cost;
}

double Aliment::getAlimentCost()
{
	return cost;
}

void Aliment::setQuantity(double _cantitate)///nu mai e nevoie sa pun virtual, compilatorul deja stie :)
{
	askedQuantity = _cantitate;
}

double Aliment::getQuantity()
{
	return askedQuantity;
}

void Aliment::setNumeAliment(std::string _nume_aliment)
{
	nume_aliment = _nume_aliment;
}

std::string Aliment::getNumeAliment()
{
	return nume_aliment;
}

void Aliment::setSoldQuantity(double _soldQuantity)
{
	soldQuantity += _soldQuantity;
}

double Aliment::getSoldQuantity()
{
	return soldQuantity;
}

void Aliment::setProprietatiComplet(std::string _proprietati_complet)
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

std::string Aliment::get_proprietati_complet()
{
	return proprietati_complet;
}

void Aliment::setUnitateDeMasa(std::string _unitate_de_masa)
{
	unitate_de_masa = _unitate_de_masa;
}

std::string Aliment::getUnitateDeMasa()
{
	return unitate_de_masa;
}

void Aliment::setIndiceAlimentDinStoc(int _indice_aliment_din_stoc)
{
	indice_aliment_din_stoc = _indice_aliment_din_stoc;
}

int Aliment::getIndiceAlimentDinStoc()
{
	return indice_aliment_din_stoc;
}

///retin care este cantitatea ceruta de cumparator, si returnez pretul pentru aceasta cantitate
double Aliment::getAlimentPriceByQuantity()
{
	return (double) askedQuantity * price;
}

void Aliment::set_price_for_customer_item(std::string item_name, std::vector<std::string> properties)
{
    for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == item_name)
		{
		    bool found_aliment = true;
		    for(int j = 0; j < properties.size(); j++)
            {
                if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(properties[j]) == std::string::npos)
                {
                    found_aliment = false;
                }
            }
			if(found_aliment)
			{
				check_for_price(i);
			}
		}
	}
}

void Aliment::check_for_price(int _indice_aliment_din_stoc)
{
    double product_price = magazinul_meu->getAlimentFromStock(_indice_aliment_din_stoc)->getAlimentPrice();
    double product_cost = magazinul_meu->getAlimentFromStock(_indice_aliment_din_stoc)->getAlimentCost();

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
