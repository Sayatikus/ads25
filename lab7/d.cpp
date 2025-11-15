#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

bool compare(const pair<string, pair<string, double>>&a, const pair<string, pair<string, double>>&b){
    if(a.second.second != b.second.second){
        return a.second.second < b.second.second;
    }
  if (a.first != b.first) return a.first < b.first;
    return a.second.first < b.second.first;

    
}
int main(){
    int n;
    cin >> n;
    map<string, double> grade_map = {
    {"A+", 4.00}, {"A", 3.75},
    {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00},
    {"D+", 1.50}, {"D", 1.00},
    {"F", 0.00}
};
    vector<pair<string,pair<string,double>>>students_grade;
    for(int i = 0; i < n; i++){
        string first_name, last_name;
        int subject;
        cin >> last_name >> first_name >> subject;
        double total_points = 0;
        double total_credits = 0;

        for(int j = 0; j < subject; j++){
            int credit;
            string grade;
            cin >> grade >> credit;
            total_points += grade_map[grade] * credit;
            total_credits += credit;
        }       
        double GPA = total_points / total_credits;
        students_grade.push_back({last_name,{first_name, GPA}});

    }
    sort(students_grade.begin(),students_grade.end(), compare);

    for(int i = 0; i < students_grade.size(); i++){
        cout << students_grade[i].first << " " << students_grade[i].second.first << " ";
        cout << fixed << setprecision(3) << students_grade[i].second.second << endl;
    }
    return 0;
}