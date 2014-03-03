#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED

#include "Aliment.h"
#include <sstream>
#include "Mod_de_vanzare.h"

class Cartof : public Aliment, public Mod_de_vanzare
{
private:
    std::string tip;///poate fi doar rosii sau albi
public:

    Cartof(char _aliment_din_stoc[])
    {
        unitate_de_masa = getKg();

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
};

#endif // CARTOFI_H_INCLUDED
