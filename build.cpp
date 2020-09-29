// bridge.cpp
// Dylan Palmieri
// 9/28/20
// Definition of bridge, CS411 Homework 2

#include<algorithm>
#include<tuple>
#include<vector>
using std::vector;

using Bridge = vector<int>;

bool bridgeIsValid( const vector<Bridge> & a, const Bridge & b ){
    return true;
}

int bridgeCount( const vector<Bridge> & bridges ){
    int totalScore = 0;
    vector<Bridge> scored_bridges = {};
    for ( const auto & i: bridges ){
        if (bridgeIsValid( scored_bridges, i ) && i[2] > totalScore){
            totalScore += i[2];
            scored_bridges.push_back(i);
        }
    } 
    return totalScore;
}

// Sorting function implementation details inspired by Chris Hartman
// https://github.com/AKQuaternion/Fall2019CS411DemoCode/blob/master/CS411Fall19HW2/build.cpp
int build( int w, int e, const vector<Bridge> & bridges ){
    if ( bridges.empty() ) {
        return 0;
    }

    vector<Bridge> sortedBridges(bridges);

    std::sort( sortedBridges.begin(), sortedBridges.end(), 
           [](const auto & a, const auto & b) {
              return std::forward_as_tuple(a[0], a[1], a[2]) <
                     std::forward_as_tuple(b[0], b[1], b[2]);
                     });
    return bridgeCount( bridges );
}
