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
        setAlimentPrice(pret_maxim);

        if(proprietati.size() >= 2)
        {
            setNume(proprietati[1]);
        }

        for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
        {
            ///daca in stoc am o jucarie
            if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "jucarie")
            {
                ///daca cumparatorul vrea o anumita jucarie
                if(getNume() != "")
                {
                    ///daca i-am gasit jucaria, o iau pe cea mai ieftina
                    if(getNume() == ((Jucarie*)(magazinul_meu->getAlimentFromStock(i)))->getNume())
                    {
                        if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
                        {
                            setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
                        }
                        std::cout<<"a gasit jucaria cu numele: "<<getNume()<<'\n';
                    }
                }
                else
                ///daca cumparatorul nu a dat un nume, iau cea mai ieftina jucarie posibila
                {
                    if(getAlimentPrice() > magazinul_meu->getAlimentFromStock(i)->getAlimentPrice())
                    {
                        setAlimentPrice(magazinul_meu->getAlimentFromStock(i)->getAlimentPrice());
                    }
                }
            }
        }
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
        setNume(_nume);
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

	void setNume(std::string _nume)
	{
	    nume = _nume;
	}

	std::string getNume()
	{
	    return nume;
	}
};


#endif // JUCARIE_H_INCLUDED
