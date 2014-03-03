#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include <sstream>
#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
public:

    Varza(char _aliment_din_stoc[])
    {
        unitate_de_masa = getBucata();

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);
    }

	Varza(double _cantitate)
	{
        unitate_de_masa = getBucata();

        setQuantity(_cantitate);
	}
	~Varza()
	{

	}
};

#endif // VARZA_H_INCLUDED
