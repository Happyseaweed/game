
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <limits>
#include <term.h>

int probNum = 10;
int atmoPc = 100;
int gravPc = 100;
int resoPc = 100;
int watePc = 100;
int tempPc = 100;
int sciPc = 100;
int culPc = 100;
int lanPc = 100;
int conPc = 100;
int human = 1000;

std::string atmoCon[] = {"Non Breathable", "Corrosive", "Toxic", "Contains Oxygen", "Breathable", "None"};
std::string gravCon[] = {"Very Low", "Low", "Similar to Earth", "High", "Very High", "None"};
std::string resoCon[] = {"Rare", "Limited", "Uncommon", "Moderate", "Rich", "None"};
std::string wateCon[] = {"Scarce", "Rivers", "Very little", "Oceans", "Ice Caps", "None"};
std::string tempCon[] = {"Near Absolute Zero", "Very Cold", "Cold", "Moderate", "Hot", "Very Hot"};