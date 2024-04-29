#include <stdio.h>
#include <stdbool.h>
#define GJAT_EMER 25
#define MAX_ARTIKULL 100

struct artikull {
    int numri;
    char emri [GJAT_EMER +1];
    int gjendja;
} inventari[MAX_ARTIKULL];
bool inicializuar[MAX_ARTIKULL]={false};
//int inventari[MAX_ARTIKULL];

int nr_artikull = 0;
int gjej_artikull (int numer);
void shto (void);
void kerko (void);
void update (void);
void printo (void);
void menu (void);
void empty();
int lexo_rresht (char str [], int n);
void njeShifror();
/* main: i kerkon perdoruesit te jape nje kod veprimi, dhe pastaj
therret funksionin perkates te kryeje veprimin e kerkuar.
Kjo gje perseritet deri sa perdoruesi te jape 'q'. Nese
perdoruesi jep nje kod te gabuar printohet nje mesazh gabimi*/
int main ()
{
    char kodi;
    menu();
    for (;;) {

        printf("Fut kodin e veprimit: ");

        scanf(" %c", &kodi);
        while (getchar() != '\n') /* kalon deri te fundi i rreshtit */
        ;
        switch (kodi) {
            case 's': shto();
            break;
            case 'k': kerko();
            break;
            case 'u': update();
            break;
            case 'p': printo();
            break;
            case 'm': menu();
            break;
            case 'e': empty();
            break;
            case 'n': njeShifror();
            break;
            case 'q': return 0; //exit
            default: printf("Kod i gabuar\n");
        }
        printf("\n");
    }
}
/* Funksioni gjej_artikull kerkon ne matricen inventari artikull me
variablin numri sa vlera qe merr si argument. Kthen indeksin e
matrices nese gjen nje artikull me nje numer te tille, ne te
kundert kthen -1
*/
int gjej_artikull(int numri)
{
    int i;
    for (i = 0; i < nr_artikull; i++)
        if (inventari[i].numri == numri)
            return i;
    return -1;
}
/* Funksioni shto, i kerkon perdoruesit informacion per nje artikull te
ri dhe me pas e shton artikullin ne databaze. Kthen nje mesazh gabimi
nese artikulli egzistonte qe me pare ose nese databaza eshte plot */
void shto(void)
{
    int artikull_nr;
    if (nr_artikull == MAX_ARTIKULL)
    {
        printf("Databaza eshte plot; nuk mund te shtohet artikull.\n");
        return;
    }
    printf("Fut numrin e artikullit: ");
    scanf("%d", &artikull_nr);
    if (gjej_artikull(artikull_nr) >= 0)
    {
        printf("Artikulli egziston.\n");
        return;
    }

    inventari[nr_artikull].numri = artikull_nr;
    printf("Jep emrin e artikullit: ");
    lexo_rresht(inventari[nr_artikull].emri, GJAT_EMER);
    printf("Jep gjendjen e artikullit: ");
    scanf("%d", &inventari[nr_artikull].gjendja);
    inicializuar[nr_artikull]=true;
    nr_artikull++;
}
/* Funksioni kerko i kerkon perdoruesit te jap nje numer artikulli,
pastaj kerkon ne databaze, nese artikulli me kete numer egziston kthen
emrin dhe gjendjen e artikullit, ne te kundert printon nje mesazh
gabimi. */
void kerko(void)
{
    int i, numer;
    printf("Jep numrin e artikullit: ");
    scanf("%d", &numer);
    i = gjej_artikull(numer);
    if (i >= 0)
    {
        printf("Emri i artikullit: %s\n", inventari[i].emri);
        printf("Gjendja e artikullit: %d\n", inventari[i].gjendja);
    } else
        printf("Artikulli nuk u gjet.\n");
}
/* Funksioni update i kerkon perdoruesit te jape nje numer artikulli.
Kthen nje mesazh gabimi nese artikulli nuk egziston; ne te kundert
i kerkon perdoruesit te jape ndryshimin ne gjendje te artikullit
dhe i ben update. */
void update(void)
{
    int i, numer, ndryshimi;
    printf("Jep numrin e artikullit: ");
    scanf("%d", &numer);
    i = gjej_artikull(numer);
    if (i >= 0)
    {
        printf("Jep ndryshimin ne gjendje te artikullit: ");
        scanf("%d", &ndryshimi);
        inventari[i].gjendja += ndryshimi;
    } else
        printf("Artikulli nuk u gjet.\n");
}
/* Funksioni printo, printon gjithe artikujt ne databaze, duke dhene
numrin, emrin dhe gjendjen e artikullit. Artikujt printohen me ate
renditje qe jane futur ne databaze. */
void printo(void)
{
    int i;
    printf("Numri i Artikullit Emri i Artikullit "
    "Gjendja e Artikullit\n");
    for (i = 0; i < nr_artikull; i++)
        printf("%7d %25s %25d\n", inventari[i].numri, inventari[i].emri, inventari[i].gjendja);
}
/* Funksioni lexo_rresht lexon karakteret e rreshtit nje nga nje dhe
i ruan tek str. Ndalon leximin e karaktereve nese numri i tyre ka
tejkaluar vleren e argumentit n. Kthen numrin e karaktereve te
ruajtura tek stringa str */
int lexo_rresht (char str [], int n)
{
    int ch, i = 0;
    while ((ch = getchar()==' '))
    ;
    while ((ch = getchar ())!='\n')
    {
        if (i < n)
        str[i++]=ch;
    }
    str[i]='\0';
}
void menu(){
	printf("Shtypni s per te shtuar nje produkt\n");
	printf("Shtpni k per te kerkuar nje produkt\n");
	printf("Shtypni u per te perditesuar(update) listen\n");
	printf("Shtypni p per te printuar te dhenat e listes\n");
	printf("Shtypni e nese doni te shihni listen e artikujve te cilet nuk jane ne gjendje\n");
	printf("Shtypni n per te pare artikujt me kod njeshifror\n");
	printf("Shtypni q per te mbyllur programin\n\n");
	printf("Nese doni tju shfaqet perseri menuja shtypni m\n");
}
void empty(){
	int count=0;
	for(int i=0;i<MAX_ARTIKULL;i++){
		if(inicializuar[i] && !inventari[i].gjendja){
			printf("\nArtikulli %d nuk eshte ne gjendje", inventari[i].numri);
			count++;
		}	
	}
	printf("\nNumri i artikujve qe nuk jane ne gjendje eshte: %d", count);
}

void njeShifror(){
	for(int i=0; i<10;i++){
		if(inicializuar[i]){
			printf("%7d %25s %25d\n", inventari[i].numri, inventari[i].emri, inventari[i].gjendja);
		}
	}
}