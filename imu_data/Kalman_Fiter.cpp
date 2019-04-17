/*kalman输出*/
float Angle = 0.0;
/*预测过程中估计的协方差Q*/
//Q=[Q_angle,0;0,Q_gyro]
//Q值很小，即认为基本无估计误差。
float Q_angle = 0.001;//陀螺仪噪声的协方差
float Q_gyro = 0.03;//陀螺仪漂移的协方差
/*预测过程误差协方差*/
//认为误差相互独立，故协方差为0
float P[2][2] = { {1,0},{0,1} };
/*测量过程中的协方差*/
float R_angle = 0.5;//加速度计测量噪声的协方差
float dt = 0.005;//积分时间。即滤波器采样时间
float Q_bias = 0;//Q_bias为陀螺仪漂移
/*kalman增益*/
//为2*1向量
float K[2] = { 0 };
//观测矩阵
//1*2行向量 Zt=H*[angle,Q_bias]'=angle
//测量值不计漂移，angle即为所测
//所以H=[1,0]
float H[2] = { 1,0 };
/*更新*/
//残差
float Angle_err = 0;

/*
	卡尔曼滤波
	输入量 Gyro:陀螺仪测量角加速度
		   Accel:加速度计的角度计算值
*/
void Kalman_Fiter(float Gyro, float Accel)
{
	/*预测*/
	//状态预测
	//X(k|k-1)=A*X(k-1|k-1)+B*u(k)
	//X=[Angle,Q_bias]'
	//A=[1,-dt;0,1]
	//B=[dt;0]
	//u(k)=Gyro
	//角度预测值：k角度=k-1角度+（角速度-偏移量）*dt
	Angle += (Gyro - Q_bias)*dt;
	//偏移量预测值：偏移量不变
	Q_bias = Q_bias;
	/*误差协方差预测*/
	//P(K|K-1)=A*P(K-1|K-1)A'+Q
	//Q=[Q_angle,0;0,Q_gyro]
	P[0][0] = P[0][0] - P[1][0] * dt - (P[0][1] - P[1][1] * dt)*dt + Q_angle;
	P[0][1] = P[0][1] - P[1][1] * dt;
	P[1][0] = P[1][0] - P[1][1] * dt;
	P[1][1] = P[1][1] + Q_gyro;
	/*kalman增益*/
	//Kg(k)=P(k|k-1)*H'/(H*P(k|k-1)*H'+R)
	K[0] = P[0][0]/(P[0][0]+R_angle);
	K[1] = P[1][0]/(P[0][0]+R_angle);
	/*更新*/
	//残差=Zt-H*X(k|k-1);
	//此处H=[1,0],X=[angle,Q_bias]
	Angle_err = Accel - Angle;
	//更新
	//X(k|k)=X(k|k-1)+Kg(k)*(Zt-H*X(k|k-1))
	Angle += K[0] * Angle_err;
	Q_bias += K[1] * Angle_err;
	//P(k|k)=(I-Kg*H)*P(k|k-1)=P(k|k-1)-Kg*(H*P(k|k-1))
	P[0][0] -= K[0] * P[0][0];
	P[0][1] -= K[0] * P[0][1];
	P[1][0] -= K[1] * P[0][0];
	P[1][1] -= K[1] * P[0][1];
}
