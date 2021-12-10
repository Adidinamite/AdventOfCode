#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
bool valid(int number, int right, int left, int up, int down)
{
    return (number < right && number < left && number< up && number<down);
}
int mat[1001][1001];
int suma = 0;
int main(){
    string line;
    int cnt = 0;int size;
    while(cin >> line)
    {
        cnt++;
        size = line.size();
        for(int i = 0; i< size; i++)
        {
            mat[cnt][i+1] = (line[i] - '0');
        }
    }
    for(int i = 0; i<= size;i++)
    {
        mat[cnt+1][i] = mat[0][i] = 10;
    }
    for(int i= 0; i<=cnt+1; i++)
    {
        mat[i][0] = mat[i][size+1] = 10;
    }
    for(int i = 1; i<=cnt; i++)
    {
        for(int j = 1; j<= size; j++)
        {
            if(valid(mat[i][j], mat[i][j+1], mat[i][j-1], mat[i-1][j], mat[i+1][j]))
            {
                suma += (1 + mat[i][j]);
            }
        }
    }
    //p1
    cout << suma << endl;
}


