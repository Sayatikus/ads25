#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

bool compare( const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    if(a.second.first != b.second.first){
        return a.second.first < b.second.first;
    }
    return a.second.second < b.second.second;


}

int main(){
    int n;
    cin >> n;
    
    vector<pair<int,pair<int,int>>>dates;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int day = stoi(s.substr(0, 2));
        int month = stoi(s.substr(3, 2));
        int year = stoi(s.substr(6, 4));

        dates.push_back({year, {month, day}});
        
    }
     sort(dates.begin(), dates.end(), compare);

     for(int i = 0; i < dates.size(); i++){
        int year = dates[i].first;
        int month = dates[i].second.first;
        int day = dates[i].second.second;

        cout << setw(2) << setfill('0') << day << "-"
             << setw(2) << setfill('0') << month << "-"
             << year << endl;
     }
    return 0;
}