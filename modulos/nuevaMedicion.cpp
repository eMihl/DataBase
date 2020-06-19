/*******************************
* NOMBRE: #Emilio Jose#
********************************/

 /** Procedimiento Nueva Medición **/

  void nuevaMedicion(Todo &todos, int cuencas){
  	
  	/** VARIABLES LOCALES **/ 
  	
  	char nombrePresa[20]; // Nombre introducido
  	int volumen; // Volumen introducido
  	int dia;
  	int mes;
  	int ano;
  	
  	bool existe=false; // Almacena si la presa existe
  	
  	int numCuenca; // Números de la cuenca y la presa identificada
  	int numPresa;
  	
  	// Fin de declaración de variables locales
  	
  	/** LECTURA INICIAL **/
  	
  	printf(" \n Nueva medicion:\n");
  	
  	printf(" \n      Nombre de la presa: ");
  	scanf("%s", nombrePresa);
  	printf(" \n      Volumen embalsado: ");
  	scanf("%d", &volumen);
  	printf(" \n      Dia de lectura:");
  	scanf("%d", &dia);
  	printf(" \n      Mes de lectura: ");
  	scanf("%d", &mes);
  	printf(" \n      Ano de lectura: ");
  	scanf("%d", &ano);
  	
  	/** ALGORITMO PRINCIPAL **/
  	
  	for(int a=0; a<=cuencas-1; a++){
  		
  		for(int b=0; b<=todos.cuencas[a].numPresas; b++){
  			
  			if(strcmp(todos.cuencas[a].presa[b].nombreP,nombrePresa)==0){
  				
  				numCuenca=a;
  				numPresa=b;
  				existe=true;
  				
  			}
  		}
  	}
  	
  	if(!existe){
  		
  		printf("\n La presa indicada no existe.\n");
  		return;
  	}
  	
  	if(volumen>todos.cuencas[numCuenca].presa[numPresa].capacidad){ // Comparación de volúmenes
  		
  		printf("\n El volumen introducido excede la capacidad de la presa.\n");
  		return; // Acaba la ejecución de nuevaMedición
  		
  		
  	} else {
  		
  			/** Comparación de fechas **/
  		
		  if (comparaFechas(ano, todos.cuencas[numCuenca].presa[numPresa].Llenado[99].year, mes, todos.cuencas[numCuenca].presa[numPresa].Llenado[99].month, dia, todos.cuencas[numCuenca].presa[numPresa].Llenado[99].day)==true){
		  	
			  printf("\n La fecha escogida no es valida al ser igual o inferior al ultimo registro.\n");
			  return;
		  }
		  
  		
  		  // Fin de comparación de fechas
  		  
  		  /** Comprobación de la fecha añadida **/
  		  
  		  if (compruebaFecha(dia, mes, ano)==true){
  		  	
  		  	  //printf("\n La fecha escogida no es valida.\n");
			  return;
  		  }
  		
		  
  		
  		  // Fin de comprobación de la fecha añadida
  		  
  		  /** Movemos una casilla todos los registros (para introducir el nuevo registro) **/
  		
  		for (int a=0; a<=98; a++){ 
  			
  			todos.cuencas[numCuenca].presa[numPresa].Llenado[a].lleno=todos.cuencas[numCuenca].presa[numPresa].Llenado[a+1].lleno;
  			todos.cuencas[numCuenca].presa[numPresa].Llenado[a].day = todos.cuencas[numCuenca].presa[numPresa].Llenado[a+1].day;
  			todos.cuencas[numCuenca].presa[numPresa].Llenado[a].month= todos.cuencas[numCuenca].presa[numPresa].Llenado[a+1].month;
  			todos.cuencas[numCuenca].presa[numPresa].Llenado[a].year = todos.cuencas[numCuenca].presa[numPresa].Llenado[a+1].year;
  		
  		
		  
		  }
		  
		    todos.cuencas[numCuenca].presa[numPresa].Llenado[99].lleno= volumen;
		  	todos.cuencas[numCuenca].presa[numPresa].Llenado[99].day = dia;
  			todos.cuencas[numCuenca].presa[numPresa].Llenado[99].month= mes;
  			todos.cuencas[numCuenca].presa[numPresa].Llenado[99].year = ano;
		  
		  
      }
  	
  	


  	
  	
  	
  	
  }
