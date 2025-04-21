#ifndef NUMBER_THEORY
#define NUMBER_THEORY

namespace number_theory{

    /**
     * Determines if a number `a` is prime.
     * Parameters:
     *  - `a`: an integer.
     */
    bool is_prime(int a){
        if(a < 2 | (a !=2 && a % 2 == 0))
            return false;
        else if(a < 4)
            return true;
        else {
            for(int i=3; i*i < a; i+=2){
                if(a % i == 0)
                    return false;
            }
            return true;
        }
    }
}

#endif