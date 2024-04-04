#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int Player = 3;
const int Rock  = 2;
const int Empty = 1;
const int firstRow = 0;

void print(vector<vector<int>>& map, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<int>>& map, int x, int y, int width, int height)
{
    if (x >= 0 && x < width && y >= 0 && y < height && map[y][x] != Rock) return true;
    return false;
}

bool firstTry = true;

bool findPath(vector<vector<int>>& map, int x, int y, int width, int height, vector<vector<int>>& sol)
{
    // print(sol, width, height);cout << endl;
    if (y == height - 1)
    {
        sol[y][x] = Player;
        return true;
    }
    
    if (isValid(map, x, y, width, height) && firstTry)
    {
        firstTry = false;
        sol[y][x] = Player;
        // y++;
        if (findPath(map, x+1, y, width, height, sol))
            return true;
        if (findPath(map, x-1, y, width, height, sol))
            return true;
        if (findPath(map, x, y, width, height, sol))
            return true;
        // if (findPath(map, x, y+1, width, height, sol))
        //     return true;
        
        sol[y][x] = Empty;
        return false;
    }
    
    if (isValid(map, x, y, width, height) && isValid(map, x, y+1, width, height))
    {
        if (sol[y][x] == Empty) return false;
        sol[y][x] = Player;
        y++;
        sol[y][x] = Player;
        // y++;
        if (findPath(map, x+1, y, width, height, sol))
            return true;
        if (findPath(map, x-1, y, width, height, sol))
            return true;
        if (findPath(map, x, y, width, height, sol))
            return true;
        // if (findPath(map, x, y+1, width, height, sol))
        //     return true;
        
        sol[y][x] = Empty;
        y--;
        sol[y][x] = Empty;
        return false;
    }
    
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int width, height;
    cin >> width >> height;
    
    vector<vector<int>> map(height, vector<int>(width));
    vector<vector<int>> sol(height, vector<int>(width));
    int playerPos;
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            char c;
            cin >> c;
            if (c == 'Y')
            {
                map[y][x] = Player;
                playerPos = x;
            }
            else if (c == 'R') map[y][x] = Rock;
            else if (c == 'E') map[y][x] = Empty;
        }
    }
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            sol[y][x] = 0;
        }
    }
    
    // print(map, width, height);
    // cout << endl;
    // print(map, width, height);
    
    if (findPath(map, playerPos, firstRow, width, height, sol))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    // cout << endl;
    // print(sol, width, height);cout << endl;
    
    return 0;
}
