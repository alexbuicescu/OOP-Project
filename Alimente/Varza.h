#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED

#include "Aliment.h"
#include "Values.h"
#include "Mod_de_vanzare.h"

class Varza : public Aliment, public Mod_de_vanzare
{
public:

    Varza();
    Varza(std::vector<std::string> proprietati);

	~Varza();

	void setQuantity(int _cantitate);
	int getQuantity();

    friend std::ifstream& operator>>(std::ifstream& input_file, Varza *obj);
};

#endif // VARZA_H_INCLUDED
