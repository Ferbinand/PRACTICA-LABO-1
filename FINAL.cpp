/*UTN
TP Nº:
Autor: Mariano Alejandro Visgarra
Ejercicio:
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

void InicializarMatrizCero(int M[][4], int f, int c){
    int i,j;
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            M[i][j]=0;
        }
    }
}


void InicializarEnCero(int *v, int t){
    int i;
    for(i=0;i<t;i++){
        v[i]=0;
    }
}


void MostrarVector(int *v, int t){
    int i;
    for(i=0;i<t;i++){
        cout << "Sucursal: "<< i+1 << "]: " << v[i] << " ";
    }
}

void ZapatosNoPantuflas(int *v, int t, int *v2, int t2){
    int i;
    int ContSucursalesZnoP=0;
    for(i=0;i<t;i++){
        if(v[i]>0 && v2[i]==0){
            ContSucursalesZnoP++;
        }
    }
    cout << "Cantidad de sucursales que vendieron Zapatos pero No Pantuflas: " << ContSucursalesZnoP << endl;
}


void PuntoC(int M[][4], int f, int c){
    int i,j, mayor,PosTipo;
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            if(i==0 && j==0){
                mayor=M[i][j];
            }
            else if (M[i][j]>mayor){
                mayor=M[i][j];
                PosTipo=j;
            }
        }
        if (PosTipo==0)
        cout << "Mes " << i+1 << " El tipo de calzado mas vendido es: Z" <<endl;
        if (PosTipo==1)
        cout << "Mes " << i+1 << " El tipo de calzado mas vendido es: X" <<endl;
        if (PosTipo==2)
        cout << "Mes " << i+1 << " El tipo de calzado mas vendido es: P" <<endl;
        if (PosTipo==3)
        cout << "Mes " << i+1 << " El tipo de calzado mas vendido es: O" <<endl;
        mayor=0;
        PosTipo=0;
    }
}



int main () {
    int Sucursal, Mes, NumTalle;
    char TipoCalzado;
    float Importe;

    int PuntoA[8];
    int VecZapatos[8], VecPantuflas[8];
    int VecC[6][4];

    InicializarEnCero(PuntoA, 8);
    InicializarEnCero(VecZapatos, 8);
    InicializarEnCero(VecPantuflas, 8);
    InicializarMatrizCero(VecC,6,4);

    do{
        cout <<"SUCURSAL: ";
        cin>>Sucursal;
        if(Sucursal==0) break;
        cout << endl;
        cout <<"MES: ";
        cin>>Mes;
        cout << endl;
        cout <<"TIPO DE CALZADO: ";
        cin>>TipoCalzado;
        cout << endl;
        cout <<"TALLE: ";
        cin>>NumTalle;
        cout << endl;
        cout <<"IMPORTE: ";
        cin>>Importe;
        cout << endl;
        //punto a
        if(NumTalle>40){PuntoA[Sucursal-1]++;}
        //punto b
        if(TipoCalzado=='Z') VecZapatos[Sucursal-1]++;
        if(TipoCalzado=='P') VecPantuflas[Sucursal-1]++;
        //punto c
        if(TipoCalzado=='Z')VecC[Mes-1][0]++;
        if(TipoCalzado=='X')VecC[Mes-1][1]++;
        if(TipoCalzado=='P')VecC[Mes-1][2]++;
        if(TipoCalzado=='O')VecC[Mes-1][3]++;

    }while(Sucursal!=0);

    cout << "Punto A: "<<endl;
    MostrarVector(PuntoA, 8);

    cout << endl << "Punto B: "<< endl;
    ZapatosNoPantuflas(VecZapatos, 8, VecPantuflas,8);

    cout << endl << "Punto C: "<< endl;
    PuntoC(VecC,6,4);


	system("pause");
	return 0;
}
