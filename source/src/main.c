#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

extern void on_off(char* input);
extern void frecce_direzione(int* input, int* frecce);
extern void gomme();

int arrowKey() {    
    int keyPressed=0;
    char input = getchar();
    if (input == 27) 
        if (getchar() == 91) 
            keyPressed = getchar();         
    if (input == 10) 
        keyPressed=10;

    return keyPressed;
}

int main(int argc, char *argv[])
{	  
	char blocco[4] = "ON";
	char backhome[4] = "ON";
    int frecce = 3;

    int menuIndex = 1;          //voce selezionata
    int key;                    //input
    int c;                      //pulizia buffer getchar
                        
	while(menuIndex!=9)
	{
		time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        //MENU
        system("clear");
        printf("Usa le frecce su e giù e conferma con Enter per navigare il menu.\n");
        switch(menuIndex) {
            case(1):
                printf("\n\nSetting automobile:\n");
                break;
            case(2):
                printf("\n\nData: %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
                break;
            case(3):
                printf("\n\nOra: %02d:%02d\n", tm.tm_hour, tm.tm_min);
                break;
            case(4):
                printf("Premi la freccia destra e conferma con Enter per cambiare l'impostazione.\n\nBlocco automatico porte: %s\n", blocco);
                break;
            case(5):
                printf("Premi la freccia destra e conferma con Enter per cambiare l'impostazione.\n\nBack-home: %s\n", backhome);
                break;
            case(6):
                printf("Premi la freccia destra e conferma con Enter per cambiare l'impostazione.\n\nFrecce direzione\n");
                break;
            case(7):
                printf("Premi la freccia destra e conferma con Enter per cambiare l'impostazione.\n\nReset pressione gomme \n");
                break; 
            default:
                break;
        }
        
        //INPUT UTENTE
        key = arrowKey();
        if(key == 65)
            menuIndex--;
        if(key == 66)
            menuIndex++;

        //SOTTOMENU
        if((key==67)&&((menuIndex>=4)&&(menuIndex<=7)))
        {  
            do{                
                while ((c = getchar()) != '\n' && c != EOF) {}
                system("clear");                
                
                if(menuIndex==4){
                    printf("Premi freccia su e giù e conferma con Enter per cambiare l'impostazione.\nPremi Enter per uscire.\n\n");
                    printf("Blocco automatico porte: %s\n", blocco);
                    key = arrowKey();  
                    if((key==66)||(key==65))
                        on_off(blocco);            
                }
                if(menuIndex==5){
                    printf("Premi freccia su e giù e conferma con Enter per cambiare l'impostazione.\nPremi Enter per uscire.\n\n");
                    printf("Back-home: %s\n", backhome);    
                    key = arrowKey(); 
                    if((key==66)||(key==65))                 
                        on_off(backhome);            
                }
                if(menuIndex==6){
                    printf("Inserisci un nuovo valore e conferma con Enter (min=2, max=5, default=3).\nPremi Enter per uscire.\n\n"); 
                    printf("Frecce direzione: %d\n", frecce);

                    key=-999;
                    int digit;
                    while ((digit = getchar()) != '\n') {
                        if(key==-999)
                            key=0;
                        key = key * 10 + (digit - '0');
                    }
                
                    if(key==-999)
                        key=10;             //invio senza input, uscire da sottomenu
                    else                        
                        frecce_direzione(&key, &frecce);                     
                    ungetc('\n', stdin);    //serve o esecuzione si blocca nello svuotare il buffer di input                                                  
                }
                if(menuIndex==7){       
                    printf("Premi freccia destra e conferma con Enter per resettare l'impostazione.\nPremi Enter per uscire.\n\n"); 
                    printf("Reset pressione gomme \n");
                    key = arrowKey(); 
                    if(key == 67){
                        gomme();              
                        sleep(2);
                        key = 10;
                    }                 
                }

            } while(key != 10);
        }  

        //GESTIONE SCORRIMENTO MENU
        if((menuIndex==8) || ((menuIndex==6) && (argc != 2 ||strcmp(argv[1], "2244") != 0)))
            menuIndex=1;
        if(menuIndex==0) 
            menuIndex=7;
        if((menuIndex==7) && (argc != 2 ||strcmp(argv[1], "2244") != 0))
            menuIndex=5;

    }

    return 0;
}
