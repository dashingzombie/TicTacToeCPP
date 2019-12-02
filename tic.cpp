//TicTacToe
#include<iostream>
#include<math.h>

// using standard namespace
using namespace std;

//  function definition
 void grid()
{
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<3;j++)
    {
      cout<<"  | \n--------";

    }
  }
}
//End of Function

//Main function begins
int main ()
   {
       grid();
   }
//End Of Main
