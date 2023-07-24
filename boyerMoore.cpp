#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string given){
    this -> base = given;
}

boyerMoore::~boyerMoore(){

}

void boyerMoore::GoodSuffixShiftCase1(std::vector<int> shift, std::vector<int> bpos, std::string pattern){
    int patSize = pattern.size();
    int tempstrSize = patSize;
    int j = patSize + 1;

    bpos[patSize] = j; //Set borderPos[patternLength] to patternLength+1.
    while(tempstrSize > 0) {
        while(j <= patSize && pattern[tempstrSize - 1] != pattern[j -1 ]){
            if (shift[j]==0){
                shift[j] = j-tempstrSize;
            }
            j = bpos[j];
        }
        tempstrSize--;
        j--;
        bpos[tempstrSize] = j;
        this->Runs++;
    }
}

void boyerMoore::GoodSuffixShiftCase2(std::vector<int> shift, std::vector<int> bposArr, std::string pattern){
    int patSize = pattern.size();
    int bpos = bposArr[0];
    for(int i=0; i<=patSize; i++){
        if(shift[i]==0){
            shift[i] = bpos;
        }
        if (i == bpos){
            bpos=bposArr[bpos];
        }
        this->Runs++;
    }
}


void boyerMoore::BadCharacterHeur(int BadCharacters[],std::string pat){

    int patSize=pat.size();

    for (int i=0; i<256;i++){
        BadCharacters[i]=-1;
        this->Runs++;
    }

    for (int i=0; i<patSize;i++){
        BadCharacters[pat[i]]=i;
        this->Runs++;
    }
}

std::vector<int> boyerMoore::findIndex(const std::string& text, const std::string& pat) {
    std::chrono::time_point<std::chrono::system_clock> begin,end;
    begin = std::chrono::system_clock::now();
    int patSize = pat.size();
    int strSize = text.size();
    int BadCharacters[256];
    BadCharacterHeur(BadCharacters, pat);

    std::vector<int> bpos(patSize + 1, 0);
    std::vector<int> shiftArr(patSize + 1, 0);

    GoodSuffixShiftCase1(shiftArr, bpos, pat);
    GoodSuffixShiftCase2(shiftArr, bpos, pat);

    std::vector<int> region; // List of indexes where the pattern appears.
    bool found = false;     // Used to keep track if at least one match has been found.
    int shift = 0;

    while (shift <= (strSize - patSize)) {
        int patIndex = patSize - 1;
        while (patIndex >= 0 && pat[patIndex] == text[shift + patIndex]) {
            patIndex--;
            this->Runs++;
        }
        if (patIndex < 0) {
            region.push_back(shift);
            found = true;
            int tempBadCharacterShift = 1;
            if (shift + patSize < strSize) {
                tempBadCharacterShift = patSize - BadCharacters[text[shift + patSize]];
            }
            shift += std::max(shiftArr[0], tempBadCharacterShift);
        } else {
            shift += std::max(shiftArr[patIndex + 1], patIndex - BadCharacters[text[shift + patIndex]]);
        }
        this->Runs++;
    }

    if (found) {
        end = std::chrono::system_clock::now();
        this->runTime = end-begin;
        return region;
    } else {
        end = std::chrono::system_clock::now();
        this->runTime = end-begin;
        return {}; // Empty vector if pattern not found.
    }

}

int boyerMoore::get_efficiency(){
    return this->Runs;
}
double boyerMoore::get_runTime(){
    return this-> runTime.count();
}
