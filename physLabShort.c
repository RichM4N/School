#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
	double L;
	double N;
	double I;
	double X0;
	double Y0;
	double Z0;
	const double U = pow(10,-7);
	
	
	printf("L = ");
	scanf("%lf", &L);
	printf("\n");
	printf("N = ");
	scanf("%lf", &N);
	printf("\n");
	printf("I = ");
	scanf("%lf", &I);
	printf("\n");
	
	printf("X = ");
	scanf("%lf", &X0);
	printf("Y = ");
	scanf("%lf", &Y0);
	printf("Z = ");
	scanf("%lf", &Z0);
	printf("\n");
	
	double valueX = 0;
	double valueY;
	double valueZ;
	
	double sumX = 0;
	double sumY = 0;
	double sumZ = 0;
	
	int j;
	
	double startPointX = -L/2;
	
	double currentPointX;
	double currentPointY;
	double currentPointZ;
	
	double dL = L/N;
	
	double RX;
	double RY = Y0;
	double RZ = Z0;
	
	double length;
	
	for(j = 0; j < N; j++)
	{
		currentPointX = startPointX + ((j + 0.5)*dL);
		
		RX = X0 - currentPointX;
		
		length = pow(sqrt(RX*RX + RY*RY + RZ*RZ),3);
		
		valueY = (-1 * dL * RZ)/length;
		valueZ = (dL * RY)/length;
		
		sumY = sumY + valueY;
		sumZ = sumZ + valueZ;
	}
	
	sumY = sumY * I * U;
	sumZ = sumZ * I * U;
	
	printf("Output vector:\n");
	printf("X = %.15lf\n",sumX);
	printf("Y = %.15lf\n",sumY);
	printf("Z = %.15lf\n",sumZ);
	
}