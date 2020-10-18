#include <iostream>
#include <iomanip>

using namespace std;

// global variables
const int totalPlayers = 3;
const int totalDays = 7;

//Global function prototypes
void getPlayersInfo(string playerNames[], int playerScores[][totalDays]);

void printPlayersInfo(const string playerNames[], const int playerScores[][totalDays]);

void calculatePlayerAverage(const string playerNames[], const int playerScores[][totalDays]);

void playerWithLowestScore(const string playerNames[], const int playerScores[][totalDays]);

void playerWithHighestScore(const string playerNames[], const int playerScores[][totalDays]);

void findWinner(const string playerNames[], const int playerScores[][totalDays]);

int main() {

    // Declare 1-D string array for player names
    string playerNames[totalPlayers];

    //Declare 2-D array for player scores
    int playerScores[totalPlayers][totalDays];

    // Initializing player names
    for (int i = 0; i < totalPlayers; i++)
        playerNames[i] = "none";

    // Initializing player scores
    for (int i = 0; i < totalPlayers; i++)
        for (int j = 0; j < totalDays; j++)
            playerScores[i][j] = 0;

    getPlayersInfo(playerNames, playerScores);

    printPlayersInfo(playerNames, playerScores);

    calculatePlayerAverage(playerNames, playerScores);

    playerWithLowestScore(playerNames, playerScores);

    playerWithHighestScore(playerNames, playerScores);

    findWinner(playerNames, playerScores);

    return 0;
}

// Takes player names and scores from the user as input
void getPlayersInfo(string playerNames[], int playerScores[][totalDays]) {

    string playerName;

    for (int i = 0; i < totalPlayers; i++) {
        cout << "Enter name of the player: ";
        getline(cin, playerName);
        playerNames[i] = playerName;
        for (int j = 0; j < totalDays; j++) {
            cout << "Enter the number of shots for " << playerNames[i] << " on day " << j + 1 << ":  ";
            cin >> playerScores[i][j];
            while (playerScores[i][j] < 0) {
                cout << "\n";
                cout << "Enter a non-negative score: ";
                cin >> playerScores[i][j];
            }
            cout << "\n";
        }
        cin.get();
    }
}

// Prints information regarding players in tournament
void printPlayersInfo(const string playerNames[], const int playerScores[][totalDays]) {

    cout << "Name\t\t";
    //printing days
    for (int i = 0; i < totalDays; i++)
        cout << "Day " << i + 1 << "\t";
    cout << endl;

    cout << "----\t\t";
    for (int i = 0; i < totalDays; i++)
        cout << "-----" << "\t";
    cout << endl;

    //printing player scores
    for (int i = 0; i < totalPlayers; i++) {
        cout << playerNames[i] << "\t";
        for (int j = 0; j < totalDays; j++) {
            cout << playerScores[i][j] << "      ";
        }
        cout << endl;
    }
    cout << "\n";
}

//Calculates average score of each player and prints it
void calculatePlayerAverage(const string playerNames[], const int playerScores[][totalDays]) {

    float averageScore = 0;
    int totalScore = 0;

    cout << "Name \t\t" << "Average score" << endl;
    cout << "---- \t\t" << "-------------" << endl;

    for (int i = 0; i < totalPlayers; i++) {
        cout << playerNames[i] << "\t";
        for (int j = 0; j < totalDays; j++) {
            totalScore = totalScore + playerScores[i][j];
        }
        // type cast to float for decimal numbers
        averageScore = float(totalScore) / float(totalDays);

        // fixed is used so that set precision applies on the fractional part as well
        cout << fixed << setprecision(2) << averageScore << endl;

        // reset total score for other players
        totalScore = 0;
    }
    cout << "\n";
}

// finds player who had lowest score on a particular day and prints his/her name, score and the day
void playerWithLowestScore(const string playerNames[], const int playerScores[][totalDays]) {

    string playerName;
    int day = 0;
    int lowestScore = playerScores[0][0]; //maximum possible score

    for (int i = 0; i < totalPlayers; i++) {
        for (int j = 0; j < totalDays; j++) {
            if (lowestScore > playerScores[i][j]) {
                lowestScore = playerScores[i][j];
                day = j;
                playerName = playerNames[i];
            }
        }
    }

    cout << "Player " << playerName << " shot the lowest score, " << lowestScore << "," << " on day " << day + 1 << ".";
    cout << "\n\n";
}

// finds player who had highest score on a particular day and prints his/her name, score and the day
void playerWithHighestScore(const string playerNames[], const int playerScores[][totalDays]) {

    string playerName;
    int day = 0;
    int lowestScore = playerScores[0][0]; //minimum possible score

    for (int i = 0; i < totalPlayers; i++) {
        for (int j = 0; j < totalDays; j++) {
            if (lowestScore < playerScores[i][j]) {
                lowestScore = playerScores[i][j];
                day = j;
                playerName = playerNames[i];
            }
        }
    }

    cout << "Player " << playerName << " shot the highest score, " << lowestScore << "," << " on day " << day + 1
         << ".";
    cout << "\n";
}

//find tournament winner, i.e. player with lowest score most number of days.
void findWinner(const string playerNames[], const int playerScores[][totalDays]) {

    //Array to store id of player with lowest score on a particular day.
    //0th index for player 1, 1st index for player 2, 2nd index for player 3
    int lowestScores[totalPlayers] = {0};
    int lowestScore, lowestIndex;

    //traversing column by column to find lowest score for each day
    for (int j = 0; j < totalDays; j++) {
        lowestScore = playerScores[0][j];
        lowestIndex = 0;
        for (int i = 1; i < totalPlayers; i++) {
            if (lowestScore > playerScores[i][j]) {
                lowestScore = playerScores[i][j];
                lowestIndex = i;
            }
        }
        lowestScores[lowestIndex]++;
    }

    //finding player id which has occurred the most
    int max = lowestScores[0];
    int maxIndex = 0;

    for (int i = 1; i < totalPlayers; i++) {
        if (max < lowestScores[i]) {
            max = lowestScores[i];
            maxIndex = i;
        }
    }

    cout << endl;
    cout << "Player " << playerNames[maxIndex] << " won the tournament with, " << max << " wins!";
}