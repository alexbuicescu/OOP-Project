#include "Vin_de_soi.h"


Vin_de_soi::Vin_de_soi()
{

}

Vin_de_soi::Vin_de_soi(std::vector<std::string> proprietati)// : Vin_varsat(proprietati)
{
	setQuantity(atof(proprietati[0].c_str()));
	setAlimentPrice(-1);

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
			else
				if(proprietati[i][0] >= '0' && proprietati[i][0] <= '9')
				{
					setAn(atoi(proprietati[i].c_str()));
				}
				else
					if(proprietati[i] == "Franta" || proprietati[i] == "Argentina" || proprietati[i] == "Chile" || proprietati[i] == "Australia")
					{
						setTara(proprietati[i]);
					}
					else
						///numele vinului e singurul care a mai putut ramane
					{
						setNumeVin(proprietati[i]);
					}
	}

	///daca anul nu mi s-a dat, atunci cand caut vinul cel mai bun, o sa omit compararea anului, facand anul "" (nu 0)
	std::string an = "";
	if(getAn() != 0)
	{
		an = ToString(getAn());
	}

	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		///daca in stoc am un vin
		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "vin_de_soi")
		{
			if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getNumeVin()) != std::string::npos &&
			        magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(an) != std::string::npos &&
			        magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getSoi()) != std::string::npos &&
			        magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getCuloare()) != std::string::npos &&
			        magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getTara()) != std::string::npos)
			{
				set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
			}
		}
	}
}

Vin_de_soi::~Vin_de_soi()
{

}

void Vin_de_soi::setNumeVin(std::string _nume)
{
	numele_vinului = _nume;
}

std::string Vin_de_soi::getNumeVin()
{
	return numele_vinului;
}

void Vin_de_soi::setTara(std::string _tara)
{
	Tara_de_origine = _tara;
}

std::string Vin_de_soi::getTara()
{
	return Tara_de_origine;
}

void Vin_de_soi::setAn(int _an)
{
	an_producere = _an;
}

int Vin_de_soi::getAn()
{
	return an_producere;
}

void Vin_de_soi::setQuantity(int _cantitate)
{
	askedQuantity = _cantitate;
}

int Vin_de_soi::getQuantity()
{
	return (int)askedQuantity;
}

std::ifstream& operator>>(std::ifstream& input_file, Vin_de_soi *obj)
{
    obj->setUnitateDeMasa(obj->getBucata());
    obj->setNumeAliment("vin_de_soi");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _nume;
    input_file>>_nume;
    obj->setNumeVin(_nume);

    std::string _culoare;
    input_file>>_culoare;
    obj->setCuloare(_culoare);

    std::string _soi;
    input_file>>_soi;
    obj->setSoi(_soi);

    std::string _tara;
    input_file>>_tara;
    obj->setTara(_tara);

    int _an;
    input_file>>_an;
    obj->setAn(_an);

    obj->setProprietatiComplet(_nume + " " + _culoare + " " + _soi + " " + _tara + " " + ToString(_an));
    return input_file;
}