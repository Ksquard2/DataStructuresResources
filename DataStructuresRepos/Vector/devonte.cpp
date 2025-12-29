
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

/* -------------------- CONSTANTS -------------------- */

const int MAX_PLAYERS = 7;
const int MIN_PLAYERS = 3;

const int ROWS_MAX = 10;
const int COLS_MAX = 15;

const int ROWS_MIN = 4;
const int COLS_MIN = 4;

const char PIECE_ORDER[MAX_PLAYERS] = { 'z', 'y', 'x', 'w', 'v', 'u', 't' };

const int WIN_SEQUENCE = 3;
const char EMPTY_CELL = ' ';
const char BOARD_INIT_CHAR = '.';

/* -------------------- DATA STRUCTURES -------------------- */

struct Player
{
    string firstName;
    string lastName;
    string fullName;
    char symbol;
    int wins;
    int losses;
    int draws;
};

/* -------------------- FUNCTION PROTOTYPES -------------------- */

void initializePlayers(Player players[], int playerCount);

bool isValidName(const string & name);

int requestIntInRange(const string & prompt, int minVal, int maxVal);

void initBoard(char board[ROWS_MAX][COLS_MAX], int rows, int cols);

void drawBoard(const char board[ROWS_MAX][COLS_MAX], int rows, int cols);

bool parseMove(const string & input, int rows, int cols, int & outRow, int & outCol);

bool playerMove(Player & player, char board[ROWS_MAX][COLS_MAX], int rows, int cols);

bool findAllWinsAndMark(char board[ROWS_MAX][COLS_MAX], int rows, int cols, char symbol);

void uppercaseWinningCells(char board[ROWS_MAX][COLS_MAX], int rows, int cols, bool marks[ROWS_MAX][COLS_MAX]);

void updateStatsAfterWin(Player players[], int playerCount, int winnerIndex);

void updateStatsAfterDraw(Player players[], int playerCount);

void displayStatistics(Player players[], int playerCount, int totalGames);

bool askYesNo(const string & prompt);

string toProperName(const string & s);

int getPlayerIndexBySymbol(char symbol, int playerCount);

/* -------------------- MAIN PROGRAM -------------------- */

