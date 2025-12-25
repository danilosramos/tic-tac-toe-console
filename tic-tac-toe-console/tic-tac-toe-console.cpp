#include <iostream>
#include <ctime>
#include <limits> // Para validação do cin

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    // Inicialização direta e limpa
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    // Semente aleatória deve ser chamada apenas UMA vez no início
    srand(time(0));

    drawBoard(spaces);

    while (running)
    {
        // --- TURNO DO JOGADOR ---
        playerMove(spaces, player);
        drawBoard(spaces);
        
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        if (checkTie(spaces))
        {
            running = false;
            break;
        }

        // --- TURNO DO COMPUTADOR ---
        computerMove(spaces, computer);
        drawBoard(spaces); // Mostrar o movimento do computador

        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }

    cout << "Obrigado por jogar!" << endl;
    return 0;
}

void drawBoard(char *spaces)
{
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void playerMove(char *spaces, char player)
{
    int number;
    while (true)
    {
        cout << "Escolha uma posicao (1-9): ";
        cin >> number;

        // Verifica se a entrada falhou (não é numero)
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida! Digite apenas numeros.\n";
            continue;
        }

        number--; // Ajusta para índice 0-8

        if (number >= 0 && number < 9 && spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
        else
        {
            cout << "Posicao invalida ou ocupada!\n";
        }
    }
}

void computerMove(char *spaces, char computer)
{
    int number;
    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    // Matriz de combinações vencedoras (linhas, colunas, diagonais)
    [cite_start]// [cite: 1] - Lógica padrão de vitória em Jogo da Velha (Tic-Tac-Toe)
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Linhas
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Colunas
        {0, 4, 8}, {2, 4, 6}             // Diagonais
    };

    for (int i = 0; i < 8; i++)
    {
        int a = winPatterns[i][0];
        int b = winPatterns[i][1];
        int c = winPatterns[i][2];

        // Verifica se as três posições são iguais e não estão vazias
        if (spaces[a] != ' ' && spaces[a] == spaces[b] && spaces[b] == spaces[c])
        {
            spaces[a] == player ? cout << "VOCE VENCEU!\n" : cout << "VOCE PERDEU!\n";
            return true;
        }
    }
    return false;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        // Se houver pelo menos um espaço vazio, não é empate ainda
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "EMPATE!\n";
    return true;
}