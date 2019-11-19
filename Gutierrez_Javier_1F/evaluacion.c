#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "evaluacion.h"


void inicializar(eClientes* client, int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        client[i].isEmpty=1;
    }
}

void alta(eClientes* client, int cantidad){
    int i,end,flag=1,rta=-1;
    char endChar;
    for(i=0;i<cantidad;i++){
        if(client[i].isEmpty==1){
            printf("\nSe contro lugar");
            flag=0;
            client[i].codCliente=i;
            fflush(stdin);
            while(rta!=0){
                rta=getString(client[i].nombre,"\nIngrese el nombre: ","\nDemasiado largo intente de nuevo",1,31);
            }
            rta=-1;
            fflush(stdin);
            while(rta!=0){
                rta=getString(client[i].apellido,"\nIngrese el apellido: ","\nDemasiado largo intente de nuevo",1,31);
            }
            rta=-1;
            fflush(stdin);
            rta=getGen(&client[i].sexo,"\nIngrese el sexo m/f: ","\nSolo f/m",'f','m');
            rta=-1;
            fflush(stdin);
            while(rta!=0){
                rta=getString(client[i].domicilio,"\nIngrese el domicilio: ","\nDemasiado largo intente de nuevo",1,51);
            }
            rta=-1;
            fflush(stdin);
            while(rta!=0){
                rta=getString(client[i].telefono,"\nIngrese el telefono: ","\nDemasiado largo intente de nuevo",1,21);
            }
            rta=-1;
            client[i].isEmpty=0;
            end=getAnswer(&endChar,"\nDesea seguir cargando otro Cliente?","Solo s/n",'s','n');
            if(end==-1){
                break;
            }
        }if(flag!=0){
            printf("\nNo se cargo ningun cliente");
        }
    }
}

void modificar(eClientes *client, int cantidad){
    int auxCod,flag=-1,flag2=0,i,menuMod,end,optionMenuMod=-1,rta;
    char aux[31];
    char auxTel[31];
    char auxDir[51];
    char keepGoing,auxSexo;
    printf("ingrese el Codigo de la persona: ");
    fflush(stdin);
    scanf("%d",&auxCod);
    for(i=0;i<cantidad;i++){
        if(auxCod==client[i].codCliente){
            flag=0;
            printf("___________________________________________________________________________\n");
            printf("Esta es la persona con ese ID:");
            printf("\nCodigo:%d\nNombre:%s\nApellido:%s\nSexo:%c\nDireccion:%s\nTelefono:%s",client[i].codCliente,client[i].nombre,client[i].apellido,client[i].sexo,client[i].domicilio,client[i].telefono);
            do{
                printf("\n\n======MENU Modificacion de Cliente=======");
                printf("\n1) Modificar Apellido");
                printf("\n2) Modificar Nombre");
                printf("\n3) Modificar Sexo");
                printf("\n4) Modificar Domicilio");
                printf("\n5) Modificar Telefono");
                printf("\n6) Salir");
                while(optionMenuMod!=0){
                    fflush(stdin);
                    optionMenuMod=getInt(&menuMod,"\nQue desea modificar?:\n","opcion no valida",1,6);
                }
                optionMenuMod=-1;
                switch(menuMod){
                    case 1:{
                        while(rta!=0){
                            rta=getString(aux,"\nIngrese el Apellido: ","\nDemasiado largo intente de nuevo",1,31);
                        }
                        rta=-1;
                        fflush(stdin);
                        strcpy(client[i].apellido,aux);
                        flag2=1;
                        break;
                    }
                    case 2:{
                        fflush(stdin);
                        while(rta!=0){
                            rta=getString(aux,"\nIngrese el nombre: ","\nDemasiado largo intente de nuevo",1,31);
                        }
                        rta=-1;
                        fflush(stdin);
                        strcpy(client[i].nombre,aux);
                        flag2=1;
                        break;
                    }
                    case 3:{
                        fflush(stdin);
                        while(rta!=0){
                            rta=getAnswer(&auxSexo,"\nIngrese el sexo m/f: ","\nSolo m/f",'f','m');
                        }
                        rta=-1;
                        client[i].sexo=auxSexo;
                        flag2=1;
                        break;
                    }
                    case 4:{
                        fflush(stdin);
                        while(rta!=0){
                            rta=getString(auxDir,"\nIngrese el domicilio: ","\nDemasiado largo intente de nuevo",1,51);
                        }
                        rta=-1;
                        strcpy(client[i].domicilio,auxDir);
                        flag2=1;
                        break;
                    }
                    case 5:{
                        fflush(stdin);
                        while(rta!=0){
                            rta=getString(auxTel,"\nIngrese el Telefono: ","\nDemasiado largo intente de nuevo",1,21);
                        }
                        strcpy(client[i].telefono,auxTel);
                        rta=-1;
                        flag2=0;
                        break;
                    }
                    case 6:{
                        flag2=0;
                        break;
                    }
                }
                if(flag2==0){
                    printf("\nNo se modifico ningun dato");
                }else{
                    printf("\nLos Datos se modificaron correctamente");
                }
                fflush(stdin);
                end=getAnswer(&keepGoing,"\nDesea seguir modificando datos?","Solo s/n",'s','n');
            }while(end!=-1);
        }else if(flag==-1){
            printf("No se encontro nadie con ese codigo");
        }
    }
}

