#include "StationsGraph.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    cout << "----------Welcome to Delhi Bus Service Application----------" << endl;
    cout << "Hello User, Hope you are good!" << endl;
    bool loop = false;
    StationGraph sg = StationGraph();
    while (true)
    {
        if (loop)
            break;
        cout << "How can we help you?" << endl;
        cout << "1. Show all buses." << endl;
        cout << "2. Minimum cost of travel between source and destination" << endl;
        cout << "3. Minimum time of travel between source and destination" << endl;
        cout << "4. Minimum distance of travel betwee source and destination" << endl;
        cout << "Press any other number to exit" << endl;
        cout << "Enter the code in the front of query to use the option." << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            sg.showStations();
            break;
        }

        case 2:
        {
            int src, dest;
            // string opt;
            // cout << "If you don't remember the ids of source or destination station.\nEnter Y\nElse N" << endl;
            // cin >> opt;
            // if (opt == "Y")
            //     sg.showStations();
            cout << "Enter source station id: " << endl;
            cin >> src;
            cout << "Enter destination station id: " << endl;
            cin >> dest;
            cout << sg.minimumFare(src, dest) << endl;
            break;
        }

        case 3:
        {
            int src, dest;
            // string opt;
            // cout << "If you don't remember the ids of source or destination station.\nEnter Y\nElse N" << endl;
            // cin >> opt;
            // if (opt == "Y")
            //     sg.showStations();
            cout << "Enter source station id: " << endl;
            cin >> src;
            cout << "Enter destination station id: " << endl;
            cin >> dest;
            cout << sg.minimumTime(src, dest) << endl;
            break;
        }

        case 4:
        {
            int src, dest;
            // string opt;
            // cout << "If you don't remember the ids of source or destination station.\nEnter Y\nElse N" << endl;
            // cin >> opt;
            // if (opt == "Y")
            //     sg.showStations();
            cout << "Enter source station id: " << endl;
            cin >> src;
            cout << "Enter destination station id: " << endl;
            cin >> dest;
            cout << sg.minimumDist(src, dest) << endl;
            break;
        }
        default:
        {
            cout << "Thank you" << endl;
            loop = true;
            break;
        }
        }
    }
    return 0;
}
