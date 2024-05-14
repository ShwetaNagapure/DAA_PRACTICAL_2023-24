#include<iostream>
#include<stdlib.h> // Include this header for using exit()

using namespace std;

#define MAX 100
#define initial 1
#define visited 2

int n; // Number of vertices in the graph
int adj[MAX][MAX]; // Adjacency matrix to represent the graph
int state[MAX]; // Array to store state of vertices (temporary or permanent)
void DF_traversal();
void DFS(int v);
void create_graph();
int stack[MAX]; // Stack to store vertices
int top = -1; // Top index of the stack

void push(int v); // Function to push a vertex into the stack
int pop(); // Function to pop a vertex from the stack
int isEmpty_stack(); // Function to check if the stack is empty

int main() {
    create_graph(); // Creating a graph
    DF_traversal(); // Performing Depth First Search
    return 0; // This is where the main function should end
}

void DF_traversal() {
    int v;
    for(v = 0; v < n; v++)
        state[v] = initial; // Initializing all vertices as temporary
    cout << "Enter starting node for Depth first search: ";
    cin >> v;
    DFS(v); // Performing Depth First Search starting from the entered vertex
}

void DFS(int v) {
    int i;
    push(v); // Pushing the entered vertex into the stack
    while(!isEmpty_stack()) {
        v = pop(); // Popping a vertex from the stack
        if (state[v] == initial) {
            cout << v << " "; // Printing the visited vertex
            state[v] = visited; // Marking the vertex as visited
        }
        for(i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && state[i] == initial)
                push(i); // Pushing the adjacent vertex into the stack if it is not visited
        }
    }
}

void push(int v) {
    if (top == (MAX - 1)) {
        cout << "\nStack overflow";
        return;
    }
    top = top + 1;
    stack[top] = v;
}

int pop() {
    int v;
    if (top == -1) {
        cout << "\nStack underflow";
        exit(1); // Exiting the program if underflow occurs
    }
    else {
        v = stack[top];
        top = top - 1;
        return v;
    }
}

int isEmpty_stack() { 
    if (top == -1)
        return 1; // Returning 1 if the stack is empty
    else
        return 0;
}

void create_graph() {
    int i, max_edges, origin, destin; 
    cout << "Enter the number of nodes: "; 
    cin >> n;
    max_edges = n * (n - 1); // Calculating maximum possible edges
    for(i = 0; i < max_edges; i++) {
        cout << "Enter the edge " << i << " (or -1 -1 to stop): ";
        cin >> origin >> destin;
        if((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            cout << "Invalid edge!\n";
            i--; // Decrementing i to re-enter edge
        }
        else {
            adj[origin][destin] = 1; // Marking the edge
        }
    }
}

/*
Enter the number of nodes: 10
Enter the edge 0 (or -1 -1 to stop): 0 1
Enter the edge 1 (or -1 -1 to stop): 0 3
Enter the edge 2 (or -1 -1 to stop): 1 2
Enter the edge 3 (or -1 -1 to stop): 2 3
Enter the edge 4 (or -1 -1 to stop): 1 5
Enter the edge 5 (or -1 -1 to stop): 2 5
Enter the edge 6 (or -1 -1 to stop): 3 6
Enter the edge 7 (or -1 -1 to stop): 1 4
Enter the edge 8 (or -1 -1 to stop): 5 6
Enter the edge 9 (or -1 -1 to stop): 4 7
Enter the edge 10 (or -1 -1 to stop): 5 8
Enter the edge 11 (or -1 -1 to stop): 5 7
Enter the edge 12 (or -1 -1 to stop): 7 8
Enter the edge 13 (or -1 -1 to stop): 8 9
Enter the edge 14 (or -1 -1 to stop): 6 9
Enter the edge 15 (or -1 -1 to stop): -1 -1
Enter starting node for Depth first search: 0
0 1 2 3 6 9 5 7 8 4 

*/