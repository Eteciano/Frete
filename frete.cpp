#include <stdio.h>
#include <conio.h>
main()
{
	int N,M; 
	scanf("%d %d", &N, &M);
	int matriz[N][N],A,B,C; 
	for(int a = 0; a<N; a++) 
	{
		for(int b = 0; b<N; b++)
		{
			matriz[a][b] = 0;
		}
		
	}
	for(int i = 0; i<M; i++) 
	{
		scanf("%d %d %d", &A, &B, &C); 
		matriz[A-1][B-1] = C;
		matriz[B-1][A-1] = C;
	}
	int d[N],achou; 
	int pr[N], aberto[N],existeaberto, pos; 
	for(int c = 0; c<N; c++) 
	{
		d[c]=9999999;
		pr[c]= -1;
		aberto[c]=1;
	}
	d[0] = 0; 
	existeaberto=1; 
	pos=0;
	achou=0;
	while(existeaberto)
	{
		for(int p = 0; p<N&&achou==0; p++)
		{
			if(aberto[p])
			{
				pos=p;
				for(int v = p+1; v<N; v++)
				{
					if(aberto[v])
					{
						if(achou==0)
						{
							if(d[p]<d[v])
							{
								pos=p;
								achou=1;
							}
							else
							{
								pos=v;
								achou=1;
							}	
						}
						else
						{
							if(d[pos]>d[v])
								pos=v;
						}
						
					}
				}
			}
		}
		for( int k = 0; k<N; k++)
		{
			if(matriz[pos][k]>0)
			{
				if(aberto[k])
				{
					if(matriz[pos][k]+d[pos]<d[k])
					{
						d[k]=matriz[pos][k]+d[pos];
						pr[k]=pos;
					}
				}	
			}
		}	
		aberto[pos]=0;
		existeaberto=0;
		achou=0;
		for(int j= 0;j<N; j++)
		{
			if(aberto[j]==1)
				existeaberto=1;
		}
	}
	printf("%d", d[N-1]);
}
