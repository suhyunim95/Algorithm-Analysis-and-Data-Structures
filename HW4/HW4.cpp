#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> vertex[10];
bool dfsVisit[10];
bool bfsVisit[10];

// Create an edge of digraph
void edge(vector <int> vertex[], int u, int v)
{
    vertex[u].push_back(v);
}

// Representation of graph
void printer(vector <int> vertex[])
{
    for (int v = 0; v < 10; v++)
    {
        cout << v ;
        for (int i : vertex[v])
            cout << "->" << i ;
        cout << endl;
    }
}

// DFS traversal
void dfs(int v) 
{
    //initialize 
    dfsVisit[v] = true;
    cout << v << " ";

    for (int i = 0; i < vertex[v].size(); i++) 
    {
        if (dfsVisit[vertex[v][i]] == false)
            dfs(vertex[v][i]);
    }
}

// BFS traversal
void bfs(int v) 
{
    queue <int> q;

    //initialize 
    bfsVisit[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (int i = 0; i < vertex[v].size(); i++)
        {
            if (!bfsVisit[vertex[v][i]])
            {
                q.push(vertex[v][i]);
                bfsVisit[vertex[v][i]] = true;
            }
        }
    }
}

// main function
int main()
{
    cout << "<Adjcency list of digraph>" << endl;
    edge(vertex, 0, 3);
    edge(vertex, 0, 5);
    edge(vertex, 0, 6);
    edge(vertex, 1, 2);
    edge(vertex, 1, 4);
    edge(vertex, 1, 8);
    edge(vertex, 2, 6);
    edge(vertex, 2, 8);
    edge(vertex, 3, 6);
    edge(vertex, 3, 7);
    edge(vertex, 3, 9);
    edge(vertex, 4, 0);
    edge(vertex, 4, 5);
    edge(vertex, 4, 8);
    edge(vertex, 5, 1);
    edge(vertex, 6, 7);
    edge(vertex, 6, 8);
    edge(vertex, 8, 5);
    edge(vertex, 9, 7);
    edge(vertex, 9, 8);
    printer(vertex);
    cout << endl;

    cout << "<DFS traversal of graph>" << endl;
    for (int i = 0; i < 10; i++) 
    {
        if (dfsVisit[i] == false)
        {
            dfs(i);
        }
    }
    cout << endl << endl;

    cout << "<BFS traversal of digraph visiting from vertex 0>" << endl;
    bfs(0);
    cout << endl;
    
    return 0;
}