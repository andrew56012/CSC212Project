#include <vector>
#include <string>
#include <utility>
#include <chrono>


class KMP{

private:
    std::string base;
    int fiRuns = 0;
    int sptRuns = 0;
    int* SPTable;
    std::chrono::duration<double> runTime;

public:
    //constructor
    KMP(std::string given);
    //deconstructor
    ~KMP();

    //Creates the suffix prefix table which keeps track of the index of the greatest matching prefix and suffix depending upon index
    void createSPT(std::string pattern);
    //Used to look for pattern in base through indexes
    std::vector<int> findIndex(std::string find);
    //helper function to find where to skip indexes too after a break in the pattern is found
    int skipTo(int& curr,int start);
    //returns amount of time it took to find the index by tracking runs
    int fi_efficiency();
    //returns amount of times it took to make SP Table
    int spt_efficiency();
    //return runtimr
    double get_runTime();

};