//----------------------------------------------------------------------------------------------------|Verteilungsform (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void profil();
void kopf();

double fn_erg;
double seed, seed1;

double qzufall(double seed, double min, double max)
{
	double SIGMA = 34.0/45;
	
	fn_erg =		   10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) 
		      - floor( 10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) );
	
	fn_erg= min + (max-min)*fn_erg;
	
	return 0;
};

void main(int argc, char *argv[])
{
	FILE *outStream, *outStream1;

	int iLauf, jL=-1, st=0, s_zlr=0;
	double sum=0, sum_erg;

	if (argc != 5) profil();

	seed1=time(0)-1234567890;
	seed=  seed1-(floor(seed1/10000))*10000;

	kopf();
	printf(" n(%s,%s), seed= %.0f, nTheta= %s, s= %s\n", argv[1], argv[2], seed, argv[3], argv[4]); 

	outStream = fopen( "verteilungsform.txt", "w" );
	outStream1 = fopen( "verteilungsform1.txt", "w" );
	for(iLauf=0;iLauf<=atoi(argv[4])*atoi(argv[3]); iLauf++)//vektorerzeugung über subpopulationen s
	{
		qzufall(seed,atoi(argv[1]),atoi(argv[2])); // zufallszahl zwischen min und max
		
		if (jL <= atoi(argv[3]))	//kennwertbildung als die summe über n=jL werte  
		{
			sum+=fn_erg; jL++; 
			if(jL == atoi(argv[3])) //<-
			{
				s_zlr++;
				jL = 0;
				sum_erg = sum;
				sum=0;st=1;
				printf("sum(%s), s= %i\r", argv[3], s_zlr);//bildschirmausgabe s zähler
				fprintf(outStream1,"%f\n", sum_erg);// Theta ausgabe in datei  
			}
		}
		
		if(st==1) 
		fprintf(outStream,"%f\t%f\t%f\n", fn_erg, floor(fn_erg), sum_erg); // gesamt ausgabe in datei   // zufallswert
																										// abgerundeter zufallswert
																										// über n=jL summierter Zufallswert
																										//																					
		seed= fn_erg;																			
	}

	fclose(outStream);
	fclose(outStream1);

	//system("bearb_.bat");// batchaufruf
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Verteilungsform.xls\n");
}

void profil()
{
	printf("------------------------------------------\n");
	printf("Usage: Verteilungsform [min] [max] [n] [s]\n");
	printf(" [min] ....................... Minimalwert\n");
	printf(" [max] ....................... Maximalwert\n");
	printf(" [n] .......... n zu Kennwert Theta=sum(x)\n");
	printf(" [s] ................... n Subpopulationen\n");
	printf("------------------------------------------\n");
	printf("Verteilungsform by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}
	
void kopf() 
{
	printf("\nVerteilungsform by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Verteilungsform:"); 
}