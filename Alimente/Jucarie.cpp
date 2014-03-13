#include "Jucarie.h"


Jucarie::Jucarie()
{

}

Jucarie::Jucarie(std::vector<std::string> proprietati)// : Varza(proprietati)
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
		setNumeJucarie(proprietati[1]);
	}

	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
	{
		///daca in stoc am o jucarie
		if(dynamic_cast<Jucarie*>(magazinul_meu->getAlimentFromStock(i)) != NULL)
//		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "jucarie")
		{
			if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getNumeJucarie()) != std::string::npos)
			{
				set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
			}
		}
	}
}

Jucarie::~Jucarie()
{

}

void Jucarie::setNumeJucarie(std::string _nume_jucarie)
{
	///Verifica daca nu cumva mai exista numele TO-DO!!
	nume_jucarie = _nume_jucarie;
}

std::string Jucarie::getNumeJucarie()
{
	return nume_jucarie;
}

std::ifstream& operator>>(std::ifstream& input_file, Jucarie *obj)
{
    obj->setUnitateDeMasa(obj->getBucata());
    obj->setNumeAliment("jucarie");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _nume;
    input_file>>_nume;
    obj->setNumeJucarie(_nume);

    obj->setProprietatiComplet(_nume);

    return input_file;
}
