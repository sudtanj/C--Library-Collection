#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>

int main () {
	MPI_Init(NULL, NULL);
	int red=0;
	int green=0;
	int blue=0;
	int ***par = (int***)malloc(256*sizeof(int**));
	int j=0,k=0,p=0,q=0,r=0,i=0;
	int colour=0;
	int *value=(int*)malloc(sizeof(int));
	
	  

   /* Get the number of processes */
   int size=0;
   MPI_Comm_size(MPI_COMM_WORLD, &size); 

   /* Get my rank among all the processes */
   int rank=0;
   MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	for(k = 0; k < 256; k++){
		par[k] = (int**)malloc(256*sizeof(int*));
		for(j=0; j<256;j++) {
			par[k][j] = (int*)malloc(256*sizeof(int));
		}
	}
	for(k = 0; k < 256; k++){
		for(j=0; j<256;j++) {
			for(i=0; i<256;i++) {
				par[k][j][i]=0;
			}
		}
	}
	int m=0;
	int n=0;
	FILE * fd;
		
	fd = fopen("rgbdata-temp","r");
	fscanf(fd, "%d %d", &m, &n);
	int* warna = (int *) malloc ((m * n) * sizeof(int));

	memset(warna,0,sizeof(int)*(m*n));

	for(i=0; i < ((m * n)/3); i++)
		fscanf(fd, "%d %d %d", &(warna[3 * i]), &(warna[3 * i + 1]), &(	warna[3 * i + 2] ));
	fclose(fd);
	for(i=0;i<(m*n)/3;i++)
		par[warna[3 * i]][warna[(3 * i) + 1]][warna[(3 * i) + 2]]=i%(((m*n)/3)/size);

	if(rank==0){
		value=(int*)malloc(((m*n))*sizeof(int));
		memset(value,0,sizeof(int)*(m*n)/3);
	}
	
	int* data = (int*)malloc(((m*n)/3)/size*sizeof(int));
	int* data2=(int*)malloc((m * n)/size * sizeof(int));
	
	MPI_Scatter(value, ((m*n)/3)/size, MPI_INT, data, ((m*n)/3)/size, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(warna, ((m*n))/size, MPI_INT, data2, ((m*n))/size, MPI_INT, 0, MPI_COMM_WORLD);
	for(i=0; i < (((m * n)/size)/3); i++){
			data[(par[data2[3 * i]][data2[(3 * i) + 1]][data2[(3 * i) + 2]])]+=1;
			printf("2. Processor %d has data: %d %d %d => %d\n", rank, data2[3 * i],data2[3 * i + 1], data2[3 * i + 2], data[par[data2[3 * i]][data2[(3 * i) + 1]][data2[(3 * i) + 2]]]);
	}
	MPI_Gather(data, ((m*n)/3)/size, MPI_INT, value, ((m*n)/3)/size, MPI_INT, 0, MPI_COMM_WORLD);
	if(rank==0)
		for(i=0; i< (m*n)/3;i++)
			printf("4. Processor %d has data %d %d %d => %d \n",rank,warna[3 * i], warna[3 * i + 1], warna[3 * i + 2],value[par[warna[3 * i]][warna[(3 * i) + 1]][warna[(3 * i) + 2]]]);
	
	
	MPI_Finalize();
	return EXIT_SUCCESS;
}
