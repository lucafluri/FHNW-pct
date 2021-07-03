#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>

#include <limits.h>


#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;


typedef pair<int, int> p1;
typedef pair<int, p1> p2;

vector<vector<vector<p2>>> Adj;
vector<vector<int>> d;
vector<vector<p1>> parent;


void dijkstraAlg(int src)
{
	priority_queue<p2, vector<p2>, greater<p2>> pq;
	for (int i = 0; i < 24; i++)
	{
		pq.push({0, {src, i}});
		d[src][i] = 0;
		parent[src][i] = {-1, -1};
	}
	while (!pq.empty())
	{
		p2 vertex = pq.top();
		pq.pop();
		if (vertex.first > d[vertex.second.first][vertex.second.second])
		{
			continue;
		}
		for (p2 adjacent : Adj[vertex.second.first][vertex.second.second])
		{
			if (d[adjacent.second.first][adjacent.second.second] > d[vertex.second.first][vertex.second.second] + adjacent.first)
			{
				d[adjacent.second.first][adjacent.second.second] = d[vertex.second.first][vertex.second.second] + adjacent.first;
				pq.push({d[adjacent.second.first][adjacent.second.second], {adjacent.second.first, adjacent.second.second}});
				parent[adjacent.second.first][adjacent.second.second] = vertex.second;
			}
		}
	}
}

int main() {
    prepare_ide("p10187");     // For IDE only
    
   int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		printf("Test Case %d.\n", i + 1);
		int E;
		// if (i == 33)
		// {
		// 	E = 2 + 2;
		// }
		cin >> E;
		Adj.clear();
		Adj.resize(E * 2);
		for (int i = 0; i < Adj.size(); i++)
		{
			Adj[i].resize(24);
			for (int j = 0; j < 24; j++)
			{
				if (j == 11)
				{
					Adj[i][j].push_back({1, {i, (j + 1) % 24}});
				}
				else
				{
					Adj[i][j].push_back({0, {i, (j + 1) % 24}});
				}
			}
		}
		map<string, int> cities;
		int freeIdx = 0;
		for (int i = 0; i < E; i++)
		{
			string src, dest;
			cin >> src >> dest;
			if (cities.find(src) == cities.end())
			{
				cities.insert({src, freeIdx});
				freeIdx++;
			}
			if (cities.find(dest) == cities.end())
			{
				cities.insert({dest, freeIdx});
				freeIdx++;
			}
			int dep, dur;
			cin >> dep >> dur;
			if ((dep % 24 >= 18 || dep % 24 <= 6) && dur <= 12 && ((dep + dur) % 24 >= 18 || (dep + dur) % 24 <= 6))
				Adj[cities[src]][dep % 24].push_back({0, {cities[dest], (dep + dur) % 24}});
		}
		d.clear();
		d.resize(cities.size());
		parent.clear();
		parent.resize(cities.size());
		for (int i = 0; i < cities.size(); i++)
		{
			d[i].assign(24, INT_MAX);
			parent[i].resize(24);
		}
		string src, dest;
		cin >> src >> dest;
		if (src != dest)
		{
			if (cities.find(src) == cities.end() || cities.find(dest) == cities.end())
			{
				printf("There is no route Vladimir can take.\n");
			}
			else
			{
				dijkstraAlg(cities[src]);
				int minimum = INT_MAX;
				int integer_destination = cities[dest];
				for (int i = 0; i < 24; i++)
				{
					minimum = min(minimum, d[integer_destination][i]);
				}
				if (minimum == INT_MAX)
					printf("There is no route Vladimir can take.\n");
				else
				{
					printf("Vladimir needs %d litre(s) of blood.\n", minimum);
				}
			}
		}
		else
		{

			printf("Vladimir needs 0 litre(s) of blood.\n");
		}
	}


    execute_tests();     // For IDE only
}   
