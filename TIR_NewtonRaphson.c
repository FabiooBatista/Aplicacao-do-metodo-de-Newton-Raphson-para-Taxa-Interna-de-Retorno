#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tir(void)
{
	float fc0, fi, dfdi, i=0, ik, Eik, Ea=0.000001, aux;
	int n, j;
	char mfc;
	
	system("cls");
	printf("Programa de Taxa Interna de Retorno \n\n");
	printf("FC0 = FC1/(1+i) + FC2/(1+i)^2 + FC3/(1+i)^3 + ... + FCn/(1+i)^n \n\n");
	printf("Fluxo de caixa inicial FC0: ");
	scanf("%f", &fc0);
	
	system("cls");
	printf("Programa de Taxa Interna de Retorno \n\n");
	printf("%.2f = FC1/(1+i) + FC2/(1+i)^2 + FC3/(1+i)^3 + ... + FCn/(1+i)^n \n\n", fc0);
	printf("Periodo: ");
	scanf("%i", &n);
	
	system("cls");
	printf("Programa de Taxa Interna de Retorno \n\n");
	printf("%.2f = FC1/(1+i) ", fc0);
	for(j=2;j<=n;j++){
		printf("+ FC%i/(1+i)^%i ", j,j);
	}
	printf("\n\n");
	printf("Os demais fluxos de caixa sao iguais entre si?[S/N] ");
    fflush(stdin);
    scanf("%c", &mfc);

    if(mfc=='s' || mfc=='S'){
    	float fc;
    	printf("Fluxo de caixa: ");
    	scanf("%f", &fc);
    	
    	system("cls");
		printf("Programa de Taxa Interna de Retorno \n\n");
		printf("%.2f = %.2f/(1+i) ", fc0,fc);
		for(j=2;j<=n;j++){
		printf("+ %.2f/(1+i)^%i ", fc,j);
		}
		printf("\n\n");
    	
		do{
			fi = 0;
			dfdi = 0;
			fi -= fc0;
			for(j=1;j<=n;j++){
    			fi += fc/(pow(1+i,j));
    			dfdi -= (j*fc)/(pow(1+i,j+1));
			}	
        	ik = i-(fi/dfdi);
        	Eik = (ik-i)/i;
        	i = ik;
        	if(Eik<0) { Eik *= -1; }
    	}while(Eik>Ea);
    	
    	i *= 100;
		printf("i = %f%% \n\n", i);
		system("pause");
		system("cls");
		printf("Programa de Taxa Interna de Retorno \n\n");
		printf("%.2f = %.2f/(1+(%f)) ", fc0,fc,ik);
		for(j=2;j<=n;j++){
		printf("+ %.2f/(1+(%f))^%i ", fc,ik,j);
		}
		printf("\n\n");
		for(j=1;j<=n;j++){
    	aux += fc/(pow(1+ik,j));
		}
		system("pause");
		system("cls");
		printf("Programa de Taxa Interna de Retorno \n\n");
		printf("%.2f = %.2f \n\n", fc0,aux);
	}else{
		if(mfc=='n' || mfc=='N'){
			float fc[n];
			for(j=0;j<n;j++){
				printf("Fluxo de caixa %i: ", j+1);
				scanf("%f", &fc[j]);
			}
			
			system("cls");
			printf("Programa de Taxa Interna de Retorno \n\n");
			printf("%.2f = ", fc0);
			for(j=1;j<=n;j++){
			printf("+ %.2f/(1+i)^%i ", fc[j-1],j);
			}
			printf("\n\n");
    		
			do{
				fi = 0;
				dfdi = 0;
				fi -= fc0;
				for(j=1;j<=n;j++){
    				fi += fc[j-1]/(pow(1+i,j));
    				dfdi -= (j*fc[j-1])/(pow(1+i,j+1));
				}
					
        		ik = i-(fi/dfdi);
        		Eik = (ik-i)/i;
        		i = ik;
        		if(Eik<0) { Eik *= -1; }
    		}while(Eik>Ea);
    		
    		i *= 100;
			printf("i = %f%% \n\n", i);
			system("pause");
			system("cls");
			printf("Programa de Taxa Interna de Retorno \n\n");
			printf("%.2f = ", fc0);
			for(j=1;j<=n;j++){
			printf("+ %.2f/(1+(%f))^%i ", fc[j-1],ik,j);
			}
			printf("\n\n");
			for(j=1;j<=n;j++){
    		aux += fc[j-1]/(pow(1+ik,j));
			}
			system("pause");
			system("cls");
			printf("Programa de Taxa Interna de Retorno \n\n");
			printf("%.2f = %.2f \n\n", fc0,aux);
		}else{
			printf("Caracter invalido...");
		}
	}
}

int main(void)
{
	char dnv;
	int sai=0;
	
	tir();
	system("pause");
	do{
		system("cls");
		printf("Programa de Taxa Interna de Retorno \n\n");
		printf("Deseja fazer de novo?[S/N] ");
		fflush(stdin);
		scanf("%c", &dnv);
		if(dnv=='s' || dnv=='S'){
			tir();
			sai = 0;
		}else{
			if(dnv=='n' || dnv=='N'){
				printf("Finalizando programa... \n\n");
				sai = 1;
			}else{
				printf("Caracter invalido \n\n");
				sai = 0;
			}
		}
		system("pause");
	}while(sai!=1);
}