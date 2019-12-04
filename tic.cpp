//TicTacToe
#include<iostream>
#include<math.h>

// using standard namespace
using namespace std;

//  function definition
//Prints the grid for the game along with user inputted options
void grid(char a[10])
{
   for (int i=1;i<9;i=i+3)
   {
      cout<<a[i]<< "  | "<< a[i+1] << "  |  "  <<a[i+2]<< " \n";
      cout<<"-------------- \n";
   }
}

//Player 1 chance
void chance1(char a[10], int b, char p1)
{
   a[b]=p1;
}
//Player 2 Chance
void chance2(char a[10], int b, char p2)
{
   a[b]=p2;
}
//For winner
int winner(char a[10], char p1 , char p2)
{
   for(int i=1;i<10;i=i+3)
   {
       if (a[i]==a[i+1] && a[i+1]==a[i+2] )
       {
          if (a[i] == p1)
          {
             cout<<"Player 1 wins. \n";
             return 1;
          }
          else if (a[i] == p2)
          {
             cout<<"Player 2 wins. \n";
             return 1;
          }
       }
       else if (a[i]==a[i+3] && a[i+3]==a[i+6] )
       {
          if (a[i] == p1)
          {
             cout<<"Player 1 wins. \n";
             return 1;
          }
          else if (a[i] == p2)
          {
             cout<<"Player 2 wins. \n";
             return 1;
          }
       }
       else if (a[1] == a[5]  && a[5] == a[9] )
       {
          if (a[i] == p1)
          {
             cout<<"Player 1 wins. \n ";
             return 1;
          }
          else if (a[i] == p2)
          {
             cout<<"Player 2 wins. \n";
             return 1;
          }
       }
       else if (a[3] == a[5] && a[5] == a[7])
       {
		   /* the case if player one chooses '+' and then selects 3->5->7
		   while player two selects anything but it has to start from 1 fails.
		   I have made a temporary fix but you should fix the logic and refine it a bit.*/
		   cout << "p1 =" << p1 << endl;
		   cout << "p2 = " << p2 << endl;
		   cout << "a[7] =" << a[7] << endl; 
		   cout << "a[i] = " << a[i] << endl;
          if (a[7] == p1)
          {
             cout<<"Player 1 wins. \n";
             return 1;
          }
          else if (a[7] == p2)
          {
             cout<<"Player 2 wins. \n";
             return 1;
          }
       }
   }
   return 0;
}
//End of Function

//Main function begins
int main ()
{
    char a[10];
    int guide,g;
    char p1,p2;
    //Assigns a ascii code of 1-9 to the character array
    for(int i=1,j=49;j<58;j++,i++)
    {
       a[i]=j;
    }
    //Assign 0 or + to player 1 and 2
    cout<<"Player 1 - Choose your guide \n 1 for 0 or 2 for +";
    cin>>guide;
    if (guide == 1)
    {
       cout<<"Player 1 has chosen 0 , Player 2 is + \n";
       p1='0';
       p2='+';
    }
    else if ( guide == 2)
    {
       cout<<"Player 1 has chosen + , Player 2 is 0 \n";
       p1='+';
       p2='0';
    }
    else
    {
       cout<<"Please restart and choose correct option";
       return 0;
    }
    //Game Starts
    for(int i=0;i<9;i=i+2)
    {
       grid(a);
       cout<<"Player 1 Enter from 1 to 9 ,where you want to place your guide";
       cin>>g;
       //So that wrong option is not entered or repeated
       if (g<1 || g>10  || a[g]==p1 || a[g]==p2)
       {
          cout<<"Wrong Choice Restart";
          return 0;
       }
       chance1(a,g,p1);
       if (winner(a,p1,p2) == 1)
       {
          grid(a);
          return 0;
       }
       grid(a);
       cout<<"Player 2 Enter from 1 to 9 ,where you want to place your guide";
       cin>>g;
       if (g<1 || g>10 || a[g]==p1 || a[g]==p2)
       {
          cout<<"Wrong Choice. Restart";
          return 0;
       }
       chance2(a,g,p2);
       if (winner(a,p1,p2) == 1)
       {
          grid(a);
          return 0;
       }
    }
    cout<<"It's a Draw";
}
//End Of Main