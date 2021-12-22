#include <fstream>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("fcc.in");
ofstream cout("fcc.out");
char linie[256];
vector<vector<long long>>mat;
vector<vector<long long>>s(9999, vector<long long>(9999,0));
int cnt_lines;
int main() {

while(cin >> linie)
    {
        vector<long long>new_row;
        for(int i = 0; i < strlen(linie) ; i++)
        {
            new_row.push_back(linie[i] - '0');
        }
        cnt_lines++;
        mat.push_back(new_row);
    }

    for(int i = 0; i<cnt_lines ; i++)
    {
        for(int j = 0; j< strlen(linie); j++)
        {
            if(i == 0 && j == 0)
                continue;
            else
            {
                if(i==0)
                    s[i][j] = mat[i][j] + s[i][j-1];
                else if(j == 0)
                    s[i][j] = mat[i][j] + s[i-1][j];
                else
                    s[i][j] = mat[i][j] + min(s[i-1][j], s[i][j-1]);
            }
        }
    }


  for(int i = 0; i<cnt_lines ; i++)
    {
        for(int j = 0; j< strlen(linie); j++)
        {
            cout<< s[i][j]<<" ";
        }
        cout << endl;
    }

}
