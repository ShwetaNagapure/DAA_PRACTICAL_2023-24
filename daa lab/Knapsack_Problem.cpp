#include<iostream>
using namespace std;

// Function to solve the knapsack problem
void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;
    // Initializing result vector
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    // Greedy approach to fill knapsack
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp += profit[i];
            u -= weight[i];
        }
    }
    
    if (i < n)
        x[i] = u / weight[i];
    tp += (x[i] * profit[i]);
    cout << "\nThe result vector is: ";
    for (i = 0; i < n; i++)
        cout << "\t" << x[i];
    
    cout << "\nMaximum profit is: " << tp;
}

int main() {
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;
    cout << "\nEnter the number of objects: ";
    cin >> num;

    cout << "\nEnter the weights and profit of each object: ";
    for (i = 0; i < num; i++) {
        cin >> weight[i] >> profit[i];
    }
    cout << "\nEnter the capacity of knapsack: ";
    cin >> capacity;

    // Calculating profit-to-weight ratio
    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }
    // Sorting objects based on profit-to-weight ratio in non-increasing order
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                // Swapping ratio, weight, and profit
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Solving knapsack problem
    knapsack(num, weight, profit, capacity);
    
    return 0;
}
//Output       
/* 
 Enter the number of objects:  7

 Enter the weights and profit of each object:  
2 10
3 5
5 15
7 7
1 6
4 18
1 3

 Enter the capacity of knapsack:  15

 The result vector is: 	1	1	1	1	1	0.666667	0
 Maximum profit is: 55.3333
*/