/*******************************
* NOMBRE: #Emilio Jose#
* EMAIL: #gemilioj@gmail.com#
********************************/

 /** Módulo de Variaciones Mensuales **/

/** Procedimiento para imprimir la cabecera **/

void mesAno(int ano, int mes, char nomCuenca[20], char nomPresa[20]){
	
		printf("\n %s %20s\n", nomCuenca, nomPresa);

    if(mes==1){

      printf("\n%s %16d", "ENERO     ", ano);

    }else if (mes==2){

      printf("\n%s %16d", "FEBRERO   ", ano);

    }else if (mes==3){

      printf("\n%s %16d", "MARZO     ", ano);

    }else if (mes==4){

      printf("\n%s %16d", "ABRIL     ", ano);

    }else if (mes==5){

      printf("\n%s %16d", "MAYO      ", ano);

    }else if (mes==6){

      printf("\n%s %16d", "JUNIO     ", ano);

    }else if (mes==7){

      printf("\n%s %16d", "JULIO     ", ano);

    }else if (mes==8){

      printf("\n%s %16d", "AGOSTO    ", ano);

    }else if (mes==9){

      printf("\n%s %16d", "SEPTIEMBRE", ano);

    }else if (mes==10){

      printf("\n%s %16d", "OCTUBRE   ", ano);

    }else if (mes==11){

      printf("\n%s %16d", "NOVIEMBRE ", ano);

    }else{

      printf("\n%s %16d", "DICIEMBRE ", ano);

    }

    printf("\n"); // CAMBIO DE LÍNEA

    for(int a=27; a>=1; a--){

    printf("=");

    }

    printf("\n"); // CAMBIO DE LÍNEA

    printf("LU  MA  MI  JU  VI | SA  DO");

    printf("\n"); // CAMBIO DE LÍNEA

    for(int a=27; a>=1; a--){

    printf("=");

    }
}


  /** Procedimiento de impresión de calendario **/


