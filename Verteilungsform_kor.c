//----------------------------------------------------------------------------------------------------|Verteilungsform_kor (c) SCHRAUSSER 2009
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

//Lineare Regressionsfunktion (f(x=y)=bx+a, b=B1y_, a=B0y_; f(y=x)=by+a, b=B1x_, a=B0x_;) 
double fn_lin_reg(double wert[2000]/*Regressionsmatrix R(x,y)*/, int n/*nR*/, int koef)
																						// Korrelation(1), KOR x11,x12, ... ,xn1,xn2
																						// Kovarianz(2), COV x11,x12, ... ,xn1,xn2
																						// Determinationskoeffizient(3), DET x11,x12, ... ,xn1,xn2
																						// Redundanz(4), RED x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent ayx (5), AYX x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent byx (6), BYX x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent axy (7), AXY x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent bxy (8), BXY x11,x12, ... ,xn1,xn2
{
	int iLauf; 
	double sum_x=0 ,sum_y=0, sum_y2=0, sum_x2=0, sum_xy=0, am_x, am_y, s2_x=0, s2_y=0, s_x, s_y, r_=0;
	double B1x_, B1y_, B0x_, B0y_;  
	
	for (iLauf = 1; iLauf <= n; iLauf+=2)// summierung x, y, y2, xy über n
	{
		sum_x  +=     wert[iLauf]; 
		sum_y  +=     wert[iLauf+1];
		sum_x2 += pow(wert[iLauf],2);
		sum_y2 += pow(wert[iLauf+1],2); 
		sum_xy +=     wert[iLauf]*wert[iLauf+1];
	}
	
	//mittelung
	am_x = sum_x / (n/2);
	am_y = sum_y / (n/2);

	for (iLauf = 1; iLauf <= n; iLauf+=2)//standardabweichungsberechnung (nb s unkorrigiert nach df)
	{
		s2_x  +=    pow(wert[iLauf]-am_x,2);
		s2_y  +=    pow(wert[iLauf+1]-am_y,2); 
	}

	s_x = sqrt(s2_x/(n/2));
	s_y = sqrt(s2_y/(n/2));

	//beta gewichte
	B1y_ = (((n/2) * sum_xy) - (sum_x * sum_y)) / (((n/2) * sum_x2) - pow(sum_x,2)); // byx
	B1x_ = (((n/2) * sum_xy) - (sum_x * sum_y)) / (((n/2) * sum_y2) - pow(sum_y,2)); // bxy
	
	if(koef==6) fn_erg = B1y_;//BYX / b / b1 / byx / x -> y / f(x) / y = bx
	if(koef==8) fn_erg = B1x_;//BXY / b / b1 / bxy / y -> x / f(y) / x = by
	
	B0y_ = am_y - (B1y_ * am_x);// ayx
	B0x_ = am_x - (B1x_ * am_y);// axy
	
	if(koef==5) fn_erg = B0y_;//AYX / a / b0 / ayx / x -> y / f(x) / y = x + a
	if(koef==7) fn_erg = B0x_;//AXY / a / b0 / axy / y -> x / f(y) / x = y + a
	
	if(koef==1 || koef==3 || koef==4)
	for (iLauf = 1; iLauf <= n; iLauf+=2)//korrelationskoeffizient
	{
		r_ += ((wert[iLauf]-am_x) /s_x) * ((wert[iLauf+1]-am_y) /s_y);	
	}

	if(koef==2)for (iLauf = 1; iLauf <= n; iLauf+=2)//kovarianz
	{
		r_ += (wert[iLauf]-am_x) * (wert[iLauf+1]-am_y);	
	}

	if(koef==1 || koef==2 || koef==3 || koef==4) fn_erg = r_ /(n/2);

	if(koef==3) fn_erg = pow(fn_erg,2); //determinationkoeffizient
	if(koef==4) fn_erg = 100*(pow(fn_erg,2)); //redundanz von y

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
	double pr_=0;
	char theta[5];

	if (argc < 6) profil();

	if (atoi(argv[3]) == 1 ) strcpy(theta, "r");
	if (atoi(argv[3]) == 2 ) strcpy(theta, "cov");
	if (atoi(argv[3]) == 3 ) strcpy(theta, "det");
	if (atoi(argv[3]) == 4 ) strcpy(theta, "red");
	if (atoi(argv[3]) == 5 ) strcpy(theta, "ayx");
	if (atoi(argv[3]) == 6 ) strcpy(theta, "byx");
	if (atoi(argv[3]) == 7 ) strcpy(theta, "axy");
	if (atoi(argv[3]) == 8 ) strcpy(theta, "bxy");

	seed1=time(0)-1234567890;
	seed=  seed1-(floor(seed1/10000))*10000; 
		
	kopf();
	if(argc == 8 && atoi(argv[7])==1) printf(" gW"); 
	printf(" n(%s,%s), seed= %.0f, n(%s)= %s, s= %s\n", argv[1], argv[2], seed, theta, argv[4], argv[5]);
	
	outStream = fopen( "verteilungsform_kor.txt", "w" );
	for(iLauf=1;iLauf<=atoi(argv[5]); iLauf++)//vektorerzeugung über subpopulationen s
	{
		for(jLauf=1;jLauf<=atoi(argv[4])*2; jLauf++)	//vektorerzeugung über n
		{
			zf_wert[jLauf] = qzufall(seed,atoi(argv[1]),atoi(argv[2])); // zufallszahl zwischen min und max
			if(argc == 8 && atoi(argv[7])==1) zf_wert[jLauf]=floor(zf_wert[jLauf]); // ganzzahliger wertebereich
			seed= fn_erg;
			
		}
		fn_lin_reg(zf_wert,atoi(argv[4])*2,atoi(argv[3]));//regressions kennwert berechnung
		printf("%s(%s,%s), s= %i\r", theta, argv[4], argv[4], iLauf);//bildschirmausgabe zähler

		fprintf(outStream,"%f\n", fn_erg); // ausgabe von theta in datei  

		if(argc == 7 && atof(argv[6]) > fn_erg) pr_++; //prozentrang von x
																																											
	}
	fclose(outStream);
	
	pr_=(pr_/atof(argv[5]))*100;
	if(argc >= 7 ) printf("\nPR(x=%s)= %.3f", argv[6], pr_);
	
	//system("bearb_.bat");
	printf("\n\ncall bearb_.bat\n"); 
	printf("edit Verteilungsform_kor.xls\n");
}

void profil()
{
	printf("------------------------------------------------------\n");
	printf("Usage: Verteilungsform_kor [min] [max] [q] [n] [s] [x]\n");
	printf(" [min] ............... Minimalwert\n");
	printf(" [max] ............... Maximalwert\n");
	printf(" [q] ................. Theta:\n");
	printf("   |1|................. Produktmoment Korrelation\n");
	printf("   |2|................. Kovarianz\n");
	printf("   |3|................. Determinationskoeffizient\n");
	printf("   |4|................. Redundanz\n");
	printf("   |5|................. Regressionskoeffizient ayx\n");
	printf("   |6|................. Regressionskoeffizient byx\n");
	printf("   |7|................. Regressionskoeffizient axy\n");
	printf("   |8|................. Regressionskoeffizient bxy\n");
	printf(" [n] ................. n zu Theta\n");
	printf(" [s] ................. n Subpopulationen\n");
	printf(" [x] ................. Vergleichswert\n");
	printf(" [g] ................. |1| Wertebereich ganzzahlig\n");
	printf("------------------------------------------------------\n");
	printf("Verteilungsform_kor by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void kopf() 
{
	printf("\nVerteilungsform_kor by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Verteilungsform_kor:"); 
}
