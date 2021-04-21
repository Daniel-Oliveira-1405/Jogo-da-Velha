#include<stdio.h>
#include<stdlib.h>

#define x 1
#define o 2
#define vazio 0

// PROTÓTIPOS
int analiza();
void monta_jogo();
void zerar_matriz();

int jogo[3][3] = {
    0,0,0,
    0,0,0,
    0,0,0
};

// Função principal
int main()
{
    menu: int l, c;
    int qt_Rod, venc=0; // Quantidade de rodadas, vencedor
    zerar_matriz();
    
    // Então, pessoal! O vídeo de hoje foi esse. Espero que tenham
    // gostado. Não se esqueça de deixar seu like e se increver no canal
    // Para mais vídeos!

    int op; // MENU INICIAL
    printf("\tBEM-VINDO AO JOGO DA VELHA\n\n");
    printf("Escolha uma opcao:\n");
    printf("(1) Jogar\n");
    printf("(2) Sair\n");
    printf("Op: ");
    scanf("%d",&op);

    if(op==1){
        while(!venc){
            jgd1: system("cls"); // Biblioteca stdlib.h
            monta_jogo();
            printf("Vez do Jogador 1.\n");
            printf("Digite a linha e a coluna: ");
            scanf("%d %d",&l,&c);
            l-=1; c-=1;
            if(l<0 || l>2 || c<0 || c>2)
            {
                printf("Coordenada invalida! Digite de 1 a 3.\n");
                system("pause");
                goto jgd1;
            }
            if(jogo[l][c]==x || jogo[l][c]==o)
            {
                printf("Coordenada invalida! Lugar ocupado.\n");
                system("pause");
                goto jgd1;
            }
            jogo[l][c] = x;
            qt_Rod++;
            venc = analiza();
            if(venc!=0) break;
            if(venc==0 && qt_Rod==9) break;

            jgd2: system("cls");
            monta_jogo();
            printf("Vez do Jogador 2.\n");
            printf("Digite a linha e a coluna: ");
            scanf("%d %d",&l,&c);
            l-=1; c-=1;
            if(l>2 || l<0 || c>2 || c<0)
            {
                printf("Coordenada invalida! Digite de 1 a 3.\n");
                system("pause");
                goto jgd2;
            }
            if(jogo[l][c]==x || jogo[l][c]==o)
            {
                printf("Coordenada invalida! Lugar ocupado.\n");
                system("pause");
                goto jgd2;
            }
            jogo[l][c] = o;
            qt_Rod++;
            venc = analiza();
            if(venc!=0) break;
            if(venc==0 && qt_Rod==9) break;
        }
        system("cls");
        monta_jogo();
        if(venc==0) printf("VELHA.\n");
        else printf("Parabens, Jogador %d! Voce venceu!\n", venc);
        system("pause");
        system("cls"); // Limpar a tela
        goto menu;
    }
}

void zerar_matriz()
{
    int l, c;
    for(l=0; l<3; l++)
        for(c=0; c<3; c++)
            jogo[l][c] = 0;
}

void monta_jogo()
{
    int l, c;
    printf("  1 2 3\n");
    for(l=0; l<3; l++)
    {
        printf("%d ",l+1);
        for(c=0; c<3; c++)
        {
            if(jogo[l][c]==x) printf("X|");
            if(jogo[l][c]==o) printf("O|");
            if(jogo[l][c]==vazio)
            {
                if(l==2) printf(" |");
                else printf("_|");
            }
        }
        printf("\n");
    }
    printf("\b \n\n");
}

int analiza()
{
    // Linhas
    if(jogo[0][0]==x && jogo[0][1]==x && jogo[0][2]==x)
        return x; // Linha superior
    if(jogo[0][0]==o && jogo[0][1]==o && jogo[0][2]==o)
        return o;
    if(jogo[1][0]==x && jogo[1][1]==x && jogo[1][2]==x)
        return x; // Linha do meio
    if(jogo[1][0]==o && jogo[1][1]==o && jogo[1][2]==o)
        return o;
    if(jogo[2][0]==x && jogo[2][1]==x && jogo[2][2]==x)
        return x; // Linha inferior
    if(jogo[2][0]==o && jogo[2][1]==o && jogo[2][2]==o)
        return o;

    // Colunas
    if(jogo[0][0]==x && jogo[1][0]==x && jogo[2][0]==x)
        return x; // Coluna da esquerda
    if(jogo[0][0]==o && jogo[1][0]==o && jogo[2][0]==o)
        return o;
    if(jogo[0][1]==x && jogo[1][1]==x && jogo[2][1]==x)
        return x; // Coluna do meio
    if(jogo[0][1]==o && jogo[1][1]==o && jogo[2][1]==o)
        return o;
    if(jogo[0][2]==x && jogo[1][2]==x && jogo[2][2]==x)
        return x; // Coluna da direita
    if(jogo[0][2]==o && jogo[1][2]==o && jogo[2][2]==o)
        return o;

    // Diagonais
    if(jogo[0][0]==x && jogo[1][1]==x && jogo[2][2]==x)
        return x; // Diagonal esquerda-direita
    if(jogo[0][0]==o && jogo[1][1]==o && jogo[2][2]==o)
        return o;
    if(jogo[0][2]==x && jogo[1][1]==x && jogo[2][0]==x)
        return x; // Diagonal direita-esquerda
    if(jogo[0][2]==o && jogo[1][1]==o && jogo[2][0]==o)
        return o;
    return 0;
}
