#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
protected:
    std::string mod_vanzare = getBucata();
public:

	Varza(std::string unitatea_de_masa_atasata)
	{
        unitate_de_masa = unitatea_de_masa_atasata;
	}
	~Varza()
	{

	}
};

#endif // VARZA_H_INCLUDED
