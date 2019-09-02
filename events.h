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

void colonize();

void endCredits(){
    std::cout << "\n\n\n\n" << std::endl;
    std::cout << "Thank you for playing" << std::endl; 
    std::cout << "Game: 2150" << std::endl;
    std::cout << "Created by: Siwei & Meguta(Ahmed), started in 2018\n\n\n" << std::endl;

    //exit;

}

int land(){
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
            colonize();
            endCredits();
            return 0;
            
        }
    }
    else if (tolower(land) == 'b'){
        
    }
    return 1;
}


//Status: Complete && working
//Goal: Astroids field that you can either pass through and risk collision, or goto another event
//Possible improvments: 
bool happened = false; //variable to determin the amount of times this function re-runs
void astroids() {//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    srand(time(0));//
    char option;
    int randNum = randomNumberGenerator(); // random number 
    int randDmg = randomNumberGenerator(); //Random damage for the scanners
    int randSaying = randomNumberGenerator(); // Random integer for the story
    
    if (randSaying >= 5){ // 2 different story
        std::cout << "\n An large astroid field has been detected, it blocks your current route. " << std::endl;
        std::cout << "(A) Fly through the astroid field and hope not to hit an astroid." << std::endl;
        std::cout << "(B) Emergency Route Change [Consumes Exessive power]." << std::endl;
        std::cin >> option;
    } else {
        std::cout << "\n Your astroid avoidence system alerts you about an incoming astroid field that blocks your current route. " << std::endl;
        std::cout << "(A) Fly through and hope not to get hit." << std::endl;
        std::cout << "(B) Emergency Route Change [Consumes exessive power]." << std::endl;
        std::cin >> option;
    }

    if (tolower(option) == 'a'){
        // Year adding
        varList[11] += 1;
        std::cout << "You risked flying through the astroid field." << std::endl;
    //Random Damage: 
        if (randomNumberGenerator() > 3){
            randNum = randomNumberGenerator();
            while(1){
                if (randNum > 1 && randNum < 10){
                    varList[randNum] -= randDmg;
                    std::cout << "Unfortunatly, an astroid collides with your ship, smashing and damaging the componants." << std::endl; 
                    std::cout << "It hits the " << varListNames[randNum] << " and dealt -" << randDmg << "%" << std::endl;
                    varList[13] -=1;//power deduction
                    break;
                }
            randNum = randomNumberGenerator();
            }

        } else {
            std::cout << "Luckily, your ship flied through safetly!" << std::endl;
            varList[13] -= 1;
        }
    } 
    else if (tolower(option) == 'b') {
        varList[11] += 1;
        std::cout << "You have engaged the Emergency Route Change Protocal and changed the route of the ship just in time. . ." << std::endl;
        
        // Power
        varList[13] -= 3;

        if (happened == false){
            if (randomNumberGenerator() >= 5){
                system("clear");
                all();
                astroids();
                happened = true;
            }
        }
        happened = false;
    }
}


