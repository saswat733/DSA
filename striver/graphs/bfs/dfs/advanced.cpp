#include <iostream>
#include <vector>
using namespace std;

// Solution class to find the number of connected components (provinces) in a graph
class Solution {
private:
    // Helper function to perform Depth First Search (DFS)
    void dfs(int node, vector<int> adjs[], vector<int>& vis) {
        // Mark the current node as visited
        vis[node] = 1;

        // Traverse all the adjacent nodes
        for (auto it : adjs[node]) {
            if (!vis[it]) {
                // If the adjacent node has not been visited, perform DFS on it
                dfs(it, adjs, vis);
            }
        }
    }

public:
    // Function to find the number of connected components (provinces)
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Number of vertices in the graph
        int V = isConnected.size();
        // Adjacency list representation of the graph
        vector<int> adjs[V];

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    // If there's a connection between node i and node j, add it to the adjacency list
                    adjs[i].push_back(j);
                    adjs[j].push_back(i); // For undirected graph
                }
            }
        }

        // Visited array to keep track of visited nodes
        vector<int> vis(V, 0);
        // Count of connected components
        int cnt = 0;

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            // If the node is not visited, it's a new component
            if (!vis[i]) {
                cnt++;
                // Perform DFS starting from this node
                dfs(i, adjs, vis);
            }
        }

        // Return the number of connected components
        return cnt;
    }
};




//******************************************************* */


#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    // Function to find the minimum time required for all oranges to rot.
    // Space complexity: O(n * m)
    // Time complexity: O(n * m)
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int n = grid.size();    // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Queue to store the cells with rotten oranges and the time at which they rot
        std::queue<std::pair<std::pair<int, int>, int>> q;

        // Visited array to keep track of cells that are processed
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

        // Initialize the queue with all currently rotten oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0; // Variable to track the maximum time taken for all oranges to rot
        // Direction vectors for traversing up, right, down, and left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        // BFS to spread the rot to adjacent cells
        while (!q.empty()) {
            int r = q.front().first.first;   // Current row
            int c = q.front().first.second;  // Current column
            int t = q.front().second;        // Current time
            tm = std::max(tm, t);            // Update the maximum time
            q.pop();

            // Traverse in all four possible directions
            for (int i = 0; i < 4; ++i) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if the adjacent cell is within bounds, not visited, and contains a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;  // Mark the cell as visited and rotten
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;  // There are still fresh oranges left
                }
            }
        }

        return tm;  // Return the total time taken for all oranges to rot
    }
};



//************************************************************************** */

//733. Flood Fill

class Solution {
private:
    // Depth First Search function to fill the image
    // Time complexity: O(n * m), where n is the number of rows and m is the number of columns
    // Space complexity: O(n * m) due to recursion stack in the worst case
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int iniColor) {
        // Fill the current cell with the new color
        ans[row][col] = newColor;
        int n = image.size();     // Number of rows in the image
        int m = image[0].size();  // Number of columns in the image
        
        // Explore the four possible directions (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i]; // Calculate the new row index
            int ncol = col + delCol[i]; // Calculate the new column index

            // Check if the new cell is within the bounds of the image and has the initial color
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                // Recursively fill the connected component
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }

public:
    // Function to perform flood fill on the image
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc]; // Get the initial color of the starting cell
        
        // If the initial color is the same as the new color, return the original image
        if (iniColor == color) return image;
        
        // Create a copy of the original image to store the result
        vector<vector<int>> ans = image;
        
        // Arrays to assist in moving to the 4-connected neighboring cells (up, right, down, left)
        int delRow[] = { -1, 0, +1, 0 };
        int delCol[] = { 0, +1, 0, -1 };
        
        // Start the flood fill process from the starting cell
        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);

        return ans; // Return the modified image
    }
};




/////

// Undirected Graph Cycle
// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <vector>
#include <queue>
using namespace std;

class Solution {
  private:
    // Function to perform BFS and detect a cycle in the graph.
    // Parameters:
    // - src: The starting vertex for BFS.
    // - adj: Adjacency list representing the graph.
    // - vis: Array to keep track of visited vertices.
    // Returns true if a cycle is detected, otherwise false.
    bool detect(int src, vector<int> adj[], int vis[]) {
        // Mark the source vertex as visited.
        vis[src] = 1;

        // Queue to store pairs of vertex and its parent.
        queue<pair<int, int>> q;

        // Start BFS from the source vertex. Parent of the source is set to -1.
        q.push({src, -1});

        // Process nodes in BFS order.
        while (!q.empty()) {
            int node = q.front().first;  // Current vertex
            int parent = q.front().second; // Parent of the current vertex
            q.pop();

            // Traverse all adjacent vertices of the current vertex.
            for (auto adjacentNode : adj[node]) {
                // If the adjacent node is not visited, mark it as visited and push it to the queue.
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // If the adjacent node is visited and it's not the parent of the current node,
                // then a cycle is detected.
                else if (parent != adjacentNode) {
                    return true;
                }
            }
        }

        // No cycle detected from the source vertex.
        return false;
    }

  public:
    // Function to detect a cycle in an undirected graph.
    // Parameters:
    // - V: Number of vertices in the graph.
    // - adj: Adjacency list representing the graph.
    // Returns true if a cycle is detected, otherwise false.
    bool isCycle(int V, vector<int> adj[]) {
        // Initialize a visited array to keep track of visited vertices.
        int vis[V] = {0};

        // Iterate through all vertices in the graph.
        for (int i = 0; i < V; i++) {
            // If the vertex is not visited, perform BFS to detect a cycle.
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }

        // No cycle found in any component of the graph.
        return false;
    }
};




