#include<bits/stdc++.h>
#include<iostream>

using namespace std;

vector<int> mvc;

int main(){
    int graph[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    bool arr[4];
    int edge_count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(graph[i][j]){
                edge_count++;
            }
        }
        arr[i] = false;
    }
    edge_count /= 2;
    int i = 0;
    while(edge_count){
        int flag = 0;
        int first = 0;
        for(int j = i; j < 4; j++){
            if(graph[i][j]){
                if(!first){
                    for(int k = j + 1; k < 4; k++){
                        if(graph[j][k]){
                            graph[j][k] = 0;
                            graph[k][j] = 0;
                            edge_count--;
                        }
                    }
                    if(arr[j] == false){
                        mvc.push_back(j + 1);
                        arr[j] = true;
                    }
                    first = 1;
                }
                flag = 1;
                graph[i][j] = 0;
                graph[j][i] = 0;
                edge_count--;
            }
        }
        if(flag){
            if(arr[i] == false){
                mvc.push_back(i + 1);
                arr[i] = true;
            }
        }
        i++;
    }
    cout << "Minimum Vertex Cover is : { " << mvc[0];
    for(int i = 1; i < mvc.size(); i++){
        cout  << " ," << mvc[i];
    }
    cout << " }" << endl;
    return 0 ;
}