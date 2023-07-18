#include "regularSS.h"

std::vector<int> StringSearch::search(const std::string& text, const std::string& pattern) {
    std::vector<int> index;

    if (pattern.empty()) {
        // Pattern is empty, return an empty result
        return index;
    }

    int textL = text.length();
    int patternL = pattern.length();

    for (int i = 0; i <= textL - patternL; ++i) {
        int j;
        for (j = 0; j < patternL; ++j) {
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
