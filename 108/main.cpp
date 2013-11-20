/* ********************
* Team exercise, so this is pretty messy
******************* */

#include <iostream>

int square_width;
int square[100][100];
int row[100];

int MaxInRow();
void FillRow( int topRow, int bottomRow );

int main(int args, char** argv) {

   int max=-200;
   int currMax = -200;

   std::cin >> square_width;
   for ( int i = 0; i < (square_width); i++) {
      for ( int j = 0; j < (square_width); j++) {
         std::cin >> square[i][j];
      }
   }

   for( int topRow=0; topRow<square_width; topRow++ )
   {
      for( int bottomRow=topRow; bottomRow<square_width; bottomRow++ )
      {
         FillRow( topRow, bottomRow );
	 currMax = MaxInRow();
	 if( currMax > max )
	    max = currMax;
      }
   }

   std::cout << max << std::endl;
   return 0;
}

int MaxInRow() {
   int current;
   int max;

   current = row[0];
   max = current;
   for (int i = 1; i < square_width; i++) {
      int index = row[i];

      if ( current < 0 && index >= 0 ) {
         current = index; 
      } else {
         current += index;
      }

     if ( current > max ) {
         max = current;
     }    
   }
   return max;
}

void FillRow( int topRow, int bottomRow )
{
	for( int i=0; i<square_width; i++ )
	{
		row[i] = square[topRow][i];
	}

	if( topRow != bottomRow )
	{
		for( int i=topRow+1; i<=bottomRow; i++ )
		{
			for( int j=0; j<square_width; j++ )
			{
				row[j] = row[j]+square[i][j];
			}
		}
	}
}
