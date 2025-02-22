#include <iostream>
#include <string>

using namespace std;

/*----------------------------------------------------------------------
     How to find the number of leap years since 1900
---------------------------------------------------------------------*/

int GetLeap(int y)
{
  int leap = 0;
  int t = y-1900;
  
  for (int i = 1900;i < y;i++)
  {
     if ((i%4 == 0 && i%100 != 0) || i%400 == 0)
     {
          leap++;
     }
  }
  return leap;
}
/*----------------------------------------------------------------------
     How to find January 1st whe accounting for  leap years since 1900
---------------------------------------------------------------------*/
int GetFirstDay(int z)
{
   int t = z - 1900;
   int h  = ((t * 365) + GetLeap(z - 1)) % 7;
   
   h += 1;  // Because first day of 1900 is Monday
   if  (h > 6) 
   {
       h -= 7;
   }
   return h;
}

int DecimalToBinary(int num){

}
/*----------------------------------------------------------------------
    Centers the name of the month and the year at the top of the calander
---------------------------------------------------------------------*/
string centerYear(string yr, int width)
{
  string full,spaces;

  int pads = width - yr.length();
  
  for (int i = 0; i<pads/2;i++)
  {
      spaces = spaces +" ";
  }

  full = spaces + yr + spaces;

  return full;
}
/*----------------------------------------------------------------------
     Printing an array
---------------------------------------------------------------------*/
void PrintArray(string x[42])
{
     for (int z = 0; z < 42; z++)
     {
        if ((z+1)%7 == 0)
        {
          cout << x[z] << endl;
        }
      else
          cout<<x[z];
     }
}


int cti(char i) 
{
    return i - '0';
}


