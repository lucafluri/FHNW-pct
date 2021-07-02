#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>
#include <queue>


#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

struct Connection{
    int start;
    int dest;
    int st; //start time
    int et; //endtime
};

int n, c, res;
string start, dest;
map<string, int> cities; //map string city to int for adj list

Connection graph[1000][1000]; //adj list
Connection connections[1000]; //Array with all connections


void printConn(Connection c){
    cout << "(" << c.start << ", " << c.dest << "; " << c.st << ", " << c.et << ")";
}

bool connEmpty(Connection c){
    return c.st == c.et;
}

int main() {
    prepare_ide("p10187");     // For IDE only
    
    int counter = 1;
    cin >> n;
    while(n--){ //foreach testcase
        cin >> c;
        int cityCounter = 0;
        int connCounter = 0;
        while(c--){ //for each connection
            string c1, c2;
            int dep, dur;
            cin >> c1 >> c2 >> dep >> dur;
            
            // Discard invalid cases
            if(dep > 6 && dep < 18) continue;
            else if(dur>12) continue;
            else if(dur==12 && dep != 18) continue;
            else if((dep+dur)%24 > 6 && (dep+dur)%24 < 18) continue;

            // Save connection
            if(!cities.count(c1)) cities[c1] = cityCounter++;
            if(!cities.count(c2)) cities[c2] = cityCounter++;

            // Add connection array
            Connection tmp = {cities[c1], cities[c2], dep, (dep+dur)%24};
            connections[connCounter++] = tmp;
            // Find

            // TODO PRINTLN
            // cout << c1 << " " << c2 << " " << dep << " " << dur << endl;
            // conns[sizeof(conns)] = tmp;

        }
        cin >> start >> dest;

        // No valid connections or start and dest not reachable
        if(!cityCounter || !cities.count(start) || !cities.count(dest)) {
            cout << "Test Case " << counter++ << "." << endl;
            cout << "There is no route Vladimir can take." << endl;
        }
        else if(start == dest) {
            cout << "Test Case " << counter++ << "." << endl;
            cout << "Vladimir needs 0 litre(s) of blood." << endl;
        }

        // Build graph with connections (structs)
        for(int i = 0; i < connCounter; i++){
            Connection conn = connections[i];
            // Find all connections that can be reached after this and add in adj list
            for(int j = 0; j<connCounter; j++){
                if(j==i) continue;

                int size = 0;
                for(int k = 0; k<connCounter; k++){
                    if(connEmpty(graph[i][k])) break;
                    size++;
                }

                // TODO Add connections to graph by start and dest not times
                if(conn.dest == connections[j].start){
                    // // TODO REMOVE PRINT
                    // cout << i << ": ";
                    // printConn(conn);
                    // cout << " -> ";
                    // printConn(connections[j]);
                    // cout << " SIZE " << size << endl;


                    graph[i][size] = connections[j];
                }
            }
        }

        // TODO Traverse graph with DFS, save all paths between start and dest
        // Go through every path and find shortest route in days


        // TODO PRINTS

        // for(int i = 0; i < connCounter; i++){
        //     Connection tmp = connections[i];
        //     cout << i << ":: " << tmp.start << " " << tmp.dest << " " << tmp.st << " " << tmp.et <<endl;
        // }
        // TODO print graph
        for(int i = 0; i < connCounter; i++){
            // Connection tmp = connections[i];
            // cout << tmp.start << " " << tmp.dest << " " << tmp.st << " " << tmp.et <<endl;
            int size = sizeof(graph[i])/sizeof(graph[i][0]);
            if(size > 0){
                if(!connEmpty(connections[i])) {
                    printConn(connections[i]);
                    cout << ":: ";

                    // cout << i << ":: ";
                    for(int j = 0; j<connCounter; j++){
                        Connection tmp = graph[i][j];
                        if(!connEmpty(tmp)) {
                            printConn(tmp);
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }

        }


    }


    execute_tests();     // For IDE only
}   
