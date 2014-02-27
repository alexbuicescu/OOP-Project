#ifndef VIN_H_INCLUDED
#define VIN_H_INCLUDED


class Vin : public Varza
{
public:

	Vin(std::string unitatea_de_masa_atasata) : Varza(unitatea_de_masa_atasata)
	{
        unitate_de_masa = unitatea_de_masa_atasata;
	}
	~Vin()
	{

	}
};


#endif // VIN_H_INCLUDED
