#include <bits/stdc++.h>

using namespace std;

class MinCut
{
    int numberOfVerticies, verticiesLeft, count, i, j, k, l, vertexV, vertexU, currentMincut, mincutAns;
    vector<vector<int>> mainGraph, initialGraph, currentGraph, graphAfterDeletion;
    vector<vector<int>> edges;

public:
    MinCut(vector<vector<int>> graph)
    {
        mincutAns = graph.size();
        mainGraph = graph;
        numberOfVerticies = graph.size();

        // test
        //  vertexU = 0;
        //  vertexV = 3;
    }
    void iterateMincut(int k)
    {
        while (k > 0)
        {
            verticiesLeft = numberOfVerticies;
            calculateMinCut();
            mincutAns = min(mincutAns, currentMincut);
            k--;
        }
    }
    void calculateMinCut()
    {
        initialGraph = mainGraph;
        graphAfterDeletion = mainGraph;
        while (verticiesLeft > 2)
        {
            initialGraph = graphAfterDeletion;
            for (i = 0; i < verticiesLeft; i++)
            {
                for (j = i + 1; j < verticiesLeft; j++)
                {
                    if (initialGraph[i][j])
                        edges.push_back({i, j});
                }
            }
            int indexOfEdge = rand() % edges.size();
            vertexU = edges[indexOfEdge][0];
            vertexV = edges[indexOfEdge][1];
            // cout<<vertexU << " " << vertexV << endl;

            vector<vector<int>> rough(verticiesLeft, vector<int>(verticiesLeft, 0));
            currentGraph = rough;
            vector<vector<int>> rough1(verticiesLeft - 1, vector<int>(verticiesLeft - 1, 0));
            graphAfterDeletion = rough1;

            contractEdge();
            verticiesLeft--;
            edges.clear();
        }
        currentMincut = graphAfterDeletion[0][1];
    }
    void contractEdge()
    {
        for (i = 0; i < verticiesLeft - 1; i++)
        {
            for (j = i + 1; j < verticiesLeft; j++)
            {
                count = 0;
                if (vertexU == i and vertexV == j)
                    currentGraph[i][j] = currentGraph[j][i] = 0;

                else if (vertexU == i or vertexV == i)
                {
                    count += initialGraph[vertexU][j];
                    count += initialGraph[vertexV][j];

                    currentGraph[vertexU][j] = currentGraph[vertexV][j] = count;
                }
                else if (vertexU == j or vertexV == j)
                {
                    count += initialGraph[vertexU][i];
                    count += initialGraph[vertexV][i];

                    currentGraph[i][vertexU] = currentGraph[i][vertexV] = count;
                }
                else
                {
                    currentGraph[i][j] = initialGraph[i][j];
                }
            }
        }
        for (i = 0; i < verticiesLeft; i++)
        {
            for (j = 0; j <= i; j++)
            {
                currentGraph[i][j] = currentGraph[j][i];
            }
        }
        copyGraph();
        // printGraph(initialGraph);
        // printGraph(currentGraph);
        // printGraph(graphAfterDeletion);
    }
    void copyGraph()
    {
        for (i = 0, k = 0; i < verticiesLeft; i++)
        {
            if (i == vertexV)
                continue;
            for (j = 0, l = 0; j < verticiesLeft; j++)
            {
                if (j == vertexV)
                    continue;
                graphAfterDeletion[k][l] = currentGraph[i][j];
                l++;
            }
            k++;
        }
    }
    void printGraph(vector<vector<int>> graph)
    {
        for (vector<int> row : graph)
        {
            for (int a : row)
                cout << a << " ";
            cout << endl;
        }
    }
    void printMincut()
    {
        cout << "The Mincut for given graph is: " << mincutAns << endl;
    }
};

int main()
{

    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}};
    MinCut minCut(graph);
    minCut.iterateMincut(100 * graph.size() * graph.size());
    minCut.printMincut();
    return 0;
}