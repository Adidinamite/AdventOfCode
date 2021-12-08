#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int mat[1000][1000];
int main(){
int x1,y1,x2,y2;
int total_coord=0,marked=0;
char comma,arrow[3];
while(cin >> x1 >> comma >> y1 >> arrow >> x2 >> comma >> y2)
{
        //y for verticcal, x for horizontal
    if(x1 == x2 || y1 == y2){
        int maxx = max(x1, x2);
        int minx = min(x1, x2);
        int maxy = max(y1, y2);
        int miny = min(y1, y2);
        for(int i = minx; i<=maxx; i++)
        {
            for(int j = miny; j<=maxy; j++)
            {
                total_coord++;
                if(mat[i][j] !=-1)
                {
                    mat[i][j]++;
                    if(mat[i][j] == 2)
                    {
                        mat[i][j] = -1;
                        marked++;
                    }
                }
            }
        }
    }
}
    cout << marked;

}
