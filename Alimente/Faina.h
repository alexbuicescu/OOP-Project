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
        setAlimentPrice(pret_maxim);

        if(proprietati.size() >= 2)
        {
            setCalitate(atoi(proprietati[1].c_str()));
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am faina
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "faina")
            {
                ///daca cumparatorul vrea o anumita calitate la faina
                if(getCalitate() != 0)
                {
                    ///daca i-am gasit faina, o iau pe cea mai ieftina
                    if(getCalitate() == ((Faina*)(magazinul_meu->getAlimentFromStock(i)))->getCalitate())
                    {
                        if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
                        {
                            setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
                        }
                        std::cout<<"a gasit faina cu calitatea: "<<getCalitate()<<'\n';
                    }
                }
                else
                ///daca cumparatorul nu a dat un nume, iau cea mai ieftina faina posibila
                {
                    if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
                    {
                        setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
                    }
                }
            }
        }
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
