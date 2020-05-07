#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
	double x;
	double y;
};

struct vector {
	double x;
	double y;
};

/*struct vector sumVectors(struct vector vector1, struct vector vector2){
	struct vector out;
	out.x = vector1.x + vector2.x;
	out.y = vector1.y + vector2.y;
	return out;
}*/

double dotProduct(struct vector vector1, struct vector vector2){
	double out;
	out = (vector1.x*vector2.x) + (vector1.y*vector2.y);
	return out;
}

double vectorLength(struct vector vector1)
{
	double out;
	out = sqrt((vector1.x*vector1.x) + (vector1.y*vector1.y));
	return out;
}

void getPointValues(struct point points[4]){
	double a;
	
	printf("A = ");
	scanf("%lf", &a);
	printf("\n");
	
	points[0].x = a;
	points[0].y = a;
	points[1].x = a;
	points[1].y = 2*a;
	points[2].x = 2*a;
	points[2].y = 2*a;
	points[3].x = 2*a;
	points[3].y = a;
}

double getQValue(){
	double Qk; 
	printf("Q = ");
	scanf("%lf", &Qk);
	printf("\n");
	return Qk;
}

double getNValue(){
	double Nk; 
	printf("N = ");
	scanf("%lf", &Nk);
	printf("\n");
	return Nk;
}

double getIntegralValue(double Qi, double Ni, struct point pointsi[4])
{
	const double k = 9 * pow(10, 9);
	double A = pointsi[1].y - pointsi[0].y;
	double dl = A/Ni;
	double paraE = k * Qi;
	/*printf("%.15lf", paraE);
	printf("\n");*/
	
	double x = 0;
	double y = 0;
	
	double xr = 0;
	double yr = 0;
	
	int j;
	double sum[4] = {0, 0, 0, 0};
	double output = 0;
	double value;
	struct vector vectorR;
	struct vector vectorDL;
	
	double directions[4] = {1, 1, -1, -1};
	
	for(j = 0; j < 4; j ++)
	{
		int i;
		x = pointsi[j].x;
		y = pointsi[j].y;
		
		if(j%2 == 0)
		{
			vectorDL.x = 0;
			vectorDL.y = dl*directions[j];
		}else{
			vectorDL.x = dl*directions[j];
			vectorDL.y = 0;
		}
		
		for(i = 0;i < Ni;i++)
		{
			xr = x + (vectorDL.x*(1 + i*2)/2);
			yr = y + (vectorDL.y*(1 + i*2)/2);
			vectorR.x = xr;
			vectorR.y = yr;
			value = paraE*dotProduct(vectorR, vectorDL) / (vectorLength(vectorR)*vectorLength(vectorR)*vectorLength(vectorR));
			output = output + value;
			sum[j] = sum[j] + value;
		}
		/*printf("%0.15lf", sum[j]);
		printf("\n");
		printf("###############################################################################");
		printf("\n");*/
	}
	return output;
}


int main() {

	struct point points[4];
	double Q;
	double N;
	
	Q = getQValue();
	N = getNValue();
	
	getPointValues(points);
	
	double output;
	output = getIntegralValue(Q, N, points);
	printf("electric potential = %.15lf",output);
	
	return 1;

}