#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include <sstream>
#include "Aliment.h"
#include "Values.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
public:

    Varza(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am o varza
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "varza")
            {
                set_most_profitable_price(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//                if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
//                {
//                    setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
//                }
            }
        }
        std::cout<<"a gasit varza "<<getAlimentPrice()<<'\n';
    }

    Varza(char _aliment_din_stoc[])
    {
        unitate_de_masa = getBucata();
        nume_aliment = "varza";

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);
    }

	Varza(double _cantitate)
	{
        unitate_de_masa = getBucata();
        nume_aliment = "varza";

        setQuantity(_cantitate);
	}
	~Varza()
	{

	}
};

#endif // VARZA_H_INCLUDED
