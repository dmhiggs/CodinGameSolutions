#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    long long speed;
    cin >> speed; cin.ignore();
    long long lightCount;
    cin >> lightCount; cin.ignore();

    long long lights[2][lightCount];
    long long totalDistance = 0;

    // duration = secs
    // distance = meters
    // speed = km / h :C

    // km / h to m / s --> * 1000/(60 * 60) --> this leads to some obnoxious flooring
    speed = speed * 1000; // m/h

    for (int i = 0; i < lightCount; i++) {
        int distance; //0
        int duration; //1
        cin >> distance >> duration; cin.ignore();

        totalDistance += (distance * 60 * 60); //to account for later conversion to seconds, total distance to that light
        lights[0][i] = (distance * 60 * 60); //to account for later conversion to seconds
        lights[1][i] = duration;
    }

    int j = 0;
    while (speed > 0 && j < lightCount) {
        // distance/speed % duration*2 > duration ---> 0<= result < duration is green, duration <= result < duration*2 is red
        // example, duration 10, hit light at 9s - green, hit light at 11s - red, hit light at 20 - green, hit light at 30 - red

        // or if turns green at "start" then check distance from start time, or just treat each start as 0
        if ((lights[0][j] / speed) >= lights[1][j] && ((lights[0][j] / speed ) % (lights[1][j] * 2) >= lights[1][j])) {
            j = -1;
            speed -= 1000; //decrement by 1km/h
        }
        j++;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    speed = speed / 1000;
    cout << speed << endl;
}