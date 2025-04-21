/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: Prime Sieve
 * @app desc: Determines if a number is a prime number or not.
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "text_style.h"
#include "validation.h"
#include "number_theory.h"

using namespace std;
using namespace style;
using namespace validation;

int main()
{
  function<bool(int)> is_valid = [](int a)
  { return a >= 0; };
  
  int n = getValidInput(
      cin,                                              // input stream
      cout,                                             // output stream
      "A positive integer or 0 to exit: ",              // prompt for input
      fg_red("<Input is invalid, please try again>\n"), // error message
      is_valid);

  if (n == 0)
    return EXIT_SUCCESS;

  if (number_theory::is_prime(n))
    cout << fg_green(n, " is a prime number.\n");
  else
  {
    cout << fg_red(n, " is NOT a prime number.\n");
    if(n != 1){
      cout << "Divisors of " << n << ":" << endl;
      cout << italic("\t1, ");
      for (int i = 2; i < n; i++)
      {
        if (n % i == 0)
          cout << italic(i, ", ");
      }
      cout << italic(n) << endl;
    }
  }

  /* Decoration to separate each sieving */
  cout << "---------------------------------" << endl;
  
  return main();
}
