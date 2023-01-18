#include <stdio.h>
#include <cctype>//per isdigit();
#include <cstring>//per strlen();
#include "prototipi.h"
using namespace std;
int main() {
    char input1[1000];//prima stringa insrita dall'utente
    char input2[1000];//seconda stringa
    int n1 = 0;//variabile che conterrà la stringa1 convertita in numero;
    int n2 = 0;//variabile che conterrà la stringa 2 convertita in numero;
    char operazione;//varibile che conterrà il carattere relativo all'operazione scelta;
    int risultato = 0;
    float risDiv = 0;//variabile float per il risultato della divisione;
    bool ctrl;//variabile di controllo per ripetere il programma;
    bool isdigit1;//variabile booleana che stabilisce se ogni carattere della stringa 1 corrisponde a un numero;
    bool isdigit2;//variabile booleana che stabilisce se ogni carattere della stringa 2 corrisponde a un numero;
    char restart;
    do {
        restart = '/';//riporto restart a un valore neutrale ogni volta che il programma si ripete;
        isdigit1 = false;//riporto i valori booleani su falso ogni volta che il programma si ripete;
        isdigit2 = false;
        while(isdigit1 == false || isdigit2 == false) {//ciclo while che si ripeterà fino a quando entrambe le stringhe inserite non conterranno solo numeri;
            printf("Inserisci il primo numero: \n");
            scanf("%s", input1);
            printf("Inserisci il secondo numero: \n");
            scanf("%s", input2);
            for (int i = 1; i < strlen(input1); i++) {//controllo ogni carattere della stringa per verificare che contenga numeri;
                if (isdigit(input1[i]) != 0) {//uso la variabile isdigit() della livreria cctype per verificare che ci siano solo caratteri numerici;
                    isdigit1 = true;//se contiene solo numeri isdigit1 è vero;
                } else {
                    isdigit1 = false;//altrimenti è falso
                }
            }
            for (int i = 0; i < strlen(input2); i++) {//stessa logica per la seconda stringa;
                if (isdigit(input2[i]) != 0) {
                    isdigit2 = true;
                } else {
                    isdigit2 = false;
                }
            }
            if(isdigit2 && isdigit1){//solo se entrambe le stringhe contengono solo numeri verranno convertite in integer tramite la funzione stoi() e il programma prosegue;
                n1 = stoi(input1);
                n2 = stoi(input2);

            }else{
                printf("Input errato!\n");//altrimenti comunico l'errore all'utente e il ciclo while si ripete;
            }
        }
        printf("seleziona l'operazione (+, -,  *, /, %)\n");//switch per scegliere l'operazione;
        scanf(" %c", &operazione);
        switch(operazione){
            case '+':
                risultato = add(n1, n2);
                printf("risultato: %d\n", risultato);
                break;
            case '-':
                risultato = sub(n1, n2);
                printf("risultato: %d\n", risultato);
                break;
            case '*':
                risultato = molt(n1, n2);
                printf("risultato: %d\n", risultato);
                break;
            case '/':
                risDiv = divisione(n1, n2);
                printf("risultato: %f\n", risDiv);
                break;
            case '%':
                risultato = modulo(n1, n2);
                printf("risultato: %d\n", risultato);
                break;
            default:
                printf("Input errato!\n");
        }
        while(restart != 'y' && restart != 'n') {//ciclo while per consentire all'utente di fare un'altra operazione;
            printf("Vuoi effettuare un'altra operazione? (y/n)\n");
            scanf(" %c", &restart);
            if(restart == 'y'){
                ctrl = true;
            }else if(restart == 'n'){
                ctrl = false;
            }else{
                printf("Input errato!\n");
            }

        }

    }while(ctrl);

    return 0;
}
