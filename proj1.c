#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define pocet_kontaktu 1000
#define pocet_znaku 100

void prevod(int i,char original[pocet_kontaktu][pocet_znaku],char kopie[pocet_kontaktu][pocet_znaku]);

int main (int argc, char *argv[])
{
	//overeni poctu argumentu
	if (argc > 2)
	{
		fprintf(stderr,"zadej pouze jedno hledane cislo\n");
		return 1;
	}

	//ulozeni seznamu
	char c;	//pomocna promena pro nacitani
	int kontakt = 0;
	int znak = 0;
	int pocet_zaznamu = 0;
	char jmeno[pocet_kontaktu][pocet_znaku];
	char cislo[pocet_kontaktu][pocet_znaku];
	while ((c=fgetc(stdin)) != EOF)
	{
		if ((pocet_zaznamu % 2) == 1)
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
			else
			{
				if (c != '\n')
				{
					jmeno[kontakt][znak] = tolower(c);
					znak++;
				}
				else
				{
					//printf("%s\n", zaznam[radek]);
					pocet_zaznamu++;
					znak = 0;
				}
			}
	}
pocet_zaznamu = (pocet_zaznamu/2)+1;

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


// pole kterre rika, jake zaznami jsme nalezly
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
			//porovnani cisel
			p = strstr(cislo_cisla[kontakt], argv[1]);
			if (p != NULL)
				{
					vypsat[kontakt] = 1;
					nalezeno = 1;
				}

				// porovnani jmen
				p = strstr(kontakt_cisla[kontakt], argv[1]);
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
			printf("%s, %s  // %s // %s\n",jmeno[kontakt],cislo[kontakt],kontakt_cisla[kontakt],cislo_cisla[kontakt]);
		}
	}

	//nebyla nalezena zadna shoda
	if (nalezeno == 0)
	{
		printf("Not found\n");
	}
	return 0;
}

void prevod (int i, char original[pocet_kontaktu][pocet_znaku],char kopie[pocet_kontaktu][pocet_znaku])
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
				default:
					kopie[i][znak] = original[i][znak];
					break;
			 }
			znak++;
		}


}
