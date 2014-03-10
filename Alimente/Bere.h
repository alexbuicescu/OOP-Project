#ifndef BERE_H_INCLUDED
#define BERE_H_INCLUDED

#include "Varza.h"

class Bere : public Varza ///public Aliment, public Mod_de_vanzare
{
private:
    std::string brand = "", tip = ""; ///tip poate fi doar blonda sau bruna
public:

    Bere();
    Bere(std::vector<std::string> proprietati);// : Varza(proprietati);

	~Bere();

	void setBrand(std::string _brand);
	std::string getBrand();

	void setTip(std::string _tip);
	std::string getTip();

    friend std::ifstream& operator>>(std::ifstream& input_file, Bere *obj);
};


#endif // BERE_H_INCLUDED
