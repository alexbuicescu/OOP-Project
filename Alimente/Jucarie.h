#ifndef JUCARIE_H_INCLUDED
#define JUCARIE_H_INCLUDED


class Jucarie : public Varza/// public Aliment, public Mod_de_vanzare
{
private:
    std::string nume_jucarie = "";
public:

    Jucarie(std::vector<std::string> proprietati) : Varza(proprietati)
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
                    set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
                }
            }
        }
    }

    Jucarie(char _aliment_din_stoc[]) : Varza(_aliment_din_stoc)
    {
        setUnitateDeMasa(getBucata());
        setNumeAliment("jucarie");

        std::stringstream _my_stream;
        _my_stream<<_aliment_din_stoc;

        double _pret;
        _my_stream>>_pret;
        setAlimentPrice(_pret);

        double _cost;
        _my_stream>>_cost;
        setAlimentCost(_cost);

        std::string _nume;
        _my_stream>>_nume;
        setNumeJucarie(_nume);

        setProprietatiComplet(_nume);
    }

	~Jucarie()
	{

	}

	void setNumeJucarie(std::string _nume_jucarie)
	{
	    ///Verifica daca nu cumva mai exista numele TO-DO!!
	    nume_jucarie = _nume_jucarie;
	}

	std::string getNumeJucarie()
	{
	    return nume_jucarie;
	}
};


#endif // JUCARIE_H_INCLUDED
