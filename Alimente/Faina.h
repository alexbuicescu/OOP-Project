#ifndef FAINA_H_INCLUDED
#define FAINA_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Faina : public Aliment, public Mod_de_vanzare
{
private:
    int calitate; ///poate fi doar 1, 2 sau 3
public:

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
};


#endif // FAINA_H_INCLUDED