int main()
{
    cout << "Extended Tic-Tac-Toe Game (3..7 players)\n\n";

    
    int playerCount = requestIntInRange("Enter number of players (3-7): ", MIN_PLAYERS, MAX_PLAYERS);

    Player players[MAX_PLAYERS];

    for (int i = 0; i < playerCount; ++i)
    {
        players[i].wins = 0;
        players[i].losses = 0;
        players[i].draws = 0;
        players[i].symbol = PIECE_ORDER[i];
    }

  
    cin.ignore(1000, '\n');
    initializePlayers(players, playerCount);

   
    cout << "\nPlease enter the dimension of the board.\n\n";
    int rows = requestIntInRange("Enter the number of rows -> ", ROWS_MIN, ROWS_MAX);

    int cols = requestIntInRange("\nEnter the number of columns -> ", COLS_MIN, COLS_MAX);

    int starterIndex = 0; 
    int totalGames = 0;
    bool continuePlaying = true;

    
    Player* playerOrder[MAX_PLAYERS];
    for (int i = 0; i < playerCount; ++i)
    {
        playerOrder[i] = &players[i];
    }

    
    for (int i = 0; i < playerCount; ++i)
    {
        if (players[i].symbol == 'p')
        {
            starterIndex = i;
            break;
        }
    }

    while (continuePlaying)
    {
        char board[ROWS_MAX][COLS_MAX];
        initBoard(board, rows, cols);

        
        Player* tempPlayerPtrs[MAX_PLAYERS];
        for (int i = 0; i < playerCount; ++i)
        {
            tempPlayerPtrs[i] = playerOrder[(starterIndex + i) % playerCount];
        }
        for (int i = 0; i < playerCount; ++i)
        {
            playerOrder[i] = tempPlayerPtrs[i];
        }
        int gameStarterIndexInOrder = 0;

        cout << "\n";
        drawBoard(board, rows, cols);

        int currentIndexInOrder = gameStarterIndexInOrder;
        bool winnerFound = false;
        int winnerIndexInOrder = -1;

        int movesAllowed = rows * cols;
        int movesMade = 0;

        while (movesMade < movesAllowed && !winnerFound)
        {
            Player& currentPlayer = *playerOrder[currentIndexInOrder];

            bool valid = playerMove(currentPlayer, board, rows, cols);

            if (valid)
            {
                ++movesMade;

                bool foundAny = findAllWinsAndMark(board, rows, cols, currentPlayer.symbol);

                drawBoard(board, rows, cols);

                if (foundAny)
                {
                    cout << currentPlayer.firstName << " wins!\n";
                    winnerFound = true;
                    winnerIndexInOrder = currentIndexInOrder;
                }
                else
                {
                    currentIndexInOrder = (currentIndexInOrder + 1) % playerCount;
                }
            }
        }

        int winnerIndex = -1;

        if (winnerFound)
        {
            Player& winnerPlayer = *playerOrder[winnerIndexInOrder];
            for (int i = 0; i < playerCount; ++i)
            {
                if (&players[i] == &winnerPlayer)
                {
                    winnerIndex = i;
                    break;
                }
            }

            updateStatsAfterWin(players, playerCount, winnerIndex);

            int winnerPieceIndex = getPlayerIndexBySymbol(players[winnerIndex].symbol, playerCount);
            int nextStarterPieceIndex = (winnerPieceIndex + 1) % playerCount;
            char nextStarterSymbol = PIECE_ORDER[nextStarterPieceIndex];

            int newStarterIndex = -1;
            for (int i = 0; i < playerCount; ++i)
            {
                if (players[i].symbol == nextStarterSymbol)
                {
                    newStarterIndex = i;
                    break;
                }
            }
            starterIndex = newStarterIndex;
        }
        else
        {
            cout << "It's a draw!\n";
            updateStatsAfterDraw(players, playerCount);

            char previousStarterSymbol = playerOrder[0]->symbol;
            
            int previousStarterPieceIndex = getPlayerIndexBySymbol(previousStarterSymbol, playerCount);
            
            int nextStarterPieceIndex = (previousStarterPieceIndex + 1) % playerCount;
            
            char nextStarterSymbol = PIECE_ORDER[nextStarterPieceIndex];

            int newStarterIndex = -1;
            for (int i = 0; i < playerCount; ++i)
            {
                if (players[i].symbol == nextStarterSymbol)
                {
                    newStarterIndex = i;
                    break;
                }
            }
            starterIndex = newStarterIndex;
        }

        ++totalGames;

        displayStatistics(players, playerCount, totalGames);

        bool playNext = askYesNo("\nPlay another game? (Y/N): ");

        if (playNext)
        {
            cout << "\nPlease enter the dimension of the board.\n\n";
            rows = requestIntInRange("Enter the number of rows -> ", ROWS_MIN, ROWS_MAX);
            cols = requestIntInRange("\nEnter the number of columns -> ", COLS_MIN, COLS_MAX);
        }

        continuePlaying = playNext;
    }

    cout << "Thanks for playing!\n";
    return 0;
}

/* -------------------- FUNCTION DEFINITIONS -------------------- */

void initializePlayers(Player players[], int playerCount)
{
    string fullLine;

    for (int i = 0; i < playerCount; ++i)
    {
        bool done = false;

        while (!done)
        {
            cout << "Enter Player " << (i + 1) << " full name (First Last): ";
            getline(cin, fullLine);

          
            size_t start = fullLine.find_first_not_of(' ');
            if (start == string::npos)
            {
                cout << "\nInvalid format. Enter first and last name separated by space.\n\n";
                continue;
            }

            string trimmedLine = fullLine.substr(start);

            
            size_t firstSpacePos = trimmedLine.find_first_of(' ');
            if (firstSpacePos == string::npos)
            {
                cout << "\nInvalid format. Enter first and last name separated by space.\n\n";
                continue;
            }

            string first = trimmedLine.substr(0, firstSpacePos);

         
            size_t lastNameStart = trimmedLine.find_first_not_of(' ', firstSpacePos);
            if (lastNameStart == string::npos)
            {
                cout << "\nInvalid format. No last name found.\n\n";
                continue;
            }

            string last = trimmedLine.substr(lastNameStart);

          
            size_t end = last.find_last_not_of(' ');
            if (end != string::npos)
            {
                last = last.substr(0, end + 1);
            }

            if (first.empty() || last.empty())
            {
                cout << "\nInvalid names. Try again.\n\n";
                continue;
            }

            if (!isValidName(first) || !isValidName(last))
            {
                cout << "\nNames must contain alphabetic characters only.\n\n";
                continue;
            }

          
            players[i].firstName = toProperName(first);
            players[i].lastName = toProperName(last);
            players[i].fullName = players[i].firstName + " " + players[i].lastName;
            done = true;
        }
    }
}


