#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string given){
    this -> base = given;
}

boyerMoore::~boyerMoore(){

}

void boyerMoore::GoodSuffixShiftCase1(std::vector<int> shift, std::vector<int> bpos, std::string pattern){ //function to compute stronger good suffix
    int patSize = pattern.size();    //the shift and borderPos is an array with size equal to the pattern + 1 
    int tempstrSize = patSize;
    int j = patSize + 1;

    bpos[patSize] = j; //Set borderPos[patternLength] to patternLength+1.
    while(tempstrSize > 0) {
        while(j <= patSize && pattern[tempstrSize - 1] != pattern[j -1 ]){    //if the spot at the pattern does not equal the pattern
            if (shift[j]==0){   //if shift is 0
                shift[j] = j-tempstrSize;    //shift will be j-temp
            }
            j = bpos[j];
        }
        tempstrSize--;
        j--;
        bpos[tempstrSize] = j;
        this->Runs++;
    }
}

void boyerMoore::GoodSuffixShiftCase2(std::vector<int> shift, std::vector<int> bposArr, std::string pattern){ //function to compute weaker good suffix
    int patSize = pattern.size();
    int tempstrSize = patSize;
    int patSize = pattern.size();
    int bpos = bposArr[0];
    for(int i=0; i<=patSize; i++){
        if(shift[i]==0){ //shift is not set to anything
            shift[i] = bpos; //shift is the border position at this location
        }
        if (i == bpos){    //when I is equal to the border position
            bpos=bposArr[bpos];    //update the border position
        }
        this->Runs++;
    }
}


void boyerMoore::BadCharacterHeur(int BadCharacters[],std::string pat){ //function to compute bad suffix
    int patSize = pattern.size();
    int tempstrSize = patSize;

    int patSize=pat.size();

    for (int i=0; i<256;i++){
        BadCharacters[i]=-1;    //initialize elements
        this->Runs++;
    }

    for (int i=0; i<patSize;i++){
        BadCharacters[pat[i]]=i;    //record rightmost occurance of each character in pattern
        this->Runs++;
    }
}

std::vector<int> boyerMoore::findIndex(const std::string& text, const std::string& pat) { //implementation of both heuristics
    std::chrono::time_point<std::chrono::system_clock> begin,end;
    begin = std::chrono::system_clock::now();
    int patSize = pat.size();
    int strSize = text.size();
    int BadCharacters[256];
    BadCharacterHeur(BadCharacters, pat);

    std::vector<int> bpos(patSize + 1, 0);        //array to store boarder positions
    std::vector<int> shiftArr(patSize + 1, 0);    //array to store shift

    GoodSuffixShiftCase1(shiftArr, bpos, pat);    //compute stronger good suffix
    GoodSuffixShiftCase2(shiftArr, bpos, pat);    //compute weaker good suffix

    std::vector<int> region; //List of indexes where the pattern appears
    bool found = false;     //Used to keep track if at least one match has been found
    int shift = 0;

    while (shift <= (strSize - patSize)) { //main pattern searching loop
        int patIndex = patSize - 1;
        while (patIndex >= 0 && pat[patIndex] == text[shift + patIndex]) {
            patIndex--;
            this->Runs++;
        }
        if (patIndex < 0) {   //pattern found at current position
            region.push_back(shift);    
            found = true;
            int tempBadCharacterShift = 1;
            if (shift + patSize < strSize) {    //calculate bad character shift using characters after matched pattern
                tempBadCharacterShift = patSize - BadCharacters[text[shift + patSize]];
            }
            shift += std::max(shiftArr[0], tempBadCharacterShift);
        } else {    //pattern mismatch so use both good and bad heuristic to determine shift
            shift += std::max(shiftArr[patIndex + 1], patIndex - BadCharacters[text[shift + patIndex]]);
        }
        this->Runs++;
    }

    if (found) {
        end = std::chrono::system_clock::now();
        this->runTime = end-begin; //caluclate run time
        return region; //return list of occurances of the pattern in the text
    } else {
        end = std::chrono::system_clock::now();
        this->runTime = end-begin;
        return {}; //return empty vector if pattern isn't found
    }

}

int boyerMoore::get_efficiency(){  //get number of runs performed for efficiency
    return this->Runs;
}
double boyerMoore::get_runTime(){  //get run time of pattern search
    return this-> runTime.count();
}



//we all worked on a shared IDE for the final commits to each file 
