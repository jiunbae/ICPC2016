//
//  bitpartite_matching.h
//  0903
//
//  Created by IRIS on 9/3/15.
//

#pragma once

#ifndef _903_bitpartite_matching_h
#define _903_bitpartite_matching_h
#endif

vector<vector<int> > v;
int backMatch[max_N*max_N];
int column_cnt[max_N*max_N];
bool visited[max_N*max_N];
 
bool dfs(int now) {
    if (visited[now]) return false;
    visited[now] = true;
        
    for (auto next: v[now]) {
        if (backMatch[next] == -1 || dfs(backMatch[next])) {
            backMatch[next] = now;
            return true;
        }
    }
    return false;
}
int BitpartiteMatching() {
    memset(backMatch, -1, sizeof(backMatch));
         
    int matched = 0;
    for (size_t i=0; i<v.size(); i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) matched++;
    }
    return matched;
}
