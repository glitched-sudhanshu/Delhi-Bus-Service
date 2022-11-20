#include <string.h>
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Station
{
private:
    // id to uniquely identify the bus
    int id = 0;

    // name of the station from where the bus start
    string stationName = "xyz";

    unordered_map<int,string> stationsId;
    unordered_map<string, int> IdStations;

    vector<Station> v;

    int getId(Station a){
        return a.id;
    }
    
    string getName(Station a){
        return a.stationName;
    }

    void showAll()
    {
        cout << "Station ID" << "                " << "Station Name" << endl;
        cout << stationsId.size() << endl;
        for(auto x : stationsId)
        {
            cout << x.first << "                           " << x.second << endl;
        }
    }

public:
    Station()
    {}
    //constructor of bus
    Station(int ids, string stationName)
    {
        this->id = ids;
        this->stationName = stationName;
        cout<<ids << " " << stationName << endl; 
        stationsId[id] = stationName;
        cout << stationsId.size() << endl;
        IdStations[stationName] = ids;
        if(v.size() != 30) v.resize(30);
    }

    

    friend class StationGraph;
};