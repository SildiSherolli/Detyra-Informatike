#include <stdio.h>
#include <stdlib.h>
int main(){
	int piket;
	printf("Ju lutem fusni numrin e pikeve te marra:");
	scanf("%d", &piket );
	if (piket < 0 || piket > 100) {
		printf("Piket duhet te jene nga 0 ne 100");
		exit(0);
	}
	
	int piketNrDhjetor = piket / 10;
	
		switch(piketNrDhjetor){	
		case 10:
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
    }
       return 0;
	}

