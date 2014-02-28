#ifndef VIN_H_INCLUDED
#define VIN_H_INCLUDED

#include "Aliment.h"
#include "Mod_de_vanzare.h"



class Vin_varsat : public Aliment, public Mod_de_vanzare
{
private:
    std::string soiul_vinului;
    std::string soi_rosu_sec = "rosu_sec", soi_alb_sec = "alb_sec";
public:

	Vin_varsat(int _cantitate)
	{
        unitate_de_masa = getVolum();

        setQuantity(_cantitate);
	}
	~Vin_varsat()
	{

	}
};

class Vin_de_soi : public Aliment, public Mod_de_vanzare
{
private:
    std::string soiul_vinului;
    std::string soiuri[4][4]; /// pe pozitia 0 se retine numele vinului, si pe 1 se retine soiul
    std::string Tara_de_origine;
    std::string tarile_de_origine[4];
    int an_producere;
public:

	Vin_de_soi(int _cantitate, std::string _soi = "", std::string _tara_de_origine = "")
	{
        unitate_de_masa = getBucata();

        soiuri[0][0] = "Cabernet";
        soiuri[0][1] = "Savignon";
        soiuri[0][2] = "rosu";
        soiuri[0][3] = "sec";

        soiuri[1][0] = "Merlot";
        soiuri[1][1] = "Merlot";
        soiuri[1][2] = "rosu";
        soiuri[1][3] = "dulce";

        soiuri[2][0] = "Savignon";
        soiuri[2][1] = "Blanc";
        soiuri[2][2] = "alb";
        soiuri[2][3] = "dulce";

        soiuri[3][0] = "Chardonnay";
        soiuri[3][1] = "Chardonnay";
        soiuri[3][2] = "alb";
        soiuri[3][3] = "dulce";


        tarile_de_origine[0] = "Franta";
        tarile_de_origine[1] = "Argentina";
        tarile_de_origine[2] = "Chile";
        tarile_de_origine[3] = "Australia";

        setQuantity(_cantitate);

        if(_soi != "")
        {
            for(int i = 0; i < 4; i++)
            {
                if(soiuri[i][0] == _soi || soiuri[i][1] == _soi || soiuri[i][2] == _soi)
                {

                }
            }
        }
	}
	~Vin_de_soi()
	{

	}
};



#endif // VIN_H_INCLUDED
