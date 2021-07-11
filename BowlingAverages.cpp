// BowlingAverages.cpp : This file contains the 'main' function, along with an int function (GetBowlingData) and 2 void functions
// (GetAverageScore) and (PrettyPrintResults). Program execution begins and ends there.
//

// This program takes in data from a file titled "BowlingScoresModified.txt".
// Uses parallel arrays, arrays as parameters



// including header file
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//global constant to store file name as a string
const string inputFile = ("BowlingScoresModified.txt");
//global const for number of rows/columns
const int total_rows = 10;
const int total_cols = 5;
// global consts for setw's
const int nameSet = 24;
const int secondarySet = 10;
const int playerSet = 14;
const int scoreSet = 5;
const int averageSet = 7;



// defining structure
struct scoresData {
	//string to hold name of bowler
	string playerNames;
	//one dimensional array of ints to store bowlers 4 scores
	int playerScores[total_cols];
	//int to hold average bowling scores
	int playerAverage;
};



//function to read and store data into two arrays. takes in file name and empty arrays as input parameters from file BowlingScores.txt; returns
//a status of success or failure (true or false)
int GetBowlingData(string inputFile, scoresData arrScores[])
{
	// attempting to use same code from the program to count the letters for file errors
	// opening input file
	ifstream inFile;
	inFile.open(inputFile);

	// attempting to use same code from the program to count the letters for file errors - pg 221 in textbook 
	// error if file fails
	if (!inFile) {
		cout << "Error with file" << endl;
		return 1;
	}

	// for loop for players names (rows)
	for (int r = 0; r < total_rows; r++)
	{
		inFile >> arrScores[r].playerNames;
		// for loop for players scores (columns)
		for (int c = 0; c < total_cols; c++)
		{
			inFile >> arrScores[r].playerScores[c];
		}
	}
	// pausing
	system("pause");
	// closing out the open file
	inFile.close();
	return 1;
}

//function to calculate the average bowling score. takes as input arrays from GetBowlingData and returns the average score of each bowler
//in a separate array
void GetAverageScore(scoresData arrScores[])
{
	// assigning variable for average score
	//int averageScore;
	// int to run through rows
	for (int r = 0; r < total_rows; r++)
	{
		// assigning the value of total to 0 - everytime it runs through the loop, it reinitializes to 0 to store new value for next player
		int total = 0;
		// for loop to add player scores together based on columns
		for (int c = 0; c < total_cols; c++)
		{
			total += arrScores[r].playerScores[c];
		}
		// taking the total for each value and dividing by 4 (number of columns of scores)
		arrScores[r].playerAverage = total / total_cols;
		// reassigning averageScore to playerAverage[i]
		//arrScores[r].playerAverage = averageScore;
	}
}

//function that ouptuts the results: bowler name, scores and average
void PrettyPrintResults(scoresData arrScores[])
{
	cout << "" << endl;
	cout << setw(nameSet) << left << "Player Name" << setw(secondarySet) << left << "Player Scores " << setw(secondarySet) << " " << left << "Player Average" << endl;
	cout << "" << endl;
	// for loop for rows
	for (int r = 0; r < total_rows; r++)
	{
		// printing out the player names
		cout << setw(playerSet) << left << arrScores[r].playerNames << " ";
		cout << setw(scoreSet) << " ";
		// for loop for running through columns for scores
		for (int c = 0; c < total_cols; c++)
		{
			// printing out the player scores
			cout << setw(scoreSet) << left << arrScores[r].playerScores[c] << " ";
		}
		// printing out the players average score
		cout << setw(averageSet) << " ";
		cout << setw(secondarySet) << left << arrScores[r].playerAverage << " " << endl;
	}
}

//main function
int main()
{
	// assigning values to names, scores, and averages for all players
	// 10 players total (rows = r)
	// each player has 4 scores listed (columns = c)
	//string playerNames[total_rows];
	//int playerScores[total_rows][total_cols] = { 0 };
	// player average has to run through all 10 players (10 rows)
	//float playerAverage[total_rows] = { 0 };

	// calling the functions with parameters
	//GetBowlingData(scoreData, playerNames, playerScores);
	//GetAverageScore(playerScores, playerAverage);
	//PrettyPrintResults(playerNames, playerScores, playerAverage);

	// struct
	scoresData arrScores[total_rows];
	GetBowlingData(inputFile, arrScores);
	GetAverageScore(arrScores);
	PrettyPrintResults(arrScores);
}


