#include "boyerMoore.h"

boyerMoore::boyerMoore(std::string base){

}
boyerMoore::~boyerMoore(){

}

void strongersuffix(int *shift, int *borderpos, char *pattern, int alength)
{
	int i=alength;
	int j=alength+1;
	borderpos[i]=j;
	while(i>0)
	{
		while(j<=a && pattern[i-1] != pattern[j-1])
		{
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
void weaker suffix(int *shift, int *bpos, char *pattern, int alength)
{
	int j = borderpos[0];
	for(int i=0; i<=alength; i++)
	{
		if(shift[i]==0)
			shift[i] = j;
		if (i==j)
			j = bpos[j];
	}
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
