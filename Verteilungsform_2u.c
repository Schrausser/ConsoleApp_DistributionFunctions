//----------------------------------------------------------------------------------------------------|Verteilungsform_2u (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void profil();
void kopf();

double fn_erg;
double seed, seed1;
double zf_wert[2000];

double stat_theta(double wert[2000], int n, int theta)	// Harmonisches Mittel(0), HM_ x1,x2, ... ,xn
														// Arithmetisches Mittel(1), AM_ x1,x2, ... ,xn
														// Summe(2) // SUM  x1,x2, ... ,xn
														// Standardabweichung(3) // SD  x1,x2, ... ,xn
														// Populationsvarianzschätzung(4) // VAR  x1,x2, ... ,xn
														// Produktsumme(5) // PSUM  x1,x2, ... ,xn
														// Geometrisches Mittel(6) // GM_  x1,x2, ... ,xn
													    // Schrausser's d(7) // D__  x1,x2, ... ,xn
														// DvarO(8) // DVARO  x1,x2, ... ,xn
{
	int iLauf; 
	double sd, sd_sum=0, pw, n1=0;
	
	if(theta<5 || theta >6) 
	{
		fn_erg=0;
		
		for(iLauf=1; iLauf<=n; iLauf++) //summierung
		{
			if(theta >= 1) fn_erg += wert[iLauf];
			if(theta == 0) fn_erg += 1/wert[iLauf];
		}
		
		if(theta==0) fn_erg = n/fn_erg;//HM mittelung
		
		if(theta==1) fn_erg = fn_erg/n;//AM mittelung

		if(theta==3 || theta==4 || theta>=7)//sd / pop var schätzer
		{
			fn_erg = fn_erg/n;
			for(iLauf=1; iLauf<=n; iLauf++) 
			{
				if(theta==3 ||
					theta== 4) {sd=fn_erg - wert[iLauf]; sd_sum += pow(sd,2);

																				}
				
				if(theta==7 ||
				   theta==8) {sd=fn_erg - wert[iLauf]; sd_sum += fabs(sd); if(sd != 0) n1++;}
			}

			if(theta==3) fn_erg = pow(sd_sum/n,0.5);
			if(theta==4) fn_erg = sd_sum/(n-1);
			
			if(theta==7 ||
			   theta==8) fn_erg = sd_sum/n1;
			
			if(theta==8) {fn_erg=fn_erg/0.7955556; fn_erg = pow(fn_erg,0.5);}
		}
	}

	if(theta==5 || theta==6) 
	{
		fn_erg=1;for(iLauf=1; iLauf<=n; iLauf++) fn_erg *= wert[iLauf];//produktsumme

		if(theta==6) {pw=1.0/n;fn_erg = pow(fn_erg,pw);}//gm
	}
	
	return 0;
};

double qzufall(double seed, double min, double max)
{
	double SIGMA = 34.0/45;
	
	fn_erg =		   10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) 
		      - floor( 10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) );
	
	fn_erg= min + (max-min)*fn_erg;
	
	return fn_erg;
};

