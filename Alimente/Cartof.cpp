#include "Cartof.h"


Cartof::Cartof()
{

}

Cartof::Cartof(std::vector<std::string> proprietati)
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

	if(proprietati.size() >= 2)
	{
		setTip(proprietati[1]);
	}

	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		///daca in stoc am o jucarie
		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "cartof")
		{
			if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getTip()) != std::string::npos)
			{
				set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
			}
		}
	}
}

Cartof::~Cartof()
{

}

void Cartof::setTip(std::string _tip)
{
	tip = _tip;
}

std::string Cartof::getTip()
{
	return tip;
}

std::ifstream& operator>>(std::ifstream& input_file, Cartof *obj)
{
    obj->setUnitateDeMasa(obj->getKg());
    obj->setNumeAliment("cartof");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _tip;
    input_file>>_tip;
    obj->setTip(_tip);

    obj->setProprietatiComplet(_tip);

    return input_file;
}
