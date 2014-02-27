#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
protected:
    std::string mod_vanzare = getBucata();
public:

	Varza(std::string _unitatea_de_masa)
	{
        unitate_de_masa = _unitatea_de_masa;
	}
	~Varza()
	{

	}
};

#endif // VARZA_H_INCLUDED
