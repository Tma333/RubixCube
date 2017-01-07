#ifndef ROTATE
#define ROTATE

// display instructions true== display; false == no display
bool ShowInstruction = true;

void RotateWL(char *Cube);
void RotateWR(char *Cube);
void RotateGL(char *Cube);
void RotateGR(char *Cube);
void RotateRL(char *Cube);
void RotateRR(char *Cube);
void RotateOL(char *Cube);
void RotateOR(char *Cube);
void RotateBL(char *Cube);
void RotateBR(char *Cube);
void RotateYL(char *Cube);
void RotateYR(char *Cube);
void MidLeft(char *Cube, char Color);
void MidRight(char *Cube, char Color);
void BottomPhaseOne(char *Cube, char ColorOne, char ColorTwo);
void BottomPhaseTwo(char *Cube, char Color);
void BotReverse(char *Cube, char Color);

//Rotation mechanics
void Rotate(char *Cube, std::string Direction){
	// rotate directions wl, wr, gl, gr, rl, rr, ol, or, bl, br, yl, yr
	if (Direction=="wl"){RotateWL(Cube);}
	else if (Direction=="wr"){RotateWR(Cube);}
	else if (Direction=="gl"){RotateGL(Cube);}
	else if (Direction=="gr"){RotateGR(Cube);}
	else if (Direction=="rl"){RotateRL(Cube);}
	else if (Direction=="rr"){RotateRR(Cube);}
	else if (Direction=="ol"){RotateOL(Cube);}
	else if (Direction=="or"){RotateOR(Cube);}
	else if (Direction=="bl"){RotateBL(Cube);}
	else if (Direction=="br"){RotateBR(Cube);}
	else if (Direction=="yl"){RotateYL(Cube);}
	else if (Direction=="yr"){RotateYR(Cube);}
	else {std::cout << "Error: Bad direction: " << Direction << std::endl;}

}
void RotateWL(char *Cube){
	//face rotate
	//into temp
	Cube[55]=Cube[11];//-8
	Cube[56]=Cube[31];

	// corner
	Cube[11]=Cube[2];//8
	Cube[2]=Cube[5];
	Cube[5]=Cube[8];//-11
	Cube[8]=Cube[55];//11

	// center
	Cube[31]=Cube[25];
	Cube[25]=Cube[27];
	Cube[27]=Cube[29];
	Cube[29]=Cube[56];

	//trim rotate
	// into temp
	Cube[55]=Cube[1];
	Cube[56]=Cube[32];
	Cube[57]=Cube[12];//-7

	Cube[32]=Cube[26];
	Cube[26]=Cube[28];
	Cube[28]=Cube[30];
	Cube[30]=Cube[56];

	// left corner
	Cube[12]=Cube[3];//7
	Cube[3]=Cube[6];
	Cube[6]=Cube[9];//-10
	Cube[9]=Cube[57];//10

	// right corner
	Cube[1]=Cube[4];
	Cube[4]=Cube[7];//-12
	Cube[7]=Cube[10];//12-9
	Cube[10]=Cube[55];//9

	if (ShowInstruction==true){std::cout<< "WL, ";}

}
void RotateWR(char *Cube){
//face rotate	
	//into temp
	Cube[55]=Cube[27];
	Cube[56]=Cube[8];//-11

	// side rotates
	Cube[27]=Cube[25];
	Cube[25]=Cube[31];
	Cube[31]=Cube[29];
	Cube[29]=Cube[55];

	// corner rotates
	Cube[8]=Cube[5];//11
	Cube[5]=Cube[2];
	Cube[2]=Cube[11];//-8
	Cube[11]=Cube[56];//8

//trim rotate
	// into temp
	Cube[55]=Cube[6];
	Cube[56]=Cube[28];
	Cube[57]=Cube[7];//-12

	// side rotate
	Cube[28]=Cube[26];
	Cube[26]=Cube[32];
	Cube[32]=Cube[30];
	Cube[30]=Cube[56];
	// right corner
	Cube[7]=Cube[4];//12
	Cube[4]=Cube[1];
	Cube[1]=Cube[10];//-9
	Cube[10]=Cube[57];//9
	// left corner
	Cube[6]=Cube[3];
	Cube[3]=Cube[12];//-7
	Cube[12]=Cube[9];//7-10
	Cube[9]=Cube[55];//10

	if (ShowInstruction==true){std::cout<< "WR, ";}

}
void RotateGL(char *Cube){
	// Face rotatE
	// into temp
	Cube[55]=Cube[3];
	Cube[56]=Cube[34];

	// corner rotate
	Cube[3]=Cube[15];//-14
	Cube[15]=Cube[16];//14
	Cube[16]=Cube[4];
	Cube[4]=Cube[55];

	// side rotate
	Cube[34]=Cube[41];
	Cube[41]=Cube[35];
	Cube[35]=Cube[26];
	Cube[26]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[13];
	Cube[56]=Cube[33];
	Cube[57]=Cube[1];

	// center 
	Cube[33]=Cube[42];
	Cube[42]=Cube[36];
	Cube[36]=Cube[25];
	Cube[25]=Cube[56];
	// left coner
	Cube[1]=Cube[14];//-15
	Cube[14]=Cube[18];//15-17
	Cube[18]=Cube[5];//17
	Cube[5]=Cube[57];
	// right corner
	Cube[13]=Cube[17];//-18
	Cube[17]=Cube[6];//18
	Cube[6]=Cube[2];
	Cube[2]=Cube[55];
	
	if (ShowInstruction==true){std::cout<< "GL, ";}

}
void RotateGR(char *Cube){
	// Face rotat
	// into temp
	Cube[55]=Cube[4];
	Cube[56]=Cube[35];

	// corner rotate
	Cube[4]=Cube[16];
	Cube[16]=Cube[15];//-14
	Cube[15]=Cube[3];//14
	Cube[3]=Cube[55];

	// side rotate
	Cube[35]=Cube[41];
	Cube[41]=Cube[34];
	Cube[34]=Cube[26];
	Cube[26]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[18];//-17
	Cube[56]=Cube[36];
	Cube[57]=Cube[6];

	// center 
	Cube[36]=Cube[42];
	Cube[42]=Cube[33];
	Cube[33]=Cube[25];
	Cube[25]=Cube[56];
	// left coner
	Cube[18]=Cube[14];//17-15
	Cube[14]=Cube[1];//15
	Cube[1]=Cube[5];
	Cube[5]=Cube[55];
	// right corner
	Cube[6]=Cube[17];//-18
	Cube[17]=Cube[13];//18
	Cube[13]=Cube[2];
	Cube[2]=Cube[57];

	if (ShowInstruction==true){std::cout<< "GR, ";}

}
void RotateRL(char *Cube){
	// Face rotat
	// into temp
	Cube[55]=Cube[24];//-23
	Cube[56]=Cube[47];

	// corner rotate
	Cube[24]=Cube[13];//23
	Cube[13]=Cube[1];
	Cube[1]=Cube[12];//-7
	Cube[12]=Cube[55];//7

	// side rotate
	Cube[47]=Cube[33];
	Cube[33]=Cube[32];
	Cube[32]=Cube[40];
	Cube[40]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[14];//-15
	Cube[56]=Cube[48];
	Cube[57]=Cube[23];//-24

	// center 
	Cube[48]=Cube[34];
	Cube[34]=Cube[31];
	Cube[31]=Cube[39];
	Cube[39]=Cube[56];
	// left coner
	Cube[23]=Cube[15];//24-14
	Cube[15]=Cube[2];//14
	Cube[2]=Cube[10];//-9
	Cube[10]=Cube[57];//9
	// right corner
	Cube[14]=Cube[3];//15
	Cube[3]=Cube[11];//-8
	Cube[11]=Cube[22];//8
	Cube[22]=Cube[55];

	if (ShowInstruction==true){std::cout<< "RL, ";}

}
void RotateRR(char *Cube){
	// Face rotat
	// into temp
	Cube[55]=Cube[12];//-7
	Cube[56]=Cube[32];

	// corner rotate
	Cube[12]=Cube[1];//7
	Cube[1]=Cube[13];
	Cube[13]=Cube[24];//-23
	Cube[24]=Cube[55];//23

	// side rotate
	Cube[32]=Cube[33];
	Cube[33]=Cube[47];
	Cube[47]=Cube[40];
	Cube[40]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[2];
	Cube[56]=Cube[31];
	Cube[57]=Cube[11];//-8

	// center 
	Cube[31]=Cube[34];
	Cube[34]=Cube[48];
	Cube[48]=Cube[39];
	Cube[39]=Cube[56];
	// left coner
	Cube[2]=Cube[15];//-14
	Cube[15]=Cube[23];//14-24
	Cube[23]=Cube[10];//24-9
	Cube[10]=Cube[55];//9
	// right corner
	Cube[11]=Cube[3];//8
	Cube[3]=Cube[14];//-15
	Cube[14]=Cube[22];//15
	Cube[22]=Cube[57];

	if (ShowInstruction==true){std::cout<< "RR, ";}

}
void RotateOL(char *Cube){
	// Face rotat
	// into temp
	Cube[55]=Cube[7];//-12
	Cube[56]=Cube[28];

	// corner rotate
	Cube[7]=Cube[6];//12
	Cube[6]=Cube[18];//-17
	Cube[18]=Cube[19];//17
	Cube[19]=Cube[55];

	// side rotate
	Cube[28]=Cube[36];
	Cube[36]=Cube[43];
	Cube[43]=Cube[37];
	Cube[37]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[5];
	Cube[56]=Cube[27];
	Cube[57]=Cube[8];//-11

	// center 
	Cube[27]=Cube[35];
	Cube[35]=Cube[44];
	Cube[44]=Cube[38];
	Cube[38]=Cube[56];
	// left coner
	Cube[8]=Cube[4];//11
	Cube[4]=Cube[17];//-18
	Cube[17]=Cube[21];//18
	Cube[21]=Cube[57];
	// right corner
	Cube[5]=Cube[16];
	Cube[16]=Cube[20];
	Cube[20]=Cube[9];//10
	Cube[9]=Cube[55];//10

	if (ShowInstruction==true){std::cout<< "OL, ";}

}
void RotateOR(char *Cube){
	// Face rotat
	// into temp
	Cube[55]=Cube[19];
	Cube[56]=Cube[43];

	// corner rotate
	Cube[19]=Cube[18];//-17
	Cube[18]=Cube[6];//17
	Cube[6]=Cube[7];//-12
	Cube[7]=Cube[55];//12

	// side rotate
	Cube[43]=Cube[36];
	Cube[36]=Cube[28];
	Cube[28]=Cube[37];
	Cube[37]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[17];//-18
	Cube[56]=Cube[44];
	Cube[57]=Cube[20];

	// center 
	Cube[44]=Cube[35];
	Cube[35]=Cube[27];
	Cube[27]=Cube[38];
	Cube[38]=Cube[56];
	// left coner
	Cube[17]=Cube[4];//18
	Cube[4]=Cube[8];//-11
	Cube[8]=Cube[21];//11
	Cube[21]=Cube[55];
	// right corner
	Cube[20]=Cube[16];
	Cube[16]=Cube[5];
	Cube[5]=Cube[9];//-10
	Cube[9]=Cube[57];//10

	if (ShowInstruction==true){std::cout<< "OR, ";}

}
void RotateBL(char *Cube){
	// Face rotate
	// into temp
	Cube[55]=Cube[22];
	Cube[56]=Cube[39];

	// corner rotate
	Cube[22]=Cube[10];//-9
	Cube[10]=Cube[9];//9-10
	Cube[9]=Cube[21];//10
	Cube[21]=Cube[55];
	// side rotate
	Cube[39]=Cube[30];
	Cube[30]=Cube[38];
	Cube[38]=Cube[45];
	Cube[45]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[12];//-7
	Cube[56]=Cube[40];
	Cube[57]=Cube[24];//-23

	// center 
	Cube[40]=Cube[29];
	Cube[29]=Cube[37];
	Cube[37]=Cube[46];
	Cube[46]=Cube[56];
	// left coner
	Cube[24]=Cube[11];//23-8
	Cube[11]=Cube[7];//8-12
	Cube[7]=Cube[20];//12
	Cube[20]=Cube[57];
	// right corner
	Cube[12]=Cube[8];//7-11
	Cube[8]=Cube[19];//11
	Cube[19]=Cube[23];//-24
	Cube[23]=Cube[55];//24

	if (ShowInstruction==true){std::cout<< "BL, ";}

}
void RotateBR(char *Cube){
	// Face rotate
	// into temp
	Cube[55]=Cube[21];
	Cube[56]=Cube[38];

	// corner rotate
	Cube[21]=Cube[9];//10
	Cube[9]=Cube[10];//10-9
	Cube[10]=Cube[22];//9
	Cube[22]=Cube[55];
	// side rotate
	Cube[38]=Cube[30];
	Cube[30]=Cube[39];
	Cube[39]=Cube[45];
	Cube[45]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[7];//-12
	Cube[56]=Cube[37];
	Cube[57]=Cube[19];

	// center 
	Cube[37]=Cube[29];
	Cube[29]=Cube[40];
	Cube[40]=Cube[46];
	Cube[46]=Cube[56];
	// left coner
	Cube[7]=Cube[11];//12-8
	Cube[11]=Cube[24];//8-23
	Cube[24]=Cube[20];//23
	Cube[20]=Cube[55];
	// right corner
	Cube[19]=Cube[8];//-11
	Cube[8]=Cube[12];//11-7
	Cube[12]=Cube[23];//7-24
	Cube[23]=Cube[57];//24

	if (ShowInstruction==true){std::cout<< "BR, ";}

}
void RotateYL(char *Cube){
	// Face rotate
	// into temp
	Cube[55]=Cube[20];
	Cube[56]=Cube[44];

	// corner rotate
	Cube[20]=Cube[17];//-18
	Cube[17]=Cube[14];//18-15
	Cube[14]=Cube[23];//15-24
	Cube[23]=Cube[55];//24
	// side rotate
	Cube[44]=Cube[42];
	Cube[42]=Cube[48];
	Cube[48]=Cube[46];
	Cube[46]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[18];//-17
	Cube[56]=Cube[43];
	Cube[57]=Cube[19];

	// center 
	Cube[43]=Cube[41];
	Cube[41]=Cube[47];
	Cube[47]=Cube[45];
	Cube[45]=Cube[56];
	// left coner
	Cube[19]=Cube[16];
	Cube[16]=Cube[13];
	Cube[13]=Cube[22];
	Cube[22]=Cube[57];
	// right corner
	Cube[18]=Cube[15];//17-14
	Cube[15]=Cube[24];//14-23
	Cube[24]=Cube[21];//23
	Cube[21]=Cube[55];

	if (ShowInstruction==true){std::cout<< "YL, ";}

}
void RotateYR(char *Cube){
	// Face rotate
	// into temp
	Cube[55]=Cube[23];//-24
	Cube[56]=Cube[48];

	// corner rotate
	Cube[23]=Cube[14];//24-15
	Cube[14]=Cube[17];//15-18
	Cube[17]=Cube[20];//18
	Cube[20]=Cube[55];
	// side rotate
	Cube[48]=Cube[42];
	Cube[42]=Cube[44];
	Cube[44]=Cube[46];
	Cube[46]=Cube[56];

	// trim rotate
	// into temp
	Cube[55]=Cube[13];
	Cube[56]=Cube[47];
	Cube[57]=Cube[24];//-23

	// center 
	Cube[47]=Cube[41];
	Cube[41]=Cube[43];
	Cube[43]=Cube[45];
	Cube[45]=Cube[56];
	// left coner
	Cube[13]=Cube[16];
	Cube[16]=Cube[19];
	Cube[19]=Cube[22];
	Cube[22]=Cube[55];
	// right corner
	Cube[24]=Cube[15];//23-14
	Cube[15]=Cube[18];//14-17
	Cube[18]=Cube[21];//17
	Cube[21]=Cube[57];

	if (ShowInstruction==true){std::cout<< "YR, ";}

}

