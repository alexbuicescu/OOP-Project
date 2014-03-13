#include "Bere.h"


Bere::Bere()
{

}

Bere::Bere(std::vector<std::string> proprietati)// : Varza(proprietati)
{
    try
    {
        setQuantity(atof(proprietati[0].c_str()));
	}
    catch(...)
    {
        setQuantity(0);
    }
	setAlimentPrice(0);

	for(int i = 1; i < proprietati.size(); i++)
	{
		if(proprietati[i] == "blonda" || proprietati[i] == "bruna")
		{
			setTip(proprietati[i]);
		}
		else
		{
			setBrand(proprietati[i]);
		}
	}

	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		///daca in stoc am o bere
		if(dynamic_cast<Bere*>(magazinul_meu->getAlimentFromStock(i)) != NULL)
//		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "bere")
		{
			if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getBrand()) != std::string::npos &&
			        magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getTip()) != std::string::npos)
			{
				set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
			}
		}
	}
}

Bere::~Bere()
{

}

void Bere::setBrand(std::string _brand)
{
	brand = _brand;
}

void Bere::setTip(std::string _tip)
{
	tip = _tip;
}

std::string Bere::getBrand()
{
	return brand;
}

std::string Bere::getTip()
{
	return tip;
}

std::ifstream& operator>>(std::ifstream& input_file, Bere *obj)
{
    obj->setUnitateDeMasa(obj->getBucata());
    obj->setNumeAliment("bere");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _brand;
    input_file>>_brand;
    obj->setBrand(_brand);

    std::string _tip;
    input_file>>_tip;
    obj->setTip(_tip);

    obj->setProprietatiComplet(_brand + " " + _tip);

    return input_file;
}
