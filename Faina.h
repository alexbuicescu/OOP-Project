#ifndef FAINA_H_INCLUDED
#define FAINA_H_INCLUDED

#include "Aliment.h"

class Faina : public Aliment, public Mod_de_vanzare
{
protected:
    std::string mod_vanzare = getKg();
public:

	Faina(std::string unitatea_de_masa_atasata)
	{
        unitate_de_masa = unitatea_de_masa_atasata;
	}
	~Faina()
	{

	}
};


#endif // FAINA_H_INCLUDED