void main(int argc, char *argv[])
{
	FILE *outStream;

	int iLauf, jLauf;
	double th1, th_d, pr_=0;
	char theta[5];

	if (argc < 7) profil();

	if (atoi(argv[3]) == 0 ) strcpy(theta, "HM");
	if (atoi(argv[3]) == 1 ) strcpy(theta, "AM");
	if (atoi(argv[3]) == 2 ) strcpy(theta, "SUM");
	if (atoi(argv[3]) == 3 ) strcpy(theta, "SD");
	if (atoi(argv[3]) == 4 ) strcpy(theta, "VAR");
	if (atoi(argv[3]) == 5 ) strcpy(theta, "PSUM");
	if (atoi(argv[3]) == 6 ) strcpy(theta, "GM");
	if (atoi(argv[3]) == 7 ) strcpy(theta, "D");
	if (atoi(argv[3]) == 8 ) strcpy(theta, "DV");

	seed1=time(0)-1234567890;
	seed=  seed1-(floor(seed1/10000))*10000; 
		
	kopf();
	if(argc == 9 && atoi(argv[8])==1) printf(" gW"); 
	printf(" n(%s,%s), seed= %.0f, n(%s)= (%s+%s) s= %s\n", argv[1], argv[2], seed, theta, argv[4], argv[5], argv[6]);
	
	outStream = fopen( "verteilungsform_2u.txt", "w" );
	for(iLauf=1;iLauf<=atoi(argv[6]); iLauf++)//vektorerzeugung über subpopulationen s
	{
		for(jLauf=1;jLauf<=atoi(argv[4]); jLauf++)	//vektorerzeugung über n1
		{
			zf_wert[jLauf] = qzufall(seed,atoi(argv[1]),atoi(argv[2])); // zufallszahl zwischen min und max
			if(argc == 9 && atoi(argv[8])==1) zf_wert[jLauf]=floor(zf_wert[jLauf]); // ganzzahliger wertebereich
			seed= fn_erg;
			
		}
		stat_theta(zf_wert,atoi(argv[4]),atoi(argv[3]));// kennwert g1 berechnung
		th1=fn_erg;

		for(jLauf=1;jLauf<=atoi(argv[5]); jLauf++)	//vektorerzeugung über n2
		{
			zf_wert[jLauf] = qzufall(seed,atoi(argv[1]),atoi(argv[2])); // zufallszahl zwischen min und max
			if(argc == 9 && atoi(argv[8])==1) zf_wert[jLauf]=floor(zf_wert[jLauf]); // ganzzahliger wertebereich
			seed= fn_erg;
			
		}
		stat_theta(zf_wert,atoi(argv[5]),atoi(argv[3]));// kennwert g2 berechnung
		
		th_d= th1-fn_erg;// theta-differenz berechnung
		
		printf("%s(%s,%s), s= %i\r", theta, argv[4], argv[5], iLauf);//bildschirmausgabe zähler

		fprintf(outStream,"%f\n", th_d); // ausgabe von theta-differenz in datei  

		if(argc >= 8 && atof(argv[7]) > th_d) pr_++; //prozentrang von x
																																											
	}
	fclose(outStream);

	pr_=(pr_/atof(argv[6]))*100;
	if(argc >= 8 ) printf("\nPR(xd=%s)= %.3f", argv[7], pr_); 
	
	//system("bearb_.bat");
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Verteilungsform_2u.xls\n");
}

void profil()
{
	printf("----------------------------------------------------------------\n");
	printf("Usage: Verteilungsform_2u [min] [max] [q] [n1] [n2] [s] [xd] [g]\n");
	printf(" [min] ............... Minimalwert\n");
	printf(" [max] ............... Maximalwert\n");
	printf(" [q] ................. Theta:\n");
	printf("   |0|................. Harmonisches Mittel\n");
	printf("   |1|................. Arithmetisches Mittel\n");
	printf("   |2|................. Summe\n");
	printf("   |3|................. Standardabweichung\n");
	printf("   |4|................. Populationsvarianzschätzung\n");
	printf("   |5|................. Produktsumme \n");
	printf("   |6|................. Geometrisches Mittel\n");
	printf("   |7|................. Schrausser's d\n");
	printf("   |8|................. DvarO\n");
	printf(" [n] ................. n1 zu Theta\n");
	printf(" [n] ................. n2 zu Theta\n");
	printf(" [s] ................. n Subpopulationen\n");
	printf(" [xd] ................ Vergleichsdifferenzwert\n");
	printf(" [g] ................. |1| Wertebereich ganzzahlig\n");
	printf("---------------------------------------------------------------\n");
	printf("Verteilungsform_2u by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void kopf() 
{
	printf("\nVerteilungsform_2u by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Verteilungsform_2u:"); 
}
