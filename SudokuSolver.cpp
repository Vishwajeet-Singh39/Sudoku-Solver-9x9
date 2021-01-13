#include<iostream>
using namespace std;
void display(int a[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int a[9][9]={0};
    cout<<"Enter the Sudoku Grid to be solved"<<endl
    <<"Note: Enter '0' in place of empty space"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>a[i][j];
        }
    }
    display(a);
}