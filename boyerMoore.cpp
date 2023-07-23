#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string base){

}
boyerMoore::~boyerMoore(){

}

void GoodSuffixShiftCase1(int *shift, int *bpos, char *pattern){
    int patSize = pat.size();
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
    }
}
void GoodSuffixShiftCase2(int *shift, int *bpos, char *pattern){
    int patSize = pat.size();
    int bpos = bposArr[0];
    for(int i=0; i<=patSize; i++){
        if(shift[i]==0){
            shift[i] = bpos;
        }
        if (i == bpos){
            bpos=bposArr[bpos];
        }
    }
}


std::vector<int> boyerMoore::BadCharacterHeur(std::string str, std::string pat){
    //Start runtimer
    std::chrono::time_point<std::chrono::system_clock> begin,end;
    begin = std::chrono::system_clock::now();

    int strSize=str.size();
    int patSize=pat.size();

    int BadCharacter[256];
    std::vector<int> indexes;
    
    for (int i=0; i<strSize;i++){
        BadCharacter[i]=-1;
        this->BadCharRuns++;
    }

    for (int i=0; i<patSize;i++){
        BadCharacter[pat[i]]=i;
        this->BadCharRuns++;

    }

    for (int i=0; i<=(strSize-patSize);){
        int j=patSize-1;

        while(j>=0 && pat[j]==str[i+j]){
            j=j-1;
        }

        if (j<0){
            indexes.push_back(i);
            if (i+patSize<strSize){
                i=i+patSize-BadCharacter[str[i+patSize]];
            }
            else{
                i=i+1;
            }
        }
        else{
            if (1>j-BadCharacter[str[i+j]]){
                i=i+1;
            }
            else{
                i=i+(j-BadCharacter[str[i+j]]);
            }
        }
        this->BadCharRuns++;

    }
    end = std::chrono::system_clock::now();
    this->runTime = end-begin;
    return indexes;
}



std::vector<int> boyerMoore::GoodCharacterHeur(std::string text, std::string pat){
    int patSize = pat.size();
    int strSize= str.size();
    int badChar[256];
    BadCharacterHeur(pat, BadCharacter);
    int bpos[patSize + 1];
    int shiftArr[patSize + 1];
    for (int i = 0; i < patSize + 1; i++){
        shiftArr[i] = 0;
    }
    GoodSuffixShiftCase1(shiftArr, bpos, pat);
    GoodSuffixShiftCase1(shiftArr, bpos, pat);
    int shift = 1;
    std::vector<int> region; //List of indexes where the pattern appears.
    bool found = 0; //used to keep track if at least one match has been found.
    while(shift <= (strSize - patSize)){
        int patIndexes = patSize - 1;
        while(patIndexes >= 0 && pat[patIndexes] == text[shift + patIndexes]){
            patIndexes--;
        }
        if (patIndexes<0){
            region.push_back(shift);
            found = 1;
            int tempBadCharacterShift = 1;
            if (shift + patternLength < textLength){
                tempBadCharacterShift = patSize-BadCharacter[text[shift + patSize]];
            } 
            shift += std::max(shiftArr[0],tempBadCharacterShift);
        }
        else{
            shift += std::max(shiftArr[patIndexes+1], patIndexes-BadCharacter[text[shift+patIndexes]]);
        }
    }
    std::pair<bool, std::vector<int>> returnVal;
    returnVal.first = found;
    returnVal.second = region;
    return returnVal;
}



std::vector<int> boyerMoore::findIndex(std::string find){


}
int boyerMoore::compare(std::string pattern){

}
int boyerMoore::get_efficiency(){
    return this->Runs;
}
