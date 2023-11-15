#include "main.h"


int sinus[] = {0,4,8,13,17,22,26,31,35,39,44,48,53,57,61,65,70,74,78,83,87,91,95,99,103,107,111,115,119,123,127,132,135,138,142,146,149,153,156,160,163,167,170,173,177,180,183,186,189,192,195,198,200,203,206,211,213,216,218,220,223,225,227,229,231,232,234,236,238,239,241,242,243,245,246,247,248,249,250,251,251,252,253,253,254,254,254,254,254,255};
//Corespond au calcul de sin(angle)*255 On perd quelques valeurs d'angles sur la fin
int ordre(int angle){

	int DTVCTR = 0;
	int phase= 1;
	int courant_A = 0;
	int courant_B = 0;


	//Calculer la polarisation de A & de B

	if ( 0 <= angle <= 180){
		phase = 0;
	}

	DTVCTR |= phase<<17;


	// Courant

	courant_A = courant(angle,1);
	courant_B = courant(angle,0);


	DTVCTR |= courant_A<<9;
	DTVCTR |= courant_B;

	return DTVCTR;

}


int courant(int angle, int numero){

	if (numero ==1){ //On gère le courant A

		if(0<= angle <=90 || 180<= angle <= 270){
			return sinus[angle%90];
		}
		else{
			return sinus[90-angle%90];
		}


	}
	else{ //On gère le courant B

		if(0<= angle <=90 || 180<= angle <= 270){
			return sinus[90-angle%90];
		}
		else{
			return sinus[angle%90];
		}

	}

}
