#include <fstream>
#include "functions.h"
#include "events.h"
#include "variables.h"
#include <string>
#include <vector>



void saveToFile(const std::string &filename){
    int variablesValue[varSize] = {
        probNum, atmoPc, gravPc, resoPc,
        watePc, tempPc, sciPc, culPc,
        lanPc, conPc, human, power, resourceIter};

    std::ofstream outputFile(filename);

    for (int i = 0; i != varSize; ++i){
        outputFile << variablesValue[i] << " ";

    }
    outputFile.close();
    std::cout << "Succ" << std::endl;

}

void loadFile(const std::string &filename, int (&arr)[varSize]){
    std::ifstream inputFile(filename);

    int val, cnt;
    while(inputFile >> val){
        *arr[cnt] = val;
        ++cnt;
    }

    inputFile.close();
    std::cout << "Super Succ" << std::endl;
}