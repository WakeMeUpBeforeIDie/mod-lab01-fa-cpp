// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype> 

unsigned int faStr1(const char *str) {
    if (!str) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (inWord && !hasDigit) count++;
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (isdigit(str[i])) hasDigit = true;          
        }
    }
    if (inWord && !hasDigit) count++; 
    return count;
}

unsigned int faStr2(const char *str) {
    if (!str) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool valid = true;
    bool firstChar = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (inWord && valid) count++;   
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
                if (!isupper(str[i])) valid = false;                
                firstChar = false;
            } else {
                if (!islower(str[i])) valid = false;               
            }
        }
    }
    if (inWord && valid) count++;
    return count;
}

unsigned int faStr3(const char *str) {
    if (!str) return 0;
    int totalLength = 0;
    int wordCount = 0;
    bool inWord = false;
    int currentWordLength = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (inWord) {
                totalLength += currentWordLength;
                wordCount++;
                currentWordLength = 0;
                inWord = false;
            }
        } else {
            if (!inWord) {
                inWord = true;
                currentWordLength = 1;
            } else {
                currentWordLength++;
            }
        }
    }
    if (inWord) {
        totalLength += currentWordLength;
        wordCount++;
    }
    if (wordCount == 0) return 0;
    double average = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(average + 0.5);
}
