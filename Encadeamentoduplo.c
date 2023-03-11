#include "Encadeamentoduplo.h"

int main(){
    int op = 5;
    int num, quant;
    header *h = cria_header();

    while (op != 12){
        printf("\nSelecione uma das opcoes:\n");
        printf("(0) Adicionar itens a lista.\n");
        printf("(1) Escolher um numero para retirar da lista.\n");
        printf("(2) Printar lista.\n");
        printf("(3) Limpar lista.\n");
        printf("(4) Sair.\n");
        scanf("%d", &op);
        
        switch (op){
        case 0:
            printf("Quantos numeros deseja adicionar? ");
            scanf("%d", &quant);
            for(int i = 0; quant > i; i++){
                printf("Digite o numero que deseja adicionar: ");
                scanf("%d", &num);
                cria_lista(h, num);
            }
            break;
        
        case 1:
        printf("Digite o numero que deseja retirar: ");
            scanf("%d", &num);
            retira_procurado(h, num);
            break;

        case 2:
            printa_lista(h);
            break;

        case 3:
            limpa_lista(h);
            break;

        case 4:
            op = 12;
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    printf("\nPrograma finalizado!\n\n");
    

    return 0;
}