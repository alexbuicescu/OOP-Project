#include <iostream>

#include "Magazin.h"
#include "ListaMagazin.h"

#include "Mod_de_vanzare.h"
#include "Aliment.h"
#include "Varza.h"
#include "Bere.h"
#include "Faina.h"
#include "Cartofi.h"
#include "Vin.h"



int main()
{
    Mod_de_vanzare *_unitate = new Mod_de_vanzare();

	Aliment *p = new Varza(12);

	return 0;
}
