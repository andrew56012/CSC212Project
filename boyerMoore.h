#include <vector>
#include <string>
#include <utility>
#include <chrono>


class boyerMoore{

private:
    int Runs=0;
    int preRuns=0;
    std::chrono::duration<double> runTime;
    std::string base;

public:
    //constructor
    boyerMoore(std::string given);
    //deconstructor
    ~boyerMoore();

    //Used to look for pattern in base through indexes
    //returns amount of loops it took to find the index by tracking runs
    int get_Searchefficiency();
    //returns amount of loops taken during preprocessing
    int get_Processefficiency();
    //Bad character heuristic approach function
    void BadCharacterHeur(int BadCharacters[],std::string pat);
    //Stronger Good heuristic approach function
    void GoodSuffixShiftCase1(std::vector<int> shift, std::vector<int> bpos, std::string pattern);
    //Weaker Good heuristic approach function
    void GoodSuffixShiftCase2(std::vector<int> shift, std::vector<int> bposArr, std::string pattern);
    //implements both heuristics to search for patter in string
    std::vector<int> findIndex(const std::string& text, const std::string& pat);
    //returns runtime of algorithm
    double get_runTime();

};
