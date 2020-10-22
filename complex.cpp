#include <cstdio>
#include <iostream>


using namespace std;

class MyComplex{	//������
	private:
		double real,imag;
	public:
		MyComplex();					//�޲������캯��
		MyComplex(double r , double i);	//�������Ĺ��캯�� 
		void Result();					//��ӡ���
		MyComplex operator+(const MyComplex &c); //�ӷ���������غ���
		MyComplex operator-(const MyComplex &c); //������������غ���
		MyComplex operator*(const MyComplex &c); //�˷���������غ���
		MyComplex operator/(const MyComplex &c); //������������غ���		
};

/*------------------------------��������--------------------------------*/
MyComplex:: MyComplex(){
	real = 0;
	imag = 0;
}

MyComplex:: MyComplex(double r, double i){
	real = r;
	imag = i;
}

//��ӡ���
void MyComplex::Result(){
	cout << "("<< real <<"," << imag << ")";
}

//��
MyComplex MyComplex:: operator + (const MyComplex &c){
	return MyComplex(this->real + c.real, this->imag + c.imag);
}

//��
MyComplex MyComplex:: operator - (const MyComplex &c){
	return MyComplex(this->real - c.real, this->imag - c.imag);
}

//��
MyComplex MyComplex:: operator * (const MyComplex &c){
	return MyComplex(this->real * c.real, this->imag * c.imag);
}

//��
MyComplex MyComplex:: operator / (const MyComplex &c){
	return MyComplex(this->real / c.real, this->imag / c.imag);
}

int main(int argc, char *argv[])
{
	cout << "��ӭ���븴����������" << endl;
	int a,b,c,d;
	cout << "�����븴��1:  ";
	cin >> a >> b;

	cout << "�����븴��2:  ";
	cin >> c >> d;
	cout << endl;

	MyComplex c1(a,b),c2(c,d),res;
	
	int choise = 0;
	
	while(1){
		cout<< "************************************" << endl;
		cout<< " 1 ��   2 ��   3 ��   4 ��   5 �˳� " << endl;
		cout<< "************************************" << endl;
		
		cout << "please choise > ";
		cin >> choise;

		switch(choise){
			case 1:
				c1.Result();
				cout << " + ";
				c2.Result();
				cout << " = ";
				res = c1+c2;
				res.Result();
				cout << endl;
				break;
			
			case 2:
				c1.Result();
				cout << " - ";
				c2.Result();
				cout << " = ";
				res = c1-c2;
				res.Result();
				cout << endl;
				break;
		
			case 3:
				c1.Result();
				cout << " * ";
				c2.Result();
				cout << " = ";
				res = c1*c2;
				res.Result();
				cout << endl;
				break;
		
			case 4:
				c1.Result();
				cout << " / ";
				c2.Result();
				cout << " = ";
				res = c1/c2;
				res.Result();
				cout << endl;
				break;
			case 5:
				cout << "��ӭ�´�ʹ�ã�" << endl;
				exit(1);
			default:
				cout << "��������������" << endl;
				break;
		}
		
	}
	return 0;
}

