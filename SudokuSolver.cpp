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
int PresentInRow(int a[9][9],int x,int n){
  for(int y=0;y<9;y++){
    if(a[x][y]==n){
      return 1;
    }
  }
  return 0;
}
int PresentInyumn(int a[9][9],int y,int n){
  for(int x=0;x<9;x++){
    if(a[x][y]==n){
      return 1;
    }
  }
  return 0;
}
int PresentInSubGrid(int a[9][9],int x,int y,int n){
  int SubGridx=x-x%3;
  int SubGridy=y-y%3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(a[SubGridx+i][SubGridy+j]==n){
        return 1;
      }
    }
  }
  return 0;
}
int check(int a[9][9],int x,int y,int n){
  return !PresentInRow(a,x,n) && !PresentInyumn(a,y,n) && !PresentInSubGrid(a,x,y,n);
}
int findLocation(int a[9][9],int &x,int &y){
  for(x=0;x<9;x++){
    for(y=0;y<9;y++){
      if(a[x][y]==0){
        return 1;
      }
    }
  }
  return 0;
}
int Status(int a[9][9]){
  int x,y;
  if(!findLocation(a, x, y)){
    return 1;
  }
  for(int n=1;n<=9;n++){
    if(check(a,x,y,n)){
      a[x][y]=n;
      if(Status(a)){
        return 1;
      }
      a[x][y]=0;
    }
  }
  return 0;
}
int main(){
  int a[9][9];
  cout<<"Enter the Sudoku Grid to be solved"<<endl
  <<"Note: Enter '0' in place of empty space"<<endl;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
     cin>>a[i][j];
    }
  }
  if(Status(a)==1){
    cout<<endl<<endl<<"Solution: "<<endl<<endl;
    display(a);
  }
  else{
    cout <<"Not Solvable"<<endl;
  }
  return 0;
}