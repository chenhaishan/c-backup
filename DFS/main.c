#include <stdio.h>

int a[3][5];
int s[3][5];
int flag;
/*
void init ()
{
	int i,j;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			scanf ("%d", &a[i][j]);
		}
	}
}
*/
void DFS (int m, int n, int p, int q)

{
	if (a[m][n] == 9)
	{
		flag = 1;
		return;
	}

	if ((n+1 < q) && (!s[m][n+1]) && (a[m][n+1] > 0)) 
	{
		s[m][n+1] = 1;
		DFS (m, n+1, p, q);
		s[m][n+1] = 0;
	}
	
	if ((m+1 < p) && (!s[m+1][n]) && (a[m+1][n] > 0)) 
	{
		s[m+1][n] = 1;
		DFS (m+1, n, p, q);
		s[m+1][n] = 0;
	}
	
	if ((n-1 >= 0) && (!s[m][n-1]) && (a[m][n-1] > 0)) 
	{
		s[m][n-1] = 1;
		DFS (m, n-1, p, q);
		s[m][n-1] = 0;
	}
	
	if ((m-1 >= 0) && (!s[m-1][n]) && (a[m-1][n] > 0)) 
	{
		s[m-1][n] = 1;
		DFS (m-1, n, p, q);
		s[m-1][n] = 0;
	}
}

int main()
{
	int i,j;
	
//	freopen ("in.txt", "r", stdin);
/*	
	init ();
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			printf ("%d ", a[i][j]);
		}
		printf ("\n");
	}
	*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			scanf ("%d", &a[i][j]);
		}
	}
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			printf ("%d ", a[i][j]);
		}
		printf ("\n");
	}
	DFS (0, 0, 3, 5);

	if (flag) printf ("success\n");
	else printf ("failure\n");
	return 0;
}
