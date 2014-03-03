#ifndef JUCARIE_H_INCLUDED
#define JUCARIE_H_INCLUDED


class Jucarie : public Aliment, public Mod_de_vanzare
{
private:
    std::string nume;
public:

    Jucarie(char _aliment_din_stoc[])
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
    }

	Jucarie(int _cantitate)
	{
        unitate_de_masa = getBucata();

        setQuantity(_cantitate);
	}
	~Jucarie()
	{

	}

	void setNume(std::string _nume)
	{
	    nume = _nume;
	}
};


#endif // JUCARIE_H_INCLUDED
