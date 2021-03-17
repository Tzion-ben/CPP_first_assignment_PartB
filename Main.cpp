#include "snowman.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;

/*this main function will print out the snowman*/
int main (){
    
    cout << snowman(11114411) << endl;  

    array<int, MAX_INPUT_SIZE> input_snowman{};

    for(int i = 0; i<5 ; i++){
        for(int j=0 ; j<MAX_INPUT_SIZE ; j++)
            {input_snowman.at(j) = (rand()% 4 +1);}
        
        int randInput = 0;
        for(int j=0 ; j<MAX_INPUT_SIZE ; j++)
            {randInput = randInput * 10 + input_snowman.at(j);}

        cout << snowman(randInput) << endl;
        cout << "\n" << endl;
       }
    
    return 0;
}
