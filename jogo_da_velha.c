#include <stdio.h>
#include <stdlib.h>

#define tam 3

void Reset(int tabuleiro[][tam])
{
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void PrintTabuleiro(int tabuleiro[][tam])
{
    printf("\n");

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            if(tabuleiro[i][j] == 0)
                printf("|   |");
            else if(tabuleiro[i][j] == 1)
                printf("| X |");
            else
                printf("| O |");
        }
        printf("\n");
    }
}

int somaDiagonalEsquerda(int tabuleiro[][tam])
{
    int soma = tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0];
    return(soma);
}

int somaDiagonaDireita(int tabuleiro[][tam])
{
    int soma = tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2];
    return(soma);
}

int somaLinha(int tabuleiro[][tam], int linha)
{
    int soma = 0;

    for(int j = 0; j < tam; j++)
    {
        soma = soma + tabuleiro[linha][j];
    }
    return(soma);
}

int somaColuna(int tabuleiro[][tam], int coluna)
{
    int soma = 0;

    for(int i = 0; i < tam; i++)
    {
        soma = soma + tabuleiro[i][coluna];
    }
    return(soma);
}

void VezCompiuter(int tabuleiro[][tam])
{
    int linhaR, colunaR, loop = 0;

    //1- Se der pra ganhar, ganhe.
    for(int i = 0; i < tam; i++)//Checa horizontais e verticais.
    {
        if(tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 && tabuleiro[i][2] == 0)
        {
            tabuleiro[i][2] = 1;
            return;
        }
        if(tabuleiro[i][0] == 1 && tabuleiro[i][2] == 1 && tabuleiro[i][1] == 0)
        {
            tabuleiro[i][1] = 1;
            return;
        }
        if(tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 && tabuleiro[i][0] == 0)
        {
            tabuleiro[i][0] = 1;
            return;
        }
        if(tabuleiro[0][i] == 1 && tabuleiro[1][i] == 1 && tabuleiro[2][i] == 0)
        {
            tabuleiro[2][i] = 1;
            return;
        }
        if(tabuleiro[0][i] == 1 && tabuleiro[2][i] == 1 && tabuleiro[1][i] == 0)
        {
            tabuleiro[1][i] = 1;
            return;
        }
        if(tabuleiro[1][i] == 1 && tabuleiro[2][i] == 1 && tabuleiro[0][i] == 0)
        {
            tabuleiro[0][i] = 1;
            return;        
        }
    }
    //Checa as diagonais
    if(tabuleiro[0][0] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][2] == 0)
    {
        tabuleiro[2][2] = 1;
        return;
    }
    if(tabuleiro[0][0] == 1 && tabuleiro[2][2] == 1 && tabuleiro[1][1] == 0)
    {
        tabuleiro[1][1] = 1;
        return;
    }
    if(tabuleiro[1][1] == 1 && tabuleiro[2][2] == 1 && tabuleiro[0][0] == 0)
    {
        tabuleiro[0][0] = 1;
        return;
    }
    if(tabuleiro[2][0] == 1 && tabuleiro[1][1] == 1 && tabuleiro[0][2] == 0)
    {
        tabuleiro[0][2] = 1;
        return;
    }
    if(tabuleiro[2][0] == 1 && tabuleiro[0][2] == 1 && tabuleiro[1][1] == 0)
    {
        tabuleiro[1][1] = 1;
        return;
    }
    if(tabuleiro[1][1] == 1 && tabuleiro[0][2] == 1 && tabuleiro[2][0] == 0)
    {
        tabuleiro[2][0] = 1;
        return;
    }           

    //2- Se der pra bloquear, bloqueie.
    for(int i = 0; i < tam; i++)//Checa horizontais e verticais.
    {
        if(tabuleiro[i][0] == 4 && tabuleiro[i][1] == 4 && tabuleiro[i][2] == 0)
        {
            tabuleiro[i][2] = 1;
            return;
        }
        if(tabuleiro[i][0] == 4 && tabuleiro[i][2] == 4 && tabuleiro[i][1] == 0)
        {
            tabuleiro[i][1] = 1;
            return;
        }
        if(tabuleiro[i][1] == 4 && tabuleiro[i][2] == 4 && tabuleiro[i][0] == 0)
        {
            tabuleiro[i][0] = 1;
            return;
        }
        if(tabuleiro[0][i] == 4 && tabuleiro[1][i] == 4 && tabuleiro[2][i] == 0)
        {
            tabuleiro[2][i] = 1;
            return;
        }
        if(tabuleiro[0][i] == 4 && tabuleiro[2][i] == 4 && tabuleiro[1][i] == 0)
        {
            tabuleiro[1][i] = 1;
            return;
        }
        if(tabuleiro[1][i] == 4 && tabuleiro[2][i] == 4 && tabuleiro[0][i] == 0)
        {
            tabuleiro[0][i] = 1;
            return;        
        }
    }
    //Checa as diagonais.
    if(tabuleiro[0][0] == 4 && tabuleiro[1][1] == 4 && tabuleiro[2][2] == 0)
    {
        tabuleiro[2][2] = 1;
        return;
    }
    if(tabuleiro[0][0] == 4 && tabuleiro[2][2] == 4 && tabuleiro[1][1] == 0)
    {
        tabuleiro[1][1] = 1;
        return;
    }
    if(tabuleiro[1][1] == 4 && tabuleiro[2][2] == 4 && tabuleiro[0][0] == 0)
    {
        tabuleiro[0][0] = 1;
        return;
    }
    if(tabuleiro[2][0] == 4 && tabuleiro[1][1] == 4 && tabuleiro[0][2] == 0)
    {
        tabuleiro[0][2] = 1;
        return;
    }
    if(tabuleiro[2][0] == 4 && tabuleiro[0][2] == 4 && tabuleiro[1][1] == 0)
    {
        tabuleiro[1][1] = 1;
        return;
    }
    if(tabuleiro[1][1] == 4 && tabuleiro[0][2] == 4 && tabuleiro[2][0] == 0)
    {
        tabuleiro[2][0] = 1;
        return;
    }        
    
    //3- Jogue em qualquer lugar ainda vazio.
    do
    {
        linhaR = rand() % tam;
        colunaR = rand() % tam;
        if(tabuleiro[linhaR][colunaR] == 0)
        {
            tabuleiro[linhaR][colunaR] = 1;
            return;
        }
        else
            continue;
    } while (loop == 0);
}

