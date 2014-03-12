#include "Vin_varsat.h"


Vin_varsat::Vin_varsat()
{

}

Vin_varsat::Vin_varsat(std::vector<std::string> proprietati)
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

	///setez proprietatile alimentului
	for(int i = 1; i < proprietati.size(); i++)
	{
		if(proprietati[i] == "rosu" || proprietati[i] == "alb")
		{
			setCuloare(proprietati[i]);
		}
		else
			if(proprietati[i] == "sec" || proprietati[i] == "dulce")
			{
				setSoi(proprietati[i]);
			}
	}

	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		///daca in stoc am un vin
		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "vin_varsat")
		{
			if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getCuloare()) != std::string::npos &&
			        magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getSoi()) != std::string::npos)
			{
				set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
			}
		}
	}
}

Vin_varsat::~Vin_varsat()
{

}

void Vin_varsat::setCuloare(std::string _culoarea_vinului)
{
	culoarea_vinului = _culoarea_vinului;
}

std::string Vin_varsat::getCuloare()
{
	return culoarea_vinului;
}

void Vin_varsat::setSoi(std::string _soiul_vinului)
{
	soiul_vinului = _soiul_vinului;
}

std::string Vin_varsat::getSoi()
{
	return soiul_vinului;
}

std::ifstream& operator>>(std::ifstream& input_file, Vin_varsat *obj)
{
    obj->setUnitateDeMasa(obj->getVolum());
    obj->setNumeAliment("vin_varsat");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _culoare;
    input_file>>_culoare;
    obj->setCuloare(_culoare);

    std::string _soi;
    input_file>>_soi;
    obj->setSoi(_soi);

    obj->setProprietatiComplet(_culoare + " " + _soi);
    return input_file;
}
