/****************************/
/*													*/
/*		Projekt 1 						*/
/*		Ondrej Keprt 					*/
/*		xkeprt03							*/
/* 		verze ze 17.11.2019		*/
/*													*/
/****************************/



#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define pocet_kontaktu 1000		//velikost pole kontaktu
#define pocet_znaku 100				//velikost jednoho zaznamu

void prevod(int i,char original[][pocet_znaku],char kopie[][pocet_znaku]); //funkce ktera prevede pole znaku na pole cicel

int main (int argc, char *argv[])
{
	//overeni poctu argumentu
	if (argc > 2)
	{
		fprintf(stderr,"zadej pouze jedno hledane cislo\n");
		return 1;
	}

	//ulozeni seznamu
	char c;														//pomocna promena pro nacitani
	int kontakt = 0;
	int znak = 0;
	int pocet_zaznamu = 0;
	char jmeno[pocet_kontaktu][pocet_znaku];
	char cislo[pocet_kontaktu][pocet_znaku];
	while ((c = fgetc(stdin)) != EOF)			//nacitani po znacich do doby, nez nalezne konec souboru
	{
		if ((pocet_zaznamu % 2) == 1)			// pokud je poradi radku liche ulozi cislo do pole cislo
			{
				if (c != '\n')
				{
					cislo[kontakt][znak] = c;
					znak++;
				}
				else
				{
					pocet_zaznamu++;
					kontakt++;
					znak = 0;
				}
			}
			else											// pokud je poradi radku sude ulozi cislo do pole jmeno
			{
				if (c != '\n')
				{
					jmeno[kontakt][znak] = tolower(c);	// prevedeni velkych cisel na mala, diky tomu se zmensi switch na prevod
					znak++;
				}
				else
				{
					pocet_zaznamu++;
					znak = 0;
				}
			}
	}
pocet_zaznamu = (pocet_zaznamu/2)+1;		// nejdrive cislo udavalo pocet radku, ktere jsme nacetli, po zmene uvadi pocet ulozenych kontaktu (celociselne deleni)

//vypis bez zadani hledaneho cisla
if (argc == 1)
	{

			for (kontakt = 0; kontakt < pocet_zaznamu-1;kontakt++)
				{
					printf("%s, %s\n",jmeno[kontakt],cislo[kontakt]);
				}
		return 0;
	}


// prevod jmena na cisla
char kontakt_cisla [pocet_kontaktu][pocet_znaku];
char cislo_cisla [pocet_kontaktu][pocet_znaku];
for (int i = 0; i < pocet_zaznamu;i++)
	{
		prevod(i,jmeno,kontakt_cisla);
		prevod(i,cislo,cislo_cisla);
		znak = 0;
	}


// pole kterre rika, jake kontakty jsme nalezly	 0 nenalezeno,   1 nalezeno
int vypsat[pocet_zaznamu];
 for (kontakt = 0; kontakt < pocet_zaznamu;kontakt++)
 {
	 vypsat[kontakt] = 0;
 }

 //porovnani
 char *p;
 int nalezeno = 0;
for (kontakt = 0; kontakt < pocet_zaznamu;kontakt++)
		{
			p = strstr(cislo_cisla[kontakt], argv[1]);		// porovnani cisla s hledanou sekvenci cisel
			if (p != NULL)
				{
					vypsat[kontakt] = 1;
					nalezeno = 1;
				}

			p = strstr(kontakt_cisla[kontakt], argv[1]);	// porovnani jmen s hledanou sekvenci cisel
			if (p != NULL)
				{
					vypsat[kontakt] = 1;
					nalezeno = 1;
				}
		}

//vypis nalezenych kontaktu
	for (int kontakt = 0; kontakt <pocet_zaznamu;kontakt++)
		{
			if (vypsat[kontakt])
			{
				printf("%s, %s\n",jmeno[kontakt],cislo[kontakt]);
			}
		}

	//nebyla nalezena zadna shoda
	if (nalezeno == 0)
	{
		printf("Not found\n");
	}
	return 0;
}

void prevod (int i, char original[][pocet_znaku],char kopie[][pocet_znaku])
{
	int znak = 0;
		while (original[i][znak] !='\0')
		{
			switch (original[i][znak])
			{
				case ' ':
				kopie[i][znak] = ' ';
				break;			// znak mezery
				case 'a':
				case 'b':
				case 'c':
					kopie[i][znak] = '2';
					break;
				case 'd':
				case 'f':
				case 'e':
					kopie[i][znak] = '3';
				break;
				case 'g':
				case 'h':
				case 'i':
					kopie[i][znak] = '4';
					break;
				case 'j':
				case 'k':
				case 'l':
					kopie[i][znak] = '5';
				break;
				case 'm':
				case 'n':
				case 'o':
					kopie[i][znak] = '6';
					break;
				case 'p':
				case 'q':
				case 'r':
				case 's':
					kopie[i][znak] = '7';
				break;
				case 't':
				case 'u':
				case 'v':
					kopie[i][znak] = '8';
					break;
				case 'w':
				case 'x':
				case 'y':
				case 'z':
					kopie[i][znak] = '9';
				 break;
				case '+':
				kopie[i][znak] = '0';
				 break;
				default:																		//pokud prevadim cislo (kvuli moznemu vyskytu + v predcisli) a nenarazim na pismeno/mezeru
					kopie[i][znak] = original[i][znak];				//automaticky se prevede hodnota z prvniho pole do druheho
					break;
			 }
			znak++;
		}
}
