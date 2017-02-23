//
//  main.cpp
//  googlehashcode
//
//  Created by Tony Li on 23/2/2017.
//  Copyright © 2017 ZeptoMind Creative Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>

using namespace std;
struct request {
    int number;
    int v;
    int e;
};
struct latency {
    int data_center_latency;
    vector<pair<int, int>> e;
};

typedef long long ll;
const int MAX_C = 500000;
const int MAX_V = 1e4;
int dp[MAX_C];
int v, e, r, c, x;
int video_size[MAX_V]; //
vector<latency> latencys;
vector<request> requests;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cin >> v >> e >> r >> c >> x;
    int t;
    for (int i = 0; i < v; i++) {
        cin >> t;
        video_size[i] = t;
    }
    int ld, et, le;
    for (int i = 0; i < e; i++) {
        cin >> ld >> t;
        vector<pair<int, int>> lt;
        latency ee;
        for (int j = 0; j < t; j++) {
            cin >> et >> le;
            ee.e.push_back(make_pair(et, le));
        }
        ee.data_center_latency = ld;
        latencys.push_back(ee);
    }
    int vid, eid, tr;
    request rd;
    for (int i = 0; i < r; i++) {
        cin >> vid >> eid >> tr;
        rd.number = tr;
        rd.v = vid;
        rd.e = eid;
    }
    requests.push_back(rd);
    
    return 0;
}
