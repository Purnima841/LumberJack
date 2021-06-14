#include<iostream>
using namespace std;

int main()
{
	int n,gz,i, profit=0, x, y=0,time, k;
	cin>>time;
	cin>>gz;
	cin>>n;
	int xt[n], yt[n];
	int g[gz][gz],m=0;
	int a[6*n];
	for(i = 0; i < 6*n; i++)
	{
		cin>>a[i];
	}
	for(i = 0; i < gz; i++)
	{
		for(int j = 0; j < gz; j++)
		{
			g[i][j] = 0;
		}
	}
	for(i=0; i < n; i++)
	{
		g[a[6*i]][a[6*i+1]] = a[6*i+2]*a[6*i+3]*a[6*i+5];		
	}
	int c = 0, count = 0;
	xt[c] = a[0];
	yt[c] = a[1];
	profit = 0;
	x = 0;
	y = 0;
	for(i = 1; i < n; i++)
	{
		c++;
		int q;
		q = c;
		xt[c] = a[6*i];
		yt[c] = a[6*i + 1];
		for(int j = 0; j < c; j++)
		{
			if(xt[j] == xt[q])
			{
				c--;
				if(yt[j] > yt[q])
				{
					yt[j] = yt[q];
				}
			}
			if(xt[j] > xt[c])
			{
				int f, h;
				f = xt[c];
				h = yt[c];
				yt[c] = yt[j];
				xt[c] = xt[j];
				xt[j] = f;
				yt[j] = h;
			}
		}
	}
	int x0, y0;
	for(i = 0; i <= c; i++)
	{
		count++;
		x0 = xt[i];
		y0 = yt[i];
		if( x0-x > 0 )
		{	while(x != x0)
			{
				x++;
				cout<<"move right\n";
			}
		}
		else
		{	while(x != x0)
			{
				x--;
				cout<<"move left\n";
		
			}
		}
		if( y0-y > 0 )
		{	while(y != y0)
			{
				y++;
				cout<<"move up\n";
	
			}
		}
		else
		{	while(y != y0)
			{
				y--;
				cout<<"move down\n";	
			}
		}
		profit += g[x][y];
		cout<<"cut up\n";
		i = i + 3;	
	}
	return 0;
	
}	
	
