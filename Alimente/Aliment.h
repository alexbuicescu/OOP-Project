#ifndef ALIMENT_H_INCLUDED
#define ALIMENT_H_INCLUDED


class Aliment
{
private:
    ///price - este pretul alimentului
    ///askedQuantity - este cantitatea pe care o cere cumparatorul inainte sa se decida
    ///soldQuantity - este cantitatea pe care magazionerul o vinde cumparatorului
	double price = 0, askedQuantity = 0, soldQuantity = 0;

protected:
    ///unitate_de_masa - reprezinta modalitatea prin care se vinde alimentul (la bucata, kg, volum, etc.)
    std::string unitate_de_masa = "", nume_aliment = "";

public:
    ///initializez cu 0 toate datele mele
	Aliment()
	{
		price = 0;
		askedQuantity = 0;
		soldQuantity = 0;
		unitate_de_masa = "";
	}

	~Aliment()
	{

	}

	void setAlimentPrice(double _price)
	{
	    price = _price;
	}

	void setQuantity(double _cantitate)
	{
	    askedQuantity = _cantitate;
	}

    ///returnez pretul alimentului
	double getAlimentPrice()
	{
	    return price;
	}

	///retin care este cantitatea ceruta de cumparator, si returnez pretul pentru aceasta cantitate
	double getAlimentPriceByQuantity()
	{
	    return (double) askedQuantity * price;
	}

	std::string getNumeAliment()
	{
	    return nume_aliment;
	}
};

#endif // ALIMENT_H_INCLUDED
