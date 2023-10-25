#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct Point{
    double x;
    double y;
};

int main(){
    int n;
    cout << "Enter No of Points : " << endl;
    cin >> n;
    struct Point arr[n];
    cout << "Enter the (x, y) coordinates : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    double min = INT32_MAX;
    vector<vector<double>> pair;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            double curr_dis = sqrt(pow((arr[i].x - arr[j].x), 2) +  pow((arr[i].y - arr[j].y), 2));
            if(curr_dis < min){
                min = curr_dis;
                pair = {{arr[i].x, arr[i].y}, {arr[j].x, arr[j].y}};
            }
        }
    }
    cout << "Closest Pair of Points are : " << "(" <<  pair[0][0] << "," << pair[0][1] << ")  " <<  "(" <<  pair[1][0] << "," << pair[1][1] << ")" << endl;
    cout << "Closest Distance is : " << min << endl;
    return 0;
}