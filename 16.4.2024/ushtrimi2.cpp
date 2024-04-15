#include <stdio.h>
int faktorial(int n){
	int prodhimi;
	if(n==1 || n==0){
		return 1;
		}else{
			return faktorial(n-1)*n;
		}
	}


int main(){
	int n;
	printf("Jepni nje numer:  ");
	scanf("%d", &n);
	int prodhimi= faktorial(n);
	printf("Numri juaj ne fatorial eshte: %d", prodhimi);
	
	return 0;
}