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
    int randNum = randomNumberGenerator(); // random number 
    int randDmg = randomNumberGenerator(); //Random damage for the scanners
    int randSaying = randomNumberGenerator(); // Random integer for the story
    
    if (randSaying >= 5){ // different story
        std::cout << "\nAn astroid field is detected, you can risk flying through the field to get to your planet, or you can switch your route." << std::endl;
        std::cout << "(A) Fly through astroid field" << std::endl;
        std::cout << "(B) Change route." << std::endl;
        std::cin >> option;
    } else {
        std::cout << "\nAn Large astroid field has been detected, blocking your path to your next planet. You can: " << std::endl;
        std::cout << "(A) Fly through astroid field" << std::endl;
        std::cout << "(B) Change route." << std::endl;
        std::cin >> option;
    }

    if (tolower(option) == 'a'){
        std::cout << "You risked flying through the astroid field" << std::endl;
    //PROBLEM: If randnum is already declard randomly, 
        //and the if condition only accepts it when it is above or equal to 5
        //This means that there is no chance of damage done to the scanners (1 to 4)
        //Solution? Seperate randum variable, or just use the function
    //Random Damage: 
        if (randomNumberGenerator() > 3){
            randNum = randomNumberGenerator();
            start:
            if (randNum != 0 && randNum != 10){
                varList[randNum] -= randDmg;
                std::cout << "Astroids collide with your ship, ripping and damaging the componants.\n" << std::endl;
            } else {
                std::cout << "hello" << std::endl;
                goto start;
            }
            power = power - 2;
        } else {
            std::cout << "Your ship flied through safetly!" << std::endl;
            power = power - 2;
        }
    } 
    else if (tolower(option) == 'b') {
        std::cout << "You have changed the ship's route, you are now heading towards a new planet" << std::endl;
        power = power - 4;
        if (randomNumberGenerator() >= 5){
            system("clear");
            all();
            astroids();
        }
    
    }
}
//Status: Fixing
void blackhole(){//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Detected by some scanners
    char response;
    int randNum = randomNumberGenerator();
    int randDmg = randomNumberGenerator();
    int randSaying = randomNumberGenerator();
    if (randSaying >= 5){
        std::cout << "You come across a unusual spot, your gravity scanner detects a sharp, strange gravitational pull but all other scanners do not detect anything, there is only one possibility, a black hole." << std::endl;
        std::cout << "Your ship begins to turn towards the abyss of space, where you see a slight curve in the area around it." << std::endl;
        std::cout << "[A] Push the engines past their safety limit and attempt to escape the 'black hole'. . ." << std::endl;
        std::cout << "[B] Restart the scanners, the harsh conditions of space might have caused it to malfunction." << std::endl;
        std::cin >> response;
    } else {
        std::cout << "" << std::endl;
        std::cout << "You can trust your scanners and activate your thrusters and try to escape the black hole, or you can ignore it, the extreme conditions of space might have made it malfunction." << std::endl;
        std::cout << "[A] Push the engines past their safety limit and attempt to escape the 'black hole'. . ." << std::endl;
        std::cout << "[B] Restart the scanners, the harsh conditions of space might have caused it to malfunction." << std::endl;
        std::cin >> response;
    }
    //srand(time(0));
    if (tolower(response) == 'a'){
        if (randNum >= 5){
            std::cout << "You have flown away safely, you were almost in the grasp of unescapeble gravity." << std::endl;
            power = power - 10;
        } else {
            std::cout << "You were able to escape, but barely, large amounts of scrap metal gets ripped off of your ship and falls back into the black hole . . ." << std::endl;
            randNum = randomNumberGenerator();
            
            start:
            if (randNum != 0 && randNum != 10){
                varList[randNum] -= randDmg;
            } else {
                goto start;
            }
            power = power - 12;
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