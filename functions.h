#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "variables.h"
//#include "events.h"


int randomNumberGenerator(){ // generates a random number from 1 to 10
    srand(time(0));
    int randNumber = 1 + (rand()%10);
    return randNumber;
}

//_________________________________________________________________________________________________________________________________________________


void planet (/*std::string atmoCon[], std::string gravCon[], std::string resoCon[], std::string wateCon[], std::string tempCon[], */int &resourceIter) {
    std::cout << "\nYou arrive at a planet: \n" << std::endl;
    srand(time(0));
    int randomScan = randomNumberGenerator();

    if (atmoPc == 100){
        varList[14] = 1 + rand()%5;
        std::cout << "[Atmosphere]: " << atmoCon[varList[14]] << std::endl;
    } else {
        if (randomScan >= 5){
            std::cout << "[Atmosphere]:"; 
            usleep(10000); 
            std::cout << " Scan Failed" << std::endl;
        } else {
            std::cout << "[Atmosphere]: " << atmoCon[varList[14]] << std::endl;
        } 

    }

    if (gravPc == 100){
        varList[15] = 1 + rand()%5;
        std::cout << "[Gravity]: " << gravCon[varList[15]] << std::endl;
    } else {
        if (randomScan >= 5){
            std::cout << "[Gravity]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        }else{
            std::cout << "[Gravity]: " << gravCon[varList[15]] << std::endl;
        }
    }

    if (resoPc == 100){
        resourceIndex = 1 + rand()%5; //Determaining the amount of fuel that is refueled
        std::cout << "[Resources]: " << resoCon[resourceIndex] << std::endl;
    } else {
        if (randomScan >= 5) {
            std::cout << "[Resources]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;    
        }else{
            std::cout << "[Resources]: " << resoCon[resourceIndex] << std::endl;
        }
    }

    if (watePc == 100){
        varList[16] = 1 + rand()%5;
        std::cout << "[Water]: " << wateCon[varList[16]] << std::endl;
    } else {
        if(randomScan >= 5){
            std::cout << "[Water]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        }else{
            std::cout << "[Water]: " << wateCon[varList[16]] << std::endl;
        }
    }

    if (tempPc == 100){
        varList[17] = 1 + rand()%5;
        std::cout << "[Temperature]: " << tempCon[varList[17]] << std::endl;
    } else {
        if (randomScan >= 5){
            std::cout << "[Temperature]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        }else{
            std::cout << "[Temperature]: " << tempCon[varList[17]] << std::endl;
        }
    }
}

/*
void land(){
    char land;
    std::cout << "\n[A]Land    [B]Skip" << std::endl;
    std::cin >> land;
    if (tolower(land) == 'a'){
        if (resourceIndex != 5){
            std::cout << "\n[A] Refuel + "<<(resourceIndex + 1) * 2  <<"    [B] Colonize" << std::endl;
            std::cin >> land;
        } else {
            std::cout << "\n[A] Refuel + 0    [B] Colonize" << std::endl;
            std::cin >> land;
        }

        if (tolower(land) == 'a'){
            switch (resourceIndex){
                case 0:
                    varList[13] += 3;
                    break;
                case 1:  
                    varList[13] += 4;
                    break;
                case 2:
                    varList[13] += 5;
                    break;
                case 3:
                    varList[13] += 6;
                    break;
                case 4:
                    varList[13] += 10;
                    break;
                case 5:
                    varList[13] += 0;
                    break;

                default:
                    break;
            
            }
            
        }
        else if (tolower(land) == 'b'){
            std::cout << "You have chosen to colonize this planet, give it a name!!" << std::endl;
            std::string planetName;
            getline(std::cin, planetName);
            //colonize();
        }
    }
    else if (tolower(land) == 'b'){
        
    }
}
*/


void probe(){
    std::cout << "     Surface Probes left: " << varList[0] << std::endl;
}

void atmo(){
    std::cout << "Atmosphere Scanner: " << varList[1] << '%'<< std::flush;
}

void gravity(){
    std::cout << "      Gravity Scanner: " << varList[2] << '%' << std::endl;
}

void reso(){
    std::cout << "Resource Scanner: " << varList[3] << '%' << std::flush;
}

void water(){
    std::cout << "        Water Scanner: " << varList[4] << '%' << std::endl;
}

void temperature(){
    std::cout << "Temperature Scanner: " << varList[5] << '%' << std::flush;
}

void science(){
    std::cout << "     Scientific Databases: " << varList[6] << '%' << std::endl;
}

void culture(){
    std::cout << "Cultural Databases: " << varList[7] << '%' << std::flush;
}

void landing(){
    std::cout << "\n\nLanding Status: " << varList[8] << '%' << std::endl;
}

void engine(){
    std::cout << "Engine Status: " << varList[9] << '%' << std::flush;
}

void humanAlive(){
    std::cout << "Humans Alive: " << varList[10] << std::endl;
}

void yearsPassed(){
    std::cout << "Years Passed: " << varList[11] << std::endl;
}

void powerPercentage(){
    std::cout << std::endl;
    std::cout << "Power: " << varList[13] << '%' << std::endl;
}
//Misc Functions:

void slow_print(const std::string message){
    for (const char c : message){
        std::cout << c << std::flush;
        usleep(10000);
    }
}

void all(){
        std::cout << "\nScanner Status: \n" << std::endl;
            atmo();
            gravity();
            reso();
            water();
            temperature();
            science();
            culture();
            landing();
            engine();
            probe();
            powerPercentage();
            humanAlive();
            yearsPassed();
            std::cout << "__________________________________________________" << std::endl;//50 spaces
    }