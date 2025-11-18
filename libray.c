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

void imprimirLivros(const book *books, int book_count) 
{
    if (book_count == 0) 
    {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (int i = 0; i < book_count; i++)
    {
        printf("--------------------------\n");
        printf("\nLivro %d:\n", i + 1);
        printf("Título: %s\n", books[i].title);
        printf("Autor: %s\n", books[i].author);
        printf("Editora: %s\n", books[i].publisher);
        printf("Área: %s\n", books[i].area);
        printf("ID: %d\n", books[i].id);
        printf("Ano de publicação: %d\n", books[i].year);
        printf("--------------------------\n");
    }
}

void pesquisarLivroPorCodigo(const book *books, int book_count, int id) 
{
    printf("Digite o ID do livro que deseja pesquisar: ");
    scanf("%d", &id);
    
    for(int i = 0; i < book_count; i++)
    {
        if(books[i].id == id)
        {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", books[i].title);
            printf("Autor: %s\n", books[i].author);
            printf("Editora: %s\n", books[i].publisher);
            printf("Área: %s\n", books[i].area);
            printf("ID: %d\n", books[i].id);
            printf("Ano de publicação: %d\n", books[i].year);
            return;
        }
    }
}

void ordenarLivros(book *books, int book_count) 
{
    for (int i = 0; i < book_count - 1; i++) 
    {
        for (int j = 0; j < book_count - i - 1; j++) 
        {
            if (books[j].year > books[j + 1].year) 
            {
                book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    printf("Livros ordenados por ano de publicação com sucesso!\n");
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
                imprimirLivros(books, book_count);
                break;
            case 3:
                pesquisarLivroPorCodigo(books, book_count, 0);
                break;
            case 4:
                ordenarLivros(books, book_count);
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