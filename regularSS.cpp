#include "regularSS.h"
#include <ctime>

regularSS::regularSS() : loopCount(0) {}

std::vector<int> regularSS::search(const std::string& text, const std::string& pattern) {
    // Reset variables before starting the search
    index.clear();
    loopCount = 0;

    if (pattern.empty()) {
        // Pattern is empty, return an empty result
        return index;
    }

    startTime = clock();

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

    return index;
}

clock_t regularSS::getExecutionTime() const {
    return clock() - startTime;
}

int regularSS::getLoopCount() const {
    return loopCount;
}