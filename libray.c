#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 20

typedef struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    char area[30];
    int id;
    int year;
} book;

int book_count = 0;

void cadastrarLivro(book *books, int *book_count) 
{
    if (*book_count < MAX_BOOKS) 
    {
        printf("Nome do livro: ");
        scanf(" %[^\n]", books[*book_count].title);

        printf("Autor do livro: ");
        scanf(" %[^\n]", books[*book_count].author);

        printf("Editora do livro: ");
        scanf(" %[^\n]", books[*book_count].publisher);

        printf("Área do livro: ");
        scanf(" %[^\n]", books[*book_count].area);

        printf("ID do livro: ");
        scanf("%d", &books[*book_count].id);

        printf("Ano de publicação do livro: ");
        scanf("%d", &books[*book_count].year);

        printf("Livro cadastrado com sucesso!\n");
        (*book_count)++;
    } 
    else 
    {
        printf("Capacidade máxima de livros atingida.\n");
    }

}
int main() 
{
    book books[MAX_BOOKS];
    int option;
    int book_count = 0;
    
        do
        {
            printf("\n=== Biblioteca ===\n");
            printf("1. Cadastar livros\n");
            printf("2. Imprimir todos os livros\n");
            printf("3. Pesquisar livro por código\n");
            printf("4. Ordenar livros por ano de publicação\n");
            printf("5. Sair do programa\n");
            printf("Escolha uma opção:\n ");
            printf("==========================================\n");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                cadastrarLivro(books, &book_count);
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida por favor tente novamente\n");
                break;
            }
            
        } while (option != 5);
    return 0;
}