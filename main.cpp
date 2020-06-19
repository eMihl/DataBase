/*******************************
* NOMBRE: #Emilio Jose#
********************************/

/************
* PRÁCTICA 4
*************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subprogramas/Tipos.cpp" // Desarrolla los tipos de datos definidos
#include "subprogramas/altaCuenca.cpp" // Opción A del Menú Principal
#include "subprogramas/nuevaMedicion.cpp" // Opción N del Menú Principal
#include "subprogramas/Registros.cpp" // Opción R del Menú Principal
#include "subprogramas/Calendario.cpp" // Opción V del Menú Principal (Calendario, adaptado de la práctica 3)


/** Procedimiento de impresión del menú principal **/

void Menu(){
	
	

  printf("\n Gestion de Reservas de Agua\n");
  printf("\n %s%s", " Alta cuenca/presa     ", "(Pulsar A)");
  printf("\n %s%s", " Nueva medicion        ", "(Pulsar N)");
  printf("\n %s%s", " Registros             ", "(Pulsar R)");
  printf("\n %s%s", " Variaciones mensuales ", "(Pulsar V)");
  printf("\n %s%s", " Salir                 ", "(Pulsar S)\n");
  printf("\n Teclear una opcion valida (A|N|R|V|S): ");

  }

/**************
      MAIN
***************/

int main(){

/** Declaración de variables globales **/

 Todo todos; // Todas las cuencas
 char opcionMenu='Z'; // Tecla de control del Menú Principal

 int numeroCuencas=0; // Número de cuencas introducidas

/** Ponemos el número de las presas de cada cuenca a cero **/

for(int a=0; a<=2; a++) {

todos.cuencas[a].numPresas=0;

}

/** Impresión del menú principal **/

while (opcionMenu!='S'){

 Menu();

 /** LECTURA DE TECLADO PARA EL MENÚ PRINCIPAL **/

  while (opcionMenu!='A' && opcionMenu!='N'&& opcionMenu!='R'&& opcionMenu!='V'&& opcionMenu!='S'){

    scanf("%c", &opcionMenu);

  } // While del MENÚ PRINCIPAL

  /** OPCIÓN A : Alta cuenca/presa **/

  if (opcionMenu=='A'){

    altaCuenca(todos, numeroCuencas);
    opcionMenu='z';

  } // Cierre de if==A

  /** OPCIÓN N : Nueva Medición **/

  if (opcionMenu=='N'){

    nuevaMedicion(todos, numeroCuencas);
    opcionMenu='z';

  } // Cierre de if==N

  /** OPCIÓN R : Registros **/

  if (opcionMenu=='R'){

    Registros(todos, numeroCuencas);
    opcionMenu='z';

  } // Cierre de if==R

    /** OPCIÓN V : Variaciones Mensuales **/

  if (opcionMenu=='V'){

    calendario(todos, numeroCuencas);
    opcionMenu='z';

  } // Cierre de if==V


} // Fin de While principal

}

