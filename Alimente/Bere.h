#ifndef BERE_H_INCLUDED
#define BERE_H_INCLUDED

#include <sstream>
#include <iostream>
#include <fstream>

class Bere : public Varza ///public Aliment, public Mod_de_vanzare
{
private:
    std::string brand = "", tip = ""; ///tip poate fi doar blonda sau bruna
public:

///TO-DO!! - supraincarca >> ca sa citesc Varza, Bere, etc.


//    friend std::istream& operator >> (stdistream &in, Bere *b)
//    {
//        in>>b->brand;
//        return in;
//    }
    Bere(std::vector<std::string> proprietati) : Varza(proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        for(int i = 1; i < proprietati.size(); i++)
        {
            if(proprietati[i] == "blonda" || proprietati[i] == "bruna")
            {
                setTip(proprietati[i]);
            }
            else
            {
                setBrand(proprietati[i]);
            }
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am o bere
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "bere")
            {
                if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getBrand()) != std::string::npos &&
                   magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getTip()) != std::string::npos)
                {
                    set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
                }
            }
        }
    }

    Bere(char _aliment_din_stoc[]) : Varza(_aliment_din_stoc)
    {
	    setUnitateDeMasa(getBucata());
        setNumeAliment("bere");

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        double _cost;
        _my_stream>>_cost;
        setAlimentCost(_cost);

        std::string _brand;
        _my_stream>>_brand;
        setBrand(_brand);

        std::string _tip;
        _my_stream>>_tip;
        setTip(_tip);

        setProprietatiComplet(_brand + " " + _tip);
    }

	~Bere()
	{

	}

	void setBrand(std::string _brand)
	{
	    brand = _brand;
	}

	void setTip(std::string _tip)
	{
	    tip = _tip;
	}

	std::string getBrand()
	{
	    return brand;
	}

	std::string getTip()
	{
	    return tip;
	}
};


#endif // BERE_H_INCLUDED
