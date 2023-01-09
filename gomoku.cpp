#include<bits/stdc++.h>
using namespace std;
int WhoPlaysFirst,EndingFlag,StartNewGame,CheckListLength,LeftMost,RightMost,UpMost,DownMost,TempLeftMost,TempRightMost,TempUpMost,TempDownMost,StopListLength,StopListLength2,WinListLength;
int Board[17][17],CheckList[255],R[5]={0,1,-1,0,0},C[5]={0,0,0,1,-1},inf=1e9+7,StopLiveThree[255],StopLiveFour[255],WinList[255];
bool ChessboardVis[255];
queue<int> q;
bool CheckIfComputerCanWin()
{
	memset(WinList,0,sizeof(WinList));
	WinListLength=0;
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==0&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+3]==Board[i][j+4]&&Board[i][j+1]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+4]==0&&Board[i][j]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i-1)*15+j+3;
			}
		}
	}//row
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=15;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+3][j]==Board[i+4][j]&&Board[i+1][j]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j]&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+4][j]==0&&Board[i][j]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i+3)*15+j-1;
			}
		}
	}//colomn
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+3][j+3]==Board[i+4][j+4]&&Board[i+1][j+1]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+4][j+4]==0&&Board[i][j]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i+3)*15+j+3;
			}
		}
	}//diagonal-leftup to rightdown
	for(int i=1;i<=11;i++)
	{
		for(int j=5;j<=15;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+3][j-3]==Board[i+4][j-4]&&Board[i+1][j-1]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+4][j-4]==0&&Board[i][j]==3-WhoPlaysFirst)
			{
				WinList[++WinListLength]=(i+3)*15+j-5;
			}
		}
	}//diagonal-rightup to leftdown
	if(WinListLength>0)
		return 1;
	return 0;
}
bool CheckUserLiveFour()
{
	memset(StopLiveFour,0,sizeof(StopLiveFour));
	StopListLength2=0;
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==0&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+3]==Board[i][j+4]&&Board[i][j+1]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+4]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j+3;
			}
			if(Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+3]&&Board[i][j+2]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j+1;
			}
			if(Board[i][j]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+1]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j;
			}
		}
	}//row
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=15;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+3][j]==Board[i+4][j]&&Board[i+1][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j]&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+4][j]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i+3)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j]&&Board[i+1][j]==Board[i+3][j]&&Board[i+2][j]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i+1)*15+j-1;
			}
			if(Board[i][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+1][j]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i)*15+j-1;
			}
		}
	}//colomn
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+3][j+3]==Board[i+4][j+4]&&Board[i+1][j+1]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+4][j+4]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i+3)*15+j+3;
			}
			if(Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+3][j+3]&&Board[i+2][j+2]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i+1)*15+j+1;
			}
			if(Board[i][j]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+1][j+1]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i)*15+j;
			}
		}
	}//diagonal-leftup to rightdown
	for(int i=1;i<=11;i++)
	{
		for(int j=5;j<=15;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+3][j-3]==Board[i+4][j-4]&&Board[i+1][j-1]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i-1)*15+j-1;
			}
			if(Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+4][j-4]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i+3)*15+j-5;
			}
			if(Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+3][j-3]&&Board[i+2][j-2]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i+1)*15+j-3;
			}
			if(Board[i][j]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+1][j-1]==0&&Board[i][j]==WhoPlaysFirst)
			{
				StopLiveFour[++StopListLength2]=(i)*15+j-2;
			}
		}
	}//diagonal-rightup to leftdown
	if(StopListLength2>0)
		return 1;
	return 0;
}
bool CheckUserLiveThree()
{
	memset(StopLiveThree,0,sizeof(StopLiveThree));
	StopListLength=0;
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==0&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+4]==0&&Board[i][j+1]==WhoPlaysFirst)
			{
				StopLiveThree[++StopListLength]=(i-1)*15+j-1;
				StopLiveThree[++StopListLength]=(i-1)*15+j+3;
			}
		}
	}//row
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=15;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+4][j]==0&&Board[i+1][j]==WhoPlaysFirst)
			{
				StopLiveThree[++StopListLength]=(i-1)*15+j-1;
				StopLiveThree[++StopListLength]=(i+3)*15+j-1;
			}
		}
	}//colomn
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+4][j+4]==0&&Board[i+1][j+1]==WhoPlaysFirst)
			{
				StopLiveThree[++StopListLength]=(i-1)*15+j-1;
				StopLiveThree[++StopListLength]=(i+3)*15+j+3;
			}
		}
	}//diagonal-leftup to rightdown
	for(int i=1;i<=11;i++)
	{
		for(int j=5;j<=15;j++)
		{
			if(Board[i][j]==0&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+4][j-4]==0&&Board[i+1][j-1]==WhoPlaysFirst)
			{
				StopLiveThree[++StopListLength]=(i-1)*15+j-1;
				StopLiveThree[++StopListLength]=(i+3)*15+j-5;
			}
		}
	}//diagonal-rightup to leftdown
	if(StopListLength>0)
		return 1;
	return 0;
}
bool CannotSearch(int p1,int p2)
{
	if(Board[p1-1][p2-1]==0&&Board[p1-1][p2]==0&&Board[p1-1][p2+1]==0&&Board[p1][p2-1]==0&&Board[p1+1][p2]==0&&Board[p1][p2+1]==0&&Board[p1+1][p2-1]==0&&Board[p1+1][p2+1]==0)
		return 1;
	return 0;
}
int EvaluateRow(int Mode,int Position)
{
	int EvaluateValue=0;
	for(int i=0;i<=15;i++)
	{
		if(i>=1&&i+4<=15&&Board[Position][i]==Board[Position][i+1]&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i]==Mode)
			EvaluateValue+=1000000;
		if(i>=1&&i+4<=15&&Board[Position][i]==Board[Position][i+1]&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i]==3-Mode)
			EvaluateValue-=10000000;
		if(i+4<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i+5]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=50000;
		if(i+4<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i+5]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=100000;
		if(i+4<=15&&Board[Position][i]==3-Mode&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i+5]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=400;
		if(i+4<=15&&Board[Position][i]==Mode&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i+5]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=100000;
		if(i+4<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i+5]==3-Mode&&Board[Position][i+1]==Mode)
			EvaluateValue+=400;
		if(i+4<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+3]==Board[Position][i+4]&&Board[Position][i+5]==Mode&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=100000;
		if(i+3<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+4]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=400;
		if(i+3<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+4]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=8000;
		if(i+3<=15&&Board[Position][i]==3-Mode&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+4]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=20;
		if(i+3<=15&&Board[Position][i]==Mode&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+4]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=50;
		if(i+3<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+4]==3-Mode&&Board[Position][i+1]==Mode)
			EvaluateValue+=20;
		if(i+3<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+2]==Board[Position][i+3]&&Board[Position][i+4]==Mode&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=50;
		if(i+2<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+3]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=20;
		if(i+2<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+3]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=50;
		if(i+2<=15&&Board[Position][i]==3-Mode&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+3]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=1;
		if(i+2<=15&&Board[Position][i]==Mode&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+3]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=3;
		if(i+2<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+3]==3-Mode&&Board[Position][i+1]==Mode)
			EvaluateValue+=1;
		if(i+2<=15&&Board[Position][i]==0&&Board[Position][i+1]==Board[Position][i+2]&&Board[Position][i+3]==Mode&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=3;
		if(i+1<=15&&Board[Position][i]==0&&Board[Position][i+2]==0&&Board[Position][i+1]==Mode)
			EvaluateValue+=1;
		if(i+1<=15&&Board[Position][i]==0&&Board[Position][i+2]==0&&Board[Position][i+1]==3-Mode)
			EvaluateValue-=3;
	}
	return EvaluateValue;
}//Mode-->Computer,3-Mode-->User
int EvaluateColomn(int Mode,int Position)
{
	int EvaluateValue=0;
	for(int i=0;i<=15;i++)
	{
		if(i>=1&&i+4<=15&&Board[i][Position]==Board[i+1][Position]&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i][Position]==Mode)
			EvaluateValue+=1000000;
		if(i>=1&&i+4<=15&&Board[i][Position]==Board[i+1][Position]&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i][Position]==3-Mode)
			EvaluateValue-=10000000;
		if(i+4<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i+5][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=50000;
		if(i+4<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i+5][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=100000;
		if(i+4<=15&&Board[i][Position]==3-Mode&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i+5][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=400;
		if(i+4<=15&&Board[i][Position]==Mode&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i+5][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=100000;
		if(i+4<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[i+5][Position]==3-Mode&&Board[i+1][Position]==Mode)
			EvaluateValue+=400;
		if(i+4<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+3][Position]==Board[i+4][Position]&&Board[Position][i+5]==Mode&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=100000;
		if(i+3<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+4][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=400;
		if(i+3<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+4][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=8000;
		if(i+3<=15&&Board[i][Position]==3-Mode&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+4][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=20;
		if(i+3<=15&&Board[i][Position]==Mode&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+4][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=50;
		if(i+3<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+4][Position]==3-Mode&&Board[i+1][Position]==Mode)
			EvaluateValue+=20;
		if(i+3<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+2][Position]==Board[i+3][Position]&&Board[i+4][Position]==Mode&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=50;
		if(i+2<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+3][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=20;
		if(i+2<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+3][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=50;
		if(i+2<=15&&Board[i][Position]==3-Mode&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+3][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=1;
		if(i+2<=15&&Board[i][Position]==Mode&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+3][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=3;
		if(i+2<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+3][Position]==3-Mode&&Board[i+1][Position]==Mode)
			EvaluateValue+=1;
		if(i+2<=15&&Board[i][Position]==0&&Board[i+1][Position]==Board[i+2][Position]&&Board[i+3][Position]==Mode&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=3;
		if(i+1<=15&&Board[i][Position]==0&&Board[i+2][Position]==0&&Board[i+1][Position]==Mode)
			EvaluateValue+=1;
		if(i+1<=15&&Board[i][Position]==0&&Board[i+2][Position]==0&&Board[i+1][Position]==3-Mode)
			EvaluateValue-=3;
	}
	return EvaluateValue;
}//Mode-->Computer,3-Mode-->User
int EvaluateDiagonal_1(int Mode)
{
	int EvaluateValue=0;
	for(int Position=0;Position<=15;Position++)
	{
		for(int i=0;i<=15;i++)
		{
			if(i>=1&&i+4<=15&&Position>=1&&Position+4<=15&&Board[Position][i]==Board[Position+1][i+1]&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position][i]==Mode)
				EvaluateValue+=1000000;
			if(i>=1&&i+4<=15&&Position>=1&&Position+4<=15&&Board[Position][i]==Board[Position+1][i+1]&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position][i]==3-Mode)
				EvaluateValue-=10000000;
			if(i+4<=15&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position+5][i+5]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=50000;
			if(i+4<=15&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position+5][i+5]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=100000;
			if(i+4<=15&&Position+4<=15&&Board[Position][i]==3-Mode&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position+5][i+5]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=400;
			if(i+4<=15&&Position+4<=15&&Board[Position][i]==Mode&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position+5][i+5]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=100000;
			if(i+4<=15&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position+5][i+5]==3-Mode&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=400;
			if(i+4<=15&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+3][i+3]==Board[Position+4][i+4]&&Board[Position+5][i+5]==Mode&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=100000;
			if(i+3<=15&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+4][i+4]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=400;
			if(i+3<=15&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+4][i+4]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=8000;
			if(i+3<=15&&Position+3<=15&&Board[Position][i]==3-Mode&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+4][i+4]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=20;
			if(i+3<=15&&Position+3<=15&&Board[Position][i]==Mode&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+4][i+4]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=50;
			if(i+3<=15&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+4][i+4]==3-Mode&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=20;
			if(i+3<=15&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+2][i+2]==Board[Position+3][i+3]&&Board[Position+4][i+4]==Mode&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=50;
			if(i+2<=15&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+3][i+3]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=20;
			if(i+2<=15&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+3][i+3]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=50;
			if(i+2<=15&&Position+2<=15&&Board[Position][i]==3-Mode&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+3][i+3]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=1;
			if(i+2<=15&&Position+2<=15&&Board[Position][i]==Mode&&Board[Position+1][i+1]==Board[Position+2][i+2]&&Board[Position+3][i+3]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=3;
			if(i+2<=15&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position][i+2]&&Board[Position+3][i+3]==3-Mode&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=1;
			if(i+2<=15&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i+1]==Board[Position][i+2]&&Board[Position+3][i+3]==Mode&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=3;
			if(i+1<=15&&Position+1<=15&&Board[Position][i]==0&&Board[Position+2][i+2]==0&&Board[Position+1][i+1]==Mode)
				EvaluateValue+=1;
			if(i+1<=15&&Position+1<=15&&Board[Position][i]==0&&Board[Position+2][i+2]==0&&Board[Position+1][i+1]==3-Mode)
				EvaluateValue-=3;
		}
	}
	return EvaluateValue;
}//Mode-->Computer,3-Mode-->User
int EvaluateDiagonal_2(int Mode)
{
	int EvaluateValue=0;
	for(int Position=0;Position<=15;Position++)
	{
		for(int i=0;i<=15;i++)
		{
			if(i>=5&&Position>=1&&Position+4<=15&&Board[Position][i]==Board[Position+1][i-1]&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position][i]==Mode)
				EvaluateValue+=1000000;
			if(i>=5&&Position>=1&&Position+4<=15&&Board[Position][i]==Board[Position+1][i-1]&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position][i]==3-Mode)
				EvaluateValue-=10000000;
			if(i>=5&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position+5][i-5]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=50000;
			if(i>=5&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position+5][i-5]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=100000;
			if(i>=5&&Position+4<=15&&Board[Position][i]==3-Mode&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position+5][i-5]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=4000;
			if(i>=5&&Position+4<=15&&Board[Position][i]==Mode&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position+5][i-5]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=100000;
			if(i>=6&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position+5][i-5]==3-Mode&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=400;
			if(i>=6&&Position+4<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+3][i-3]==Board[Position+4][i-4]&&Board[Position+5][i-5]==Mode&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=100000;
			if(i>=4&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+4][i-4]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=400;
			if(i>=4&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+4][i-4]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=8000;
			if(i>=4&&Position+3<=15&&Board[Position][i]==3-Mode&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+4][i-4]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=20;
			if(i>=4&&Position+3<=15&&Board[Position][i]==Mode&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+4][i-4]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=50;
			if(i>=5&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+4][i-4]==3-Mode&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=20;
			if(i>=5&&Position+3<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+2][i-2]==Board[Position+3][i-3]&&Board[Position+4][i-4]==Mode&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=50;
			if(i>=3&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+3][i-3]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=20;
			if(i>=3&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+3][i-3]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=50;
			if(i>=3&&Position+2<=15&&Board[Position][i]==3-Mode&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+3][i-3]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=1;
			if(i>=3&&Position+2<=15&&Board[Position][i]==Mode&&Board[Position+1][i-1]==Board[Position+2][i-2]&&Board[Position+3][i-3]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=3;
			if(i>=4&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position][i-2]&&Board[Position+3][i-3]==3-Mode&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=1;
			if(i>=4&&Position+2<=15&&Board[Position][i]==0&&Board[Position+1][i-1]==Board[Position][i-2]&&Board[Position+3][i-3]==Mode&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=3;
			if(i>=2&&Position+1<=15&&Board[Position][i]==0&&Board[Position+2][i-2]==0&&Board[Position+1][i-1]==Mode)
				EvaluateValue+=1;
			if(i>=2&&Position+1<=15&&Board[Position][i]==0&&Board[Position+2][i-2]==0&&Board[Position+1][i-1]==3-Mode)
				EvaluateValue-=3;
		}
	}
	return EvaluateValue;
}//Mode-->Computer,3-Mode-->User
int Evaluate(int Mode)
{
	int ret=0;
	for(int i=1;i<=15;i++)
		ret+=EvaluateRow(Mode,i);//row 
	for(int i=1;i<=15;i++)
		ret+=EvaluateColomn(Mode,i);//colomn
	ret+=EvaluateDiagonal_1(Mode);//diagonal-leftup to rightdown
	ret+=EvaluateDiagonal_2(Mode);//diagonal-rightup to leftdown
	return ret;
}
void bfs()
{
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		int Row=cur/15+1;
		int Col=cur%15+1;
		for(int i=1;i<=4;i++)
		{
			int NewRow=Row+R[i];
			int NewCol=Col+C[i];
			if(NewCol>15||NewCol<1)
				continue;
			if(NewRow>15||NewRow<1)
				continue;
			if(ChessboardVis[(NewRow-1)*15+NewCol-1]==0)
			{
				ChessboardVis[(NewRow-1)*15+NewCol-1]=1;
				CheckList[++CheckListLength]=(NewRow-1)*15+NewCol-1;
				q.push((NewRow-1)*15+NewCol-1);
			}
		}
	}
}
void GenerateCheckList()
{
	q.push(112);
	CheckList[++CheckListLength]=112;
	ChessboardVis[112]=1;
	bfs();
}
void clear()
{
	WhoPlaysFirst=0;
	EndingFlag=0;
	StartNewGame=0;
	LeftMost=0;
	RightMost=0;
	UpMost=0;
	DownMost=0;
	TempLeftMost=0;
	TempRightMost=0;
	TempUpMost=0;
	TempDownMost=0;
	memset(Board,0,sizeof(Board));
	return;
}
int TryingEndingCheck()
{
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+3]==Board[i][j+4]&&Board[i][j]!=0)
			{
				return Board[i][j];
			}
		}
	}
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=15;j++)
		{
			if(Board[i][j]==Board[i+1][j]&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+3][j]==Board[i+4][j]&&Board[i][j]!=0)
			{
				return Board[i][j];
			}
		}
	}
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+3][j+3]==Board[i+4][j+4]&&Board[i][j]!=0)
			{
				return Board[i][j];
			}
		}
	}
	for(int i=1;i<=11;i++)
	{
		for(int j=5;j<=15;j++)
		{
			if(Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+3][j-3]==Board[i+4][j-4]&&Board[i][j]!=0)
			{
				return Board[i][j];
			}
		}
	}
	return 0;
}
void EndingCheck()
{
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+3]==Board[i][j+4]&&Board[i][j]!=0)
			{
				EndingFlag=Board[i][j];
				return;
			}
		}
	}
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=15;j++)
		{
			if(Board[i][j]==Board[i+1][j]&&Board[i+1][j]==Board[i+2][j]&&Board[i+2][j]==Board[i+3][j]&&Board[i+3][j]==Board[i+4][j]&&Board[i][j]!=0)
			{
				EndingFlag=Board[i][j];
				return;
			}
		}
	}
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+3][j+3]==Board[i+4][j+4]&&Board[i][j]!=0)
			{
				EndingFlag=Board[i][j];
				return;
			}
		}
	}
	for(int i=1;i<=11;i++)
	{
		for(int j=5;j<=15;j++)
		{
			if(Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+3][j-3]==Board[i+4][j-4]&&Board[i][j]!=0)
			{
				EndingFlag=Board[i][j];
				return;
			}
		}
	}
}
void ShowBoard()
{
	printf("   A B C D E F G H I J K L M N O\n");
	for(int i=1;i<=15;i++)
	{
		if(i<=9)
			printf("%d  ",i);
		else
			printf("%d ",i);
		for(int j=1;j<=15;j++)
		{
			if(Board[i][j]==1)
			{
				printf("X ");
			}
			else if(Board[i][j]==2)
			{
				printf("O ");
			}
			else
			{
				printf("- ");
			}
		}
		printf("\n");
	}
	return;
}
//player1(first player) uses X,and player2(second player) uses O
//WhoPlaysFirst=1 --> player1=User and player2=Computer
//WhoPlaysFirst=2 --> player1=Computer and player2=User
int MinMaxSearch(int alpha,int beta,int MinMaxMode,int dep)
{
	int pl1,pl2,SearchValue,ReturnValue;
	if(dep==0)
	{
		ReturnValue=Evaluate(3-WhoPlaysFirst);
		return ReturnValue;
	}
	for(int i=1;i<=CheckListLength;i++)
	{
		pl1=CheckList[i]/15+1;
		pl2=CheckList[i]%15+1;
		if(CannotSearch(pl1,pl2))
			continue;
		if(Board[pl1][pl2]!=0)
			continue;
		if(pl2<LeftMost-2)
			continue;
		if(pl2>RightMost+2)
			continue;
		if(pl1<UpMost-2)
			continue;
		if(pl1>DownMost+2)
			continue;
		if(MinMaxMode)
		{
			Board[pl1][pl2]=3-WhoPlaysFirst;
			TempLeftMost=LeftMost;
			TempRightMost=RightMost;
			TempUpMost=UpMost;
			TempDownMost=DownMost;
			LeftMost=min(pl2,LeftMost);
			RightMost=max(pl2,RightMost);
			UpMost=min(pl1,UpMost);
			DownMost=max(pl1,DownMost);
			if(TryingEndingCheck()==0)
				SearchValue=MinMaxSearch(alpha,beta,MinMaxMode^1,dep-1);
			//cout<<"##Log-Floor: "<<5-dep<<' '<<"##Log-MaxMode: "<<pl1<<' '<<pl2<<' '<<SearchValue<<endl;//log output
			if(alpha<SearchValue)
				alpha=SearchValue;
			Board[pl1][pl2]=0;
			LeftMost=TempLeftMost;
			RightMost=TempRightMost;
			UpMost=TempUpMost;
			DownMost=TempDownMost;
			if(beta<=alpha)
				break;//alpha-beta cutting branch
		}
		else
		{
			Board[pl1][pl2]=3-WhoPlaysFirst;
			TempLeftMost=LeftMost;
			TempRightMost=RightMost;
			TempUpMost=UpMost;
			TempDownMost=DownMost;
			LeftMost=min(pl2,LeftMost);
			RightMost=max(pl2,RightMost);
			UpMost=min(pl1,UpMost);
			DownMost=max(pl1,DownMost);
			if(TryingEndingCheck()==0)
				SearchValue=MinMaxSearch(alpha,beta,MinMaxMode^1,dep-1);
			//cout<<"##Log-Floor: "<<5-dep<<' '<<"##Log-MinMode: "<<pl1<<' '<<pl2<<' '<<SearchValue<<endl;//log output
			if(beta>SearchValue)
				beta=SearchValue;
			Board[pl1][pl2]=0;
			LeftMost=TempLeftMost;
			RightMost=TempRightMost;
			UpMost=TempUpMost;
			DownMost=TempDownMost;
			if(beta<=alpha)
				break;//alpha-beta cutting branch
		}
	}
	if(MinMaxMode)
		ReturnValue=alpha;
	else
		ReturnValue=beta;
	return ReturnValue;
}
//MinMaxSearch with alpha-beta cutting branch, MinMaxMode=1 --> MaxMode; MinMaxMode=0 --> MinMode;
void UserRound()
{
	int PlaceChessRow;
	char PlaceChessColomn;
	printf("It's your round. Please select a valid place (presented by '-') to place your chess.\n");
	printf("You can input the number on the chessboard to place your chess. (For exapmle, input '3E' to place your chess in the third row and the fifth column.)\n");
	while(1)
	{
		cin>>PlaceChessRow;
		cin>>PlaceChessColomn;
		int op1=PlaceChessRow;
		int op2=PlaceChessColomn-'A'+1;
		if(op1>=1&&op1<=15&&op2>=1&&op2<=15&&Board[op1][op2]==0)
		{
			Board[op1][op2]=WhoPlaysFirst;
			LeftMost=min(op2,LeftMost);
			RightMost=max(op2,RightMost);
			UpMost=min(op1,UpMost);
			DownMost=max(op1,DownMost);
			ShowBoard();
			printf("You have placed a chess.\n");
			return;
		}
		else
		{
			printf("Invalid Input. Pleas try again.\n");
		}
	}
}
void ComputerRound()
{
	printf("It's Computer's round. \n");
	
	int op1,op2,p1,p2,SearchResult,MaxVal=-inf,SearchVal;
	bool UserLiveThree,UserLiveFour,ComputerCanWin;
	UserLiveThree=CheckUserLiveThree();
	UserLiveFour=CheckUserLiveFour();
	ComputerCanWin=CheckIfComputerCanWin();
	//UserLiveThree=0;
	//UserLiveFour=0;
	//ComputerCanWin=0;
	if(ComputerCanWin)
	{
		op1=WinList[1]/15+1;
		op2=WinList[1]%15+1;
	}
	else if(UserLiveFour)
	{
		for(int i=1;i<=StopListLength2;i++)
		{
			p1=StopLiveFour[i]/15+1;
			p2=StopLiveFour[i]%15+1;
			if(CannotSearch(p1,p2))
				continue;
			if(Board[p1][p2]!=0)
				continue;
			if(p2<LeftMost-2)
				continue;
			if(p2>RightMost+2)
				continue;
			if(p1<UpMost-2)
				continue;
			if(p1>DownMost+2)
				continue;
			Board[p1][p2]=3-WhoPlaysFirst;
			SearchResult=MinMaxSearch(-inf,inf,0,2);
			if(MaxVal<SearchResult)
			{
				MaxVal=SearchResult;
				op1=p1;
				op2=p2;
			}
			Board[p1][p2]=0;
		}
	}
	else if(UserLiveThree)
	{
		for(int i=1;i<=StopListLength;i++)
		{
			p1=StopLiveThree[i]/15+1;
			p2=StopLiveThree[i]%15+1;
			if(CannotSearch(p1,p2))
				continue;
			if(Board[p1][p2]!=0)
				continue;
			if(p2<LeftMost-2)
				continue;
			if(p2>RightMost+2)
				continue;
			if(p1<UpMost-2)
				continue;
			if(p1>DownMost+2)
				continue;
			Board[p1][p2]=3-WhoPlaysFirst;
			SearchResult=MinMaxSearch(-inf,inf,0,2);
			if(MaxVal<SearchResult)
			{
				MaxVal=SearchResult;
				op1=p1;
				op2=p2;
			}
			Board[p1][p2]=0;
		}
	}
	else
	{
		for(int i=1;i<=CheckListLength;i++)
		{
			p1=CheckList[i]/15+1;
			p2=CheckList[i]%15+1;
			if(CannotSearch(p1,p2))
				continue;
			if(Board[p1][p2]!=0)
				continue;
			if(p2<LeftMost-2)
				continue;
			if(p2>RightMost+2)
				continue;
			if(p1<UpMost-2)
				continue;
			if(p1>DownMost+2)
				continue;
			Board[p1][p2]=3-WhoPlaysFirst;
			SearchResult=MinMaxSearch(-inf,inf,0,2);
			if(MaxVal<SearchResult)
			{
				MaxVal=SearchResult;
				op1=p1;
				op2=p2;
			}
			Board[p1][p2]=0;
		}
	}
	Board[op1][op2]=3-WhoPlaysFirst;
	LeftMost=min(op2,LeftMost);
	RightMost=max(op2,RightMost);
	UpMost=min(op1,UpMost);
	DownMost=max(op1,DownMost);
	ShowBoard();
	printf("Computer has placed a chess.\n");
	return;
}
void Game()
{
	if(WhoPlaysFirst==2)
	{
		printf("Computer plays first. Computer's chess is presented by 'X', and your chess is presented by 'O'.\n");
		Board[8][8]=1;
		ShowBoard();
		printf("Computer has placed a chess.\n");
	}
	else
	{
		printf("You plays first. Your chess is presented by 'X', and Computer's chess is presented by 'O'.\n");
		ShowBoard();
	}
	while(1)
	{
		UserRound();
		EndingCheck();
		if(EndingFlag==1)
		{
			if(WhoPlaysFirst==2)
			{
				printf("Computer Wins.\n");
			}
			else
			{
				printf("Congratulation! You Win.\n");
			}
			printf("If you want to start a new game, please input '1'. Or you can input anything except '1' to exit.)\n");
			cin>>StartNewGame;
			if(StartNewGame!=1)
			{
				printf("Thanks for playing Gomoku, see you next time.\n");
				return;
			}
			else
			{
				return;
			}
		}
		else if(EndingFlag==2)
		{
			if(WhoPlaysFirst==1)
			{
				printf("Computer Wins.\n");
			}
			else
			{
				printf("Congratulation! You Win.\n");
			}
			printf("If you want to start a new game, please input '1'. Or you can input anything except '1' to exit.)\n");
			cin>>StartNewGame;
			if(StartNewGame!=1)
			{
				printf("Thanks for playing Gomoku, see you next time.\n");
				return;
			}
			else
			{
				return;
			}
		}
		ComputerRound();
		EndingCheck();
		if(EndingFlag==1)
		{
			if(WhoPlaysFirst==2)
			{
				printf("Computer Wins.\n");
			}
			else
			{
				printf("Congratulation! You Win.\n");
			}
			printf("If you want to start a new game, please input '1'. Or you can input anything except '1' to exit.)\n");
			cin>>StartNewGame;
			if(StartNewGame!=1)
			{
				printf("Thanks for playing Gomoku, see you next time.\n");
				return;
			}
			else
			{
				return;
			}
		}
		else if(EndingFlag==2)
		{
			if(WhoPlaysFirst==1)
			{
				printf("Computer Wins.\n");
			}
			else
			{
				printf("Congratulation! You Win.\n");
			}
			printf("If you want to start a new game, please input '1'. Or you can input anything except '1' to exit.)\n");
			cin>>StartNewGame;
			if(StartNewGame!=1)
			{
				printf("Thanks for playing Gomoku, see you next time.\n");
				return;
			}
			else
			{
				return;
			}
		}
	}
}
void IO()
{
	printf("Welcome to Gomoku, please select who plays first.\n");
	printf("If you want to play first, please input '1'; If you want to play after computer, please input '2'.\n");
	cin>>WhoPlaysFirst;
	while(1)
	{
		if(WhoPlaysFirst==1||WhoPlaysFirst==2)
		{
			Game();
			return;
		}
		else
		{
			printf("Invalid Input. Pleas try again. Or you can input '0' to exit.\n");
			cin>>WhoPlaysFirst;
			if(!WhoPlaysFirst)
			{
				printf("Thanks for playing Gomoku, see you next time.\n");
				return;
			}
		}
	}
}
int main()
{
	GenerateCheckList();
	IO();
	while(StartNewGame==1)
	{
		clear();
		IO();
	}
	return 0;
}
