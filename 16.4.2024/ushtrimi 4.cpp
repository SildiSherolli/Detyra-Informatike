#include <stdio.h>

int fibonaci(int n){
		if(n==0)
		return 0;
		else if(n==1)
		return 1;
		else{
			return fibonaci(n-1)+fibonaci(n-2);
		}
	}


int main(){
	int n;
	int shuma=0;
	printf(" Vendosni deri ne cilen kufize do te behet mbledhja: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		shuma+=fibonaci(i);
	}
	printf("Shuma: %d", shuma);
	return 0;
}