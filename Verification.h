#ifndef VERIFYCUBE
#define VERIFYCUBE

bool VerifyCube(char *Cube); // verify combination of colors is possible
bool CheckCorners(char *Cube); //corner pieces color combonation verify portion
bool CheckSides(char *Cube); // side pieces color combination verify portion

// combine coner and side pieces check for complete cube verification
bool VerifyCube(char *Cube){
	if (CheckCorners(Cube)==true&&CheckSides(Cube)==true){return true;}
	else {return false;}
}

bool CheckSides(char *Cube){
	//side pieces positions 25 thru 48
	//top row:    wr, wg, wo, wb
	//second row: gr, go, bo, br
	//bottom row: yr, yg, yo, yb

	int wr=0, wg=0, wo=0, wb=0;
	int gr=0, go=0, bo=0, br=0;
	int yr=0, yg=0, yo=0, yb=0;

	for (int i = 25;i<48;i+=2){
		// id color piece location
		int cw=0, cr=0, cb=0, cg=0, co=0, cy=0;
		for (int j=i;j<i+2;j++){
			if (Cube[j]=='W'){cw++;}
			else if (Cube[j]=='R'){cr++;}
			else if (Cube[j]=='B'){cb++;}
			else if (Cube[j]=='G'){cg++;}
			else if (Cube[j]=='O'){co++;}
			else if (Cube[j]=='Y'){cy++;}
		}
		// check to see which side piece
		if (cw==1&&cr==1){wr++;}
		else if (cw==1&&cg==1){wg++;}
		else if (cw==1&&co==1){wo++;}
		else if (cw==1&&cb==1){wb++;}
		else if (cg==1&&cr==1){gr++;}
		else if (cg==1&&co==1){go++;}
		else if (cb==1&&co==1){bo++;}
		else if (cb==1&&cr==1){br++;}
		else if (cy==1&&cr==1){yr++;}
		else if (cy==1&&cg==1){yg++;}
		else if (cy==1&&co==1){yo++;}
		else if (cy==1&&cb==1){yb++;}
		else {std::cout << "Invalid side piece\n";return false;}
	}

	// final check to make sure all pieces are present
	if (wr==1&&wg==1&&wo==1&&wb==1&&gr==1&&go==1&&bo==1&&br==1&&yr==1&&yg==1&&yo==1&&yb==1){return true;}
	else {std::cout << "Invalid side piece 2\n";return false;}
}

bool CheckCorners(char *Cube){
	//corner pieces positions 1 thru 24
	//whites: wgr, wgo, wbr, wbo;
	//yellows: ygr, ygo, ybr, ybo;

	int wgr=0, wgo=0, wbr=0, wbo=0;
	int ygr=0, ygo=0, ybr=0, ybo=0;
	
	// verify input for a given side position
	for (int i=1;i<24;i+=3){
		int cw=0, cr=0, cb=0, cg=0, co=0, cy=0;
		for (int j=i;j<i+3;j++){
			if (Cube[j]=='W'){cw++;}
			else if (Cube[j]=='R'){cr++;}
			else if (Cube[j]=='B'){cb++;}
			else if (Cube[j]=='G'){cg++;}
			else if (Cube[j]=='O'){co++;}
			else if (Cube[j]=='Y'){cy++;}
			else {std::cout << j <<" Error: invalid input\n";return 0;}
		}
		//verify side piece color combinations
		// wgr
		if (cw==1&&cg==1&&cr==1){wgr++;}
		// wgo
		else if (cw==1&&cg==1&&co==1){wgo++;}
		// wbr
		else if (cw==1&&cb==1&&cr==1){wbr++;}
		// wbo
		else if (cw==1&&cb==1&&co==1){wbo++;}
		// ygr
		else if (cy==1&&cg==1&&cr==1){ygr++;}
		// ygo
		else if (cy==1&&cg==1&&co==1){ygo++;}
		// ybr
		else if (cy==1&&cb==1&&cr==1){ybr++;}
		// ybo
		else if (cy==1&&cb==1&&co==1){ybo++;}
		//else {std::cout << cw << cg<< cr << cb << co << cy << "Error: Invalid coner piece combination\n";return 0;}
		else {std::cout << "Error: Invalid corner piece combination\n";return 0;}

	}
	// verify all side pieces are present
	if (wgr==1&&wgo==1&&wbr==1&&wbo==1&&ygr==1&&ybr==1&&ybo==1){return true;}
	else {std::cout << "Invalid corner piece combination\n";return 0;}
}

#endif