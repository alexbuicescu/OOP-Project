#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED

#include "Faina.h"

class Cartofi : public Faina
{
private:
public:

	Cartofi(std::string unitatea_de_masa_atasata) : Faina(unitatea_de_masa_atasata)
	{
        unitate_de_masa = unitatea_de_masa_atasata;
	}
	~Cartofi()
	{

	}
};

#endif // CARTOFI_H_INCLUDED
