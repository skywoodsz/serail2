/*kalman���*/
float Angle = 0.0;
/*Ԥ������й��Ƶ�Э����Q*/
//Q=[Q_angle,0;0,Q_gyro]
//Qֵ��С������Ϊ�����޹�����
float Q_angle = 0.001;//������������Э����
float Q_gyro = 0.03;//������Ư�Ƶ�Э����
/*Ԥ��������Э����*/
//��Ϊ����໥��������Э����Ϊ0
float P[2][2] = { {1,0},{0,1} };
/*���������е�Э����*/
float R_angle = 0.5;//���ٶȼƲ���������Э����
float dt = 0.005;//����ʱ�䡣���˲�������ʱ��
float Q_bias = 0;//Q_biasΪ������Ư��
/*kalman����*/
//Ϊ2*1����
float K[2] = { 0 };
//�۲����
//1*2������ Zt=H*[angle,Q_bias]'=angle
//����ֵ����Ư�ƣ�angle��Ϊ����
//����H=[1,0]
float H[2] = { 1,0 };
/*����*/
//�в�
float Angle_err = 0;

/*
	�������˲�
	������ Gyro:�����ǲ����Ǽ��ٶ�
		   Accel:���ٶȼƵĽǶȼ���ֵ
*/
void Kalman_Fiter(float Gyro, float Accel)
{
	/*Ԥ��*/
	//״̬Ԥ��
	//X(k|k-1)=A*X(k-1|k-1)+B*u(k)
	//X=[Angle,Q_bias]'
	//A=[1,-dt;0,1]
	//B=[dt;0]
	//u(k)=Gyro
	//�Ƕ�Ԥ��ֵ��k�Ƕ�=k-1�Ƕ�+�����ٶ�-ƫ������*dt
	Angle += (Gyro - Q_bias)*dt;
	//ƫ����Ԥ��ֵ��ƫ��������
	Q_bias = Q_bias;
	/*���Э����Ԥ��*/
	//P(K|K-1)=A*P(K-1|K-1)A'+Q
	//Q=[Q_angle,0;0,Q_gyro]
	P[0][0] = P[0][0] - P[1][0] * dt - (P[0][1] - P[1][1] * dt)*dt + Q_angle;
	P[0][1] = P[0][1] - P[1][1] * dt;
	P[1][0] = P[1][0] - P[1][1] * dt;
	P[1][1] = P[1][1] + Q_gyro;
	/*kalman����*/
	//Kg(k)=P(k|k-1)*H'/(H*P(k|k-1)*H'+R)
	K[0] = P[0][0]/(P[0][0]+R_angle);
	K[1] = P[1][0]/(P[0][0]+R_angle);
	/*����*/
	//�в�=Zt-H*X(k|k-1);
	//�˴�H=[1,0],X=[angle,Q_bias]
	Angle_err = Accel - Angle;
	//����
	//X(k|k)=X(k|k-1)+Kg(k)*(Zt-H*X(k|k-1))
	Angle += K[0] * Angle_err;
	Q_bias += K[1] * Angle_err;
	//P(k|k)=(I-Kg*H)*P(k|k-1)=P(k|k-1)-Kg*(H*P(k|k-1))
	P[0][0] -= K[0] * P[0][0];
	P[0][1] -= K[0] * P[0][1];
	P[1][0] -= K[1] * P[0][0];
	P[1][1] -= K[1] * P[0][1];
}
