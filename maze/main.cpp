#include <iostream>
#include "Vector.h"

using namespace std;

bool find9(const Vector< Vector<int> > &maze, int &row, int &line){
	for(int i = 0; i < maze.size(); ++i){
		for(int j = 0; j < maze[0].size(); ++i){
			if(maze[i][j] == 9){
				row = i;
				line = j;
				return true;
			}
		}
		
	}
	return false;
}

bool Judge(const Vector< Vector<int> > &maze){
	int row,line;
	
}

int main()
{
	Vector<Vector <int> > maze = {
		{1,0,1,0,0},
		{1,1,1,1,0},
		{1,0,0,9,0}
	};
	cout<<maze.size()<<endl;
	cout<<maze[0].size()<<endl;
	
	int row, line;
	
	find9(maze, row, line);
	cout<<row<<endl<<line<<endl;
	
	return 0;
}