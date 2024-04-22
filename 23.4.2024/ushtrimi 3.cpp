#include <stdio.h>
int simetria(int vec[], int n, int i);
int simetria(int vec[], int n, int i){
	if(i>=n/2){
		return 0;
	}
	if(vec[i] != vec[n-i-1]){
		return 1; 
	}
		return simetria(vec, n, i+1);
}


int main(){
	int n;
	printf("Vendosni numrin e elementeve te vektorit: ");
	scanf("%d", &n);
	int vektori[n];
	printf("Shkruani elementet e vektorit: \n");
	for(int i=0;i<n;i++){
		scanf("%d", &vektori[i]);
	}
	int count= simetria(vektori, n, 0);
	if(count){
		printf("Vektori nuk eshte simetrik.");
	}
	else{
		printf("Vektori eshte simetrik.");
	}
	return 0;
}