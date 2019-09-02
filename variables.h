#pragma once 

#include <iostream>
#include <string>
#include <unistd.h>
#include <term.h>

const int varSize = 18;

const int probNum = 10; // 0
const int atmoPc = 100; // 1
const int gravPc = 100; // 2
const int resoPc = 100; // 3
const int watePc = 100; // 4
const int tempPc = 100; // 5
const int sciPc = 100; // 6
const int culPc = 100; // 7
const int lanPc = 100; // 8
const int engPc = 100; // 9
const int human = 1000; // 10
const int year = 0; // 11 Amount of years from the start of the exploration
int resourceIndex = 0;//12
const int power = 100; //13

const int atmoIndex = 0;
const int gravIndex = 0;
const int resoIndex = 0;
const int wateIndex = 0;  
const int tempIndex = 0;


int varList[varSize] = {
    probNum, // 0 
    atmoPc, // 1
    gravPc, // 2
    resoPc, // 3
    watePc, // 4
    tempPc, // 5
    sciPc, // 6
    culPc, // 7
    lanPc, // 8
    engPc, // 9
    human, // 10
    year, // 11
    resourceIndex, // 12
    power, // 13
    atmoIndex, // 14
    gravIndex, // 15
    wateIndex, // 16
    tempIndex, // 17
    };

std::string varListNames[11] = {
    "Surface Probes",
    "Atmosphere Scanner",
    "Gravity Scanner",
    "Resource Scanner",
    "Water Scanner",
    "Temperature Scanner",
    "Scientific Database",
    "Cultural Database",
    "Landing Gears",
    "Engine",
    "Cryosleep chambers"
};
//array - start 0
//order - start 1


std::string atmoCon[] = {"Non Breathable", "Corrosive", "Toxic", "Contains Oxygen", "Breathable", "None"};
std::string gravCon[] = {"Almost None", "Very Low", "Low", "Similar to Earth", "High", "Very High"};
std::string resoCon[] = {"Rare", "Limited", "Uncommon", "Moderate", "Rich", "None"}; // determines the refuel amount
                        // +2        +4      +6           +8          +10       +0
                        // 0 1 2 3 4 5
std::string wateCon[] = {"Scarce", "Rivers", "Very little", "Oceans", "Ice Caps", "None"};
std::string tempCon[] = {"Near Absolute Zero", "Very Cold", "Cold", "Moderate", "Hot", "Very Hot"};
