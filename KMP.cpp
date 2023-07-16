#include "KMP.h"

KMP::KMP(std::string given){

    this -> base = given;

}
KMP::~KMP(){

}

void KMP::createSPT(std::string pattern){

    //Create Suffix Prefix table
    //(Keeps track of the index of the largest matching prefix suffix pair in a given pattern based on the index of the pattern at any time)

    int arr[pattern.size()];
    this->SPTable = &arr[0];

    //Create iterators to use in table creation
    int i = 0;
    int j = 1;

    //The first cell of SPTable will always be equal to 0
    *(this->SPTable) = 0;

    //run until the entire table is full
    while(j < pattern.size()){

        //if the letter at i matches the letter at j fill the SPTable index of j with the number i (says i is the largest matching index for a pattern that long)
        if(pattern[i] == pattern[j]){
            *(this->SPTable+j) = i+1;
            i++;
            j++;
        }
        //If the letter did not match and the i is checking from the first index make j equal to 0 to say that it has no match
        else if(i == 0){
            *(this->SPTable+j) = 0;
            j++;
        }
        //If the letter did not match and the i is not equal to 0 then set i equal to the index that is held in the table before the current i and run again.
        else{
            i = *(this->SPTable+i-1);
        }
        //keep track of efficiency
        this->sptRuns++;
    }
}

std::vector<int> KMP::findIndex(std::string find){
    //holds all indexes where the pattern is found
    std::vector<int> indexes;
    int curr = 0;
    int start = 0;

    //Make Suffix Prefix table
    createSPT(find);

    //checks to see if the pattern is longer than the length left to check and if it is return the indexes as they have all been found
    while((this->base.size()-start) >= find.size()){

        //if the pattern has been successfully found add the index i to the found patterns list
        if(curr == find.size()){
            indexes.push_back(start);
            start++;
            curr = 0;
        }

        //check if patterns match. If not activate helper function to see where to start search from next
        if(this->base[curr+start] == find[curr]){
            curr++;
        }
        else{
            start += skipTo(curr,start);
        }
        //keep track of efficiency
        this->fiRuns++;
    }

    return indexes;

}

int KMP::skipTo(int& curr, int start){

    //If there is no greatest SP return 1 to make start increase by 1 like a normal search
    if(curr==0){
        curr = 0;
        return 1;
    }
    else if(*(this->SPTable+curr-1) == 0){
        curr = 0;
        return 1;
    }

    //makes start equal to where the break was found minus the greatest prefix suffix
    start = curr-*(this->SPTable+curr-1);

    //set the checker equal to the given index in the SPT(Is the location of greatest prefix end)
    curr = *(this->SPTable+curr-1);
    return start;

}
int KMP::fi_efficiency(){
    return this-> fiRuns;
}
int KMP::spt_efficiency(){
    return this-> sptRuns;
}