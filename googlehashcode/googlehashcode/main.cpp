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
const int MAX_SERVER = 1e4;
const int MAX_V = 1e4;
int dp[MAX_C+1][MAX_V];
int v, e, r, c, x;
int video_size[MAX_V]; //
vector<latency> latencys;
vector<request> requests;
vector<int> result[MAX_SERVER];


void solve(){
    for (int i = 0; i < latencys.size(); i++) {
        cout << latencys[i].data_center_latency << endl;
    }
    
}

int requestValue(int vid, int cid){
    return 0;
}

void fillCache(int cache_id){
    for (int i = 1 ; i < x + 1; i++){
        for (int j = 1; j < v + 1; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-video_size[j-1]][j-1] + requestValue(j-1, cache_id));
        }
    }
    
    // backtrace
    int t = dp[x][v];
    int i = x, j = v;
    while (t > 0 && i > 0 && j > 0) {
        if (t == dp[i-video_size[j-1]][j-1] - requestValue(j, cache_id)) {
            result[cache_id].push_back(j);
            i = i-video_size[j-1];
        }
        j--;
    }
}


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
        requests.push_back(rd);
    }
    solve();
    return 0;
}
