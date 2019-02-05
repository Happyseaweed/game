#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "variables.h"

void planet (int scan[], std::string atmoCon[], std::string gravCon[], std::string resoCon[], std::string wateCon[], std::string tempCon[]) {
    std::cout << "\nYou arrive at a planet: \n" << std::endl;
    srand(time(0));
    if (varList[1] == 100){
        std::cout << "[Atmosphere]: " << atmoCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Atmosphere]:"; usleep(10000); std::cout << " Scan Failed" << std::endl; 
    }
    if (varList[2] == 100){
        std::cout << "[Gravity]: " << gravCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Gravity]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
    }
    if (varList[3] == 100){
        std::cout << "[Resources]: " << resoCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Resources]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
    }
    if (varList[4] == 100){
        std::cout << "[Water]: " << wateCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Water]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
    }
    if (varList[5] == 100){
        std::cout << "[Temperature]: " << tempCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Temperature]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
    }
}

void land(){
    char land;
    std::cout << "\n[Y]Land    [N]Skip" << std::endl;
    std::cin >> land;
    if (tolower(land) == 'y'){
        std::cout << "Working" << std::endl;
        usleep(1000000);
        std::string planetName;
        std::cout << "C1000 Starts orbiting the planet, and eventually it starts falling into the planet, through the atmosphere and crashes down on the planet, the colinists have named the planet: " << std::endl;
        getline(std::cin, planetName);
        std::cout << "the planet is called: " + planetName << std::endl;

    }
    else if (tolower(land) == 'n'){
        
    }
}


void probe(int probNum){
    std::cout << "     Surface Probes left: " << varList[0] << std::endl;
}

void atmo(int atmoPc){
    std::cout << "Atmosphere Scanner: " << varList[1] << '%'<< std::flush;
}

void gravity(int gravPc){
    std::cout << "      Gravity Scanner: " << varList[2] << '%' << std::endl;
}

void reso(int resoPc){
    std::cout << "Resource Scanner: " << varList[3] << '%' << std::flush;
}

void water(int watePc){
    std::cout << "        Water Scanner: " << varList[4] << '%' << std::endl;
}

void temperature(int tempPc){
    std::cout << "Temperature Scanner: " << varList[5] << '%' << std::flush;
}

void science(int sciPc){
    std::cout << "     Scientific Databases: " << varList[6] << '%' << std::endl;
}

void culture(int culPc){
    std::cout << "Cultural Databases: " << varList[7] << '%' << std::flush;
}

void landing(int lanPc){
    std::cout << "\n\nLanding Status: " << varList[8] << '%' << std::endl;
}

void construction(int conPc){
    std::cout << "Construction Status: " << varList[9] << '%' << std::flush;
}



//Misc Functions:

void slow_print(const std::string message){
    for (const char c : message){
        std::cout << c << std::flush;
        usleep(10000);
    }
}

int randomNumberGenerator(){
    srand(time(0));
    int randNumber = 1 + (rand()%10);
    return randNumber;
}
