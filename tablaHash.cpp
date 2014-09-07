#include "tablaHash.h"

Ccelda::Ccelda(int m)
{
  num=m;
  //clave = new long[m];  //bloques de tamaño m
  
}; 


Ctabla::Ctabla(int x, int p)
{
  n=x;
  m=p;
  comparaciones_buscar=comparaciones_insertar=colicciones=num_celdas=0;
   
  for(int i=0;i<n;i++)
    celda= new Ccelda(p);
  
};

int Ctabla::H_lineal()
{
    for(int i = casilla; i < n;i++)
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == -1)
      {
	comparaciones_insertar++;
	celda[i].clave[j]=dni;
	num_celdas++;
	return(1);
      }
      else
      {
	colicciones++;
	comparaciones_insertar++;
      }
      
    }
   for(int i = 0; i < n;i++)  //si no encuentra desde la posicion al final, volvemos al principio de la serie
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == -1)
      {
	comparaciones_insertar++;
	celda[i].clave[j]=dni;
	num_celdas++;
	return(1);
      }
      else
      {
	colicciones++;
	comparaciones_insertar++;
      }
    } 
    
};

int Ctabla::G_lineal()
{
  for(int i = casilla; i < n;i++)
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == dni)
      {
	comparaciones_buscar++;
	return(1);	
      }
      else
      {
	if(celda[i].clave[j] == -1)   //si lo encuentra vacio, para que seguir buscando
	  return(0);
	comparaciones_buscar++;
      }
    }
   for(int i = 0; i < n;i++)  //si no encuentra desde la posicion al final, volvemos al principio de la serie
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == dni)
      {
	comparaciones_buscar++;
	return(1);
      }
      else
      {
	if(celda[i].clave[j] == -1)   //si lo encuentra vacio, para que seguir buscando
	  return(0);
	comparaciones_buscar++;
      }
    } 
    
};

int Ctabla::H_cuadratica()
{
  for(int i = casilla; i < n;i*=2)
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == -1)
      {
	comparaciones_insertar++;
	celda[i].clave[j]=dni;
	num_celdas++;
	return(1);
      }
      else
      {
	colicciones++;
	comparaciones_insertar++;
      }
      
    }
   for(int i = 0; i < n;i*=2)  //si no encuentra desde la posicion al final, volvemos al principio de la serie
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == -1)
      {
	comparaciones_insertar++;
	celda[i].clave[j]=dni;
	num_celdas++;
	return(1);
      }
      else
      {	
	colicciones++;
	comparaciones_insertar++;
      }
    } 
    
};

int Ctabla::G_cuadratica()
{
  for(int i = casilla; i < n;i*=2)
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == dni)
      {
	comparaciones_buscar++;
	return(1);	
      }
      else
      {
	if(celda[i].clave[j] == -1)   //si lo encuentra vacio, para que seguir buscando
	  return(0);
	comparaciones_buscar++;
      }
    }
   for(int i = 0; i < n;i*=2)  //si no encuentra desde la posicion al final, volvemos al principio de la serie
    for(int j = 0;j < m; j++)
    {
      if(celda[i].clave[j] == dni)
      {
	comparaciones_buscar++;
	return(1);
      }
      else
      {
	if(celda[i].clave[j] == -1)   //si lo encuentra vacio, para que seguir buscando
	  return(0);
	comparaciones_buscar++;
      }
    } 
    
};

int Ctabla::H_dobleDispersion()
{
    if(celda[casilla].clave[m] == -1)  //encuentra hueco a la primera
      {
	comparaciones_insertar++;
	celda[casilla].clave[m]=dni;
	num_celdas++;
	return(1);
      }
      else                             //hacemos doble dispersion
      {
	int x=0;
	x=n/2;
	x=numero_primo(x,0);   //buscamos un numero primo anterior a x
	casilla=dni%x;                //buscamos una nueva clave
	for(int i = casilla; i < n;i++)
	  for(int j = 0;j < m; j++)
	  {
	    if(celda[i].clave[j] == -1)
	    {
	    comparaciones_insertar++;
	    celda[i].clave[j]=dni;
	    num_celdas++;
	    return(1);
	    }
	    else
	    {	
	    colicciones++;
	    comparaciones_insertar++;
	    }  
	    
	  }
      
      }
    for(int i = 0; i < n;i++)       //si no encuentra desde la posicion al final, volvemos al principio de la serie
      for(int j = 0;j < m; j++)
      {
	if(celda[i].clave[j] == -1)
	{
	  comparaciones_insertar++;
	  celda[i].clave[j]=dni;
	  num_celdas++;
	  return(1);
	}
	else
	{
	  colicciones++;
	  comparaciones_insertar++;	
	}
	 
      }
};