bool intChecker(string str)
{
    for (int i = 0;i < str.length();i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}


int STI(string n) {
    int num = 0;
    int p = 1;

    for  (int i = 0; i < n.length(); i++) 
    {
        for  (int s = n.length() - 1; s > i; s--) 
        {
            p = p * 10;
        }
        num += cti(n[i]) * p;
        p = 1;
    }

    return num;
}


bool IndentChecker(string arr[42])
{
    return arr[35][2] > '1';
}


int main() 
{
  string syr;
  cout << "What year would you like to see the calander of past 1899? ";
  cin >> syr;
  while(!intChecker(syr) || STI(syr) < 1899 || STI(syr) > 9999)
  {
      if(!intChecker(syr))
      {
        cout << "Please put a number. What year would you like to see the calander of past 1899? ";
      cin >> syr;
      }
    
      if (STI(syr) < 1899)
      {
        cout << "Choose a later year. What year would you like to see the calander of past 1899? ";
      cin >> syr;
      }
    
      if (STI(syr) > 9999)
      {
        cout << "Choose a earlier year. What year would you like to see the calander of past 1899? ";
      cin >> syr;
      }
  }
  while (STI(syr) < 1899 || STI(syr) > 9999)
  {
      
  }

  int yr = STI(syr);
  
  
  string Jan[42];
  string Feb[42];
  string March[42];
  string Apr[42];
  string May[42];
  string Jun[42];
  string July[42];
  string Aug[42];
  string Sep[42];
  string Oct[42];
  string Nov[42];
  string Dec[42];
  int dc = 0;
  int btw = 0;
 
  string DOY = "  Su  Mo  Tu  We  Th  Fr  Sa";
  string l = "----------------------------";
  string Months[12] = {"January", 
                      "February", 
                      "March", 
                      "April", 
                      "May", 
                      "June", 
                      "July", 
                      "August", 
                      "September", 
                      "October", 
                      "November", 
                      "December"};

  int FD = GetFirstDay(yr);
  if  (((yr-1)%4 == 0 && (yr-1)%100 != 0) || (yr-1)%400 == 0)
  {
    FD = GetFirstDay(yr) + 1;
  }
   
  for  (int j = 0; j < 42; j++) 
  {    
      if  (j > FD - 1 && dc < 31) 
      {
          dc++;
          if  (dc < 10)
             Jan[j] = "   " + to_string(dc);
          else
             Jan[j] = "  " + to_string(dc);
      }
      else 
         Jan[j] = "    ";
      
      if  (Jan[j] == "  31") 
      {
          btw = (j + 1) % 7;
      }
  }
    
  dc = 0;
  for  (int f = 0; f < 42; f++) 
  {
   if  (f < btw) 
   {
      Feb[f] = "    ";
   }
   if  (f > btw - 1 &&
           dc < 28 &&
           ((yr % 4 != 0) || (yr % 4 == 0 && yr % 400 != 0))) 
   {
      dc++;
      if  (dc < 10) 
      {
        Feb[f] = "   " + to_string(dc);
      } 
   else
      Feb[f] = "  " + to_string(dc);
   } 
   else if  ((f > btw - 1 &&
           dc < 29 &&
           yr%4 == 0 && yr%100 != 0) || yr%400 == 0)
   {
       dc++;
      if  (dc < 10) 
      {
          Feb[f] = "   " + to_string(dc);
      } 
      else
          Feb[f] = "  " + to_string(dc);
   }
    if  (Feb[f] == "  29" &&
        yr % 4 == 0 &&
        yr % 100) 
    {
        btw = (f + 1) % 7;
    }
    if  (Feb[f] == "  28" &&
        ((yr % 4 != 0) || (yr % 4 == 0 && yr % 400 != 0))) 
    {
        btw = (f + 1) % 7;
    }
  }
    dc = 0;
  for  (int mr = 0; mr < 42; mr++) 
  {
     if  (mr < btw) 
     {
        March[mr] = "    ";
     }
     if  (mr > btw - 1 && dc < 31) 
     {
        dc++;
       if  (dc < 10) 
       {
         March[mr] = "   " + to_string(dc);
       } 
       else March[mr] = "  " + to_string(dc);
     }
     if  (March[mr] == "  31") 
     {
      btw = (mr + 1) % 7;
     }
  }
  dc = 0;
  for  (int ap = 0; ap < 42; ap++) 
  {
     if  (ap < btw) 
     {
        Apr[ap] = "    ";
     }
     if  (ap > btw - 1 && dc < 30) 
     {
       dc++;
       if  (dc < 10) 
       {
          Apr[ap] = "   " + to_string(dc);
       } 
       else Apr[ap] = "  " + to_string(dc);
     }
     if  (Apr[ap] == "  30") 
     {
      btw = (ap + 1) % 7;
     }
  }
   dc = 0;
  for  (int my = 0; my < 42; my++) 
  {
     if  (my < btw) 
     {
        May[my] = "    ";
     }
     if  (my > btw - 1 && dc < 31) 
     {
       dc++;
       if  (dc < 10) 
       {
          May[my] = "   " + to_string(dc);
       } 
       else May[my] = "  " + to_string(dc);
     }
     if  (May[my] == "  31") 
     {
      btw = (my + 1) % 7;
     }
  }
   dc = 0;
  for  (int jn = 0; jn < 42; jn++) 
  {
   if  (jn < btw) 
   {
      Jun[jn] = "    ";
   }
   if  (jn > btw - 1 && dc < 30) 
   {
   dc++;
      if  (dc < 10) 
      {
        Jun[jn] = "   " + to_string(dc);
      } 
      else Jun[jn] = "  " + to_string(dc);
   }
    if  (Jun[jn] == "  30") 
    {
       btw = (jn + 1) % 7;
    }
  }
  dc = 0;
  for  (int jl = 0; jl < 42; jl++) {
   if  (jl < btw) 
   {
     July[jl] = "    ";
   }
   if  (jl > btw - 1 && dc < 31) 
   {
     dc++;
     if  (dc < 10) 
     {
        July[jl] = "   " + to_string(dc);
     } 
     else July[jl] = "  " + to_string(dc);
   }
   if (July[jl] == "  31") 
   {
      btw = (jl + 1) % 7;
   }
  }
  dc = 0;
  for  (int au = 0; au < 42; au++) 
  {
   if  (au < btw) 
   {
      Aug[au] = "    ";
   }
   if  (au > btw - 1 && dc < 31) 
   {
      dc++;
      if  (dc < 10) 
      {
        Aug[au] = "   " + to_string(dc);
      } 
      else Aug[au] = "  " + to_string(dc);
   }
    if  (Aug[au] == "  31") 
    {
     btw = (au + 1) % 7;
    }
  }
  dc = 0;
  for  (int se = 0; se < 42; se++) 
  {
     if  (se < btw) 
     {
        Sep[se] = "    ";
     }
     if  (se > btw - 1 && dc < 31) 
     {
      dc++;
        if  (dc < 10) 
        {
          Sep[se] = "   " + to_string(dc);
        } 
        else Sep[se] = "  " + to_string(dc);
     }
      if  (Sep[se] == "  31") 
      {
        btw = (se + 1) % 7;
      }
  }
    
  dc = 0;
  for  (int o = 0; o < 42; o++) 
  {
     if  (o < btw) 
     {
        Oct[o] = "    ";
     }
     if  (o > btw - 1 && dc < 31) 
     {
       dc++;
       if  (dc < 10) 
       {
          Oct[o] = "   " + to_string(dc);
       } 
       else Oct[o] = "  " + to_string(dc);
     }
     if  (Oct[o] == "  31") 
     {
      btw = (o + 1) % 7;
     }
  }
  dc = 0;
  for  (int n = 0; n < 42; n++) {
     if  (n < btw) 
     {
        Nov[n] = "    ";
     }
     if  (n > btw - 1 && dc < 31) {
      dc++;
     if  (dc < 10) 
     {
        Nov[n] = "   " + to_string(dc);
     } 
     else Nov[n] = "  " + to_string(dc);
     }
     if  (Nov[n] == "  31") 
     {
      btw = (n + 1) % 7;
     }
  }
  dc = 0;
  for  (int d = 0; d < 42; d++) {
     if  (d < btw) 
     {
      Dec[d] = "    ";
     }
     if  (d > btw - 1 && dc < 31)
     {
        dc++;
        if  (dc < 10) 
        {
          Dec[d] = "   " + to_string(dc);
        } 
        else Dec[d] = "  " + to_string(dc);
      }
     if  (Dec[d] == "  31") 
     {
      btw = (d + 1) % 7;
     }
  
  }
  
    while (yr < 1900)
    {
     cout<<"Wrong Year"<<endl;
     cout << "What year would you like to see the calander of past 1899? ";
     cin >> yr;  
    
    }
  
    cout<<endl;
  
  for  (int cal = 0; cal < 24; cal++) 
  {
     if  (cal % 2 == 0) 
     {
        cout << centerYear(Months[cal / 2] + " " + to_string(yr),28) << endl;
        cout << DOY << endl;
        cout << l << endl;
     }
     if  (cal == 1) 
     {
        PrintArray(Jan);
        if (IndentChecker(Jan))
        {
          cout<<endl;
        }
     }
     if  (cal == 3) 
     {
        PrintArray(Feb);
        if (IndentChecker(Feb))
        {
          cout<<endl;
        }
     }
     if  (cal == 5) 
     {
        PrintArray(March);
        if (IndentChecker(March))
        {
          cout<<endl;
        }
     }
     if  (cal == 7) 
     {
        PrintArray(Apr);
        if (IndentChecker(Apr))
        {
          cout<<endl;
        }
     }
     if  (cal == 9) 
     {
        PrintArray(May);
        if (IndentChecker(May))
        {
          cout<<endl;
        }
     }
     if  (cal == 11) 
     {
        PrintArray(Jun);
        if (IndentChecker(Jun))
        {
          cout<<endl;
        }
     }
     if  (cal == 13) 
     {
        PrintArray(July);
        if (IndentChecker(July))
        {
          cout<<endl;
        }
     }
     if  (cal == 15) 
     {
        PrintArray(Aug);
        if (IndentChecker(Aug))
        {
          cout<<endl;
        }
     }
     if  (cal == 17) 
     {
        PrintArray(Sep);
        if (IndentChecker(Sep))
        {
          cout<<endl;
        }
     }
     if  (cal == 19) 
     {
        PrintArray(Oct);
        if (IndentChecker(Oct))
        {
          cout<<endl;
        }
     }
     if  (cal == 21) 
     {
        PrintArray(Nov);
        if (IndentChecker(Nov))
        {
          cout<<endl;
        }
     }
     if  (cal == 23) 
     {
        PrintArray(Dec);
        if (IndentChecker(Dec))
        {
          cout<<endl;
        }
     }
   }


}
