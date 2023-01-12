/*
PROBLEMA 1
Una matriz entera de 5x5 se considera Simoniana si el valor máximo
de la matriz se encuentra en cada una de las filas de la misma.
Hacer una función llamada EsMatrizSimoniana que reciba una matriz
entera de 5x5 y devuelva true si es Simoniana o false si no lo es.

PROBLEMA 2
Se dispone de los registros de las exportaciones realizadas en el año 2022
de diez productos elaborados en Argentina. Cada registro tiene el siguiente
formato:
Número de producto (1 a 10)
Día (entero)
Mes (entero)
Tipo (10 - carne, 20 - cereales, 30 - frutas y hortalizas, 40 - hierro y acero)
Continente de destino (1 - América, 2 - Asia, 3 - Europa, 4 - África, 5 - Oceanía)
Cantidad de kilos exportados

La información no se encuentra agrupada ni ordenada. El fin de la carga
de datos se indica con número de producto igual a cero.

Se pide calcular e informar:
A) Por cada producto, la cantidad de toneladas exportadas a cada continente.
B) El nombre del tipo de producto más exportado en Octubre de 2022.
C) Los continentes a los que no se exportó, en total, más de 5000 kilos de carne.
D) El número de mes que mayor cantidad de toneladas de cereales haya exportado.

Nota: Una tonelada equivale a 1000 kilos

*/


#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;


void InicializarVectorEnCero(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}
void MostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout << "["<< i << "]" << v[i];
    }
}

void BuscarMayorVec(int *v,int tam){ //busca pos y numero mayor dentro de vec
    int i, Mayor, PosMayor=0;
    Mayor=v[0];
    for (i=0;i<tam;i++){
        if(v[i]>Mayor){
            Mayor=v[i];
            PosMayor=i;
        }
    }
    if (PosMayor==0) cout << "Producto mas exportado: Carne" << endl;
    if (PosMayor==1) cout << "Producto mas exportado: Cereales" << endl;
    if (PosMayor==2) cout << "Producto mas exportado: Frutas y hortalizas" << endl;
    if (PosMayor==3) cout << "Producto mas exportado: Hierro" << endl;

    cout << "Para el punto D el mes con mas kilos exportados de cereales es: " << PosMayor+1 << endl;
}

void VectorMenorA (int *v,int tam,int comp){ // numeros que no llegan a 5000 dentro de vec
    int i;
    for(i=0;i<tam;i++){
        if (v[i]<comp){
            cout << "En el continente " << i+1 << " no se vendieron mas de 5 toneladas"<< endl;
        }
    }
}


void InicializarMatrizCero(int M[][5], int f, int c){
    int i,j;
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            M[i][j]=0;
        }
    }
}


void InicializarMatriz(int M[][5]){
    int i,j;
    cout << "Ingrese los numeros de la matriz segun la posicion "<<endl;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout << "[" << i <<"]" << "["<< j <<"]: ";
            cin>>M[i][j];
        }
        cout << endl;
    }
}

///BUSQUEDA DE MAYOR EN MATRIZ 5X5
bool EsMatrizSimoniana(int M[][5]){
    int i,j, mayor;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==0 && j==0){
                mayor=M[i][j];
            }
            else if (M[i][j]>mayor){
                mayor=M[i][j];
            }
        }
    }
    cout << "El numero mayor de la matriz es: " << mayor <<endl;

///DETECTAR VALOR MAXIMO POR FILA MATRIZ 5X5

int m=0,c=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (M[i][j]==mayor){
                c++;
            }
        }
        if(c>0){
            m++;
            c=0;}
    }

    if(m>=5)return true;

    else return false;
}

void MostrarMatriz (int M[][5]){
    int i,j;
    for(i=0;i<5;i++){
        cout << "| ";
        for(j=0;j<5;j++){
            cout << setw(3) << M[i][j]<< " | ";
        }
        cout << endl;
    }
    cout << endl;
}

void MostrarMatriz2 (int M[][5],int f,int c){
    int i,j;
    for(i=0;i<10;i++){
        cout << "| ";
        for(j=0;j<5;j++){
            cout << setw(8) << M[i][j]<< " | ";
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    ///PROBLEMA 1
	int M1[5][5];
    //InicializarMatrizCero(M1);
    MostrarMatriz(M1);
    cout << "Es matriz simoniana?: ";
    if(EsMatrizSimoniana(M1)==true){
        cout << "SI" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    ///PROBLEMA 2
    int NumProducto, Dia, Mes, Tipo, Continente;
    float Kilos;

    int MatrizA[10][5];
    int VecB[4];
    int VecC[5];
    int VecD[12];

    InicializarVectorEnCero(VecB,4);
    InicializarVectorEnCero(VecC,5);
    InicializarVectorEnCero(VecD,12);
    InicializarMatrizCero(MatrizA,10,5);

    do{
        cout <<"NUM PRODUCTO: ";
        cin>>NumProducto;
        if (NumProducto==0) break;
        cout << endl;
        cout <<"DIA: ";
        cin>>Dia;
        cout << endl;
        cout <<"MES: ";
        cin>>Mes;
        cout << endl;
        cout <<"TIPO: ";
        cin>>Tipo;
        cout << endl;
        cout <<"CONTINENTE: ";
        cin>>Continente;
        cout << endl;
        cout <<"KILOS: ";
        cin>>Kilos;
        cout << endl;
        MatrizA[NumProducto-1][Continente-1]+=Kilos;
        if (Mes==10) VecB[(Tipo/10)-1]++;
        if (Tipo==10) VecC[Continente-1]+=Kilos;
        if (Tipo==20) VecD[Mes-1]+=Kilos;
    }while(NumProducto!=0);

    cout << "PUNTO A: " << endl;
    MostrarMatriz2(MatrizA, 10, 5);
	cout << endl;

	cout << "PUNTO B: " << endl;
	BuscarMayorVec(VecB,4);
	cout << endl;

	cout << "PUNTO C: " << endl;
    VectorMenorA(VecC,5, 5000);
	cout << endl;

	cout << "PUNTO D: " << endl;
    BuscarMayorVec(VecD,12);
	cout << endl;

	system("pause");
	return 0;
}
