#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <limits.h>


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

int cityCounter = 0;
int connCounter = 0;

int graphM[1000][1000];

Connection connections[1000]; //Array with all connections


void printConn(Connection c){
    cout << "(" << c.start << ", " << c.dest << "; " << c.st << ", " << c.et << ")";
}

bool connEmpty(Connection c){
    return c.st == c.et;
}

int connsCatchable(Connection a, Connection b){
    if(a.et <24 && a.et >=19){
        if(b.st < 24 && b.st >=19 && a.et < b.st) return 0;
        else if(b.st >=0 && b.st <=6) return 0;
    }else if(a.et >=0 && a.et <=6){
        if(b.st >=0 && b.st <=6 && a.et <= b.st) return 0;
    }
    return 1;
}


int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < 1000; v++)
    if (sptSet[v] == false && dist[v] <= min)
        min = dist[v], min_index = v;
    return min_index;
}

int dijkstra(int src) {
    int dist[1000];
    bool sptSet[1000];
    for (int i = 0; i < 1000; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
        dist[src] = 0;
    for (int count = 0; count < 1000 - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < 1000; v++)
            if (!sptSet[v] && graphM[u][v] != -1 && dist[u] != INT_MAX && dist[u] + graphM[u][v] < dist[v]) dist[v] = dist[u] + graphM[u][v];
    }
    // res = dist[cities[dest]];

    // printSolution(dist);
    // Return lowest #blood
    // iterete over all conns that have dest as dest and return lowest
    int min = INT_MAX;
    for(int i = 0; i < 1000; i++){
        if(dist[i] == INT_MAX) continue;
        if(connections[i].dest == cities[dest] && dist[i] < min) min = dist[i];
    }
    return min;
}


int main() {
    prepare_ide("p10187");     // For IDE only
    
    int counter = 1;
    cin >> n;
    while(n--){ //foreach testcase
        cin >> c;
        cityCounter = 0;
        connCounter = 0;
        for(int i = 0; i<1000; i++){
            memset(graphM[i], -1, sizeof(graphM[i]));
            connections[i] = Connection();
        }
        cities.clear();
        res = 0;

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
        
        if(start == dest) {
            cout << "Test Case " << counter++ << "." << endl;
            cout << "Vladimir needs 0 litre(s) of blood." << endl;
            continue;
        }
        if(!cityCounter || !cities.count(start) || !cities.count(dest)) {
            cout << "Test Case " << counter++ << "." << endl;
            cout << "There is no route Vladimir can take." << endl;
            continue;
        }

        // Build graph with connections (structs)
        for(int i = 0; i < connCounter; i++){
            Connection conn = connections[i];
            // Find all connections that can be reached after this and add in adj list
            for(int j = 0; j<connCounter; j++){
                if(j==i) continue;

                // TODO Add connections to graph by start and dest not times
                if(conn.dest == connections[j].start){
                    graphM[i][j] = connsCatchable(conn, connections[j]);
                }
            }
        }

        // TODO DIJKSTRA and find shorted weighted path => weight sum = litre of blood
        // Dijkstra for every conn that has start as start adn find lowest res
        int min = INT_MAX;


        for(int i = 0; i<connCounter; i++){
            // if(connEmpty(connections[i]) || connections[i].st != cities[start]) continue;
            if(connections[i].start == cities[start]) {
                // printConn(connections[i]);
                // cout << endl;

                int tmp = dijkstra(i);
                // cout << tmp << endl;
                if(tmp < min) min = tmp;
            }

        }
        // res = dijkstra(cities[start]);
        // cout << cities[start] << " -> " << cities[dest] << endl;
        // cout << min << endl;
        if(min == INT_MAX){
            cout << "Test Case " << counter++ << "." << endl;
            cout << "There is no route Vladimir can take." << endl;
        }else{
            cout << "Test Case " << counter++ << "." << endl;
            cout << "Vladimir needs " << min << " litre(s) of blood." << endl;
        }
        



    }


    execute_tests();     // For IDE only
}   
