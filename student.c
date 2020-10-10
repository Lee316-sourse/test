/*================================================================
*   Copyright (C) 2020 hqyj Ltd. All rights reserved.
*   
*   文件名称：student.c
*   创 建 者：Lee
*   创建日期：2020年09月24日
*   描    述：学生管理
*
================================================================*/


#include <stdio.h>
#include <string.h>
#define MAX 50


/*学生信息结构体*/
typedef struct student{
	char name[20];
	char sex;
	int age;
	int score;
}student_t;

/*班级信息结构体*/
typedef struct {
	int n;
	student_t stu[MAX];
}class_t;

/*枚举*/
enum {
	ADD_STUDENT = 1,
	SHOW_STUDENT,
	DEL_STUDENT,
	FIND_STUDENT,
	SORT_STUDENT,
	QUIT
};

/*----------------------------添加--------------------------------*/
int input_student(class_t* class, student_t* pstu)
{
	int ret = -1;
TRY_AGAIN:
	printf("name\tsex\tage\tscore\n");
	ret = scanf("%s%*c%c%d%d",
			pstu->name,&pstu->sex,&pstu->age,&pstu->score);
	if(ret < 4){
		printf("ret %d\n",ret);
		printf("input error,try again!\n");
		while(getchar()!='\n');
		goto TRY_AGAIN;
	}

	if(class->n >= MAX){
		printf("class is full\n");
		return -1;
	}else{
		class->stu[class->n++] = *pstu;
	}

	printf("add successful!\n");
	return 0;
}
/*-----------------------------查询-------------------------------*/
void show(student_t* pstu)
{
	printf("%s\t%c\t%d\t%d\n",
			pstu->name,pstu->sex,pstu->age,pstu->score);
}

void show_student(class_t* class)
{
	int i;
	printf("name\tsex\tage\tscore\n");
	for(i=0; i<class->n; i++){
		show(&class->stu[i]);
	}
	if(class->n == 0){
		printf("nobody in class\n");
	}
}

/*-----------------------------删除-------------------------------*/

int delete_student(class_t* class, char* name)
{
	int i,j;
	for(i=0,j=0; i<class->n; i++){
		if(strcmp(class->stu[i].name,name) != 0){
			class->stu[j++] = class->stu[i];
		}
	}

	if(j==i){
		printf("The delete student[%s] isn't in class!\n",name);
		return 0;
	}

	class->n = j;

	return i-j;
}

/*-----------------------------查找--------------------------------*/
int find_student(class_t* class,char* name)
{
	int i =0,cout=0;
	for(i=0; i<class->n; i++){
		if(strcmp(class->stu[i].name,name) == 0){
			show(&class->stu[i]);
			cout++;
		}
	}
	return cout;
}

/*-----------------------------排序--------------------------------*/
void sort_student(class_t* class)
{
	
	int i=0,j=0;
	student_t stu;
	printf("class->n   %d\n",class->n);
	for(i=0; i< class->n -1; i++){
		for(j=0; j< (class->n)-1-i; j++){
			if(class->stu[j].score > class->stu[j+1].score){
				stu = class->stu[j];
				class->stu[j] = class->stu[j+1];
				class->stu[j+1] = stu;
			}
		} 
	}
}



int main(int argc, char *argv[])
{
	int n,num;
	int choise;
	char name[20];
	student_t student;
	class_t class = {0};


	while(1)
	{
		puts("**************************************************");
		puts("  1,添加  2,查询  3,删除  4,查找  5,排序  6,退出  ");	
		puts("**************************************************");
		printf("please input choose >");
		scanf("%d",&choise);
		switch(choise){
			case ADD_STUDENT:
				input_student(&class,&student);
				printf("%d\n",class.n);
				break;
			case SHOW_STUDENT:
				show_student(&class);
				printf("%d\n",class.n);
				break;
			case DEL_STUDENT:
				printf("please input del (name) >");
				scanf("%s",name);
				n = delete_student(&class,name);
				if(n > 0){
					printf("delete %d students\n",n);
				}
				printf("%d\n",class.n);
				break;
			case FIND_STUDENT:
				printf("please input find (name) >");
				scanf("%s",name);
				num = find_student(&class,name);
				printf("Find %d this name information\n",num);
				printf("%d\n",class.n);
				break;
			case SORT_STUDENT:
				sort_student(&class);
				show_student(&class);
				break;
			case QUIT:
				printf("thanks for use!\n");
				goto quit;
				break;
			default:
				break;
		}
		
		
	}
quit:
	return 0;
}

