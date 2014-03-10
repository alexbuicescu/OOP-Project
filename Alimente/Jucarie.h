#ifndef JUCARIE_H_INCLUDED
#define JUCARIE_H_INCLUDED

#include "Varza.h"

class Jucarie : public Varza/// public Aliment, public Mod_de_vanzare
{
private:
    std::string nume_jucarie = "";
public:

    Jucarie();
    Jucarie(std::vector<std::string> proprietati);// : Varza(proprietati);

	~Jucarie();

	void setNumeJucarie(std::string _nume_jucarie);
	std::string getNumeJucarie();

    friend std::ifstream& operator>>(std::ifstream& input_file, Jucarie *obj);
};


#endif // JUCARIE_H_INCLUDED
