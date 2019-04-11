#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ofstream fout_filter;

class Butterworth_filter
{
	public:
		Butterworth_filter()
		{
			
		}
		~Butterworth_filter()
		{
			
		}
		void LPButterworth(double curr_input)
		{
			
			static int LPB_Cnt = 0;
			Input_Butter_[2] = curr_input;
			
			//��ȡǰ500������
			if (LPB_Cnt >= 0)
			{
				
				//Butterworth�˲�
				//y(n) = b1x(n) + b2x(n-1) - a(2)y(n-1) -a(3)y(n-2)
				Output_Butter_[2] = bz_[0] * Input_Butter_[2]
					+ bz_[1] * Input_Butter_[1] 
					+ bz_[2] * Input_Butter_[0]
					 - az_[1] * Output_Butter_[1] 
					- az_[2] * Output_Butter_[0];
				LPB_Cnt++;	

			}
			else
			{
				LPB_Cnt++;
				Output_Butter_[2] = Input_Butter_[2];
			}
			
			//���б���
			//x(n)
			Input_Butter_[0] = Input_Butter_[1];
			Input_Butter_[1] = Input_Butter_[2];
			//y(n)
			Output_Butter_[0] = Output_Butter_[1];
			Output_Butter_[1] = Output_Butter_[2];

			cout <<"the"<< LPB_Cnt <<"is= "<< Output_Butter_[2] << endl;
			fout_filter << Output_Butter_[2] <<endl;		
		}
	public:
		double Input_Butter_[3] = {0,0,0}; //ȡ3����ʷ���ݽ����˲�
		double Output_Butter_[3] = {0,0,0};
		double az_[3] = { 1 ,- 1.9111970674260732,0.91497583480143374}; //ϵͳ�������� ��ĸ ϵ��һ��Ҫ��ȷ��
		double bz_[3] = {0.00094469184384015075,0.0018893836876803015,0.00094469184384015075 };	//����
		double ans;
		
};
int main()
{
	ifstream fin_accOril("acc_data.txt");
	fout_filter.open("acc_filter.txt");
	double acc_int;
	string buffer;
	Butterworth_filter acc_filter;
	if (!fin_accOril.is_open())
	{
		cout <<"Can not open the acc_data.txt"<<endl;
	}
	while (getline(fin_accOril,buffer))
	{
		acc_int = atof(buffer.c_str());
		//cout << acc_int << endl;
		acc_filter.LPButterworth(acc_int);
	}

	cout << "filter is end" << endl;
	return 0;
}