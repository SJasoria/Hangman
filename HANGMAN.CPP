#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>

class game
 {
  char word_o[15],word_u[15] ;
  int  position,gleft;
  public:
  int selectword();
  int askuser(int);
  int level1();
  int level2();
  void level3();
  void display(char wg[]);
  void displayHM();
  int  check();//to check if word is guessed completely
 }s1,s2,s3;

int game::level1()
 {
  int c=0;
  ifstream file;
  file.open("level_1.dat",ios::binary);
  position=selectword();
  while(c!=position)
   {
    file>>word_o;
    c++;
   }
   for(int i=0;word_o[i]!='\0';i++)
      word_u[i]='*';
   cout<<"Level 1: Guess the name of fruit or vegetable  ";
   if(askuser(i)==1)
   {
    cout<<"\n!!Congratulations!! You have cleared level 1!!\n";
    cout<<"\nPress any key to continue";
    getch();
    return 1;
   }
   else
   {
    cout<<"\nSorry,you are hanged";
    cout<<"\nYou have failed to clear level 1";
    cout<<"\nThe word you were looking for is :"<<word_o;
    cout<<"\nPress any key to end the game";
    getch();
    exit(0);
   }
   return 0;
  }

int game::level2()
 {
  int c=0;
  ifstream file;
  file.open("level_2.dat",ios::binary);
  position=selectword();

  while(c!=position)
   {
    file>>word_o;
    c++;
   }
  for(int i=0;word_o[i]!='\0';i++)
     word_u[i]='*';
  clrscr();
  cout<<"\nLevel 2: Guess the name of animal or bird";
  if(askuser(i)==1)
   {
    cout<<"\n!!Congratulations!! You have cleared level 2!!";
    cout<<"\nPress any key to continue";
    getch();
    return 1;
   }
  else
   {
    cout<<"\nSorry,you are hanged";
    cout<<"\nYou have failed to clear level 2";
    cout<<"\nThe word you were looking for is :"<<word_o;
    cout<<"\nPress any key to end the game";
    getch();
    exit(0);
   }
   return 0;
  }

void game::level3()
 {
  int c=0;
  ifstream file;
  file.open("level_3.dat",ios::binary);
  position=selectword();
  while(c!=position)
   {
    file>>word_o;
    c++;
   }
  for(int i=0;word_o[i]!='\0';i++)
     word_u[i]='*';
  clrscr();
  cout<<"\nLevel 3: Guess the name of the country";
  if(askuser(i)==1)
   {
    cout<<"\n!!Congratulations!! You have cleared level 3!!";
    cout<<"\nPress any key to end the game";
    getch();
   }
  else
   {
    cout<<"\nSorry,you are hanged";
    cout<<"\nYou have failed to clear level 3";
    cout<<"\nThe word you were looking for is :"<<word_o;
    cout<<"\nPress any key to end the game";
    getch();
    exit(0);
   }
  }

int game::selectword()
 {
  int p;
  randomize();
  p=random(40)+1;
  return p;
 }

int game::askuser(int x)
 {
  int g,tg=0;
  gleft=6;
  char  c,wrong_g[7],tguesses[25];
  cout<<"\nGuess the word \t"<<word_u<<endl;
  while(gleft!=0)
   {
    if(wherey()>20)
      {
       clrscr();
       cout<<endl;
       display(wrong_g);
      }
    cout<<"\nEnter a letter ";
    cin>>c;
    if(tg!=0) //to check repetition of letters
     {
      for(int i=0;i<tg;i++)
	{
	 if(tguesses[i]==c)
	  break;
	}
      if(i!=tg)
	{
	 cout<<"You have already entered this letter. Try again.\n";
	 continue;
	}
      }
    g=0;
    for(int i=0;i<=x;i++)
     {
      if(word_o[i]==c)
       {
	g++;
	word_u[i]=c;
       }
      }
    if(g!=0)
      cout<<"Right guess!";
    else
     {
      cout<<"Wrong guess";
      wrong_g[gleft]=c;
      gleft--;
     }
    display(wrong_g);
    if(check())
      return 1;
    tguesses[tg]=c;
    tg++;
   }
  return 0;
 }

void game::display(char wg[])
  {
   cout<<"\nWord :"<<word_u;
   if(gleft==6)
     cout<<"\nWrong guesses: nil";
   else
    {
     cout<<"\nWrong guesses:";
     for(int i=6;i>gleft;i--)
     cout<<wg[i]<<",";
    }
   displayHM();
  }

int game ::check()
  {
   if(strcmp(word_o,word_u))
     return 0;
   else
     return 1;
  }

void game :: displayHM()
  {
   int y1,y2;
   y2=wherey();
   y1=y2-3;
   switch(gleft)
     {
      case 6: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       \n\n\n";
	      break;

      case 5: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       ";
	      gotoxy(50,y1++);
	      cout<<"     O       \n\n";
	      break;

      case 4: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       ";
	      gotoxy(50,y1++);
	      cout<<"     O       ";
	      gotoxy(50,y1++);
	      cout<<"     I       ";
	      gotoxy(50,y1++);
	      cout<<"     I       ";
	      break;

      case 3: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       ";
	      gotoxy(50,y1++);
	      cout<<"     O       ";
	      gotoxy(50,y1++);
	      cout<<"    /I       ";
	      gotoxy(50,y1++);
	      cout<<"     I       ";
	      break;

      case 2: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       ";
	      gotoxy(50,y1++);
	      cout<<"     O       ";
	      gotoxy(50,y1++);
	      cout<<"    /I\\     ";
	      gotoxy(50,y1++);
	      cout<<"     I       ";
	      break;

      case 1: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       ";
	      gotoxy(50,y1++);
	      cout<<"     O       ";
	      gotoxy(50,y1++);
	      cout<<"    /I\\     ";
	      gotoxy(50,y1++);
	      cout<<"     I       ";
	      gotoxy(50,y1++);
	      cout<<"    /        ";
	      break;

      case 0: gotoxy(50,y1++);
	      cout<<"  _______    ";
	      gotoxy(50,y1++);
	      cout<<"     |       ";
	      gotoxy(50,y1++);
	      cout<<"     O       ";
	      gotoxy(50,y1++);
	      cout<<"    /I\\     ";
	      gotoxy(50,y1++);
	      cout<<"     I       ";
	      gotoxy(50,y1++);
	      cout<<"    / \\     ";
	      break;
       }
   }


void main()
{
 clrscr();
 int x;
 cout<<"********************************   HANGMAN   ***********************************";
 cout<<"\nYou have to save Hangman from gallows by guessing the correct word before you";
 cout<<"\nrun out of chances.";
 cout<<"\n\nYou can input one letter at a time.If you guess correct letter, it will be";
 cout<<"\nfilled at its appropriate place.";
 cout<<"\n\nThere are 3 theme based levels.You get 6 tries in each level.";
 cout<<"\n\nEnjoy the classic game of Hangman.";
 cout<<"\n\nPRESS ANY KEY TO START THE GAME";
 cout<<"\n********************************************************************************";
 getch();
 clrscr();
   x=s1.level1();
 if(x)
   x=s2.level2();
 if(x)
   s3.level3();
 getch();
}
