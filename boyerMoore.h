#include <vector>
#include <string>
#include <utility>

class boyerMoore{

private:
    std::string base;
    std::string find;
    int Runs;
    int Index;

public:
    //constructor
    boyerMoore(std::string base);
    //deconstructor
    ~boyerMoore();

    //Used to look for pattern in base through indexes
    std::vector<int> findIndex(std::string find);
    //helper function to find where to skip indexes too after a break in the pattern is found
    int compare(std::string pattern);
    //returns amount of time it took to find the index by tracking runs
    int get_efficiency();

};
