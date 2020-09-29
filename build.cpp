// bridge.cpp
// Dylan Palmieri
// 9/28/20
// Definition of bridge, CS411 Homework 2

#include<vector>
using std::vector;

using Bridge = vector<int>;

int bridgeCount(const vector<Bridge> & bridges){
    int score = 0;
    for (const auto & i: bridges){
        if (i[2] > score){
            score = i[2];
        }
    } 
    return score;
}

int build(int w, int e, const vector<Bridge> & bridges){
    if (bridges.empty()) {
        return 0;
    }

    int score = 0;
    score = bridgeCount(bridges);

    return score;
}
