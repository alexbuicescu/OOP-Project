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
    std::string soi_rosu_sec = "rosu_sec", soi_alb_sec = "alb_sec";
public:

    Vin_varsat(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        for(int i = 1; i < proprietati.size(); i++)
        {
            if(proprietati[i] == "rosu" || proprietati[i] == "alb")
            {
                setCuloare(proprietati[i]);
//                culoarea_vinului = proprietati[i];
            }
            else
            if(proprietati[i] == "sec" || proprietati[i] == "dulce")
            {
                setSoi(proprietati[i]);
//                soiul_vinului = proprietati[i];
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
                    set_most_profitable_price(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//                    std::cout<<"a gasit vin varsat "<<getAlimentPrice()<<'\n';
                }
            }
        }
//        std::cout<<"a gasit vin varsat "<<getAlimentPrice()<<'\n';
    }

    Vin_varsat(char _aliment_din_stoc[])
    {
        unitate_de_masa = getVolum();
        nume_aliment = "vin_varsat";

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

        proprietati_complet = _culoare + " " + _soi;
    }

	Vin_varsat(int _cantitate)
	{
        unitate_de_masa = getVolum();
        nume_aliment = "vin_varsat";

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

	std::string getSoi()
	{
	    return soiul_vinului;
	}

	std::string getCuloare()
	{
	    return culoarea_vinului;
	}
};

class Vin_de_soi : public Aliment, public Mod_de_vanzare
{
private:
    std::string numele_vinului = "";
    std::string culoarea_vinului = "";
    std::string soiul_vinului = "";
    std::string Tara_de_origine = "";
    int an_producere = 0;

public:

    Vin_de_soi(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        for(int i = 1; i < proprietati.size(); i++)
        {
            if(proprietati[i] == "rosu" || proprietati[i] == "alb")
            {
                culoarea_vinului = proprietati[i];
            }
            else
            if(proprietati[i] == "sec" || proprietati[i] == "dulce")
            {
                soiul_vinului = proprietati[i];
            }
            else
            if(proprietati[i][0] >= '0' && proprietati[i][0] <= '9')
            {
                an_producere = atoi(proprietati[i].c_str());
            }
            else
            if(proprietati[i] == "Franta" || proprietati[i] == "Argentina" || proprietati[i] == "Chile" || proprietati[i] == "Australia")
            {
                Tara_de_origine = proprietati[i];
            }
            else
            ///numele vinului e singurul care a mai putut ramane
            {
                numele_vinului = proprietati[i];
            }
        }
        std::string an = "";
        if(an_producere != 0)
        {
            an = ToString(an_producere);
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am un vin
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "vin_de_soi")
            {
                if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(numele_vinului) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(an) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(soiul_vinului) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(culoarea_vinului) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(Tara_de_origine) != std::string::npos)
                {
                    set_most_profitable_price(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//                    std::cout<<"a gasit vin de soi "<<getAlimentPrice()<<'\n';
                }
            }
        }
//        std::cout<<"'"<<numele_vinului<<"' "<<"'"<<an_producere<<"' "<<"'"<<numele_vinului<<"' "<<"'"<<numele_vinului<<"' "<<"'"<<numele_vinului<<'\n';
//        std::cout<<"a gasit vin de soi "<<getAlimentPrice()<<'\n';
    }

    Vin_de_soi(char _aliment_din_stoc[])
    {
        unitate_de_masa = getBucata();
        nume_aliment = "vin_de_soi";

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string _nume;
        _my_stream>>_nume;
        setNumeVin(_nume);

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

        proprietati_complet = _nume + " " + _culoare + " " + _soi + " " + _tara + " " + ToString(_an);
    }

	Vin_de_soi(int _cantitate, std::string _soi = "", std::string _tara_de_origine = "")
	{
        unitate_de_masa = getBucata();
        nume_aliment = "vin_de_soi";
        setQuantity(_cantitate);

	}
	~Vin_de_soi()
	{

	}

    void setNumeVin(std::string _nume)
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

    std::string getNumeVin()
    {
        return numele_vinului;
    }

    std::string getCuloare()
    {
        return culoarea_vinului;
    }

    std::string getSoi()
    {
        return soiul_vinului;
    }

    std::string getTara()
    {
        return Tara_de_origine;
    }

    int getAn()
    {
        return an_producere;
    }
};



class Vin
{
private:
    std::string culoare = "", soi = "", tara = "", an = "", nume = "";
public:

    Vin(std::string proprietati[], int _size)
    {
        for(int i = 0; i < _size; i++)
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
//            else
//            if(proprietati[i] == "sec" || proprietati[i] == "dulce")
//            {
//                setSoi(proprietati[i]);
//            }
        }
    }

    void setCuloare(std::string _culoare)
    {
        culoare = _culoare;
    }
    void setSoi(std::string _soi)
    {
        soi = _soi;
    }
    void setTara(std::string _tara)
    {
        tara = _tara;
    }
    void setAn(std::string _an)
    {
        an = _an;
    }
    void setNume(std::string _nume)
    {
        nume = _nume;
    }

    Aliment* get_cel_mai_ieftin_vin(std::vector<std::string> proprietati)
    {
        Aliment *p1 = new Vin_varsat(proprietati);
        Aliment *p2 = new Vin_de_soi(proprietati);

        if(p1->getAlimentPrice() < p2->getAlimentPrice())
        {
            delete p1;
            return p2;
        }
        delete p2;
        return p1;
    }

    Vin_de_soi* get_cel_mai_ieftin_soi()
    {
//        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
//        {
//            return (Vin_de_soi*)magazinul_meu->getAlimentFromStock(i);
//        }
    }

    Vin_varsat* get_cel_mai_ieftin_varsat()
    {
//        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
//        {
//            return (Vin_varsat*)magazinul_meu->getAlimentFromStock(i);
//        }
    }
};


#endif // VIN_H_INCLUDED
