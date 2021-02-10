#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>


#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY

//Count votes DONE
//Winner? If not: 
    //Find lowest count number
    //Delete all candidates with this count number
// Redo Process until winner found


using namespace std;

void printVector(vector<int> vec){
    for(int i : vec){
        cout << i << " ";
    }cout << endl;
}

vector<int> countVotes(vector<int> (&ballots)[1000], int n){
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
    float maxPerc = 0.0;
    for(int i = 0; i<counts.size(); i++){
        if(counts[i] == 0) discarded++;
    }
    // cout << discarded-1 << endl;

    for(int i = 1; i<counts.size(); i++){
        float p = (counts[i]/((float) ballotCount));
        if(counts[i] != 0 && p > maxPerc && (p > 0.5)) {
            maxPerc = p;
            winners.clear();
            winners.push_back(i);
        }
        else if(counts[i] != 0 && p == maxPerc) winners.push_back(i);
    }
    // Check for tie
    if(winners.size() == 0){
        for(int i = 1; i<counts.size(); i++){
            float p = (counts[i]/((float) ballotCount));
            if(counts[i] != 0 && p == (1/((float) counts.size()-discarded))) {
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
        if(counts[i] != 0 && counts[i] < min){
            lowest.clear();
            lowest.push_back(i);
            min = counts[i];
        }
        else if(counts[i] != 0 && counts[i] == min) lowest.push_back(i);
    }
    return lowest;
}

void delVotesLowest(vector<int> (&ballots)[1000], vector<int> lowest, int ballotCount){
    for(int j = 0; j<ballotCount; j++){
        // vector<int> ballot = ballots[j];
        // delete candidate
        for(int c : lowest){
            for(int i = 0; i<ballots[j].size(); i++){
                if(ballots[j][i] == c) {
                    ballots[j][i] = 0;

                    ballots[j].erase(ballots[j].begin() + i);
                    ballots[j].push_back(0);
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

    getline(cin, tmp);
    cases = stoi(tmp);
    // cases = 1;
    getline(cin, tmp); //discard spacer line

    
    int n; //#candidates
    string candidates[20];
    // vector<int[]> ballots

    
    // per case
    for(int i = 0; i<cases; i++){
        getline(cin, tmp);
        n = stoi(tmp);
        // cout << cases << " " << n << endl;
        // Read candidates
        for(int i = 0; i<n; i++){
            getline(cin, candidates[i]);
            // cout << candidates[i] << endl;
        }

        int ballotCount = 0;
        vector<int> ballots[1000];
        int vote;

        getline(cin, tmp);
        while(!tmp.empty()){
            stringstream votes(tmp);
            for(int i = 0; i<n;i++){
                votes >> vote;
                ballots[ballotCount].push_back(vote);
            }
            ballotCount++;
            if(cin.eof()) break;
            getline(cin, tmp);
        }

        // // TODO
        // if(i==19){
        //     printf("%d\n", n);
        //     for(string c : candidates){
        //         cout << c << endl;
        //     }
        //     for(int i = 0; i<ballotCount; i++){
        //         printVector(ballots[i]);
        //     }
        // }

        vector<int> winners;
        while(winners.size() == 0){
            vector<int> counts = countVotes(ballots, n);
            winners = getWinners(counts, ballotCount);
            if(winners.size()>0) break;

            vector<int> lowest = findLowest(counts);
            delVotesLowest(ballots, lowest, ballotCount);

            // printVector(counts);
            // printVector(lowest);
            // cout << "============================="<< endl;
            // for(int i = 0; i<ballotCount; i++){
            //     printVector(ballots[i]);
            // }
            // // printVector(winners);
            // cout << "============================="<< endl;

        }


        printWinners(winners, candidates);
        // cout << n << " " << ballotCount << endl;
        if( i < cases-1) cout << endl;
    }

    execute_tests();     // For IDE only
}

