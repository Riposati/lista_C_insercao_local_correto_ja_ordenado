#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listaSimples{
    int valor;
    struct lista *prox;
};

struct listaSimples *insere(struct listaSimples *ini,int valor){

    struct listaSimples *aux = (struct listaSimples *)malloc(sizeof(struct listaSimples));
    aux->valor = valor;
    aux->prox = NULL;

    if(ini==NULL)ini = aux; /// caso o ponteiro ini seja nulo entra aqui
    else{

        struct listaSimples *ultimo = ini;
        int flag= 0;
        struct listaSimples *aux2 = ini;
        struct listaSimples *aux3 = NULL;

        if(ultimo->prox==NULL){ /// condição de único bloco

            if(aux->valor > ultimo->valor){

                ultimo->prox = aux;
            }else{

                aux->prox = ultimo;
                ini = aux;
            }
        }else{
            /// no caso de ser menor que o primeiro ou igual o bloco novo que chegar entra aqui
            if(aux->valor < ultimo->valor || aux->valor==ultimo->valor){
                aux->prox = ultimo;
                ini = aux;
            }else{
                    /// caso o bloco esteja no meio aqui será deslocado para a posição certa
                    while(ultimo->prox!=NULL){

                        aux2 = ultimo;
                        aux3 = ultimo;
                        ultimo = ultimo->prox;

                        if(aux->valor > aux2->valor &&
                           aux->valor < ultimo->valor){ /// desloca blocos do meio para encaixar o bloco na posição certa
                                flag=1;
                                aux2->prox = aux;
                                aux->prox = ultimo;
                                break;
                           }else{

                                if(aux->valor==ultimo->valor){ /// Se tiver bloco com valores no meio igual entra aqui pra encaixar na posição certa
                                    flag=1;
                                    aux3 = ultimo->prox;
                                    ultimo->prox = aux;
                                    aux->prox = aux3;
                                    break;
                                }
                           }
                        }

                    if(flag==0){ /// aqui é só pra valores que vão pro final mesmo da lista

                        ultimo->prox = aux;
                    }
                }
            }
        }
    return ini;
}

void mostrarLista(struct listaSimples *ini){

    if(ini!=NULL){
        struct listaSimples *aux = ini;

        if(aux!=NULL){
            while(aux!=NULL){
                printf("%d -> ",aux->valor);
                aux = aux->prox;
            }
        }else{

            puts("Lista vazia");
        }
    }

    printf("\n\n");
}

int main()
{

    struct listaSimples *ini = NULL;
    int i;

    /*ini = insere(ini,1);
    ini = insere(ini,0);
    ini = insere(ini,3);
    ini = insere(ini,2);
    ini = insere(ini,7);
    ini = insere(ini,-1);
    ini = insere(ini,4);
    ini = insere(ini,6);
    ini = insere(ini,-1);
    ini = insere(ini,0);
    ini = insere(ini,0);
    ini = insere(ini,0);
    ini = insere(ini,-5);
    ini = insere(ini,5);
    ini = insere(ini,50);*/

    /* pra gerar números aleátorios ,
       pra mudar o valor limite é só alterar o valor apos %
    */

    for(i=1 ; i <= 10 ; i++){
        ini = insere(ini,rand() % 100);
    }

    printf("valores alocados ja ordenados : \n");
    mostrarLista(ini);

    system("pause");
}
