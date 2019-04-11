#include <fstream>
#include "functions.h"
#include "events.h"
#include "variables.h"
#include <string>
#include <iterator>
#include <vector>



void saveToFile(const std::string &filename){
    std::ofstream outputFile(filename);

    for (int i = 0; i != varSize; i++){
        outputFile << varList[i] << " ";

    }
    outputFile.close();
    std::cout << "Succ" << std::endl;

}

void loadFile(const std::string &filename){
    std::ifstream inputFile(filename);//Takes in file as input
    int val = 0;
    int n = 0;
    while (inputFile >> val){
        varList[n] = val;
        n++;
    }
    inputFile.close();
    std::cout << "Super Succ" << std::endl;
}