void baja(eClientes *client, int cantidad){
    int auxCod,flag1=0,i=0,response=-1;
    char keepGoing;
    printf("\nIngrese el Codigo de la persona: ");
    fflush(stdin);
    scanf("%d",&auxCod);
    printf("___________________________________________________________________________\n");
    printf("Esta es la persona con ese Codigo:");
    printf("\nCodigo:%d\nNombre:%s\nApellido:%s\nSexo:%c\nDireccion:%s\nTelefono:%s",client[i].codCliente,client[i].nombre,client[i].apellido,client[i].sexo,client[i].domicilio,client[i].telefono);
    for(i=0;i<cantidad;i++){
        if(auxCod==client[i].codCliente){
            response=getAnswer(&keepGoing,"Desea dar de baja? s/n","Solo s/n",'s','n');
            if(response==0){
                client[i].isEmpty=1;
                flag1=1;
                break;
            }else{
                printf("No se modificaron los datos");
            }
        }
        response=-1;
    }
    if(flag1==0){
        printf("No se encontro el registro");
    }
}

void listar(eClientes *client, int cantidad){
    int i,j, bandera;
    int temp,temp1;
    eClientes aux;
    for(i=1; i<cantidad; i++){
        bandera=0;
        for(j=cantidad-1; j>=i; j--){
            temp=strcmp(client[j-1].apellido,client[j].apellido);
            if(temp>0){
                aux=client[j];
                client[j]=client[j-1];
                client[j-1]=aux;
                bandera=1;
            }else if(temp==0){
                temp1=strcmp(client[j-1].nombre,client[j].nombre);
                aux=client[j];
                if(temp1>0){
                        client[j]=client[j-1];
                        client[j-1]=aux;
                        bandera=1;
                }
            }
        }
        if (bandera==0)
        break;
    }
    for(i=0;i<cantidad;i++){
        if(client[i].isEmpty==0){
            printf("___________________________________________________________________________\n");
            printf("\nCodigo:%d\nNombre:%s\nApellido:%s\nSexo: %c\nDireccion: %s\nTelefono: %s",client[i].codCliente,client[i].nombre,client[i].apellido,client[i].sexo,client[i].domicilio,client[i].telefono);
        }
    }
}

void mostrarJuegos(eJuegos* juego,int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        printf("------------------------------------------------------\n");
        printf("Codigo: %d\n",juego[i].codJuego);
        printf("Descripcion: %s\n",juego[i].descripcion);
        printf("Precio: $%.2f\n",juego[i].importe);
    }
}

void iniAlquiler(eAlquileres* alquiler, int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        alquiler[i].isEmpty=1;
    }
}

void altaAlquiler(eAlquileres* alquiler,int cantidad){
    int i,end,rta=-1,aux;
    int lugar=1;
    char endChar;
    for(i=0;i<cantidad;i++){
        if(alquiler[i].isEmpty==1){
            lugar=0;
            alquiler[i].codAlquiler=i+1;
            fflush(stdin);
            while(rta!=0){
                rta=getInt(&aux,"\ningrese el Codigo de Juego: ","Intente de nuevo",1,3);
            }
            alquiler[i].codJuego=aux;
            rta=-1;
            fflush(stdin);
            printf("\ningrese la Fecha: ");
            while(rta!=0){
                rta=getInt(&aux,"\nDia: ","Intente de nuevo",1,31);
            }
            rta=-1;
            alquiler[i].fecha.dia=aux;
            while(rta!=0){
                rta=getInt(&aux,"\nMes: ","Intente de nuevo",1,12);
            }
            rta=-1;
            alquiler[i].fecha.mes=aux;
            while(rta!=0){
                rta=getInt(&aux,"\nAnio: ","Intente de nuevo",2019,2021);
            }
            rta=-1;
            alquiler[i].fecha.anio=aux;
            alquiler[i].isEmpty=0;
        end=getAnswer(&endChar,"Desea seguir cargando otro alquiler?","Solo s/n",'s','n');
        if(end==-1){
            break;
            }
        }
    }
    if(lugar==1){
        printf("\nNo hay mas lugar");
    }
}

