#include<iostream>
using namespace std;

int main(){
  int a[2][2], b[2][2], c[2][2], i,j;
  int m1,m2,m3,m4,m5,m6,m7;
  // Prompting user to enter the four elements of a matrix
  cout<<"Enter the four elements of a matrix :"<<endl;

  for(i=0 ; i<2 ; i++){
    for(j=0;j<2;j++){
        cin>>a[i][j];
    }
  }
  // Prompting user to enter the four elements of b matrix
  cout<<"Enter the four elements of b matrix :"<<endl;

  for(i=0 ; i<2 ; i++){
    for(j=0;j<2;j++){
        cin>>b[i][j];
    }
  }
  // Displaying the a matrix
  cout<<"The a matrix is :"<<endl;
    for(i=0 ; i<2 ; i++){
        cout<<endl;
    for(j=0;j<2;j++){
        cout<<a[i][j]<<" ";
    }
  }
  cout<<endl;
  // Displaying the b matrix
  cout<<"The b matrix is :"<<endl;
  for(i=0 ; i<2 ; i++){
        cout<<endl;
    for(j=0;j<2;j++){
        cout<<b[i][j]<<" ";
    }
  }
  cout<<endl;
  // Calculating the values of m1, m2, m3, m4, m5, m6, m7 using the formulae
  m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  m2 = (a[1][0] + a[1][1]) * b[0][0];
  m3 = a[0][0] * (b[0][1] - b[1][1]);
  m4 = a[1][1] * (b[1][0] - b[0][0]);
  m5 = (a[0][0] + a[0][1]) * b[1][1];
  m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
  m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

  // Calculating the values of c[0][0], c[0][1], c[1][0], c[1][1] using the formulae
  c[0][0] = m1 + m4 - m5 + m7;
  c[0][1] = m3 + m5;
  c[1][0] = m2 + m4;
  c[1][1] = m1 - m2 + m3 + m6;

  // Displaying the result after multiplication using Strassen's Algorithm
  cout<<"After multiplication using Strassen's Algorithm\n";
  for(i =0 ; i<2 ; i++){
    cout<<endl;
    for(j=0; j<2 ; j++){
        cout<<c[i][j]<<" ";
    }
  }
return 0;
}
//Output
/* 
Enter the four elements of a matrix :
11 21 9 7
Enter the four elements of b matrix :
8 13 27 24
The a matrix is :

11 21 
9 7 
The b matrix is :

8 13 
27 24 
After multiplication using Strassen's Algorithm

655 647 
261 285 
*/