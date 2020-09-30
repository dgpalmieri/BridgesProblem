// bridge.cpp
// Dylan Palmieri
// 9/28/20
// Definition of bridge, CS411 Homework 2

// Lambda function details (lines XX and YY) inspired by Chris Hartman
// https://github.com/AKQuaternion/Fall2019CS411DemoCode/blob/master/CS411Fall19HW2/build.cpp

#include<algorithm> // for std::sort
#include<tuple>     // for std::forward_to_tuple
#include<numeric>   // for std::accumulate
#include<vector>
using std::vector;

#include<iostream>

using Bridge = vector<int>;

void printVector(const vector<int> & a){
    std::cout << "{ ";
    for (const auto & i: a){
        std::cout << i << " ";
    }
    std::cout << "}" << std::endl;
}

void printVector(const vector<bool> & a){
    std::cout << "{ ";
    for (const auto & i: a){
        std::cout << i << " ";
    }
    std::cout << "}" << std::endl;
}

void printBridges(const vector<Bridge> & bridges){
    std::cout << "{ " << std::endl;
    for (const auto & j: bridges){
        printVector(j);
    }
    std::cout << "}" << std::endl;
}

bool bridgeIsValid( const vector<Bridge> & bridge){
    for ( const auto & a: bridge ){
        for ( const auto & b: bridge ){
            if (a == b)
                continue;
            if ( ( a[ 0 ] < b[ 0 ] && a[ 1 ] < b[ 1 ] ) ||
                 ( a[ 0 ] > b[ 0 ] && a[ 1 ] > b[ 1 ] ) ) {
                return true;
            }
        }
    }
    return false;
}

vector<Bridge> subsetItem( const size_t & id, const vector<Bridge> & totalSet ){
    vector<Bridge> subset;
    vector<bool> bits;
    for ( size_t i = 0; i < totalSet.size(); ++i ){
        if (1 << i & id){
            bits.push_back( true );
        }
        else{
            bits.push_back( false );
        }
    }
/*
 *    std::cout << "Total Set:" << std::endl;
 *    printBridges(totalSet);
 *    std::cout << std::endl;
 *
 *    std::reverse( bits.begin(), bits.end() );
 *
 *    std::cout << "bits (reversed):" << std::endl;
 *    printVector(bits);
 *    std::cout << std::endl;
 */
    for ( size_t j = 0; j < bits.size(); ++j){
        if(bits[ j ]){
            subset.push_back(totalSet[ j ]); //TODO: segfault happens here: probably oob error
        }
    }

    /*
     *std::cout << "subset:" << std::endl;
     *printBridges(subset);
     *std::cout << std::endl;
     *std::cout << std::endl;
     */


    return subset;
}

int calculateToll(const vector<Bridge> & a){
    return std::accumulate(a.begin(), a.end(), 0 ,
           []( int & sum, const Bridge & bridge ){ return sum + bridge[ 2 ]; });
}

int bridgeCount( const vector<Bridge> & bridges ){
    vector<Bridge> subset;
    int greatestToll = 0;
    for( size_t subsetID = 0; subsetID < 1u<<bridges.size(); ++subsetID ){
        std::cout << "Here!" << std::endl;
        subset = subsetItem( subsetID, bridges );
        if ( subset.empty() ){ continue; }
        int temp = calculateToll( subset );
        std::cout << "f&b: " << int(subset.front() == subset.back()) << std::endl;
        std::cout << "valid: " << int(bridgeIsValid( subset )) << std::endl;
        std::cout << "empty: " << subset.empty() << std::endl;
        if ( ( subset.front() != subset.back() && bridgeIsValid( subset ) ) ||
             ( !subset.empty() && subset.front() == subset.back() ) ){
            if (greatestToll < temp ){
                greatestToll = temp;
            }
        }
    } 
    return greatestToll;
}

int build( int w, int e, const vector<Bridge> & bridges ){
    if ( bridges.empty() ) {
        return 0;
    }

    vector<Bridge> sortedBridges(bridges);

    std::sort( sortedBridges.begin(), sortedBridges.end(), 
           [](const auto & a, const auto & b) {
              return std::forward_as_tuple(a[ 0 ], a[ 1 ], a[ 2 ]) <
                     std::forward_as_tuple(b[ 0 ], b[ 1 ], b[ 2 ]);
                     });
    return bridgeCount( bridges );
}
