#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>

#define FILE_S "sensor_data.txt"



typedef struct NO{
    
    int dado;
    int hour;
    int min;
    int seg;
    struct NO *prox, *aux, *n;
    
}NO;

typedef struct FILA{

    NO *inicio;
    NO *fim;

}FILA;

void inicializador(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void add(int hour, int min, int seg, int dado, FILA *f){
    
    NO *ptr = (NO*) malloc(sizeof(NO));

        ptr->hour = hour;
        ptr->min = min;
        ptr->seg = seg;
        ptr->dado = dado;
        ptr->prox = NULL;
        if(f->inicio == NULL){
            f->inicio = f->fim = ptr;
            printf("%d:%d:%d-->%d\n", ptr->hour, ptr->min, ptr->seg, ptr->dado);
        }else{
            if(f->inicio->seg > seg){
                ptr->prox = f->inicio;
                f->inicio = ptr;
            }else {
               NO *n = f->inicio;
               NO *aux = n->prox;
               while(aux != NULL && aux->seg < seg){
                    n = n->prox;
                    aux = aux->prox;
               }
               if(aux == NULL){
                   f->fim->prox = ptr;
                   f->fim = ptr;
                   ptr->prox = NULL;
               }else{
                    n->prox = ptr;
                    ptr->prox = aux;
               }     
        }
        printf("%d:%d:%d-->%d\n", ptr->hour, ptr->min, ptr->seg, ptr->dado);
    }
}

void print(FILA *f){
    
    NO *ptr = f->inicio;
    if(ptr!=NULL){
        
        while(ptr!=NULL){
            if(ptr->prox == NULL){
            printf("[%d:%d:%d-->%d]\n", ptr->hour, ptr->min, ptr->seg, ptr->dado);
            }else{
            printf("[%d:%d:%d-->%d]\n", ptr->hour, ptr->min, ptr->seg, ptr->dado);    
            }
            ptr = ptr->prox;
        }
      printf("\n");
        
    }else{
        
        printf("Nenhum dado listado!\n");
        return;    
    }   
}

int main()
{
    FILA *f1 = (FILA*)malloc(sizeof(FILA));
    int sec = 0;
    int min = 0;
    int hour = 0;
    int data = 0;
    char inp;
    FILE *fp;
    char nome[70], login[30], nick[30], email[50], profissao[30], jogo[30], senha[30];
    int idade, comecar, novamente, logincheck = 1;
    char cmplogin[30], cmpsenha[30];

    
    printf("\t\tMenu de Cadastro\n\n ");


    do{

    printf("Insira seu nome: ");
    scanf(" %s",nome);
    fflush(stdin);

    printf("Insira seu nick: ");
    scanf(" %s",nick);
    fflush(stdin);

    printf("Insira seu email: ");
    scanf( "%s", email);
    fflush(stdin);

    printf("Insira sua idade: ");
    scanf("%d", &idade);
    fflush(stdin);

    printf("Insira seu login: ");
    scanf( "%s", login);
    fflush(stdin);

    printf("Insira sua senha: ");
    scanf( "%s", senha);
    fflush(stdin);

    
        printf("Deseja cadastrar outro usuário ou ir para a tela de login? (cadastrar um novo usuário [1] ou ir para a tela de login [2]): ");
        scanf("%d", &novamente);
        
        if (novamente == 2){
            printf("\nBem vindo a tela de login ");
            do{
                printf("\nInsira seu login: ");
                scanf(" %s", cmplogin);
                fflush(stdin);
                
                printf("\nInsira sua senha: ");
                scanf(" %s", cmpsenha);
    
                if (strcmp(login,cmplogin) == 0){
                  if(strcmp(senha,cmpsenha) == 0){
                    printf("Login realizado com sucesso\n");
                  }
                }
                logincheck = 1;
                if (strcmp(login,cmplogin) == 1 || strcmp(senha,cmpsenha)){
                  logincheck = 0;
                  printf("login ou senha incorreto\n");
                }
            }while(logincheck==0);
            


        }
          
    }   
            while(novamente == 1);
    
    if(logincheck==1){
    inicializador(f1);//iniciando a fila de dados

    fp = fopen(FILE_S, "a");

    printf("Pressione ENTER para comecar\n\nQuando comecar, pressione qualquer tecla para parar\n");
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

                data = 194+rand() % (100-194); //Gerador de dados aleatórios, pois não temos acesso aos reais ainda
                add(hour, min, sec, data, f1);//inserindo na fila os dados aleatorios
                fprintf(fp, "%d:%d:%d -- %d\n", hour, min, sec, data);
                
                sec++;
                Sleep(1000);
            }
        }
    }
    
    print(f1);//printando os dados coletados em seu respectivo tempo de coleta
    fclose(fp);
    printf("Dados salvos com sucesso!\n");

    return 0;
    }
}