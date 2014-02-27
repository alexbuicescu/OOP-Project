#ifndef VIN_H_INCLUDED
#define VIN_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"



class Vin_varsat : public Aliment, public Mod_de_vanzare
{
private:
    std::string soiul_vinului;
    std::string soi_rosu_sec = "rosu_sec", soi_alb_sec = "alb_sec";
protected:
    std::string mod_vanzare = getVolum();
public:

	Vin_varsat(std::string _unitatea_de_masa)
	{
        unitate_de_masa = _unitatea_de_masa;
	}
	~Vin_varsat()
	{

	}
};

class Vin_de_soi : public Aliment, public Mod_de_vanzare
{
private:
    std::string soiul_vinului;
    int nrSoiuri = 4;
    std::string soiuri[4][2]; /// pe pozitia 0 se retine numele vinului, si pe 1 se retine soiul
protected:
    std::string mod_vanzare = getBucata();
public:

	Vin_de_soi(std::string _unitatea_de_masa)
	{
        unitate_de_masa = _unitatea_de_masa;
	}
	~Vin_de_soi()
	{

	}
};



#endif // VIN_H_INCLUDED
