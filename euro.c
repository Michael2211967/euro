/* Euro.c				 */
/* Dieses Programm rechnet Euro in DM um */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "upper.h"
#include "tools.h"

float Wert, Euro, DM;
char Waehrung[5];

float DM_Euro(float DM)
{
    Euro=DM/1.95583;
    return(Euro);
}

float Euro_DM(float Euro)
{
    DM=Euro*1.95583;
    return(DM);

}

void Ausgabe(float Euro, float DM)
{
    printf("\n\033[4m\033[31m%8.2f EUR = %8.2f DM\033[0m\n\n", Euro, DM);
}

int main(void)
{
    char Antwort[5];
    do
    {
        Wert = getSafeFloat("\nGeben Sie bitte den Wert in Euro oder DM ein: ");
        printf("Geben Sie die Ausgabewährung EUR oder DM ein: ");
	    scanf("%4s",Waehrung);
        while(getchar() != '\n'); // Puffer leeren nach String-Eingabe

	m_upper(Waehrung);
	    if (strcmp(Waehrung,"EUR") == 0)
	        Ausgabe(DM_Euro(Wert), Wert);
	    else
	    if (strcmp(Waehrung,"DM") == 0)
	        Ausgabe(Wert, Euro_DM(Wert));
	    else
                puts("\n\033[7mDie Währung ist mir nicht bekannt!!!\033[0m");
	    printf("\nWollen Sie noch eine Umrechnung? ");
	    scanf("%4s",Antwort);
        while(getchar() != '\n'); // Puffer leeren nach String-Eingabe
	m_upper(Antwort);
    }
    while(strcmp(Antwort,"JA") == 0 || Antwort[0] == 'J');
    return(0);
}
