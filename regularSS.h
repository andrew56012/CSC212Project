#include <vector>
#include <string>
#include <chrono>

class regularSS {
public:
    regularSS();
    std::vector<int> search(const std::string& text, const std::string& pattern);
    double getExecutionTime() const;
    int getLoopCount() const;

private:
    std::vector<int> index;
    int loopCount;
    std::chrono::duration<double> startTime;
};
