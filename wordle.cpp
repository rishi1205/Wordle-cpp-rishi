#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <unordered_map>
#include <cctype>

using namespace std;

const string GREEN="\033[42;30m";
const string YELLOW="\033[43;30m";
const string GRAY="\033[100;30m";
const string RESET="\033[0m";

vector<string> dictionary;

string upper(string s){
    for(char &c:s) c=toupper(c);
    return s;
}

bool loadWords(const string& file){
    ifstream fin(file);
    if(!fin) return false;

    string w;

    while(fin>>w){
        w=upper(w);
        if(w.size()==5)
            dictionary.push_back(w);
    }

    return !dictionary.empty();
}

string randomWord(){
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> dist(0,dictionary.size()-1);
    return dictionary[dist(rng)];
}

bool validGuess(const string& s){

    if(s.size()!=5)
        return false;

    for(char c:s)
        if(!isalpha(c))
            return false;

    return find(dictionary.begin(),
                dictionary.end(),
                upper(s))
           !=dictionary.end();
}

vector<int> scoreGuess(string guess,string answer){

    guess=upper(guess);
    answer=upper(answer);

    vector<int> state(5,0);

    unordered_map<char,int> freq;

    for(char c:answer)
        freq[c]++;

    for(int i=0;i<5;i++){

        if(guess[i]==answer[i]){

            state[i]=2;
            freq[guess[i]]--;
        }
    }

    for(int i=0;i<5;i++){

        if(state[i]) continue;

        if(freq[guess[i]]>0){

            state[i]=1;
            freq[guess[i]]--;
        }
    }

    return state;
}

void printGuess(string guess,
                vector<int> state){

    guess=upper(guess);

    for(int i=0;i<5;i++){

        if(state[i]==2)
            cout<<GREEN;

        else if(state[i]==1)
            cout<<YELLOW;

        else
            cout<<GRAY;

        cout<<" "<<guess[i]<<" "<<RESET<<" ";
    }

    cout<<"\n";
}

void banner(){

    cout<<"\n";
    cout<<"=========================\n";
    cout<<"      WORDLE C++\n";
    cout<<"=========================\n";
    cout<<"Guess the hidden 5-letter word.\n";
    cout<<"You have 6 attempts.\n\n";
}

void playGame() {

    string answer = randomWord();

    vector<pair<string, vector<int>>> history;

    bool won = false;

    for (int attempt = 1; attempt <= 6; ) {

        banner();

        cout << "Attempt " << attempt << "/6\n\n";

        for (auto &g : history)
            printGuess(g.first, g.second);

        cout << "\nEnter guess: ";

        string guess;
        cin >> guess;
        guess = upper(guess);

        if (!validGuess(guess)) {
            cout << "\nInvalid word!\n";
            cout << "Press ENTER...";
            cin.ignore();
            cin.get();
            continue;
        }

        vector<int> result = scoreGuess(guess, answer);

        history.push_back({guess, result});

        if (guess == answer) {
            won = true;
            break;
        }

        attempt++;
    }

    banner();

    for (auto &g : history)
        printGuess(g.first, g.second);

    cout << "\n";

    if (won) {

        cout << GREEN
             << " Congratulations! You guessed the word!"
             << RESET << "\n";

    } else {

        cout << GRAY
             << " You lost!"
             << RESET << "\n";

        cout << "The word was: "
             << answer
             << "\n";
    }
}

bool playAgain() {

    while (true) {

        cout << "\nPlay again? (Y/N): ";

        string s;
        cin >> s;

        if (s.empty())
            continue;

        char c = toupper(s[0]);

        if (c == 'Y')
            return true;

        if (c == 'N')
            return false;
    }
}

void credits() {

    cout << "\n";

    cout << "=====================================\n";
    cout << "   Thanks for Playing with Rishi!\n";
    cout << "=====================================\n";

    cout << "\n";
}

int main() {

    if (!loadWords("words.txt")) {

        cout << "Error: Could not load words.txt\n";
        cout << "Make sure words.txt exists in the same folder.\n";

        return 1;
    }

    cout << "Loaded "
         << dictionary.size()
         << " words.\n";

    do {

        playGame();

    } while (playAgain());

    credits();

    return 0;
}
