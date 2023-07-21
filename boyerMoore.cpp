#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string base){

}
boyerMoore::~boyerMoore(){

}

void strongersuffix(int *shift, int *borderpos, char *pattern, int alength){
	int i=alength;
	int j=alength+1;
	borderpos[i]=j;
	while(i>0){
		while(j<=a && pattern[i-1] != pattern[j-1]){
			if (shift[j]==0){
				shift[j] = j-i;
            		}
		j = borderpos[j];
		}
	i--;
        j--;
	bpos[i] = j;
	}
}
void weakersuffix(int *shift, int *bpos, char *pattern, int alength){
	int j = borderpos[0];
	for(int i=0; i<=alength; i++){
		if(shift[i]==0)
		shift[i] = j;
		if (i==j)
		j = bpos[j];
	}
}


void BadCharacterHeur(int badchar[256]) {
    for (int i = 0; i < 256; i++) {
       BadCharacterHeur[i] = ;
    	}
    for (int i = 0; i < ; i++) {
        BadCharacterHeur
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