//Rotation Algorithm for middle layer solution
void MidRight(char *Cube, char Color){
	char ColorLowerCase = tolower(Color);
	std::string PartL = "l";
	std::string PartR = "r";

	Rotate(Cube, ColorLowerCase+PartL);
	Rotate(Cube, "yr");
	Rotate(Cube, ColorLowerCase+PartR);
	Rotate(Cube, "yr");
	Rotate(Cube, ColorLowerCase+PartL);
	Rotate(Cube, "yr");
	Rotate(Cube, "yr");
	Rotate(Cube, ColorLowerCase+PartR);
	Rotate(Cube, "yl");
	Rotate(Cube, ColorLowerCase+PartL);
	Rotate(Cube, "yl");
	Rotate(Cube, ColorLowerCase+PartR);
	std::cout << std::endl;
}
void MidLeft(char *Cube, char Color){
	char ColorLowerCase = tolower(Color);
	std::string PartL = "l";
	std::string PartR = "r";

	Rotate(Cube, ColorLowerCase+PartR);
	Rotate(Cube, "yl");
	Rotate(Cube, ColorLowerCase+PartL);
	Rotate(Cube, "yl");
	Rotate(Cube, ColorLowerCase+PartR);
	Rotate(Cube, "yl");
	Rotate(Cube, "yl");
	Rotate(Cube, ColorLowerCase+PartL);
	Rotate(Cube, "yr");
	Rotate(Cube, ColorLowerCase+PartR);
	Rotate(Cube, "yr");
	Rotate(Cube, ColorLowerCase+PartL);
	std::cout << std::endl;
}