void calendario(Todo &todos, int cuencas){

    /** Declaración de variables locales **/

    int ano=0; // Almacena el año seleccionado por el usuario
    int mes=0; //Almacena el año seleccionado por el usuario
    int dia=0; // Almacena el número de días del mes seleccionado
    bool bisiesto=false; // Nos ayudará a identificar si el mes de febrero tiene 29 días
    int cont1=1; // Contador de los días del mes para la impresión
    int diaComienzo=1; // Día en que comienza el mes
    int contTotal=1; // Contador de días para los bisiestos y para el total
    
    bool hayregistro=0; // Comprueba si hay registro para el día del mes correspondiente
    bool hayregistro2=0; // Comprueba si hay registro para algún día previo del día correspondiente
    int registro=0; // Almacena el registro antes indicado
    int registro2=0; // Almacena el registro previo al antes indicado
    
    int numCuenca=0;
    int numPresa=0;
    int resultado=0; // Porcentaje a imprimir para cada día
    
    char nombreCuenca[20]; // Nombre introducido
  	char nombrePresa[20]; // Nombre introducido
  	
  	bool existeC=0; // Si existe la cuenca
  	bool existeP=0; // Si existe la presa
  	//bool unico=0; // Si se especifica la cuenca y la presa
  	
  	//int a1=0; // Parámetros para el inicio y fin de las iteraciones de las cuencas y las presas
  	//int a2=0;
  	//int b1=0;
  	//int b2=0;
  	
  	//int laspresas=0;
  	//int lascuencas=0;
  	
  	//int laspresasPrevio=0;
  	//int lascuencasPrevio=0;
    
    // Fin de declaración de variables locales

    /** Lectura de datos **/

    printf("\n Variaciones mensuales: ");
	
	printf("\n\n Nombre de la cuenca: ");
  	scanf("%s", nombreCuenca);
  	printf("\n Nombre de la presa: ");
	scanf("%s", nombrePresa);
	printf("\n Mes: ");
    scanf("%d", &mes);
    printf("\n Ano: ");
    scanf("%d", &ano);

    /** Condición inicial del programa  **/

if((mes>=1 && mes<=12) && (ano>=1601 && ano<=3000)){
	
	
	// Averiguar si existen Cuenca y Presa (y agregar los valores a los parámetros)
	
	
	for(int a=0; a<=cuencas-1; a++){ // Averiguar si la cuenca y la presa existen, e identificarlas
  		
  		if(strcmp(todos.cuencas[a].nombreC,nombreCuenca)==0){
		  
		  numCuenca=a;
		  existeC=true;
		  
		  }
  		
  		
  		
  		for(int b=0; b<=todos.cuencas[a].numPresas; b++){
  			
  			if(strcmp(todos.cuencas[a].presa[b].nombreP,nombrePresa)==0){
		  
		 		 numPresa=b;
		 		 existeP=true;
		  
		  }	
  		}
  	}
  	
  	if ((!existeC && !existeP) ||  (!existeC && existeP)  || (existeC && !existeP)){ // Si la cuenca o la presa no existen
  	
  	return;
  	
  	}

    /** Contar los años bisiestos  **/

    for(int a=1601; a<=ano-1; a++){

      if(a%4==0){

        if(a%100==0 && a%400!=0){

        contTotal=contTotal+365;

        } else {
          contTotal=contTotal+366;
        }

    } else {

        contTotal=contTotal+365;

      }

    }

    // Conocer si el año seleccionado es bisiesto

     if(ano%4==0){

        if(ano%100==0 && ano%400!=0){

          bisiesto=false;

        } else {

          bisiesto=true;
        }
     }

    /** Contar los días de todos los meses  **/

    for (int a=1; a<=mes-1; a++){

      if(a==1 || a==3|| a==5|| a==7|| a==8|| a==10){
        contTotal=contTotal+31;

      } else if (a==2 && bisiesto){

        contTotal=contTotal+29;

        }else if (a==2 && !bisiesto){

        contTotal=contTotal+28;

        } else {

          contTotal=contTotal+30;
          }
    }

    /** Identificación del día inicial de la semana **/

      if(contTotal!=1){ // Se añade un día para el mes que comienza

      diaComienzo=(contTotal%7);

      }

      if(diaComienzo==0){
        diaComienzo=7;
        }

    /** Obtención del número de días del mes a imprimir **/

        if(mes==1 || mes==3|| mes==5|| mes==7|| mes==8|| mes==10|| mes==12){

        dia=31;

      } else if (mes==2 && bisiesto){

        dia=29;

        }else if (mes==2 && !bisiesto){

        dia=28;

        } else {

          dia=30;
        }

    /** Comienza la Impresión **/


    mesAno(ano, mes, todos.cuencas[numCuenca].nombreC, todos.cuencas[numCuenca].presa[numPresa].nombreP); // Imprimir la cabecera

  printf("\n"); // CAMBIO DE LÍNEA
  

  /** IMPRESIÓN DEL RESTO DEL CALENDARIO **/

  while (cont1<=dia) {

    for(int b=1; b<=14; b++){ // Impresión de cada línea semanal del calendario

    if(b>(diaComienzo-1)*2){ // El -1 evita el desborde

    if((b==1 || b==3 ||b==5 ||b==7 ||b==9 ||b==11||b==13) && (cont1<dia+1)){

      
	  // Parte nueva del código (para práctica 4)
	  
	  	
	  
	  		for(int a=99; a>=0; a--){ // Comprobar si dicho día hay registro (cont)
	  	
	  			if(mes==todos.cuencas[numCuenca].presa[numPresa].Llenado[a].month && ano==todos.cuencas[numCuenca].presa[numPresa].Llenado[a].year && cont1==todos.cuencas[numCuenca].presa[numPresa].Llenado[a].day){
	  		
	  				hayregistro=1;
	  				registro=a;	 	
	  		 	
	  			}
	  		}
	  	
	 		
	  
	  
	  if(hayregistro){ // Hay registro para dicho día
	  	
	  	for(int a=registro-1; a>=0; a--){
	  		
	  			if(todos.cuencas[numCuenca].presa[numPresa].Llenado[a].lleno>-1 ){
	  		
		  				hayregistro2=1;
		  				registro2=todos.cuencas[numCuenca].presa[numPresa].Llenado[a].lleno;	
		  				a=-1; // Interrumpe el for
			
		     }
	 	 }
	  }
	  
	  if (hayregistro && hayregistro2){ // Hay algún registro previo a dicho día
	  
	  	if(todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno > registro2){
		  
		  
		  	if(((todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno*100)/registro2)-100>9){
		  	
		  		printf("EE");
		  	
		 	 } else if (((todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno*100)/registro2)-100==0){
		  	
		  		printf("00");
		  	
				}else{
		  	
		  		printf("+%1d", ((todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno*100)/registro2)-100);
		 	 }
		 	 
		 } else {
		 	
		 	if(((registro2*100)/todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno)-100>9){
		  	
		  		printf("EE");
		  	
		 	 } else if (((registro2*100)/todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno)-100==0){
		  	
		  		printf("00");
		  	
				}else{
		  	
		  		printf("-%1d", ((registro2*100)/todos.cuencas[numCuenca].presa[numPresa].Llenado[registro].lleno)-100);
		 	 }
			  	
		 }
		  
		  
		  // Fin de parte Nueva del código
		  

      	
      } else {
      	printf("--");
      }
      	
      	hayregistro=0;
      	registro=0;
      	registro2=0;
      	cont1++; // Movemos 1 día hacia adelante


      } else if ((b==1 || b==3 ||b==5 ||b==7 ||b==9 ||b==11||b==13) && (cont1>=dia+1)){

      printf(" .");

    } else if (b==2 || b==4 ||b==6 ||b==8 ||b==12||b==14){

      printf("  ");

    } else {

      printf(" | ");

    }


     if (b==14){
    	printf("\n");
     }

    } else {

        if (b==1 || b==3 ||b==5 ||b==7 ||b==9 ||b==11||b==13){

          printf(" .");

        } else if (b==2 || b==4 ||b==6 ||b==8 ||b==12||b==14){

          printf("  ");

        }else {

      printf(" | ");

        }

      }

  
 }
  
  diaComienzo=0; // Tras imprimir la primera línea de semana, diaComienzo toma un valor neutro


}
    }else{

      return;

    }

}
