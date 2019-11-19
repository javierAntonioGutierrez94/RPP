#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "evaluacion.h"
#define CANTCLIENTES 10
#define CANTJUEGOS 10
#define CANTALQUIL 10


/*******************************************************************
*Parcial de Programacion N°1
*
*Objetivo:El objetivo del siguiente trabajo es que el alumno sea capaz de evaluar y realizar los requerimentos solicitados
*utilizando todos sus conocimientos hasta la fecha.
* Variables globales y locales.
* Funciones y Bibliotecas.
* Manejo de arrays.
* Manejo de pasaje por referencia.
* Manejo de estructuras
*
*Version:1.2 del 19 de noviembre de 2019
*Autor:Javier Gutierrez
*
*/

int main()
{
    int mainMenu,answerMain=-1,mainVal=-1,i;
    int clientesMenu,clientesMenuRespuesta=-1,clientesMenuVal=-1,flagClientes=1,aux;
    int informesMenuVal=-1,informesMenu,informesMenuRespuesta=-1;
    float promedio;
    char yesNo;
    //eClientes cliente[CANTCLIENTES];
    eClientes cliente[CANTCLIENTES]={{0,"ape1","nom1",'m',"dom1","12345678",0},
                                    {4,"ape5","nom5",'f',"dom5","12345678",0},
                                    {5,"ape6","nom6",'f',"dom6","12345678",0},
                                    {6,"ape7","nom7",'m',"dom7","12345678",0},
                                    {7,"ape8","nom8",'f',"dom8","12345678",0},
                                    {8,"ape9","nom9",'f',"dom9","12345678",0},
                                    {9,"ape0","nom0",'m',"dom0","12345678",0},
                                    {1,"ape2","nom2",'m',"dom2","12345678",0},
                                    {2,"ape3","nom3",'m',"dom3","12345678",0},
                                    {3,"ape4","nom4",'m',"dom4","12345678",0}};
    //eAlquileres alquiler[CANTALQUIL];
    eAlquileres alquiler[CANTALQUIL]= {{1,1,1,{20,2,2019},0},
                                        {2,2,2,{10,3,2019},0},
                                        {3,3,3,{11,4,2019},0},
                                        {4,4,4,{11,5,2019},0},
                                        {5,5,5,{10,6,2019},0},
                                        {6,6,6,{11,7,2019},0},
                                        {7,7,7,{30,8,2019},0},
                                        {8,8,8,{25,9,2019},0},
                                        {9,9,9,{15,10,2019},0},
                                        {10,1,2,{13,11,2019},0}};

    eJuegos juego[CANTJUEGOS]= {{0,"Castillo Inflable Pequeño",3000},
                                {1,"Castillo Inflable Mediano",4000},
                                {2,"Castillo Inflable Grande",5000},
                                {3,"Cama Elastica Pequeña",3500},
                                {4,"Cama Elastica Mediana",5000},
                                {5,"Cama Elastica Grande",7500},
                                {6,"Set Paintball",9000},
                                {7,"Set Pistolas Laser",12000},
                                {8,"Set Arcade",11000},
                                {9,"Set Zoo",15000}};
    //inicializar(cliente,CANTCLIENTES);
    //iniAlquiler(alquiler,CANTALQUIL);
    do{
        printf("==========MENU PRINCIPAL=========\n");
        printf("\n1)MENU DE CLIENTES\n2)MOSTRAR JUEGOS\n3)ALTAS DE ALQUILER\n4)INFORMAR\n");
        while(mainVal==-1){
            mainVal=getInt(&mainMenu,"\nIngrese Accion:","Opcion no valida intente de nuevo",1,4);
            }
                switch(mainMenu){
                    case 1:{
                        do{
                            printf("==========MENU DE CLIENTES=========\n");
                            printf("\n1)ALTAS\n2)MODIFICAR\n3)BAJA\n4)LISTAR\n5)Salir");
                            while(clientesMenuVal==-1){
                                clientesMenuVal=getInt(&clientesMenu,"\nIngrese Accion:","Opcion no valida intente de nuevo",1,5);
                            }
                            switch(clientesMenu){
                                case 1:{
                                    alta(cliente,CANTCLIENTES);
                                    flagClientes=1;
                                    break;
                                }
                                case 2:{
                                    if(flagClientes==1){
                                        modificar(cliente,CANTCLIENTES);
                                    }else{
                                        printf("\nPrimero cargue al menos un empleado");
                                    }
                                    break;
                                }
                                case 3:{
                                    if(flagClientes==1){
                                        baja(cliente,CANTCLIENTES);
                                    }else{
                                        printf("\nPrimero cargue al menos un empleado");
                                    }
                                    break;
                                }
                                case 4:{
                                    if(flagClientes==1){
                                        listar(cliente,CANTCLIENTES);
                                    }else{
                                        printf("\nPrimero cargue al menos un cliente");
                                    }
                                    break;
                                }
                                case 5:{
                                    break;
                                }
                            }
                            fflush(stdin);
                            clientesMenuRespuesta=getAnswer(&yesNo,"\nRealizara otra accion en Clientes?: ","Solo S / N: ",'S','N');
                            clientesMenuVal=-1;
                        }while(clientesMenuRespuesta==0);
                        break;
                    }
                    case 2:{
                        mostrarJuegos(juego,CANTJUEGOS);
                        break;
                    }
                    case 3:{
                        if(flagClientes==1){
                            printf("\ningrese el Codigo de Cliente: ");
                            fflush(stdin);
                            scanf("%d",&aux);
                            for(i=0;i<CANTCLIENTES;i++){
                                if(aux==cliente[i].codCliente&&cliente[i].isEmpty==0){
                                    altaAlquiler(alquiler,CANTALQUIL);
                                }
                            }
                        }else{
                            printf("Primero cargue al menos un cliente");
                        }
                        break;
                    }
                    case 4:{
                        if(flagClientes==1){
                            do{
                                printf("==========MENU DE INFORMES=========\n");
                                printf("\nInforme 7\nInforme 8\nInforme 9\nInforme 10\nInforme 11\nInforme 12\nInforme 13\nInforme 14\nInforme 15\nInforme 16\n17) Salir");
                                while(informesMenuVal==-1){
                                    informesMenuVal=getInt(&informesMenu,"\nIngrese Accion:","\nOpcion no valida intente de nuevo",7,17);
                                }
                                switch(informesMenu){
                                    case 7:{
                                        promedio=informe7(alquiler,CANTALQUIL,juego,CANTJUEGOS);
                                        break;
                                    }
                                    case 8:{
                                        informe8(promedio,juego,CANTJUEGOS);
                                        break;
                                    }
                                    case 9:{
                                        informe9(alquiler,CANTALQUIL,cliente,CANTCLIENTES);
                                        break;
                                    }
                                    case 10:{
                                        informe10(alquiler,CANTALQUIL,juego,CANTJUEGOS);
                                        break;
                                    }
                                    case 11:{
                                        informe11(alquiler,CANTALQUIL,juego,CANTJUEGOS);
                                        break;
                                    }
                                    case 12:{
                                        informe12(alquiler,CANTALQUIL,cliente,CANTCLIENTES);
                                        break;
                                    }
                                    case 13:{
                                        informe13(alquiler,CANTALQUIL,juego,CANTJUEGOS);
                                        break;
                                    }
                                    case 14:{
                                        informe14(alquiler,CANTALQUIL,cliente,CANTCLIENTES);
                                        break;
                                    }
                                    case 15:{
                                        informe15(juego,CANTJUEGOS);
                                        break;
                                    }
                                    case 16:{
                                        informe16(cliente,CANTCLIENTES);
                                        break;
                                    }
                                    case 17:{
                                        break;
                                    }
                                }
                                fflush(stdin);
                                informesMenuRespuesta=getAnswer(&yesNo,"\nRealizara otra accion en INFORMES?: ","Solo S / N: ",'S','N');
                                informesMenuVal=-1;
                                system("cls");
                            }while(informesMenuRespuesta==0);
                            break;
                        }else{
                            printf("No se cargo nada");
                        }
                        break;
                    }
                }
        fflush(stdin);
        answerMain=getAnswer(&yesNo,"\nRealizara otra accion?: ","Solo S / N: ",'S','N');
        mainVal=-1;
        system("cls");
    }while(answerMain==0);
    return 0;
}

