#include <stdio.h>
int cift(int vec[], int n){
	if(n==0){
	return 0;
	} 
	else {
        if (vec[0] % 2 == 0) {
            return 1 + cift(vec + 1, n - 1);
        } else {
            return cift(vec + 1, n - 1);
        }
	}
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
	
	int count= cift(vektori, n);
	printf(" Vektori ka %d elemente cift.", count);
	
	return 0;
}