//Status: Complete && Working
//Goal: System malfunction that may or may not be a real black hole
// 
//POssible Improvments: 
void blackhole(){//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Detected by some scanners
    char response;
    int randNum = randomNumberGenerator();
    int randDmg = randomNumberGenerator();
    int randSaying = randomNumberGenerator();

    if (randSaying >= 5){
        std::cout << "You come across a unusual spot, your gravity scanner detects a sharp, strange gravitational pull but all other scanners do not detect anything." << std::endl;
        std::cout << "It is possible that there is a black hole near by. . ." << std::endl;
        std::cout << "[A] Push the engines past their safety limit and attempt to escape gravity of the 'black hole'. . ." << std::endl;
        std::cout << "[B] Restart the scanners, the harsh conditions of space might have caused it to malfunction." << std::endl;
        std::cin >> response;
    } else {
        std::cout << "" << std::endl;
        std::cout << "The gravity scanner activates an alarm, telling you that there is a strange gravitational pull near by, and it could be a black hole. . .";
        std::cout << "You check all the other scanners, and see no strange signs that a black hole could give off. . ." << std::endl;
        std::cout << "[A] Push the engines past their safety limit and attempt to escape the gravity of the 'black hole'. . ." << std::endl;
        std::cout << "[B] Restart the scanners, the harsh conditions of space might have caused it to malfunction." << std::endl;
        std::cin >> response;
    }
    //srand(time(0));
    if (tolower(response) == 'a'){
        varList[11] +=1;
        if (randNum >= 5){ //There is a black Hole
            std::cout << "You push the engine throttle above the safety limit and it damages the engines, you do not know if there was actually a black hole. . ." << std::endl;
            varList[13] -= 5;
            varList[9] -= 5;
        } else {
            std::cout << "As you push the engines, the entire ship begins shaking, there was really a black hole. . ." << std::endl;
            std::cout << "You were barely able to escape the grasp of a black hole, you ship has been seriously damaged. . . ";
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
        varList[11] +=1;
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


//Status: Working
//Goal: Sacrafice one module or the other
//possible improvments: More variation on the message
void meteor(){//-------------------------------------------------------------------------------------------------------------------------------------------------------
    char option;
    srand(time(0));
    int randSpeed = 1 + (rand()%10);
    int rand1 = 1 + (rand()%10), rand2 = 1 + (rand()%10);

    std::cout << "A emergency alert is sent by your scanners of an incoming astroid, approximatly the size of a car, travelling at " << std::endl;
    std::cout << randSpeed*1234 << " km/h towards your ship. " << std::endl;
    std::cout << "After calculating the trajectory of the astroid, it will be colliding with the " << varListNames[rand1] << ". But you can rotate " << std::endl;
    std::cout << "the ship so it collides with the " << varListNames[rand2] << " instead. . ." << std::endl;
    std::cout << "[A] " << varListNames[rand1] << std::endl;
    std::cout << "[B] " << varListNames[rand2] << std::endl;
    std::cin >> option;
    int dmg = 1+(rand()%10);
    if (tolower(option) == 'a'){
        std::cout << "You have chose to let the meteor collide with the " << varListNames[rand1] << std::endl;
        varList[rand1] -= dmg;
    }
    else if (tolower(option) == 'b'){
        std::cout << "You have chose to let the meteor collide with the " << varListNames[rand2] << std::endl;
        varList[rand2] -= dmg;
    }
}

//Status: Working(Need to develop more interesting message)________________________________________________________________________________________________________________________________________________
//Goal: System over heat, either shut down system which causes potential damage, or eject humans to lessen load
//Possible improvments: 
void oHeat(){
    char res;
    std::cout << "The ventilation systems are failing, and the CryoSleep chambers are over heating" << std::endl;
    std::cout << "[A]Shut entire system down to bring down temperature" << std::endl;
    std::cout << "[B]Eject Cryosleep chambers to lessen system load" << std::endl;
    std::cin >> res;
    if (tolower(res) == 'a'){
        int dead;
        int dmgAtmo, dmgGrav;
        std::cout << "You chose to shut down the entire system." << std::endl;

        // damaging and killing stuff
        dead = randomNumberGenerator() * 10;
        int energyCost = randomNumberGenerator() * 10;

        std::cout << "When turning off the entire system, " << dead << " colonists died in the process. However, this lead to the decrease in temperature." << std::endl;
        std::cout << "By shutting down the ship and restarting, a tremendous amount of energy is consumed by this process. . ." << std::endl;
        // changing the variables in the varList
        varList[10] -= dead;
        varList[13] -= energyCost;

        
    } else if (tolower(res) == 'b'){
        int dead;
        std::cout << "You chose to eject Cryosleep chambers to lessen system load." << std::endl;

        // getting the amount of dead people
        dead = randomNumberGenerator() * 10;
        std::cout << "Due to the ejecting of the chambers, the temperature of the ship was brought down, but "<< dead << " died from the chambers being ejected." << std::endl;

        // changing the variable in the varList
        varList[10] -= dead;
    }
}

//Status: Developing. . .
//Goal: System bug/virus that causes the text to be mis-displayed
//Possible improvments: 
void systemBug(){
    srand(time(0));
    char option;
    std::cout << "The systems sends an alert, a virus has been discovered by the anti-virus software, its origin is unknown, " << std::endl;
    std::cout << "but it will be causing significant problems if not fixed soon. To fix it, it will consume an enormous amount of power and time." << std::endl;
    std::cout << "[A] Eliminate the Virus at all costs"  << std::endl;
    std::cout << "[B] Ignore" << std::endl;
    std::cin >> option;
    int randDeath = 1+(rand()%10);
    if (tolower(option) == 'a'){
        std::cout << "You have chose to eliminate the virus" << std::endl;
        std::cout << "You had to eject " << randDeath << " sleep chambers to reserve power" << std::endl;
    }
    else if (tolower(option) == 'b'){

    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
// Developing. . .
void colonize(){
    // First sentence
    std::string messages[8];
    messages[0] = "The colonists begin constructing a settlement with the aid of the seedship's construction robots.";
    
    // Breathing statement____________________________________________________________________________________________________________________________________________________________________
    switch (varList[14]){
        case 0:
            messages[1] = "They cannot go outside due to the \'Non Breathable\' atmosphere.";
            break;
        case 1:
            messages[1] = "They cannot go outside until they have adapted to the \'Corrosive\' atmosphere.";
            break;
        case 2:
            messages[1] = "They can go outside, but they must wear heavy breathing gear due to the \'Toxic\' atmosphere.";
            break;
        case 3:
            messages[1] = "They can leave the ship with minimal breathing gear.";
            break;
        case 4:
            messages[1] = "They can leave the ship with no breathing gear.";
            break;
        default:
            std::cerr << "lungs.exe was not found!! No breathing level indicated." << std::endl;
            break;
    }

    // Temperature statement____________________________________________________________________________________________________________________________________________________________________
    switch (varList[17]){
        case 0:
            messages[2] = "The colonists are able to leave the ship for short periods of time with heated suits due to the \'Near Absolute Zero\' temperature.";
            break;
        
        case 1:
            messages[2] = "The colonists are able to leave the ship and transerve the land for small periods of time due to the  \'Very Cold\' temperature.";
            break;
        
        case 2:
            messages[2] = "The colonists are able to leave the ship for long periods of time with multiple layers of clothing due to the cold temperature.";
            break;
        
        case 3:
            messages[2] = "The colonists are able to traverse in and out of the ship freely for exploration due to the moderate temperature.";
            break;
        
        case 4:
            messages[2] = "The colonists are able to explore the planet for moderate periods of time before needing to rehydrate.";
            break;
        
        case 5:
            messages[2] = "The colonists are able to leave the ship for short periods of timeand explore with water cooled spacesuits.";
            break;

    }

    // Gravity______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
    switch (varList[15])
    {
        case 0:
            messages[3] = "The exploration rate of the colonists have been significantly reduced due to the \'Extremely Low Gravity\' of the planet.";
            break;
        case 1:
            messages[3] = "The exploration rate of the colonists is slower due to the \'Very Low\' gravity level.";
            break;

        case 2:
            messages[3] = "The exploration rate of the colonists is faster due to the \'Low\' gravity level.";
            break;

        case 3:
            messages[3] = "The colonists are able to explore the planet and study its enviroments with ease due to the similar-to-earth gravity.";
            break;

        case 4:
            messages[3] = "The \'High\' gravity level makes exploration within the planet difficult amongst the colonists.";
            break;

        case 5:
            messages[3] = "The extremely high gravity pull of the planet has reduced the exploration speed significantly. Many colonists have trouble getting used to this high gravity as they pass out frequently.";
            break;

        default:
            break;
    }
    
    // Water______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
    switch (varList[16]){
        case 0:
            messages[4] = "The colonists must fight over the extremely limited amount of water.";
            break;
        case 1:
            messages[4] = "The colonists are able to obtain water through the rivers on the planet.";
            break;
        case 2:
            messages[4] = "Many colonists are not able to drink water on some days due to the small amount of water on the planet.";
            break;
        case 3:
            messages[4] = "The colonists are able to survive easily with the high amounts of water from the oceans.";
            break;
        case 4:
            messages[4] = "The colonists are unable to get high amounts of water due to most of the water being frozen in the ice caps.";
            break;
        default:
            break;
    }
    // Resources!____________________________________________________________________________________________________________________________________________________________________
    switch (varList[12]){
        case 0:
            messages[5] = "They must compete over the resources to due to the low amount.";
            break;
        case 1:
            messages[5] = "The limited resources causes for some colonists without resources to expand their settlement.";
            break;
        case 2:
            messages[5] = "They have just enough resources for all the colonists to be well off.";
            break;
        case 3:
            messages[5] = "They have enough resources for all the colonists to be able to live without worry.";
            break;
        case 4:
            messages[5] = "All of the colonists are able to live in luxury due to the rich resources on the planet.";
            break;
        case 5:
            messages[5] = "";
            break;
    }
    //Scientific Data____________________________________________________________________________________________________________________________________________________________________
    if (varList[16] <= 25){
        messages[6] = "The colonists are not able to make signifcant progress with the materials they have due to the lack of scienctific knowledge.";
    } else if (varList[16] > 25 && varList[16] <= 50){
        messages[6] = "The colonists are able to make small incremental progress with the information they have.";
    } else if (varList[16] > 50 && varList[16] <= 75){
        messages[6] = "The colonists are able to make good process with the scientific knowledge they have left.";
    } else if (varList[16] > 75){
        messages[6] = "The colonists are able to make the maximum amount of process with information they have due to the high scientific knowledge base.";
    }

    // Cultural Database \\ Change messages____________________________________________________________________________________________________________________________________________________________________
    if (varList[17] <= 25){
        messages[7] = "They are not able make social structures, such as governments, or relive as they used on Earth due to the lack of cultural data";
    } else if (varList[17] > 25 && varList[17] <= 50){
        messages[7] = "They are able learn simple cultural ways of humans, however they process is limited due to their lack of cultural data.";
    } else if (varList[17] > 50 && varList[17] <= 75){
        messages[7] = "They are easily able to relearn the ways of the humans in the past with no difficulties, however they struggle with diversifying their ways.";
    } else if (varList[17] > 75){
        messages[7] = "They are able to mimic the way humans used to act effortlessly due to the high amount of cultural data, and with the wealth of this data allows for diversity within the population.";
    }

    // creating the message
    std::string finalMessage;
    for (int i = 0;  i != 8; ++i){
       finalMessage = finalMessage + " " + messages[i];
    }

    // printing the message
    slow_print(finalMessage);
}

