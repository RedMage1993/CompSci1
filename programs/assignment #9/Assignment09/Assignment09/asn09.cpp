// Fritz Ammon
// Section #1008
// Assignment #9
//
// This program reads information about songs from a file using the fstream class
// and prints it out in an organized manner with the calculated total length of
// the songs combined.
//
// Input:
// Gets name of file to open with ifstream (string).
// Read song information that includes the song title (string) and the length of
// the song in minutes and seconds (short).
//
// Process:
// Opens the file entered by the user with ifstream and reads from it until EOF.
// Formats song title string to have no extra spaces and so that the first letter
// of every word are the only letters in uppercase.
// Calculates the correct representation of time in hh::mm:ss so that minutes and
// seconds do not exceed 59.
//
// Output:
// Prints my name, section#, and assignment#.
// Prompts the user for name of file with song information.
// Prints a table that lists the song title, song length, and cumulative song
// length at each song in a formatted manner as described in Process.

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void rmExSpace(string& str);
void formatTrackName(string& str);
void timeTick(short& bigger, short& smaller);

int main()
{
	string inFileName = ""; // Name of file with song data to be opened.
	ifstream inFile; // The ifstream object to use with inFileName.
	string trackName = ""; // Title of the current song being processed.
	short secInTrack = 0, minInTrack = 0; // Seconds and minutes of song in process.
	short secInPlaylist = 0, minInPlaylist = 0; // Total seconds and minutes of songs.
	short hrInPlaylist = 0; // Total hours of songs.

	cout << "Fritz Ammon    Section #1008    Assignment #9\n\n";

	// Prompt user for name of file.
	cout << "Please enter name of input file\n";
	cin >> inFileName;
	cout << endl;

	// Open file with an inFile by passing a c-string equivalent of the std::string.
	inFile.open(inFileName.c_str());

	// Print headers of tables left aligned.
	cout << left << setw(45) << "SONG TITLE"
		 << setw(12) << "LENGTH"
		 << "TOT TIME\n";

	// Keep reading until EOF is reached.
	while (inFile >> minInTrack) // Get minutes of current song.
	{
		inFile >> secInTrack; // Get seconds of current song.

		// Update total minutes and seconds.
		minInPlaylist += minInTrack;
		secInPlaylist += secInTrack;

		// Correct time as hours as the biggest unit.
		timeTick(minInPlaylist, secInPlaylist);
		timeTick(hrInPlaylist, minInPlaylist);

		getline(inFile, trackName); // Read title of song.

		rmExSpace(trackName); // Remove all extra spaces and leave 1 between words.
		formatTrackName(trackName); // Let the first letter of each word be capital only.

		// Start displaying table.
		cout << left << setw(46) << trackName; // Print formatted track name.

		cout << setfill('0'); // Change fill character to '0' for setw.
		cout << right << setw(2) << minInTrack << ':'; // Print minutes of song.
		cout << setw(2) << secInTrack; // Print seconds of song.

		cout << "\t "; // Leave a 6-space gap between song length and total length.

		cout << setw(2) << hrInPlaylist << ':' // Print total hours.
			 << setw(2) << minInPlaylist << ':' // Print total minutes.
			 << setw(2) << secInPlaylist << endl; // Print total seconds.

		cout << setfill(' '); // Change fill character back to ' ' for setw.
	}

	inFile.close(); // Close the file opened by inFile.

	return 0;
}

void rmExSpace(string& str)
// Removes extra spaces found at the beginning of str and
// in between words in str.
// str is an unformatted track name (std::string) passed by reference with
// lots of unwanted spaces.
// The function returns and str is formatted and has only 1 space between each
// word in str.
{
	size_t noSpaces = 0; // Number of series of spaces to delete.

	// Loop through str searching for spaces.
	for (size_t strPos = str.find(' '), nextPos = 0; strPos < str.size();)
	{
		// Find the first occurence of something other than a space.
		nextPos = str.find_first_not_of(' ', strPos);

		noSpaces = nextPos - strPos; // Use nextPos to find how many spaces to delete.
		str.erase(strPos, ((strPos == 0) ? noSpaces : --noSpaces)); // Delete spaces.

		strPos = str.find(' ', nextPos - noSpaces); // Look for the next start of spaces.
	}
}

void formatTrackName(string& str)
// Formats str so that only the first letter of each word in str is
// capitalized.
// str is an unformatted track name (std::string) passed by reference with
// mixed case.
// The function returns and str is formatted and only the first letter
// of each word is in uppercase.
{
	// Loop through str and search for the start of a new word.
	for (size_t strPos = str.find_first_not_of(' '), nextPos = 0; strPos < str.size() - 1;)
	{
		// Set to uppercase the first letter of the word found.
		str[strPos] = static_cast<char> (toupper(static_cast<int> (str[strPos])));

		nextPos = str.find(' ', ++strPos); // Look for the end of the word.
		if (nextPos == -1) // If no new word is found, set the rest of the characters to lowercase.
			nextPos = str.size();

		// Loop through the letter after the first to the last letter of a word
		// and set all those letters to lowercase.
		for (size_t lowPos = strPos; lowPos < nextPos; lowPos++)
			str[lowPos] = tolower(str[lowPos]);

		strPos = str.find_first_not_of(' ', nextPos); // Look for the next word.
	}
}

void timeTick(short& bigger, short& smaller)
// Corrects the time according to base 60 with respect to the bigger unit of time.
// bigger is the bigger unit of time (ex. hours), and smaller is a unit of time
// that is smaller than bigger (ex. minutes).
// The function returns and bigger and smaller is corrected so that bigger is
// increased and smaller does not exceed 59.
{
	// Increase bigger by how many times smaller goes into 60.
	bigger += static_cast<short> (smaller / 60);
	smaller = smaller % 60; // Save the reminder of the division into smaller.
}