void VezJogador(int tabuleiro[][tam])
{
    int linha, coluna, loop = 1;

    system("clear");

    do
    {
        printf("!! S U A  V E Z !!\n");
        PrintTabuleiro(tabuleiro);

        printf("\n\nMin [ 1 ]\nMax [ 3 ]\nEm que linha jogará: ");
        scanf("%d", &linha);
        printf("\n\nMin [ 1 ]\nMax [ 3 ]\nEm que coluna jogará: ");
        scanf("%d", &coluna);

        if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3)
        {
            system("clear");
            printf("Por favor, digite uma coordenada válida. . .\n\n");
            continue;
        }

        linha--;
        coluna--;

        if(tabuleiro[linha][coluna] != 0)
        {
            system("clear");
            printf("Por favor, digite uma coordenada que ainda não tenha sido usada. . .\n\n");
            continue;
        }
        tabuleiro[linha][coluna] = 4;
        loop = 0;
    } while (loop == 1);
}

int Jogo()//Retorna 0 (Empate), 1 (Derrota) ou 2 (Vitória).
{
    int tabuleiro[tam][tam], vez;

    Reset(tabuleiro);

    srand(time(NULL));
    vez = rand() % 2;

    for(int jogada = 1; jogada < 9; jogada++)
    {
        if(vez == 0)
        {
            VezCompiuter(tabuleiro);
        }
        else
            VezJogador(tabuleiro);

        for(int i = 0; i < tam; i++)
        {
            if(somaLinha(tabuleiro, i) == 3)
            {
                system("clear");
                printf("-----------------Derrota pela linha: %d", i + 1);
                PrintTabuleiro(tabuleiro);
                getchar();getchar();
                return 1;
            }
            if(somaColuna(tabuleiro, i) == 3)
            {
                system("clear");
                printf("-----------------Derrota pela coluna: %d", i + 1);
                PrintTabuleiro(tabuleiro);
                getchar();getchar();
                return 1;
            }
            if(somaLinha(tabuleiro, i) == 12)
            {
                system("clear");
                printf("-----------------Vitória pela linha: %d", i + 1);
                PrintTabuleiro(tabuleiro);
                getchar();getchar();
                return 2;
            }
            if(somaColuna(tabuleiro, i) == 12)
            {
                system("clear");
                printf("-----------------Vitória pela coluna: %d", i + 1);
                PrintTabuleiro(tabuleiro);
                getchar();getchar();
                return 2;
            }
        }
        if(somaDiagonaDireita(tabuleiro) == 3)
        {
            system("clear");
            printf("-----------------Derrota pela Diagonal Direita.");
            PrintTabuleiro(tabuleiro);
            getchar();getchar();
            return 1;
        }
        if(somaDiagonalEsquerda(tabuleiro) == 3)
        {
            system("clear");
            printf("-----------------Derrota pela Diagonal Esquerda.");
            PrintTabuleiro(tabuleiro);
            getchar();getchar();
            return 1;
        }
        if(somaDiagonaDireita(tabuleiro) == 12)
        {
            system("clear");
            printf("-----------------Vitória pela Diagonal Direita.");
            PrintTabuleiro(tabuleiro);
            getchar();getchar();
            return 2;
        }
        if(somaDiagonalEsquerda(tabuleiro) == 12)
        {
            system("clear");
            printf("-----------------Vitória pela Diagonal Esquerda.");
            PrintTabuleiro(tabuleiro);
            getchar();getchar();
            return 2;
        }

        if(vez == 1)
            vez = 0;
        else
            vez = 1;
    }
    printf("\n\n\n-------------------------------Empate");
    PrintTabuleiro(tabuleiro);
    getchar();getchar();
    return 0;
}

int main()
{
    int vitorias = 0, derrotas = 0, empates = 0, nPartidas = 0, jogar = 1, resultado;

    do
    {
        system("clear");
        printf("Bem-vindo ao Lobby do Jogo da Velha!\n\n");
        if(nPartidas > 0)
        {
            printf("--------- Placar Atual --------\n\n");
            printf("-Vitórias: %d \n", vitorias);
            printf("-Derrótas: %d \n", derrotas);
            printf("-Empates:  %d \n", empates);
            printf("-Partidas: %d \n\n", nPartidas);
            printf("-------------------------------\n\n");
        }
        printf("O que você quer fazer?");
        printf("\n[ 0 ] = Sair do Jogo");
        printf("\n[ 1 ] = Jogar");
        printf("\nDigite sua escolha: ");
        scanf("%d", &jogar);

        if(jogar == 0)
            exit(0);
        else if(jogar > 1 || jogar < 0)
        {
            system("clear");
            printf("Por favor, digite uma opção válida. . .\n\n");
            continue;
        }

        resultado = Jogo();
        if(resultado == 0)
            empates++;
        else if(resultado == 1)
            derrotas++;
        else
            vitorias++;

        nPartidas++;
    } while (jogar >= 1 || jogar < 0);

    getchar();getchar();
    return(0);
}