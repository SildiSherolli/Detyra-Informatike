#include<stdio.h>
int main(){
int n,i,j;
printf("Vendosni numrin e kolonave:");
scanf("%d", &n);
for(i = 0;i < n;i++){
	for(j=0;j<(n-1-i);j++){
		printf(" ");
	}
	for(j=0;j<(i+1);j++){
		printf("*");
	}	
    printf("\n");	
}
return 0;
}
