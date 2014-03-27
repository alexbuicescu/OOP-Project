#include "Varza.h"
#include "Bere.h"
#include "Jucarie.h"
#include <iostream>



Varza::Varza()
{

}

Varza::Varza(std::vector<std::string> proprietati)
{
    try
    {
        setQuantity(atof(proprietati[0].c_str()));
	}
    catch(...)
    {
        setQuantity(0);
    }
	setAlimentPrice(0);

    std::vector<std::string> properties;

    set_price_for_customer_item("varza", properties);

//	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
//	{
////	    Aliment *op = dynamic_cast<Varza*>(magazinul_meu->getAlimentFromStock(i));
//		///daca in stoc am o varza
////		if(op != NULL)
//
////        if(dynamic_cast<Varza*>(magazinul_meu->getAlimentFromStock(i)) != NULL &&
////           dynamic_cast<Bere*>(magazinul_meu->getAlimentFromStock(i)) == NULL && ///Bere mosteneste Varza
////           dynamic_cast<Jucarie*>(magazinul_meu->getAlimentFromStock(i)) == NULL) ///Jucarie mosteneste Varza
//		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "varza")
//		{
////		    std::cout<<"a gasit varza: "<<i<<' '<<magazinul_meu->getAlimentFromStock(i)->getNumeAliment()<<'\n';
//			check_for_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
////            delete op;
//		}
//	}
}

void Varza::setQuantity(int _cantitate)
{
	askedQuantity = _cantitate;
}

int Varza::getQuantity()
{
	return (int)askedQuantity;
}

Varza::~Varza()
{

}

std::ifstream& operator>>(std::ifstream& input_file, Varza *obj)
{
    obj->setUnitateDeMasa(obj->getBucata());
    obj->setNumeAliment("varza");

    double _pret;
    input_file>>_pret;
    obj->setAlimentPrice(_pret);

    double _cost;
    input_file>>_cost;
    obj->setAlimentCost(_cost);

    return input_file;
}
