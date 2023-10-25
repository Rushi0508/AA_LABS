#include <bits/stdc++.h>

#define pointType pair<int, int>
#define pointWithSin pair<double, pointType>
using namespace std;

pointType basePoint;
static vector<pointWithSin> points;
class GrahamConvexHull
{
public:
    void findSin(pointWithSin &point)
    {
        if (point.second == basePoint)
            return;
        int y = point.second.second - basePoint.second;
        double d = sqrt(pow(point.second.first - basePoint.first, 2) + pow(y, 2));
        double sin = y / d;
        double value;
        if (point.second.first < basePoint.first)
            value = 2 - sin;
        else
            value = sin;
        point.first = value;
    }

    void generateSin()
    {
        for (pointWithSin &point : points)
        {
            findSin(point);
        }
    }

    void findBasePoint()
    {
        int minY = INT_MAX, minX = INT_MAX;
        for (pointWithSin point : points)
        {
            if (point.second.second < minY)
            {
                minY = point.second.second;
                minX = point.second.first;
            }
            else if (point.second.second == minY)
                minX = min(minX, point.second.first);
        }
        basePoint = {minX, minY};
    }

    GrahamConvexHull(vector<pointType> points1)
    {
        for (pointType point : points1)
        {
            points.push_back({-1.0, point});
        }
    }

    int direction(pointType p1, pointType p2, pointType p3)
    {
        return (p2.first - p1.first) * (p3.second - p1.second) -
               (p2.second - p1.second) * (p3.first - p1.first);
    }

    vector<pointWithSin> getConvexHull()
    {
        findBasePoint();
        generateSin();
        sort(points.begin(), points.end());
        vector<pointWithSin> convexHull;
        if (3 > points.size())
            return points;

        convexHull.push_back(points[0]);
        convexHull.push_back(points[1]);
        convexHull.push_back(points[2]);

        for (int i = 3; i < points.size(); i++)
        {
            while (convexHull.size() > 1)
            {
                pointWithSin p1 = convexHull[convexHull.size() - 2];
                pointWithSin p2 = convexHull[convexHull.size() - 1];
                if (direction(p1.second, p2.second, points[i].second) < 0)
                    convexHull.pop_back();
                else
                    break;
            }
            convexHull.push_back(points[i]);
        }
        return convexHull;
    }
};

int main()
{
    vector<pointType> pointsInput = {{1, 1}, {1, 3}, {3, 1}, {1, 2}, {2, 1}, {0, 0}, {0, 3}, {-1, 3}, {-1, 1}, {-3, 1}};
    GrahamConvexHull grahamHull(pointsInput);
    vector<pointWithSin> convexHull = grahamHull.getConvexHull();
    for (pointWithSin point : convexHull)
        cout << "(" << point.second.first << ", " << point.second.second << ")\n";
    return 0;
}