/*
Código feito por Emotion Now
Autor: Guilherme Laurindo Schneck
Projeto da Emotion Now em conjunto com a Flow
*/

//Macros
#define FILE_S "sensor_data.txt"

//Bibliotecas
#include<stdio.h> //Biblioteca necessárioa para input e output
#include<time.h> //Biblioteca necessária para parar o código por 1seg
#include<stdlib.h> //Biblioteca necessária para obter mais funções necessárias para o código
#include<windows.h> //Biblioteca necessária para limpar o console
#include<math.h> //Biblioteca necessária para fazer operações matemáticas no código
#include<conio.h> //Biblioteca necessária para detectar input de teclado sem parar o código

int main()
{
    //Variáveis do cronômetro
    int sec = 0;
    int min = 0;
    int hour = 0;
    int data = 0;
    char inp;
    FILE *fp;

    fp = fopen(FILE_S, "a"); //Cria ou abre o arquivo em que serão armazenados os dados

    printf("Pressione ENTER para comecar\n\nQuando comecar, pressione qualquer tecla para parar");
    scanf("%c", &inp);
    if(inp) //Detecta se alguma tecla foi pressionada para iniciar o cronômetro
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

                data = 194927035+rand() % (1000000000-194927035); //Gerador de dados aleatórios, pois não temos acesso aos reais ainda

                system("cls");

                fprintf(fp, "%d:%d:%d -- %d\n", hour, min, sec, data); //Armazena os dados no arquivo
                
                sec++; //Incrementação dos segindos no timestamp
                Sleep(1000); //Intervalo de 1s entre coletas de dados
            }
        }
    }
    
    fclose(fp); //Fecha o arquivo
    return 0;
}
