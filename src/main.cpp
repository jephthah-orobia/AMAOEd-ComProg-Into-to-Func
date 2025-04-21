/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: IMS
 * @app desc: 
 *  (Read README.MD)
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include "validation.h"
#include "text_style.h"

using namespace std;
using namespace style;

int main()
{
  const int MAXINPUT = 20, STOCKLIMIT=99999;
  vector<pair<string, int>> items = {
    {"Apples", 10},
    {"Bananas", 20},
    {"Oranges", 15},
    {"Grapes", 5},
  };

  while(true){
    string item;
    int stock = 0;
    bool isNewItem = true;
    
    system("clear");

    /* Display Title */
    cout << "Inventory Management System" << endl << endl;

    /* Print Heading */
    cout << right << setfill('-') << "+" << setw(MAXINPUT+3) << "+" << setw(8) << "+" << endl; // top border
    cout << setfill(' ') << "|\033[1m" << left << setw(MAXINPUT+2) << " ITEMS" << "\033[0m|" << setw(7) << " STOCK" << "|" << endl; // content
    cout << right << setfill('-') << "+" << setw(MAXINPUT+3) << "+" << setw(8) << "+" << endl; // bottom border of the header
    
    /* Print table rows */
    cout << left << setfill(' ');
  
    for(auto& i: items)
      cout << "| " << setw(MAXINPUT) << i.first << " | " << setw(5) << i.second << " |" << endl; // row
    
    /* Print bottom border of the table */
    cout << right << setfill('-') << "+" << setw(MAXINPUT+3) << "+" << setw(8) << "+" << endl; // bottom border of the header
    
    /* Prompt user to which item to create or update */
    cout << endl << "\033[2m[Case sensitive & Max of " << MAXINPUT << " characters or type `exit` to terminate program]\033[0m"
    << endl << "Item to update: ";
    getline(cin, item);

    if(item.length() > MAXINPUT)
      item = item.substr(0, MAXINPUT);
    
    if(item == "exit")
      break;


    /* Check if item already exist */
    for(auto i: items)
      if(i.first == item){
        isNewItem = false;
        stock = i.second;
        break;
      }
    if(isNewItem)
      cout << endl << italic(fg_green(item)) << italic(" will be created.") << endl;
    
    /* Prompt user for the stock count */
    function<bool(int)> is_valid = [](int s){ return s >= 0 && s < STOCKLIMIT;};
    stock = validation::getValidInput(
      cin, cout,
      "# of stocks for " + fg_green(item) +": ",
      fg_red("Invalid #, Please again. [0-", STOCKLIMIT, " only]\n"),
      is_valid
    );

    /* Updating the table */
    if(isNewItem)
      items.emplace_back(make_pair(item, stock)); // create new entry if the item is new.
    else{
      for(auto& i: items){ // update table if item already exist
        if(i.first == item)
          i.second = stock;
      }
    }
  }
  
  return EXIT_SUCCESS;
}
