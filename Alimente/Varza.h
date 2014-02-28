#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
public:

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
