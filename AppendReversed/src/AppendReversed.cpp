// This program stores the text of a text file, prompts the user
// for text to append, appends the original text file, and then creates a
// new text file with the reverse of the original text file

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse the contents of the file and store it in another file
void reverseFileContent(const string &inputFileName, const string &outputFileName) {
    // Open the input file
    ifstream inputFile(inputFileName);

    if (!inputFile) {
        cerr << "Error: Could not open input file: " << inputFileName << endl;
        return;
    }

    // Read the content of the input file into a string
    string content((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    inputFile.close();

    // Reverse the content
    reverse(content.begin(), content.end());

    // Write the reversed content to the output file
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error: Could not open output file: " << outputFileName << endl;
        return;
    }

    outputFile << content;
    outputFile.close();

    cout << "Reversed content written to: " << outputFileName << endl;
}

int main() {
    string fileName = "CSC450_CT5_mod5.txt";
    string reversedFileName = "CSC450_mod5_reverse.txt";

    // Append user input to the file
    ofstream file(fileName, ios::app);
    if (!file) {
        cerr << "Error: Could not open file for appending: " << fileName << endl;
        return 1;
    }

    // Get user input
    string userInput;
    cout << "Enter text to append to the file: ";
    getline(cin, userInput);

    // Append the input to the file
    file << userInput << endl;
    file.close();

    cout << "Text successfully appended to: " << fileName << endl;

    // Reverse the contents of the file and store it in a new file
    reverseFileContent(fileName, reversedFileName);

    return 0;
}


