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
        // Year adding
        varList[11] += 1;
        std::cout << "You risked flying through the astroid field" << std::endl;
    //PROBLEM: If randnum is already declard randomly, 
        //and the if condition only accepts it when it is above or equal to 5
        //This means that there is no chance of damage done to the scanners (1 to 4)
        //Solution? Seperate randum variable, or just use the function
    //Random Damage: 
        if (randomNumberGenerator() > 3){
            start:
            randNum = randomNumberGenerator();
            if (randNum > 0 && randNum < 10){
                randNum = randomNumberGenerator();
                varList[randNum] -= randDmg;
                std::cout << "Astroids collide with your ship, ripping and damaging the componants.\n" << std::endl; 
                
                // Power
                varList[13] -= 2;
            } else {
                goto start;
            }
            
        } else {
            std::cout << "Your ship flied through safetly!" << std::endl;
            varList[13] -= 2;
        }
    } 
    else if (tolower(option) == 'b') {
        std::cout << "You have changed the ship's route, you are now heading towards a new planet" << std::endl;
        
        // Power
        varList[13] -= 4;
        varList[13] += 2;
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
        std::cout << "Your ship begins to turn uncontrollabely towards the abyss of space, where you see a slight curve in the area around it." << std::endl;
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
            varList[13] -= 5;
            varList[9] -= 5;
        } else {
            std::cout << "You were able to escape, but barely, large amounts of scrap metal are ripped off of the ship . . ." << std::endl;
            randNum = randomNumberGenerator();

            start:
            if (randNum != 0 && randNum != 10){
                varList[randNum] -= randDmg;
            } else {
                goto start;
            }
            varList[13] -= 5;
            varList[9] -= 5;
        }
    } 
    else if (tolower(response) == 'b'){
        randNum = randomNumberGenerator();
        if (randNum > 5){ //Gets damaged
            std::cout << "You restart the scanners, hoping that this will fix the problem, but as they reboot, the emergenc system warns you about a near black hole. " << std::endl;
            std::cout << "You immediatly engage the engines and attempts to escape the black hole, you barely escape. . ." << std::endl;
            std::cout << "Your ship has been severely damaged. . ." << std::endl;
            for (int i = 0; i < 14; i++){
                varList[i] -= 2;
            }
        } else { // Malfunction
            std::cout << "You restart your scanners, hoping that this will fix the malfunction. . ." << std::endl;
            std::cout << "The scanners boot back on, and there appears to be no black hole near you, it was indeed a malfunction. . ." << std::endl;

        }
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

void colonize(){
    // First sentence
    std::string message1 = "The colonists begin constructing a settlement with the aid of the seedship's construction robots.";
    std::string message2;
    switch (varList[14]){
        case 0:
            message2 = "They cannot go outside due to the \'Non Breathable\' atmosphere.";
            break;
        case 1:
            message2 = "They cannot go outside until they have adapted to the \'Corrosive\' atmosphere.";
            break;
        case 2:
            message2 = "They can go outside, but they must wear heavy breathing gear due to the \'Toxic\' atmosphere.";
            break;
        case 3:
            message2 = "They can leave the ship with minimal breathing gear.";
            break;
        case 4:
            message2 = "They can leave the ship with no breathing gear.";
            break;
        case 5:
            message2 = "";
            break;
    }
    
};
   

