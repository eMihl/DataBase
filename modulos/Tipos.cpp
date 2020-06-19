/*******************************
* NOMBRE: #Emilio Jose#
********************************/

/** ESTRUCTURA DE DATOS Y ALGUNOS PROCEDIMIENTOS GLOBALES **/

/** Clase de fecha y volumen embalsado **/

struct fechaLleno {

  int day;
  int month;
  int year;
  int lleno;

  };

/** Clase presa **/

struct Presa {

  char nombreP[20];
  int capacidad;
  fechaLleno Llenado[100];


  };

/** Clase cuenca **/

struct Cuenca {

  char nombreC[20];
  int numPresas; // Número de presas introducidas en la cuenca
  Presa presa[5];

  };

/** Las 3 cuencas **/

struct Todo {

  Cuenca cuencas[3];

};

/** Procedimiento para comparar dos fechas **/

 bool comparaFechas(int y1, int y2, int m1, int m2, int d1, int d2){
  			
  			
  			if(y1 <= y2){ // Comparación de fechas con el último registro
  		
  			if(y1 == y2){
  			
		  
		 		 if(m1 <= m2){
		 		 	
		 		 	if(m1 == m2){
		  	
		  					if(d1 <= d2){
		  		
		  						//printf("\n La fecha escogida no es valida al ser igual o inferior al ultimo registro.\n");
		  						return true; // Acaba la ejecución de nuevaMedición
		  					} else {
		  						
		  						return false;
		  					}
		  					
		  			} else {
		  				
		  				//printf("\n La fecha escogida no es valida al ser igual o inferior al ultimo registro.\n");
		  				return true; // Acaba la ejecución de nuevaMedición
		  				
		  			}
		 		 } else {
		 		 	
		 		 	return false;
		 		 }
		 	 } else {
		 	 	
		 	 	//printf("\n La fecha escogida no es valida al ser igual o inferior al ultimo registro.\n");
		  		return true; // Acaba la ejecución de nuevaMedición
		 	 	
		 	 }
		  
		  
		  } else {
		  
		  return false;
  			
 } 
} // Fin de Comparación de fechas con el último registro


/** Comprueba si una fecha es correcta **/

bool compruebaFecha(int dia, int mes, int ano){
  		
		  if (ano<0 || ano>2100){
		  	
			  printf("\n La fecha escogida no es valida. Falla el ano.\n");
			  return true;
		} 
			  
			  if (mes<1 || mes>12){
			  	
			  	printf("\n La fecha escogida no es valida. Falla el mes.\n");
			 	return true;
			 }
			 	
			 	if (mes==1 || mes ==3 || mes ==5|| mes ==7|| mes ==8|| mes ==10||mes ==12){
			 		
			 		if(dia<0 || dia>31){
			 			
			 			printf("\n La fecha escogida no es valida. Falla el dia.\n");
			 			return true;
			 		} else {
			 			return false;
			 		}
			 	} else if (mes==4 || mes ==6 || mes ==9|| mes ==11){
			 		
			 		if(dia<0 || dia>30){
			 			
			 			printf("\n La fecha escogida no es valida. Falla el dia.\n");
			 			return true;
			 		} else {
			 			return false;
			 		}
			 		
			 		
			 	} else if(mes==2){
			 		
			 		    if(ano%4==0){

      						  if(ano%100==0 && ano%400!=0){

      								  if(dia<0 || dia>28){
			 			
			 								printf("\n La fecha escogida no es valida. Falla el dia.\n");
			 									return true;
			 									} else {
			 								return false;
			 									}

       							 } else {
        							  if(dia<0 || dia>29){
			 			
			 								printf("\n La fecha escogida no es valida. Falla el dia.\n");
			 									return true;
			 									} else {
			 								return false;
			 									}
       								 }

    					} else {

       						  		if(dia<0 || dia>28){
			 			
			 							printf("\n La fecha escogida no es valida. Falla el dia.\n");
			 							return true;
			 						} else {
			 							return false;
			 						}

      					}
			 		
			 		
			 	}
}
			 	
			 	
  		
