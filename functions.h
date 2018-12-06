#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <thread>

void planet (char atmo, char gravity, char reso, char water ,char temperature, std::string atmoCon[], std::string gravCon[], std::string resoCon[], std::string wateCon[], std::string tempCon[]) {
    srand(time(0));
    if (atmo == 100){
        std::cout << "[Atmosphere]: " << atmoCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Atmosphere]: Scan Failed" << std::endl; 
    }
    if (gravity == 100){
        std::cout << "[Gravity]: " << gravCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Gravity]: Scan Failed" << std::endl;
    }
    if (reso == 100){
        std::cout << "[Resources]: " << resoCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Resources]: Scan Failed" << std::endl;
    }
    if (water == 100){
        std::cout << "[Water]: " << wateCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Water]: Scan Failed" << std::endl;
    }
    if (temperature == 100){
        std::cout << "[Temperature]: " << tempCon[1 + rand()%5] << std::endl;
    } else {
        std::cout << "[Temperature]: Scan Failed" << std::endl;
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
    std::cout << "     Surface Probes left: " << probNum << std::endl;
}

void atmo(int atmoPc){
    std::cout << "Atmosphere Scanner: " << atmoPc << '%'<< std::flush;
}

void gravity(int gravPc){
    std::cout << "      Gravity Scanner: " << gravPc << '%' << std::endl;
}

void reso(int resoPc){
    std::cout << "Resource Scanner: " << resoPc << '%' << std::flush;
}

void water(int watePc){
    std::cout << "        Water Scanner: " << watePc << '%' << std::endl;
}

void temperature(int tempPc){
    std::cout << "Temperature Scanner: " << tempPc << '%' << std::flush;
}

void science(int sciPc){
    std::cout << "     Scientific Databases: " << sciPc << '%' << std::endl;
}

void culture(int culPc){
    std::cout << "Cultural Databases: " << culPc << '%' << std::flush;
}

void landing(int lanPc){
    std::cout << "\n\nLanding Status: " << lanPc << '%' << std::endl;
}

void construction(int conPc){
    std::cout << "Construction Status: " << conPc << '%' << std::flush;
}



//Misc Functions:

void slow_print(const std::string message){
    for (const char c : message){
        std::cout << c << std::flush;
        usleep(10000);
    }
}

