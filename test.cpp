#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

// run tests in this file!

int randomNumberGenerator(){ // generates a random number from 1 to 10
    srand(time(NULL));
    int randNumber = 1 + (rand()%10);
    return randNumber;
}

int main(){
    int a = 0;
    for (int i = 0; i < 10; i++){
        a = randomNumberGenerator();
        cout << a;
    }
}