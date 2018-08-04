// wcount.cpp - simple character, word and line count 
#include 
#include 
#include // Gives isalmun() 
#include // Gives system() 
int ccount=0; // Number of characters 
int wcount=0; // Number of words 
int lcount=0; // Number of lines 
int inword = 0;// Is the file cursor inside a word we have already counted 
int c; // The current char being processed 

int main() 
{ 
	ifstream input("countTheLines.cpp"); 
	if (input.fail()) { 
		cout << "error: could not open file " << endl; exit(1); } 
	c = input.get(); 
	while (!input.eof()) { 
		if (isalnum(c)) 
			inword=1; 
		else if (inword==1) 
		{ 
			// At this point we have just finished a word 
			wcount++; 
			inword=0; 
		} 
		if (c=='\n') 
			lcount++; 
		ccount++; 
		c = input.get();
	} 
	cout << lcount << " lines, "; 
	cout << wcount << " words, "; 
	cout << ccount << " chars." << endl; input.close(); 
	system("pause"); 
	
	return(0); } 