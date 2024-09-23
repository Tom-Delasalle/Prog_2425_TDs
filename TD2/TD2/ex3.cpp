//#include <stringstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream file("file_to_read.txt"); // Opens the file. Note that the actuel file that is read is currently in the folder where the .exe files are found
	if (!file.is_open()) { // If file failed to open, we send an error
		cerr << "Failed to open the file." << endl;
		return EXIT_FAILURE;
	}

	string line;
	while (getline(file, line)) { // Everytime a line is found in the file, print it
		cout << line << endl;
	}

	file.close(); // Closes the file
	return EXIT_SUCCESS;

}