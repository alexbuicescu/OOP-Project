#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Cartofi : public Aliment, public Mod_de_vanzare
{
private:
    std::string mod_vanzare = getKg();
public:

	Cartofi(std::string _unitatea_de_masa)
	{
        unitate_de_masa = _unitatea_de_masa;
	}
	~Cartofi()
	{

	}
};

#endif // CARTOFI_H_INCLUDED
