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

}
int boyerMoore::compare(std::string pattern){

}
int boyerMoore::get_efficiency(){
    return this->Runs;
}
