#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED

#include "Aliment.h"
#include <sstream>
#include "Mod_de_vanzare.h"

class Cartof : public Aliment, public Mod_de_vanzare
{
private:
    std::string tip = "";///poate fi doar rosii sau albi
public:

    Cartof(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

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
                    set_most_profitable_price(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//                    std::cout<<"a gasit vin de soi "<<getAlimentPrice()<<'\n';
                }
            }
        }
        std::cout<<"a gasit cartof "<<getAlimentPrice()<<'\n';
    }

    Cartof(char _aliment_din_stoc[])
    {
        unitate_de_masa = getKg();
        nume_aliment = "cartof";

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string _tip;
        _my_stream>>_tip;
        setTip(_tip);

        proprietati_complet = _tip;
    }

	Cartof(int _cantitate)
	{
        unitate_de_masa = getKg();
        nume_aliment = "cartof";

        setQuantity(_cantitate);
        tip = "";
	}
	~Cartof()
	{

	}

	void setTip(std::string _tip)
	{
	    tip = _tip;
	}

	std::string getTip()
	{
	    return tip;
	}
};

#endif // CARTOFI_H_INCLUDED
