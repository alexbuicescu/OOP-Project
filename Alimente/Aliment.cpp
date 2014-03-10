//#include "Aliment.h"
//
//Aliment::Aliment()
//{
//	price = 0;
//	askedQuantity = 0;
//	soldQuantity = 0;
//	unitate_de_masa = "";
//}
//
//Aliment::~Aliment()
//{
//
//}
//
//void Aliment::setAlimentPrice(double _price)
//{
//	price = _price;
//}
//
//double Aliment::getAlimentPrice()
//{
//	return price;
//}
//
//void Aliment::setAlimentCost(double _cost)
//{
//	cost = _cost;
//}
//
//double Aliment::getAlimentCost()
//{
//	return cost;
//}
//
//virtual void Aliment::setQuantity(double _cantitate)
//{
//	askedQuantity = _cantitate;
//}
//
//double Aliment::getQuantity()
//{
//	return askedQuantity;
//}
//
//void Aliment::setNumeAliment(std::string _nume_aliment)
//{
//	nume_aliment = _nume_aliment;
//}
//
//std::string Aliment::getNumeAliment()
//{
//	return nume_aliment;
//}
//
//void Aliment::setSoldQuantity(double _soldQuantity)
//{
//	soldQuantity += _soldQuantity;
//}
//
//double Aliment::getSoldQuantity()
//{
//	return soldQuantity;
//}
//
//void Aliment::setProprietatiComplet(std::string _proprietati_complet)
//{
//	///inlocuiesc mai intai toate spatiile cu _
//	for(int i = 0; i < _proprietati_complet.size(); i++)
//	{
//		if(_proprietati_complet[i] == ' ')
//		{
//			_proprietati_complet[i] = '_';
//		}
//	}
//
//	proprietati_complet = _proprietati_complet;
//}
//
//std::string Aliment::get_proprietati_complet()
//{
//	return proprietati_complet;
//}
//
//void Aliment::setUnitateDeMasa(std::string _unitate_de_masa)
//{
//	unitate_de_masa = _unitate_de_masa;
//}
//
//std::string Aliment::getUnitateDeMasa()
//{
//	return unitate_de_masa;
//}
//
//void Aliment::setIndiceAlimentDinStoc(int _indice_aliment_din_stoc)
//{
//	indice_aliment_din_stoc = _indice_aliment_din_stoc;
//}
//
//int Aliment::getIndiceAlimentDinStoc()
//{
//	return indice_aliment_din_stoc;
//}
//
/////retin care este cantitatea ceruta de cumparator, si returnez pretul pentru aceasta cantitate
//double Aliment::getAlimentPriceByQuantity()
//{
//	return (double) askedQuantity * price;
//}
//
//void Aliment::set_most_profitable_price(int _indice_aliment_din_stoc, double product_price, double product_cost)
//{
//	if(getAlimentPrice() != -1)
//	{
//		if(getAlimentPrice() - getAlimentCost() < product_price - product_cost)
//		{
//			setAlimentPrice(product_price);
//			setAlimentCost(product_cost);
//			setIndiceAlimentDinStoc(_indice_aliment_din_stoc);
//		}
//	}
//	else
//	{
//		setAlimentPrice(product_price);
//		setAlimentCost(product_cost);
//		setIndiceAlimentDinStoc(_indice_aliment_din_stoc);
//	}
//}
