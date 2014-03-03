#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

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

Magazin *magazinul_meu = new Magazin();

int char_to_nr(char _cuvant[]);
int char_to_nr(std::string _cuvant);
std::string char_to_string(char _cuvant[]);
void parse_numele_alimentului(std::string _aliment);
void add_produse_valabile_din_stoc(std::string _nume_fisier_intrare);
void serveste_clienti();
void deschide_magazin();
void inchide_magazin();

int main()
{
    deschide_magazin();
    inchide_magazin();

	return 0;
}


//int char_to_nr(char _cuvant[])
//{
//    int nr = 0;
//    for(int i = 0; i < strlen(_cuvant); i++)
//    {
//        if(_cuvant[i] >= '0' && _cuvant[i] <= '9')
//        {
//            nr = 10 * nr + rand_citit[i] - '0';
//        }
//    }
//    return nr;
//}
//
//double char_to_nr(std::string _cuvant)
//{
//    double nr = 0;
//    for(int i = 0; i < _cuvant.size(); i++)
//    {
//        if(_cuvant[i] >= '0' && _cuvant[i] <= '9')
//        {
//            nr = 10 * nr + rand_citit[i] - '0';
//        }
//    }
//    return nr;
//}

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

void serveste_clienti(std::string _nume_fisier_intrare)
{
    std::ifstream fin(_nume_fisier_intrare.c_str());

    std::string action = "";

    char rand_citit[1000];
//    fin.getline(rand_citit, 1000);
//
//    action = char_to_string(rand_citit);

    fin>>action;
    while(action != "stop")
    {
        std::string numele_alimentului = "";
        fin>>numele_alimentului;

        double _cantitate = 0;
        fin>>_cantitate;

        ///citesc care sunt alimentele pe care le vrea cumparatorul
        while(numele_alimentului != "next" && numele_alimentului != "stop" && numele_alimentului != "")
        {
            ///citesc proprietatile alimentului (calitate, an productie, etc.)
            fin.getline(rand_citit, 1000);
            Aliment *_aliment_curent;

            if(numele_alimentului == "varza")
            {
                _cantitate = atof(rand_citit);
                _aliment_curent = new Varza(_cantitate);
            }
            else
            if(strstr(numele_alimentului.c_str(), "vin"))
            {
                std::string proprietati[6];
                int k = 0;
                for(int i = 0; i < strlen(rand_citit); i++)
                {
                    if(rand_citit[i] != ' ')
                    {
                        proprietati[k] += rand_citit[i];
                    }
                    else
                    {
                        k++;
                    }
                }

                if(numele_alimentului == "vin_varsat")
                {

                }
                else
                if(numele_alimentului == "vin_de_soi")
                {

                }
            }

            fin>>numele_alimentului;

            if(numele_alimentului != "next" && numele_alimentului != "stop" && numele_alimentului != "")
            {
                fin>>_cantitate;
            }
        }

        if(numele_alimentului != "next")
        {
            fin>>action;
        }
        else
        {
            action = "next";
        }
    }


}

void deschide_magazin()
{
    add_produse_valabile_din_stoc("alimente_stoc.txt");
    serveste_clienti("cumparator.txt");
}

void inchide_magazin()
{

    delete magazinul_meu;
}
