#include<iostream>
#include<algorithm>
void PrintMat(int a[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			std::cout<<a[i][j]<<" ";
		std::cout<<std::endl;
	}
}

void Mat_1(int (&arr)[4][4])
{
	for(int i=0;i<4;i++)
		for(int j= 0;j<4;j++)
			arr[i][j]=-1;
}

void Working_Mat(int (&arr)[4][4],int b[4][4]  ,int stand)
{
	for(int i=0;i<4;i++)
		arr[i][i]=0;
	
	for(int i=0;i<4;i++)
	{
		arr[stand][i] = b[stand][i];
		arr[i][stand] = b[i][stand];
	}
}

void Adjust_Mat(int (&arr)[4][4],int b[4][4],int stand)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i!=j)
			{
			
			if((i<stand&&j<stand) || (i>stand && j>stand))
				arr[i][j]= std::min(b[i][j], (arr[i][stand]+arr[stand][j]) );
				
			else if( (i>stand&&j<stand) || (i<stand&&j>stand))
				arr[i][j]= std::min(b[i][j], (arr[i][stand]+arr[stand][j]) );	
			}
		}
	}
}

int main() 
{
	int INF= 99;
	int a[4][4] = {{0,9,-4,INF}, {6,0,INF,2}, {INF,5,0,INF}, {INF,INF,1,0}};
	int tmpMat[4][4];
	Mat_1(tmpMat);
	Working_Mat(tmpMat,a,0);
	Adjust_Mat(tmpMat,a,0);
	for(int i=1;i<4;i++)
		Adjust_Mat(tmpMat,tmpMat,i);
	PrintMat(tmpMat);
	
}
