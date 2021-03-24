/*
* AUTHORS: <Tzion Beniaminov>
* This code is about drawing a Snowman from input 8 digits number
* in range of 11111111 to 44444444 
*/

#include <iostream>
#include <sstream>
#include "snowman.hpp"
#include <string>
#include <array>
using namespace std;

namespace ariel {
	
	string snowman(int inputNum) {
	
	int copy_inputNum = inputNum;/*create a copy of the input to change the value of it*/
	if(!validInput(copy_inputNum)){
		throw out_of_range{"invalid input"};
	}

	/*put the input to an array*/
	array<int, MAX_INPUT_SIZE> input_snowman{};
	for(int i=MAX_INPUT_SIZE-1; i>=0 ; i--){
		input_snowman.at(i) = inputNum%CUT_NUMBER;
		inputNum/=CUT_NUMBER;
	}
	/*insert the hat of the smowman*/
	string all_snow_Man = " "+hat(input_snowman[HAT]);

	/*create the right and left armes*/
	string rigth_left_arm_part;

	/*for each input will create a different sanoeman*/
		if(input_snowman[LEFT_ARM] == RIGHT_ARM_UP){
			rigth_left_arm_part = left_up(input_snowman);}
		/*case 1: <
		 *case 3: >
		 *case 4: " " */
		else {rigth_left_arm_part = left_down_rigth_up_arms(input_snowman);}

	string base_part = "\n ("+base(input_snowman[BASE])+")";

	/*combine all the parts together*/
	all_snow_Man = all_snow_Man + " "+rigth_left_arm_part + base_part;
	
	return all_snow_Man;
	}

	/*
	*gets the input number for the snowman and checks if
	*it's in the rigth range
	*/
	bool validInput (int inputNum){
		int copy_inputNum = inputNum;
		int lastDigit = 0;
    	int numSize = 0;

		while(copy_inputNum>0){
			numSize++;
			lastDigit = copy_inputNum%CUT_NUMBER;
			if(lastDigit>4 || lastDigit<1){return false;}
			copy_inputNum/=CUT_NUMBER;	
		}
		return (numSize - MAX_INPUT_SIZE) == 0;
		
	}

	/*case of lest arm up, (x==2)*/
	string left_up(const array<int ,MAX_INPUT_SIZE> &input_snowman){
		string LNR = eye_R_or_L(input_snowman[LEFT_EYE])+nose_mouth(input_snowman[NOSE_MOUTH])+eye_R_or_L(input_snowman[RIGTH_EYE]);
		string TTT = torso(input_snowman[TORSO]);
		
		if(input_snowman[RIGHT_ARM]==RIGHT_ARM_UP)
			{return "\\("+LNR+")/\n  ("+TTT+")";}
		return "\\("+LNR+")\n("+TTT+")"+rightArm(input_snowman[RIGHT_ARM]);
		
	}

	/*case of left arm down , (x==1)or(x==3)or(x==4)*/
	string left_down_rigth_up_arms(const array<int ,MAX_INPUT_SIZE> &input_snowman){
		string LNR = eye_R_or_L(input_snowman[LEFT_EYE])+nose_mouth(input_snowman[NOSE_MOUTH])+eye_R_or_L(input_snowman[RIGTH_EYE]);
		string TTT = torso(input_snowman[TORSO]);

		if(input_snowman[RIGHT_ARM] == RIGHT_ARM_UP)
			{return "("+LNR+")/\n"+leftArm(input_snowman[LEFT_ARM])+"("+TTT+")";}
		return "("+LNR+")\n"+leftArm(input_snowman[LEFT_ARM])+"("+TTT+")"+rightArm(input_snowman[RIGHT_ARM]);			
		
	}
	
	/**
	* returns the hat -H : in case 1: Straw Hat : _===_
 	*                     in case 2: Mexican Hat:   ___
    *                                              ..... 
 	* 				      in case 3: Fez:  _  
 	*						              /_\ 
 	*                     in case 4: Russian Hat:  ___ 
	*				   						      (_*_)
 	*/
	string hat (int x){
		switch(x){
			case 1 : return "_===_\n";
			case 2 : return " ___\n .....\n";
			case 3 : return "  _ \n  /_\\\n";
			case 4 : return " ___\n (_*_)\n";
			default : return "";
		}
	}

	/**
	* returns the nose/mouth -N : in case 1: Normal : ,
 	*                             in case 2: Dot : .
 	* 				              in case 3: Line : _
 	*                             in case 4: None : 
	*/
	string nose_mouth (int x){
		switch(x){
			case 1 : return ",";
			case 2 : return ".";
			case 3 : return "_";
			//case 4
			default : return " ";
		}
	}

	/**
	* returns the eye R and L : in case 1: Dot : .
 	*                           in case 2: Bigger Dot : o
 	* 				            in case 3: Biggest Dot : O
 	*                           in case 4: Closed : -
	*/
	string eye_R_or_L (int x){
		switch(x){
			case 1 : return ".";
			case 2 : return "o";
			case 3 : return "O";
			case 4 : return "-";
			default : return "";
		}
	}

	/**
	* returns the leftArm -X in case 1: Normal Arm : <
 	*                        in case 2: Upwards Arm : \
 	* 				         in case 3: Downwards Arm : /
 	*                        in case 4: None : 
	*/
	string leftArm (int x){
		switch(x){
			case 1 : return "<";
			case 2 : return "\\";
			case 3 : return "/";
			//case 4
			default : return " ";
		}
	}

	/**
	* returns the rightArm -Y in case 1: Normal Arm : >
 	*                         in case 2: Upwards Arm : /
 	* 				          in case 3: Downwards Arm : \
 	*                         in case 4: None : 
	*/
	string rightArm (int x){
		switch(x){
			case 1 : return ">";
			case 2 : return "/";
			case 3 : return "\\";
			//case 4
			default : return " ";
		}
	}

	/**
	* returns the torso -T   in case 1: Buttons : :
 	*                        in case 2: Vest : ] [
 	* 				         in case 3: Inward Arms : > <
 	*                        in case 4: None : 
	*/
	string torso (int x){
		switch(x){
			case 1 : return " : ";
			case 2 : return "] [";
			case 3 : return "> <";
			//case 4
			default : return "   ";
		}
	}

	/**
	* returns the base -B   in case 1: Buttons : :
 	*                       in case 2: Upwards Arm : " "
 	* 				        in case 3: Downwards Arm : ___
 	*                       in case 4: None : 
	*/
	string base (int x){
		switch(x){
			case 1 : return " : ";
			case 2 : return "\" \"";
			case 3 : return "___";
			//case 4
			default : return "   ";
		}
	}
}