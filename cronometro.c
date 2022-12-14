/*
Código feito por Emotion Now
Autor: Guilherme Laurindo Schneck / Hugo campelo de Melo Rosa
Projeto da Emotion Now em conjunto com a Flow
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>

#define FILE_S "sensor_data.txt"

int main()
{
    int sec = 0;
    int min = 0;
    int hour = 0;
    double data = (194927035+rand() % (1000000000-194927035))*0.000000001; //Gerador de dados aleatórios, pois não temos acesso aos reais ainda
    char inp;
    FILE *fp;

    fp = fopen(FILE_S, "a");

    printf("Pressione ENTER para comecar\n\nQuando comecar, pressione qualquer tecla para parar");
    scanf("%c", &inp);
    if(inp)
    {
        system("cls");

        Sleep(10);
        while (1)
        {
            if(kbhit())
                break;
            else
            {
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

                fprintf(fp, "%d:%d:%d -- %.9f\n", hour, min, sec, data);
                
                sec++;
                Sleep(1000);
            }
        }
    }
    
    fclose(fp);
    printf("Dados salvos com sucesso!");
    return 0;
}
