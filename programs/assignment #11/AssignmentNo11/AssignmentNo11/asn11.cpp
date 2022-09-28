// Fritz Ammon
// Section #1001
// Assignment #11
//
// This program provides stastical information summarized in reports of a basketball
// team. The information is gathered from two different files, one for player info
// and another for game info.
//
// Input
// The program prompts the user for the two files and another file to output the
// summary. One file holding the player info will contain a max of 15 players,
// their position in the game, and the number of their uniform. The program then
// reads data of games from the second file. Performance of each player will follow
// their uniform number. a for assists, p for points, and r for rebounds.
//
// Process
// The program sorts the list of players in alphabetical order by last name using
// a selection sort function. It adds up data and calculates the average of each
// set of data for each player. Formatting of strings is also executed.
//
// Output
// Prints out the roster of the team, the statistics of each player, and the total
// for the team. It then prints out a report on the averages for each player, all
// with two decimal places and neatly formatted.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

struct playerType
{
	string firstName; // First name of player.
	string lastName; // Last name of player.
	string posPlayed; // Position player played.
	int noUniform; // Number on player's uniform.
	int noGamesPlayed; // Number of games player has played.
	int noAssists; // Number of assists in game.
	int noPointsScored; // Number of points scored in game.
	int noRebounds; // Number of rebounds in game.
};

void selectionSort(playerType list[], int n);
double getAverage(int sum, int size);
void initialize(playerType& player);
void format(string& str);

