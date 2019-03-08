#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "variables.h"
#include "functions.h"

//Status: Complete && working
void astroids() {//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    srand(time(0));
    char option;
    std::cout << "\nAn astroid field is detected, you can risk flying through the field to get to your planet, or you can switch your route." << std::endl;
    std::cout << "(A) Fly through astroid field" << std::endl;
    std::cout << "(B) Change route." << std::endl;
    std::cin >> option;
    int randNum = randomNumberGenerator(); // random number 
    int randDmg = randomNumberGenerator(); //Random damage for the scanners

    if (tolower(option) == 'a'){
        std::cout << "You risked flying through the astroid field" << std::endl;
    //PROBLEM: If randnum is already declard randomly, 
        //and the if condition only accepts it when it is above or equal to 5
        //This means that there is no chance of damage done to the scanners (1 to 4)
        //Solution? Seperate randum variable, or just use the function
    //Random Damage: 
        if (randomNumberGenerator() > 3){
            
            start:
            if (randNum != 0 && randNum != 10){
                varList[randNum] -= randDmg;
                std::cout << "Astroids collide with your ship, ripping and damaging the componants.\n" << std::endl;
            } else {
                randNum = randomNumberGenerator();
                goto start;
            }
            power = power - 1;
        } else {
            std::cout << "Your ship flied through safetly!" << std::endl;
            power = power - 1;
        }
    } 
    else if (tolower(option) == 'b') {
        std::cout << "You have changed the ship's route" << std::endl;
        power = power - 2;
    }
}
//Status: Fixing
void blackhole(){//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Detected by some scanners
    char response;
    std::cout << "You come across a unusual spot, some of your scanners detect a strange gravitational pull, the only possible answer is a nearby Black Hole" << std::endl;
    std::cout << "You can trust your scanners and activate your thrusters and try to escape the black hole, or you can ignore it, the extreme conditions of space might have made it malfunction." << std::endl;
    std::cout << "[A] Attempt to escape, engage thrusters to 150%" << std::endl;
    std::cout << "[B] Ignore and stay on course " << std::endl;
    std::cin >> response;
    //srand(time(0));
    if (tolower(response) == 'a'){
        int randNum = randomNumberGenerator();
        int randDmg = randomNumberGenerator();
        if (randNum >= 5){
            
            std::cout << "You have flown away" << std::endl;

        } else {

            std::cout << "You were just fast enough to able to escape, but pieces of your ship gets torned off and dissappears into the dark abyss" << std::endl;
        }
    } 
    else if (tolower(response) == 'b'){
        std::cout << "You have changed your ship's course, you are now heading towards a new planet!" << std::endl;    
    }
}

//Status: Fixing
void meteor(int atmoPc, int resoPc){//-------------------------------------------------------------------------------------------------------------------------------------------------------
    char option;
    char c;
    srand(time(0));

    int amt = 12 + (rand() % 6);
    std::cout << "Your scanners have found a metoer that is heading your way currently, and through calculation,"
                 "It will collide with the sleep chambers area, potentially killing some passengers."
                 "You can rotate your ship and allow it to hit one of your scanners, or stay put and let it collide with the chambers." << std::endl;
    printf("[A] Collide");
    printf("[B] Rotate\n");
    std::cin >> option;
    if (tolower(option) == 'a'){
        std::cout << "The meteor strikes the sleeping chambers area, killing " << amt << "Astronauts on board." << std::endl;
        std::cout << "Enter C to Continue!" << std::flush;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (tolower(option) == 'b'){
        srand(time(0));
        int hit = 1 + (rand() % 6);
        if (hit == 1){
            std::cout << "You rotate your ship, and the meteor hits the scanners and torns the atmosphere scanner apart" << std::endl;
            atmoPc = atmoPc - hit*2;
        } else {
            std::cout << "You rotate your ship, and the meteor hits the scanners and damages the resource scanner" << std::endl;
            resoPc = resoPc - hit*2;
        }
    }
}
//Status: Fixing
void oHeat(){
    char res;
    std::cout << "The ventilation systems are failing, and the CryoSleep chambers are over heating" << std::endl;
    std::cout << "[A]Shut entire system down to bring down temperature" << std::endl;
    std::cout << "[B]Eject Cryosleep chambers to lessen system load" << std::endl;
    std::cin >> res;
    if (tolower(res) == 'a'){
        std::cout << "You chose to shut down the entire system." << std::endl;
        
    }
}