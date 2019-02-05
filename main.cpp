#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <limits>
#include <term.h>
#include "functions.h"
#include "events.h"
#include "variables.h"

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
    }

    void all(){
        std::cout << "Scanner Status: \n" << std::endl;
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
    }


//Texts to be printed to console: 
    std::string start = "It is the year 2089, the human civilization has come to an end. Earth is no longer habitable, the humans built"
                    " a space ship with their last availible resources. The ship is called C1000. The 1000 " 
                    " astronouts onboard are in deep sleep. Their mission is to find a new habitable planet and continue the colonize it "
                    " in order to to coninue the human civilization.";

    std::string start2 = "[You are playing as the ship AI, your responsibility is to find the most suitable planet for human civilization.]\n"
                         "[This here is your control panel, where you can see the scanners.]";



//Main

int main(){
    //Welcome Page:
        char userInput;
        char response;
        printf("\nWelcome To Space Seed!\n");
        std::cout << "[A] [New Game]" << std::endl;
        std::cout << "[B] [Exit]" << std::endl;
        std::cin >> userInput;
//game:
while(tolower(userInput) != 'b')
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
    /*
    //Game control Panel:
        system("clear");
        allbegin();
    //Exploration Starts:
    
        slow_print("*You are about to enter the orbit of your first planet*\n\n\n");
        //1st
        system("clear");
        all();
        planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon);
        land();
        system("clear");

        //2nd
        all();        
        astroids();
        std::cout << "Enter C to Continue!" << std::flush;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
        all();
        planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon);
        land();
        system("clear");
        
        //3rd
        all();
        astroids();
        std::cout << "Enter C to Continue!" << std::flush;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
        all();
        planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon);
        land();
        system("clear");
        
        //4th
        all();
        astroids();
        std::cout << "Enter C to Continue!" << std::flush;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
        all();
        planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon);
        land();
        system("clear");
        
        //5th
        all();
        astroids();
        std::cout << "Enter C to Continue!" << std::flush;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
        all();
        planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon);
        land(); 
        */
        ran();
        //ran();
        //meteor(atmoPc, resoPc);
        //all();
        //planet(varList, atmoCon, gravCon, resoCon, wateCon, tempCon);
        //usleep(1000000);
        
       
    } else {
        
        std::cout << "[You have failed to enter a choice, please enter one of the listed options: ]\n" << std::endl;
        std::cin >> userInput;
    }
    return 0;
//End credits: 
    if (tolower(userInput) == 'b' ){
    std::cout << "Thank you for playing" << std::endl;
    std::cout << "Game: Space Seed" << std::endl;
    std::cout << "Created by: Siwei Du, 2018" << std::endl;
    } 
}