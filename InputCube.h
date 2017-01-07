#ifndef INPUTCUBE
#define INPUTCUBE

//bool Debug = false;
int Green, Red, White, Orange, Blue, Yellow;
char temp;

void GetInput(); // get cube color input from user
void InputChecker(char Input); // check to see if input is a valid color
void PieceCounter (char Input); // keep track of number of valid number of piece entries 8 per color limit
// bool VerifyCube(char *Cube); // verify combination of colors is possible

void InputCube(char *Cube){
	Green=0, Red=0, White=0, Orange=0, Blue=0, Yellow=0;
	
	// input section

	// map color input to proper array location
	// GREEN side input

	std::cout << "Center piece orientation for input sequence:\n  G\nR W O Y\n  B\n";
	std::cout << "Please enter cube state\n";
	std::cout << "Use the first letter of the color \nG=Green, R=Red, W=White, O=Orange, B=Blue, Y=Yellow\n";
	std::cout << "Enter colors for GREEN side first in the following order \n0 1 2\n3 G 5\n6 7 8\n\n";
	std::cout << "0:";
	GetInput();
	Cube[15] = temp;//14
	std::cout << "1:";
	GetInput();
	Cube[41] = temp;
	std::cout << "2:";
	GetInput();
	Cube[16] = temp;
	std::cout << "3:";
	GetInput();
	Cube[34] = temp;
	std::cout << "Note skipping center input #4.\n";
	Cube[50] = 'G';
	std::cout << "5:";
	GetInput();
	Cube[35] = temp;
	std::cout << "6:";
	GetInput();
	Cube[3] = temp;
	std::cout << "7:";
	GetInput();
	Cube[26] = temp;
	std::cout << "8:";
	GetInput();
	Cube[4] = temp;

	// WHITE side input
	std::cout << "Enter colors for WHITE side first in the following order \n0 1 2\n3 W 5\n6 7 8\n\n";
	std::cout << "0:";
	GetInput();
	Cube[2] = temp;
	std::cout << "1:";
	GetInput();
	Cube[25] = temp;
	std::cout << "2:";
	GetInput();
	Cube[5] = temp;
	std::cout << "3:";
	GetInput();
	Cube[31] = temp;
	std::cout << "Note skipping center input #4.\n";
	Cube[49] = 'W';
	std::cout << "5:";
	GetInput();
	Cube[27] = temp;
	std::cout << "6:";
	GetInput();
	Cube[11] = temp;//8
	std::cout << "7:";
	GetInput();
	Cube[29] = temp;
	std::cout << "8:";
	GetInput();
	Cube[8] = temp;//11

	// RED side input
	std::cout << "Enter colors for RED side first in the following order \n0 1 2\n3 R 5\n6 7 8\n\n";
	std::cout << "0:";
	GetInput();
	Cube[13] = temp;
	std::cout << "1:";
	GetInput();
	Cube[33] = temp;
	std::cout << "2:";
	GetInput();
	Cube[1] = temp;
	std::cout << "3:";
	GetInput();
	Cube[47] = temp;
	std::cout << "Note skipping center input #4.\n";
	Cube[53] = 'R';
	std::cout << "5:";
	GetInput();
	Cube[32] = temp;
	std::cout << "6:";
	GetInput();
	Cube[24] = temp;//23
	std::cout << "7:";
	GetInput();
	Cube[40] = temp;
	std::cout << "8:";
	GetInput();
	Cube[12] = temp;//7
	
	// BLUE side input
	std::cout << "Enter colors for BLUE side first in the following order \n0 1 2\n3 B 5\n6 7 8\n\n";
	std::cout << "0:";
	GetInput();
	Cube[10] = temp;//9
	std::cout << "1:";
	GetInput();
	Cube[30] = temp;
	std::cout << "2:";
	GetInput();
	Cube[9] = temp;//10
	std::cout << "3:";
	GetInput();
	Cube[39] = temp;
	std::cout << "Note skipping center input #4.\n";
	Cube[52] = 'B';
	std::cout << "5:";
	GetInput();
	Cube[38] = temp;
	std::cout << "6:";
	GetInput();
	Cube[22] = temp;
	std::cout << "7:";
	GetInput();
	Cube[45] = temp;
	std::cout << "8:";
	GetInput();
	Cube[21] = temp;

	// ORANGE side input
	std::cout << "Enter colors for ORANGE side first in the following order \n0 1 2\n3 O 5\n6 7 8\n\n";
	std::cout << "0:";
	GetInput();
	Cube[6] = temp;
	std::cout << "1:";
	GetInput();
	Cube[36] = temp;
	std::cout << "2:";
	GetInput();
	Cube[18] = temp;//17
	std::cout << "3:";
	GetInput();
	Cube[28] = temp;
	std::cout << "Note skipping center input #4.\n";
	Cube[51] = 'O';
	std::cout << "5:";
	GetInput();
	Cube[43] = temp;
	std::cout << "6:";
	GetInput();
	Cube[7] = temp;//12
	std::cout << "7:";
	GetInput();
	Cube[37] = temp;
	std::cout << "8:";
	GetInput();
	Cube[19] = temp;
	
	// YELLOW side input
	std::cout << "Enter colors for YELLOW side first in the following order \n0 1 2\n3 Y 5\n6 7 8\n\n";
	std::cout << "0:";
	GetInput();
	Cube[17] = temp;//18
	std::cout << "1:";
	GetInput();
	Cube[42] = temp;
	std::cout << "2:";
	GetInput();
	Cube[14] = temp;//15
	std::cout << "3:";
	GetInput();
	Cube[44] = temp;
	std::cout << "Note skipping center input #4.\n";
	Cube[54] = 'Y';
	std::cout << "5:";
	GetInput();
	Cube[48] = temp;
	std::cout << "6:";
	GetInput();
	Cube[20] = temp;
	std::cout << "7:";
	GetInput();
	Cube[46] = temp;
	std::cout << "8:";
	GetInput();
	Cube[23] = temp;//24

}

// get input from user
void GetInput(){
	char Input;
	std::cin>> Input;
	Input = toupper(Input);
	InputChecker(Input);
}

// Make sure input is a valid color input
void InputChecker(char Input){
	if (Input =='G'||Input=='R'||Input=='W'||Input=='O'||Input=='Y'||Input=='B'){PieceCounter(Input);}
	else {std::cout << "That's not a valid input, try again: ";GetInput();}
}

// Make sure there are no more than eight pieces of any color
void PieceCounter(char Input){
	switch (Input){
	case 'G': 
		if (Green < 8){temp = Input;Green++;}
		else {std::cout << "Too many Green pieces. " << Green << " Try again: ";GetInput();};break;
	case 'R':
		if (Red < 8){temp = Input;Red++;}
		else {std::cout << "Too many Red pieces. " << Red << " Try again: ";GetInput();};break;
	case 'W':
		if (White < 8){temp = Input;White++;}
		else {std::cout << "Too many White pieces. " << White << " Try again: ";GetInput();}break;
	case 'O':
		if (Orange < 8){temp = Input;Orange++;}
		else {std::cout << "Too many Orange pieces. " << Orange << " Try again: ";GetInput();};break;
	case 'Y':
		if (Yellow < 8){temp = Input;Yellow++;}
		else {std::cout << "Too many Yellow pieces. " << Yellow << " Try again: ";GetInput();};break;
	case 'B':
		if (Blue< 8){temp = Input;Blue++;}
		else {std::cout << "Too many Blue pieces. " << Blue << " Try again: ";GetInput();};break;
	default: std::cout << "Error, Try again."; GetInput();
	};
}

#endif