//Rotation for bottom layer corner pieces
void BottomPhaseOne(char *Cube, char ColorOne, char ColorTwo){
	//one is face color, two is right side color.
	ColorOne = tolower(ColorOne);
	ColorTwo = tolower(ColorTwo);

	std::string Left = "l", Right = "r";

	Rotate(Cube, ColorTwo+Left);
	Rotate(Cube, "yl");
	Rotate(Cube, ColorTwo+Right);
	Rotate(Cube, ColorOne+Right);
	Rotate(Cube, "yr");
	Rotate(Cube, ColorOne+Left);
	Rotate(Cube, ColorTwo+Left);
	Rotate(Cube, "yr");
	Rotate(Cube, ColorTwo+Right);
	Rotate(Cube, "yr");
	Rotate(Cube, "yr");
	std::cout << std::endl;	
}
void BottomPhaseTwo(char *Cube, char Color){
	Color=tolower(Color);
	std::string Left = "l", Right = "r";

	Rotate(Cube, Color+Left);
	Rotate(Cube, "yl");
	Rotate(Cube, Color+Right);
	Rotate(Cube, "yl");
	Rotate(Cube, Color+Left);
	Rotate(Cube, "yl");
	Rotate(Cube, "yl");
	Rotate(Cube, Color+Right);
	Rotate(Cube, "yl");
	Rotate(Cube, "yl");
	std::cout << std::endl;
}

