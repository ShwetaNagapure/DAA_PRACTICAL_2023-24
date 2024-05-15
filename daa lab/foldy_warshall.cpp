#include<iostream>
using namespace std;

// Define the maximum number of vertices and the value for infinity
#define max 100
#define infi 99999

// Declare global variables
int n; // Number of vertices
int adj[max][max]; // Adjacency matrix
int D[max][max]; // Shortest path matrix
int pre[max][max]; // Predecessor matrix

// Function to create the graph
void createg() {
    int i, max_edges, o, d, wt;

    // Prompt the user to enter the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Calculate the maximum number of edges
    max_edges = n * (n - 1);

    // Loop through each edge
    for (i = 1; i <= max_edges; i++) {
        // Prompt the user to enter the edge
        cout << "Enter the edge (-1 -1 to quit) " << i << ":";
        cin >> o >> d;

        // Check if the user wants to quit
        if ((o == -1) && (d == -1))
            break;

        // Check if the edge is valid
        if (o >= n || d >= n || o < 0 || d < 0) {
            cout << "Invalid edge\n";
            i--;
        } else {
            // Prompt the user to enter the weight for this edge
            cout << "Enter the weight for this edge :";
            cin >> wt;

            // Store the weight in the adjacency matrix
            adj[o][d] = wt;
        }
    }
}

// Function to implement the Floyd-Warshall algorithm
void warshall() {
    int i, j, k;

    // Initialize the shortest path matrix and predecessor matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 0) {
                D[i][j] = infi;
                pre[i][j] = -1;
            } else {
                D[i][j] = adj[i][j];
                pre[i][j] = i;
            }
        }

    // Loop through each vertex
    for (k = 0; k < n; k++) {
        // Loop through each pair of vertices
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                // Check if the path through vertex k is shorter
                if (D[i][k] + D[k][j] < D[i][j]) {
                    // Update the shortest path matrix and predecessor matrix
                    D[i][j] = D[i][k] + D[k][j];
                    pre[i][j] = pre[k][j];
                }
    }

    // Display the shortest path matrix and predecessor matrix
    cout << "Shortest path matrix is :\n";
    display(D, n);
    cout << "Predecessor matrix is :\n";
    display(pre, n);
}

// Function to find the shortest path between two vertices
void find_path(int s, int d) {
    int i;
    int path[max];

    int count;

    // Check if there is no path between the two vertices
    if (D[s][d] == infi) {
        cout << "No path";
        return;
    }

    // Construct the path
    count = -1;
    do {
        path[++count] = d;
        d = pre[s][d];
    } while (d!= s);
    path[++count] = s;

    // Display the path
    for (i = count; i >= 0; i--)
        cout << path[i] << " ";
    cout << "\n";
}

// Function to display a matrix
void display(int mat[max][max], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";

        cout << "\n";
    }
}

int main() {
    int s, d;

    // Create the graph
    createg();

    // Implement the Floyd-Warshall algorithm
    warshall();

    // Loop until the user wants to exit
    while (1) {
        // Prompt the user to enter the source vertex
        cout << "Enter the source(-1) to exit: ";
        cin >> s;

        // Check if the user wants to exit
        if (s == -1)
            break;

        // Prompt the user to enter the destination vertex
        cout << "Enter the destinaton vertex: ";
        cin >> d;

        // Check if the vertices are valid
        if (s >= n || d >= n || s < 0 || d < 0) {
            cout << "Invalid vertices\n";
            continue;
        }

        // Find the shortest path between the two vertices
        find_path(s, d);
    }

    return 0;
}
/* output
Enter the number of vertices: 4
Enter the edge (-1 -1 to quit) 1:0 1
Enter the edge (-1 -1 to quit) 2:1 2
Enter the edge (-1 -1 to quit) 3:2 3
Enter the edge (-1 -1 to quit) 4:3 4
Enter the edge (-1 -1 to quit) -1 -1
Shortest path matrix is :
0 1 2 3 
1 0 1 2 
2 1 0 1 
3 2 1 0 
Predecessor matrix is :
-1 0 1 2 
0 -1 1 2 
0 1 -1 2 
0 1 2 -1 
Enter the source(-1) to exit: 0
Enter the destinaton vertex: 3
0 1 2 
Enter the source(-1) to exit: -1
*/