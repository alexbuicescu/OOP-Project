#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"
#include "Values.h"

class Cartof : public Aliment, public Mod_de_vanzare
{
private:
    std::string tip = "";///poate fi doar rosii sau albi
public:

    Cartof();
    Cartof(std::vector<std::string> proprietati);

	~Cartof();

	void setTip(std::string _tip);
	std::string getTip();

    friend std::ifstream& operator>>(std::ifstream& input_file, Cartof *obj);
};

#endif // CARTOFI_H_INCLUDED
