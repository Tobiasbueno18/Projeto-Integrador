#include <stdio.h>

struct Veiculo {
    int codigo;
    char modelo[50];
    char marca[50];
    char categoria[30];
    char status[20];
};

struct Veiculo v[50];
int total = 0;

void cadastrar() {
    printf("\nCodigo: ");
    scanf("%d", &v[total].codigo);

    printf("Modelo: ");
    scanf(" %[^\n]", v[total].modelo);

    total++;
    printf("\nCadastrado!\n");
}

void listar() {
    int i;

    if (total == 0) {
        printf("\nNenhum veiculo.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d\n", v[i].codigo);
        printf("Modelo: %s\n", v[i].modelo);
    }
}

void alterar() {
    int cod, i;

    printf("\nDigite o codigo: ");
    scanf("%d", &cod);

    for (i = 0; i < total; i++) {
        if (v[i].codigo == cod) {

            printf("Novo modelo: ");
            scanf(" %[^\n]", v[i].modelo);

            printf("Nova marca: ");
            scanf(" %[^\n]", v[i].marca);
            printf("\nAlterado!\n");
            return;
        }
    }

    printf("\nNao encontrado!\n");
}

void excluir() {
    int cod, i, j;

    printf("\nDigite o codigo: ");
    scanf("%d", &cod);

    for (i = 0; i < total; i++) {
        if (v[i].codigo == cod) {

            for (j = i; j < total - 1; j++) {
                v[j] = v[j + 1];
            }

            total--;
            printf("\nExcluido!\n");
            return;
        }
    }

    printf("\nNao encontrado!\n");
}

int main() {
    int op;

    do {
        printf("\n1 Cadastrar\n");
        printf("2 Listar\n");
        printf("3 Alterar\n");
        printf("4 Excluir\n");
        printf("0 Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) cadastrar();
        else if (op == 2) listar();
        else if (op == 3) alterar();
        else if (op == 4) excluir();
        else if (op == 0) printf("\nFim\n");
        else printf("\nOpcao invalida\n");

    } while (op != 0);

    return 0;
}
