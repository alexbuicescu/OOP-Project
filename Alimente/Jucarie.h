#ifndef JUCARIE_H_INCLUDED
#define JUCARIE_H_INCLUDED


class Jucarie : public Aliment, public Mod_de_vanzare
{
private:
    std::string nume = "";
public:

    Jucarie(std::vector<std::string> proprietati)
    {
        setQuantity(atof(proprietati[0].c_str()));
        setAlimentPrice(-1);

        if(proprietati.size() >= 2)
        {
            setNumeJucarie(proprietati[1]);
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am o jucarie
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "jucarie")
            {
                if(magazinul_meu->getAlimentFromStock(i)->get_proprietati_complet().find(getNumeJucarie()) != std::string::npos)
                {
                    set_most_profitable_price(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//                    std::cout<<"a gasit vin de soi "<<getAlimentPrice()<<'\n';
                }
            }
        }
        std::cout<<"a gasit jucarie "<<getAlimentPrice()<<'\n';
    }

    Jucarie(char _aliment_din_stoc[])
    {
        unitate_de_masa = getBucata();
        nume_aliment = "jucarie";

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        std::string _nume;
        _my_stream>>_nume;
        setNumeJucarie(_nume);

        proprietati_complet = _nume;
    }

	Jucarie(int _cantitate)
	{
        unitate_de_masa = getBucata();
        nume_aliment = "jucarie";

        setQuantity(_cantitate);
	}
	~Jucarie()
	{

	}

	void setNumeJucarie(std::string _nume)
	{
	    nume = _nume;
	}

	std::string getNumeJucarie()
	{
	    return nume;
	}
};


#endif // JUCARIE_H_INCLUDED
