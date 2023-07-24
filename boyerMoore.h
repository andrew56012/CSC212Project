#include <vector>
#include <string>
#include <utility>
#include <chrono>


class boyerMoore{

private:
    int Runs=0;
    std::chrono::duration<double> runTime;
    std::string base;

public:
    //constructor
    boyerMoore(std::string given);
    //deconstructor
    ~boyerMoore();

    //Used to look for pattern in base through indexes
    //returns amount of time it took to find the index by tracking runs
    int get_efficiency();
    //Bad character heuristic approach function
    void BadCharacterHeur(int BadCharacters[],std::string pat);
    //
    void GoodSuffixShiftCase1(std::vector<int> shift, std::vector<int> bpos, std::string pattern);
    //
    void GoodSuffixShiftCase2(std::vector<int> shift, std::vector<int> bposArr, std::string pattern);
    std::vector<int> findIndex(const std::string& text, const std::string& pat);
    int get_loops();
    double get_runTime();

};
