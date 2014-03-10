#ifndef VIN_H_INCLUDED
#define VIN_H_INCLUDED

#include <sstream>
#include "Values.h"
#include "Aliment.h"
#include "Mod_de_vanzare.h"


class Vin_varsat : public Aliment, public Mod_de_vanzare
{
private:
    std::string culoarea_vinului = "", soiul_vinului = "";
public:

    Vin_varsat()
    {

    }

    Vin_varsat(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        ///setez proprietatile alimentului
        for(int i = 1; i < proprietati.size(); i++)
        {
            if(proprietati[i] == "rosu" || proprietati[i] == "alb")
            {
                setCuloare(proprietati[i]);
            }
            else
            if(proprietati[i] == "sec" || proprietati[i] == "dulce")
            {
                setSoi(proprietati[i]);
            }
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am un vin
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "vin_varsat")
            {
                if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getCuloare()) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getSoi()) != std::string::npos)
                {
                    set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
                }
            }
        }
    }

	~Vin_varsat()
	{

	}

	void setCuloare(std::string _culoarea_vinului)
	{
	    culoarea_vinului = _culoarea_vinului;
	}

	std::string getCuloare()
	{
	    return culoarea_vinului;
	}

	void setSoi(std::string _soiul_vinului)
	{
	    soiul_vinului = _soiul_vinului;
	}

	std::string getSoi()
	{
	    return soiul_vinului;
	}

    friend std::ifstream& operator>>(std::ifstream& input_file, Vin_varsat *obj);
};
std::ifstream& operator>>(std::ifstream& input_file, Vin_varsat *obj)
{
    obj->setUnitateDeMasa(obj->getVolum());
    obj->setNumeAliment("vin_varsat");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _culoare;
    input_file>>_culoare;
    obj->setCuloare(_culoare);

    std::string _soi;
    input_file>>_soi;
    obj->setSoi(_soi);

    obj->setProprietatiComplet(_culoare + " " + _soi);
    return input_file;
}

class Vin_de_soi : public Vin_varsat
{
private:
    std::string numele_vinului = "", Tara_de_origine = "";
    int an_producere = 0;
public:

    Vin_de_soi()
    {

    }

    Vin_de_soi(std::vector<std::string> proprietati) : Vin_varsat(proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        ///setez proprietatile alimentului
        for(int i = 1; i < proprietati.size(); i++)
        {
            if(proprietati[i] == "rosu" || proprietati[i] == "alb")
            {
                setCuloare(proprietati[i]);
            }
            else
            if(proprietati[i] == "sec" || proprietati[i] == "dulce")
            {
                setSoi(proprietati[i]);
            }
            else
            if(proprietati[i][0] >= '0' && proprietati[i][0] <= '9')
            {
                setAn(atoi(proprietati[i].c_str()));
            }
            else
            if(proprietati[i] == "Franta" || proprietati[i] == "Argentina" || proprietati[i] == "Chile" || proprietati[i] == "Australia")
            {
                setTara(proprietati[i]);
            }
            else
            ///numele vinului e singurul care a mai putut ramane
            {
                setNumeVin(proprietati[i]);
            }
        }

        ///daca anul nu mi s-a dat, atunci cand caut vinul cel mai bun, o sa omit compararea anului, facand anul "" (nu 0)
        std::string an = "";
        if(getAn() != 0)
        {
            an = ToString(getAn());
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am un vin
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "vin_de_soi")
            {
                if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getNumeVin()) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(an) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getSoi()) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getCuloare()) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getTara()) != std::string::npos)
                {
                    set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
                }
            }
        }
    }

	~Vin_de_soi()
	{

	}

    void setNumeVin(std::string _nume)
    {
        numele_vinului = _nume;
    }

    std::string getNumeVin()
    {
        return numele_vinului;
    }

    void setTara(std::string _tara)
    {
        Tara_de_origine = _tara;
    }

    std::string getTara()
    {
        return Tara_de_origine;
    }

    void setAn(int _an)
    {
        an_producere = _an;
    }

    int getAn()
    {
        return an_producere;
    }

	void setQuantity(int _cantitate)
	{
	    askedQuantity = _cantitate;
	}

	int getQuantity()
	{
	    return (int)askedQuantity;
	}

    friend std::ifstream& operator>>(std::ifstream& input_file, Vin_de_soi *obj);
};
std::ifstream& operator>>(std::ifstream& input_file, Vin_de_soi *obj)
{
    obj->setUnitateDeMasa(obj->getBucata());
    obj->setNumeAliment("vin_de_soi");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    std::string _nume;
    input_file>>_nume;
    obj->setNumeVin(_nume);

    std::string _culoare;
    input_file>>_culoare;
    obj->setCuloare(_culoare);

    std::string _soi;
    input_file>>_soi;
    obj->setSoi(_soi);

    std::string _tara;
    input_file>>_tara;
    obj->setTara(_tara);

    int _an;
    input_file>>_an;
    obj->setAn(_an);

    obj->setProprietatiComplet(_nume + " " + _culoare + " " + _soi + " " + _tara + " " + ToString(_an));
    return input_file;
}


#endif // VIN_H_INCLUDED
