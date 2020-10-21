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


const int MAXN = 100;	 //最大求解方程数
int N;					 //实际求解方程数
double A[MAXN][MAXN + 1];//增广矩阵
//double arr[3][4] = { {2,1,-1,8},{-3,-1,2,-11},{-2,1,2,-3}};  指定测试
double arr[4][5] = { {8,2,1,2.5,1.5},{1,8,-0.5,2,-3},{1.5,2,8,-1,-4.5},{1,0.5,0.7,8,3.2}};  //固定测试
double X[MAXN];//解

void Input();			//输入方程组
void Inputagain();	    //自定义输入方程组
void Display();			//显示求解方程组
void DisplayResult();	//输出解
void FindMain(int i);	//寻找第i列主元，并将其所在的行交换到当前处理行位置上
void DivMain(int i);	//将主元所在的行的各个系数除以主元，当前主元为1
void Del(int i);		//进行第i列消元
void GaussFun();		//高斯消元


//====================主函数===========================
int main()
{
   
	char ch;
	while (1) {
		Input();
NEXT:	Display();
		GaussFun();
		DisplayResult();
		cout << "是否要继续求解其他方程组？(Y/N)";
		cin >> ch;
	
		if (ch == 'N'||ch == 'n') {
			cout << endl <<"欢迎下次使用！"<< endl;
			break;
		}
		if (ch == 'Y'||ch == 'y'){
			Inputagain();	

			goto NEXT;
		}
	}
	return 0;
}
void Input()//输入测试数据	
{   int i,j;
	N = 4;
	for (i = 0; i < N; i++)
		for (j = 0; j < N + 1; j++)
			A[i][j] = arr[i][j];
}

void Inputagain()
{
	int i,j;
	cout << "请输入方程组阶数N: ";
	cin >> N;
	for (i = 0; i < N; i++){

		for ( j = 0; j < N + 1; j++){
			cout << "第"<< i <<"行" << "第"<< j << "列：";
			cin >> A[i][j];
		}
		cout << endl;
	}
}

void Display()//显示求解方程组
{
	int i,j;
    cout<<"===============================方程组=============================="<<endl;
    for (i = 0; i < N; i++)
	{
		
        cout<<"|";
        for (j = 0; j < N ; j++)
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
	int i;
    cout<<"具体解如下："<<endl;
    for( i = 0 ; i < N ; i++)
        cout<<"X"<< i+1 <<"  =  "<<X[i]<<endl;
}
void FindMain(int i)
{
    // 找主元
    int k = 0;
	int l,j;
    for(j = i; j < N; j++)					//找第i列绝对值最大的元素的行号
        if(A[j][i]&&abs(A[j][i])> abs(A[k][i]))
        {
            k = j;
        }
    if(k != i)									//绝对值最大元素不在i行上,交换行
    {
       double tmp =A[i][0];
       for (l = 0; l < N + 1; l++)
       {
           /* code */
           tmp=A[i][l];
           A[i][l]=A[k][l];
           A[k][l]= tmp;
       }      
    }
}
void DivMain(int i)						//将绝对值最大元素所在行，所有元素除该主元	如：-3/-3
{
	int l;
    double tmp = A[i][i];
    for ( l = 0; l < N + 1; l++)
    {
        /* code */
        A[i][l]=A[i][l]/tmp;    
    }   
}
void Del(int i)							//消去第i行，第i列下面的元素变为0
{
	int j,k;
    for(j = i + 1; j < N; j++) 
    {
         double tmp =A[j][i];
        for (k = 0; k < N+1 ; k++)
        {
            /* code */  
            A[j][k] = A[i][k]*tmp - A[j][k];
        }
    }
}

void GaussFun()//高斯消元
{
	int i,j;
	for ( i = 0; i < N; i++)  //按行处理
	{
		if (i < N - 1)			 //寻找主元，交换到适应位置上
			FindMain(i);
		DivMain(i);
		if (i < N - 1)			 //进行消元处理
			Del(i);
        Display();
	}
	for ( i = N - 2; i >= 0; i--)  //回代过程
		for ( j = N - 1; j > i; j--)
			A[i][N] -= A[i][j] * A[j][N];
	for ( i = 0; i < N; i++)
		X[i] = A[i][N];
	cout << "求解完毕！" << endl;
}
