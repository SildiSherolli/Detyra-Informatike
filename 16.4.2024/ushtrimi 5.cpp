#include <stdio.h>
int prodhimicift(int n){
	if(n==0)
	return 1;
	else{
		return prodhimicift(n-1)*2*n;
	}
}


int main(){
 	int n;
 	
	printf("Vendosni numrin e kufizave qe do te shumezoni:  ");
	scanf("%d", &n);
	int prodhimi= prodhimicift(n);
	printf("Prodhimi %d:", prodhimi);
	
	return 0;
}