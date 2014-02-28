#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Cartofi : public Aliment, public Mod_de_vanzare
{
public:

	Cartofi(int _cantitate)
	{
        unitate_de_masa = getKg();

        setQuantity(_cantitate);
	}
	~Cartofi()
	{

	}
};

#endif // CARTOFI_H_INCLUDED
