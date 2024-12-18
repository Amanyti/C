#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/* Simple Linked List ou Lista simplesmente encadeada
Lista simplesmente encadeada é um tipo de estrutura de dados
que contém um grupo de nós interligados através de um ponteiro next,
dentro da estrutura, que aponta para o próximo nó até que o ponteiro seja NULL, indicando assim o fim da lista. */

typedef struct no{
    int cod;
    struct no *next;
}no;

struct no *inicio, *corrente, *auxiliar;

void ENTERDATA(){
    printf("Digite o código a ser inserido: ");
    scanf("%d", &corrente->cod);
}

void INSERT(){
    if(inicio==NULL){
        corrente = (no*)malloc(sizeof(no));
        corrente->next = NULL;
        inicio = corrente;
        auxiliar = corrente;
        ENTERDATA();
    }else{
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->next = NULL;
        ENTERDATA();
        auxiliar = corrente;
    }
}

void REMOVE(){

    int achou = 0;
    int xcod=0;

    if (inicio == NULL){ 
        printf("\n>>>>> Lista vazia <<<<<");

    }else{
        printf("\n\nDigite o código a ser removido: ");
        scanf("%d", &xcod);
        auxiliar = inicio;

        if (auxiliar->cod==xcod){ //SE FOR O 1° NÓ DA LISTA
            inicio = inicio->next;
            free(auxiliar);
            printf("\n>>>>> Registro removido da 1° posição <<<<<");
            achou = 1;

        }else{ //SE ESTIVER NO MEIO OU FIM DA LISTA
            corrente = inicio;
            auxiliar = auxiliar->next;

            while (auxiliar != NULL){
                if (auxiliar->cod== xcod){
                    corrente->next = auxiliar->next;
                    free(auxiliar);
                    auxiliar = corrente->next;
                    printf("\n>>>>> Registro removido <<<<<");
                    achou = 1;
                    break;

                }else{
                    auxiliar = auxiliar->next;
                    corrente = corrente->next;
                }
            }
        }
    }
    if (achou == 0){
        printf(">>>>> Registro inexistente na lista <<<<<");

    }
}

void SEARCH(){

    int xcod=0;
    int achou = 0;
    int k = 0;

    if(inicio == NULL){
        printf("\n>>>>> Lista vazia <<<<<");


    }else{
        printf("\n\nDigite o código a ser pesquisado: ");
        scanf("%d", &xcod);
        auxiliar = inicio;

        while(auxiliar != NULL){
            k++;

            if(xcod== auxiliar->cod){
                printf("\nRegistro encontrado na %d° posicao \n", k);
                achou = 1;
                break;

            }else{
                auxiliar = auxiliar->next;
            }
        }
        if(achou == 0){
            printf("\n>>>>> Registro inexistente tabela <<<<<");
        }
    }
}

void SHOW(){
    if (inicio == NULL) {
        printf("\n >>>>> Lista vazia <<<<<");


    }else{
        auxiliar = inicio;
        printf("\n\nCódigos da lista simplesmente encadeada:\n");

        while (auxiliar != NULL){
            printf("|%d|-", auxiliar->cod);
            auxiliar = auxiliar->next;
        }
    }
}

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int op;
    char resp;
    inicio = NULL;
    corrente = NULL;
    auxiliar = NULL;

    do{
        system("cls");
        printf("\n__________ LISTA __________");
        printf("\n [1] Inserir Registro na Lista\n [2] Exibir os Registros da Lista\n [3] Pesquisar Registros da Lista \n [4] Remover Registros da Lista\n\n Escolha: ");
        scanf(" %d", &op);
        fflush(stdin);

        switch (op){
            case 1:
            printf("\n__________ Inserção __________\n");
            INSERT();
            break;

            case 2:
            printf("\n__________ Exibir __________");
            SHOW();
            break;

            case 3:
            printf("\n__________ Pesquisa __________");
            SEARCH();
            break;

            case 4:
            printf("\n__________ Remoção __________");
            REMOVE();
            break;

            default:
            printf("\n>>>>> Escolha inválida <<<<<");
        }

        printf("\n\n Deseja continuar no sistema? [S]im [N]ao ");
        scanf(" %c", &resp);
        resp=toupper(resp);

    }while(resp != 'N');
    return 0;
}



