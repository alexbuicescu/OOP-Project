#ifndef VIN_DE_SOI_H_INCLUDED
#define VIN_DE_SOI_H_INCLUDED

#include "Vin_varsat.h"

class Vin_de_soi : public Vin_varsat
{
private:
    std::string numele_vinului = "", Tara_de_origine = "";
    int an_producere = 0;
public:

    Vin_de_soi();

    Vin_de_soi(std::vector<std::string> proprietati);// : Vin_varsat(proprietati)

	~Vin_de_soi();

    void setNumeVin(std::string _nume);

    std::string getNumeVin();

    void setTara(std::string _tara);

    std::string getTara();

    void setAn(int _an);

    int getAn();

	void setQuantity(int _cantitate);

	int getQuantity();

    friend std::ifstream& operator>>(std::ifstream& input_file, Vin_de_soi *obj);
};


#endif // VIN_H_INCLUDED
