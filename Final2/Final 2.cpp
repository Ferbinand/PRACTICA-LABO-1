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
    int NumeroCliente, TipoCliente, Cliente, NumComercio, Dia, i;
    float Importe;
    //Para resolver A:
    int ContOperaciones[200]={} ,AuxA;
    //Para resolver B:
    int ContPesosCliente[200][31]={{}}, j;
    //Para resolver C:
    int ContOperacionesComercio[100]={};
    //Para resolver D:
    int AuxD[31]={}, ClienteComercio[200], VecD[31];


	for(i=0;i<2;i++){
        cout <<"Número de Cliente (1 a 200): "<< endl;
        cin >> NumeroCliente;
        cout <<"Tipo de Cliente (1=comercio, 2=empresa, 3=ONG): " << endl;
        cin >> TipoCliente;
        if(TipoCliente==1){ ///Punto D
            ClienteComercio[NumeroCliente-1]=NumeroCliente;
        }
    }

        cout << ">>>"<<endl;
        cout << "// INGRESO DE DATOS OPERACIONES //"<<endl;
        cout << "<<<"<<endl;
        cout << "CLIENTE: "<< endl;
        cin >> Cliente;
    while(Cliente!=0){
        if (Cliente==0){break;}
        cout << "DIA: "<< endl;
        cin >> Dia;
        cout << "IMPORTE: "<< endl;
        cin >> Importe;
        cout << "NUMERO DE COMERCIO "<< endl;
        cin >> NumComercio;
        cout << "======================" <<endl;

        ///PUNTO D
        if(Importe>AuxD[Dia-1]){
            for(i=0;i<200;i++){
                if(ClienteComercio[i]==Cliente){
                    AuxD[Dia-1]=Importe;
                    VecD[Dia-1]=Cliente;
                }
            }
        }

        ContOperaciones[Cliente-1]++;
        ContPesosCliente[Cliente-1][Dia-1]+=Importe;
        ContOperacionesComercio[NumComercio-1]++;
        cout << "CLIENTE: "<< endl;
        cin >> Cliente;
    }

///PUNTO A:
    int IndA;
    AuxA=ContOperaciones[0];
    for(i=0;i<200;i++){
        if(ContOperaciones[i]>AuxA){
            AuxA=ContOperaciones[i];
            IndA=i;
        }
    }
    cout << "Punto A: " << IndA+1 << endl;

///PUNTO B:

    cout << "====== PUNTO B =======" << endl;
    for(i=0;i<200;i++){
        for(j=0;j<31;j++){
            cout << "Numero de cliente: " << i+1 << " Dia: " << j+1 << " Deposito: $"<< ContPesosCliente[i][j] << endl;
        }
    }
///PUNTO C:
    for (i=0;i<100;i++){
        if(ContOperacionesComercio[i]==0){
            cout<< "El comercio " << i+1 << " no informo ventas el mes anterior." << endl;
        }
    }
///PUNTO D:
    for(i=0;i<31;i++){
            cout << "Dia: " << i+1 << " Importe maximo: " << VecD[i] <<endl;
    }



	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
