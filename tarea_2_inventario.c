#include <stdio.h>
int main () {
	
	srand(time(NULL)); //semilla para generar números aleatorios
	
	//i j: contadores, cant: cantidad de artículos, igual poci val: variables utilizadas en la generación de números aleatorios	
	int i, j, cant, igual, poci, val; 
	 
	printf("\n\n\n\t\t\t\tSistema de Inventario.\n\n");
	printf("\n\t\tIntroduce la cantidad de articulos para inventariar: "); 
	scanf("%i",&cant);
	
	char desc[cant][25]; //desc : arreglo para guardar la descripción del artículo
	int datos[cant][3];	  //datos: matriz que contiene el código, número aleatorio y cantidad de cada artículo.
	float precio[cant][2], mayor=0; //precio: matriz que contiene el precio y valor del artículo, mayor: artículo de mayor valor.
	
	//Nos aseguramos que las columna donde guardaremos los números aleatorios tenga cada posición vacía. 
	for (j=0; j<cant; j++) {
		datos[j][1]=cant+2; 
	}
	
	//Pedimos los datos para cada artículo
	for(i=0; i<cant; i++) {
		printf("\n\n\t\tArticulo %i:",i+1);
		printf("\n\t\t\t\tCodigo del articulo: ");
		scanf("%i",&datos[i][0]);		
		printf("\t\t\t\tPrecio: "); 
		scanf("%f",&precio[i][0]); 	
		printf("\t\t\t\tCantidad: "); 
		scanf("%i",&datos[i][2]); 
		
		//Generamos una posición aleatoria donde guardaremos la descripción de cada artículo.
		val = 0;
		while(val==0) {
			igual = 0;
			poci = rand()%cant; 
			
			for (j=0; j<cant && igual == 0; j++) {
				if (datos[j][1]==poci) {
					igual = 1; 
				}
			}
			
			if (igual==0) {
				datos[i][1]=poci; 
				val = 1;
			}
		}	
		printf("\t\t\t\tDescripcion no mas de 100 caracteres: ");
		fflush(stdin); 
		fgets(desc[datos[i][1]],25,stdin);
		precio[i][1]=datos[i][2]*precio[i][0];
	}
	
	//Buscamos el número de mayor valor.
	for (i=0; i<cant; i++)	 {
		if (mayor<precio[i][1]) {
			mayor=precio[i][1];
			poci = i;
		}
	}
	printf("\n\n\n\t\tArticulo De Mayor valor:\n\n");
	printf("\t\t\t\t\tCodigo: %i\n\n\t\t\t\t\tDescripcion: %s\n",datos[poci][0],desc[datos[poci][1]]);
	
	return 0; 
}
