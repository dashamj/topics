/*
01---
--2--
--232
----2
*/

//DFA sample C++ program for Topics Class
//
//
#include <iostream> 
#include <iomanip>
#include <fstream>
using namespace std;

char DFA[4][5] = 
{ { '_', '_', '_', '_', '_' },
{ '_', '_', '_', '_', '_'},
{ '_', '_', '_', '_', '_'},
{ '_', '_', '_', '_', '_'} };


char move (char state, char ch)
{
  int row, col;
  row = (int)state - 48; 
  switch (ch)
  {
  case 'a':  col = 0; break; 
  case 'b':  col = 1; break;
  case 'c':  col = 2; break; 
  case 'd':  col = 3; break; 
  case 'm': col = 4; break;  
  default:  cout << "\n" << ch << "is an invalid character***";
  cout << "***not in the dictionary***\n";
  cin.get(); exit(0);
  };
  return DFA [row][col];
}

//Function to view the contents of the transistion table
void showTable()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << setw(2)<<DFA[i][j];
    }
    cout << "\n";
  }
}
//New section
void getFile()
{ 
  ifstream fptr;
  fptr.open("DFA1", ios::in);
  if (fptr.fail())
  {
    cerr << "error opening file\n";
    cin.get();
    exit(0);
  }

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      fptr>> DFA[i][j];
    }
  }
}
int main()
{
  showTable(); //New function 
  getFile(); //Call to a file
  cout << "after\n";
  showTable(); //second call
  char s = '0';
  char ch;
  while ((ch = getchar()) != '\n') 
  {
    cout << "move from" << s << " on " << ch;
    s = move (s, ch);
    if (s != '_')
      cout << "to" << s << "\n";
    else 
    {
      cout << " to ? <-- you can't move to another state using  " << ch << "\n";
      cout << "***not in the dictionary***\n";
      cin.get(); exit(0);
    }
  }
  if (s == '3')
    cout << "accepted\n";
  else 
    cout << "did not reach tje final state(not in the dictionary)";
  cin.get(); return 0;
}
  
