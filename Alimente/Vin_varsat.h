#ifndef VIN_VARSAT_H_INCLUDED
#define VIN_VARSAT_H_INCLUDED

#include "Values.h"
#include "Aliment.h"
#include "Mod_de_vanzare.h"


class Vin_varsat : public Aliment, public Mod_de_vanzare
{
private:
    std::string culoarea_vinului = "", soiul_vinului = "";
public:

    Vin_varsat();
    Vin_varsat(std::vector<std::string> proprietati);

	~Vin_varsat();

	void setCuloare(std::string _culoarea_vinului);
	std::string getCuloare();

	void setSoi(std::string _soiul_vinului);
	std::string getSoi();

    friend std::ifstream& operator>>(std::ifstream& input_file, Vin_varsat *obj);
};

#endif // VIN_H_INCLUDED
