#ifndef FAINA_H_INCLUDED
#define FAINA_H_INCLUDED

#include "Values.h"
#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Faina : public Aliment, public Mod_de_vanzare
{
private:
    int calitate = 0; ///poate fi doar 1, 2 sau 3
public:

    Faina(std::vector<std::string> proprietati)
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
                    set_most_profitable_price(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//                    std::cout<<"a gasit vin de soi "<<getAlimentPrice()<<'\n';
                }
            }
        }
        std::cout<<"a gasit faina "<<getAlimentPrice()<<'\n';
    }

    Faina(char _aliment_din_stoc[])
    {
        unitate_de_masa = getKg();
        nume_aliment = "faina";

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string not_important;
        _my_stream>>not_important;

        int _calitate;
        _my_stream>>_calitate;
        setCalitate(_calitate);

        proprietati_complet = ToString(_calitate);
    }

	Faina(int _cantitate, int _calitate)
	{
        unitate_de_masa = getKg();
        nume_aliment = "faina";

        if(_calitate >= 1 && calitate <= 3)
        {
            calitate = _calitate;
        }
        else
        {
            ///Throw an exception!!! TO-DO
        }

        setQuantity(_cantitate);
	}
	~Faina()
	{

	}

	void setCalitate(int _calitate)
	{
	    calitate = _calitate;
	}

	int getCalitate()
	{
	    return calitate;
	}
};


#endif // FAINA_H_INCLUDED
