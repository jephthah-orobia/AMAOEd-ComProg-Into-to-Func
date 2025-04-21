/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: Theatre Seating Chart
 * @app desc: 
 *  (Read README.MD)
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include "validation.h"
#include "text_style.h"

using namespace std;
using namespace style;

int main()
{
  const int rows = 10, cols = 30;
  char seatingChart[rows][cols];

  memset(seatingChart, 'O', sizeof(seatingChart));

  pair<int, int> last_attempt = {0, 0};

  bool accomodated = true;

  while(true){
    int r=1, c=1;
    
    system("clear");
    
    cout << "Theatre Seats" << endl << endl;
    /* Print Column Labels */
    cout << "\033[2m   |";
    for(int col_label = 1; col_label <= cols; col_label++){
      cout << " " << left << setfill(' ') << setw(2) << col_label;
    }
    cout << endl << "---+" << setfill('-') << setw(cols*3) << "-" << endl;
    cout << setfill(' ') << left;
    
    /* Print Rows and Seats*/
    for(int row = 1; row<=rows; row++){
      cout << "\033[2m" << setw(3) << row << "|\033[0m";
      for(int col = 1; col<=cols; col++){
        if(last_attempt.first == row && last_attempt.second == col){
          if(accomodated)
            cout << fg_green(" ", seatingChart[row-1][col-1], " ");
          else
            cout << fg_red(" ", seatingChart[row-1][col-1], " ");
        } else
          cout << " " << seatingChart[row-1][col-1] << " ";
      }
      cout << endl;
    }

    /* Notify of the result of last action */
    if(last_attempt.first > 0){
      if(accomodated)
        cout << endl << fg_green(last_attempt.first,"-",last_attempt.second," was successfully reserved!");
      else
        cout << endl << fg_red("Seat already taken. Choose another one.");
    }

    cout << endl << "*** Seat to reserved ***" << endl;

    /* Prompt the user for row number*/
    function<bool(int)> is_valid_row = [rows](int a){return a > 0 && a < rows;};
    r = validation::getValidInput(
      cin, cout,
      "-> row number: ",
      fg_red("Invalid row number. Try again [1-", rows, "]!\n"),
      is_valid_row
    );

    /* Prompt the user for column number*/
    function<bool(int)> is_valid_col = [rows](int a){return a > 0 && a < cols;};
    c = validation::getValidInput(
      cin, cout,
      "-> column number: ",
      fg_red("Invalid column number. Try again [1-", cols, "]!\n"),
      is_valid_col
    );

    /* update seating chart */
    if(seatingChart[r-1][c-1] == 'X'){
      accomodated = false;
    } else {
      accomodated = true;
      seatingChart[r-1][c-1] = 'X';
    }
      
    last_attempt = make_pair(r, c);
  }

  return EXIT_SUCCESS;
}
