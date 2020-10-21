#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
/*
  ʹ�÷��� 
  const int N=4;
  double A[N][N + 1];
  double X[N];
  N����N�����Է�����
  ͨ������GaussFun������AΪ��������Է��̵ľ�����ʽ
  | A00 A01 A02 A03 |  | X0 |    | A04 |
  | A10 A11 A12 A13 |  | X1 | =  | A14 |
  | A20 A21 A22 A23 |  | X2 |    | A24 |
  | A30 A31 A32 A33 |  | X3 |    | A34 |
  ����ʽ�ṹ������ʾ   x0,x1,x2,x3Ϊ�����ֵ
  A00-A03��A10-A13��A20-A23��A30-A33 Ϊ����ʽϵ��
  A04��A14��A24��A34 Ϊ������
 */


const int MAXN = 100;	 //�����ⷽ����
int N;					 //ʵ����ⷽ����
double A[MAXN][MAXN + 1];//�������
//double arr[3][4] = { {2,1,-1,8},{-3,-1,2,-11},{-2,1,2,-3}};  ָ������
double arr[4][5] = { {8,2,1,2.5,1.5},{1,8,-0.5,2,-3},{1.5,2,8,-1,-4.5},{1,0.5,0.7,8,3.2}};  //�̶�����
double X[MAXN];//��

void Input();			//���뷽����
void Inputagain();	    //�Զ������뷽����
void Display();			//��ʾ��ⷽ����
void DisplayResult();	//�����
void FindMain(int i);	//Ѱ�ҵ�i����Ԫ�����������ڵ��н�������ǰ������λ����
void DivMain(int i);	//����Ԫ���ڵ��еĸ���ϵ��������Ԫ����ǰ��ԪΪ1
void Del(int i);		//���е�i����Ԫ
void GaussFun();		//��˹��Ԫ


//====================������===========================
int main()
{
   
	char ch;
	while (1) {
		Input();
NEXT:	Display();
		GaussFun();
		DisplayResult();
		cout << "�Ƿ�Ҫ����������������飿(Y/N)";
		cin >> ch;
	
		if (ch == 'N'||ch == 'n') {
			cout << endl <<"��ӭ�´�ʹ�ã�"<< endl;
			break;
		}
		if (ch == 'Y'||ch == 'y'){
			Inputagain();	

			goto NEXT;
		}
	}
	return 0;
}
void Input()//�����������	
{   int i,j;
	N = 4;
	for (i = 0; i < N; i++)
		for (j = 0; j < N + 1; j++)
			A[i][j] = arr[i][j];
}

void Inputagain()
{
	int i,j;
	cout << "�����뷽�������N: ";
	cin >> N;
	for (i = 0; i < N; i++){

		for ( j = 0; j < N + 1; j++){
			cout << "��"<< i <<"��" << "��"<< j << "�У�";
			cin >> A[i][j];
		}
		cout << endl;
	}
}

void Display()//��ʾ��ⷽ����
{
	int i,j;
    cout<<"===============================������=============================="<<endl;
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
    cout<<"��������£�"<<endl;
    for( i = 0 ; i < N ; i++)
        cout<<"X"<< i+1 <<"  =  "<<X[i]<<endl;
}
void FindMain(int i)
{
    // ����Ԫ
    int k = 0;
	int l,j;
    for(j = i; j < N; j++)					//�ҵ�i�о���ֵ����Ԫ�ص��к�
        if(A[j][i]&&abs(A[j][i])> abs(A[k][i]))
        {
            k = j;
        }
    if(k != i)									//����ֵ���Ԫ�ز���i����,������
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
void DivMain(int i)						//������ֵ���Ԫ�������У�����Ԫ�س�����Ԫ	�磺-3/-3
{
	int l;
    double tmp = A[i][i];
    for ( l = 0; l < N + 1; l++)
    {
        /* code */
        A[i][l]=A[i][l]/tmp;    
    }   
}
void Del(int i)							//��ȥ��i�У���i�������Ԫ�ر�Ϊ0
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

void GaussFun()//��˹��Ԫ
{
	int i,j;
	for ( i = 0; i < N; i++)  //���д���
	{
		if (i < N - 1)			 //Ѱ����Ԫ����������Ӧλ����
			FindMain(i);
		DivMain(i);
		if (i < N - 1)			 //������Ԫ����
			Del(i);
        Display();
	}
	for ( i = N - 2; i >= 0; i--)  //�ش�����
		for ( j = N - 1; j > i; j--)
			A[i][N] -= A[i][j] * A[j][N];
	for ( i = 0; i < N; i++)
		X[i] = A[i][N];
	cout << "�����ϣ�" << endl;
}
