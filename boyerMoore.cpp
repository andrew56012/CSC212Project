#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string given){
    this -> base = given;
}

boyerMoore::~boyerMoore(){

}

//function to compute stronger good suffix
void boyerMoore::GoodSuffixShiftCase1(std::vector<int> shift, std::vector<int> bpos, std::string pattern){

    //the shift and borderPos is an array with size equal to the pattern + 1
    int patSize = pattern.size();
    int tempstrSize = patSize;
    int j = patSize + 1;

    //Set borderPos[patternLength] to patternLength+1.
    bpos[patSize] = j;
    while(tempstrSize > 0) {
        //if the spot at the pattern does not equal the pattern
        while(j <= patSize && pattern[tempstrSize - 1] != pattern[j -1 ]){
            //if shift is 0
            if (shift[j]==0){
                //shift will be j-temp
                shift[j] = j-tempstrSize;
            }
            j = bpos[j];
            //count each time loop runs
            preRuns++;
        }
        tempstrSize--;
        j--;
        bpos[tempstrSize] = j;
        //count each time loop runs
        preRuns++;
    }
}

//function to compute weaker good suffix
void boyerMoore::GoodSuffixShiftCase2(std::vector<int> shift, std::vector<int> bposArr, std::string pattern){
    int patSize = pattern.size();
    int bpos = bposArr[0];
    for(int i=0; i<=patSize; i++){
        //shift is not set to anything
        if(shift[i]==0){
            //shift is the border position at this location
            shift[i] = bpos;
        }
        //when i is equal to the border position
        if (i == bpos){
            //update the border position
            bpos=bposArr[bpos];
        }
        //count each time loop runs
        this->preRuns++;
    }
}

//function used to preprocess the pattern into a bad characters table
void boyerMoore::BadCharacterHeur(int BadCharacters[],std::string pat){
    // calculate size of the pattern we are searching for
    int patSize=pat.size();

    //Loop sets all elements of the BadCharacters Array to -1
    //Initialized to -1 to show that no characters in the patter have been encountered
    for (int i=0; i<256;i++){
        BadCharacters[i]=-1;
        //count each time loop runs
        this->preRuns++;
    }

    //Loop fills BadCharacters array with rightmost index of each letter in pattern
    for (int i=0; i<patSize;i++){
        BadCharacters[pat[i]]=i;
        //count each time loop runs
        this->preRuns++;
    }
}

//implementation of both heuristics
std::vector<int> boyerMoore::findIndex(const std::string& text, const std::string& pat) {
    //start runtime of algorithm
    std::chrono::time_point<std::chrono::system_clock> begin,end;
    begin = std::chrono::system_clock::now();
    int patSize = pat.size();
    int strSize = text.size();
    //size of all extended ascii characters
    int BadCharacters[256];
    //preprocess bad characters in the patters
    BadCharacterHeur(BadCharacters, pat);

    //vectors to store boarder positions and shifts
    std::vector<int> bpos(patSize + 1, 0);
    std::vector<int> shiftArr(patSize + 1, 0);

    //preprocess stronger and weaker suffixes.
    GoodSuffixShiftCase1(shiftArr, bpos, pat);
    GoodSuffixShiftCase2(shiftArr, bpos, pat);

    //List of indexes where the pattern appears
    std::vector<int> indexes;

    //Used to keep track if at least one match in string and pattern has been found.
    bool found = false;
    int shift = 0;

    //search for patterns in string
    while (shift <= (strSize - patSize)) {
        int patIndex = patSize - 1;
        while (patIndex >= 0 && pat[patIndex] == text[shift + patIndex]) {
            patIndex--;
            //count each time loop runs
            this->Runs++;
        }

        //pattern found at current position
        if (patIndex < 0) {
            //pattern has been found
            found = true;
            //add index to vector
            indexes.push_back(shift);
            //temp var for shift
            int tempBadCharacterShift = 1;
            //calculate bad character shift using characters after matched pattern
            if (shift + patSize < strSize) {
                tempBadCharacterShift = patSize - BadCharacters[text[shift + patSize]];
            }
            shift += std::max(shiftArr[0], tempBadCharacterShift);
        }
        //pattern mismatch so use both good and bad heuristic to determine shift
        else {
            //take the greater of the two and add to the shift
            shift += std::max(shiftArr[patIndex + 1], patIndex - BadCharacters[text[shift + patIndex]]);
        }
        this->Runs++;
    }
    //if there is at least one instance of the pattern found, returns indexes they were found at
    if (found) {
        //end runtime
        end = std::chrono::system_clock::now();
        this->runTime = end-begin;
        return indexes;
    }
    //else no patterns found and empty vector returned.
    else {
        //end runtime
        end = std::chrono::system_clock::now();
        this->runTime = end-begin;
        return {};
    }
}

//returns amount of loops from just searching through string for pattern
int boyerMoore::get_Searchefficiency() {
    return this->Runs;
}

//returns amount of loops from good suffix and bad character preprocessing heuristics
int boyerMoore::get_Processefficiency() {
    return this->preRuns;
}

//returns runtime of algorithm
double boyerMoore::get_runTime(){
    return this-> runTime.count();
}
