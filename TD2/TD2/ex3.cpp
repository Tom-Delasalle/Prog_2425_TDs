#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

const unsigned int ALPHA_LENGTH = 26;

using namespace std;

int main() {

	ifstream file("../file_to_read.txt"); // Opens the file. Note that the actuel file that is read is currently in the parent folder of the folder where the .exe files are found
	if (!file.is_open()) { // If file failed to open, send an error
		cerr << "Failed to open the file." << endl;
		return EXIT_FAILURE;
	}
	
	unsigned int nbrOfLines = 0, nbrOfWords = 0, nbrOfLetters = 0;
	auto charCount = new unsigned int[ALPHA_LENGTH];
	for (unsigned int j = 0; j < ALPHA_LENGTH; ++j) {
		charCount[j] = 0;
	}
	string line, word;
	char temp;
	while (getline(file, line)) { // As long as there are lines in the file, read them
		++nbrOfLines;
		stringstream ssLine(line);
		while (ssLine >> word) { // As long as there are words in the line, read them
			++nbrOfWords;
			nbrOfLetters += static_cast<unsigned int>(word.length()); // Convert size_t into unsigned int
			for (unsigned int i = 0; i < word.length(); ++i) {
				temp = word[i];
				if (isalpha(temp)) { // If the character is from the alphabet
					temp = tolower(temp);
					++charCount[temp - 'a']; // This ranges from 0 to 25
				}
			}
		}
	}

	cout << "Number of lines : " << nbrOfLines << "\nNumber of words : " << nbrOfWords << "\nNumber of letters : " << nbrOfLetters << endl;
	for (unsigned int k = 0; k < ALPHA_LENGTH; k++) {
		temp = k + 'a';
		cout << temp << " : " << charCount[k] << endl;
	}

	file.close(); // Closes the file
	return EXIT_SUCCESS;

}