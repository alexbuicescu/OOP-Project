//#include "Varza.h"
//
//
//
//Varza::Varza()
//{
//
//}
//
//Varza::Varza(std::vector<std::string> proprietati)
//{
//	setQuantity(atof(proprietati[0].c_str()));
//	setAlimentPrice(-1);
//
//	for(int i = 0; i < magazinul_meu->size_of_lista_stoc(); i++)
//	{
//		///daca in stoc am o varza
//		if(magazinul_meu->getAlimentFromStock(i)->getNumeAliment() == "varza")
//		{
//			set_most_profitable_price(i, magazinul_meu->getAlimentFromStock(i)->getAlimentPrice(), magazinul_meu->getAlimentFromStock(i)->getAlimentCost());
//		}
//	}
//}
//
//void Varza::setQuantity(int _cantitate)
//{
//	askedQuantity = _cantitate;
//}
//
//int Varza::getQuantity()
//{
//	return (int)askedQuantity;
//}
//
//Varza::~Varza()
//{
//
//}