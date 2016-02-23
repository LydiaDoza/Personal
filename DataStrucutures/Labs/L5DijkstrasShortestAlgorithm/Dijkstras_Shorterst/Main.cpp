/**************************************************************************
* Author:					Lydia Doza
* Date Created:				30/5/2015
* Last Modification Date:	30/5/2015
* Lab Number:
* Filename:					Dijkstras_Shorterst
*
* Overview:
*	Utilizes Dijkstra's shortest algorithm.
*
* Input:
*	Input from a file the cities and highway junctions as
*	Vertices, input highways as edges between the vertices.
*
*	From user:
*		Starting Vertex : Klamath Falls
*		Ending Vertex : Hwy 140 and Dead Indian Memorial Road Junction
*
* Output:
*	The results from using Dijkstra's Algorithm are printed
*	to the screen indicating 1) the shortest distance
*	between two cities and 2) the time it would take to
*	drive between the cities (assuming the speed
*	limit is driven).
*
*	Distance:	31 miles
*	Time:		0 hours 34 minutes
**************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Graph.h"
#include "Exception.h"

struct City
{
	string m_name;
	string m_preceding_edge;

	vector<Edge<string, string>> m_roads; // for subscript

	int m_miles = -1;
	int iPrev = -1;

	bool m_processed = false;
};

// called from functions
string ValidInput(string & s, const Graph<string, string> & g);
void PrimeCities(vector<City> & cities, int & iStart, int & iEnd);

// called by user
bool ReadFile(const string & file, Graph<string, string> & graph);
void GetCities(string & begin, string & finish, const Graph<string, string> & g);
list<City> Dijkstra(const Graph<string, string> & graph, string begin, string finish);
void DisplayTimeAndDistance(const list<City> & shortest, const string & begin, const string & finish);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	string begin, finish;
	list<City> shortest;
	Graph<string, string> g;

	if (ReadFile("Map.txt", g))
	{
		GetCities(begin, finish, g); // get user input
		shortest = Dijkstra(g, begin, finish);
		DisplayTimeAndDistance(shortest, begin, finish);
	}

	return 0;
}

/**********************************************************************
* Purpose:	Reads file and inserts info into Graph graph
*			Primes all the data. If success, return true.
* Entry: 	string file, Graph<string, string> & graph
* Exit:		returns true if successful.
************************************************************************/
bool ReadFile(const string & file, Graph<string, string> & graph)
{
	ifstream map(file.c_str());
	bool valid = true;

	if (map.is_open())
		while (!map.eof())
		{
			string orig, dest, hwy;
			int weight = 0;

			getline(map, orig, ',');
			getline(map, dest, ',');
			getline(map, hwy, ',');
			map >> weight;
			map.get(); // for end line

			try
			{
				graph.InsertVertex(orig);
			}
			catch (Exception e)
			{
				//cout << e << endl;
			}

			try
			{
				graph.InsertVertex(dest);
			}
			catch (Exception e)
			{
				//cout << e << endl;
			}

			graph.InsertEdge(orig, dest, hwy, weight);

		}
	else
		valid = false;

	return valid;
}

/**********************************************************************
* Purpose:	Gets begin and finish vertices from user
* Entry: 	string & begin, string & finish
* Exit:		begin and finish are input from user
************************************************************************/
void GetCities(string & begin, string & finish, const Graph<string, string> & g)
{
	string temp;

	cout << "\nWhat city/jct would you like to start at? ";
	begin = ValidInput(temp, g);

	cout << "\nWhat city/jct would you like to end at? ";
	finish = ValidInput(temp, g);

}

/**********************************************************************
* Purpose:	checks to make sure input is valid.
* Entry: 	string & s, const Graph<string, string> & g
* Exit:		string s is changed to valid value
************************************************************************/
string ValidInput(string & s, const Graph<string, string> & g)
{
	string temp;
	bool valid = false;

	while (!valid)
	{
		cin.sync();
		getline(cin, temp);
		valid = g.CityInList(temp);
		if (!valid)
			cout << "\nInvalid City. Input a valid city." << endl;
	}

	return temp;
}

