#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
 private:
   string name;
   int score;
 public:
    Player() : name(""), score(0) {}
    Player(string newName, int newScore) : name(newName), score(newScore) {}
    void setName(string newName) {
        name = newName;
    }
    void setScore(int newScore) {
        score = newScore;
    }
    string getName() const {
        return name;
    }
    int getScore() const {
        return score;
    }
};

// Adding a player (maximum up to 10)
bool addPlayer(vector<Player>& players, const string& name, int score) {
    if (players.size() >= 10) {
        cout << "Only 10 players can be stored at a time!" << endl;
        return false;
    }
    players.emplace_back(name, score);
    return true;
}
// Printing all player names and their scores to the screen
void printPlayers(const vector<Player>& players) {
    cout << "Players:" << endl;
    for (const auto& player : players) {
        cout << player.getName() << ": " << player.getScore() << endl;
    }
}

// View player's score
void viewPlayerScore(const vector<Player>& players, const string& name) {
    for (const auto& player : players) {
        if (player.getName() == name) {
            cout << name << ": " << player.getScore() << endl;
            return;
        }
    }
    cout << name << " hasn't been entered." << endl;
}
// Remove a player by name
void removePlayer(vector<Player>& players, const string& name) {
    for (auto i = players.begin(); i != players.end(); i++) {
        if (i->getName() == name) {
            players.erase(i);
            cout << name << " has been removed." << endl;
            return;
        }
    }
    cout <<  name << " hasn't been entered." << endl;
}

int main() {
    vector<Player> players;
    string name;
    int score;
    char option;

    while (true) {
        // Options for user
        cout << "\n[A]dd player\n";
        cout << "[R]emove player\n";
        cout << "[P]rint all players\n";
        cout << "[V]iew player's score\n";
        cout << "\nType a letter to continue: " << endl;
        cin >> option;
        switch (option) {
            case 'A':
                cout << "Name of player to add:  " << endl;
                cin >> name;
                cout << name << "'s score: " << endl;
                cin >> score;
                addPlayer(players, name, score);
                break;
            case 'R':
                cout << "Name of player to remove: " << endl;
                cin >> name;
                removePlayer(players, name);
                break;
            case 'P':
                printPlayers(players);
                break;
            case 'V':
                cout << "Name of player to view: " << endl;
                cin >> name;
                viewPlayerScore(players, name);
                break;
            default:
                cout << "Please enter a number 1-4." << endl;
        }
    }
}
