#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<string, string>>nn;
    for(int i = 0; i < n; i++){
        string old_name, new_name;
        cin >> old_name >> new_name;
        if(nn.empty()){
            nn.push_back(make_pair(old_name, new_name));
        }
        else{
            bool check = false;
            for(int i = 0; i < nn.size(); i++){
                if(nn[i].second == old_name){
                    nn[i].second = new_name;
                    check = true;
                    break;
                }
            }
            if(!check){
                nn.push_back(make_pair(old_name, new_name));
            }
        }
    }
    map<string,string>names (nn.begin(), nn.end());
    cout << names.size() << endl;
    for(map<string, string>::iterator it = names.begin(); it != names.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}