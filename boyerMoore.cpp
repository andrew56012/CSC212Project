#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string base){

}
boyerMoore::~boyerMoore(){

}

std::vector<int> boyerMoore::findIndex(std::string find){
    int PatLength = pat.size();
    int TxtLength = txt.size();
    int BadCharacter[256];
    BadCharacterHeur(pat, PatLength, BadCharacter);

    int Pos[PatLength + 1];
    int shiftArr[Patlength+1];
    for(int i=0){
        shiftArr[i] = 0;
    }

}
int boyerMoore::compare(std::string pattern){

}
int boyerMoore::get_efficiency(){
    return this->Runs;
}
