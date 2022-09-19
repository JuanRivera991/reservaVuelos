#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Crear struct con los datos del cliente
struct clienteReserva{
	char nombre[20];
	char apellido[20];
	char identificacion[11];
	char numero[10];
};

//Funcion Main
int main(){
	//Definir variables y llamando al struct
	struct clienteReserva persona;
	int opcion;
	int matriz[20][4];
	int fila;
	int columna;
	int i;
	int j;
	int fila1;
	int columna1;
	srand(time(NULL));

	opcion=0;
	fila=0;
	columna=0;
	columna1=0;
	fila1=0;

	for(i=0;i<20;i++){
		for(j=0;j<4;j++){
			matriz[i][j]=rand()%2;
		}
	}
	//Piidiendo datos que se guardan en el struct
	fflush(stdin);
	printf("Ingrese su nombre: ");
	gets(persona.nombre);
	fflush(stdin);
	printf("Ingrese su apellido: ");
	gets(persona.apellido);
	fflush(stdin);
	printf("Ingrese su numero de identificacion: ");
	gets(persona.identificacion);
	fflush(stdin);
	printf("Ingrese su numero telefonico: ");
	gets(persona.numero);
	system("cls");

	//Menu
	do{
		system("cls");
		printf("Bienvenido %s %s\n",persona.nombre, persona.apellido);
		printf("_________MENU_________\n");
		printf("|1.Reservar asiento. |\n");
		printf("|2.Cancelar reserva. |\n");
		printf("|3.Imprimir boleto.  |\n");
		printf("|4.Salir del programa|\n");
		printf("|____________________|\n\n");

		printf("Digite una opcion: ");
		scanf("%d",&opcion);

		//Switch con las opciones del menu
		switch(opcion){
			case 1:{
				//Mostrar que asientos estan disponibles
				system("cls");
				printf("Apreciado cliente %s %s estos son los asientos disponibles (Los que estan marcados con 0 estan disponibles.)\n\n", persona.nombre, persona.apellido);
				printf("\t\t\tMapa de los asientos.\n\n");
				for(i=0;i<20;i++){
					printf("Fila %d\t\t\t", (i+1));
					for(j=0;j<4;j++){
						if(j==0){
							printf("%d",matriz[i][j]);
						}else if(j==2){
							printf("\t%d",matriz[i][j]);
						}else{
							printf("%d",matriz[i][j]);
						}
					}
					printf("\n");
				}
				printf("\n");

				//Pedir y verificar si el asiento que deseea el usuario esta disponible
				do{
					printf("\nUsuario %s %s elija la fila del asiento que desee reservar: \n",persona.nombre, persona.apellido);
					scanf("%d",&fila);
					fila=fila-1;
				}while(fila<0 || fila>20);

				do{
					printf("Usuario %s %s elija la columna del asiento que desee reservar: \n",persona.nombre, persona.apellido);
					scanf("%d",&columna);
					columna=columna-1;
				}while(columna<0 || columna>4);

				if(matriz[fila][columna]==0){
					printf("\nUsuario %s %s con numero de identidicacion %s ",persona.nombre, persona.apellido,persona.identificacion);
					printf("\nSu asiento en la fila %d y en la columna %d ha sido reservado exitosamente.\n\n",(fila+1), (columna+1));
					matriz[fila][columna]=1;
				}else{
					printf("\nUsuario %s %s su asiento en la fila %d y en la columna %d esta ocupado, intentelo nuevamente. \n\n",persona.nombre, persona.apellido, (fila+1), (columna+1));
				}
				system("pause");

				break;
			}
			case 2:{
				//Mostrar mapa de asientos
				system("cls");

				printf("\t\t\tMapa de los asientos.\n\n");
				for(i=0;i<20;i++){
					printf("Fila %d\t\t\t", (i+1));
					for(j=0;j<4;j++){
						if(j==0){
							printf("%d",matriz[i][j]);
						}else if(j==2){
							printf("\t%d",matriz[i][j]);
						}else{
							printf("%d",matriz[i][j]);
						}
					}
					printf("\n");
				}
				printf("\n");


				printf("\nUsuario %s %s su ultima reserva fue en la fila %d y en la columna %d (Solamente puede cancelar su ultima reservacion)\n",persona.nombre, persona.apellido, (fila+1),(columna+1));

				//Pedir y verificar si el asiento dado se puede cancelar o si no ha sido reservado por el usuario.
				do{
					printf("\nUsuario %s %s elija la fila del asiento que desea cancelar: \n",persona.nombre, persona.apellido);
					scanf("%d",&fila1);
					fila1=fila1-1;
				}while(fila1<0 || fila1>20);

				do{
					printf("\nUsuario %s %s elija la columna del asiento que desea cancelar: \n",persona.nombre, persona.apellido);
					scanf("%d",&columna1);
					columna1=columna1-1;
				}while(columna1<0 || columna1>4);

				if(fila==fila1 && columna==columna1 && matriz[fila1][columna1]==1){
					printf("\nUsuario %s %s su asiento en la fila %d y en la columna %d ha sido cancelando exitosamente.\n",persona.nombre,persona.apellido,(fila+1),(columna+1));
					matriz[fila1][columna1]=0;
				}else if(fila!=fila1 || columna!=columna1 && matriz[fila1][columna1]==1){
					printf("\nUsuario %s %s el asiento en la fila %d y en la columna %d fue reservado por otro usuario.\n",persona.nombre,persona.apellido,(fila1+1),(columna1+1));
				}else if(matriz[fila1][columna1]==0){
					printf("\nUsuario %s %s el asiento en la fila %d y en la columna %d no ha sido reservado.\n",persona.nombre,persona.apellido,(fila1+1),(columna1+1));
				}
				system("pause");

				break;
			}
			case 3:{
			    system("cls");
			    printf("\t__________________BOLETO_DE_VUELO___________________\n");
			    printf("\t|Usuario %s %s\n",persona.nombre, persona.apellido);
			    printf("\t|Numero de identificacion: %s\n", persona.identificacion);
			    printf("\t|Numero de telefono: %s\n",persona.numero);
			    printf("\t|Asiento reservado en la fila %d y en la columna %d\n",(fila+1),(columna+1));
			    printf("\t|__________________________________________________\n");
			    system("pause");

			break;
			}
			case 4:{
				system("cls");
				printf("Fue un gusto atenderlo %s %s \n",persona.nombre, persona.apellido);
				system("pause");
				exit(0);
				break;
			}
			default:{
				system("cls");
				printf("Esa opcion no esta disponible\n");
				system("pause");
				break;
			}

		}
	}while(opcion>0 || opcion<5);

}
