#ifndef FAINA_H_INCLUDED
#define FAINA_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Faina : public Aliment, public Mod_de_vanzare
{
private:
    int calitate; ///poate fi doar 1, 2 sau 3
protected:
    std::string mod_vanzare = getKg();
public:

	Faina(std::string _unitatea_de_masa, int _calitate)
	{
        unitate_de_masa = _unitatea_de_masa;

        if(_calitate >= 1 && calitate <= 3)
        {
            calitate = _calitate;
        }
        else
        {
            ///Throw an exception!!! TO-DO
        }
	}
	~Faina()
	{

	}
};


#endif // FAINA_H_INCLUDED
