#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if the next move is safe
bool isSafe(int newI, int newJ, int n , const vector<vector<int>> visited, const vector<vector<int>>& maze) {
    if((newI >= 0 && newI < n) && (newJ >= 0 && newJ < n) && (visited[newI][newJ] == 0) && (maze[newI][newJ] == 1)) {
        return true;
    }
    return false;
}

// Function to find paths in the maze
void ratMaze(vector<vector<int>>& maze, int n, vector<string>& ans, string output, vector<vector<int>> visited, int i, int j) {
    // Base case: reach the bottom-right corner
    if(i == n-1 && j == n-1) {
        ans.push_back(output);
        return;
    }

    // Mark the current cell as visited
    visited[i][j] = 1;

    // Move Down
    int newI = i+1;
    int newJ = j;
    if(isSafe(newI, newJ, n, visited, maze)) {
        output.push_back('D');
        ratMaze(maze, n, ans, output, visited, newI, newJ);
        output.pop_back();
    }

    // Move Up
    newI = i-1;
    newJ = j;
    if(isSafe(newI, newJ, n, visited, maze)) {
        output.push_back('U');
        ratMaze(maze, n, ans, output, visited, newI, newJ);
        output.pop_back();
    }

    // Move Left
    newI = i;
    newJ = j-1;
    if(isSafe(newI, newJ, n, visited, maze)) {
        output.push_back('L');
        ratMaze(maze, n, ans, output, visited, newI, newJ);
        output.pop_back();
    }

    // Move Right
    newI = i;
    newJ = j+1;
    if(isSafe(newI, newJ, n, visited, maze)) {
        output.push_back('R');
        ratMaze(maze, n, ans, output, visited, newI, newJ);
        output.pop_back();
    }

    // Unmark the current cell as visited
    visited[i][j] = 0;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans;
    string output;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // Start from the top-left corner of the maze
    if (maze[0][0] == 1) {
        ratMaze(maze, n, ans, output, visited, 0, 0);
    }

    // Print the results
    for (const auto& path : ans) {
        cout << path << endl;
    }

    return 0;
}
