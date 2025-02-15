#include <iostream>
#include <string>

using namespace std;

/*----------------------------------------------------------------------
    Capitalizes an individual position. Used in function below 
---------------------------------------------------------------------*/
void capitalize(string& str);
/*----------------------------------------------------------------------
    Capitalizing multiple win connditions if they are found
---------------------------------------------------------------------*/
void capitalizeWinConditions(string **pString, int row, int col, int rows, int cols);

/*----------------------------------------------------------------------
    Ensures that even if final placement for a win is in the final column they are still set to equal each other
---------------------------------------------------------------------*/
string SpaceReplace(string s)
{
   if (s[s.length()-1] != ' ')
   {
    s.erase(s.length()-1);
 }
  return s;
}
/*----------------------------------------------------------------------
  Capitalizes the First and last name of each player
---------------------------------------------------------------------*/
string Capital(string v)
{
   v[0]=toupper(v[0]);
 
for(int i=1;i < v.length();i++)
{
    v[i]=tolower(v[i]);
}
for(int i=1;i < v.length();i++)
{
  if(v[i-1] == ' ')
  {
      v[i]=toupper(v[i]);
  }
}
  return v;
}

/*----------------------------------------------------------------------
  shortens the name for the display durng the game
---------------------------------------------------------------------*/
string Shorten(string s)
{
string v = "";
for(int i = 0;i < s.length();i++){
  if(s[i] != ' ')
  {
      v = v+s[i];
  }
  else break;
  }
  
  return Capital(v);
}


/*----------------------------------------------------------------------
  turns the letter inputted during the placement input phase inton an integer to be placed on to the board
---------------------------------------------------------------------*/
int AlphToInt(string g)
{
    if (g[0] == 'A' || g[0] == 'a')
    {
        return 2;
    }
    if (g[0] == 'B' || g[0] == 'b')
    {
        return 4;
    }
    if (g[0] == 'C' || g[0] == 'c')
    {
        return 6;
    }
    if (g[0] == 'D' || g[0] == 'd')
    {
        return 8;
    }
    if (g[0] == 'E' || g[0] == 'e')
    {
        return 10;
    }
    if (g[0] == 'F' || g[0] == 'f')
    {
        return 12;
    }
    if (g[0] == 'G' || g[0] == 'g')
    {
        return 14;
    }
    if (g[0] == 'H' || g[0] == 'h')
    {
        return 16;
    }
    if (g[0] == 'I' || g[0] == 'i')
    {
        return 18;
    }
    if (g[0] == 'J' || g[0] == 'j')
    {
        return 20;
    }
    if (g[0] == 'K' || g[0] == 'k')
    {
        return 22;
    }
    if (g[0] == 'L' || g[0] == 'l')
    {
        return 24;
    }
    else return 300;
}
/*----------------------------------------------------------------------
  prints the board
---------------------------------------------------------------------*/
void print2DArray(string** array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j];
        }
        cout << 
          endl;
    }
}
/*----------------------------------------------------------------------
  determines weither a game was a draw
---------------------------------------------------------------------*/
bool FindDraw(string** array, int rows, int cols)
{
  for (int i = 0; i < (rows * 2) + 3; i++)
    {
        for (int j = 0; j < cols + 2; j++)
        {
          if (i > 1 && i < rows * 2 + 1 
            && i % 2 == 0 && j > 0 
            && j < cols 
            && array[i][j] == "|   ")
          {
           return false;
          }
          if (i > 1 && i < rows * 2 + 1 
            && i % 2 == 0 
            && j > 0 
            && j == cols 
            && array[i][j] == "|   |")
          {
           return false;
          }
        }
    }
  return true;
}
/*----------------------------------------------------------------------
  Changes the second half of the placement input into anenterger to tp be placed on the board
---------------------------------------------------------------------*/
int sti(string s)
{
 s.erase(0,1);
 if(s ==  "1")
 {
     return 1;
 }
 if(s ==  "2")
 {
     return 2;
 }
 if(s ==  "3")
 {
     return 3;
 }
 if(s ==  "4")
 {
    return 4;
 }
 if(s ==  "5")
 {
    return 5;
 }
 if(s ==  "6")
 {
    return 6;
 }
 if(s ==  "5")
 {
    return 5;
 }
 if(s ==  "6")
 {
    return 6;
 }
 if(s ==  "7")
 {
    return 7;
 }
 if(s ==  "8")
 {
    return 8;
 }
 if(s ==  "9")
 {
    return 9;
 }
 if(s ==  "10")
 {
    return 10;
 }
 if(s ==  "11")
 {
    return 11;
 }
 if(s ==  "12")
 {
    return 12;
 }
 if(s ==  "13")
 {
    return 13;
 }
 if(s ==  "14")
 {
    return 14;
 }
 else 
   return 9000;
}

