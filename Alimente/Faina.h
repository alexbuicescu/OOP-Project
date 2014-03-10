#ifndef FAINA_H_INCLUDED
#define FAINA_H_INCLUDED

#include "Values.h"
#include "Aliment.h"
#include "Mod_de_vanzare.h"

class Faina : public Aliment, public Mod_de_vanzare
{
private:
    int calitate = 0; ///poate fi doar 1, 2 sau 3
public:

    Faina();
    Faina(std::vector<std::string> proprietati);

	~Faina();

	void setCalitate(int _calitate);
	int getCalitate();

    friend std::ifstream& operator>>(std::ifstream& input_file, Faina *obj);
};


#endif // FAINA_H_INCLUDED
