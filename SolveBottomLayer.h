#ifndef SOLVEBOTTOMLAYER
#define SOLVEBOTTOMLAYER

void BLCornerPhaseOne(char *Cube);
void BLCornerPhaseTwo(char *Cube);
void BLInBetweenPieces(char *Cube);


void BottomLayer(char *Cube){

	// Solve bottom layer corner pieces
	BLCornerPhaseOne(Cube);
	
	//std::cout << "DOUBLE CHECK THIS\n";
	//DisplayCube(Cube);

	BLCornerPhaseTwo(Cube);
	std::cout << "\n\n***Bottom corners in position***\n\n";
	DisplayCube(Cube);
	BLInBetweenPieces(Cube);

	// Solve bottom layer in between pieces

}

void BLCornerPhaseOne(char *Cube){
	int Position=NULL, SecondPosition=NULL;
	bool cr=false, cg=false, co=false;

	// Find first corner piece
	for (int i=13;i<=24;i+=3){
		cr=false;cg=false;co=false;
		int j=i;
		for(j;j<i+3;j++){
			if (Cube[j]=='G'){cg=true;}
			else if (Cube[j]=='R'){cr=true;}
			else if (Cube[j]=='O'){co=true;}
		}
		// identify corner piece positions
		if (cr==true&&cg==true){Position=i;}
		else if (co==true&&cg==true){SecondPosition=i;}
		//std::cout << std::endl << cr << ":" << cg << ":" << co << ":" << i << std::endl;
	}

	if (Position==16&&SecondPosition==13){BottomPhaseOne(Cube,'g','r');}
	else if (Position==16){Rotate(Cube, "yr");}
	else if (Position==19){Rotate(Cube,"yl");Rotate(Cube,"yl");}
	else if (Position==22){Rotate(Cube,"yl");}
	
	// find second corner piece
	for (int i=13;i<=24;i+=3){
		cr=false;cg=false;co=false;
		int j=i;
		for(j;j<i+3;j++){
			if (Cube[j]=='G'){cg=true;}
			else if (Cube[j]=='R'){cr=true;}
			else if (Cube[j]=='O'){co=true;}
		}
		// identify corner piece positions
		if (cr==true&&cg==true){Position=i;}
		else if (co==true&&cg==true){SecondPosition=i;}
		//std::cout << std::endl << cr << ":" << cg << ":" << co << ":" << i << std::endl;
	}

	//std::cout << std::endl << "postion:" << Position << " SecondPosition:" << SecondPosition << std::endl;
	//DisplayCube(Cube);

	// move second corner piece into position
	if (SecondPosition==19){BottomPhaseOne(Cube, 'o', 'g');}
	else if (SecondPosition==22){Rotate(Cube,"yl");BottomPhaseOne(Cube,'g','r');}


	// position corner three and four
	// confirm corner four location
	cr=false;
	for (int i=19;i<=21;i++){
		if (Cube[i]=='R'){cr=true;}
	}
	// rotate into correct order

	if (cr==true){BottomPhaseOne(Cube, 'b','o');}

}

void BLCornerPhaseTwo(char *Cube){
	int YellowCounter=0, NonYellowcounter=0, YellowPosition=NULL;
	int NonYellowPositionOne=NULL, NonYellowPositionTwo=NULL;
	bool Solved = false;
	while (Solved==false){
	//for (int j=0;j<4;j++){
		YellowCounter=0;
		for (int i=14;i<=23;i+=3){
			if (Cube[i]=='Y'){YellowCounter++;YellowPosition=i;}
			else {
				NonYellowPositionOne=i;
				NonYellowcounter++;
				if(NonYellowcounter==1){NonYellowPositionTwo=i;}
			}
		}
		if(YellowCounter==1){
			if(YellowPosition==14){BottomPhaseTwo(Cube,'b');}
			else if (YellowPosition==17){BottomPhaseTwo(Cube,'r');}
			else if (YellowPosition==20){BottomPhaseTwo(Cube,'g');}
			else if (YellowPosition==23){BottomPhaseTwo(Cube,'o');}
		}
		else if (YellowCounter==2){
			// isolate a target piece
			if (Cube[NonYellowPositionOne+1]=='Y'){
				NonYellowPositionOne=NonYellowPositionTwo;
			}
			//rotate pieces
			if (NonYellowPositionOne==14){BottomPhaseTwo(Cube,'b');}
			else if (NonYellowPositionOne==17){BottomPhaseTwo(Cube,'r');}
			else if (NonYellowPositionOne==20){BottomPhaseTwo(Cube,'g');}
			else if (NonYellowPositionOne==23){BottomPhaseTwo(Cube,'o');}
		}
		else if (YellowCounter==0){
			for (int i=14;i<=23;i+=3){
				if (Cube[i+1]=='Y'){NonYellowPositionOne=i;}
			}
			//rotate pieces
			if (NonYellowPositionOne==14){BottomPhaseTwo(Cube,'b');}
			else if (NonYellowPositionOne==17){BottomPhaseTwo(Cube,'r');}
			else if (NonYellowPositionOne==20){BottomPhaseTwo(Cube,'g');}
			else if (NonYellowPositionOne==23){BottomPhaseTwo(Cube,'o');}
		}
		else if (YellowCounter==4){Solved=true;}
	}
}

void BLInBetweenPieces(char *Cube){
	int Position=NULL;
	int YellowCounter=0, NonYellowCounter=0, NonYellowOne, NonYellowTwo;
	bool cy=false, cg=false;

	// Locate first target piece
	for (int i=41;i<=48;i+=2){
		cy=false;cg=false;
		for (int j=i;j<=i+1;j++){
			if (Cube[j]=='G'){cg=true;}
			else if (Cube[j]=='Y'){cy=true;}
		}
		if (cy==true&&cg==true){Position=i;}
	}
	if (Position==43){BotRight(Cube,'b');}
	else if (Position==45){BotRight(Cube,'o');}
	else if (Position==47){BotLeft(Cube,'b');}

	// Rotate three pieces into position
	if (Cube[45]=='R'||Cube[46]=='R'){BotLeft(Cube,'g');}
	else if (Cube[45]=='O'||Cube[46]=='O'){BotRight(Cube,'g');}

	// Match colors and isolate non matching colors
	for (int i=42;i<=48;i+=2){
		if (Cube[i]=='Y'){YellowCounter++;}
		else if (Cube[i]!='Y'){
			if (NonYellowCounter==0){NonYellowCounter++;NonYellowOne=i;}
			else if (NonYellowCounter==1){NonYellowCounter++;NonYellowTwo=i;}
		}
	}

	// Solve match color
	if (YellowCounter==0){BotLeft(Cube, 'g');BotReverse(Cube, 'g');BotLeft(Cube, 'b');BotReverse(Cube, 'b');}
	else if (YellowCounter==2){
		if (NonYellowOne==42&&NonYellowTwo==44){BotLeft(Cube,'b');BotReverse(Cube,'b');}
		else if (NonYellowOne==44&&NonYellowTwo==46){BotLeft(Cube,'r');BotReverse(Cube,'r');}
		else if (NonYellowOne==46&&NonYellowTwo==48){BotLeft(Cube,'g');BotReverse(Cube,'g');}
		else if (NonYellowOne==42&&NonYellowTwo==48){BotLeft(Cube,'o');BotReverse(Cube,'o');}
		else if (NonYellowOne==42&&NonYellowTwo==46){BotReverse(Cube,'r');BotLeft(Cube,'r');}
		else if (NonYellowOne==44&&NonYellowTwo==48){BotReverse(Cube,'g');BotLeft(Cube,'g');}
	}
}

#endif 