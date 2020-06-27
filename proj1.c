#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//overeni poctu hledanych cisel
	if (argc > 2)
	{
		printf("zadej poze jedno hledane cislo\n");
		return 1;
	}

	//nacteni hodnot
	char c[100];			// 100+-2
	char jmeno[100][100];		 //100+-2
	char cislo[100][100];	 	// 10+-2
	int radek = 0;

	while (fgets(c,100,stdin) !=NULL)
		{
			strcpy(jmeno[radek][0],c);
			radek++;
		}

	//vypsani
	radek = 0;
	while (jmeno[radek][0] != NULL)
		{
			puts(jmeno[radek][0]);
			radek++;
		}






	//porovnani
	//one day maybe xD

	//kvuli prekladaci protoze je zatim nepouzivam
//	string[2][3] = 'a';
//	printf("%s",argv[1]);
//	printf("%d",argc);
//	printf("%c",string[2][3]);
	return 0;
}
