#include "Faina.h"


Faina::Faina()
{

}

Faina::Faina(std::vector<std::string> proprietati)
{
	setQuantity(atof(proprietati[0].c_str()));
	setAlimentPrice(-1);

	if(proprietati.size() >= 2)
	{
		setCalitate(atoi(proprietati[1].c_str()));
	}

	std::string _calitate = "";
	if(getCalitate() != 0)
	{
		_calitate = ToString(getCalitate());
	}

	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		///daca in stoc am faina
		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "faina")
		{
			if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(_calitate) != std::string::npos)
			{
				set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
			}
		}
	}
}

Faina::~Faina()
{

}

void Faina::setCalitate(int _calitate)
{
    if(_calitate >= 1 || _calitate <=3)
	{
	    calitate = _calitate;
	}
	else
    {
        calitate = 0;
    }
}

int Faina::getCalitate()
{
	return calitate;
}

std::ifstream& operator>>(std::ifstream& input_file, Faina *obj)
{
    obj->setUnitateDeMasa(obj->getKg());
    obj->setNumeAliment("faina");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string not_important;
    input_file>>not_important;

    int _calitate;
    input_file>>_calitate;
    obj->setCalitate(_calitate);

    obj->setProprietatiComplet(ToString(_calitate));

    return input_file;
}
