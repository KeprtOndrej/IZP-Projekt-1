#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char c;
	int radek, znak;
	char string[1000][100];
	radek = znak = 0;
	
	//nacteni ze seznamu
	while ((c=fgetc(stdin)) != EOF)
	{
		while (c != '\n')
			{
			/*	while (c != '\0')				//tohle cast kodu kdyz se odkomentaruje tak mi to vyhodi vetu, ze saham nekam, kde nemam pristum
				{						// kdyz to je takhle zakomentarovane, tak se mi dodrbe prikazova radka(jakoch porad psal argumenty si myslim..)
					string[radek][znak] = c;
					znak++;
				}	*/
			znak = 0;
			}
		radek++;
	}
	


	//porovnani
	//one day maybe xD

	//kvuli prekladaci protoze je zatim nepouzivam
	string[2][3] = 'a';
	printf("%s",argv[1]);
	printf("%d",argc);
	printf("%c",string[2][3]);
	return 0;
}

