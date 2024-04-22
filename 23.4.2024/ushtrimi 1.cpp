#include <stdio.h>
#include <stdlib.h>
int shumaMatrices(int **mat, int n, int m, int i, int j);
int shumaMatrices(int **mat, int n, int m, int i, int j){
	if(n==i){
		return 0;
	}
	if(m==j){
		return shumaMatrices(mat, n, m, i+1, 0);	
	}
	
		return mat[i][j] + shumaMatrices(mat, n, m, i, j+1);
}
int main(){
	int n, m;
	printf("Jepni numrin e rreshtave te matrices: \n");
	scanf("%d", &n);
	printf("Jepni numrin e shtyllave  te matrices: \n");
	scanf("%d", &m);
	
	int **matrica= (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++){
		matrica[i]=(int*)malloc(m*sizeof(int));
	}
	printf("Shkruani elementet e matrices: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d", &matrica[i][j]);
		}
	}	
	int sh;
	sh= shumaMatrices(matrica, n, m, 0, 0);
	printf("Shuma e elementeve te matrices eshte: %d", sh);
	return 0;
}