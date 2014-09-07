#include "tablaHash.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>    //para setprecision en el cout

#define TAM 50000000

using namespace std;

main()
{
  
  int nceldas,bloques,explora,carga,pruebas,i,dato,minimo_b,maximo_b,minimo_i,maximo_i;
  long dni=0;
  string  muestra;
  
  vector<long> banco(TAM,0);  //donde guardamos los dni
  
  
  nceldas=bloques=explora=carga=pruebas=minimo_b=maximo_b=minimo_i=maximo_i=0;
  
  for(i=0;i<TAM;i++)
  {
    dni= rand() % TAM + 25000001; //numero aleatorio entre 25.000.001 y 75000000;
    banco[i]=dni;
  };  

    
  cout << "NUMERO DE CELDAS: ";
  cin >> nceldas;
  cout << "\nTAMAÑO DE BLOQUES: ";
  cin >> bloques;
  cout << "\nMETODO DE EXPLORACION:(0:Lineal,1:Cuadratica,2:dobleDispersion,3:Redispersion):";
  cin >> explora;
  cout << "\nFACTOR DE CARGA:(valor entero de celdas)ej:500 ";
  cin >> carga;
  cout << "\nNUMERO DE PRUEBAS: ";
  cin >> pruebas;
  
  Ctabla tabla(nceldas,bloques);
  tabla.inicializa();
  
  vector<long> vCarga(carga,0);  //los dni que guardamos en la tabla
  for(i=0;i<carga;i++)
  {    
    vCarga[i]=banco[rand() % TAM];
    tabla.insertar(vCarga[i],explora);  //metemos todos los dni de la carga
  };
  
  
  minimo_b=TAM;  //minimo_b minimo de comparaciones en busqueda
  minimo_i=TAM;  //minimo_b minimo de comparaciones en insertar
  
  for(i=0;i<pruebas;i++)  //realizamos las pruebas, y vamos tomando el numero maximo y minimos de comparaciones
  {  
    if(explora==3)   //si queremos redispersion debemos destruir la tabla B y crear una nueva a 2*B primo, copiar elementos a la nueva de la vieja tabla.
    {
     tabla.~Ctabla();   //llamamos al destructor Y destruimos las celdas
     nceldas*=2;
     tabla.numero_primo(nceldas,1);  //buscamos un numero primo cercano a nceldas
     Ctabla tabla(nceldas,bloques);  //creamos la nueva tabla redimencionada
    }
    
    tabla.insertar(rand()%TAM,explora);
    tabla.buscar(vCarga[rand() % carga],explora);
    
    if(minimo_b > tabla.com_bus())
      minimo_b=tabla.com_bus();
    if(minimo_i > tabla.com_ins())
      minimo_i=tabla.com_ins();
    if(maximo_b < tabla.com_bus())
      maximo_b=tabla.com_bus();
    if(maximo_i < tabla.com_ins())
      maximo_i=tabla.com_ins();
      
  };
  
  switch(explora)
  {
    case(0):
      muestra="LINEAL    ";
      break;
    case(1):
      muestra="CUADRATICA";
      break;
    case(2):
      muestra="DOBLE     ";
      break;
    case(3):
      muestra="REHASH    ";
      break;
  };
  
  
  cout << "\n\n\tCELDAS\tBLOQUES\tEXPLORACION\tCARGA\tPRUEBAS\n";
  cout << "\t------"  << "\t------" << "\t-----------"  << "\t-----"  << "\t------"  << endl;
  cout << "\t" << nceldas << "\t" << bloques << "\t" << muestra << "\t" << fixed << setprecision( 2 ) << float(tabla.devnum_celdas())/((nceldas*bloques)) << "\t" << pruebas << endl << endl;  //factor carga insertados/total celdas
  cout << "\t\t\tNUMEROS DE COMPARACIONES" << "\n\t\t\t------------------------" << endl;
  cout << "\t\t\tMINIMO" << "\tMEDIO" << "\tMAXIMO" << endl;
  cout << "\t\t\t------" << "\t-----" << "\t------" << endl;
  cout << "\tBUSQUEDAS" << "\t" << minimo_b << "\t" << (maximo_b+minimo_b)/2 << "\t" << maximo_b << endl;
  cout << "\tINSERCION" << "\t" << minimo_i << "\t" << (maximo_i+minimo_i)/2 << "\t" << maximo_i << endl;
                  
  
  
    
}  


















    
  