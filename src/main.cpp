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

using namespace std;

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
      cout << endl << "\033[3mNew item \033[32m" << item << "\033[39m will be created.\033[0m" << endl;
    
      /* Prompt user for the stock count */
    do{
      if(cin.fail() || stock < 0 || stock > STOCKLIMIT){
        cout << "\033[31mInvalid #, Please again. [0-"<< STOCKLIMIT <<" only]\033[0m" << endl;
        if(cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(isNewItem)
          stock = 0;
        else{
          for(auto i: items)
            if(i.first == item){
              stock = i.second;
              break;
            }
        }
      }
      cout << "# of stocks for \033[32m" << item << "\033[0m: ";
      cin >> stock;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (cin.fail() || stock < 0 || stock > STOCKLIMIT);

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
