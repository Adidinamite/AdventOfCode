#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int mat[1000][1000];
void modif(int &modifi, int &modifj, int x1, int x2, int y1, int y2)
{
    if(x1 < x2)
    {
        modifi = 1;
        if(y1 < y2)
            modifj = 1;
        else
            modifj = -1;
    }
    else
    {
        modifi = -1;
        if(y1 < y2)
            modifj = 1;
        else
            modifj = -1;
    }
}
int main(){
int x1,y1,x2,y2;
int marked_diag=0,marked=0;
char comma,arrow[3];
while(cin >> x1 >> comma >> y1 >> arrow >> x2 >> comma >> y2)
{
        //y for vertical, x for horizontal
    int maxx = max(x1, x2);
    int minx = min(x1, x2);
    int maxy = max(y1, y2);
    int miny = min(y1, y2);
    if(x1 == x2 || y1 == y2){
        for(int i = miny; i<=maxy; i++)
        {
            for(int j = minx; j<=maxx; j++)
            {
                if(mat[i][j] !=-1)
                {
                    mat[i][j]++;
                    if(mat[i][j] == 2)
                    {
                        //mat[i][j] = -1;
                        marked++;
                    }
                }
            }
        }
    }
    else
    {
        int modifi, modifj;
        modif(modifi,modifj,x1,x2,y1,y2);int i, j;
        do
        {
            if(mat[y1][x1] !=-1)
            {
                mat[y1][x1]++;
                if(mat[y1][x1] == 2)
                {
                    //mat[y1][x1] = -1;
                    marked_diag++;
                }
            }x1 = x1 + modifi;
            y1 = y1 + modifj;
        }while(x1!=x2);
        if(mat[y1][x1] !=-1)
        {
            mat[y1][x1]++;
            if(mat[y1][x1] == 2)
            {
                //mat[y1][x1] = -1;
                marked_diag++;
            }
        }
    }
}

    cout << marked+ marked_diag;
}