int Ctabla::G_dobleDispersion()
{
  if(celda[casilla].clave[m] == -1)  //encuentra dni a la primera
      {
	comparaciones_buscar++;
	return(1);
      }
      else                             //hacemos doble dispersion
      {
	int x=0;
	x=n/2;
	x=numero_primo(x,0);   //buscamos un numero primo anterior a x
	casilla=dni%x;                //buscamos una nueva clave
	for(int i = casilla; i < n;i++)
	  for(int j = 0;j < m; j++)
	  {
	    if(celda[i].clave[j] == -1)
	    {
	      colicciones++;
	      comparaciones_buscar++;
	      return(1);
	    }
            else
	      {
		if(celda[i].clave[j] == -1)   //si lo encuentra vacio, para que seguir buscando
		return(0);
		comparaciones_buscar++;
	      }
	  }
      }
    for(int i = 0; i < n;i++)       //si no encuentra desde la posicion al final, volvemos al principio de la serie
      for(int j = 0;j < m; j++)
      {
	if(celda[i].clave[j] == -1)
	{
	  comparaciones_buscar++;
	  return(1);
	}
	else                             
	{
	if(celda[i].clave[j] == -1)   //si lo encuentra vacio, para que seguir buscando
	  return(0);
	comparaciones_buscar++;
	}
      }
      
      
};

int Ctabla::H_redispersion()
{

};

int Ctabla::G_redispersion()
{

};


void Ctabla::inicializa()
{
  for(int i = 0; i < n;i++)  
    for(int j = 0;j < m; j++)
       celda[i].clave[j] = -1;   //todo NULL
};

int Ctabla::insertar(long num,int opc)
{
  dni=num;
  casilla=num%n;
  
  switch(opc)
  {
    case(0):  //lineal
    H_lineal();
    break;
    case(1):  //cuadratica
    H_cuadratica();
    break;
    case(2):
    H_dobleDispersion();  //doble dispersion
    break;
    case(3):
    H_lineal();        //primero la creamos normal, y luego redispersion creando nueva tabla con el doble de tamaño y nueva clave
    break;
    
  }
};  

int Ctabla::buscar(long num, int opc)
{
  dni=num;
  casilla=num%n;
  switch(opc)
  {
    case(0):  //lineal
    G_lineal();
    break;
    case(1):  //cuadratica
    G_cuadratica();
    break;
    case(2):
    G_dobleDispersion();
    break;
    case(3):
    G_lineal();        //primero la creamos normal, y luego redispersion creando nueva tabla con el doble de tamaño y nueva clave
    break;
  }
  
};

int Ctabla::numero_primo(int numero,int sentido)
{
int divisor=2;
  
if(sentido==1)  //buscamos numero primo siguiente al numero dado
{ 
  while(divisor<numero)
       {  
	 while( numero % divisor != 0)
           divisor=divisor+1;
	  
          if(numero== divisor)                                
           return numero;
	  else
	  {  
	    numero+=1;
	    divisor=2;
	  }
       }
}
else if(sentido==0)      //buscamos numero primo anterior al numero dado
{ 
   while(divisor<numero)
       {  
	 while( numero % divisor != 0)
          divisor=divisor+1;
          if(numero == divisor)                                
           return numero;
	  else
	  {  
	    numero-=1;
	    divisor=2;
	  }
       }
}
  
};  
  
  
int Ctabla::devnum_celdas()
{
  return num_celdas;
};  

int Ctabla::total_col()
{
  return colicciones;
};


int Ctabla::bloque()
{
  return m;
};  
      
int Ctabla::com_bus()      
{
  return comparaciones_buscar;
};

int Ctabla::com_ins()      
{
  return comparaciones_insertar;
};

Ctabla::~Ctabla()
{
  //delete[] celda->clave;
  delete[] celda;  
}; 

	
	
  
  
  
  
