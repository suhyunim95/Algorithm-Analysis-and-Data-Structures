#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Vertex {
public:
    char v;
    list <Vertex*> v1;
    bool visited = false;

    Vertex(char v) {
        this->v = v;
    }

    // connect v & v1
    void connect(Vertex* v) {
        this->v1.push_back(v);
    }
};

class Top {
public:
    Vertex** vertices;
    list <Vertex*> v1;
    int n;

    Top(Vertex* vertices[], int n) {
        this->vertices = vertices;
        this->n = n;
    }

    list <Vertex*> label;

    void sort() {

        for (int i = 0; i < n; i++) {
            Vertex* vertex = vertices[i];
            if (!vertex->visited) {
                //dfs sorting
                dfs(vertex);
            }
        }

        //print all the labels
        for (Vertex* vertex : label) {
            cout << vertex->v << " ";
        }
    }

    //dfs
    void dfs(Vertex* vertex) {
        vertex->visited = true;

        for (Vertex* v : vertex->v1) {
            if (!v->visited) {
                dfs(v);
            }
        }

        //print labelled vertices in order
        label.push_front(vertex);
    }


    //bfs
    void bfs(Vertex* vertex[], int predCount[]) {

        queue<int> q;
        int ret[14] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
    //graph 2
    Vertex* vertices[] = { new Vertex('m'), new Vertex('n'), new Vertex('o'), new Vertex('p'), new Vertex('q'), new Vertex('r'), new Vertex('s'), new Vertex('t'), new Vertex('u'), new Vertex('v'), new Vertex('w'), new Vertex('x'), new Vertex('y'), new Vertex('z') };
    vertices[0]->connect(vertices[4]); // m -> q 
    vertices[0]->connect(vertices[5]); // m -> r 
    vertices[0]->connect(vertices[11]); // m -> x 
    vertices[1]->connect(vertices[2]); // n -> o 
    vertices[1]->connect(vertices[4]); // n -> q
    vertices[1]->connect(vertices[8]); // n -> u
    vertices[2]->connect(vertices[5]); // o -> r
    vertices[2]->connect(vertices[6]); // o -> s 
    vertices[2]->connect(vertices[9]); // o -> v
    vertices[3]->connect(vertices[2]); // p -> o
    vertices[3]->connect(vertices[6]); // p -> s
    vertices[3]->connect(vertices[13]); // p -> z
    vertices[4]->connect(vertices[7]); // q -> t
    vertices[5]->connect(vertices[8]); // r -> u
    vertices[5]->connect(vertices[12]); // r -> y
    vertices[6]->connect(vertices[5]); // s -> r
    vertices[8]->connect(vertices[7]); // u -> t
    vertices[9]->connect(vertices[10]); // v -> w
    vertices[9]->connect(vertices[11]); // v -> x
    vertices[10]->connect(vertices[13]); // w -> z
    vertices[12]->connect(vertices[9]); // y -> v
    int predCount[14] = { 0, 0, 2, 0, 2, 3, 2, 2, 2, 2, 1, 2, 1, 2 };

    cout << "DFS topological sort of the second graph" << endl;
    Top top(vertices, 14);
    top.sort();
    cout << endl;

    if (top.cycle())
        cout << "There is a cycle" << endl;
    else
        cout << "There is no cycle" << endl;

    cout << "BFS topological sort of the second graph" << endl;
    top.bfs(vertices, predCount);
    cout << endl;

    if (top.cycle())
        cout << "There is a cycle" << endl;
    else
        cout << "There is no cycle" << endl;

    return 0;
}


