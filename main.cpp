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

	char tecla, esc;
	int band=0, band1=0;
	
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
	          	printf("\n\nSI DESEA REGRESAR AL MENU PRINCIPAL PRESIONE (4).");
	        	 esc=getch();
	            
	             if(esc!='4'){
	          	     printf("\n OPCION INVALIDA, INTENTE DE NUEVO");
				  }
	          	
	          	
			  }while(esc!='4');
	          
	          if(esc=='4'){
	          	
	          	band1=1;
	          	system("cls");
			  }
				
				break;
			}
			case 51:{
				system("cls");
				printf("CREADOR: MARCO JOSE USECHE RIVERA\n ESTUDIANTE INGENIERIA EN INFORMATICA\n UNET 2016 ");
				do{
	          	  printf("\n\nSI DESEA REGRESAR AL MENU PRINCIPAL PRESIONE (4).");
	            	esc=getch();
	          	  if(esc!= '4'){
	          	     printf("\n OPCION INVALIDA, INTENTE DE NUEVO");
				  }
				  
	          	
			   }while(esc!='4');
	          
	           if(esc=='4'){
	          	
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
	
	seleccion();

	/////////////////////
	char boton;
	int aux2;
	
	
	fflush(stdin);
	boton=getch();
	aux2=boton-48;

	int mat_aux[tm->filas][tm->columnas];

	for(int i=0; i<tm->filas; i++)
	{
		for(int j=0; j<tm->columnas; j++)
		{
			mat_aux[i][j]=0;
		}
	}
	
	printf("\n\n\n");
	switch(aux2)
	{
		case 'a':
			mat_aux[0][0]=1;
			break;
		case 'b':
			mat_aux[0][0]=2;
			break;
		case 'c':
			mat_aux[0][0]=4;
			break;
		case 'd':
			mat_aux[0][0]=5;
			break;
		case 'e':
			mat_aux[0][0]=6;
			break;
		case 'f':
			mat_aux[0][0]=3;
			break;
	}
	
	for(int i=0; i< tm->filas-1; i++)
	{
		for(int j=0; j< tm->columnas-1; j++)
		{
			if(mat_aux[i][j]== tm->matriz[i+1][j])
			{
				mat_aux[i+1][j]=tm->matriz[i+1][j];
			}
			
			if(mat_aux[i][j]== tm->matriz[i][j+1])
			{
				mat_aux[i][j+1]=tm->matriz[i][j+1];
			}
		}
	}
	
	for(int i=0; i< tm->filas; i++)
	{
		printf("\n");
		for(int j=0; j< tm->columnas; j++)
		{
			printf("%d", mat_aux[i][j]);
		}
	}
	
	
	
	
	
}

void menu()
{
	printf("\t-------BIENVENIDO A COLORFLOOD---USECHE EDITION V. 0.2 CON BUGS---------\n");
	printf("\n\n\t-------(1)MODOS DE JUEGO----\n");
	printf("\t-------(2)AYUDA-------------\n");
	printf("\t-------(3)CREDITOS----------\n");
}

void seleccion()
{
	gotoxy(25, 5);
	color(15*16+9);
	printf("%c%c%c A", 219, 219, 219);
	
	gotoxy(25, 7);
	color(15*16+12);
	printf("%c%c%c B", 219, 219, 219);
	
	gotoxy(25, 9);
	color(15*16+14);
	printf("%c%c%c C", 219, 219, 219);
	
	gotoxy(25, 11);
	color(15*16+13);
	printf("%c%c%c D", 219, 219, 219);
	
	gotoxy(25, 13);
	color(15*16+10);
	printf("%c%c%c E", 219, 219, 219);
	
	gotoxy(25, 15);
	color(15*16+11);
	printf("%c%c%c F", 219, 219, 219);
}


