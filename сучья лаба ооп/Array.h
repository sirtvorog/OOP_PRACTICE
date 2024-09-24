#define _CRT_SECURE_NO_WARNINGS
#ifndef OOPPRACTICE_ARRAY_H
#define OOPPRACTICE_ARRAY_H
#include "number.h"

class Array{

    private:
        int len;
        number *arr;

    public:
        Array(int len = 0);
        ~Array();  
        int getLength();
        void fillArray();
        bool changeArrayLength(int newLen);
        bool changeElement(int index, number value);
        void printArray();
        number middleValueArray();
        number skoArray();
        void sortArray(bool up);
};

#endif //OOPPRACTICE_NUMBER_H