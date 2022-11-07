/*
Código feito por Emotion Now
Autor: Guilherme Laurindo Schneck
Projeto da Emotion Now em conjunto com a Flow
*/

//Bibliotecas
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>

int main()
{
    //Variáveis do cronômetro
    int sec = 0;
    int min = 0;
    int hour = 0;
    char inp;

    scanf("%c", &inp); //Detecta se alguma tecla foi pressionada para iniciar o cronômetro
    if(inp)
    {
        Sleep(10);
        while (1)
        {
            if(kbhit()) //Detector de input de teclado
                break;
            else
            {
                //Conversão segundo-minuto/minuto-hora
                if(sec == 60)
                {
                    sec = 0;
                    min++;
                    if(min == 60)
                    {
                        min = 0;
                        hour++;
                    }
                }
            
                system("cls");
                printf("%d:%d:%d -- %d\n", hour, min, sec, 194927035+rand() % (1000000000-194927035)); //Imprime h:m:s -- Dado do sensor
                sec++;
                Sleep(1000); //Intervalo de 1s entre coletas de dados
            }
        }
    }
        
    return 0;
}
