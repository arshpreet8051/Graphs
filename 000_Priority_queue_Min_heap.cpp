#include<iostream>
#include<vector>
#include<priority_queue>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
int main()
{
    // The functionality of the below queue can be understood from the below function
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

    return 0;
}

struct comapre{
    bool operator() (const prority_queue<pair<pair<int,int>,int>>q1, const priority_queue<pair<pair<int,int>,int>>q2){
    return q1.second > q2.second;
    }
}