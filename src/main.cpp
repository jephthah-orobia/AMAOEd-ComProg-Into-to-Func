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

using namespace std;

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
            cout << "\033[32m";
          else
            cout << "\033[31m";
        }
        cout << " " << seatingChart[row-1][col-1] << " \033[0m";
      }
      cout << endl;
    }

    /* Notify of the result of last action */
    if(last_attempt.first > 0){
      if(accomodated)
        cout << endl << "\033[32mSeat "<<last_attempt.first<<"-"<<last_attempt.second
            <<" was successfully reserved!\033[0m";
      else
        cout << endl << "\033[31mSeat already taken. Choose another one.\033[0m";
    }

    cout << endl << "*** Seat to reserved ***" << endl;

    /* Prompt the user for row number*/
    do{
      if(cin.fail() || r < 1 || r > rows){
        cout << "\033[31mInvalid row number. Try again [1-" << rows << "]!\033[0m" << endl;
        if(cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
      cout << "-> row number: ";
      cin >> r;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(cin.fail() || r < 1 || r > rows);

    /* Prompt the user for column number*/
    do{
      if(cin.fail() || c < 1 || c > cols){
        cout << "\033[31mInvalid column number. Try again [1-" << cols << "]!\033[0m" << endl;
        if(cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
      cout << "-> column number: ";
      cin >> c;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(cin.fail() || c < 1 || c > cols);
    
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
