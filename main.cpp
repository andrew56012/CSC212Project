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

    std::cout << "Please input the pattern you would like to search for within this string.\n";
    std::getline(std::cin,find);

    //make sure strings can be tested
    if(find.length() > base.length()){

        std::cout << "This pattern will not exist in the base string as it is too large. Please try again.\n";
        return 0;

    }

    //create objects
    boyerMoore BM(base);
    KMP KMP(base);

    //have to only perform this once to ensure number of runs for efficiency is correct
    std::vector<int> kIndex = KMP.findIndex(find);

    //Check if the vector of found indexes is empty or not
    if(kIndex.empty() == 1) {
        std::cout << "The given pattern could not be found within the base string using the KMP algorithm.\n";
        return 0;
    }
    else if(kIndex.size() == 1){
        std::cout << "Using the Knuth-Morris-Pratt algorithm it is found that the pattern appears at index " << kIndex[0]<< ".\n";
        std::cout << "This program looped a total of " << KMP.fi_efficiency() + KMP.spt_efficiency() << " times to find this.\n";
        std::cout << KMP.spt_efficiency() << " of these loops occurred while creating the Suffix Prefix Table while the other " << KMP.fi_efficiency() << " loops occurred while finding the indexes in which the pattern appears.\n";
        std::cout << "This algorithm took " << KMP.get_runTime() << " seconds to run.\n";
    }
    else{
        std::cout << "Using the Knuth-Morris-Pratt algorithm it is found that the pattern appears at indexes ";
        //print all indexes where the pattern was found
        for(int i = 0; i < kIndex.size(); i++){
            std::cout << kIndex[i];
            if(i == kIndex.size()-1){
                std::cout << ".\n";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "This program ran a total of " << KMP.fi_efficiency() + KMP.spt_efficiency() << " times to find this.\n";
        std::cout << KMP.spt_efficiency() << " of these loops occurred while creating the Suffix Prefix Table while the other " << KMP.fi_efficiency() << " loops occurred while finding the indexes in which the pattern appears\n";
    }

    //have to only perform this once to ensure number of runs for efficiency is correct
    std::vector<int> bmIndex = BM.findIndex(find);

    //state indexes found
    if(bmIndex.size() == 1){
        std::cout << "Using the Boyer-Moore algorithm it is found that the pattern appears at index " << bmIndex[0]<< ".\n";
        std::cout << "This program ran a total of " << BM.get_efficiency() << " times to find this.\n";
    }
    else{
        std::cout << "Using the Boyer-Moore algorithm it is found that the pattern appears at indexes ";
        //print all indexes where the pattern was found
        for(int i = 0; i < bmIndex.size(); i++){
            std::cout << bmIndex[i];
            if(i == bmIndex.size()-1){
                std::cout << ".\n";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "This program ran a total of " << BM.get_efficiency() << " times to find this.\n";
    }

    return 0;

}