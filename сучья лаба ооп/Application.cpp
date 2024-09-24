#include "Application.h"
#include "Array.h"
#include "iostream"
#include "windows.h"
using namespace std;


Application::Application() {

}


void Application::menu() {
    cout << "\n\n";
    cout << "1) create array\n";
    cout << "2) fill array\n";
    cout << "3) change array length\n";
    cout << "4) print array elements\n";
    cout << "5) calculate average\n";
    cout << "6) calculate <<CKO>>\n";
    cout << "7) sort array\n";
    cout << "8) change element\n";
    cout << "0) exit\n\n";
}

int Application::exec() {
    unsigned char task;
    int len, newLen, index, sortchoise;
    number value;
    Array* arr = new Array(0);

     while(true){
        menu();
        cout << "choose task: ";
        cin >> task;

        switch (task){

            case '0': {
                return 0;
            }

            case '1': {
                cout << "Enter array length: "; cin >> len;
                arr = new Array(len);
               
               break;
            }

            case '2': {
                arr->fillArray();
                cout << "\nArray is filled\n";
                break;
            }

            case '3': {
                cout << "Enter new array length: "; cin >> newLen;
                
                arr->changeArrayLength(newLen);
                
                arr->printArray();

                break;
            }

            case '4': {
                arr->printArray();

                break;
            }

            case '5': {
                cout<<"\n\nArithmetic mean: "<<arr->middleValueArray()<<"\n";
                break;
            }

            case '6': {
                cout << "\n\nCKO: " << arr->skoArray() << "\n";
                break;
            }

            case '7': {
                cout << "\n\nDo you want to sort the array in ascending or descending order?\n 1. Ascending\n 0.Descending\n\nYour choise: ";
                cin >> sortchoise;
                arr->sortArray(sortchoise);

                arr->printArray();
                break;
            }

            case '8': {
                cout << "\n\nEnter the index of the element you want to change: ";
                cin >> index;
                cout << "\n\nEnter the new value of the element: ";
                cin >> value;
                arr->changeElement(index, value);
                break;
            }

            default: {
                cout << "\nWrong task!\n";
                break;
            }
        }
     }
}