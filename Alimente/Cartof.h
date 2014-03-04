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
        setAlimentPrice(pret_maxim);

        if(proprietati.size() >= 2)
        {
            setTip(proprietati[1]);
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am o jucarie
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "cartof")
            {
                ///daca cumparatorul vrea un anumita cartof
                if(getTip() != "")
                {
                    ///daca i-am gasit cartoful, il iau pe cel mai ieftina
                    if(getTip() == ((Cartof*)(magazinul_meu->getAlimentFromStock(i)))->getTip())
                    {
                        if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
                        {
                            setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
                        }
                        std::cout<<"a gasit cartof cu culoarea: "<<getTip()<<'\n';
                    }
                }
                else
                ///daca cumparatorul nu a dat un nume, iau cel mai ieftin cartof posibil
                {
                    if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
                    {
                        setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
                    }
                }
            }
        }

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
