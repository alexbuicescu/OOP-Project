#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>

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
double pret_maxim = -1;

void get_proprietati_aliment(char aliment[], std::vector<std::string> &proprietati);
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

///in proprietati[0] se va afla mereu cantitatea dorita
void get_proprietati_aliment(char aliment[], std::vector<std::string> &prop)
{
    std::string proprietate = "";
    int k = 0;
    ///vad care este prima pozitie pe care nu se afla un spatiu
    for(k = 0; k < strlen(aliment); k++)
    {
        if(aliment[k] != ' ')
        {
            break;
        }
    }
    for(int i = k; i < strlen(aliment); i++)
    {
        if(aliment[i] != ' ' && i != strlen(aliment) - 1)
        {
            proprietate += aliment[i]; ///change to .append TO-DO!!!
            continue;
        }
        else
            if(i == strlen(aliment) - 1)
            {
                proprietate += aliment[i]; ///change to .append TO-DO!!!
            }

        prop.push_back(proprietate);
        proprietate = "";
    }
//    std::cout<<aliment<<'\n';
//    for(int i = 0; i < proprietati.size(); i++)
//    {
//        std::cout<<"'"<<proprietati[i]<<"'"<<'\n';
//    }
//    std::cout<<'\n';
}

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

        if(pret_maxim == -1)
        {
            pret_maxim = _aliment->getAlimentPrice();
        }
        else
            if(pret_maxim < _aliment->getAlimentPrice())
            {
                pret_maxim = _aliment->getAlimentPrice();
            }
    }
    pret_maxim++;
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

//        double _cantitate = 0;
//        fin>>_cantitate;

        ///citesc care sunt alimentele pe care le vrea cumparatorul
        while(numele_alimentului != "next" && numele_alimentului != "stop" && numele_alimentului != "")
        {
            ///citesc proprietatile alimentului (calitate, an productie, etc.)
            fin.getline(rand_citit, 1000);

            std::vector<std::string> proprietati;
            get_proprietati_aliment(rand_citit, proprietati);

            Aliment *_aliment_curent;

            if(numele_alimentului == "varza")
            {
//                _cantitate = atof(rand_citit);
                _aliment_curent = new Varza(proprietati);
            }
            else
            if(strstr(numele_alimentului.c_str(), "vin"))
            {
                if(numele_alimentului == "vin_varsat")
                {
                    _aliment_curent = new Vin_varsat(proprietati);
                }
                else
                if(numele_alimentului == "vin_de_soi")
                {
                    _aliment_curent = new Vin_de_soi(proprietati);
                }
            }
            else
            if(numele_alimentului == "faina")
            {
                _aliment_curent = new Faina(proprietati);
            }
            else
            if(numele_alimentului == "bere")
            {
                _aliment_curent = new Bere(proprietati);
            }
            else
            if(numele_alimentului == "jucarie")
            {
                _aliment_curent = new Jucarie(proprietati);
            }
            else
            if(numele_alimentului == "cartof")
            {
                _aliment_curent = new Cartof(proprietati);
            }

            fin>>numele_alimentului;

            if(numele_alimentului != "next" && numele_alimentului != "stop" && numele_alimentului != "")
            {
//                fin>>_cantitate;
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
