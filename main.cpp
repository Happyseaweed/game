#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <limits>
#include <term.h>
#include "functions.h"
#include "events.h"
#include "variables.h"
#include "saveload.cpp"




void ran (){
    srand(time(0));
        switch(rand() % 3 + 1){
            case 1: astroids(); break;
            case 2: blackhole(); break;
            case 3: std::cout << "YES WORKS" << std::endl; break;
        }
}

//Function to print all the scanners at once:

    void allbegin(){
        std::cout << "Scanner Status: \n" << std::endl;
            atmo(varList[1]);
            usleep(200000);

            gravity(varList[2]);
            usleep(200000);

            reso(varList[3]);
            usleep(200000);

            water(varList[4]);
            usleep(200000);

            temperature(varList[5]);
            usleep(200000);

            science(varList[6]);
            usleep(200000);

            culture(varList[7]);
            usleep(200000);

            landing(varList[8]);
            usleep(200000);

            construction(varList[9]);
            usleep(200000);

            probe(varList[0]);
            usleep(200000);

            powerPercentage(power);
            usleep(200000);
    }


//Texts to be printed to console: 
    std::string start = "It is the year 2150, the human civilization has come to an end. Earth is no longer habitable, the humans built"
                    " a space ship with their last availible resources. As the count down ends and the engines of the ship roars to life."
                    "The last hopes of human civilization rest in the cryosleep chambers of the ship. The people on Earth begins shrinking,"
                    "smaller and smaller, until each are just a tiny dot. Scientist have created the most intelligen AI in history to guide"
                    "this ship, the AI's job is to scan each planet the ship arrives at and decides if it is suitable for human survival"
                    "in order to prevent the end of human civilization.";

    std::string start2 = "[You, are the work of millions of scientists. This is your responsibility to ensure that humans does not go extinct.]\n"
                         "[Scanners Booting up. . .]";



//Main

int main(){
    //Welcome Page:
        char userInput;
        char response;
        system("clear");
        printf("\n[–––§ Welcome To 2150! §–––]\n\n");
        std::cout << "[A] [Play]" << std::endl;
        std::cout << "[B] [Exit]" << std::endl;
        std::cout << "[C] [Save]" << std::endl;
        std::cin >> userInput;
//game:
    //while(tolower(userInput) != 'b')//-------------------------------------------------------------------------------------------------------------------------------------------
    if (tolower(userInput) == 'a'){
    //Start up Message:
        system("clear");
        std::cout << "\n\n\n" << std::endl;
        slow_print(start);
        std::cout << '\n' << std::endl;
        slow_print(start2);
        std::cout << '\n' << std::endl;

    //Enter C to continue:
        std::cout << "Enter C to Continue!" << std::flush;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    //Game control Panel:
        system("clear");
        allbegin();
    //Exploration Starts:
        slow_print("*As the ship sails into the dark abyss of space, You come across your first planet*\n\n\n");
        usleep(2000000);
        //1st
        system("clear");
        all();
        planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon, resourceIter);
        land(resourceIter);
        system("clear");

        while(power >= 0){
        
            all();        
            astroids();
            std::cout << "Enter C to Continue!" << std::flush;
            std::cin >> userInput;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("clear");
            all();
            planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon, resourceIter);
            land(resourceIter);
            system("clear");
        }
    } 
    else if (tolower(userInput) == 'b' ){
        system("clear");
        std::cout << "Thank you for playing" << std::endl; 
        std::cout << "Game: 2150" << std::endl;
        std::cout << "Created by: Siwei & Meguta(Ahmed), 2018\n\n\n" << std::endl;
    
    } else if (tolower(userInput) == 'c'){
        system("clear");
        saveToFile("savedata.dat");
    
    } else {    
        std::cout << "[You have failed to enter a choice, please enter one of the listed options: ]\n" << std::endl;
        std::cin >> userInput;
    }
    
    return 0; 
}