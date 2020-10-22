#include <cstdio>
#include <iostream>


using namespace std;

class MyComplex{	//复数类
	private:
		double real,imag;
	public:
		MyComplex();					//无参数构造函数
		MyComplex(double r , double i);	//带参数的构造函数 
		void Result();					//打印结果
		MyComplex operator+(const MyComplex &c); //加法运算符重载函数
		MyComplex operator-(const MyComplex &c); //减法运算符重载函数
		MyComplex operator*(const MyComplex &c); //乘法运算符重载函数
		MyComplex operator/(const MyComplex &c); //除法运算符重载函数		
};

/*------------------------------函数定义--------------------------------*/
MyComplex:: MyComplex(){
	real = 0;
	imag = 0;
}

MyComplex:: MyComplex(double r, double i){
	real = r;
	imag = i;
}

//打印结果
void MyComplex::Result(){
	cout << "("<< real <<"," << imag << ")";
}

//加
MyComplex MyComplex:: operator + (const MyComplex &c){
	return MyComplex(this->real + c.real, this->imag + c.imag);
}

//减
MyComplex MyComplex:: operator - (const MyComplex &c){
	return MyComplex(this->real - c.real, this->imag - c.imag);
}

//乘
MyComplex MyComplex:: operator * (const MyComplex &c){
	return MyComplex(this->real * c.real, this->imag * c.imag);
}

//除
MyComplex MyComplex:: operator / (const MyComplex &c){
	return MyComplex(this->real / c.real, this->imag / c.imag);
}

int main(int argc, char *argv[])
{
	cout << "欢迎进入复数运算器！" << endl;
	int a,b,c,d;
	cout << "请输入复数1:  ";
	cin >> a >> b;

	cout << "请输入复数2:  ";
	cin >> c >> d;
	cout << endl;

	MyComplex c1(a,b),c2(c,d),res;
	
	int choise = 0;
	
	while(1){
		cout<< "************************************" << endl;
		cout<< " 1 加   2 减   3 乘   4 除   5 退出 " << endl;
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
				cout << "欢迎下次使用！" << endl;
				exit(1);
			default:
				cout << "输入有误，请重试" << endl;
				break;
		}
		
	}
	return 0;
}

