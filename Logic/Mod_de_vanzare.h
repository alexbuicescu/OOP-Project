#ifndef MOD_DE_VANZARE_H_INCLUDED
#define MOD_DE_VANZARE_H_INCLUDED


///Prin clasa Mod_de_vanzare voi scrie corect modul prin care se vand alimentele, astfel un aliment se poate vinde doar prin modurile
///implementate aici. Mai mult, se evita astfel problema in care as scrie gresit modul de vanzare pentru fiecare aliment de fiecare data.
class Mod_de_vanzare
{
private:
    std::string bucata, volum, kg;
public:
    Mod_de_vanzare()
    {
        bucata = "bucata";
        volum = "volum";
        kg = "kg";
    }
    ~Mod_de_vanzare()
    {

    }

    std::string getBucata()
    {
        return bucata;
    }
    std::string getVolum()
    {
        return volum;
    }
    std::string getKg()
    {
        return kg;
    }
};

#endif // MOD_DE_VANZARE_H_INCLUDED
