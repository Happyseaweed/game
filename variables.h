#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <limits>
#include <term.h>

int probNum = 10; // 0
int atmoPc = 100; // 1
int gravPc = 100; // 2
int resoPc = 100; // 3
int watePc = 100; // 4
int tempPc = 100; // 5
int sciPc = 100; // 6
int culPc = 100; // 7
int lanPc = 100; // 8
int conPc = 100; // 9
int human = 1000; // 10
int power = 100;
int resourceIter = 0;


int varList[11] = {probNum, atmoPc, gravPc, resoPc, watePc, tempPc, sciPc, culPc, lanPc, conPc, human};



std::string atmoCon[] = {"Non Breathable", "Corrosive", "Toxic", "Contains Oxygen", "Breathable", "None"};
std::string gravCon[] = {"Very Low", "Low", "Similar to Earth", "High", "Very High", "None"};
std::string resoCon[] = {"Rare", "Limited", "Uncommon", "Moderate", "Rich", "None"};
std::string wateCon[] = {"Scarce", "Rivers", "Very little", "Oceans", "Ice Caps", "None"};
std::string tempCon[] = {"Near Absolute Zero", "Very Cold", "Cold", "Moderate", "Hot", "Very Hot"};
