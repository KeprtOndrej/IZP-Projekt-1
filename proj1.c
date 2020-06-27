// Projekt 1
//verze z: 11.11.2019
// Ondrej Keprt, xkeprt03


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	//overeni poctu argumentu
	if (argc > 2)
	{
		printf("zadej pouze jedno hledane cislo\n");
		return 1;
	}

	//ulozeni seznamu
	char c;	//pomocna promena pro nacitani
	int kontakt = 0;
	int znak = 0;
	int radek_zaznamu = 0;
	char jmeno[1000][100];
	char cislo[1000][100];
	while ((c=fgetc(stdin)) != EOF)
	{
		if ((radek_zaznamu % 2) == 1)
			{
				if (c != '\n')
				{
					cislo[kontakt][znak] = c;
					znak++;
				}
				else
				{
					radek_zaznamu++;
					kontakt++;
					znak = 0;
				}
			}
			else
			{
				if (c != '\n')
				{
					jmeno[kontakt][znak] = c;
					znak++;
				}
				else
				{
					//printf("%s\n", zaznam[radek]);
					radek_zaznamu++;
					znak = 0;
				}
			}
	}
radek_zaznamu = (radek_zaznamu/2)+1;

//vypis bez zadani hledaneho cisla
kontakt = 0;
if (argc == 1)
	{

			for (int i =1; i < radek_zaznamu;i++)
				{
					printf("%s, %s\n",jmeno[kontakt],cislo[kontakt]);
					kontakt++;
				}
		return 0;
	}


// prevod jmena na cisla
char kontakt_cisla [1000][100];
znak = 0;
for (int i = 0; i < radek_zaznamu;i++)
	{
		while (jmeno[i][znak] !='\0')
		{
			switch (jmeno[i][znak])
			{
				case ' ':
				kontakt_cisla[i][znak] = ' ';
				break;			// znak mezery
				case 'a':
				case 'A':
				case 'b':
				case 'B':
				case 'c':
				case 'C':
					kontakt_cisla[i][znak] = '2';
					break;
				case 'd':
				case 'D':
				case 'f':
				case 'F':
				case 'e':
				case 'E':
					kontakt_cisla[i][znak] = '3';
				break;
				case 'g':
				case 'G':
				case 'H':
				case 'h':
				case 'i':
				case 'I':
					kontakt_cisla[i][znak] = '4';
					break;
				case 'j':
				case 'J':
				case 'k':
				case 'K':
				case 'l':
				case 'L':
					kontakt_cisla[i][znak] = '5';
				break;
				case 'm':
				case 'M':
				case 'n':
				case 'N':
				case 'o':
				case 'O':
					kontakt_cisla[i][znak] = '6';
					break;
				case 'p':
				case 'P':
				case 'q':
				case 'Q':
				case 'r':
				case 'R':
				case 's':
				case 'S':
					kontakt_cisla[i][znak] = '7';
				break;
				case 't':
				case 'T':
				case 'u':
				case 'U':
				case 'v':
				case 'V':
					kontakt_cisla[i][znak] = '8';
					break;
				case 'w':
				case 'W':
				case 'x':
				case 'X':
				case 'y':
				case 'Y':
				case 'z':
				case 'Z':
					kontakt_cisla[i][znak] = '9';
				 break;
				case '+':
				 kontakt_cisla[i][znak] = '0';
				 break;
			 }
			znak++;
		}
		znak = 0;
	}

// pole kterre rika, jake zaznami jsme nalezly
int vypsat[radek_zaznamu];
 for (int i = 0;i < radek_zaznamu;i++)
 {
	 vypsat[i] = 0;
 }

 //porovnani
 char *p;
 char *s;
 int nalezeno = 0;
for (int i = 0; i < radek_zaznamu;i++)
		{
			//porovnani cisel
			p = strstr(cislo[i], argv[1]);
			if (p != NULL)
				{
					vypsat[i] = 1;
					nalezeno = 1;
				}

				// porovnani jmen
				s = strstr(kontakt_cisla[i], argv[1]);
				if (s != NULL)
					{
						vypsat[i] = 1;
						nalezeno = 1;
					}
		}
//vypis nalezenych kontaktu
	for (int i = 0; i <radek_zaznamu;i++)
	{
		if (vypsat[i])
		{
			printf("%s, %s                   %s\n",jmeno[i],cislo[i],kontakt_cisla[i]);
		}
	}

	//nebyla nalezena zadna shoda
	if (nalezeno == 0)
	{
		printf("Not found\n");
	}
	return 0;
}
