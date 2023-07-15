#include "KMP.h"
#include "boyerMoore.h"
#include <iostream>

int main(){
    //create variables
    std::string base;
    std::string find;

    // get given information
    std::cout << "Please input your base string to find a pattern within.\n";
    std::getline(std::cin,base);

    std::cout << "Please input the pattern you would like to search for within this string\n";
    std::getline(std::cin,base);

    //make sure strings can be tested
    if(find.length() > base.length()){

        std::cout << "This pattern will not exist in the base string as it is too large. Please try again.\n";
        return 0;

    }

    //create objects
    boyerMoore BM(base);
    KMP KMP(base);

    //have to only perform this once to ensure number of runs for efficiency is correct
    int kIndex = KMP.findIndex(find);

    //program returns -1 if function could not be found else state index where pattern was found and efficiency.
    if(kIndex != -1) {
        std::cout << "Using the Knuth-Morris-Pratt algorithm the index this pattern appears is " << kIndex<< ".\n";
        std::cout << "This program ran a total of " << KMP.get_efficiency() << " times to find this.\n";
    }
    else{
        std::cout << "The given pattern could not be found within the base string.\n";
        return 0;
    }

    //have to only perform this once to ensure number of runs for efficiency is correct
    int bmIndex = BM.findIndex(find);

    //program returns -1 if function could not be found else state index where pattern was found and efficiency.
    if(bmIndex != -1) {
        std::cout << "Using the Boyer-Moore algorithm the index this pattern appears is " << bmIndex<< ".\n";
        std::cout << "This program ran a total of " << BM.get_efficiency() << " times to find this.\n";
    }

    return 0;

}