int main()
{
    int NumPlayers;
    int len;
    int wid;
    int turnCounter = 2;
    int tempCounter = turnCounter;
    string a1, b1, c1, d1, e1, f1, g1;
    int WinCheck;
    int NumGames = 0;
    int wins[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int loss[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int draw[7] = { 0, 0, 0, 0, 0, 0, 0 };
    string n = "C";
    cout << "How long would you like the board to be? ";
    cin >> len;
    cin.ignore();
    cout << "How wide would you like the board to be? ";
    cin >> wid;
    cin.ignore();
    cout << "How many players are playing? ";
    cin >> NumPlayers;
    cin.ignore();
    while(wid > 12 || len > 14 || NumPlayers > 7 || len < 3 || wid < 3)
    {
    cout << "Invalid Perimeters"<<endl;
    cout << "How long would you like the board to be? ";
    cin >> len;
    cin.ignore();
    cout << "How wide would you like the board to be? ";
    cin >> wid;
    cout << "How many players are playing? ";
    cin >> NumPlayers;
    cin.ignore();
    }

    string Players[NumPlayers];
    string CapPlayers[NumPlayers];
    string ShortPlayers[NumPlayers];
    for(int k = 0;k < NumPlayers;k++)
    {
        cout << "What is the name of player "<<k+1<<"? ";
        getline(cin, Players[k]);
    }

    for (int i = 0; i < NumPlayers; i++)
    {
        CapPlayers[i] = Capital(Players[i]);
        ShortPlayers[i] = Shorten(Players[i]);
    }
    int rows1 = (len * 2) + 3;
    int cols1 = wid + 2;
    string** Board = new string * [rows1];
    for (int i = 0; i < rows1; i++)
    {
        Board[i] = new string[cols1];
    }
  string resBoard[(NumPlayers*2)+3][4];
  int w = 3;
  int l = 3;
  int dr = 3;
  int k = 3;
    for (int i = 0; i < (len * 2) + 3; i++)
    {
        for (int j = 0; j < wid + 2; j++)
        {
            if ((i == 0 || i == (len * 2) + 2) && j == 1)
            {
                Board[i][j] = "    " + to_string(j) + "  ";
            }

            else if ((i == 0 || i == (len * 2) + 2) && j > 0 && j < wid + 1)
            {
    
                if (j < 10)
                {
                    Board[i][j] = " " + to_string(j) + "  ";
                }
                else  Board[i][j] = " " + to_string(j) + " ";
            }
            if (i % 2 == 1 && (j == 0 || j == wid + 1))
            {
                Board[i][j] = " ";
            }
            else if (i % 2 == 1 && j == 1)
            {
                Board[i][j] = "  --- ";
            }
            else if (i % 2 == 1 && j != 1 && j != wid + 1)
            {
                Board[i][j] = "--- ";
            }
            if (j == 0)
            {
                if (i == 2)
                {
                    Board[i][j] = "A ";
                }
                if (i == 4 && len > 1)
                {
                    Board[i][j] = "B ";
                }
                if (i == 6 && len > 2)
                {
                    Board[i][j] = "C ";
                }
                if (i == 8 && len > 3)
                {
                    Board[i][j] = "D ";
                }
                if (i == 10 && len > 4)
                {
                    Board[i][j] = "E ";
                }
                if (i == 12 && len > 5)
                {
                    Board[i][j] = "F ";
                }
                if (i == 14 && len > 6)
                {
                    Board[i][j] = "G ";
                }
                if (i == 16 && len > 7)
                {
                    Board[i][j] = "H ";
                }
                if (i == 18 && len > 8)
                {
                    Board[i][j] = "I ";
                }
                if (i == 20 && len > 9)
                {
                    Board[i][j] = "J ";
                }
                if (i == 22 && len > 10)
                {
                    Board[i][j] = "K ";
                }
                if (i == 24 && len > 11)
                {
                    Board[i][j] = "L ";
                }
                if (i == 26 && len > 12)
                {
                    Board[i][j] = "M ";
                }
                if (i == 28 && len > 13)
                {
                    Board[i][j] = "N ";
                }
            }
            if (j == wid + 1)
            {
                if (i == 2)
                {
                    Board[i][j] = " A";
                }
                if (i == 4 && len > 1)
                {
                    Board[i][j] = " B";
                }
                if (i == 6 && len > 2)
                {
                    Board[i][j] = " C";
                }
                if (i == 8 && len > 3)
                {
                    Board[i][j] = " D";
                }
                if (i == 10 && len > 4)
                {
                    Board[i][j] = " E";
                }
                if (i == 12 && len > 5)
                {
                    Board[i][j] = " F";
                }
                if (i == 14 && len > 6)
                {
                    Board[i][j] = " G";
                }
                if (i == 16 && len > 7)
                {
                    Board[i][j] = " H";
                }
                if (i == 18 && len > 8)
                {
                    Board[i][j] = " I";
                }
                if (i == 20 && len > 9)
                {
                    Board[i][j] = " J";
                }
                if (i == 22 && len > 10)
                {
                    Board[i][j] = " K";
                }
                if (i == 24 && len > 11)
                {
                    Board[i][j] = " L";
                }
                if (i == 26 && len > 12)
                {
                    Board[i][j] = " M";
                }
                if (i == 28 && len > 13)
                {
                    Board[i][j] = " N";
                }
            }

            if (i > 1 && i < len * 2 + 1 && i % 2 == 0 && j > 0 && j < wid)
            {
                Board[i][j] = "|   ";
            }
            if (i > 1 && i < len * 2 + 1 && i % 2 == 0 && j > 0 && j == wid)
            {
                Board[i][j] = "|   |";
            }
        }
    }
    int rows = (len * 2) + 3;
    int cols = wid + 2;
    string** temp = new string * [rows];
    for (int i = 0; i < rows; i++)
    {
        temp[i] = new string[cols];
    }

    for (int x = 0; x < (len * 2) + 3; x++)
    {
        for (int r = 0; r < wid + 2; r++)
        {
            temp[x][r] = Board[x][r];
        }
    }
    print2DArray(Board, (len * 2) + 3, wid + 2);

  
    while (n != "Q"||n != "q")
    {
      if(FindDraw(Board, len, wid))
      {
        for(int k = 0;k < NumPlayers;k++)
        {
           draw[k]++;
        }
        for(int i = 0;i < (NumPlayers*2)+3;i++)
        {
          for(int j = 0; j < 4;j++)
          {
              if(i%2 == 0 && j < 3)
              {
                  resBoard[i][j] = " ------ ";
              }
              if(j == 3 && i > 2 && i%2 == 1)
              {
                  resBoard[i][j] = Capital(Players[i-k]);
                  k++;
              }
             else if(i == 1 && j == 0)
             {
                  resBoard[i][j] = "|  WINS|";
             }
             else if(i == 1 && j == 1)
             {
                  resBoard[i][j] = "|  LOSS|";
             }
             else if(i == 1 && j == 2)
             {
                  resBoard[i][j] = "|  DRAW|";
             }
             else if(i%2 == 1 && j == 0)
             {
                  resBoard[i][j] = "|     "+to_string(wins[i-w])+"|";
                  w++;
             }
             else if(i%2 == 1 && j == 1)
             {
                  resBoard[i][j] = "|     "+to_string(loss[i-l])+"|";
                  l++;
             }
             else if(i%2 == 1 && j == 2)
             {
                  resBoard[i][j] = "|     "+to_string(draw[i-dr])+"|";
                  dr++;
             }
          }
       
        }
        for(int x = 0;x < (NumPlayers*2)+3;x++)
        {
            for(int y = 0;y < 4;y++)
            {
                cout<<resBoard[x][y];
            }
            cout<<endl;
        }
        
        turnCounter = tempCounter;
        tempCounter++;
        NumGames++;
        cout << "The number of games played is " << NumGames << endl;
        cout << "Press C to continue and press Q to quit" << endl;
        cin >> n;
        Board = temp;
        print2DArray(Board, (len * 2) + 3, wid + 2);
        }

  if (turnCounter % NumPlayers == 0)
  {
  if (NumPlayers == 2)
  {
   cout << "What is your placement " <<ShortPlayers[1] << "? ";
   cin >> b1;
   while(sti(b1) > wid || AlphToInt(b1)/2 > len || (Board[AlphToInt(b1)][sti(b1)] !=  "|   " && Board[AlphToInt(b1)][sti(b1)] !=  "|   |"))
   {
   cout << "Invalid Input Try Again" << endl;
   cout << "What is your placement " << ShortPlayers[1] << "? ";
   cin >> b1;
   }

      if (sti(b1) == wid)
      {
          Board[AlphToInt(b1)][sti(b1)] = "| b |";
      }
      else Board[AlphToInt(b1)][sti(b1)] = "| b ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 1;
            }
 if (NumPlayers == 3)
 {
   cout << "What is your placement " << ShortPlayers[2] << "? ";
   cin >> c1;
   while(sti(c1) > wid || 
     AlphToInt(c1)/2 > len || 
     (Board[AlphToInt(c1)][sti(c1)] !=  "|   " && Board[AlphToInt(c1)][sti(c1)] !=  "|   |"))
  {
   cout << "Invalid Input Try Again" << endl;
   cout << "What is your placement " << ShortPlayers[2] << "? ";
   cin >> c1;
  }
      if (sti(c1) == wid)
      {
          Board[AlphToInt(c1)][sti(c1)] = "| c |";
      }
      else Board[AlphToInt(c1)][sti(c1)] = "| c ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 2;
 }
 if (NumPlayers == 4)
 {
   cout << "What is your placement " << ShortPlayers[3] << "? ";
   cin >> d1;
   while(sti(d1) > wid || 
     AlphToInt(d1)/2 > len || 
     (Board[AlphToInt(d1)][sti(d1)] !=  "|   " && Board[AlphToInt(d1)][sti(d1)] !=  "|   |"))
   {
       cout << "Invalid Input Try Again" << endl;
       cout << "What is your placement " << ShortPlayers[3] << "? ";
       cin >> d1;
   }
      if (sti(d1) == wid)
      {
          Board[AlphToInt(d1)][sti(d1)] = "| d |";
      }
      else Board[AlphToInt(d1)][sti(d1)] = "| d ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 3;
  }
 if (NumPlayers == 5)
 {
   cout << "What is your placement " << ShortPlayers[4] << "? ";
   cin >> e1;
   while(sti(e1) > wid || 
     AlphToInt(e1)/2 > len || 
     (Board[AlphToInt(d1)][sti(e1)] !=  "|   " && Board[AlphToInt(e1)][sti(e1)] !=  "|   |"))
   {
       cout << "Invalid Input Try Again" << endl;
       cout << "What is your placement " << ShortPlayers[4] << "? ";
       cin >> e1;
   }
      if (sti(e1) == wid)
      {
          Board[AlphToInt(e1)][sti(e1)] = "| e |";
      }
      else Board[AlphToInt(e1)][sti(e1)] = "| e ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 4;
  }
  if (NumPlayers == 6)
  {
   cout << "What is your placement " << ShortPlayers[5] << "? ";
   cin >> f1;
   while(sti(f1) > wid || 
     AlphToInt(f1)/2 > len || 
     (Board[AlphToInt(f1)][sti(f1)] !=  "|   " && Board[AlphToInt(f1)][sti(f1)] !=  "|   |"))
   {
       cout << "Invalid Input Try Again" << endl;
       cout << "What is your placement " << ShortPlayers[5] << "? ";
       cin >> f1;
   }
      if (sti(f1) == wid)
      {
          Board[AlphToInt(f1)][sti(f1)] = "| f |";
      }
      else Board[AlphToInt(f1)][sti(f1)] = "| f ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 5;
  }
  if (NumPlayers == 7)
  {
   cout << "What is your placement " << ShortPlayers[6] << "? ";
   cin >> g1;
   while(sti(g1) > wid || AlphToInt(g1)/2 > len || (Board[AlphToInt(g1)][sti(g1)] !=  "|   " && Board[AlphToInt(g1)][sti(g1)] !=  "|   |"))
   {
      cout << "Invalid Input Try Again" << endl;
      cout << "What is your placement " << ShortPlayers[6] << "? ";
      cin >> g1;
   }
      if (sti(g1) == wid)
      {
          Board[AlphToInt(g1)][sti(g1)] = "| g |";
      }
      else Board[AlphToInt(g1)][sti(g1)] = "| g ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 6;
  }
}

  else if (turnCounter % NumPlayers == 1 && NumPlayers > 1)
  {
    cout << "What is your placement " << ShortPlayers[0] << "? ";
    cin >> a1;
    while(sti(a1) > wid || 
      AlphToInt(a1)/2 > len || 
      (Board[AlphToInt(a1)][sti(a1)] !=  "|   " && Board[AlphToInt(a1)][sti(a1)] !=  "|   |"))
    {
        cout << "Invalid Input Try Again" << endl;
        cout << "What is your placement " << ShortPlayers[0] << "? ";
        cin >> a1;
    }
      if (sti(a1) == wid)
      {
          Board[AlphToInt(a1)][sti(a1)] = "| a |";
      }
      else Board[AlphToInt(a1)][sti(a1)] = "| a ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 0;
  }
  else if (turnCounter % NumPlayers == 2 && NumPlayers > 2)
  {
    cout << "What is your placement " << ShortPlayers[1] << "? ";
    cin >> b1;
    while(sti(b1) > wid || 
     AlphToInt(b1)/2 > len || 
     (Board[AlphToInt(b1)][sti(b1)] !=  "|   " && Board[AlphToInt(b1)][sti(b1)] !=  "|   |"))
    {
       cout << "Invalid Perimeter Try Again" << endl;
       cout << "What is your placement " << ShortPlayers[1] << "? ";
       cin >> b1;
    }
    if (sti(b1) == wid)
    {
        Board[AlphToInt(b1)][sti(b1)] = "| b |";
    }
    else Board[AlphToInt(b1)][sti(b1)] = "| b ";
    turnCounter++;
    print2DArray(Board, (len * 2) + 3, wid + 2);
    WinCheck = 1;
  }

  else if ((turnCounter) % NumPlayers == 3 && NumPlayers > 3)
  {
    cout << "What is your placement " << ShortPlayers[2] << "? ";
    cin >> c1;
    while(sti(c1) > wid || 
      AlphToInt(c1)/2 > len || 
      (Board[AlphToInt(c1)][sti(c1)] !=  "|   " && Board[AlphToInt(c1)][sti(c1)] !=  "|   |"))
    {
       cout << "Invalid Perimeter Try Again" << endl;
       cout << "What is your placement " << ShortPlayers[4] << "? ";
       cin >> c1;
    }
      if (sti(c1) == wid)
      {
          Board[AlphToInt(c1)][sti(c1)] = "| c |";
      }
      else Board[AlphToInt(c1)][sti(c1)] = "| c ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 2;
  }
    else if ((turnCounter) % NumPlayers == 4 && NumPlayers > 4)
    {
      cout << "What is your placement " << ShortPlayers[3] << "? ";
      cin >> d1;
      while(sti(d1) > wid || 
       AlphToInt(d1)/2 > len || 
       (Board[AlphToInt(d1)][sti(d1)] !=  "|   " && Board[AlphToInt(d1)][sti(d1)] !=  "|   |"))
     {
        cout << "Invalid Perimeter Try Again" << endl;
        cout << "What is your placement " << ShortPlayers[3] << "? ";
        cin >> d1;
     }
       if (sti(d1) == wid)
       {
          Board[AlphToInt(d1)][sti(d1)] = "| d |";
       }
       else Board[AlphToInt(d1)][sti(d1)] = "| d ";
       turnCounter++;
       print2DArray(Board, (len * 2) + 3, wid + 2);
       WinCheck = 3;
    }

  else if ((turnCounter) % NumPlayers == 5 && NumPlayers > 5)
  {
    cout << "What is your placement " << ShortPlayers[4] << "? ";
    cin >> e1;
    while(sti(e1) > wid || 
      AlphToInt(e1)/2 > len || 
      (Board[AlphToInt(e1)][sti(e1)] !=  "|   " && Board[AlphToInt(e1)][sti(e1)] !=  "|   |"))
    {
       cout << "What is your placement " << ShortPlayers[4] << "? ";
       cin >> e1;
    }

      if (sti(e1) == wid)
       {
          Board[AlphToInt(e1)][sti(e1)] = "| e |";
       }
      else Board[AlphToInt(e1)][sti(e1)] = "| e ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 4;
 }

 else if ((turnCounter) % NumPlayers == 6 && NumPlayers > 6)
 {
   cout << "What is your placement " << ShortPlayers[5] << "? ";
   cin >> f1;
   while(sti(f1) > wid || 
     AlphToInt(d1)/2 > len || 
     (Board[AlphToInt(f1)][sti(f1)] !=  "|   " && Board[AlphToInt(f1)][sti(f1)] !=  "|   |"))
   {
       cout << "What is your placement " << ShortPlayers[5] << "? ";
       cin >> f1;
   }
      if (sti(f1) == wid)
      {
          Board[AlphToInt(f1)][sti(f1)] = "| f |";
      }
      else Board[AlphToInt(f1)][sti(f1)] = "| f ";
      turnCounter++;
      print2DArray(Board, (len * 2) + 3, wid + 2);
      WinCheck = 5;
}
        bool gameWon = false;
        bool** wins1 = new bool*[(len * 2) + 3];
        for (int i = 0; i < (len * 2) + 3; ++i) 
        {
            wins1[i] = new bool[wid + 2];
            for (int j = 0; j < wid + 2; ++j) 
            {
                wins1[i][j] = false;
            }
        }

        for (int x = 0; x < (len * 2) - 1; x++)
        {
            for (int r = 0; r < wid; r++)
            {
                if ((Board[x][r] == Board[x + 2][r]
                  && Board[x + 2][r] == Board[x + 4][r]
                  ||
                  Board[x][r] == Board[x][r + 1]
                  && Board[x][r + 1] == SpaceReplace(Board[x][r + 2])
                  || 
                  Board[x][r] == Board[x + 2][r + 1]
                  && Board[x + 2][r + 1] == SpaceReplace(Board[x + 4][r + 2]))
                  && Board[x][r] != "|   |"
                  && Board[x][r] != "--- "
                  && Board[x][r] != " --- "
                  && Board[x][r] != " "
                  && Board[x][r] != "|   ")
                {

                    if((Board[x][r] == Board[x + 2][r]
                        && Board[x + 2][r] == Board[x + 4][r])) {
                        wins1[x][r] = wins1[x+2][r] = wins1[x+4][r] = true;
                    }
                    if((Board[x][r] == Board[x][r+1]
                        && Board[x][r] == Board[x][r+2])) {
                        wins1[x][r] = wins1[x][r + 1] = wins1[x][r+2] = true;

                    }

                    if((Board[x][r] == Board[x + 2][r+1]
                        && Board[x + 2][r+1] == Board[x + 4][r+2])) {
                        wins1[x][r] = wins1[x+2][r + 1] = wins1[x+4][r+2] = true;
                    }

                    gameWon = true;

                }
            }
        }
        for (int i = 0; i < (len * 2) + 3; ++i) {
            for (int j = 0; j < wid + 2; ++j) {
                if(wins1[i][j]) {
                    capitalize(Board[i][j]);
                }
            }
            delete[] wins1[i];
        }
        delete[] wins1;
        if(gameWon) {
            print2DArray(Board, (len * 2) + 3, wid + 2);

            NumGames++;
            for (int i = 0; i < NumPlayers; i++)
            {
                if (WinCheck == i)
                {
                  wins[i]++;
                }
                else loss[i]++;
            }
            for(int i = 0;i < (NumPlayers*2)+3;i++)
            {
                for(int j = 0; j < 4;j++)
                {
                   if(i%2 == 0 && j < 3)
                    {
                        resBoard[i][j] = " ------ ";
                    }
                    if(j == 3 && i > 2 && i%2 == 1)
                    {
                        resBoard[i][j] = Capital(Players[i-k]);
                        k++;
                    }
                    else if(i == 1 && j == 0)
                    {
                        resBoard[i][j] = "|  WINS|";
                    }
                    else if(i == 1 && j == 1)
                    {
                        resBoard[i][j] = "|  LOSS|";
                    }
                    else if(i == 1 && j == 2)
                    {
                        resBoard[i][j] = "|  DRAW|";
                    }
                    else if(i%2 == 1 && j == 0)
                    {
                        resBoard[i][j] = "|     "+to_string(wins[i-w])+"|";
                        w++;
                    }
                    else if(i%2 == 1 && j == 1)
                    {
                        resBoard[i][j] = "|     "+to_string(loss[i-l])+"|";
                        l++;
                    }
                    else if(i%2 == 1 && j == 2)
                    {
                        resBoard[i][j] = "|     "+to_string(draw[i-dr])+"|";
                        dr++;
                    }
                  }
                   
              }
              Board = temp;
            for(int x = 0;x < (NumPlayers*2)+3;x++)
            {
                for(int y = 0;y < 4;y++)
                {
                    cout<<resBoard[x][y];
                }
                cout<<endl;
            }
            tempCounter = turnCounter;
            Board = temp;
           
            cout << "The number of games played is " << NumGames << endl;
            cout << "Press C to continue and press Q to quit" << endl;
            cin >> n;
            tempCounter = turnCounter;
            print2DArray(Board, (len * 2) + 3, wid + 2);
          }
        }
        
  cout << "Thank you for playing!" << endl;
        
}



// Because we search for the win condition from top-down, left-right. The starting point of
// wining conditions will be top left
void capitalizeWinConditions(string **board, int row, int col, int rows, int cols) {
    bool wins[5][5];
    for (int i = 0; i < 5 && (row + (i*2)) < rows; ++i) {
        for (int j = 0; j < 5 && (col + j) < cols; ++j) {
            if(SpaceReplace(board[row + (i*2)][col + j]) == board[row][col]) {
                wins[i][j] = true;
            }
            else {
                wins[i][j] = false;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(wins[i][j]) {
                capitalize(board[row + (i*2)][col + j]);
            }
        }
    }


}

void capitalize(string& str) {
    for(char& c : str) {
        c = toupper(c);
    }
}
