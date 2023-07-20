#include <vector>
#include <string>

class regularSS {
private:
    std::vector<int> index;
    clock_t startTime;
    int loopCount;

public:
    regularSS();

    std::vector<int> search(const std::string& text, const std::string& pattern);

    clock_t getExecutionTime() const;
    int getLoopCount() const;
};