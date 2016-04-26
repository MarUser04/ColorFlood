#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

struct tablero{
	int **matriz;
	int filas, columnas;
};

void cargarmatriz(tablero *tm);
void color(int X);

int main(int argc, char** argv) {
	
	system("color f0");
	
	tablero tm;
	cargarmatriz(&tm);
	
	srand(time(0));
	
	system("pause>null");
	return 0;
}

void color(int X) 
{ 
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); 
} 
void cargarmatriz(tablero *tm)
{
	char opc; 
	int aux;
	do{
	system("cls");
	printf("-------BIENVENIDO A COLORFLOOD---USECHE EDITION V.1 CON BUGS---------\n");
	printf("-------FACIL-----\n");
	printf("-------MEDIO-----\n");
	printf("-------DIFICEL---\n");

    
    fflush(stdin);
    opc= getch();
    
    aux=opc-48;
	}while(aux<1 || aux>4);
	
	switch(aux)
	{
		case 1:
			tm->filas=10;
			tm->columnas=10;
			break;
		case 2:
			tm->filas=15;
			tm->columnas=15;
			break;
		case 3:
			tm->filas=20;
			tm->columnas=20;
			break;
	
	}
	
	tm->matriz= new int *[tm->filas];
	for(int i=0; i<tm->filas; i++)
	{
		tm->matriz[i]=new int [tm->columnas];
	}
	
	for(int i=0;i<tm->filas;i++){
		for(int j=0;j<tm->columnas;j++){
			tm->matriz[i][j]=rand()%6;
		}
	}
	
	for(int i=0;i<tm->filas;i++){
		printf("\n");
		for(int j=0;j<tm->columnas;j++){
			if(tm->matriz[i][j]==1)
			{
				color(0*16+9);
				printf("%c", 219);
			}
			else if(tm->matriz[i][j]==2)
			{
				color(0*16+12);
				printf("%c", 219);
			}
				else if(tm->matriz[i][j]==3)
			{
				color(0*16+11);
				printf("%c", 219);
			}
				else if(tm->matriz[i][j]==4)
			{
				color(0*16+14);
				printf("%c", 219);
			}
				else if(tm->matriz[i][j]==5)
			{
				color(0*16+13);
				printf("%c", 219);
			}
			else if(tm->matriz[i][j]==6 || tm->matriz[i][j]==0)
			{
				color(0*16+10);
				printf("%c", 219);
			}
		}
	}
	
	
	
}
