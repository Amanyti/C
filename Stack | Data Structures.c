#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/* PILHA OU STACK
Pilhas são estruturas de dados que armazenam os elementos 
em um formato sequencial, empilhando um item acima do outro. 
O paradigma principal por trás da pilha é o LIFO - Last In, First Out, ou “o último a entrar é o primeiro a sair”. */

typedef struct no{
    int cod;
    struct no *next, *back;
} no;

struct no *topo,*corrente,*auxiliar;
int k=0;

void Enterdata(){

    printf("\n Informe o Codigo: ");
    scanf("%d",&corrente->cod);

}

void PUSH(){

    if (topo == NULL){//SE FOR O PRIMEIRO NO DA PILHA
        corrente=(no*) malloc (sizeof(no));
        auxiliar = corrente;
        topo = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        Enterdata();
        k++;

    }else{

        if(k>=5){
            printf("\n>>>>> Stack Overflow <<<<<\n");
        }else{

            corrente=(no*)malloc(sizeof(no));
            auxiliar->next = corrente;
            corrente->back = auxiliar;
            topo = corrente;
            corrente->next = NULL;
            auxiliar = corrente;
            Enterdata();
            k++;
        }
    }
}

void POP(){

    if (topo == NULL){
        printf("\n>>>>> Stack Underflow <<<<<");
    }else{
        k--;
        auxiliar = topo;
        topo = topo->back;
        topo->next = NULL;
        free(auxiliar);
        printf("\n>>>>> Removido com sucesso o último registro da Pilha <<<<<");
        printf("\n>>>>> Número de elementos na Pilha: %d\n",k);

    }
}

void TOP(){
    if( topo == NULL){
        printf("\n>>>>> Stack Underflow <<<<<\n");
    }else{
        printf("\n Código: %d",topo->cod);
    }
}

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    topo = NULL;
    corrente = NULL;
    auxiliar = NULL;
    int op = 0, resp = 0;

    do{
        system("cls");
        printf("\n__________ Pilha / Stack __________");
        printf("\n [1] - PUSH (Inserção)");
        printf("\n [2] - TOP (Exibição) ");
        printf("\n [3] - POP  (Remoção)");

        printf("\n\n Escolha a Operação: ");
        scanf("%d",&op);

        switch (op){
        case 1:
            PUSH();
            break;
        case 2:
            TOP();
            break;
        case 3:
            POP();
            break;

        default:
            printf("\n>>>>> Opção Inválida, Tente novamente <<<<<");

        }

        printf("\n\n Deseja continuar no sistema? [S]im [N]ao ");
        scanf(" %c", &resp);
        resp=toupper(resp);

    }while(resp != 'N');
    return 0;
}