/**********************************************************************
* Purpose:	fills in data for cities
* Entry: 	vector<City> & cities, int iStart, int iEnd
* Exit:		vector of cities is primed with data
************************************************************************/
void PrimeCities(vector<City> & cities, int & iStart, int & iEnd)
{
	int processed_cities = 1; // one city has already been processed
	int size = cities.size();	// function called once
	int cur = iStart;			// set a temp index to keep iStart val
	int distance = 0;

	while (processed_cities < size) // go through entire vector of cities
	{
		cities[cur].m_processed = true;

		for (Edge<string, string> & e : cities[cur].m_roads)
		{
			bool found = false;
			int iDest = -1;

			// increment iDest until city name is found
			while (iDest < size && !found)
			{
				++iDest;
				if (cities[iDest].m_name == e.GetDest()->GetData())
					found = true;
			}

			// set distance to current city distance + edge weight
			distance = cities[cur].m_miles + e.GetWeight();

			// if the city isn't processed
			if (!cities[iDest].m_processed)
				// if the miles in the city is larger than the current mileage
				if (cities[iDest].m_miles > distance || cities[iDest].m_miles == -1)
				{
					//set the miles to shortest
					//set the previous index to cur
					//set the preceding edge name to current edges name
					cities[iDest].m_miles = distance;
					cities[iDest].iPrev = cur;
					cities[iDest].m_preceding_edge = e.GetData();
				}
		}

		// Find Next city to process
		for (int citz(0), d(-1); citz < cities.size(); citz++)
		{
			// city isn't processed AND city miles isn't -1 (never visited)
			if (!cities[citz].m_processed && cities[citz].m_miles != -1)

				// temp distance hasn't changed yet 
				// OR the temp distance is larger than current cities miles
				if (d == -1 || d > cities[citz].m_miles)
				{
					cur = citz;					// set current index
					d = cities[citz].m_miles;	// set temp distance
				}
		}

		++processed_cities;
	}
}



/**********************************************************************
* Purpose:	implements Dijkstra's shortest path algorithm
* Entry: 	const Graph<string, string> & graph, string begin, string finish
* Exit:		list<City>
************************************************************************/
list<City> Dijkstra(const Graph<string, string> & g, string orig, string dest)
{
	list<City> shortest_path;	// used for return
	vector<City> cities;		// cities vector (vector because [] access)

	int iStart(-1), iEnd(-1), size(0);

	bool fStart = false, fEnd = false, done = false;

	for (Vertex<string, string> & v : g.GetVertices())
	{
		City temp;
		temp.m_name = v.GetData();	// assign name
		list<Edge<string, string>> roads = v.GetEdges(); // get list of roads

		// turn list of roads into a vector of roads by passing in the 
		// beginning and end of the list.
		temp.m_roads = { begin(roads), end(roads) }; // assign list of roads

		cities.push_back(temp); // add temp to vector of cities
	}

	size = cities.size();

	// go through each city to set indexes
	for (int citz(0); citz < size; citz++)
	{
		// find start city
		if (cities[citz].m_name == orig)
			iStart = citz;

		// find end city
		if (cities[citz].m_name == dest)
			iEnd = citz;
	}

	// origin distance is zero
	cities[iStart].m_miles = 0;
	// processed now! :D
	cities[iStart].m_processed = true;

	//////////////////////////////////////////////////////////////////////////
	//					Fill in data for rest of cities						//
	//////////////////////////////////////////////////////////////////////////
	PrimeCities(cities, iStart, iEnd);

	// start from end then go through all the cities until
	// beginning.
	while (iEnd != -1)
	{
		shortest_path.push_front(cities[iEnd]);
		iEnd = cities[iEnd].iPrev;
	}

	return shortest_path;
}
/**********************************************************************
* Purpose:	Displays distance from beginning to end cities and time it
*			takes to drive going the speed limit.
* Entry: 	const list<City> & cities
* Exit:		void
************************************************************************/
void DisplayTimeAndDistance(const list<City> & shortest, const string & begin, const string & finish)
{
	int step(1), miles(0), dist(0), minutes(0);
	double time(0.0), mph(0.0);

	system("CLS");
	cout << setw(17) << "Starting City:" << begin << endl;
	cout << setw(17) << "End City:" << finish << endl << endl;

	for (City c : shortest)
	{
		//////////////////////////////////////////////////////////////////////////
		//								Distances								//
		//////////////////////////////////////////////////////////////////////////
		if (c.m_name == begin)
		{
			cout << "Start at " << c.m_name << endl << endl;
		}
		else if (c.m_name == finish)
		{
			cout << step++ << ". Take " << setw(8) << c.m_preceding_edge << " to "
				<< c.m_name << endl;
			cout << "\nArrived at " << c.m_name;
		}
		else
		{
			cout << step++ << ". Take " << setw(8) << c.m_preceding_edge << " to "
				<< c.m_name << endl;
		}

		//////////////////////////////////////////////////////////////////////////
		//									Times								//
		//////////////////////////////////////////////////////////////////////////
		if (c.m_preceding_edge == "I-5")
			mph = 65.0;
		else
			mph = 55.0;
		// first pass, miles is zero
		dist = c.m_miles - miles;

		time += dist / mph;

		// reassign miles after finding time
		miles += dist;
	}

	minutes = (time - floor(time)) * 60;

	cout << "\n\n\n" << setw(14) << "Total mileage:" << " " << miles << endl
		<< setw(14) << "Total Time:" << " " << floor(time) << " hours "
		<< minutes << " minutes\n" << endl;
}

