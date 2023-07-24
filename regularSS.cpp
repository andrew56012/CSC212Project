#include "regularSS.h"

regularSS::regularSS() : loopCount(0) {}

std::vector<int> regularSS::search(const std::string& text, const std::string& pattern) {
    //Start runtimer
    std::chrono::time_point<std::chrono::system_clock> begin,end;
    begin = std::chrono::system_clock::now();
    // Reset variables before starting the search
    index.clear();
    loopCount = 0;

    if (pattern.empty()) {
        // Pattern is empty, return an empty result
        return index;
    }

    int textL = text.length();
    int patternL = pattern.length();

    for (int i = 0; i <= textL - patternL; ++i) {
        int j;
        for (j = 0; j < patternL; ++j) {
            loopCount++; // Increment loop counter
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternL) {
            index.push_back(i);
        }
    }
    end = std::chrono::system_clock::now();
    this->startTime = end-begin;

    return index;
}

double regularSS::getExecutionTime() const {

    return this->startTime.count();

}

int regularSS::getLoopCount() const {
    return loopCount;
}
