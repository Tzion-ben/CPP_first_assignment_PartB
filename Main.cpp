#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include <thread>


using namespace ariel;
using namespace std;

/*this main function will print out the snowman*/
int main (){
 
    array<int, MAX_INPUT_SIZE> input_snowman{};

    for(int i = 0; i<5 ; i++){
        for(int j=0 ; j<MAX_INPUT_SIZE ; j++)
            {
                /*generate rendom integers for the snowman*/
                srand(time(NULL));
                input_snowman.at(j) = (rand()% 4 +1);
                this_thread::sleep_for(chrono::milliseconds(700) ); 
           }
        
        /*create an integer of 8 digits for the snowman input*/
        int randInput = 0;
        for(int j=0 ; j<MAX_INPUT_SIZE ; j++)
            {randInput = randInput * 10 + input_snowman.at(j);}

        cout << snowman(randInput) << endl;
        cout << "\n" << endl;
       }
    
    return 0;
}
