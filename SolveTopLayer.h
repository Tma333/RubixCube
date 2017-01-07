#ifndef SOLVETOPLAYER
#define SOLVETOPLAYER

void TLCorners(char *Cube);
void TLInBetweenPieces(char *Cube);

void TopLayer(char *Cube){
	// Position top layer corner pieces
	TLCorners(Cube);

	// Position top layer in between pieces
	TLInBetweenPieces(Cube);
}

void TLCorners(char *Cube){
	//corner 1 (123)
	// find piece
	SolveDebug=false;
	
	bool TargetPiece=false;
	int i=1, PositionNumber=NULL;
	while (TargetPiece==false && i<24){
		bool cw=false, cg=false, cr=false;
		for (int j =i;j<i+3;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='G'){cg=true;}
			else if (Cube[j]=='R'){cr=true;}
		}
		if (cw==true&&cg==true&&cr==true){TargetPiece=true;}
		else {i+=3;}
	}
	// reposition instructions
	switch (PositionNumber){
	case 1:{Rotate(Cube, "wl");Rotate(Cube, "rl");break;}
	case 3:{Rotate(Cube, "gr");Rotate(Cube, "rr");break;}
	case 4:{Rotate(Cube, "gl");Rotate(Cube, "gl");Rotate(Cube, "rr");break;}
	case 5:{Rotate(Cube, "wl");break;}
	case 6:{Rotate(Cube, "gr");break;}
	case 7:{Rotate(Cube, "or");Rotate(Cube, "gr");break;}//12
	case 8:{Rotate(Cube, "wr");Rotate(Cube, "wr");break;}//11
	case 9:{Rotate(Cube, "bl");Rotate(Cube, "rl");break;}//10
	case 10:{Rotate(Cube, "rl");break;}//9
	case 11:{Rotate(Cube, "wr");break;}//8
	case 12:{Rotate(Cube, "rr");Rotate(Cube, "rr");Rotate(Cube, "gl");break;}//7
	case 13:{Rotate(Cube, "gl");break;}
	case 14:{Rotate(Cube, "gl");Rotate(Cube, "gl");Rotate(Cube, "wl");break;}//15
	case 15:{Rotate(Cube, "rr");break;}//14
	case 16:{Rotate(Cube, "gl");Rotate(Cube, "rr");break;}
	case 17:{Rotate(Cube, "gr");Rotate(Cube, "gr");break;}//18
	case 18:{Rotate(Cube, "ol");Rotate(Cube, "gr");break;}//17
	case 19:{Rotate(Cube, "bl");Rotate(Cube, "wl");Rotate(Cube, "wl");break;}
	case 20:{Rotate(Cube, "ol");Rotate(Cube, "gl");Rotate(Cube, "rr");break;}
	case 21:{Rotate(Cube, "bl");Rotate(Cube, "bl");Rotate(Cube, "rl");break;}
	case 22:{Rotate(Cube, "br");Rotate(Cube, "rl");break;}
	case 23:{Rotate(Cube, "rr");Rotate(Cube, "rr");break;}//24
	case 24:{Rotate(Cube, "rr");Rotate(Cube, "gl");break;}//23
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==2){std::cout << "Corner 1 in position" << std::endl;}

	//corner 2 (4 5 6)
	i=4;
	TargetPiece = false;
	while (TargetPiece==false && i<24){
		bool cw=false, cg=false, co=false;
		for (int j =i;j<i+3;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='G'){cg=true;}
			else if (Cube[j]=='O'){co=true;}
		}
		if (cw==true&&cg==true&&co==true){TargetPiece=true;}
		else {i+=3;}
	} 
	switch (PositionNumber){
	case 4:{Rotate(Cube, "or");Rotate(Cube, "yl");Rotate(Cube, "ol");Rotate(Cube, "ol");break;}
	case 6:{Rotate(Cube, "or");Rotate(Cube, "or");Rotate(Cube, "yr");Rotate(Cube, "ol");break;}
	case 7:{Rotate(Cube, "br");Rotate(Cube, "ol");Rotate(Cube, "ol");break;}//12
	case 8:{Rotate(Cube, "br");Rotate(Cube, "yr");Rotate(Cube, "ol");break;}//11
	case 9:{Rotate(Cube, "or");break;}//10
	case 10:{Rotate(Cube, "br");Rotate(Cube, "or");break;}//9
	case 11:{Rotate(Cube, "bl");Rotate(Cube, "bl");Rotate(Cube, "ol");Rotate(Cube, "ol");break;}//8
	case 12:{Rotate(Cube, "bl");Rotate(Cube, "bl");Rotate(Cube, "yr");Rotate(Cube, "ol");break;}//7
	case 13:{Rotate(Cube, "yl");Rotate(Cube, "ol");break;}
	case 14:{Rotate(Cube, "yl");Rotate(Cube, "yl");Rotate(Cube, "ol");Rotate(Cube, "ol");break;}//15
	case 15:{Rotate(Cube, "yl");Rotate(Cube, "yl");Rotate(Cube, "bl");Rotate(Cube, "or");break;}//14
	case 16:{Rotate(Cube, "ol");break;}
	case 17:{Rotate(Cube, "yl");Rotate(Cube, "ol");Rotate(Cube, "ol");break;}//18
	case 18:{Rotate(Cube, "or");Rotate(Cube, "yr");Rotate(Cube, "ol");break;}//17
	case 19:{Rotate(Cube, "yr");Rotate(Cube, "ol");break;}
	case 20:{Rotate(Cube, "ol");Rotate(Cube, "ol");break;}
	case 21:{Rotate(Cube, "bl");Rotate(Cube, "or");break;}
	case 22:{Rotate(Cube, "bl");Rotate(Cube, "bl");Rotate(Cube, "or");break;}
	case 23:{Rotate(Cube, "bl");Rotate(Cube, "yr");Rotate(Cube, "ol");break;}//24
	case 24:{Rotate(Cube, "bl");Rotate(Cube, "ol");Rotate(Cube, "ol");break;}//23
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==5){std::cout << "Corner 2 in position"<< std::endl;}


	// due to the restructuring of the cube numbering system, position of corner 3 and corner 4 are checked out of order.
	// new position of corner 3 is now (10 11 12)
	// corner 3 (7 8 9)
	i=7;
	TargetPiece = false;
	while (TargetPiece==false && i<24){
		bool cw=false, cr=false, cb=false;
		for (int j =i;j<i+3;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='B'){cb=true;}
			else if (Cube[j]=='R'){cr=true;}
		}
		if (cw==true&&cb==true&&cr==true){TargetPiece=true;}
		else {i+=3;}
	}
	switch(PositionNumber){
	case 7:{Rotate(Cube,"bl");break;}//12
	case 8:{Rotate(Cube,"br");Rotate(Cube,"rr");Rotate(Cube,"yl");Rotate(Cube,"rl");break;}//11
	case 9:{Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"br");break;}//10
	case 10:{Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"br");}//9

	case 12:{Rotate(Cube,"bl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"br");break;}//7
	case 13:{Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 14:{Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"br");break;}//15
	case 15:{Rotate(Cube,"yr");Rotate(Cube,"br");break;}//14
	case 16:{Rotate(Cube,"yl");Rotate(Cube,"rr");Rotate(Cube,"yl");Rotate(Cube,"rl");break;}
	case 17:{Rotate(Cube,"yl");Rotate(Cube,"bl");Rotate(Cube,"bl");break;}//18
	case 18:{Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"br");break;}//17
	case 19:{Rotate(Cube,"rr");Rotate(Cube,"yl");Rotate(Cube,"rl");break;}
	case 20:{Rotate(Cube,"br");Rotate(Cube,"br");break;}
	case 21:{Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 22:{Rotate(Cube,"bl");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 24:{Rotate(Cube,"br");break;}//23
	case 23:{Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"br");break;}//24
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==11){std::cout << "Corner 3 in position" << std::endl;}
	
	// New positon of corner for is now (7 8 9) 
	//corner 4 (10 11 12)
	i=7;
	TargetPiece = false;
	while (TargetPiece==false && i<24){
		bool cw=false, co=false, cb=false;
		for (int j =i;j<i+3;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='B'){cb=true;}
			else if (Cube[j]=='O'){co=true;}
		}
		if (cw==true&&cb==true&&co==true){TargetPiece=true;}
		else {i+=3;}
	}
	switch (PositionNumber){
	case 7:{Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");break;}//12

	case 9:{Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"yl");Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");break;}//10
	case 13:{Rotate(Cube,"br");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"bl");break;}
	case 14:{Rotate(Cube,"br");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");break;}//15
	case 15:{Rotate(Cube,"ol");Rotate(Cube,"yl");Rotate(Cube,"yl");Rotate(Cube,"or");break;}//14
	case 16:{Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");break;}
	case 17:{Rotate(Cube,"br");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");break;}//18
	case 18:{Rotate(Cube,"yl");Rotate(Cube,"yl");Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");break;}//17
	case 19:{Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");break;}
	case 20:{Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"br");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"bl");break;}
	case 21:{Rotate(Cube,"yl");Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");break;}
	case 22:{Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"yl");Rotate(Cube,"bl");break;}
	case 23:{Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"yl");Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");break;}//24
	case 24:{Rotate(Cube,"ol");Rotate(Cube,"yr");Rotate(Cube,"or");break;}//23
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==8){std::cout << "Corner 4 in position" << std::endl;}

}

void TLInBetweenPieces(char *Cube){
	bool TargetPiece=false;
	int i=NULL, PositionNumber=NULL;

	// toplayer middle pieces
	// middle 25 26
	i=25;
	TargetPiece = false;
	while (TargetPiece==false && i<48){
		bool cw=false, cg=false;
		for (int j =i;j<i+2;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='G'){cg=true;}
		}
		if (cw==true&&cg==true){TargetPiece=true;}
		else {i+=2;}
	}
	
	//std::cout << "Position: " << PositionNumber << std::endl;
	switch (PositionNumber){
	case 26:{Rotate(Cube,"gl");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rr");Rotate(Cube,"rr");Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"yl");Rotate(Cube,"ol");Rotate(Cube,"wl");break;}
	case 27:{Rotate(Cube,"bl");Rotate(Cube,"gr");Rotate(Cube,"rr");Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"wl");break;}
	case 28:{Rotate(Cube,"ol");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gr");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 29:{Rotate(Cube,"rl");Rotate(Cube,"or");Rotate(Cube,"gr");Rotate(Cube,"gr");Rotate(Cube,"rr");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 30:{Rotate(Cube,"ol");Rotate(Cube,"rr");Rotate(Cube,"bl");Rotate(Cube,"or");Rotate(Cube,"rl");Rotate(Cube,"wr");break;}
	case 31:{Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"ol");Rotate(Cube,"bl");Rotate(Cube,"gr");Rotate(Cube,"wr");break;}
	case 32:{Rotate(Cube,"br");Rotate(Cube,"gl");Rotate(Cube,"rr");Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 33:{Rotate(Cube,"wr");Rotate(Cube,"or");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gl");break;}
	case 34:{Rotate(Cube,"wr");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"rr");Rotate(Cube,"wr");break;}
	case 35:{Rotate(Cube,"wl");Rotate(Cube,"rr");Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"ol");Rotate(Cube,"wl");break;}
	case 36:{Rotate(Cube,"wl");Rotate(Cube,"rl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"gr");break;}
	case 37:{Rotate(Cube,"wl");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 38:{Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"or");Rotate(Cube,"wl");break;}
	case 39:{Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rl");Rotate(Cube,"wr");break;}
	case 40:{Rotate(Cube,"wr");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 41:{Rotate(Cube,"gl");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rr");Rotate(Cube,"wr");break;}
	case 42:{Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rr");Rotate(Cube,"rr");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"gr");break;}
	case 43:{Rotate(Cube,"ol");Rotate(Cube,"rr");Rotate(Cube,"gr");Rotate(Cube,"or");Rotate(Cube,"rl");break;}
	case 44:{Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"ol");Rotate(Cube,"ol");Rotate(Cube,"rr");Rotate(Cube,"br");Rotate(Cube,"gl");Rotate(Cube,"wl");break;}
	case 45:{Rotate(Cube,"yr");Rotate(Cube,"ol");Rotate(Cube,"rr");Rotate(Cube,"gr");Rotate(Cube,"or");Rotate(Cube,"rl");break;}
	case 46:{Rotate(Cube,"yr");Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"ol");Rotate(Cube,"ol");Rotate(Cube,"rr");Rotate(Cube,"br");Rotate(Cube,"gl");Rotate(Cube,"wl");break;}
	case 47:{Rotate(Cube,"ol");Rotate(Cube,"rr");Rotate(Cube,"gl");Rotate(Cube,"or");Rotate(Cube,"rl");break;}
	case 48:{Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"rr");Rotate(Cube,"rr");Rotate(Cube,"ol");Rotate(Cube,"bl");Rotate(Cube,"gr");Rotate(Cube,"wr");break;}
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==25){std::cout << "Middle 1 in position" << std::endl;}

	// middle piece 27 28
	i=27;
	TargetPiece = false;
	while (TargetPiece==false && i<48){
		bool cw=false, co=false;
		for (int j =i;j<i+2;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='O'){co=true;}
		}
		if (cw==true&&co==true){TargetPiece=true;}
		else {i+=2;}
	}
	//std::cout << PositionNumber << std::endl;Rotate(Cube,"");
	switch (PositionNumber){
	case 28:{Rotate(Cube,"ol");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"wl");break;}
	case 29:{Rotate(Cube,"or");Rotate(Cube,"rl");Rotate(Cube,"gr");Rotate(Cube,"yr");Rotate(Cube,"wl");Rotate(Cube,"gl");Rotate(Cube,"br");break;}
	case 30:{Rotate(Cube,"bl");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"rl");Rotate(Cube,"gr");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 31:{Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"or");Rotate(Cube,"or");Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 32:{Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"ol");break;}
	case 33:{Rotate(Cube,"or");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gl");Rotate(Cube,"wr");break;}
	case 34:{Rotate(Cube,"wr");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 35:{Rotate(Cube,"wr");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"ol");break;}
	case 36:{Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"rl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"gr");Rotate(Cube,"wr");break;}
	case 37:{Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"wl");break;}
	case 38:{Rotate(Cube,"wl");Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"or");break;}
	case 39:{Rotate(Cube,"wl");Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 40:{Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"wl");break;}
	case 41:{Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"ol");Rotate(Cube,"gl");Rotate(Cube,"br");break;}
	case 42:{Rotate(Cube,"yl");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"ol");break;}
	case 43:{Rotate(Cube,"yr");Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"ol");Rotate(Cube,"gl");Rotate(Cube,"br");break;}
	case 44:{Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"ol");break;}
	case 45:{Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"or");Rotate(Cube,"gl");Rotate(Cube,"br");break;}
	case 46:{Rotate(Cube,"yr");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"ol");break;}
	case 47:{Rotate(Cube,"yl");Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"ol");Rotate(Cube,"gl");Rotate(Cube,"br");break;}
	case 48:{Rotate(Cube,"gr");Rotate(Cube,"bl");Rotate(Cube,"rr");Rotate(Cube,"rr");Rotate(Cube,"br");Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==27){std::cout << "Middle 2 in position" << std::endl;}

	// middle piece 29 30
	i=29;
	TargetPiece = false;
	while (TargetPiece==false && i<48){
		bool cw=false, cb=false;
		for (int j =i;j<i+2;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='B'){cb=true;}
		}
		if (cw==true&&cb==true){TargetPiece=true;}
		else {i+=2;}
	}
	//std::cout << PositionNumber << std::endl;Rotate(Cube,"");
	switch (PositionNumber){
	case 30:{Rotate(Cube,"bl");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"wl");Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rl");Rotate(Cube,"wr");break;}
	case 31:{Rotate(Cube,"rl");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");Rotate(Cube,"gr");Rotate(Cube,"wl");break;}
	case 32:{Rotate(Cube,"rl");Rotate(Cube,"br");Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"gl");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 33:{Rotate(Cube,"wl");Rotate(Cube,"or");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 34:{Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");Rotate(Cube,"wl");break;}
	case 35:{Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"ol");Rotate(Cube,"wr");break;}
	case 36:{Rotate(Cube,"wr");Rotate(Cube,"rl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"gr");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 37:{Rotate(Cube,"wr");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"bl");break;}
	case 38:{Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"or");Rotate(Cube,"wr");break;}
	case 39:{Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rl");Rotate(Cube,"wl");break;}
	case 40:{Rotate(Cube,"wl");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 41:{Rotate(Cube,"yl");Rotate(Cube,"or");Rotate(Cube,"rl");Rotate(Cube,"bl");Rotate(Cube,"rr");Rotate(Cube,"ol");break;}
	case 42:{Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 43:{Rotate(Cube,"or");Rotate(Cube,"rl");Rotate(Cube,"bl");Rotate(Cube,"rr");Rotate(Cube,"ol");break;}
	case 44:{Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 45:{Rotate(Cube,"bl");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"wr");break;}
	case 46:{Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	case 47:{Rotate(Cube,"or");Rotate(Cube,"rl");Rotate(Cube,"br");Rotate(Cube,"rr");Rotate(Cube,"ol");break;}
	case 48:{Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"or");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");break;}
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==29){std::cout << "Middle 3 in position" << std::endl;}

	//middle piece 31 32
	i=31;
	TargetPiece = false;
	while (TargetPiece==false && i<48){
		bool cw=false, cr=false;
		for (int j =i;j<i+2;j++){
			if (Cube[j] =='W'){cw=true;PositionNumber=j;}
			else if (Cube[j]=='R'){cr=true;}
		}
		if (cw==true&&cr==true){TargetPiece=true;}
		else {i+=2;}
	}
	//std::cout << PositionNumber << std::endl;Rotate(Cube,"");
	switch (PositionNumber){
	case 32:{Rotate(Cube,"rl");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"or");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gl");Rotate(Cube,"wl");break;}
	case 33:{Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"or");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"gl");Rotate(Cube,"wl");break;}
	case 34:{Rotate(Cube,"wl");Rotate(Cube,"bl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");break;}
	case 35:{Rotate(Cube,"wl");Rotate(Cube,"br");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 36:{Rotate(Cube,"rl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"gr");Rotate(Cube,"wl");break;}
	case 37:{Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"bl");Rotate(Cube,"wr");break;}
	case 38:{Rotate(Cube,"wr");Rotate(Cube,"gl");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"or");Rotate(Cube,"wr");Rotate(Cube,"wr");break;}
	case 39:{Rotate(Cube,"wr");Rotate(Cube,"gr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"rl");break;}
	case 40:{Rotate(Cube,"wr");Rotate(Cube,"wr");Rotate(Cube,"ol");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"br");Rotate(Cube,"wr");break;}
	case 41:{Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"rr");Rotate(Cube,"gr");Rotate(Cube,"bl");break;}
	case 42:{Rotate(Cube,"yr");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");break;}
	case 43:{Rotate(Cube,"yr");Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"rr");Rotate(Cube,"gr");Rotate(Cube,"bl");break;}
	case 44:{Rotate(Cube,"yr");Rotate(Cube,"yr");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");break;}
	case 45:{Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"rl");Rotate(Cube,"gr");Rotate(Cube,"bl");break;}
	case 46:{Rotate(Cube,"yl");Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");break;}
	case 47:{Rotate(Cube,"yl");Rotate(Cube,"gl");Rotate(Cube,"br");Rotate(Cube,"rr");Rotate(Cube,"gr");Rotate(Cube,"bl");break;}
	case 48:{Rotate(Cube,"rr");Rotate(Cube,"wl");Rotate(Cube,"yr");Rotate(Cube,"br");Rotate(Cube,"br");Rotate(Cube,"wr");Rotate(Cube,"yl");Rotate(Cube,"rr");break;}
	};
	std::cout << std::endl;
	if (SolveDebug==true){std::cout << "Position Number:" << PositionNumber << std::endl;DisplayCube(Cube);}
	if (PositionNumber==31){std::cout << "Middle 4 in position" << std::endl;}

}

#endif