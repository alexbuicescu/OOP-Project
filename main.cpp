#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
//#include <windows.h>//include <unistd.h> - unix

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

Aliment* get_cel_mai_ieftin_vin(std::vector<std::string> proprietati)
{
    Aliment *p1 = new Vin_varsat(proprietati);
    Aliment *p2 = new Vin_de_soi(proprietati);

    ///daca vinul varsat are un profit mai mic, atunci iau vinul de soi
    if(p1->getAlimentPrice() < p2->getAlimentPrice())
    {
        delete p1;
        return p2;
    }
    delete p2;
    return p1;
}

void add_produse_valabile_din_stoc(std::string _nume_fisier_intrare)
{
    char rand_citit[1000];
    std::string _nume_aliment = "";
    std::ifstream fin(_nume_fisier_intrare.c_str());

    while(fin>>_nume_aliment)
    {
        fin.getline(rand_citit, 1000);
        Aliment *_aliment;

        if(_nume_aliment == "varza")
        {
            _aliment = new Varza(rand_citit);
        }
        else
        if(_nume_aliment == "faina")
        {
            _aliment = new Faina(rand_citit);
        }
        else
        if(_nume_aliment == "bere")
        {
            _aliment = new Bere(rand_citit);
        }
        else
        if(_nume_aliment == "vin_varsat")
        {
            _aliment = new Vin_varsat(rand_citit);
        }
        else
        if(_nume_aliment == "vin_de_soi")
        {
            _aliment = new Vin_de_soi(rand_citit);
        }
        else
        if(_nume_aliment == "cartofi")
        {
            _aliment = new Cartof(rand_citit);
        }
        else
        if(_nume_aliment == "jucarie")
        {
            _aliment = new Jucarie(rand_citit);
        }

        magazinul_meu->add_in_stoc(_aliment);

        if(pret_maxim < _aliment->getAlimentPrice())
        {
            pret_maxim = _aliment->getAlimentPrice();
        }
    }

    ///salvez si pretul maxim
    pret_maxim = (int)pret_maxim + 2;
}

void loopUntilRead(std::string path, std::string string_to_compare)
{
    std::string readed_string = "";
    while(readed_string != string_to_compare)
    {
        std::ifstream fin(path.c_str());
        fin>>readed_string;
//                Sleep(1000); //usleep(1000) - unix
    }
    std::ofstream fout2(path.c_str());
    fout2<<"";
    fout2.close();
}

std::string loopUntilRead(std::string path, std::string string_to_compare1, std::string string_to_compare2)
{
    std::string readed_string = "";
    while(readed_string != string_to_compare1 && readed_string != string_to_compare2)
    {
        std::ifstream fin(path.c_str());
        fin>>readed_string;
//                Sleep(1000); //usleep(1000) - unix
    }
    std::ofstream fout2(path.c_str());
    fout2<<"";
    fout2.close();

    return readed_string;
}

void serveste_clienti(std::string _nume_fisier_intrare)
{
    ///asteapta pana cand introduce primul client lista de cumparaturi
    loopUntilRead("decizie cumparator.txt", "next");

    std::string action = "next";

    while(action != "stop")
    {
        std::ifstream fin(_nume_fisier_intrare.c_str());

        fin>>action;

        char rand_citit[1000];

        std::string numele_alimentului = "";
        fin>>numele_alimentului;

        ///citesc care sunt alimentele pe care le vrea cumparatorul
        while(numele_alimentului != "finish")
        {
            ///citesc proprietatile alimentului (calitate, an productie, etc.)
            fin.getline(rand_citit, 1000);
            std::vector<std::string> proprietati;
            magazinul_meu->get_proprietati_aliment(rand_citit, proprietati);


            Aliment *_aliment_curent;

            if(numele_alimentului == "varza")
            {
                _aliment_curent = new Varza(proprietati);
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
            else
            if(numele_alimentului == "vin")
            {
                _aliment_curent = get_cel_mai_ieftin_vin(proprietati);
            }
            else
            if(numele_alimentului == "vin_varsat")
            {
                _aliment_curent = new Vin_varsat(proprietati);
            }
            else
            if(numele_alimentului == "vin_de_soi")
            {
                _aliment_curent = new Vin_de_soi(proprietati);
            }
            magazinul_meu->add_in_lista_client(_aliment_curent);

            fin>>numele_alimentului;
        }
        if(numele_alimentului == "finish")
        {
            ///afisez pretul corespunzator listei de cumparaturi a clientului
            std::ofstream fout_pret_client("pret client curent.txt");
            fout_pret_client<<magazinul_meu->getPretTotalClient();
            fout_pret_client.close();

            ///vad daca clientul doreste sa cumpere sau nu
            std::string _decizie = loopUntilRead("decizie cumparator.txt", "da", "nu");

            if(_decizie == "da")
            {
                std::cout<<"am vandut tot"<<'\n';
                magazinul_meu->Sell_all_items_from_list();
            }
            else
            {
                std::cout<<"nu am vandut nimic"<<'\n';
            }
            magazinul_meu->Remove_all_items_from_list_client();
        }

        ///astept pana cand apare un client nou, sau pana trebuie sa inchid ziua
        action = loopUntilRead("decizie cumparator.txt", "next", "stop");

        if(action == "next")
        {
            std::cout<<'\n'<<"clientul urmator"<<'\n'<<'\n';
        }

        std::ofstream fout5("pret client curent.txt");
        fout5<<"";
        fout5.close();

        fin.close();
    }
    magazinul_meu->inchide_ziua();
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
