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
void gotoxy(int x,int y);
void menu();
void seleccion();

int main(int argc, char** argv) {
	srand(time(0));
	system("color f0");
	
	tablero tm;

	char tecla;
	int band=0, band1=0, n;
	menu();
	
	
	do{	
	
		tecla=getch( );
		switch(tecla){
			case 49:{
				
				system("cls");
				band=1;
				break;
			}
			case 50:{
	          
	          system("cls");
	         
	          do{
	          	printf("\n\nSI DESEA REGRESAR AL MENU PRINCIPAL PRESIONE <4>.");
	            scanf("%d",&n);
	            
	             if(n!=4){
	          	     printf("\n OPCION INVALIDA, INTENTE DE NUEVO");
				  }
	          	
	          	
			  }while(n!=4);
	          
	          if(n==4){
	          	
	          	band1=1;
	          	system("cls");
			  }
				
				break;
			}
			case 51:{
				system("cls");
				printf("CREADOR: MARCO JOSE USECHE RIVERA\n ESTUDIANTE INGENIERIA EN INFORMATICA\n UNET 216 ");
				do{
	          	  printf("\n\nSI DESEA REGRESAR AL MENU PRINCIPAL PRESIONE <4>.");
	            	scanf("%d",&n);
	          	  if(n!=4){
	          	     printf("\n OPCION INVALIDA, INTENTE DE NUEVO");
				  }
				  
	          	
			   }while(n!=4);
	          
	           if(n==4){
	          	
	          	band1=1;
	          	system("cls");
			   }
				break;
			}
			default:{
			
				
				gotoxy(26,8);
				printf("\n OPCION INVALIDA, INTENTE DE NUEVO");
				
				break;
			}
			
		}//switch
		
		 if(band1==1){
	    	
	       menu( );
	   
	     }
		
		
		
	}while(band!=1);
	
	if(band==1){
		system("cls");
			tablero tm;
        	cargarmatriz(&tm);
	
	}
	
	

	
	
	system("pause>null");
	return 0;
}

void color(int X) 
{ 
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); 
} 

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
void cargarmatriz(tablero *tm)
{
	char opc; 
	int aux;
	do{
	system("cls");
	printf("-------SELECCIONE SU DIFICULTAD-------\n");
	printf("-1-----FACIL-----\n");
	printf("-2-----MEDIO-----\n");
	printf("-3-----DIFICIL---\n");

    
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

void menu()
{
	printf("\t-------BIENVENIDO A COLORFLOOD---USECHE EDITION V. 0.1 CON BUGS---------\n");
	printf("\n\n\t-------(1)MODOS DE JUEGO----\n");
	printf("\t-------(2)AYUDA-------------\n");
	printf("\t-------(3)CREDITOS----------\n");
}

void seleccion()
{
	
}
