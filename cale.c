/*
 * =====================================================================================
 *
 *       Filename:  cale.c
 *
 *    Description: Este programa es un calendario que toma año y mes como imput. 
 *
 *        Version:  1.0
 *        Created:  04/09/20 09:40:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Juan Olivera
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int dia(int);
int bisiesto(int);
int diaMes(int,int,int);
void mover(int*,int);
void modificar(int*,int);
void formato(int*,int,int);

int main(){
	int mes, year, primerDiaYear, bi, primerDiaMes;
	int i,j,valor;

	int meses[6][7] = {
		 1, 2, 3, 4, 5, 6, 7,
		 8, 9,10,11,12,13,14,
		15,16,17,18,19,20,21,
		22,23,24,25,26,27,28,
		29,30,31, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0};

	printf("Ingrese el año y el mes (1, 12): ");
	scanf("%d%d",&year,&mes);

	bi = bisiesto(year);
	primerDiaYear = dia(year);

	primerDiaMes = diaMes(mes, primerDiaYear, bi);
	
	formato(*meses, mes, bi);
	mover(*meses, primerDiaMes);

	switch(mes)
	{
		case 1:
			printf("	Enero\n");
			break;
		case 2:
			printf("	Febrero\n");
			break;
		case 3:
			printf("	Marzo\n");
			break;
		case 4:
			printf("	Abril\n");
			break;
		case 5:
			printf("	Mayo\n");
			break;
		case 6:
			printf("	Junio\n");
			break;
		case 7:
			printf("	Julio\n");
			break;
		case 8:
			printf("	Agosto\n");
			break;
		case 9:
			printf("	Septiembre\n");
			break;
		case 10:
			printf("	Octubre\n");
			break;
		case 11:
			printf("	Noviembre\n");
			break;
		case 12:
			printf("	Diciembre\n");
			break;
	}

	printf("do lu ma mi ju vi sa\n");

	for(i = 0; i < 6;i++){
		printf("\n");
		for(j = 0; j < 7; j++){
			valor = *(*(meses + i) + j);
			if(valor == 0){
				printf("   ");
			}
			else if(valor > 0 && valor <= 9){

				printf(" ");
				printf("%d ",valor);

			}else{

				printf("%d ",valor);
			}
		}
	}







	//switch(primerDiaMes)
	//{
	//	case 0:
	//		printf("Domingo\n");
	//		break;
	//	case 1:
	//		printf("Lunes\n");
	//		break;
	//	case 2:
	//		printf("Martes\n");
	//		break;
	//	case 3:
	//		printf("Miercoles\n");
	//		break;
	//	case 4:
	//		printf("Jueves\n");
	//		break;
	//	case 5:
	//		printf("Viernes\n");
	//		break;
	//	case 6:
	//		printf("Sábado\n");
	//		break;
	//}

}

//Esta función nos dice el primer día de un mes basandose en el primer dia del año.
int diaMes(int m, int pd, int bi){
	int r = pd, i, count[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if(bi){
		*(count + 1) = 29;	
	}

	for(i = 0; i < m - 1; i++){

		r += *(count + i);
	}

	return(r % 7);
}

//Esta función nos regresa el primer dia del año, siendo lunes = 1.
int dia(int year){
	int i = 1900, di = 1900;
	for(i ; i < year;i++){
		if(bisiesto(i)){
			di++;//aumenta un dia extra por cada año bisiesto.
		}
		di++;
	}
	return((di + 5)% 7);
}

//Esta funcio comprueba si el año es bisiesto.
int bisiesto(int y){
	if(y % 100== 0){
		if(y % 400 == 0){
			return 1;
		}else{
			return 0;
		}
	}
	else if(y % 4 == 0){
		return 1;
	}else{
		return 0;
	}
}

//Esta función mueve los ceros al final o al inicio del arreglo.
void mover(int *a, int c){
	int i, tmp;
	
	if(c == 0){
		return;

	}else{
		for(i = 41; i > 0; i--){
			tmp = *(a + i);
			*(a + i) = *(a + i - 1);
			*(a + i - 1) = tmp;
		}
 
	mover(a,c-1);
	}
}
//Esta función modifica los ultimos digitos del arreglo.
void modificar(int *a, int c){
	int i, pos = 30;

	for(i = 0; i < c; i++){
		*(a + pos) = 0;
		pos--;
	}
}

//formatea la cantidad de dias que tiene un mes.
void formato(int *a, int m, int bi){


	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
		return ;

	}else if(m == 4 || m == 6 || m == 9 || m == 11){

		modificar(a,1);//Crea un mes de 30 dias.

	}else if(m == 2 && bi){

		modificar(a,2);//Crea un mes de 29 dias.

	}else if(m == 2 && !bi){

		modificar(a,3);//crea un mes de 28.
	}
}
