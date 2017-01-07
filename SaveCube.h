#ifndef SAVECUBE
#define SAVECUBE

void CubeSave(char *Cube){
	// save cube to text file for debugging purposes not necessary.
	std::fstream Fileout;
	Fileout.open("SavedCube.txt",std::ios::out);
	
	// line one
	Fileout <<"      " <<Cube[15]<<' '<<Cube[41]<<' '<<Cube[16]<< std::endl;
	
	// line two
	Fileout <<"      " <<Cube[34]<<' '<<Cube[50]<<' '<<Cube[35]<< std::endl;
	
	// line three
	Fileout <<"      " <<Cube[3]<<' '<<Cube[26]<<' '<<Cube[4]<< std::endl;
	
	// line four
	Fileout <<Cube[13]<<' '<<Cube[33]<<' '<<Cube[1]<<' '<<Cube[2]<<' '<<Cube[25]<<' '<<Cube[5]<<' '<<Cube[6]<<' '<<Cube[36]<<' '<<Cube[18]<<' '<<Cube[17]<<' '<<Cube[42]<<' '<<Cube[14] << std::endl;
	
	//line five
	Fileout <<Cube[47]<<' '<<Cube[53]<<' '<<Cube[32]<<' '<<Cube[31]<<' '<<Cube[49]<<' '<<Cube[27]<<' '<<Cube[28]<<' '<<Cube[51]<<' '<<Cube[43]<<' '<<Cube[44]<<' '<<Cube[54]<<' '<<Cube[48] << std::endl;
	
	//line six
	Fileout <<Cube[24]<<' '<<Cube[40]<<' '<<Cube[12]<<' '<<Cube[11]<<' '<<Cube[29]<<' '<<Cube[8]<<' '<<Cube[7]<<' '<<Cube[37]<<' '<<Cube[19]<<' '<<Cube[20]<<' '<<Cube[46]<<' '<<Cube[23] << std::endl;
	
	//line seven 
	Fileout <<"      " <<Cube[10]<<' '<<Cube[30]<<' '<<Cube[9]<< std::endl;
	
	//line eight
	Fileout <<"      " <<Cube[39]<<' '<<Cube[52]<<' '<<Cube[38]<< std::endl;
	
	//line nine
	Fileout <<"      " <<Cube[22]<<' '<<Cube[45]<<' '<<Cube[21]<< std::endl<<std::endl;

	Fileout.close();

}

#endif