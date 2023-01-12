/*UTN
TP Nº:
Autor: Mariano Alejandro Visgarra
Ejercicio:
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;


int main () {
    int CiuDestino, Cliente, Dia, Destino, Cant, PuntoVenta, ContPuntoVenta[10]={}, i, AuxA, AuxB=0, ContDestino[50]={}, M1[200][31]={{}};
    float Precio,PuntoC[31], V1[50], Total;


    for(i=0;i<50;i++){
        cout <<"CODIGO CIUDAD DESTINO: "<< endl;
        cin >> CiuDestino;
        cout <<"PRECIO: " << endl;
        cin >> Precio;
        V1[CiuDestino]=Precio;
    }

        cout << "// INGRESO DE DATOS VENTAS //"<<endl;
        cout << "CLIENTE: "<< endl;
        cin >> Cliente;
    while(Cliente!=0){
        if (Cliente==0){break;}
        cout << "DIA: "<< endl;
        cin >> Dia;
        cout << "DESTINO: "<< endl;
        cin >> Destino;
        cout << "CANTIDAD: "<< endl;
        cin >> Cant;
        PuntoC[Dia-1]=V1[Destino-1]*Cant;
        cout << "PUNTO DE VENTA: "<< endl;
        cin >> PuntoVenta;
        cout << "======================" <<endl;
        cout << "CLIENTE: "<< endl;
        cin >> Cliente;
        ContPuntoVenta[PuntoVenta-1]++;
        M1[Cliente][Dia-1]++;
        ContDestino[Destino-1]++;
    }

    ///PUNTO A;
    int IndA;
    AuxA=ContPuntoVenta[0];
    for(i=0;i<10;i++){
        if(ContPuntoVenta[i]>AuxA){
            AuxA=ContPuntoVenta[i];
            IndA=i;
        }
    }
    cout << "Punto A: " << IndA+1 << endl;

    ///PUNTO B;
    int IndB;
    AuxB=ContDestino[0];
    for(i=0;i<50;i++){
        if(ContDestino[i]<AuxB && ContDestino[i]!=0){
            AuxB=ContDestino[i];
            IndB=i;
        }
    }

    cout << "Punto B: " << IndB+1 <<endl;

    ///PUNTO C
    for(i=0;i<31;i++){
        Total+=PuntoC[i];
    }
    for(i=0;i<31;i++){
        cout << "Porcentaje Recaudacion Dia "<< i+1 << ": %" << (PuntoC[i]/Total)*100 << endl;
    }

    ///PUNTO D
    int c=0, T=0;
    for(i=0;i<200;i++){
        for(int j=0;i<31;j++){
            if(M1[Cliente][Dia]==0){
                c++;
                if(c==5){
                    T+=c;
                    c=0;
                    if (T==5){
                    cout << "El cliente " << i << " No compro hace 5 dias" << endl;
                    }
                }
            }
            else{
                c=0;
            }
        }
        T=0;
    }

	cout << "Fin del programa" << endl;
	system("pause");
	return 0;
}