//Rotation for bottom layer in between pieces
void BotRight(char *Cube, char Color){
	char SideLeft, SideRight;
	std::string Left = "l";
	std::string Right = "r";
	Color=tolower(Color);
	if (Color=='g'){SideLeft='o';SideRight='r';}
	else if (Color=='r'){SideLeft='g';SideRight='b';}
	else if (Color=='b'){SideLeft='r';SideRight='o';}
	else if (Color=='o'){SideLeft='b';SideRight='g';}

	Rotate(Cube, SideLeft+Left);
	Rotate(Cube, SideRight+Right);
	Rotate(Cube, Color+Right);
	Rotate(Cube, SideLeft+Right);
	Rotate(Cube, SideRight+Left);
	Rotate(Cube, "yr");
	Rotate(Cube, "yr");
	Rotate(Cube, SideLeft+Left);
	Rotate(Cube, SideRight+Right);
	Rotate(Cube, Color+Right);
	Rotate(Cube, SideLeft+Right);
	Rotate(Cube, SideRight+Left);
	std::cout << std::endl;

}
void BotLeft(char *Cube, char Color){
	char SideLeft, SideRight;
	std::string Left = "l";
	std::string Right = "r";
	Color=tolower(Color);
	if (Color=='g'){SideLeft='o';SideRight='r';}
	else if (Color=='r'){SideLeft='g';SideRight='b';}
	else if (Color=='b'){SideLeft='r';SideRight='o';}
	else if (Color=='o'){SideLeft='b';SideRight='g';}

	Rotate(Cube, SideLeft+Left);
	Rotate(Cube, SideRight+Right);
	Rotate(Cube, Color+Left);
	Rotate(Cube, SideLeft+Right);
	Rotate(Cube, SideRight+Left);
	Rotate(Cube, "yr");
	Rotate(Cube, "yr");
	Rotate(Cube, SideLeft+Left);
	Rotate(Cube, SideRight+Right);
	Rotate(Cube, Color+Left);
	Rotate(Cube, SideLeft+Right);
	Rotate(Cube, SideRight+Left);
	std::cout << std::endl;

}
void BotReverse(char *Cube, char Color){
	char Side, Back;
	std::string Left = "l";
	std::string Right = "r";
	Color=tolower(Color);
	if (Color=='g'){Side='o';Back='b';}
	else if (Color=='o'){Side='b';Back='r';}
	else if (Color=='r'){Side='g';Back='o';}
	else if (Color=='b'){Side='r';Back='g';}

	Rotate(Cube, Color+Right);
	Rotate(Cube, Side+Right);
	Rotate(Cube, Back+Left);
	Rotate(Cube, Side+Left);
	Rotate(Cube, Back+Right);
	Rotate(Cube, Color+Left);
	Rotate(Cube, "yr");
	Rotate(Cube, Back+Right);
	Rotate(Cube, "yl");
	Rotate(Cube, Back+Left);
	std::cout << std::endl;

}

#endif
