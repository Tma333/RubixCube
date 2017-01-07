#ifndef READFROMFILE
#define READFROMFILE

void ReadFile(char *Cube){
	std::ifstream f;
	f.open("testcube.txt", std::ios::in);
	
	f>>temp;Cube[15] = temp;//14	
	f>>temp;Cube[41] = temp;
	f>>temp;Cube[16] = temp;
	f>>temp;Cube[34] = temp;
	Cube[50] = 'G';
	f>>temp;Cube[35] = temp;
	f>>temp;Cube[3] = temp;
	f>>temp;Cube[26] = temp;
	f>>temp;Cube[4] = temp;

	// WHITE side input
	f>>temp;Cube[2] = temp;
	f>>temp;Cube[25] = temp;
	f>>temp;Cube[5] = temp;
	f>>temp;Cube[31] = temp;
	Cube[49] = 'W';
	f>>temp;Cube[27] = temp;
	f>>temp;Cube[11] = temp;//8
	f>>temp;Cube[29] = temp;
	f>>temp;Cube[8] = temp;//11

	// RED side input
	f>>temp;Cube[13] = temp;
	f>>temp;Cube[33] = temp;
	f>>temp;Cube[1] = temp;
	f>>temp;Cube[47] = temp;
	Cube[53] = 'R';
	f>>temp;Cube[32] = temp;
	f>>temp;Cube[24] = temp;//23
	f>>temp;Cube[40] = temp;
	f>>temp;Cube[12] = temp;//7
	
	// BLUE side input
	f>>temp;Cube[10] = temp;//9
	f>>temp;Cube[30] = temp;
	f>>temp;Cube[9] = temp;//10
	f>>temp;Cube[39] = temp;
	Cube[52] = 'B';
	f>>temp;Cube[38] = temp;
	f>>temp;Cube[22] = temp;
	f>>temp;Cube[45] = temp;
	f>>temp;Cube[21] = temp;

	// ORANGE side input
	f>>temp;Cube[6] = temp;
	f>>temp;Cube[36] = temp;
	f>>temp;Cube[18] = temp;//17
	f>>temp;Cube[28] = temp;
	Cube[51] = 'O';
	f>>temp;Cube[43] = temp;
	f>>temp;Cube[7] = temp;//12
	f>>temp;Cube[37] = temp;
	f>>temp;Cube[19] = temp;
	
	// YELLOW side input
	f>>temp;Cube[17] = temp;//18
	f>>temp;Cube[42] = temp;
	f>>temp;Cube[14] = temp;//15
	f>>temp;Cube[44] = temp;
	Cube[54] = 'Y';
	f>>temp;Cube[48] = temp;
	f>>temp;Cube[20] = temp;
	f>>temp;Cube[46] = temp;
	f>>temp;Cube[23] = temp;//24

	for(int i=0;i<49;i++){
		Cube[i]=toupper(Cube[i]);
	}

	f.close();

}

#endif