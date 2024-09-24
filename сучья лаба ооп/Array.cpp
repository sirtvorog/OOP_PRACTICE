#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <iostream>
using namespace std;

Array::Array(int len){
    if(len < 0){
        this->len = 0;
        cout << "\n\nIncorrect length specified\n";
    }
    this->len = len;
    arr = new number[len];
}

Array::~Array(){
    delete []arr;
}

int Array::getLength() {
    return this->len;
}

void Array::fillArray() {

    cout << "\n\nEnter " << len << " array elements:\n";
    for (int i = 0; i < len; i++){
        cin >> *(arr + i);
    }

}

bool Array::changeArrayLength(int newLen) {

    if (newLen < 0) {

        cout << "\n\nIncorrect length!!\n";
            return 0;
    }

    number* changedArray = new number[newLen];

    for (int i = 0; i < newLen;i++) {

        *(changedArray + i) = *(arr + i);
    }

    len = newLen;
    delete [] arr;
    arr = changedArray;
    return 1;  

}

bool Array::changeElement(int index, number value){
    if(index <= 0 && index >= len){
        return false;
    }
    *(arr + index) = value;
    return true;
}


void Array::printArray(){
    cout << "\n\nYour array: \n\n";
    for(int i = 0; i < len; i++){
        cout << *(arr + i) << " ";
    }
    cout << "\n\n";   
}


number Array::middleValueArray(){
    number middleValue = 0;
    if(len == 0){
        return false;
    }    
    for(int i = 0; i < len; i++){
        middleValue += *(arr + i);
    }
    middleValue = (middleValue / ((number)len));
    return middleValue;
}


number Array::skoArray(){
    number average = middleValueArray();
    number sko = 0;
    if(len == 0){
        return false;
    }
    for(int i = 0; i < len; i++){
        sko += pow(*(arr + i) - average, 2);
    }
    sko = (sko / ((number)(len - 1)));
    sko = pow(sko, 0.5);
    return sko;
}



// shaker sort
void Array::sortArray(bool up) {

    if (up) {
        for (int i = 0;i < (len / 2);i++) {

            for (int i = 0;i < len - 1;i++) {
                if (*(arr + i) > *(arr + i + 1))
                    swap(*(arr + i), *(arr + i + 1));
            }

            for (int i = len - 1;i > 0;i--) {
                if (*(arr + i) < *(arr + i - 1))
                    swap(*(arr + i), *(arr + i - 1));
            }
        }
    }

    else {
        
        for (int i = 0;i < (len / 2);i++) {

            for (int i = 0;i < len - 1;i++) {
                if (*(arr + i) < *(arr + i + 1))
                    swap(*(arr + i), *(arr + i + 1));
            }

            for (int i = len-1;i >0 ;i--) {
                if (*(arr + i) > *(arr + i - 1))
                    swap(*(arr + i), *(arr + i - 1));
            }
        }
    }

}
