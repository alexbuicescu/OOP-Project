#ifndef VIN_H_INCLUDED
#define VIN_H_INCLUDED

#include <sstream>
#include "Aliment.h"
#include "Mod_de_vanzare.h"



class Vin_varsat : public Aliment, public Mod_de_vanzare
{
private:
    std::string culoarea_vinului, soiul_vinului;
    std::string soi_rosu_sec = "rosu_sec", soi_alb_sec = "alb_sec";
public:

    Vin_varsat(char _aliment_din_stoc[])
    {
        unitate_de_masa = getVolum();

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string _culoare;
        _my_stream>>_culoare;
        setCuloare(_culoare);

        std::string _soi;
        _my_stream>>_soi;
        setSoi(_soi);
    }

	Vin_varsat(int _cantitate)
	{
        unitate_de_masa = getVolum();

        setQuantity(_cantitate);
	}
	~Vin_varsat()
	{

	}

	void setSoi(std::string _soiul_vinului)
	{
	    soiul_vinului = _soiul_vinului;
	}

	void setCuloare(std::string _culoarea_vinului)
	{
	    culoarea_vinului = _culoarea_vinului;
	}
};

class Vin_de_soi : public Aliment, public Mod_de_vanzare
{
private:
    std::string numele_vinului;
    std::string culoarea_vinului;
    std::string soiul_vinului;
    std::string Tara_de_origine;
    int an_producere;

public:

    Vin_de_soi(char _aliment_din_stoc[])
    {
        unitate_de_masa = getBucata();

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string _nume;
        _my_stream>>_nume;
        setNume(_nume);

        std::string _culoare;
        _my_stream>>_culoare;
        setCuloare(_culoare);

        std::string _soi;
        _my_stream>>_soi;
        setSoi(_soi);

        std::string _tara;
        _my_stream>>_tara;
        setTara(_tara);

        int _an;
        _my_stream>>_an;
        setAn(_an);
    }

	Vin_de_soi(int _cantitate, std::string _soi = "", std::string _tara_de_origine = "")
	{
        unitate_de_masa = getBucata();
        setQuantity(_cantitate);

	}
	~Vin_de_soi()
	{

	}

    void setNume(std::string _nume)
    {
        numele_vinului = _nume;
    }

    void setCuloare(std::string _culoare)
    {
        culoarea_vinului = _culoare;
    }

    void setSoi(std::string _soi)
    {
        soiul_vinului = _soi;
    }

    void setTara(std::string _tara)
    {
        Tara_de_origine = _tara;
    }

    void setAn(int _an)
    {
        an_producere = _an;
    }
};



#endif // VIN_H_INCLUDED
