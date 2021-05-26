#pragma once
#ifndef _MYIMPDICTIONARY_H
#define _MYIMPDICTIONARY_H

#include <iostream>
#include <fstream>
#include <vector>

class myDictionary
{
public: 

	myDictionary(void); 
	~myDictionary(void);
	myDictionary(int wordCount);
	std::vector<std::string> myGreatBook;
	bool searchAgain; 

	//GETTERS
	std::vector<std::string> getDictionary(); 

	//PUBLIC INTS
	int numOfWordsCounter; 
	void setDictionary(std::string fileLocation);  //THIS WILL CREATE OUR VIRTUAL DICTIONARY
	void getWord(std::string wordsearch, int counterPos);		//WILL SEARCH FOR A WORD IN THE VECTOR ARRAY OF WORDS

private:
	//SETTERS
};
#endif // !_MYIMPDICTIONARY_H




