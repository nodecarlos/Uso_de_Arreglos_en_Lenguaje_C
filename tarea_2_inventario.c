#include <stdio.h>
int main () {
	
	srand(time(NULL)); //semilla para generar numeros aleatorios
	
	//i j: contadores, cant: cantidad de articulos, igual poci val: variables utilizadas en la generacion de numeros aleatorios	
	int i, j, cant, igual, poci, val; 
	 
	printf("\n\n\n\t\t\t\tSistema de Inventario.\n\n");
	printf("\n\t\tIntroduce la cantidad de articulos para inventariar: "); 
	scanf("%i",&cant);
	
	char desc[cant][25]; //desc : arreglo para guardar la descripcion del articulo
	int datos[cant][3];	  //datos: matriz que contiene el codigo, numero aleatorio y cantidad de cada articulo.
	float precio[cant][2], mayor=0; //precio: matriz que contiene el precio y valor del articulo, mayor: articulo de mayor valor.
	
	//Nos aseguramos que las columna donde guardaremos los numeros aleatorios tenga cada posicion vacia. 
	for (j=0; j<cant; j++) {
		datos[j][1]=cant+2; 
	}
	
	//Pedimos los datos para cada articulo
	for(i=0; i<cant; i++) {
		printf("\n\n\t\tArticulo %i:",i+1);
		printf("\n\t\t\t\tCodigo del articulo: ");
		scanf("%i",&datos[i][0]);		
		printf("\t\t\t\tPrecio: "); 
		scanf("%f",&precio[i][0]); 	
		printf("\t\t\t\tCantidad: "); 
		scanf("%i",&datos[i][2]); 
		
		//Generamos una posicion aleatoria donde guardaremos la descripcion de cada articulo.
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
	
	//Buscamos el numero de mayor valor.
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
