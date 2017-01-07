#ifndef SOLVEMIDDLELAYER
#define SOLVEMIDDLELAYER

void MidSolve(char *Cube, int PositionCounter);
void MidLowerCheck(char *Cube);
void MidMidCheck(char *Cube);
void SidePositionCalc(char *Cube, int Position, int &RightSide, int &LeftSide);

void MiddleLayer(char *Cube){
	//mid main
	MidLowerCheck(Cube);
	MidMidCheck(Cube);	
}

// look for target pieces on the bottom layer
void MidLowerCheck(char *Cube){
	bool NonYellow = true;
	while (NonYellow==true){
		NonYellow=false;
		for (int i=42;i<=48;i+=2){
			if (Cube[i]!='Y'&&Cube[i-1]!='Y'){
				if (SolveDebug==true){std::cout << "Position:" << i << " Colors:" << Cube[i] << ":" << Cube[i-1] << std::endl;}
				NonYellow=true;
				MidSolve(Cube, i);
			}
		}
	}
}

// look for target pieces in middle layer
void MidMidCheck(char *Cube){
	bool Solved = false;
	while (Solved==false){
		Solved=true;
		if (Cube[50]!=Cube[35]){MidLeft(Cube, Cube[51]);MidLowerCheck(Cube);Solved=false;}
		else if (Cube[51]!=Cube[37]){MidLeft(Cube, Cube[52]);MidLowerCheck(Cube);Solved=false;}
		else if (Cube[52]!=Cube[39]){MidLeft(Cube, Cube[53]);MidLowerCheck(Cube);Solved=false;}
		else if (Cube[53]!=Cube[33]){MidLeft(Cube, Cube[50]);MidLowerCheck(Cube);Solved=false;}
	}
}

void MidSolve(char *Cube, int Position){
	int SidePositionRight, SidePositionLeft, PositionLeft, PositionRight, PositionOppEnd;
	SidePositionRight=Position;
	SidePositionLeft=Position;
	PositionLeft=Position;
	PositionRight=Position;
	PositionOppEnd=Position;

	// position rotate loop check
	if (Position==42){PositionLeft+=2;PositionRight+=6;PositionOppEnd+=4;}
	else if (Position==44){PositionLeft+=2;PositionRight-=2;PositionOppEnd+=4;}
	else if (Position==46){PositionLeft+=2;PositionRight-=2;PositionOppEnd-=4;}
	else if (Position==48){PositionLeft-=6;PositionRight-=2;PositionOppEnd-=4;}

	// set side positions
	SidePositionCalc(Cube, Position, SidePositionRight, SidePositionLeft);

	// move into position

	if (Cube[Position]!=Cube[Position-16]){
		if (Cube[Position]==Cube[SidePositionRight]){
			Rotate(Cube, "yr");Position=PositionRight;SidePositionCalc(Cube, Position, SidePositionRight, SidePositionLeft);}
		else if (Cube[Position]==Cube[SidePositionLeft]){
			Rotate(Cube, "yl");Position=PositionLeft;SidePositionCalc(Cube, Position, SidePositionRight, SidePositionLeft);}
		else {
			Rotate(Cube, "yr");Rotate(Cube, "yr");Position=PositionOppEnd;SidePositionCalc(Cube, Position, SidePositionRight, SidePositionLeft);}
	}
	
	// rotate direction
	if (Cube[Position-1]==Cube[SidePositionRight]){
		MidRight(Cube, Cube[SidePositionRight]);}
	else {MidLeft(Cube, Cube[SidePositionLeft]);}
}

void SidePositionCalc(char *Cube, int Position, int &RightSide, int &LeftSide){
	//reset side positions
	RightSide=Position;
	LeftSide=Position;
	//set side positions
	if (Position==42){RightSide-=10;LeftSide-=14;}
	else if (Position==48){RightSide-=18;LeftSide-=22;}
	else {RightSide-=18;LeftSide-=14;}
}
#endif