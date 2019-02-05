#include <fstream>
#include "functions.h"
#include "events.h"
#include "variables.h"
#include <string>
#include <vector>


void saveToFile(const std::string &filename){
    std::vector<int> variablesValue = {
        probNum, atmoPc, gravPc, resoPc,
        watePc, tempPc, sciPc, culPc,
        lanPc, conPc, human
    };
    std::ofstream outputFile(filename);



    for (int i = 0; i != 2; ++i){
        outputFile << vari
    }

}