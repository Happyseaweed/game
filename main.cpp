#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unistd.h>
#include <limits>
#include <term.h>
#include "functions.h"
#include "events.h"
#include "variables.h"
#include "saveload.cpp"



void ran (){
    srand(time(0));
        switch(rand() % 10 + 1){
            case 1: astroids(); break;
            case 2: blackhole(); break;
            case 3: oHeat(); break;
            case 4: meteor(); break;
            case 5: blackhole(); break;
            case 6: oHeat(); break;
            case 7: meteor(); break;
            case 8: oHeat(); break;
            case 9: blackhole(); break;
        }
}

//Function to print all the scanners at once:

    void allbegin(){
        std::cout << "Scanner Status: \n" << std::endl;
            atmo();
            usleep(200000);

            gravity();
            usleep(200000);

            reso();
            usleep(200000);

            water();
            usleep(200000);

            temperature();
            usleep(200000);

            science();
            usleep(200000);

            culture();
            usleep(200000);

            landing();
            usleep(200000);

            engine();
            usleep(200000);

            probe();
            usleep(200000);

            powerPercentage();
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
        std::cout << "[A] [Play/New Game]" << std::endl;
        std::cout << "[B] [Exit]" << std::endl;
        std::cout << "[L] [Load]" << std::endl;
        std::cin >> userInput;
//game:
    //while(tolower(userInput) != 'b')//-------------------------------------------------------------------------------------------------------------------------------------------
    if (tolower(userInput) == 'a' || tolower(userInput == 'l')){
    //Start up Message:
        system("clear");
        std::cout << "\n\n\n" << std::endl;
        slow_print(start);
        std::cout << '\n' << std::endl;
        slow_print(start2);
        std::cout << '\n' << std::endl;

    //Exploration Starts: //POP RIGHT HERE V
        slow_print("*As the ship sails into the dark abyss of space, You come across your first planet*\n\n\n");
        usleep(2000000);

    // Loading file
        if (tolower(userInput) == 'l'){
            loadFile("savedata.dat");
        }
    // Game Loop
        while(power >= 0){
            all();
            planet(varList[12]);
            if (land() == 0)
                return 0;
            system("clear");
            all();
            oHeat();
            std::cout << "[S] Save Game     " << "[C] Continue" << std::endl;
            std::cin >> userInput;
            if (tolower(userInput) == 's'){
                system("clear");
                saveToFile("savedata.dat");
            }
            varList[11] +=1;
            //-------------------------------------------------------------------------------
            all();
            planet(varList[12]);
            if (land() == 0)
                return 0;
            system("clear");
            all();
            blackhole();
            std::cout << "[S] Save Game     " << "[C] Continue" << std::endl;
            std::cin >> userInput;
            if (tolower(userInput) == 's'){
                system("clear");
                saveToFile("savedata.dat");
            }
            varList[11] +=1;
            //---------------------------------------------------------------------------------
            all();
            planet(varList[12]);
            if (land() == 0)
                return 0;
            system("clear");
            all();
            astroids();
            std::cout << "[S] Save Game     " << "[C] Continue" << std::endl;
            std::cin >> userInput;
            if (tolower(userInput) == 's'){
                system("clear");
                saveToFile("savedata.dat");
            }
            varList[11] +=1;
            //---------------------------------------------------------------------------------------
            all();
            planet(varList[12]);
            if (land() == 0)
                return 0;
            system("clear");
            all();
            meteor();
            std::cout << "[S] Save Game     " << "[C] Continue" << std::endl;
            std::cin >> userInput;
            if (tolower(userInput) == 's'){
                system("clear");
                saveToFile("savedata.dat");
            }
            varList[11] +=1;

        }
    }
    else if (tolower(userInput) == 'b' ){
        system("clear");
        std::cout << "Thank you for playing" << std::endl;
        std::cout << "Game: 2150" << std::endl;
        std::cout << "Created by: Siwei & Meguta(Ahmed), started in 2018\n\n\n" << std::endl;


    } else {
        std::cout << "[You have failed to enter a choice, please enter one of the listed options: ]\n" << std::endl;
        std::cin >> userInput;
    }

    return 0;
}
