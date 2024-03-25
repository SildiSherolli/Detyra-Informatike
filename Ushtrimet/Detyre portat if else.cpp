#include <stdio.h>
#include <stdbool.h>

int main(){
    int hedhje, porta;
    int counter = 0, counterY = 0, piket = 0;
    bool x = true, y = true, z = true;

    printf("Vendosni numrin e hedhjeve te topit: ");
    scanf("%d", &hedhje);

    while(counter < hedhje){
        printf("Zgjidhni porten %d: 0.A   1.B:  ", counter + 1);
        scanf("%d", &porta);
        while((porta != 0) && (porta != 1)){
            printf("VLERE E PALEJUAR! Ju lutem shtypni numrin 1 ose 0: ");
            scanf("%d", &porta);
        }

        if(porta == 0){
            // Logjika per porten 0
            if(x){
                x = false;
            } else if(!x && y){
                x = true;
                counterY++;
                if(counterY % 2 == 0){
                    y = !y;
                }
            } else if(!x && !y){
                x = true;
                counterY++;
                piket++;
                if(counterY % 2 == 0){
                    y = !y;
                }
            }
        } else {
            // Logjika per porten 1
            if(!z){
                z = true;
                piket++;
            } else if(z && y){
                z = false;
                counterY++;
                if(counterY % 2 == 0){
                    y = !y;
                }
            } else if(z && !y){
                z = false;
                counterY++;
                piket++;
                if(counterY % 2 == 0){
                    y = !y;
                }
            }
        }
        counter++;
    }
    printf("Numri i pikeve: %d\n", piket);
    return 0;
}
