#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Vertex {
public:
    char v;
    list <Vertex*> v1;
    bool visited = false;

    Vertex(char v) {
        this -> v = v;
    }

    // connect v & v1
    void connect(Vertex* v) {
        this -> v1.push_back(v);
    }
};

class Top {
public:
    Vertex** vertices;
    list <Vertex*> v1;
    int n;

    Top(Vertex* vertices[], int n) {
        this -> vertices = vertices;
        this -> n = n;
    }

    list <Vertex*> label;

    void sort() {

        for (int i = 0; i < n; i++) {
            Vertex* vertex = vertices[i];
            if (!vertex -> visited) {
                //dfs sorting
                dfs(vertex);
            }
        }

        //print all the labels
        for (Vertex* vertex : label) {
            cout << vertex -> v << " ";
        }
    }

    //dfs
    void dfs(Vertex* vertex) {
        vertex -> visited = true;

        for (Vertex* v : vertex -> v1) {
            if (!v -> visited) {
                dfs(v);
            }
        }

        //print labelled vertices in order
        label.push_front(vertex);
    }

    //bfs
    void bfs(Vertex* vertex[], int predCount[]) {

        queue<int> q;
        int ret[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        int pointer = 0;
        for (int i = 0; i < n; i++) {
            if (predCount[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ret[pointer] = cur;

            for (Vertex* ver : vertex[pointer]->v1) {
                predCount[ver->v]--;
                cout << ver->v << " ";
                if (predCount[ver->v] == 0) {
                    q.push(ver->v);
                }
            }

            pointer++;

        }
    }

    bool cycleCatcher(int v, bool visited[], bool* stack) {
        
            visited[v] = true;
            stack[v] = true;

            for (int i = 0; i < n; ++i)
            {
                if (stack[i])
                    return true;
                else if (i == v)
                    return true;
                else if (!visited[i]) {
                    if (cycleCatcher(i, visited, stack))
                        return true;
                }
            }

        stack[v] = false;
        return false;
    }

    bool cycle() {
        bool* visited = new bool[n];
        bool* stack = new bool[n];

        for (int i = 0; i < n; i++)
        {
            if (cycleCatcher(i, visited, stack))
                return true;
        }
        return true;
    }
    
};

int main()
{
    //graph 1
    Vertex* vertices[] = { new Vertex('1'), new Vertex('2'), new Vertex('3'), new Vertex('4'), new Vertex('5'), new Vertex('6'), new Vertex('7'), new Vertex('8')};
    vertices[0]->connect(vertices[1]);
    vertices[0]->connect(vertices[4]);
    vertices[0]->connect(vertices[5]);
    vertices[1]->connect(vertices[2]);
    vertices[1]->connect(vertices[4]);
    vertices[1]->connect(vertices[6]);
    vertices[2]->connect(vertices[3]);
    vertices[3]->connect(vertices[4]);
    vertices[4]->connect(vertices[6]);
    vertices[4]->connect(vertices[7]);
    vertices[5]->connect(vertices[4]);
    vertices[5]->connect(vertices[7]);
    vertices[6]->connect(vertices[3]);
    vertices[6]->connect(vertices[7]);
    int predCount[8] = { 0, 1, 1, 2, 4, 1, 2, 3 };

    cout << "DFS topological sort of the first graph" << endl;
    Top top(vertices, 8);
    top.sort();
    cout << endl;

    if (!top.cycle())
        cout << "There is a cycle" << endl;
    else
        cout << "There is no cycle" << endl;

    cout << "BFS topological sort of the first graph" << endl;
    top.bfs(vertices, predCount);
    cout << endl;
    
    if (!top.cycle())
        cout << "There is a cycle";
    else
        cout << "There is no cycle";

    return 0;
}

