/*******************************
* NOMBRE: #Emilio Jose#
********************************/

 /** Procedimiento Alta Cuenca/Presa **/

  void altaCuenca(Todo &todos, int &numCuencas){
  	
  	/** VARIABLES LOCALES **/ 

    //bool libre=0; // Hay lugar para más presas
    bool existeC=0; // Para saber si la cuenca existe
    bool existeP=0; // Para saber si la presa existe
    char nombreCuenca[20];
    char nombrePresa[20];
    int capacidad;
    int anteriorC; // Valor anterior del número de cuencas
    int anteriorP; // Valor anterior del número de presas
    int cuenca3=0; // Cuenca a la que pertenece la presa
    int presa5=0; // Número de la presa seleccionada, NO ESTÁ EN USO
    
	 // Fin de declaración de variables locales
	 
	 /** Lectura de datos **/

    printf("\n\n Alta Cuenca/presa:\n\n");

    printf("\n Nombre de la cuenca:");

    scanf("%s", nombreCuenca);

    printf("\n Nombre de la presa:");
    scanf("%s", nombrePresa);

    printf("\n Capacidad de la presa:");
    scanf("%d", &capacidad);
    
    // Fin de lectura de datos
    
    /** Algoritmo principal **/
		
		anteriorC=numCuencas;
//	}

      for(int a=0; a<=numCuencas-1; a++){ // Comprobar CUENCA

        if(strcmp(todos.cuencas[a].nombreC,nombreCuenca)==0){

        printf(" \n El nombre de la cuenca ya existe.\n");
        existeC=true;
        cuenca3=a; // Se identifica la cuenca
        
        	
        }
  	  }
      
      if (!existeC) {
	  
	 	if(numCuencas<3){
      	
      	strcpy(todos.cuencas[numCuencas].nombreC, nombreCuenca);
        presa5=0; // Número de presas que contiene, sin uso
        cuenca3=numCuencas;
		numCuencas=numCuencas+1;
        printf(" \n Se ha anadido una cuenca.\n");
    
      	
      } else {
      	
      	printf(" \n No hay espacio para más cuencas.\n");
      	return;
      	
      	
      }
  	}
      
      anteriorP=todos.cuencas[cuenca3].numPresas; // Número de presas en la cuenca
	        
        for(int b=0; b<=todos.cuencas[cuenca3].numPresas-1; b++){ // Comprobar PRESA
        
        		if(strcmp(todos.cuencas[cuenca3].presa[b].nombreP,nombrePresa)==0){
        			
					printf(" \n El nombre de la presa ya existe.\n");
					existeP=true;
					
				}
        
    	}
      
       if (!existeP){
       	
       	if(todos.cuencas[cuenca3].numPresas<=4){
      	
      	   strcpy(todos.cuencas[cuenca3].presa[anteriorP].nombreP,nombrePresa);
           todos.cuencas[cuenca3].numPresas=todos.cuencas[cuenca3].numPresas+1; // Se añade la presa
           todos.cuencas[cuenca3].presa[anteriorP].capacidad=capacidad; // Se añade su capacidad
           
           printf(" \n Se ha anadido una presa\n");
           
           // Inicializamos valores
           
           for(int a=0; a<=99; a++) {
	
			todos.cuencas[cuenca3].presa[anteriorP].Llenado[a].lleno=-1;
			todos.cuencas[cuenca3].presa[anteriorP].Llenado[a].day=0;
			todos.cuencas[cuenca3].presa[anteriorP].Llenado[a].month=0;
			todos.cuencas[cuenca3].presa[anteriorP].Llenado[a].year=0;

			}
           
        
    	
         } else {
    	 
		 		printf(" \n No hay lugar para más presas en este cuenca.\n");
    	
         }
      	
       }
  }

