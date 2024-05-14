#include <iostream>
using namespace std;

#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

// Function to find the shortest path from source to destination vertex
void findPath(int s, int v);

// Function to implement Dijkstra's algorithm
void Dijkstra(int s);

// Function to find the temporary vertex with minimum path length
int min_temp();

// Function to create a graph
void create_graph();

int n; // Number of vertices in the graph
int adj[MAX][MAX]; // Adjacency matrix to represent the graph
int pred[MAX]; // Array to store predecessor vertices
int pathlength[MAX]; // Array to store path lengths from source to all vertices
int status[MAX]; // Array to store status of vertices (temporary or permanent)

int main() {
    int s, v;

    // Creating a graph
    create_graph();

    // Prompting user to enter the source vertex
    cout << "Enter the source vertex: ";
    cin >> s;

    // Implementing Dijkstra's algorithm
    Dijkstra(s);

    // Loop to find shortest paths from source to all other vertices
    while (1) {
        // Prompting user to enter the destination vertex
        cout << "Enter destination vertex (-1 to quit): ";
        cin >> v;

        // Checking if the user wants to quit
        if (v == -1)
            break;

        // Checking if the destination vertex is valid
        if (v < 0 || v >= n)
            cout << "This vertex does not exist\n";
        else if (v == s)
            cout << "Source and destination vertices are the same\n";
        else if (pathlength[v] == infinity)
            cout << "There is no path from source to destination vertex\n";
        else
            // Finding the shortest path from source to destination vertex
            findPath(s, v);
    }

    return 0;
}

// Function to implement Dijkstra's algorithm
void Dijkstra(int s) {
    int i, current;

    // Initializing all vertices as temporary with infinite path lengths
    for (i = 0; i < n; i++) {
        pred[i] = NIL;
        pathlength[i] = infinity;
        status[i] = TEMP;
    }

    // Setting the path length of the source vertex to 0
    pathlength[s] = 0;

    // Loop to find the shortest path lengths from source to all vertices
    while (1) {
        // Finding the temporary vertex with minimum path length
        current = min_temp();

        // Breaking the loop if all vertices have been processed
        if (current == NIL)
            return;

        // Marking the current vertex as permanent
        status[current] = PERM;

        // Updating path lengths of adjacent temporary vertices
        for (i = 0; i < n; i++) {
            if ((adj[current][i]!= 0) && (status[i] == TEMP)) {
                if (pathlength[current] + adj[current][i] < pathlength[i]) {
                    pred[i] = current; // Relabeling the predecessor vertex
                    pathlength[i] = pathlength[current] + adj[current][i];
                }
            }
        }
    }
}

// Function to find the temporary vertex with minimum path length
int min_temp() {
    int i;
    int min = infinity;
    int k = NIL;

    // Finding the temporary vertex with minimum path length
    for (i = 0; i < n; i++) {
        if (status[i] == TEMP && pathlength[i] < min) {
            min = pathlength[i];
            k = i;
        }
    }

    return k;
}

// Function to find the shortest path from source to destination vertex
void findPath(int s, int v) {
    int i, u;
    int path[MAX]; // Array to store the shortest path
    int shortDist = 0; // Length of the shortest path
    int count = 0; // Number of vertices in the shortest path

    // Storing the full path in the array path
    while (v!= s) {
        count++;
        path[count] = v;
        u = pred[v];
        shortDist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;

    // Displaying the shortest path
    cout << "Shortest path is: ";
    for (i = count; i >= 1; i--)
        cout << path[i] << " ";
    cout << "\nThe shortest distance is: " << shortDist << endl;
}

// Function to create a graph
void create_graph() {
    int i, max_edges, origin, destin, wt;
    cout << "Enter the number of vertices: ";
    cin >> n;

    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        cout << "Enter edge " << i << " (enter -1 -1 to finish): ";
        cin >> origin >> destin;

        if (origin == -1 && destin == -1)
            break;

        cout << "Enter weight of this edge: ";
        cin >> wt;

        if (origin > n || destin > n || origin < 0 || destin < 0) {
            cout << "Invalid edge! Please enter again." << endl;
            i--;
        } else
            adj[origin][destin] = wt;
    }
}
//Output
/* 
Enter the number of vertices: 3
Enter edge 1 (enter -1 -1 to finish): 0 0
Enter weight of this edge: 5
Enter edge 2 (enter -1 -1 to finish): 0 1
Enter weight of this edge: 2
Enter edge 3 (enter -1 -1 to finish): 0 2
Enter weight of this edge: 7
Enter edge 4 (enter -1 -1 to finish): 1 1
Enter weight of this edge: 8
Enter edge 5 (enter -1 -1 to finish): 1 2
Enter weight of this edge: 3
Enter edge 6 (enter -1 -1 to finish): 2 0
Enter weight of this edge: 9
Enter the source vertex: 0
Enter destination vertex (-1 to quit): 2
Shortest path is: 0 1 2 
The shortest distance is: 5
Enter destination vertex (-1 to quit): 1
Shortest path is: 0 1 
The shortest distance is: 2
Enter destination vertex (-1 to quit): -1
*/