#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/* QUEUE OU FILAS
Fila são estruturas de dados bastante utilizadas na computação, 
onde o primeiro elemento a ser inserido, será também o primeiro a ser retirado. 
Desta forma, serão adicionados elementos no fim e removê-los pelo início.
A estrutura de dados fila segue um padrão conhecido como FIFO (first-in first-out), onde o primeiro a entrar é o primeiro a sair. */ 

typedef struct no{
    int cod;
    struct no *next;
}no;

struct no *inicio = NULL, *fim = NULL, *auxiliar = NULL;
int c = 0;

void Enqueue(){//VOID DE INSERÇÃO

    if(inicio == NULL){//SE A FILA ESTIVER VAZIA.
        fim = (no*)malloc(sizeof(no));
        printf("\n Informe o código para ser inserido na lista: ");
        scanf("%d", &fim->cod);
        fim->next = NULL;
        inicio = fim;
        auxiliar = fim;
        c++;
    }else{
        if(c >= 10){// E SENÃO ESTIVER.
            printf(">>>>> Queue Overflow <<<<<");
        }else{
            fim = (no*)malloc(sizeof(no));
            printf("\n Informe o código para ser inserido na lista: ");
            scanf("%d", &fim->cod);
            auxiliar->next = fim;
            fim->next = NULL;
            auxiliar = fim;
            c++;
        }
    }

}

void Dequeue(){//VOID DE REMOÇÃO

    if(inicio == NULL){
        printf("\n>>>>> Queue Is Empty <<<<<");

    }else{
        auxiliar = inicio;
        inicio = inicio->next;
        free(auxiliar);
        printf("\n>>>>> Removido o primeiro elemento da fila <<<<<\n");
        c--;
    }

}

void SeaQueue(){//VOID DE PESQUISA
    int pesq = 0, k = 0, achou = 0;

    if(inicio == NULL){
        printf("\n>>>>> Queue Is Empty <<<<<");

    }else{
        auxiliar = inicio;
        printf("\n Informe o código a ser procurado: ");
        scanf("%d", &pesq);
        while(auxiliar!=NULL){
            k++;
            if(pesq == auxiliar->cod){
                printf("\n>>>>> A task se encontra na %d° posição na Queue <<<<<\n", k);
                 achou = 1;
                break;
            }else{
                auxiliar = auxiliar->next;
            }
        }
        if(achou == 0){
            printf("\n>>>>> Task not found Queue <<<<\n");
        }else{
        }
    }

}


int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int op;
    char resp;

    do{
        system("cls");
        printf("\n__________ QUEUE __________");
        printf("\n [1] Enqueue (inserção)\n [2] Dequeue (Remoção)\n [3] Seoqueue (Pesquisa) \n\n Escolha: ");
        scanf(" %d", &op);
        fflush(stdin);

        switch (op){
        case 1:
         printf("\n__________ Enqueue __________\n");
            Enqueue();
            break;
        case 2:
            printf("\n__________ Dequeue __________");
            Dequeue();
            break;
        case 3:
            printf("\n__________ Sequeue __________");
            SeaQueue();
            break;
        default:
            printf("\n>>>>> Escolha Invalida <<<<");
        }

        printf("\n\n Deseja continuar no sistema? [S]im [N]ao ");
        scanf(" %c", &resp);
        resp = toupper(resp);

    }while(resp != 'N');

    return 0;

}