string toProperName(const string & s)
{
    string result = s;
    for (size_t i = 0; i < result.size(); ++i)
        result[i] = tolower(static_cast<unsigned char>(result[i]));

    if (!result.empty())
        result[0] = toupper(static_cast<unsigned char>(result[0]));

    return result;
}

bool isValidName(const string & name)
{
    if (name.empty())
        return false;

    for (char c : name)
    {
        if (!isalpha(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

int requestIntInRange(const string & prompt, int minVal, int maxVal)
{
    int value = 0;
    bool valid = false;
    while (!valid)
    {
        cout << prompt;
        if (!(cin >> value))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input. Please enter an integer.\n\n"; 
            continue;
        }
        cin.ignore(1000, '\n');

        if (value < minVal || value > maxVal)
        {
            cout << "\nValue must be between " << minVal << " and " << maxVal << ".\n\n";  
            continue;
        }

        valid = true;
    }

    return value;
}


void initBoard(char board[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            board[r][c] = BOARD_INIT_CHAR;
}

void drawBoard(const char board[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    const int CONTENT_WIDTH = 3;
    cout << " ";
    for (int c = 0; c < cols; ++c)
    {
        cout << setw(CONTENT_WIDTH) << (c + 1) << setw(1) << " ";
    }
    cout << "\n";

    string dashes(CONTENT_WIDTH, '-');
    string sepLine = "";
    for (int c = 0; c < cols; ++c)
    {
        sepLine += dashes;
        sepLine += " ";
    }
    sepLine = sepLine.substr(0, sepLine.length() - 1);
    cout << " " << sepLine << "\n";

    for (int r = 0; r < rows; ++r)
    {
        char rowLetter = static_cast<char>('A' + r);
        cout << rowLetter;
        for (int c = 0; c < cols; ++c)
        {
            char displayChar = (board[r][c] == BOARD_INIT_CHAR) ? EMPTY_CELL : board[r][c];
            cout << "|" << " " << displayChar << " ";
        }
        cout << "|" << rowLetter << "\n";
        cout << " " << sepLine << "\n";
    }

    cout << " ";
    for (int c = 0; c < cols; ++c)
    {
        cout << setw(CONTENT_WIDTH) << (c + 1) << " ";
    }
    cout << "\n";
}

bool parseMove(const string & input, int rows, int cols, int & outRow, int & outCol)
{
    string trimmedInput = input;
    trimmedInput.erase(0, trimmedInput.find_first_not_of(' '));
    trimmedInput.erase(trimmedInput.find_last_not_of(' ') + 1);

    if (trimmedInput.empty()) return false;

    char letter = trimmedInput[0];
    if (!isalpha(static_cast<unsigned char>(letter))) return false;

    int rowIndex = toupper(static_cast<unsigned char>(letter)) - 'A';
    if (rowIndex < 0 || rowIndex >= rows) return false;

    string colStr = trimmedInput.substr(1);
    if (colStr.empty()) return false;

    int colNum = 0;
    for (char ch : colStr)
    {
        if (!isdigit(static_cast<unsigned char>(ch))) return false;
        colNum = colNum * 10 + (ch - '0');
    }

    if (colNum < 1 || colNum > cols) return false;

    outRow = rowIndex;
    outCol = colNum - 1;

    return true;
}

bool playerMove(Player & player, char board[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    cout << "\n" << player.firstName << ", enter your move (e.g. D5): ";
    string input;
    getline(cin, input);

    int r, c;
    if (!parseMove(input, rows, cols, r, c))
    {
        cout << "\nInvalid move format or out of range. Use RowLetter + ColumnNumber (e.g. A1, J15).\n\n";
        return false;
    }

    if (board[r][c] != BOARD_INIT_CHAR)
    {
        cout << "\nCell " << static_cast<char>('A' + r) << (c + 1)
             << " already occupied. Choose another cell.\n\n";
        return false;
    }

    board[r][c] = player.symbol;
    return true;
}


bool findAllWinsAndMark(char board[ROWS_MAX][COLS_MAX], int rows, int cols, char symbol)
{
    bool mark[ROWS_MAX][COLS_MAX] = { {false} };
    bool foundAny = false;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c + (WIN_SEQUENCE - 1) < cols; ++c)
        {
            bool ok = true;
            for (int k = 0; k < WIN_SEQUENCE; ++k)
            {
                if (tolower(static_cast<unsigned char>(board[r][c + k])) != symbol)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                foundAny = true;
                for (int k = 0; k < WIN_SEQUENCE; ++k) mark[r][c + k] = true;
            }
        }
    }

    for (int c = 0; c < cols; ++c)
    {
        for (int r = 0; r + (WIN_SEQUENCE - 1) < rows; ++r)
        {
            bool ok = true;
            for (int k = 0; k < WIN_SEQUENCE; ++k)
            {
                if (tolower(static_cast<unsigned char>(board[r + k][c])) != symbol)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                foundAny = true;
                for (int k = 0; k < WIN_SEQUENCE; ++k) mark[r + k][c] = true;
            }
        }
    }

    for (int r = 0; r + (WIN_SEQUENCE - 1) < rows; ++r)
    {
        for (int c = 0; c + (WIN_SEQUENCE - 1) < cols; ++c)
        {
            bool ok = true;
            for (int k = 0; k < WIN_SEQUENCE; ++k)
            {
                if (tolower(static_cast<unsigned char>(board[r + k][c + k])) != symbol)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                foundAny = true;
                for (int k = 0; k < WIN_SEQUENCE; ++k) mark[r + k][c + k] = true;
            }
        }
    }

    for (int r = WIN_SEQUENCE - 1; r < rows; ++r)
    {
        for (int c = 0; c + (WIN_SEQUENCE - 1) < cols; ++c)
        {
            bool ok = true;
            for (int k = 0; k < WIN_SEQUENCE; ++k)
            {
                if (tolower(static_cast<unsigned char>(board[r - k][c + k])) != symbol)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                foundAny = true;
                for (int k = 0; k < WIN_SEQUENCE; ++k) mark[r - k][c + k] = true;
            }
        }
    }

    if (foundAny) uppercaseWinningCells(board, rows, cols, mark);

    return foundAny;
}

void uppercaseWinningCells(char board[ROWS_MAX][COLS_MAX],
    int rows, int cols,
    bool marks[ROWS_MAX][COLS_MAX])
{
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (marks[r][c])
                board[r][c] = static_cast<char>(toupper(static_cast<unsigned char>(board[r][c])));
}

void updateStatsAfterDraw(Player players[], int playerCount)
{
    for (int i = 0; i < playerCount; ++i)
        players[i].draws++;
}

void updateStatsAfterWin( Player players[ ], int playerCount, int winnerIndex )
{
    for ( int i = 0 ; i < playerCount ; ++i )
    {
        if ( i == winnerIndex )
        {
            players[i].wins ++ ;
        }
        else
        {
            players[i].losses ++ ;
        }
    }
}

void displayStatistics( Player players[ ], int playerCount, int totalGames )
{
    
    const int NAME_WIDTH = 15;
    const int NUM_WIDTH = 5;

    
    cout << "\nTotal game played = " << totalGames << "\n\n";

  
    string stat_dashes( NUM_WIDTH, '-' );

    auto print_border = [&]()
    {
       
        cout << setw( NAME_WIDTH + 1 ) << right << "";

      
        cout << "|" << stat_dashes << "|";
        cout << stat_dashes << "|";
        cout << stat_dashes << "|\n";
    };

 
    print_border();


    cout << setw( NAME_WIDTH + 1 ) << right << "" << "|"
             << setw( NUM_WIDTH ) << "WIN" << "|"
             << setw( NUM_WIDTH ) << "LOSS" << "|"
             << setw( NUM_WIDTH ) << "DRAW" << "|\n";

  
    print_border();

    
    for ( int i = 0 ; i < playerCount ; ++i )
    {
      
        cout << setw( NAME_WIDTH + 1 ) << right << players[i].fullName << "|"
                 << setw( NUM_WIDTH ) << right << players[i].wins << "|"
                 << setw( NUM_WIDTH ) << right << players[i].losses << "|"
                 << setw( NUM_WIDTH ) << right << players[i].draws << "|\n";
    }


    print_border();
}

bool askYesNo(const string & prompt)
{
    string resp;
    bool valid = false;
    bool answer = false;

    while (!valid)
    {
        cout << prompt;
        getline(cin, resp);

        size_t start = resp.find_first_not_of(' ');
        if (start == string::npos)
        {
            continue;
        }

        char ch = tolower(static_cast<unsigned char>(resp[start]));

        switch (ch)
        {
            case 'y':
                answer = true;
                valid = true;
                break;

            case 'n':
                answer = false;
                valid = true;
                break;

            default:
                cout << "Invalid input. Enter Y or N.\n";
                break;
        }
    }

    return answer;
}


int getPlayerIndexBySymbol( char symbol, int playerCount )
{
    for ( int i = 0 ; i < playerCount ; ++i )
    {
        if ( PIECE_ORDER[i] == symbol )
        {
            return i;
        }
    }
    return -1;
}