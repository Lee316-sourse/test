#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
/*
  使用方法 
  const int N=4;
  double A[N][N + 1];
  double X[N];
  N代表N阶线性方程组
  通过调用GaussFun函数，A为输入的线性方程的矩阵形式
  | A00 A01 A02 A03 |  | X0 |    | A04 |
  | A10 A11 A12 A13 |  | X1 | =  | A14 |
  | A20 A21 A22 A23 |  | X2 |    | A24 |
  | A30 A31 A32 A33 |  | X3 |    | A34 |
  行列式结构如上所示   x0,x1,x2,x3为所求的值
  A00-A03、A10-A13、A20-A23、A30-A33 为行列式系数
  A04、A14、A24、A34 为常数项
 */
const int MAXN = 100;//最大求解方程数
int N; //实际求解方程数
double A[MAXN][MAXN + 1];//增广矩阵
double arr[4][5] = { {8,2,1,2.5,1.5},{1,8,-0.5,2,-3},{1.5,2,8,-1,-4.5},{1,0.5,0.7,8,3.2} };//测试数据
double X[MAXN];//解

void Input(); //输入方程组
void Display();//显示求解方程组
void DisplayResult();//输出解
void FindMain(int i);//寻找第i列主元，并将其所在的行交换到当前处理行位置上
void DivMain(int i); //将主元所在的行的各个系数除以主元，当前主元为1
void Del(int i);//进行第i列消元
void GaussFun();//高斯消元
//====================主函数===========================
int main()
{
   
	char ch;
	while (1) {
		Input();
		Display();
		GaussFun();
		DisplayResult();
		cout << "是否要继续求解其他方程组？(Y/N)";
		cin >> ch;
		if (ch == 'N'||ch == 'n') break;
	}
	return 0;
}
void Input()//输入基本数据
{   //测试数据
	N = 4;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N + 1; j++)
			A[i][j] = arr[i][j];
	/*
	改写成可以让用户输入各项数据
	*/
}
void Display()//显示求解方程组
{
    cout<<"===============================方程组=============================="<<endl;
    for (int i = 0; i < N; i++)
	{
        cout<<"|";
        for (int j = 0; j < N ; j++)
		{
           cout<<setw(10) <<A[i][j];
        }
        cout<<"|";
        if(i==N/2)cout<<"  *  ";
        else cout<<"     ";
        cout<<"|  "<<"X"<<i+1<<"  |";
        cout<<"|"<<setw(10)<<A[i][N]<<"|"<<endl;
    }	
}
void DisplayResult()
{
    cout<<"具体解如下："<<endl;
    for(int i = 0 ; i < N ; i++)
        cout<<"X"<< i+1 <<"  =  "<<X[i]<<endl;
}
void FindMain(int i)
{
    // 找主元
    int k = 0; 
    for(int j = i; j < N; j++)//找第i列最大的元素的行号
        if(A[j][i]&&abs(A[j][i])> abs(A[k][i]))
        {
            k = j;
        }
    if(k != i)//最大元素不在i上,交换行
    {
       double tmp =A[i][0];
       for (int l = 0; l < N + 1; l++)
       {
           /* code */
           tmp=A[i][l];
           A[i][l]=A[k][l];
           A[k][l]= tmp;
       }      
    }
}
void DivMain(int i)
{
     double tmp = A[i][i];
    for (int l = 0; l < N + 1; l++)
    {
        /* code */
        A[i][l]=A[i][l]/tmp;    
    }   
}
void Del(int i)
{
    for(int j = i + 1; j < N; j++) //消去第i行，第i列下面的元素
    {
         double tmp =A[j][i];
        for (int k = 0; k < N+1 ; k++)
        {
            /* code */  
            A[j][k] = A[i][k]*tmp - A[j][k];
        }
    }
}

void GaussFun()//高斯消元
{
	for (int i = 0; i < N; i++)  //按行处理
	{
		if (i < N - 1)   //寻找主元，交换到适应位置上
			FindMain(i);
		DivMain(i);
		if (i < N - 1)  //进行消元处理
			Del(i);
        Display();
	}
	for (int i = N - 2; i >= 0; i--)  //回代过程
		for (int j = N - 1; j > i; j--)
			A[i][N] -= A[i][j] * A[j][N];
	for (int i = 0; i < N; i++)
		X[i] = A[i][N];
	cout << "求解完毕！" << endl;
}
