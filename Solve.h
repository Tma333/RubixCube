#ifndef SOLVE
#define SOLVE

bool SolveDebug = false;

void TopLayer(char *Cube);
void MiddleLayer(char *Cube);
void BottomLayer(char *Cube);

void Solve(char *Cube){
	std::cout << "Follow these instructions to solve cube.  \nThe color side is followed by R or L.  \nR = clockwise turn. L = counter clockwise turn.\n\n";
	
	TopLayer(Cube);
	std::cout << "\n***Top layer solved***\n\n";
	DisplayCube(Cube);
	
	MiddleLayer(Cube);
	std::cout << "\n***Middle layer solved***\n\n";
	DisplayCube(Cube);
	
	BottomLayer(Cube);
	std::cout << "\n\n***CUBE SOLVED***\n";
	DisplayCube(Cube);
}



#endif