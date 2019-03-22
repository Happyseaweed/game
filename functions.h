#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "variables.h"

int randomNumberGenerator(){ // generates a random number from 1 to 10
    srand(time(0));
    int randNumber = 1 + (rand()%10);
    return randNumber;
}

//_________________________________________________________________________________________________________________________________________________


void planet (int scan[], std::string atmoCon[], std::string gravCon[], std::string resoCon[], std::string wateCon[], std::string tempCon[], int &resourceIter) {
    std::cout << "\nYou arrive at a planet: \n" << std::endl;
    srand(time(0));
    int randomScan = randomNumberGenerator();

    if (atmoPc == 100){
        std::cout << "[Atmosphere]: " << atmoCon[1 + rand()%5] << std::endl;
    } else {
        if (randomScan >= 3){
            std::cout << "[Atmosphere]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        } else {
            std::cout << "[Atmosphere]: " << atmoCon[1 + rand()%5] << std::endl;
        } 

    }

    if (gravPc == 100){
        std::cout << "[Gravity]: " << gravCon[1 + rand()%5] << std::endl;
    } else {
        if (randomScan >= 3){
            std::cout << "[Gravity]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        }else{
            std::cout << "[Gravity]: " << gravCon[1 + rand()%5] << std::endl;
        }
    }

    if ( == 100){
        resourceIter = 1 + rand()%5; //Determaining the amount of fuel that is refueled
        std::cout << "[Resources]: " << resoCon[resourceIter] << std::endl;
    } else {
        if (randomScan >= 3) {
            std::cout << "[Resources]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;    
        }else{
            std::cout << "[Resources]: " << resoCon[resourceIter] << std::endl;
        }
    }

    if (varList[4] == 100){
        std::cout << "[Water]: " << wateCon[1 + rand()%5] << std::endl;
    } else {
        if(randomScan >= 3){
            std::cout << "[Water]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        }else{
            std::cout << "[Water]: " << wateCon[1 + rand()%5] << std::endl;
        }
    }

    if (varList[5] == 100){
        std::cout << "[Temperature]: " << tempCon[1 + rand()%5] << std::endl;
    } else {
        if (randomScan >= 3){
            std::cout << "[Temperature]:"; usleep(10000); std::cout << " Scan Failed" << std::endl;
        }else{
            std::cout << "[Temperature]: " << tempCon[1 + rand()%5] << std::endl;
        }
    }
}

void land(int &resourceIter){
    char land;
    std::cout << "\n[A]Land    [B]Skip" << std::endl;
    std::cin >> land;
    if (tolower(land) == 'a'){
        if (resourceIter != 5){
            std::cout << "\n[A] Refuel + "<<(resourceIter + 1) * 2  <<"    [B] Colonize" << std::endl;
            std::cin >> land;
        } else {
            std::cout << "\n[A] Refuel + 0    [B] Colonize" << std::endl;
            std::cin >> land;
        }

        if (tolower(land) == 'a'){

            switch (resourceIter){
                case 0:
                    power += 3;
                    break;
                case 1:  
                    power += 4;
                    break;
                case 2:
                    power += 5;
                    break;
                case 3:
                    power += 6;
                    break;
                case 4:
                    power += 10;
                    break;
                case 5:
                    power += 0;
                    break;

                default:
                    break;
            
            }
            
        }
        else if (tolower(land) == 'b'){
            std::cout << "You have chosen to colonize this planet, give it a name!!" << std::endl;
            std::string planetName;
            getline(std::cin, planetName);
        }
    }
    else if (tolower(land) == 'b'){
        
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

void powerPercentage(int powerPc){
    std::cout << std::endl;
    std::cout << "Power: " << powerPc << '%' << std::endl;
}

void humanAlive(int &human){
    std::cout << "Humans Alive: " << human << std::endl;
}

void yearsPassed(int &year){
    std::cout << "Years Passed: " << year << std::endl;
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
            atmo(atmoPc);
            gravity(gravPc);
            reso(resoPc);
            water(watePc);
            temperature(tempPc);
            science(sciPc);
            culture(culPc);
            landing(lanPc);
            construction(conPc);
            probe(probNum);
            powerPercentage(power);
            humanAlive(human);
            yearsPassed(year);
            std::cout << "__________________________________________________" << std::endl;//50 spaces
    }