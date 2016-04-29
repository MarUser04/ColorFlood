#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

struct tablero{
	int **matriz;
	int filas, columnas;
	char boton;
	int aux2;
	int cont;
	int figura=219;
};

void cargarmatriz(tablero *tmc);
void imprimir(tablero *tmc);
void jugar(tablero *tmc);
void color(int X);
void gotoxy(int x,int y);
void menu();
void seleccion(tablero *tmc);
void eleccion(tablero *tmc);


int main(int argc, char** argv) {
	srand(time(0));
	system("color f0");
	
	tablero tm;

	char tecla, esc, r;
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
	          	printf("\t\t-----AYUDA-----\n\n");
	          	printf("\n\tEL OBJETIVO DE COLORFLOOD ES MUY SENCILLO, HACER QUE LA MATRIZ QUEDE DE UN SOLO COLOR,\n");
	          	printf("\n\tA PARTIR DE CAMBIOS DE COLORES QUE EL USUARIO REALIZE.\n");
	          	printf("\n\t(1)LO PRIMERO QUE SE TIENE QUE REALIZAR ES ESCOGER UNA DIFICULTAD EN EL MENU DE SELECCION\n");
	          	printf("\t(2)SE PRESENTARA LA MATRIZ DE UN TAMAÑO ESTABLECIDO SEGUN LA DIFICULTAD,\n");
	          	printf("\tY A LA DERECHA DE ESTA, UNA SERIES DE OPCIONES DE COLORES CON LAS LETRAS QUE REPRESENTA CADA UNO.	\n");
	          	printf("\t(3)EL USUARIO ESCOGERA UN COLOR CON EL CUAL INICIAR, EL CUAL MODIFICARA LA ESQUINA SUPERIO IZQUIERDA DE LA MATRIZ\n");
	          	printf("\tCON EL OBJETIVO DE IGUALARLA A ALGUNA CASILLA ADYACENTE QUE TENGA EL MISMO COLOR.\n");
	          	printf("\t(4) A CONTINUACION SE SELECCIONARA OTRO COLOR, Y ASI SUCESIVAMENTE HASTA LOGRAR LLENAR LA MATRIZ DE UN SOLO COLOR, EL CUAL ES EL OBETIVO DEL JUEGO.\n");
	          	printf("\tESTA SERIE DE CAMBIOS SE TENDRAN QUE HACER CON UN NUMERO LIMITE DE MOVIMIENTOS ESTABLECIDOS SEGUN LA DIFICULTAD,\n");
	          	printf("\tEN CASO DE NO LOGRAR EL OBJETIVO ANTES DE QUE SE ACABEN EL NUMERO LIMITE DE MOVIMIENTOS, EL USUARIO PIERDE EL JUEGO.");
	          	
	          	printf("\n\n\tBASICAMENTE ESTA ES LA MECANICA DEL JUEGO, ASI SIN MAS QUE DECIR.....\n\n");
	          	printf("\t\tA GANAR!!! %c", 01);
	          	
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
			tablero tmc;
        	do
        	{   cargarmatriz(&tmc);
        		jugar(&tmc);
				
				printf("\n\n\n\tDesea regresar al menu principal? (S/N)");
				r=getch();
			}while(r=='s' || r=='S');
	
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
 
void cargarmatriz(tablero *tmc)
{
	char opc; 
	int aux;
	do{
	system("cls");
		eleccion(tmc);
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
			tmc->filas=10;
			tmc->columnas=10;
			break;
		case 2:
			tmc->filas=15;
			tmc->columnas=15;
			break;
		case 3:
			tmc->filas=20;
			tmc->columnas=20;
			break;
	
	}
	
	if(tmc->filas==10)
	{
		tmc->cont= 22;
	}
	else if(tmc->filas==15)
	{
		tmc->cont= 32;
	}
	else if(tmc->filas==20)
	{
		tmc->cont=42;
	}
	

	tmc->matriz= new int *[tmc->filas];
	for(int i=0; i<tmc->filas; i++)
	{
		tmc->matriz[i]=new int [tmc->columnas];
	}
	


	
	
	for(int i=0;i<tmc->filas;i++){
		for(int j=0;j<tmc->columnas;j++){
			tmc->matriz[i][j]=rand()%6+1;
		}
	}
	
	imprimir(tmc);
	
	seleccion(tmc);


}

void imprimir(tablero *tmc)
{

	
	for(int i=0;i<tmc->filas;i++){
		printf("\n");
		for(int j=0;j<tmc->columnas;j++){
			if(tmc->matriz[i][j]==1)
			{
				color(15*16+9);
				printf("%c", tmc->figura);
			}
			else if(tmc->matriz[i][j]==2)
			{
				color(15*16+12);
				printf("%c", tmc->figura);
			}
				else if(tmc->matriz[i][j]==3)
			{
				color(15*16+11);
				printf("%c", tmc->figura);
			}
				else if(tmc->matriz[i][j]==4)
			{
				color(15*16+14);
				printf("%c", tmc->figura);
			}
				else if(tmc->matriz[i][j]==5)
			{
				color(15*16+13);
				printf("%c", tmc->figura);
			}
			else if(tmc->matriz[i][j]==6 )
			{
				color(15*16+10);
				printf("%c", tmc->figura);
			}
			else if(tmc->matriz[i][j]==9)
			{
				switch(tmc->aux2)
				{
					case 1:
						color(15*16+9);
						printf("%c", tmc->figura);
						break;
					case 2:
						color(15*16+12);
						printf("%c", tmc->figura);
						break;
					case 3:
						color(15*16+11);
						printf("%c", tmc->figura);
						break;
					case 4:
						color(15*16+14);
						printf("%c", tmc->figura);
						break;
					case 5:
						color(15*16+13);
						printf("%c", tmc->figura);
						break;
					case 6:
						color(15*16+10);
						printf("%c", tmc->figura);
						break;
				}
			}
			
		}
	}
	
	
}

void jugar(tablero *tmc)
{
	tmc->matriz[0][0]=9;
	
	do
	{
		

	do{
		
	
	fflush(stdin);
	tmc->boton=getch();
	tmc->aux2=tmc->boton-48-48;
	
	}while(!(tmc->aux2 >0 && tmc->aux2<7));

	tmc->cont--;
	

	
	for(int i=0; i<tmc->filas-1; i++)
	{
		for(int j=0; j< tmc->columnas-1; j++)
		{
			if(tmc->matriz[i][j]==9)
			{
				if(tmc->matriz[i+1][j]==tmc->aux2)
				{
					tmc->matriz[i+1][j]=9;
				}
				if(i-1>=0 && tmc->matriz[i-1][j]==tmc->aux2)
				{
					tmc->matriz[i-1][j]=9;
				}
				if(j-1>=0 && tmc->matriz[i][j-1]==tmc->aux2)
				{
					tmc->matriz[i][j-1]=9;
				}
				if( tmc->matriz[i][j+1]==tmc->aux2)
				{
					tmc->matriz[i][j+1]=9;
				}
			}
		}
	}

	
	system("cls");
	imprimir(tmc);
	seleccion(tmc);
	
	
	
	}while(tmc->cont >0);
}

void menu()
{
	printf("\t-------BIENVENIDO A COLORFLOOD---USECHE EDITION V. 0.2 CON BUGS---------\n");
	printf("\n\n\t-------(1)MODOS DE JUEGO----\n");
	printf("\t-------(2)AYUDA-------------\n");
	printf("\t-------(3)CREDITOS----------\n");
}

void seleccion(tablero *tmc)
{
	
	gotoxy(25, 3);
	color(15*16+8);
	printf("MOVIMIENTOS: %d", tmc->cont);
	
	
	gotoxy(25, 5);
	color(15*16+9);
	printf("%c%c%c A", 219, 219, 219);
	
	gotoxy(25, 7);
	color(15*16+12);
	printf("%c%c%c B", 219, 219, 219);
	
	gotoxy(25, 9);
	color(15*16+11);
	printf("%c%c%c C", 219, 219, 219);
	
	gotoxy(25, 11);
	color(15*16+14);
	printf("%c%c%c D", 219, 219, 219);
	
	gotoxy(25, 13);
	color(15*16+13);
	printf("%c%c%c E", 219, 219, 219);
	
	gotoxy(25, 15);
	color(15*16+10);
	printf("%c%c%c F", 219, 219, 219);
}

void eleccion(tablero *tmc)
{
	char opc2;
	int aux3;
	
	printf("\n\tESCOGA LA FIGURA CON LA QUE DESEE JUGAR: ");
	
	gotoxy(2, 3);
	printf("(A)CLASICO %c", 219);
	
	gotoxy(2, 5);
	printf("(B)CARA SONRIENTE %c", 02);
	
	gotoxy(2, 7);
	printf("(C) CORAZON %c", 03);
	
	gotoxy(2, 9);
	printf("(D) ROMBO %c", 04);
	
	gotoxy(2, 11);
	printf("(E)TREBOL %c", 05);
	
	gotoxy(2, 13);
	printf("(F)DIAMANTE %c", 06);
	
	gotoxy(2, 15);
	printf("(G)TRIANGULO %c", 30);
	
	gotoxy(2, 17);
	printf("(H)ARROVA %c", 64);
	
	do
	{
		
	
	fflush(stdin);
    opc2= getch();
    aux3=opc2-48-48;
    }while(!(aux3>0 && aux3 <9));
    
    switch(aux3)
    {
    	case 1:
    		tmc->figura=219;
    		break;
    	case 2:
    		tmc->figura=02;
    		break;
    	case 3:
    		tmc->figura=03;
    		break;
    	case 4:
    		tmc->figura=04;
    		break;
    	case 5:
    		tmc->figura=05;
    		break;
    	case 6:
    		tmc->figura=06;
    		break;
    	case 7:
    		tmc->figura=30;
    		break;
    	case 8:
    		tmc->figura=64;
    		break;
	}
	 
}
