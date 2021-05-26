#include "MyImpDictionary.h"

/*******************************************************************************
class myDictionary
{
public:
	myDictionary(void);
	~myDictionary(void);
	myDictionary(int wordCount);
	std::vector<std::string> myGreatBook;
	bool searchAgain;


	//GETTERS
	void getWord(std::string wordsearch, int counterPos);		//WILL SEARCH FOR A WORD IN THE VECTOR ARRAY OF WORDS
	std::vector<std::string> getDictionary();

	//PUBLIC INTS
	int numOfWordsCounter;

	//SETTERS
	void setDictionary(std::string filePath);  //THIS WILL CREATE OUR VIRTUAL DICTIONARY
};
********************************************************************************/
/*****************************
NAME: myDiciontary
FUNCTION: CREATES AN EMPTY DICTIONARY 
TYPE: CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
myDictionary::myDictionary()
	:numOfWordsCounter(0),
	myGreatBook(0),
	searchAgain(true)
{}

/*****************************
NAME: myDiciontary
FUNCTION: CREATES AN EMPTY DICTIONARY, SETS WORDCOUNT TO SPECIFIC POSITION
TYPE: CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
myDictionary::myDictionary(int wordcount)
	:numOfWordsCounter(wordcount),
	myGreatBook(0), 
	searchAgain(true) 
{}


myDictionary::~myDictionary()
{}

void myDictionary::setDictionary(std::string filePath)
{
	std::string words;
	std::fstream myFile; 
	myFile.open(filePath); 

	if (!myFile.is_open())
	{
		std::cout << "ERROR: Could not open or find file." << std::endl;
		system("pause"); 
		exit(0); 
	}
	std::cout << "Looking Good.  File found\n\n" << std::endl;
	
	while (!myFile.eof())
	{
		myFile >> words;
		myGreatBook.push_back(words); 
		if (numOfWordsCounter % 15 == 0)
		{
			std::cout << std::endl << std::endl;
		}
		std::cout << " " << myGreatBook[numOfWordsCounter];
		numOfWordsCounter++; 
	}
	
	std::cout << "There is a total of " << numOfWordsCounter << " in your dictionary." << std::endl; 
	myFile.close();

}

std::vector<std::string> myDictionary::getDictionary()
{
	return myGreatBook;
}

void myDictionary::getWord(std::string wordsearch, int counterPos)
{
	std::vector<std::string> temp_Dictionary = getDictionary(); 
	int word_counter{ 0 }, letter_counter{ 0 }, match_counter{ 0 };
	bool isMatch = false; 
	 
	std::size_t temp_Word; 

	for (std::string hold_Temp_Word : temp_Dictionary)
	{
		isMatch = false;
		letter_counter = 0; 
		for (char character_of_target_word : wordsearch)
		{
			if (character_of_target_word == hold_Temp_Word.at(letter_counter))
			{
				isMatch = true; 
			}
			else
			{
				isMatch = false; 
				break;
			}
			letter_counter++;
		}
		if (isMatch)
		{
			if (match_counter % 10 == 0)
			{
				std::cout << std::endl;
			}
			std::cout << match_counter+1 << ": " << hold_Temp_Word << " ";
			match_counter++;
		}	
		word_counter++;
	}
	
	std::cout << std::endl << "There was a total of " << match_counter << " matches. " << std::endl;

	std::cout << std::endl << std::endl;
	
}

int main()
{
	std::string myWord;
	myDictionary d(0);
	d.setDictionary("C:/Users/Rex_Kidd/Desktop/myManyWordsFile.txt");
	
	while (d.searchAgain) {
		
		std::cout << "What letter does your word start with? " << std::endl;
		std::cin >> myWord;
		d.getWord(myWord, 5);

		std::cout << "\nWant to search another word? Enter N for no: ";
		std::cin >> myWord; 
		if (myWord.at(0) == 'n')
		{
			d.searchAgain = false;
		}
	}
	
	system("pause"); 
	return 0; 
}