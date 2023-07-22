#include <vector>
#include <string>
#include <chrono>

class regularSS {
public:
    regularSS();
    std::vector<int> search(const std::string& text, const std::string& pattern);
    std::chrono::milliseconds getExecutionTime() const;
    int getLoopCount() const;

private:
    std::vector<int> index;
    int loopCount;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};