float informe7(eAlquileres* alquiler,int cantidad,eJuegos* juego, int cantidad2){
    int i,j,aux;
    int acumulador=0;
    float sumador=0;
    float promedio=0;
    for(i=0;i<cantidad;i++){
        if(alquiler[i].isEmpty==0){
                aux=alquiler[i].codJuego;
            for(j=0;j<cantidad2;j++){
                    if(juego[j].codJuego==aux){
                        sumador=sumador+juego[j].importe;
                        acumulador++;
                    }
            }
        }
    }
    promedio=sumador/acumulador;
    printf("\nEl promedio es: %.2f y el Total de los importes es: %.2f \nde todos los juegos alquilados.",promedio,sumador);
    return promedio;
}

void informe8(float promedio,eJuegos* juego,int cantidad){
    int i;
    int contador=0;
    for(i=0;i<cantidad;i++){
        if(promedio>juego[i].importe){
            contador++;
        }
    }
    printf("\nLa cantidad de juegos que No supera el promedio total de los juegos alquilados es %d",contador);
}

void informe9(eAlquileres* alquiler,int cantidad,eClientes* cliente,int cantidad2){
    int aux,aux2,i,j;
    printf("\nIngrese el codigo de el juego: ");
    fflush(stdin);
    scanf("%d",&aux);
    for(i=0;i<cantidad;i++){
        if(alquiler[i].codJuego==aux&&alquiler[i].isEmpty==0){
            aux2=alquiler[i].codCliente;
                for(j=0;j<cantidad2;j++){
                    if(cliente[j].codCliente==aux2&&cliente[j].isEmpty==0){
                    printf("\nCodigo: %d",cliente[j].codCliente);
                    printf("\nApellido: %s",cliente[j].apellido);
                    printf("\nNombre: %s",cliente[j].nombre);
                    printf("\nSexo: %c",cliente[j].sexo);
                    printf("\nDomicilio: %s",cliente[j].domicilio);
                    printf("\nTelefono: %s",cliente[j].telefono);
                    printf("\n_________________________________________________________");
                }
            }
        }
    }
}

void informe10(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2){
    int aux,aux2,i,j;
    printf("\nIngrese el codigo de el Cliente: ");
    fflush(stdin);
    scanf("%d",&aux);
    for(i=0;i<cantidad;i++){
        if(alquiler[i].codCliente==aux){
            aux2=alquiler[i].codJuego;
                for(j=0;j<cantidad2;j++){
                    if(juego[j].codJuego==aux2){
                    printf("\nCodigo: %d\n",juego[j].codJuego);
                    printf("Descripcion: %s\n",juego[j].descripcion);
                    printf("Precio: $%.2f\n",juego[j].importe);
                    printf("\n_________________________________________________________");
                }
            }
        }
    }
}

void informe11(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2){
    int i,j;
    int max;
    int min;
    int flag=0;
    int contador[cantidad2];
    for(i=0;i<cantidad2;i++){
        contador[i]=0;
    }
    for(i=0;i<cantidad2;i++){
        for(j=0;j<cantidad;j++){
            if(juego[i].codJuego==alquiler[j].codJuego){
                contador[i]++;
            }
        }
    }
    for(i=0;i<cantidad2;i++){
        if(flag==0){
            max=contador[i];
            min=contador[i];
        }
        if(contador[i]>max) {
                max = contador[i];
        }
        if(contador[i]<min) {
                min = contador[i];
        }
        flag++;
    }
    printf("\nJuego/s alquilados menor cantidad de veces:\n");

    for(i=0;i<cantidad2;i++){
        if(contador[i]==min){
            printf("------------------------------------------------------\n");
            printf("Codigo: %d\n",juego[i].codJuego);
            printf("Descripcion: %s\n",juego[i].descripcion);
            printf("Precio: $%.2f\n",juego[i].importe);
        }
    }
}

void informe12(eAlquileres* alquiler,int cantidad,eClientes* cliente,int cantidad2){

    int i,j;
    int max;
    int min;
    int flag=0;
    int contador[cantidad2];
    for(i=0;i<cantidad2;i++){
        contador[i]=0;
    }
    for(i=0;i<cantidad2;i++){
        for(j=0;j<cantidad;j++){
            if(cliente[i].codCliente==alquiler[j].codCliente){
                contador[i]++;
            }
        }
    }
    for(i=0;i<cantidad2;i++){
        if(flag==0){
            max=contador[i];
            min=contador[i];
        }
        if(contador[i]>max) {
                max = contador[i];
        }
        if(contador[i]<min) {
                min = contador[i];
        }
        flag++;
    }
    printf("\nLa/s persona/s que alquilaron mas cantidad de veces:\n");

    for(i=0;i<cantidad2;i++){
        if(contador[i]==max){
            printf("\nCodigo:%d\nNombre:%s\nApellido:%s\nSexo:%c\nDireccion:%s\nTelefono:%s",cliente[i].codCliente,cliente[i].nombre,cliente[i].apellido,cliente[i].sexo,cliente[i].domicilio,cliente[i].telefono);
        }
    }
}

