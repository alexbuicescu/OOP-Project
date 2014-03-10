#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include <sstream>
#include "Aliment.h"
#include "Values.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
public:

    Varza()
    {

    }

    Varza(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am o varza
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "varza")
            {
                set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
            }
        }
    }

	void setQuantity(int _cantitate)
	{
	    askedQuantity = _cantitate;
	}

	int getQuantity()
	{
	    return (int)askedQuantity;
	}

	~Varza()
	{

	}

    friend std::ifstream& operator>>(std::ifstream& input_file, Varza *obj);
};
std::ifstream& operator>>(std::ifstream& input_file, Varza *obj)
{
    obj->setUnitateDeMasa(obj->getBucata());
    obj->setNumeAliment("varza");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    return input_file;
}

#endif // VARZA_H_INCLUDED
