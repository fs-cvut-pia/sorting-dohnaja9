#include "trideni.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <exception>
#include <vector>
#include <stdexcept>
#include <stdio.h>

using namespace std;

void nacti (string nazev, seznam_slov & jmena)
{
  	ifstream soubor ;
  	soubor.open(nazev.c_str());
  	
	string radek;

   	while(std::getline(soubor, radek))
   	{
   		jmena.push_back(radek);
	}
   	soubor.close();     	 	
  	
}

void serad(seznam_slov & jmena)
{
	string tmp;
	bool bylo_prohozeno;
	do
	{
		bylo_prohozeno = false;
		for (int i =1; i<jmena.size();++i)
		{
			if(jmena[i].compare(jmena[i-1])<0)
			{
				tmp= jmena[i];
				jmena[i]= jmena[i-1];
				jmena[i-1]=tmp;
				bylo_prohozeno = true;
			}
		}
	} while (bylo_prohozeno);
}

bool zeptej_se_jestli_vypsat()
{
	std::string vypsat;
	cout << "Chcete vypsat seznam? (Ano/Ne)" << endl;
	cin >> vypsat;
	if(vypsat == "ANO" || vypsat == "ano" || vypsat == "Ano" || vypsat == "a"|| vypsat == "A")
		return 1;
	return 0;
}

void vypis(seznam_slov const& jmena)
{
	for (int i=0; i<jmena.size();++i)
	{
		cout << jmena[i] << endl;
	}
}