void informe13(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2){
    int i,j,aux,rta;
    eFecha auxFecha;
    int auxCodJuego;
    printf("\nIngrese la fecha a buscar: ");
    while(rta!=0){
        rta=getInt(&aux,"\nDia: ","Intente de nuevo",1,31);
    }
    rta=-1;
    auxFecha.dia=aux;
    while(rta!=0){
        rta=getInt(&aux,"\nMes: ","Intente de nuevo",1,12);
    }
    rta=-1;
    auxFecha.mes=aux;
    while(rta!=0){
        rta=getInt(&aux,"\nAnio: ","Intente de nuevo",2019,2021);
    }
    rta=-1;
    auxFecha.anio=aux;
    for(i=0;i<cantidad;i++){
        if(alquiler[i].fecha.dia==auxFecha.dia&&alquiler[i].fecha.mes==auxFecha.mes&&alquiler[i].fecha.anio==auxFecha.anio){
            auxCodJuego=alquiler[i].codJuego;
            for(j=0;j<cantidad2;j++){
                if(juego[j].codJuego==auxCodJuego){
                    printf("------------------------------------------------------\n");
                    printf("Codigo: %d\n",juego[j].codJuego);
                    printf("Descripcion: %s\n",juego[j].descripcion);
                    printf("Precio: $%.2f\n",juego[j].importe);
                }
            }
        }
    }
}

void informe14(eAlquileres* alquiler,int cantidad,eClientes* client,int cantidad2){
    int i,j,aux,rta;
    eFecha auxFecha;
    int auxCodCliente;
    printf("\nIngrese la fecha a buscar: ");
    while(rta!=0){
        rta=getInt(&aux,"\nDia: ","Intente de nuevo",1,31);
    }
    rta=-1;
    auxFecha.dia=aux;
    while(rta!=0){
        rta=getInt(&aux,"\nMes: ","Intente de nuevo",1,12);
    }
    rta=-1;
    auxFecha.mes=aux;
    while(rta!=0){
        rta=getInt(&aux,"\nAnio: ","Intente de nuevo",2019,2021);
    }
    rta=-1;
    auxFecha.anio=aux;
    for(i=0;i<cantidad;i++){
        if(alquiler[i].fecha.dia==auxFecha.dia&&alquiler[i].fecha.mes==auxFecha.mes&&alquiler[i].fecha.anio==auxFecha.anio){
            auxCodCliente=alquiler[i].codCliente;
            for(j=0;j<cantidad2;j++){
                if(client[j].codCliente==auxCodCliente){
                    printf("\n_________________________________________________________");
                    printf("\nCodigo: %d",client[j].codCliente);
                    printf("\nApellido: %s",client[j].apellido);
                    printf("\nNombre: %s",client[j].nombre);
                    printf("\nSexo: %c",client[j].sexo);
                    printf("\nDomicilio: %s",client[j].domicilio);
                    printf("\nTelefono: %s",client[j].telefono);
                    printf("\n_________________________________________________________");
                }
            }
        }
    }
}

void informe15(eJuegos* juego,int cantidad){
    int j;
    float aux;
    int flagNoEstaOrdenado=1;
    while (flagNoEstaOrdenado==1){
        flagNoEstaOrdenado=0;
        for(j=1;j<cantidad;j++){
            if (juego[j].importe<juego[j-1].importe){
                aux = juego[j].importe;
                juego[j].importe = juego[j-1].importe;
                juego[j-1].importe = aux;
                flagNoEstaOrdenado=1;
            }
        }
    }
    mostrarJuegos(juego,cantidad);
}

void informe16(eClientes* client,int cantidad){
     int i, j;
     char temp[31];
     for(i=0; i<cantidad; i++){
         strcpy(temp,client[i].apellido);
         j=i-1;
         while(j>=0 && 1==(strcmp(client[j].apellido,temp))){
             strcpy(client[j+1].apellido,client[j].apellido);
             j--;
         }
        strcpy(client[j+1].apellido,temp);
     }
     for(i=0;i<cantidad;i++){
        printf("\n________________________________________________________________________");
        printf("\nCodigo:%d\nNombre:%s\nApellido:%s\nSexo:%c\nDireccion:%s\nTelefono:%s",client[i].codCliente,client[i].nombre,client[i].apellido,client[i].sexo,client[i].domicilio,client[i].telefono);
    }
}
