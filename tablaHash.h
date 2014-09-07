#if !defined(_TABLAHASH_H_)
#define _TABLAHASH_H_


class Ccelda;

class Ctabla 
{
private:
  int n,m,casilla,colicciones,comparaciones_buscar,comparaciones_insertar;
  long dni;
  int num_celdas; //numero de celdas ocupadas
  int H_lineal();  //hash lineal
  int G_lineal();  //busqueda lineal 
  int H_cuadratica();  //exploracion cuadratica
  int G_cuadratica();
  int H_dobleDispersion();
  int G_dobleDispersion();
  int H_redispersion();
  int G_redispersion();
  
    
public:
  Ctabla(int x, int p);  //constructor
  ~Ctabla();
  void inicializa();
  int insertar(long num,int opc);
  int buscar(long num,int opc);
  Ccelda *celda;
  int devnum_celdas();  //devolver numero de celdas ocupadas
  int numero_primo(int numero,int sentido);   //busca el numero primo mas cercano antes o despues del numero dado
  int total_col();  //devolver las colicciones
  int com_bus();    //devolver total comparaciones buscar y insertar
  int com_ins();
  int bloque();
};

class Ccelda
{
private:
  int num;
public:
  Ccelda(int m);  //constructor
  //long *clave; //bloque
  long clave[10];
};  
  

#endif