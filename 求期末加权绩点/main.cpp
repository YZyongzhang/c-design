/*
* ����ĿĿ�����������ĩ����ļ�Ȩ��ֵ
* ����ʵ��˼·�����һ�������࣬�������������ԣ�1.�ɼ�2.ѧ��
* ������ʵ��������Ϊ����һ�������ѧ�ֵ��ܺ�
* �ڶ������ÿһ���ɼ��ļ���
* ���������������
*/

#include <iostream>
using namespace std;

//const int  text_number = 4; 
//��������const�������ʣ���Ϊ���ǲ��ɸı����
//�ҵ�Ŀ���ǽ���һ���û����������ȫ�ֱ���
//#define text_number 4
//��������defineҲ�ǲ��Եģ�define�Ƕ����ȫ�ֱ���û�д���������ȫ�ֱ����޷����ģ�
/*
* �������ԣ�const��define���������ȫ�ֱ������޷������޸ĵ�
*/
int text_number ;


/*
*��ʼ��Ƽ�����
*/
class GPA {
public:
	//��Ƴɼ�������,�����в�ͬ�Ŀ�Ŀ��������������
	double score[20];
	int std_score[20] = {0};//������ѧ��
	double gpa[20] = { 0 };//������ÿһ���ɼ���gpa����

	/*
	* ��д��Ϊ
	* ���ѧ�ֺ�
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
	* ���б�д��Ϊ
	*/
	//���ÿһ���ɼ��ļ������Ϊ
	double transform(double x)//�������Ϊ���ô��ݲ���
	{
		return (x - 50)/10;
	}
	/*��������ѧ��֮��*/
	//������Ҫ����ָ��
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
* ���������
*/

int main()
{
	GPA end_text;
	double end_product_and_sum;
	int sum_score1;
	cout << "������Ŀ��Կ�Ŀ������" << endl;//������Զ����е�
	cin >> text_number;
	int judgment = text_number > 20 ? 1 : 0;
	if (judgment == 1)
		cout << "���Կ�Ŀ���࣬���������б�����" << endl;
	else
		cout << "��ʼ���ر�������������������" << endl;
	for (int i = 0; i < text_number; i++)
	{
		cout << "������ĵ�"<<i+1<<"����Ŀ�ɼ�" << endl;
		cin >> end_text.score[i];
		cout << "����óɼ���ѧ��" << endl;
		cin >> end_text.std_score[i];
		end_text.gpa[i] = transform(end_text.score[i]);
	}
	end_product_and_sum = product_and_sum(end_text.std_score, end_text.gpa);
	sum_score1 = sum_score(end_text.std_score);
	
	cout << "���ļ�Ȩƽ������" << end_product_and_sum / sum_score1 << endl;
	return 0;


}