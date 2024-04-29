#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PERSONA 3

struct person {
    char emri [20];
    char mbiemri [20];
    int mosha;
} person[MAX_PERSONA];

struct student {
    char nrMatrikullimi [20];
};

int personi_vjeter (struct person p[]){
    int i;
    int max = 0;
    for(i=0; i<MAX_PERSONA; i++){
        if(p[i].mosha > max){
            max = p[i].mosha;
        }
    }
    return max;
}

void emriPerpara(struct person p[]){
    int i;
    for(i=0; i<MAX_PERSONA-1; i++){
        if((strcmp(p[i].emri, p[i+1].emri)) == 1){
            printf("\nEmri %s eshte mbrapa emrit %s", p[i].emri, p[i+1].emri);
        }else if((strcmp(p[i].emri, p[i+1].emri)) == 0){
            printf("\nEmrat %s dhe %s jane njesoj",p[i].emri, p[i+1].emri);
        }else if((strcmp(p[i].emri, p[i+1].emri)) == -1){
            printf("\nEmri %s eshte me perpara se emri %s", p[i].emri, p[i+1].emri);
        }
    }
}

void rendit(struct person p[]){
    int i, j;
    for(i=0; i<MAX_PERSONA-1; i++){
        for(j=i+1; j<MAX_PERSONA; j++){
            if((strcmp(p[i].emri, p[j].emri)) == 1){
                struct person temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            else if((strcmp(p[i].emri, p[j].emri)) == 0){
                if((strcmp(p[i].mbiemri, p[j].mbiemri)) == 1){
                    struct person temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
            }
            }
}
    }}


void printoDhena(struct person person){
    printf("\nEmri: %s", strlwr(person.emri));
    printf("\nMbiemri: %s", strupr(person.mbiemri));
    printf("\nMosha: %d", person.mosha);
}
//Kerkesa 1
int shkronjaPare(struct person p[], char c){
	int count=0;
	c=toupper(c);
	for(int i=0; i<MAX_PERSONA; i++){
		p[i].emri[0]=toupper(p[i].emri[0]);
		if(p[i].emri[0] == c){
			count++;
		}
	}
	return count;
}
//Kerkesa 2
int mbiemriMeIGjate(struct person p[]){
	int max= 0;
	int gjatesiaMax = strlen(p[0].mbiemri);
	for(int i=1; i<MAX_PERSONA-1; i++){
			if(gjatesiaMax < strlen(p[i].mbiemri)){
				max= i;
				gjatesiaMax = strlen(p[i].mbiemri);
		}
	}
	return max;
}

int main(){
    int i;
    for(i=0; i<MAX_PERSONA; i++){
        printf("Jep emrin e personit: ");
        scanf("%s", &person[i].emri);
        printf("Jep mbiemrin e personit: ");
        scanf("%s", &person[i].mbiemri);
        printf("Jep moshen e personit: ");
        scanf("%d", &person[i].mosha);
        printf("***************************************\n");
    }

    printf("\nMosha me e madhe: %d", personi_vjeter(person));
    emriPerpara(person);

    for(i=0; i<MAX_PERSONA; i++){
        printoDhena(person[i]);
        printf("\n***************************************");
    }
//Kerkesa 1
    char ch;
    printf("\nJu lutem vendosni nje shkronje: ");
    scanf(" %c", &ch);
    int countShkronja= shkronjaPare(person, ch);
    printf("\nNumri i emrave qe fillojne me shkronjen %c jane %d \n", ch, countShkronja);
    printf("***************************************\n");
//Kerkesa 2
    printf("Personi me mbiemrin me te gjate eshte: \n");
    int max= mbiemriMeIGjate(person);
    printoDhena(person[max]);
    

return 0;
}