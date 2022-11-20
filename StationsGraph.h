#include "Station.h"
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <set>
#include <cstdlib>
#include <vector>

class StationGraph
{
private:
    int vertices = 0;
    // unordered_map<Station, vector<pair<Station, vector<int>>>> adjList;
    unordered_map<int, vector<pair<int, vector<int>>>> adjList;

    
    vector<Station> stations;

    void addConnection(Station a, Station b, int fare, int time, int distance)
    {
        int aid = a.getId(a);
        int bid = b.getId(b);
        adjList[aid].push_back({bid, {fare, time, distance}});
        adjList[bid].push_back({aid, {fare, time, distance}});
    }

    int dikjstraAlgo(Station src, Station dest, int parameter)
    {
        vertices = adjList.size();
        vector<int> dist(vertices, 1e9);
        int srcId = src.getId(src);
        int destId = dest.getId(dest);
        dist[srcId] = 0;
        set<pair<int, int>> st;
        st.insert({0, srcId});

        while (!st.empty())
        {
            auto it = st.begin();
            int node = it->second;
            int distTillNow = it->first;
            st.erase(it);

            for (auto nbrPair : adjList[node])
            {
                int nbr = nbrPair.first;
                int currEdge = nbrPair.second[parameter];
                if (distTillNow + currEdge < dist[nbr])
                {
                    auto f = st.find({dist[nbr], nbr});
                    if (f != st.end())
                        st.erase(f);
                    dist[nbr] = distTillNow + currEdge;
                    st.insert({dist[nbr], nbr});
                }
            }
        }
        return dist[destId];
    }

    void addStation()
    {
        stations.resize(20);
        Station s1 = Station(0, "Manglapuri");
        Station s2 = Station(1, "Pitampura");
        Station s3 = Station(2, "Puth kala");
        Station s4 = Station(3, "Rajaouri");
        Station s5 = Station(4, "Janakpuri West");
        Station s6 = Station(5, "Palam");
        Station s7 = Station(6, "Dwarka sector 11");
        Station s8 = Station(7, "Pole star");
        Station s9 = Station(8, "Peeragadhi");
        Station s10 = Station(9, "Kali Mata Mandir");
        Station s11 = Station(10, "Rajnagar");
        Station s12 = Station(11, "Sadhnagar");
        Station s13 = Station(12, "Syndicate Market");
        Station s14 = Station(13, "Gola Bazaar");
        Station s15 = Station(14, "Sadar Bazaar");
        Station s16 = Station(15, "Mangolpuri");
        Station s17 = Station(16, "Peeru Vihar");
        Station s18 = Station(17, "Vikas Enclave");
        Station s19 = Station(18, "Airport");
        Station s20 = Station(19, "Railway");

        // s1.v[0]= s1;
        // s2.v[1]= s2;
        // s3.v[2]= s3;
        // s4.v[3]= s4;
        // s5.v[4]= s5;
        // s6.v[5]= s6;
        // s7.v[6]= s7;
        // s8.v[7]= s8;
        // s9.v[8]= s9;
        // s10.v[9]= s10;
        // s11.v[10]= s11;
        // s12.v[11]= s12;
        // s13.v[12]= s13;
        // s14.v[13]= s14;
        // s15.v[14]= s15;
        // s16.v[15]= s16;
        // s17.v[16]= s17;
        // s18.v[17]= s18;
        // s19.v[18]= s19;
        // s20.v[19]= s20;

        stations[0]= s1;
        stations[1]= s2;
        stations[2]= s3;
        stations[3]= s4;
        stations[4]= s5;
        stations[5]= s6;
        stations[6]= s7;
        stations[7]= s8;
        stations[8]= s9;
        stations[9]= s10;
        stations[10]= s11;
        stations[11]= s12;
        stations[12]= s13;
        stations[13]= s14;
        stations[14]= s15;
        stations[15]= s16;
        stations[16]= s17;
        stations[17]= s18;
        stations[18]= s19;
        stations[19]= s20;
    }

public:
    StationGraph()
    {
        addStation();
        int n = stations.size();
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int r1 = rand() % 20;
                int r2 = rand() % 20;
                int r3 = rand() % 20;
                int r4 = rand() % 20;
                int r5 = rand() % 20;
                if (i % 3 == 0)
                {
                    if (j == r1 || j == r2 || j == r3 || j == r5 || j == r4)
                        continue;
                    addConnection(stations[i], stations[j], 20 + r4, 34 + r2, 12 + r3);
                }
                else if (i % 3 == 1)
                {
                    if (j == r1 || j == r5 || j == r4 || j==r2)
                        continue;
                    addConnection(stations[i], stations[j], 20 + r1, 34 + r5, 12 + r3);
                }
                else
                {
                    if (j == r5 || j == r4)
                        continue;
                    addConnection(stations[i], stations[j], 20 + r1, 34 + r2, 12 + r3);
                }
            }
        }
    }

    int minimumTime(int x, int y)
    {
        Station a = stations[x];
        Station b = stations[y];
        return dikjstraAlgo(a, b, 1);
    }

    int minimumFare(int x, int y)
    {
        Station a = stations[x];
        Station b = stations[y];
        return dikjstraAlgo(a, b, 0);
    }

    int minimumDist(int x, int y)
    {
        Station a = stations[x];
        Station b = stations[y];
        return dikjstraAlgo(a, b, 2);
    }

    void showStations()
    {
        cout << "Station ID" << "                " << "Station Name" << endl;
        for(auto x : stations)
        {
            cout << "  " << x.getId(x) << "           |             " << x.getName(x) << endl;
        }
        return;
    }
};