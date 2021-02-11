#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>


#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY

using namespace std;

vector<int> countVotes(vector<int> (&ballots)[1001], int n){
    vector<int> counts(n+1, 0);
    for(vector<int> ballot : ballots){
        for(int vote : ballot){
            if(vote != 0) counts[vote]++;
            break;
        }
    }
    return counts;
}

vector<int> getWinners(vector<int> &counts, int ballotCount){
    vector<int> winners;
    int discarded = 0;
    int maxPerc = 0;
    const int mult = 100000;
    for(int i = 0; i<counts.size(); i++){
        if(counts[i] == 0) discarded++;
    }

    for(int i = 1; i<counts.size(); i++){
        int p = (counts[i]/((float) ballotCount)) * mult;
        if(counts[i] != 0 && p > maxPerc && (p > (int)(0.5*mult))) {
            maxPerc = p;
            winners.clear();
            winners.push_back(i);
        }
        else if(counts[i] != 0 && p == maxPerc) winners.push_back(i);
    }
    // Check for tie
    if(winners.size() == 0){
        for(int i = 1; i<counts.size(); i++){
            int p = (counts[i]/((float) ballotCount)) * mult;
            int fraction = (mult/((float) counts.size()-discarded));
            if(counts[i] != 0 && p == fraction) {
                winners.push_back(i);
            }
        }
        if(winners.size() != counts.size()-discarded) winners.clear();
    }
    
    return winners;
}

void printWinners(vector<int> winners, string (&candidates)[20]){
    for(int winner : winners){
        cout << candidates[winner-1] << endl;
    }
}

vector<int> findLowest(vector<int> &counts){
    vector<int> lowest;
    int min = 100;
    for(int i = 1; i<counts.size(); i++){
        if(counts[i] != -1 && counts[i] != 0 && counts[i] < min){
            lowest.clear();
            lowest.push_back(i);
            min = counts[i];
        }
        else if(counts[i] != -1 && counts[i] != 0 && counts[i] == min) lowest.push_back(i);
    }
    // add all that have 0
    for(int i = 1; i<counts.size(); i++){
        if(counts[i] == 0) lowest.push_back(i);
    }
    return lowest;
}

void delVotesLowest(vector<int> (&ballots)[1001], vector<int> lowest, int ballotCount){
    for(int j = 0; j<ballotCount; j++){
        // delete candidate
        for(int c : lowest){
            for(int i = 0; i<ballots[j].size(); i++){
                if(ballots[j][i] == c) {
                    ballots[j].erase(ballots[j].begin() + i);
                    ballots[j].push_back(-1);
                    break;
                }
            }
        }    
    }
}


int main() {
    prepare_ide("p10142");     // For IDE only

    int cases;

    string tmp;

    cin >> cases;
    if(cases == 0) return 0;
    while(getchar()!='\n');
    while(getchar()!='\n');

    int n; //#candidates
    string candidates[20];

    // per case
    for(int i = 0; i<cases; i++){
        int ballotCount = 0;
        vector<int> ballots[1001];
        int vote;
        bool hasVotes = false;

        cin >> n;
        while(getchar()!='\n');
        if(n == 0) continue;
        // Read candidates
        for(int j = 0; j<n; j++){
            getline(cin, candidates[j]);
        }


        getline(cin, tmp);  
        while(!tmp.empty()){
            hasVotes = true;
            stringstream votes(tmp);
            for(int j = 0; j<n;j++){
                votes >> vote;
                ballots[ballotCount].push_back(vote);
            }
            ballotCount++;
            if(cin.eof()) break;
            getline(cin, tmp);
        }
        
        

        if(hasVotes){
            vector<int> winners;
            while(winners.size() == 0){
                vector<int> counts = countVotes(ballots, n);
                winners = getWinners(counts, ballotCount);
                if(winners.size()>0) break;

                vector<int> lowest = findLowest(counts);
                delVotesLowest(ballots, lowest, ballotCount);
            }
            printWinners(winners, candidates);
        }else{ 
            // No votes
            for(int j = 0; j<n;j++){
                cout << candidates[j] << endl;
            }
        }
        if( i < cases-1) cout << endl;

    }

    execute_tests();     // For IDE only
}

