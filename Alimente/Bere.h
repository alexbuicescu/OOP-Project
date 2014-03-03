#ifndef BERE_H_INCLUDED
#define BERE_H_INCLUDED

#include <sstream>
#include <iostream>
#include <fstream>

class Bere : public Aliment, public Mod_de_vanzare
{
private:
    std::string brand, tip; ///tip poate fi doar blonda sau bruna
    std::string tip_blonda = "blonda", tip_bruna = "bruna";
public:

///TO-DO!! - supraincarca >> ca sa citesc Varza, Bere, etc.


//    friend std::istream& operator >> (stdistream &in, Bere *b)
//    {
//        in>>b->brand;
//        return in;
//    }

    Bere(char _aliment_din_stoc[])
    {
	    unitate_de_masa = getBucata();

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string _brand;
        _my_stream>>_brand;
        setBrand(_brand);

        std::string _tip;
        _my_stream>>_tip;
        setTip(_tip);
    }

	Bere(int _cantitate, std::string _brand, std::string _tip)
	{
	    unitate_de_masa = getBucata();
	    brand = _brand;

	    if(_tip == tip_blonda || _tip == tip_bruna)
	    {
	        tip = _tip;
	    }
	    else
        {
            ///Throw an exception here !!! TO-DO
        }

        setQuantity(_cantitate);
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
};


#endif // BERE_H_INCLUDED
