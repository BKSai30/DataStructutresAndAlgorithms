#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int isSafe(vector<vector<int>> &mat, int row, int col) // mat is the actual chess board for some case
{
    int i, j;
    int n = mat.size();
    for (i = row - 1; i >= 0; i--)
    {
        if (mat[i][col] == 1)
            return 0;
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 1)
            return 0;
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (mat[i][j] == 1)
            return 0;
    }
    return 1;
}

void placeQueens(int row, vector<vector<int>> &mat, vector<vector<int>> &result)
{
    // mat stores the current chess board
    // result stores all the ans for example if a 3x3 board one solution
    // is in row 1 at col2 , row 2 at col 3 , row 4 at col col1 then the result stores [[2,3,1],[],[],[]]etc...
    int n = mat.size();
    if (row == n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    ans.push_back(j + 1); // as we try to store 1 based indexing in result vectors
                }
            }
        }
        result.push_back(ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(mat, row, i))
        {
            mat[row][i] = 1;
            placeQueens(row + 1, mat, result);
            mat[row][i] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;
    placeQueens(0, mat, result);
    return result;
}
