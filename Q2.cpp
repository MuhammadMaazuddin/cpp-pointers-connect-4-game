
#include <iostream>
#include <cmath>
using namespace std;
void DisplayMagicSquare(int** array, int order);//displaying magicSquare
bool InstructionDisplay(bool flage);// displaying instruction 
int main() 
{
    bool flag = false;
    flag = InstructionDisplay(flag); 
    if(flag == true)
{ 
  int order;                 // Dimension input from user
  cout<<"Enter the dimension of squareBox  ::  ";
  cin>>order;

    //Allocating memory 
    //Declaration

  int **array = new int*[order]; //*array 1D declaration

    for (int i = 0; i < order; i++) 
        { array[i] = new int[order];} //**array 2D declaration

// indexes of array that will be genrated logically //==> see --> (MAIN LOGIC)
  int width = 0;
  int  height = order / 2;
  int  num = 1;

  // MAIN LOGIC ::
  // 
  for (int i = 1; i <= order * order; i++) 
  {
    array[width][height] = i;
    width--;
    height++;
    if (i % order == 0)
    { width += 2; height--;} 
    else
    { if (width < 0) { width = order - 1;}
    if(height == order) 
    {height = 0;}}
  }
// Displaying

  DisplayMagicSquare(array, order);

// Deallocating

  for (int i = 0; i < order; i++) 
  {
    delete[] array[i];
  }
   delete[] array;
}
  return 0;
}
bool InstructionDisplay(bool flage )
{
    char alpha;
    cout<<"__________________________________________\n";
    cout<<"[READ THE FOLLOWING INSTRUCTION CAREFULLY]\n";
    cout<<"------------------------------------------\n";
    cout<<"****************MAGIC_SQUARE**************\n";
    cout<<"***********Enter the odd integer**********\n";
    cout<<"[****************THANK_YOU***************]\n";
    cout<<"------------------------------------------\n";
    cout<<"Press c to continue ::  ";
    cin>>alpha;
    if(alpha == 'c')
    { flage = true; }
    return flage;
}

// function to display magicSquare
void DisplayMagicSquare(int** array, int order)
{
    cout << "The magic square of size " << order << "x" << order << " is: " << endl;
  for (int i = 0; i < order; i++) 
  {
    for (int j = 0; j < order; j++) 
    {
      if(*(*(array+i)+j) <=9)
            {
            cout<< *(*(array+i)+j) << "   ";
            }
            if(*(*(array+i)+j)>9)
            {
            cout << *(*(array+i)+j) << "  ";
            }
    }
    cout<<endl;
    cout<<endl;
  }
}

