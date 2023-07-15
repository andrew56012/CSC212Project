#include "KMP.h"

KMP::KMP(std::string given){

    this -> base = given;

}
KMP::~KMP(){

}

std::vector<int> KMP::findIndex(std::string find){
    //holds all indexes where the pattern is found
    std::vector<int> indexes;
    int curr = 0;
    int start = 0;
    int iter = 0;

    //checks to see if the pattern is longer than the length left to check and if it is return the indexes as they have all been found
    while((this->base.size()-start) > find.size()){

        //if the pattern has been successfully found add the index i to the found patterns list
        if(curr == find.size()-1){
            indexes.push_back(iter);
        }

        //check if patterns match. If not activate helper function to see where to start search from next
        if(this->base[iter] == find[curr]){
            iter++;
            curr++;
        }
        else{
            start = skipTo(find);
            iter = start;
            curr = 0;
        }
    }

    return indexes;

}
int KMP::skipTo(std::string pattern){

}
int KMP::get_efficiency(){
    return this-> Runs;
}