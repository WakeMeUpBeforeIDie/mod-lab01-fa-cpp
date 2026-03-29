// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    for (const char *p = str; *p != '\0'; ++p) {
        if (*p == ' ') {
            if (inWord && !hasDigit) {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (*p >= '0' && *p <= '9') {
                hasDigit = true;
            }
        }
    }
    if (inWord && !hasDigit) {
        ++count;
    }
    return count;
}
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool valid = true;
    bool firstChar = true;
    for (const char *p = str; *p != '\0'; ++p) {
        if (*p == ' ') {
            if (inWord && valid) {
                ++count;
            }
            inWord = false;
            firstChar = true;
            valid = true;
        } else {
            if (!inWord) {
                inWord = true;
                firstChar = true;
                valid = true;
            }
            if (firstChar) {
                if (!(*p >= 'A' && *p <= 'Z')) {
                    valid = false;
                }
                firstChar = false;
            } else {
                if (!(*p >= 'a' && *p <= 'z')) {
                    valid = false;
                }
            }
        }
    }
    if (inWord && valid) {
        ++count;
    }
    return count;
}
unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    bool inWord = false;
    unsigned int currentLength = 0;
    for (const char *p = str; *p != '\0'; ++p) {
        if (*p == ' ') {
            if (inWord) {
                ++wordCount;
                totalLength += currentLength;
                currentLength = 0;
                inWord = false;
            }
        } else {
            if (!inWord) {
                inWord = true;
                currentLength = 0;
            }
            ++currentLength;
        }
    }
    if (inWord) {
        ++wordCount;
        totalLength += currentLength;
    }
    if (wordCount == 0) {
        return 0;
    }
    unsigned int result = (totalLength + wordCount / 2) / wordCount;
    return result;
}
