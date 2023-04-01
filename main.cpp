/*
 * Maze Path Finder
 * 4/1/2023
 * Seung Jun LEE (Somnium Caeruleum)
 * somniumcaeruleum@gmail.com
*/

#include <iostream>

using namespace std;

const int N{5};
const int M{5};

bool find(int** maze, int y, int x) {
	maze[y][x] = '*';
	if (y == N && x == M) return true;
	
	if(maze[y+1][x-1] == 0) {
		if(find(maze, y+1, x+1) == true) return true;
	}

	if(maze[y+1][x] == 0) {
		if(find(maze, y+1, x) == true) return true;
	}

	if(maze[y+1][x+1] == 0) {
		if(find(maze, y+1, x+1) == true) return true;
	}

	if(maze[y][x-1] == 0) {
		if(find(maze, y, x-1) == true) return true;
	}

	if(maze[y][x+1] == 0) {
		if(find(maze, y, x+1) == true) return true;
	}

	if(maze[y-1][x-1] == 0) {
		if(find(maze, y-1, x-1) == true) return true;
	}

	if(maze[y-1][x] == 0) {
		if(find(maze, y-1, x) == true) return true;
	}

	if(maze[y-1][x+1] == 0) {
		if(find(maze, y-1, x+1) == true) return true;
	}
	
	maze[y][x] = 'X';
	return false;	
}

void print_maze(int** maze) {
	for (int i{1}; i < N+1; i++) {
		for (int j{1}; j < M+1; j++) {
			switch(maze[i][j]) {
				case 0:
					cout << 0 << " ";
					break;
				case 1:
					cout << "M" << " ";
					break;
				default:
					cout << (char)maze[i][j] << " ";
					break;
			}
		}
		cout << endl;
	}
	return;
}

int main() {
	int** maze = new int*[N+2];
	for(int i{}; i < N+2; i++) maze[i] = new int[M+2];

	//INPUT
	for (int i{}; i < N+2; i++) {
		for (int j{}; j < M+2; j++) {
			maze[i][j] = 1;
		}
	}

	for (int i{1}; i < N+1; i++) {
		for (int j{1}; j < M+1; j++) {
			cin >> maze[i][j];
		}
	}
	cout << endl << endl;
		
	//(1,1) -> (N, M)
	bool result {find(maze, 1, 1)};
	if(result == false) {
		cout << "False" << endl;
	}
	else {
		cout << "True" << endl;
	}

	print_maze(maze);
	
	return 0;
}

