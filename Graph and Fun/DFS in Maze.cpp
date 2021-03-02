#include <bits/stdc++.h>
using namespace std;
int R,C;
unordered_map<int,char> m;

void Print(vector<vector<int>> Path)
{
    m[1]='-';  m[0]='.';
    m[2]='^';m[3]='$';
    m[4]='+';
    for(int i=R-1;i>=0;i--)
    {
        for(int j=0;j<C;j++)
        cout<<m[Path[i][j]]<<" ";
        cout<<endl;
    }
}

bool isSafe(int i,int j,vector<vector<int>> Grid)
{
    if(i>=0 && i<R && j>=0 && j<C && Grid[i][j]!=0)
    return true;

    return false;
}

bool MazePathFinder(int i,int j,vector<vector<int>> Grid,vector<vector<int>> &Path)
{
    if(i==R-1 && j==C-1 && Grid[i][j]==3) {return true;}
    if(isSafe(i,j,Grid))
    {
    if(Path[i][j]==4) return false; // Means allready visited
    Path[i][j]=4;
    if(MazePathFinder(i+1,j,Grid,Path)) return true;
    if(MazePathFinder(i,j+1,Grid,Path)) return true;
    if(MazePathFinder(i-1,j,Grid,Path)) return true;
    if(MazePathFinder(i,j-1,Grid,Path)) return true;
    Path[i][j]=0;
    return false;
    }
    return false;
}

int main()
{
    R=6;C=8;
    vector<vector<int>> Grid(R,vector<int>(C,1)),Path(R,vector<int>(C,0));
    // Now we make the Maze in a static way
    // Putting 0s if the place has blockage
    Grid[0][1]=0;Grid[0][7]=0;Grid[5][3]=0;
    Grid[1][3]=0;Grid[1][5]=0;Grid[2][0]=0;Grid[2][2]=0;
    Grid[2][4]=0;Grid[2][6]=0;Grid[3][2]=0;Grid[4][1]=0;
    Grid[4][3]=0;Grid[4][7]=0;Grid[4][5]=0;Grid[4][6]=0;
    Grid[0][0]=2;Grid[R-1][C-1]=3; // Start and end
    cout<<"Here is the Maze\n";
    Print(Grid);
    Path=Grid;
    cout<<"Here is the path to reach the destination\n";
    if(MazePathFinder(0,0,Grid,Path)==false) cout<<"Solution Doesn't Exist";
    else Print(Path);
}
