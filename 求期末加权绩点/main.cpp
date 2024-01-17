/*
* 本项目目的在于求出期末绩点的加权均值
* 程序实现思路：设计一个绩点类，类中有两个属性：1.成绩2.学分
* 在类中实现三个行为，第一个是求出学分的总和
* 第二个求出每一个成绩的绩点
* 第三个将绩点相加
*/

#include <iostream>
using namespace std;

//const int  text_number = 4; 
//这里利用const并不合适，因为这是不可改变的量
//我的目的是建立一个用户可以输入的全局变量
//#define text_number 4
//这里利用define也是不对的，define是定义的全局变量没有错，但是这种全局变量无法更改？
/*
* 经过尝试，const和define两个定义的全局变量是无法进行修改的
*/
int text_number ;


/*
*开始设计绩点类
*/
class GPA {
public:
	//设计成绩的属性,鉴于有不同的科目，这里利用数组
	double score[20];
	int std_score[20] = {0};//定义了学分
	double gpa[20] = { 0 };//定义了每一个成绩的gpa属性

	/*
	* 编写行为
	* 求出学分和
	*/
};
	int  sum_score( int *gpa_parameter)
	{
		double sum_score = 0;
		for (int i = 0; i < 20; i++)
		{
			if (*(gpa_parameter+i) != 0)
				sum_score = sum_score + *(gpa_parameter + i);
			else
				break;
		}
		return sum_score;
	}
	



	
	/*
	* 进行编写行为
	*/
	//求出每一个成绩的绩点的行为
	double transform(double x)//这里的行为不用传递参数
	{
		return (x - 50)/10;
	}
	/*求出绩点和学分之积*/
	//这里需要传递指针
	double product_and_sum(int *std_score_parameter, double *gpa_parameter) {
		int i = 0;
		double product_sum = 0;
		for (i = 0; i < 10; i++)
		{
			product_sum = product_sum + (*(std_score_parameter + i)) * (*(gpa_parameter + i));
		}
		return product_sum;
	}






/*
* 设计主函数
*/

int main()
{
	GPA end_text;
	double end_product_and_sum;
	int sum_score1;
	cout << "输入你的考试科目总数：" << endl;//这个是自动换行的
	cin >> text_number;
	int judgment = text_number > 20 ? 1 : 0;
	if (judgment == 1)
		cout << "考试科目过多，建议多次运行本程序" << endl;
	else
		cout << "开始加载本程序，请您按操作进行" << endl;
	for (int i = 0; i < text_number; i++)
	{
		cout << "输入你的第"<<i+1<<"个科目成绩" << endl;
		cin >> end_text.score[i];
		cout << "输入该成绩的学分" << endl;
		cin >> end_text.std_score[i];
		end_text.gpa[i] = transform(end_text.score[i]);
	}
	end_product_and_sum = product_and_sum(end_text.std_score, end_text.gpa);
	sum_score1 = sum_score(end_text.std_score);
	
	cout << "您的加权平均分是" << end_product_and_sum / sum_score1 << endl;
	return 0;


}