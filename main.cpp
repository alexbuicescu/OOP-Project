#include <iostream>
#include <fstream>
#include <cstring>

#include "Magazin.h"
#include "ListaMagazin.h"

#include "Mod_de_vanzare.h"
#include "Aliment.h"
#include "Varza.h"
#include "Bere.h"
#include "Faina.h"
#include "Cartof.h"
#include "Vin.h"
#include "Jucarie.h"

std::ifstream fin("cumparator.txt");

Magazin *magazinul_meu = new Magazin();




std::string char_to_string(char _cuvant[])
{
    std::string _cuvant_nou = "";
    for(int i = 0; i < strlen(_cuvant); i++)
    {
        _cuvant_nou += _cuvant[i];
    }
    return _cuvant_nou;
}

void parse_numele_alimentului(std::string _aliment)
{

}

void add_produse_valabile_din_stoc(std::string _nume_fisier_intrare)
{
    char rand_citit[1000];
    std::string _val = "";
    std::ifstream cit(_nume_fisier_intrare.c_str());

    while(cit>>_val)
    {
        cit.getline(rand_citit, 1000);
        Aliment *_aliment;

        if(_val == "varza")
        {
            _aliment = new Varza(rand_citit);
        }
        else
        if(_val == "faina")
        {
            _aliment = new Faina(rand_citit);
        }
        else
        if(_val == "bere")
        {
            _aliment = new Bere(rand_citit);
        }
        else
        if(_val == "vin_varsat")
        {
            _aliment = new Vin_varsat(rand_citit);
        }
        else
        if(_val == "vin_de_soi")
        {
            _aliment = new Vin_de_soi(rand_citit);
        }
        else
        if(_val == "cartofi")
        {
            _aliment = new Cartof(rand_citit);
        }
        else
        if(_val == "jucarie")
        {
            _aliment = new Jucarie(rand_citit);
        }

        magazinul_meu->add_in_stoc(_aliment);
    }
}

int main()
{
    add_produse_valabile_din_stoc("alimente_stoc.txt");

    std::string action = "";

    char rand_citit[1000];
    fin.getline(rand_citit, 1000);

    action = char_to_string(rand_citit);

//    Bere p(1, "asd", "Asdas");
//    std::cin>>p;

//    while(action != "stop")
//    {
//        std::string numele_alimentului = "";
//        fin.getline(rand_citit, 1000);
//        while(numele_alimentului != "")
//        {
//            parse_numele_alimentului(numele_alimentului);
//
//
//            fin.getline(rand_citit, 1000);
//            numele_alimentului = char_to_string(rand_citit);
//        }
//
//
////        std::cout<<action<<'\n'<<numele_alimentului<<'\n';
//
//
//        fin.getline(rand_citit, 1000);
//        action = char_to_string(rand_citit);
//    }

    delete magazinul_meu;
	return 0;
}
