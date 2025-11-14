#include <stdio.h>
#include <string.h>

#define MAX 50


typedef struct {
    char nome[50];
    float horas;
    float valorHora;
    float total;
    int aprovado; 
} Registro;

int main() {
    Registro registros[MAX];
    int qtd = 0;
    int opcao;

    do {
        printf("\n=== Sistema de Controle de Horas Extras ===\n");
        printf("1 - Registrar horas extras\n");
        printf("2 - Listar solicitacoes\n");
        printf("3 - Aprovar/Reprovar solicitacao\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

        
        case 1: {
            printf("\n--- Novo Registro ---\n");
            printf("Nome do funcionario: ");
            getchar(); 
            fgets(registros[qtd].nome, 50, stdin);

            
            registros[qtd].nome[strcspn(registros[qtd].nome, "\n")] = '\0';

            printf("Horas extras trabalhadas: ");
            scanf("%f", &registros[qtd].horas);

            printf("Valor da hora extra (R$): ");
            scanf("%f", &registros[qtd].valorHora);

            
            registros[qtd].total = registros[qtd].horas * registros[qtd].valorHora;
            registros[qtd].aprovado = 0; 

            printf("\n[notificacao] horas enviadas para aprovacao do gestor\n");

            qtd++;
            break;
        }

        
        case 2: {
            printf("\n lista de solicitações: \n");

            if (qtd == 0) {
                printf("Nenhuma solicitacao registrada\n");
                break;
            }

            for (int i = 0; i < qtd; i++) {
                printf("\nID: %d\n", i);
                printf("Funcionario: %s\n", registros[i].nome);
                printf("Horas: %.1f   Valor/hora: R$ %.2f\n", registros[i].horas, registros[i].valorHora);
                printf("Total:  %.2f\n reais", registros[i].total);

                if (registros[i].aprovado == 0)
                    printf("Status: pendente\n");
                else if (registros[i].aprovado == 1)
                    printf("Status: aprovado\n");
                else
                    printf("Status: reprovado\n");
            }
            break;
        }

        
        case 3: {
            int id, decisao;

            if (qtd == 0) {
                printf("Nao ha solicitacoes para aprovar.\n");
                break;
            }

            printf("\nDigite o ID da solicitacao: ");
            scanf("%d", &id);

            if (id < 0 || id >= qtd) {
                printf("ID invalido!\n");
                break;
            }

            printf("Aprovar (1) ou Reprovar (2)? ");
            scanf("%d", &decisao);

            if (decisao == 1) {
                registros[id].aprovado = 1;
                printf("\n[NOTIFICACAO] %s teve suas horas APROVADAS.\n", registros[id].nome);
            } else if (decisao == 2) {
                registros[id].aprovado = 2;
                printf("\n[NOTIFICACAO] %s teve suas horas REPROVADAS.\n", registros[id].nome);
            } else {
                printf("Decisao invalida.\n");
            }

            break;
        }

        
        case 4:
            printf("\nEncerrando sistema...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
