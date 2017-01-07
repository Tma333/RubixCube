#include <iostream>
#include <fstream>
#include <string>

#include "DisplayCube.h"
#include "InputCube.h"
#include "ReadFromFile.h"
#include "Rotate.h"
#include "SaveCube.h"
#include "Solve.h"
#include "SolveBottomLayer.h"
#include "SolveMiddleLayer.h"
#include "SolveTopLayer.h"
#include "Verification.h"

int main() {

	bool Answer=false;
	do {
		// DEFAULT STATE CUBE
		char Cube[60] ={'X',
			'R','W','G','G','W','O','O','W','B','B',
			'W','R','R','Y','G','G','Y','O','O','Y',
			'B','B','Y','R','W','G','W','O','W','B',
			'W','R','R','G','G','O','O','B','B','R',
			'G','Y','O','Y','B','Y','R','Y','W','G',
			'O','B','R','Y'};
	
		// Read cube state from text file used for test purposes
		//ReadFile(Cube);

		// Get cube state from user input
		InputCube(Cube);

		// Save inputed cube to text file
		CubeSave(Cube);

		DisplayCube(Cube);

		// verify cube is valid
		if (VerifyCube(Cube)==true){std::cout<< "Cube is valid\n\n";Solve(Cube);}
		else {std::cout << "Cube is invalid\n";}

		// Do again?
		std::cout << "\nSolver another cube? (y|n):";
		char temp;
		std::cin >> temp;
		temp = tolower(temp);
		if (temp=='y'){
			Answer=true;
		}
		else{
			Answer=false;
		}
	} while (Answer==true);

	return 0;
}