////////////////////////////////////////////



// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <vector>
using namespace std;

class Solution {
  private:
    // Function to perform DFS and detect a cycle in the graph.
    // Parameters:
    // - node: The current vertex being visited.
    // - parent: The parent vertex of the current node in the DFS traversal.
    // - vis: Array to keep track of visited vertices.
    // - adj: Adjacency list representing the graph.
    // Returns true if a cycle is detected, otherwise false.
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        // Mark the current node as visited.
        vis[node] = 1;

        // Traverse all adjacent vertices of the current node.
        for (auto adjNode : adj[node]) {
            // If the adjacent node has not been visited, perform DFS on it.
            if (!vis[adjNode]) {
                if (dfs(adjNode, node, vis, adj) == true) {
                    return true;  // Cycle detected in the DFS subtree.
                }
            }
            // If the adjacent node is visited and is not the parent of the current node,
            // then a cycle is detected.
            else if (adjNode != parent) {
                return true;
            }
        }

        // No cycle detected from the current node.
        return false;
    }

  public:
    // Function to detect a cycle in an undirected graph.
    // Parameters:
    // - V: Number of vertices in the graph.
    // - adj: Adjacency list representing the graph.
    // Returns true if a cycle is detected, otherwise false.
    bool isCycle(int V, vector<int> adj[]) {
        // Initialize a visited array to keep track of visited vertices.
        int vis[V] = {0};

        // Iterate through all vertices in the graph.
        for (int i = 0; i < V; i++) {
            // If the vertex is not visited, perform DFS to detect a cycle.
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj)) return true;
            }
        }

        // No cycle found in any component of the graph.
        return false;
    }
};



///////////////////////////////////////////////////////////////
//542. 01 Matrix



/**
 * @class Solution
 * @brief Provides a solution to the problem of updating a matrix where each cell contains the distance to the nearest 0.
 * 
 * The `updateMatrix` function calculates the shortest distance from each cell in a binary matrix to the nearest `0`. 
 * The function utilizes a breadth-first search (BFS) strategy to achieve this, ensuring efficient computation.
 */
class Solution {
public:
    /**
     * @brief Updates a binary matrix with the distance to the nearest 0 for each cell.
     * 
     * The function takes a matrix `mat` of size `n x m` as input, where each element is either 0 or 1. 
     * It returns a matrix of the same size where each cell contains the shortest distance to a 0.
     * 
     * @param mat A 2D vector of integers representing the input binary matrix.
     * @return A 2D vector of integers where each cell contains the distance to the nearest 0.
     * 
     * @details
     * The function works as follows:
     * 1. It initializes a queue and a visited matrix. All cells containing `0` are added to the queue with a distance of `0`.
     * 2. A BFS is performed from these cells. The BFS explores all four possible directions (up, right, down, left) from each cell.
     * 3. If an unvisited neighboring cell is found, it is marked as visited, its distance is updated, and it is added to the queue.
     * 4. The BFS continues until all cells have been processed, ensuring that each cell is updated with the shortest distance to a `0`.
     * 
     * @note The time complexity of this function is O(n * m), where `n` is the number of rows and `m` is the number of columns in the matrix.
     */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Get matrix dimensions
        int n = mat.size();  // Number of rows
        int m = mat[0].size();  // Number of columns

        // Initialize the visited and distance matrices
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Initialize the queue with all 0's positions and mark them as visited
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});  // Push the position and initial distance (0) into the queue
                    vis[i][j] = 1;  // Mark the cell as visited
                } else {
                    vis[i][j] = 0;  // Mark the cell as unvisited
                }
            }
        }

        // Define the possible directions for movement (up, right, down, left)
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // Perform BFS to update distances
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            // Explore all four possible directions
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // Check if the neighboring cell is within bounds and unvisited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;  // Mark the cell as visited
                    q.push({{nrow, ncol}, steps + 1});  // Push the cell with the updated distance into the queue
                }
            }
        }

        // Return the distance matrix
        return dist;
    }
};





//problem 130
//Replace o's with x's


class Solution {
private:
    // Helper function for DFS traversal
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delRow[], int delCol[]) {
        // Mark the current cell as visited
        vis[row][col] = 1;
        
        int n = board.size();     // Number of rows
        int m = board[0].size();  // Number of columns

        // Explore the 4 possible directions: up, right, down, left
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            // Check if the next position is within bounds and has not been visited,
            // and if it contains an 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int delRow[] = {-1, 0, +1, 0};  // Directional vectors for row (up, right, down, left)
        int delCol[] = {0, +1, 0, -1};  // Directional vectors for column
        
        int n = board.size();     // Number of rows
        int m = board[0].size();  // Number of columns

        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited array initialized to 0

        // Step 1: Traverse the first and last rows to find 'O's connected to the boundary
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delRow, delCol);
            }
            if (!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board, delRow, delCol);
            }
        }

        // Step 2: Traverse the first and last columns to find 'O's connected to the boundary
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delRow, delCol);
            }
            if (!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board, delRow, delCol);
            }
        }

        // Step 3: Convert all unvisited 'O's to 'X' since they are surrounded by 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};




