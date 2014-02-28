#ifndef BERE_H_INCLUDED
#define BERE_H_INCLUDED

class Bere : public Aliment, public Mod_de_vanzare
{
private:
    std::string brand, tip; ///tip poate fi doar blonda sau bruna
    std::string tip_blonda = "blonda", tip_bruna = "bruna";
public:

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
};


#endif // BERE_H_INCLUDED
