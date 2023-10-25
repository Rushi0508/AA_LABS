#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x;
    int y;
};

int Direction(struct Point p1, struct Point p2, struct Point p3){
    return ((p3.x - p1.x)*(p2.y - p1.y) - (p3.y - p1.y)*(p2.x - p1.x));
}

bool OnSegment(struct Point p1, struct Point p2, struct Point p3){
    if((min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x)) && (min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y))){
        return 1;
    }
    else{
        return 0;
    }
}

bool Check_Intersection(struct Point p1, struct Point p2, struct Point p3, struct Point p4){
    int d1, d2, d3, d4;
    d1 = Direction(p1, p2, p3);
    d2 = Direction(p1, p2, p4);
    d3 = Direction(p3, p4, p1);
    d4 = Direction(p3, p4, p2);
    if((d1*d2 < 0) && (d3*d4 < 0)){
        return 1;
    }
    else if((d1 == 0) && OnSegment(p1, p2, p3)){
        return 1;
    }
    else if((d2 == 0) && OnSegment(p1, p2, p4)){
        return 1;
    }
    else if((d3 == 0) && OnSegment(p3, p4, p1)){
        return 1;
    }
    else if((d4 == 0) && OnSegment(p3, p4, p2)){
        return 1;
    }
    return 0;
}

int main(){
    struct Point p1, p2, p3, p4;
    cout << "Enter the Coordinates of Two Points of Line 1 : " << endl;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cout << "Enter the Coordinates of Two Points of Line 2 : " << endl;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;
    if(Check_Intersection(p1, p2, p3, p4)){
        cout << "Two Lines are Intersecting" << endl;
    }
    else{
        cout << "Two Lines are not Intersecting" << endl;
    }
    return 0;
}