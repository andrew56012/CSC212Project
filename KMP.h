#include <vector>
#include <string>
#include <utility>


class KMP{

private:
    std::string base;
    std::string find;
    int Runs;
    int Index;

public:
    //constructor
    KMP(std::string base);
    //deconstructor
    ~KMP();

    //Used to look for pattern in base through indexes
    int findIndex(std::string find);
    //helper function to find where to skip indexes too after a break in the pattern is found
    int skipTo(std::string pattern);
    //returns amount of time it took to find the index by tracking runs
    int get_efficiency();

};