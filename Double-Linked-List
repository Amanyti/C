#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

/* Double Linked List ou Lista duplamente encadeada
Lista duplamente encadeada é um tipo de estrutura de dados 
que contém um grupo de nós interligados através dos ponteiros next e back, 
dentro da estrutura, que apontam, respectivamente, para o próximo nó e o nó anterior, até que os ponteiros sejam NULL, indicando assim o fim ou o início da lista. */

typedef struct no{
 int codigo;
 struct no *next;
 struct no *back;
} no;

struct no *inicio, *fim, *corrente, *auxiliar;

void ENTERDATA(){

    printf("\n Informe o código: ");
    scanf(" %d", &corrente->codigo);

}


void REMOVE(){
    
    int achou = 0;
    int xcod=0;

    if (inicio == NULL){ //SE A FILA ESTIVER VAZIA
        printf("\n>>>>> Lista vazia <<<<<");

    }else{ 
        printf("\n\nInforme o código a ser removido: ");
        scanf("%d", &xcod);
        auxiliar = inicio;
        
        if (auxiliar->codigo==xcod){ //SE FOR O 1° NÓ DA LISTA
            inicio = inicio->next;
            free(auxiliar);
            printf("\n>>>>> Registro removido da 1° posição <<<<<");
            achou = 1;

        }else{ //SE ESTIVER NO MEIO OU FIM DA LISTA
            corrente = inicio;
            auxiliar = auxiliar->next;

            while (auxiliar != NULL){
                if (auxiliar->codigo== xcod){
                    corrente->next = auxiliar->next;
                    free(auxiliar);
                    auxiliar = corrente->next;
                    auxiliar->back = corrente;
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
    int cod = 0; 
    int achou = 0;
    int k = 0;

    if(inicio == NULL){
        printf("\n>>>>> Lista vazia <<<<<");
    

    }else{
        printf("\n\nInforme o código a ser pesquisado: ");
        scanf("%d", &xcod);
        auxiliar = inicio;
        
        while(auxiliar != NULL){
            k++; 

            if(xcod== auxiliar->codigo){
                printf("\n>>>>> Registro encontrado na %d° posicao <<<<<\n", k);
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
        printf("\n\nCódigos da lista duplamente encadeada:\n");

        while (auxiliar != NULL){
            printf("|%d|-", auxiliar->codigo);
            auxiliar = auxiliar->next; 
        }
    }
}

void INSERT(){
    if(inicio == NULL){
        corrente = (no*)malloc(sizeof(no));
        inicio = corrente;
        fim = corrente;
        auxiliar = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        ENTERDATA();

    }else{
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        auxiliar = corrente;
        corrente->next = NULL;
        fim = corrente;
        ENTERDATA();
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