int main()
{
	ifstream teamData; // The ifstream object that opens the player info file.
	ifstream teamStats; // The ifstream object that opens the game info file.
	ofstream teamSummary; // The ofstream object that opens the file to write to.
	string buffer; // A temporary string used while reading file names to use.
	playerType players[15]; // An array of playerType structures.
	int noPlayers = 0; // The number of players found in the file.
	int noBuffer; // A temporary integer used while adding up the player stats.
	char dataType; // To tell apart from different information (a, p, or r).
	int totAssists = 0; // The sum of each player's assists.
	int totPoints = 0; // The sum of each player's points scored.
	int totRebounds = 0; // The sum of each player's rebounds.

	cout << "Please enter name of player information data file\n";
	cin >> buffer;

	teamData.open(buffer.c_str()); // Open player info file for reading.

	cout << "Please enter name of output file\n";
	cin >> buffer;

	teamSummary.open(buffer.c_str()); // Open team info file for writing.

	cout << "Please enter name of player stats file\n";
	cin >> buffer;

	teamStats.open(buffer.c_str()); // Open game info file for reading.

	while (teamData >> players[noPlayers].firstName)
	{
		// Read in the entire team roster.
		teamData >> players[noPlayers].lastName;
		teamData >> players[noPlayers].posPlayed;
		teamData >> players[noPlayers].noUniform;

		// Make the first letter uppercase and all others lowercase.
		format(players[noPlayers].firstName);
		format(players[noPlayers].lastName);
		format(players[noPlayers].posPlayed);

		initialize(players[noPlayers]); // Set integer members to 0.

		noPlayers++;
	}

	selectionSort(players, noPlayers); // Sort the array by strings (last name).

	while (teamStats >> noBuffer) // Read uniforn number.
	{
		for (int player = 0; player < noPlayers; player++)
		{
			if (players[player].noUniform == noBuffer) // Correct player sruct found.
			{
				players[player].noGamesPlayed++;

				// Read in all 3 different types of information.
				for (int dataPart = 0; dataPart < 3; dataPart++)
				{
					teamStats >> dataType;
					teamStats >> noBuffer;

					switch (dataType)
					{
					case 'a':
						players[player].noAssists += noBuffer;
						break;
					case 'p':
						players[player].noPointsScored += noBuffer;
						break;
					case 'r':
						players[player].noRebounds += noBuffer;
						break;
					}
				}

				break;
			}
		}
	}

	teamSummary << "Fritz Ammon  Assignment #11  Section #1001\n\n";

	teamSummary << left << setw(25) << "NAME"
				<< setw(13) << "POSITION"
				<< "UNIFORM #\n";

	// Display the position and uniform.
	for (int player = 0; player < noPlayers; player++)
	{
		teamSummary << left << setw(25) << (players[player].lastName +
			',' + players[player].firstName); // Append strings.
		teamSummary << setw(19) << players[player].posPlayed;
		teamSummary << right << setw(3) << players[player].noUniform;
		teamSummary << endl;
	}

	teamSummary << endl;

	teamSummary << left << setw(26) << "NAME"
				<< setw(14) << "UNIFORM #" 
				<< setw(8) << "GAMES"
				<< setw(11) << "ASSISTS"
				<< setw(8) << "POINTS"
				<< "REBOUNDS\n";

	for (int player = 0; player < noPlayers; player++)
	{
		teamSummary << left << setw(32) << (players[player].lastName +
			',' + players[player].firstName);
		teamSummary << right << setw(3) << players[player].noUniform;
		teamSummary << setw(10) << players[player].noGamesPlayed;
		teamSummary << setw(10) << players[player].noAssists;
		teamSummary << setw(10) << players[player].noPointsScored;
		teamSummary << setw(10) << players[player].noRebounds << endl;

		// Keep track of team totals.
		totAssists += players[player].noAssists;
		totPoints += players[player].noPointsScored;
		totRebounds += players[player].noRebounds;
	}

	teamSummary << left << setw(52) << "TEAM TOTALS"
				<< right << setw(3) << totAssists
				<< setw(10) << totPoints
				<< setw(10) << totRebounds << endl << endl;

	teamSummary << setw(65) << "AVERAGE   AVERAGE   AVERAGE" << endl;
	teamSummary << left << setw(26) << "NAME"
				<< setw(12) << "UNIFORM #" 
				<< setw(11) << "ASSISTS"
				<< setw(8) << "POINTS"
				<< "REBOUNDS" << endl;

	teamSummary << fixed << showpoint;
	teamSummary << setprecision(2);

	for (int player = 0; player < noPlayers; player++)
	{
		// Print out 0 if no games have been played, otherwise print out
		// the average stats of each player.
		teamSummary << left << setw(32) << (players[player].lastName +
			',' + players[player].firstName);
		teamSummary << right << setw(3) << players[player].noUniform;
		teamSummary << setw(10) << ((players[player].noGamesPlayed > 0) ?
			getAverage(players[player].noAssists, players[player].noGamesPlayed) : 0);
		teamSummary << setw(10) << ((players[player].noGamesPlayed > 0) ?
			getAverage(players[player].noPointsScored, players[player].noGamesPlayed) : 0);
		teamSummary << setw(10) << ((players[player].noGamesPlayed > 0) ?
			getAverage(players[player].noRebounds, players[player].noGamesPlayed) : 0);
		teamSummary << endl;
	}

	teamStats.close();
	teamSummary.close();
	teamData.close();

	return 0;
}

void selectionSort(playerType list[], int n)
// list is the array of playerTypes.
// n is the size, or length, of the array.
// Sorts list so that elements are in alphabetical order by last name.
{
	playerType temp;
	int index;
	
	for (int i = 0; i < n - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list[j].lastName < list[index].lastName)
				index = j;
		}

		temp = list[index];
		list[index] = list[i];
		list[i] = temp;
	}
}

double getAverage(int sum, int size)
// sum is the sum of all integers in a set.
// size is the number of integers that were added.
// Returns the average of a set of integers.
{
	return static_cast<double> (sum) / size;
}

void initialize(playerType& player)
// player is a playerType, holding info of a basketball player.
// The function sets all integer members of player to 0.
{
	player.noAssists = player.noGamesPlayed = player.noPointsScored =
	player.noRebounds = 0;
}

void format(string& str)
// str is an unformatted string with a mix of uppercase and lowercase letters.
// Makes str have only the first letter uppercase.
{
	str[0] = toupper(str[0]);
	for (size_t c = 1; c < str.size(); c++)
		str[c] = tolower(str[c]);
}