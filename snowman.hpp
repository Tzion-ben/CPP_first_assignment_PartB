#include <sstream>
#include <string>
#include <array>

/*#DEFINE constants*/
constexpr int CUT_NUMBER = 10;
constexpr int MAX_INPUT_SIZE = 8;

const int HAT = 0;
const int NOSE_MOUTH = 1;
const int LEFT_EYE = 2;
const int RIGTH_EYE = 3;
const int LEFT_ARM = 4;
const int RIGHT_ARM = 5;
const int TORSO = 6;
const int BASE = 7;

const int RIGHT_ARM_UP = 2;

namespace ariel { 
	std::string snowman(int inputNum);

	/*declaration to private function*/
	bool validInput (int inputNum);
	std::string hat (int x);
	std::string nose_mouth (int x);
	std::string eye_R_or_L (int x);
	std::string leftArm (int x);
	std::string rightArm (int x);
	std::string torso (int x);
	std::string base (int x);

	std::string left_down_rigth_up_arms(const std::array<int ,MAX_INPUT_SIZE> &input_snowman);
	std::string left_up(const std::array<int ,MAX_INPUT_SIZE> &input_snowman);
	//////////////////////////////
};