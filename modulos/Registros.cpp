/*******************************
* NOMBRE: #Emilio Jose#
********************************/

 /** Procedimiento Registros **/

  void Registros(Todo &todos, int cuencas){
  	
  	/** VARIABLES LOCALES **/ 
  	
  	char nombreCuenca[20]; // Nombre introducido
  	char nombrePresa[20]; // Nombre introducido
  	int dia;
  	int mes;
  	int ano;
  	
  	bool existeC=false; // Almacena si la cuenca existe
  	bool existeP=false; // Almacena si la presa existe
  	
  	int numCuenca; // Números de la cuenca y la presa identificada
  	int numPresa;
  	int numRegistro; // Registro a partir del cual se debe imprimir
  	
  	int totalPresasActual1=0; // Almacena el caudal total de la cuenca y de las presas
  	int totalPresasActual3=0; 
  	int totalPresasMaximo1=0;
  	int totalPresasMaximo3=0;
  	int totalCuencas;
  	
  	int a1=0; // Para imprimir los registros según se conozca o no el número de cuenca y de presa
  	int b1=0;
  	int a2=0; 
  	bool unico=0; // Este booleano ayuda a saber si se conocen la cuenca y presa exactas
  	
  	// Fin de declaración de variables locales
  	
  	/** LECTURA INICIAL **/

  	printf("\n Registros\n");
  	
  	printf("\n    Nombre de la cuenca: ");
  	scanf("%s", nombreCuenca);
  	printf("\n    Nombre de la presa: ");
  	scanf("%s", nombrePresa);
  	printf("\n    Posterior al dia: ");
  	scanf("%d", &dia);
  	printf("\n    Mes: ");
  	scanf("%d", &mes);
  	printf("\n    Ano: ");
  	scanf("%d", &ano);
  	
  	/** ALGORITMO PRINCIPAL **/
  	
  	// CONDICIÓN INICIAL DE FECHA //
  	
  if (compruebaFecha(dia, mes, ano)==true){ // No lee más allá de 2100
  		  	
  		  	  //printf("\n La fecha escogida no es valida.\n");
			  return;
  		  } else {
  	
  	// Fin de Condición inicial de fecha
  	
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
  	
  	
  	if (existeC && existeP){ // Si tanto la cuenca como la presa EXISTEN
  	
  		a1=numCuenca;
  		b1=numPresa;
  		a2=numCuenca;
  		
  		unico=1;
  	}
  		
  	
  	if (existeC && !existeP){ // Si existe la CUENCA pero NO LA PRESA
  		
  		a1=numCuenca;
  		b1=0;
  		a2=numCuenca;
  		
  		unico=0;
  		
	}
	
	 if ((!existeC && !existeP) || (!existeC && existeP)){ 	// Si NO existe la CUENCA NI LA PRESA
	 
	 	a1=0;
  		b1=0;
  		a2=cuencas-1;
  		
  		unico=0;
	 }
	 
	 /** IMPRESIÓN DEL REGISTRO **/
  	
  	printf("\n%16s%16s%16s%16s\n\n", "Cuenca", "Presa", "Volumen", "Fecha");
  	
  	  for(int c=a1; c<=a2; c++){ 
  	  
  	  	if(todos.cuencas[c].numPresas>0){
  	  
  	
  			for(int b=b1; b<=todos.cuencas[c].numPresas-1; b++){
  				
  				if(unico){ // Si se especifica cuál es la presa
  					
  					b=numPresa;
  				}
  			
  			
  				for(int a=99; a>=0; a--){
  				
  					if(todos.cuencas[c].presa[b].Llenado[a].year>1){
  		
  						if(comparaFechas(ano, todos.cuencas[c].presa[b].Llenado[a].year, mes, todos.cuencas[c].presa[b].Llenado[a].month, dia, todos.cuencas[c].presa[b].Llenado[a].day)){
  				
  							numRegistro=a;
  						
  						}
  					}
  			
  				}
  		
  				for(int a=numRegistro; a<=99; a++){
  			
  					printf("%16s%16s%9d(%2d%%)          %d-%d-%d\n", todos.cuencas[c].nombreC,todos.cuencas[c].presa[b].nombreP,todos.cuencas[c].presa[b].Llenado[a].lleno, (todos.cuencas[c].presa[b].Llenado[a].lleno*100)/todos.cuencas[c].presa[b].capacidad,todos.cuencas[c].presa[b].Llenado[a].day, todos.cuencas[c].presa[b].Llenado[a].month, todos.cuencas[c].presa[b].Llenado[a].year);
  			
  				}	
				  numRegistro=100;	
				  
  			}
  		}
  		
  	  }
  	
  	
  		for(int c=a1; c<=a2; c++){ // Suma el caudal y la capacidad de las presas de toda la región
  		
  			for(int b=0; b<=todos.cuencas[c].numPresas-1; b++){
  				
  		
  				totalPresasActual1 = todos.cuencas[c].presa[b].Llenado[99].lleno + totalPresasActual1;
  				totalPresasMaximo1 = todos.cuencas[c].presa[b].capacidad + totalPresasMaximo1;
  				
  				totalPresasActual3 = todos.cuencas[c].presa[b].Llenado[99].lleno + totalPresasActual3;
  				totalPresasMaximo3 = todos.cuencas[c].presa[b].capacidad + totalPresasMaximo3;
  				
  				
  			}
  			printf("%16s%16s%9d(%2d%%)\n", todos.cuencas[c].nombreC,"TOTAL",totalPresasActual1,(totalPresasActual1*100)/totalPresasMaximo1);
			  
				totalPresasActual1=0;
				totalPresasMaximo1=0;
  			

  		  }
  		
  			if((!existeC && !existeP) || (!existeC && existeP)){ // Imprimir el total para la región
  		
  				printf("%16s%16s%9d(%2d%%)\n", "REGION","TOTAL",totalPresasActual3,(totalPresasActual3*100)/totalPresasMaximo3);
  				return; // Acaba la ejecución de "Registros"
  		
  			}
  		
			
	}
	
	
	
	  /*		for(int b=0; b<=todos.cuencas[numCuenca].numPresas; b++){
  		
  			totalPresasActual = todos.cuencas[numCuenca].presa[b].Llenado[99].lleno + totalPresasActual;
  			totalPresasMaximo = todos.cuencas[numCuenca].presa[b].capacidad + totalPresasMaximo;
  		}
  		
  		printf("%16s%16s%9d(%2d%%)\n", todos.cuencas[numCuenca].nombreC,"TOTAL",totalPresasActual,(totalPresasActual*100)/totalPresasMaximo);
  		return; // Acaba la ejecución de "Registros"
  		
  	}*/
 }
