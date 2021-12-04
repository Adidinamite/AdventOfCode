#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int freq[2][33];
int main()
{
    char x[33];
    int size;
     vector <vector <int>> vec;
     while(cin.getline(x, 32))
     {
         size = strlen(x);
         vector <int > line;
         for(int i = 0; i<size; i++)
         {
             int num = x[i] - '0';
             line.push_back(num);
             freq[num][i+1]++;
         }
         vec.push_back(line);
     }
     int gamma=0, epsilon=0;
     for(int i = size; i>=1; i--)
     {
         if(freq[0][i] < freq[1][i])
            gamma += (1 << size-i);
         else
            epsilon += (1 << size-i);
     }
    cout << gamma * epsilon;
    return 0;
}
