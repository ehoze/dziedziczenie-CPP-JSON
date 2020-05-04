#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;



class TOWAR
{
	public:
	struct muzyka
{
        string tytul, wykonawca;
        int id;
        float cena;
};
	vector <struct muzyka> wektor;
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
//              void wczytajZPliku(const char *);                
};

class MUZYKA : public TOWAR
{
	public:
	void automatyzacja()
	{
		TOWAR::wprowadz();
		TOWAR::wypisz();
		TOWAR::zapiszDoPliku("C:\\Users\\Eryk\\Desktop\\Files\\Programowanie\\dziedziczenieJSON\\x.txt");
		
	}	
};


void TOWAR::wprowadz()
{
        //int iloscTytulow;
        struct muzyka wprowadzana;
        /*cout << "Ilosc tytulow: ";
        cin  >> iloscTytulow;
        for (int i=0; i<iloscTytulow; i++)*/
        {
                cout << "ID Tytul Wykonawca Cena: ";
                cin >> wprowadzana.id
                        >> wprowadzana.tytul
                        >> wprowadzana.wykonawca
                        >> wprowadzana.cena;
                wektor.push_back(wprowadzana); //TU WSTAW do tablicy nowy rekord
        }
}


void TOWAR::wypisz()
{
        for (vector<struct muzyka>::iterator it = wektor.begin(); it != wektor.end(); ++it)
        {
                cout << it->id << " "
                         << it->tytul << " "
                         << it->wykonawca << " "
						 << it->cena << "\n";
        }
}



void TOWAR::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct muzyka>::iterator it = wektor.begin(); it != wektor.end(); ++it)
        {
                plik << "[\n" << "  { \"numer\" : \""
						 << it->id << "\" }\n" // wprowadzenie numeru plyty w sklepie ((id))
                         << "  { \"tytul\" : \"" << it->tytul << "\" }\n" // wprowadzenie tytulu plyty w sklepie
                         << "  { \"wykonawca\" : \"" << it->wykonawca << "\" }\n"
						 << "  { \"cena\" : \"" << it->cena << "zl\" }\n]"; // wprowadzenie wykonawcy plyty w sklepie
        }	
        plik.close();  
}



int main(int argc, char** argv) {
        MUZYKA M;
        M.automatyzacja();
        return 0;
}
