#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Directions for moving in the grid (up, down, left, right)
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

// Function to check if a cell is valid (inside the grid and not a wall)
bool isValid(int x, int y, int rows, int cols, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 && !visited[x][y];
}

// Function to find the shortest path from start to end in a grid
int shortestPath(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> end)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a visited array to track visited cells
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    
    // Queue for BFS: stores (x, y) coordinates and number of steps
    queue<pair<pair<int, int>, int>> q; // ((x, y), distance)

    // Start BFS from the start cell
    q.push({start, 0}); // Start cell with distance 0
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int x = current.first.first;
        int y = current.first.second;
        int dist = current.second;

        // If we reach the end cell, return the distance
        if (x == end.first && y == end.second)
        {
            return dist;
        }

        // Explore the 4 possible directions (up, down, left, right)
        for (int i = 0; i < 4; i++)
        {
            int newX = x + rowDir[i];
            int newY = y + colDir[i];

            // Check if the new position is valid
            if (isValid(newX, newY, rows, cols, grid, visited))
            {
                visited[newX][newY] = true;
                q.push({{newX, newY}, dist + 1});
            }
        }
    }

    // If no path exists
    return -1;
}

int main()
{
    // Example grid
    vector<vector<int>> grid = {
        {1, 1, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}};

    // Start and end coordinates
    pair<int, int> start = {0, 0}; // Start cell (row 0, column 0)
    pair<int, int> end = {4, 4};   // End cell (row 4, column 4)

    // Find the shortest path
    int result = shortestPath(grid, start, end);

    // Output result
    if (result != -1)
    {
        cout << "The shortest path length is: " << result << endl;
    }
    else
    {
        cout << "No path exists from start to end." << endl;
    }

    return 0;
}
