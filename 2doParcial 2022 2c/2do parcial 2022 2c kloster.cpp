/*UTN
TP Nº:
Autor: Mariano Alejandro Visgarra
Ejercicio:
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

void CargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void CargarLote(){
    int Venta, Dia, Sala, Espectaculo, CantLocalidades;
    float ImporteTotal;
    char NombreEspectaculo[30];

    //extras:
    int pos=0;
    ///Punto A Declaraciones:
    float ImporteMaxDia5=0;
    int EspectaculoMax;
    char NombreEspectaculoMax [30];

    ///Punto B Declaraciones:
    int VecB[10]; //contacdor de acu importes por n espectaculo

    ///Punto C Declaraciones:
    int VecC[31], MayorCantLocalidades,PosMax;

    ///Punto D Declaraciones:
    int VecD[10];


    while(true){
    pos++;
    cout << "VENTA: " << endl;
    cin >> Venta;
    if(Venta==0)break;
    cout << "DIA: " << endl;
    cin >> Dia;
    cout << "SALA (1 a 10): " << endl;
    cin >> Sala;
    cout << "ESPECTACULO (1 a 10): " << endl;
    cin >> Espectaculo;
    cout << "NOMBRE ESPECTACULO: " << endl;
    CargarCadena(NombreEspectaculo, 29);
    cout << "LOCALIDADES: " << endl;
    cin >> CantLocalidades;
    cout << "TOTAL: " << endl;
    cin >> ImporteTotal;
    cout << "Fin carga ================= Elemento Numero: " << pos << endl;
    ///PUNTO D RESOLUCION:
    VecD[Espectaculo-1]+=ImporteTotal;
    ///PUNTO C RESOLUCION:
    VecC[Dia-1]+=CantLocalidades;
    ///PUNTO B RESOLUCION:
    VecB[Espectaculo-1]+=ImporteTotal;

    ///PUNTO A RESOLUCION:
        if (Dia==5){
            if (ImporteMaxDia5==0){
                ImporteMaxDia5=ImporteTotal;
                EspectaculoMax=Espectaculo;
                strcpy(NombreEspectaculoMax,NombreEspectaculo);
            }
            if (ImporteTotal>ImporteMaxDia5){
                ImporteMaxDia5=ImporteTotal;
                EspectaculoMax=Espectaculo;
                strcpy(NombreEspectaculoMax,NombreEspectaculo);
            }
        }
    }
    ///FINAL PUNTO A:
    cout << endl << "PUNTO A: " << "El espectaculo numero " << EspectaculoMax << ": " << NombreEspectaculoMax << " Obtuvo el maximo importe del dia 5 con $" << ImporteMaxDia5 <<endl;
    ///FINAL PUNTO B:
    cout << endl;
    cout << "PUNTO B: " << "Numeros de Espectaculo que no superaron los $100000: "<< endl;
    for(int i=0;i<10;i++){
        if (VecB[i]<100000){
            cout << i+1 << " - ";
        }
    }
    ///FINAL PUNTO C:
    for(int i=0;i<31;i++){
        if (VecC[i]==0) {
            MayorCantLocalidades=VecC[i];
            PosMax=i;
        }
        if (VecC[i]>MayorCantLocalidades){
            MayorCantLocalidades=VecC[i];
            PosMax=i;
        }
    }
    cout << "PUNTO C: El dia con mayor cantidad de Localidades vendidas es: " << PosMax+1 << endl;
    ///FINAL PUNTO D:
    cout << "Espectaculos con importe mayor a 0 en todo el mes de ventas: "<< endl;
    for(int i=0;i<10;i++){
        if(VecD[i]>0){
            cout << i+1 << " - ";
        }
    }
}



int main () {
	int opc;

	while(true){
	cout << "===MENU VENTAS===" <<endl;
	cout << "-----------------" << endl;
	cout << "1. CARGAR DATOS" <<endl;
	cout << "2. PUNTO A." <<endl;
	cout << "3. PUNTO B. " <<endl;
	cout << "4. PUNTO C. " <<endl;
	cout << "5. PUNTO D. " <<endl;
	cout << "-----------------" << endl;
	cout << "0. SALIR." << endl;
	cin >> opc;
	system("cls");
        switch(opc){
        case 1:
            system("cls");
            CargarLote();
            system("cls");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            return 0;
        }
	}


	system("pause");
	return 0;
}
