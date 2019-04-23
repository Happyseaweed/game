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


void randomDamage(){//Possible function, returns a number(the scanner's array num)

}



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
                //randNum = randomNumberGenerator();
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
    else if (tolower(response) == 'b'){//---------------------------------------Damage system
        randNum = randomNumberGenerator();
        if (randNum > 5){ //
            std::cout << "You restart the scanners, hoping that this will fix the problem, but as they reboot, the emergenc system warns you about a near black hole. " << std::endl;
            std::cout << "You immediatly engage the engines and attempts to escape the black hole, you barely escape. . ." << std::endl;
            std::cout << "Your ship has been severely damaged. . ." << std::endl;
            for (int i = 0; i < 14; i++){
                if (i != 11){
                    varList[i] -= 2;
                }
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
    
    // Breathing statement
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
        default:
            std::cerr << "lungs.exe was not found!! No breathing level indicated." << std::endl;
            break;
    }

    // Temperature statement.
    std::string message3;
    switch (varList[17]){
        case 0:
            message3 = "The colonists are able to leave the ship for short periods of time with heated suits due to the \'Near Absolute Zero\' temperature.";
            break;
        
        case 1:
            message3 = "The colonists are able to leave the ship and transerve the land for small periods of time due to the  \'Very Cold\' temperature.";
            break;
        
        case 2:
            message3 = "The colonists are able to leave the ship for long periods of time with multiple layers of clothing due to the cold temperature.";
            break;
        
        case 3:
            message3 = "The colonists are able to traverse in and out of the ship freely for exploration due to the moderate temperature.";
            break;
        
        case 4:
            message3 = "The colonists are able to explore the planet for moderate periods of time before needing to rehydrate.";
            break;
        
        case 5:
            message3 = "The colonists are able to leave the ship for short periods of timeand explore with water cooled spacesuits.";
            break;

    }

    // Gravity
    std::string message4;
    switch (varList[15])
    {
        case 0:
            message4 = "The exploration rate of the colonists have been significantly reduced due to the \'Extremely Low Gravity\' of the planet.";
            break;
        case 1:
            message4 = "The exploration rate of the colonists is slower due to the \'Very Low\' gravity level.";
            break;

        case 2:
            message4 = "The exploration rate of the colonists is faster due to the \'Low\' gravity level.";
            break;

        case 3:
            message4 = "The colonists are able to explore the planet and study its enviroments with ease due to the similar-to-earth gravity.";
            break;

        case 4:
            message4 = "The \'High\' gravity level makes exploration within the planet difficult amongst the colonists.";
            break;

        case 5:
            message4 = "The extremely high gravity pull of the planet has reduced the exploration speed significantly. Many colonists have trouble getting used to this high gravity as they pass out frequently.";
            break;

        default:
            break;
    }
    
    // Water
    std::string message5;
    switch (varList[16]){
        case 0:
            message5 = "The colonists must fight over the extremely limited amount of water.";
            break;
        case 1:
            message5 = "The colonists are able to obtain water through the rivers on the planet.";
            break;
        case 2:
            message5 = "Many colonists are not able to drink water on some days due to the small amount of water on the planet.";
            break;
        case 3:
            message5 = "The colonists are able to survive easily with the high amounts of water from the oceans.";
            break;
        case 4:
            message5 = "The colonists are unable to get high amounts of water due to most of the water being frozen in the ice caps.";
            break;
        default:
            break;
    }
    // Resources!
    std::string message6;
    switch (varList[12]){
        case 0:
            message6 = "They must compete over the resources to due to the low amount.";
            break;
        case 1:
            message6 = "The limited resources causes for some colonists without resources to expand their settlement.";
            break;
        case 2:
            message6 = "They have just enough resources for all the colonists to be well off.";
            break;
        case 3:
            message6 = "They have enough resources for all the colonists to be able to live without worry.";
            break;
        case 4:
            message6 = "All of the colonists are able to live in luxury due to the rich resources on the planet.";
            break;
        case 5:
            message6 = "";
            break;
    }
    //Scientific Data
    std::string message7;
    if (varList[16] <= 25){
        message7 = "The colonists are not able to make signifcant ";
    }
    /*
        case 1:
            message5 = "";
            break;
        case 2:
            message5 = "";
            break;
        case 3:
            message5 = "";
            break;
        case 4:
            message5 = "";
            break;
        case 5:
            message5 = "";
            break;
        */
    //Cultural Data
    std::string message8;
    switch (varList[16]){
        case 0:
            message8 = "";
            break;
        case 1:
            message8 = "";
            break;
        case 2:
            message8 = "";
            break;
        case 3:
            message8 = "";
            break;
        case 4:
            message8 = "";
            break;
        case 5:
            message8 = "";
            break;
    }
   
}

