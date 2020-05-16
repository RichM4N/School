#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct vec3d{
	double x;
	double y;
	double z;
};

struct point3d{
	double x;
	double y;
	double z;
};

struct vec3d crossProduct(struct vec3d vector1, struct vec3d vector2){
	struct vec3d outVec;
	outVec.x = (vector1.y*vector2.z) - (vector1.z*vector2.y);
	outVec.y = (vector1.z*vector2.x) - (vector1.x*vector2.z);
	outVec.z = (vector1.x*vector2.y) - (vector1.y*vector2.x);
	return outVec;
}

struct vec3d createVector(struct point3d point1, struct point3d point2){
	struct vec3d outVec;
	outVec.x = point2.x - point1.x;
	outVec.y = point2.y - point1.y;
	outVec.z = point2.z - point1.z; 
	return outVec;
}

double vectorLength(struct vec3d vector1){
	double out;
	out = sqrt((vector1.x*vector1.x) + (vector1.y*vector1.y) + (vector1.z*vector1.z));
	return out;
}

struct vec3d splitVector(struct vec3d vector1, double Ni){
	struct vec3d outVec;
	outVec.x = vector1.x/Ni;
	outVec.y = vector1.y/Ni;
	outVec.z = vector1.z/Ni;
	return outVec;
}

struct point3d getPoint(){
	struct point3d outPoint;
	printf("X = ");
	scanf("%lf", &outPoint.x);
	printf("Y = ");
	scanf("%lf", &outPoint.y);
	printf("Z = ");
	scanf("%lf", &outPoint.z);
	printf("\n");
	return outPoint;
}

struct vec3d getL(){
	struct vec3d outVec;
	double Li;
	printf("L = ");
	scanf("%lf", &Li);
	printf("\n");
	outVec.x = Li;
	outVec.y = 0;
	outVec.z = 0;
	return outVec;
}

struct point3d getLstart(struct vec3d vector1){
	struct point3d outPoint;
	outPoint.x = (-1 * vector1.x * 0.5);
	outPoint.y = 0;
	outPoint.z = 0;
	return outPoint;
}

double getN(){
	double out;
	printf("N = ");
	scanf("%lf", &out);
	printf("\n");
	return out;
}

double getI(){
	double out;
	printf("I = ");
	scanf("%lf", &out);
	printf("\n");
	return out;
}

struct vec3d calculateIntegral(struct point3d userPoint, struct point3d Lstart, struct vec3d L, double N, double I){
	
	const double paraU = pow(10,-7);
	struct point3d currentPosition;
	struct vec3d dL = splitVector(L,N);
	struct vec3d R;
	struct vec3d sum;
	sum.x = 0;
	sum.y = 0;
	sum.z = 0;
	struct vec3d out;
	double j;
	for(j = 0; j < N; j++)
	{
		currentPosition.x = Lstart.x + ((1 + (j*2))/2)*dL.x;
		currentPosition.y = Lstart.y + ((1 + (j*2))/2)*dL.y;
		currentPosition.z = Lstart.z + ((1 + (j*2))/2)*dL.z;
		
		R = createVector(currentPosition, userPoint);
		
		printf("X = %.15lf\n",vectorLength(R));
		
		sum.x = sum.x + ((I*crossProduct(dL, R).x) / pow(vectorLength(R),3));
		sum.y = sum.y + ((I*crossProduct(dL, R).y) / pow(vectorLength(R),3));
		sum.z = sum.z + ((I*crossProduct(dL, R).z) / pow(vectorLength(R),3));
	}
	out.x = sum.x * paraU;
	out.y = sum.y * paraU;
	out.z = sum.z * paraU;
	return out;
}

int main(){

	double N;
	double I;
	struct vec3d L;
	struct point3d Lstart;
	struct point3d userPoint;
	struct vec3d output;
	
	N = getN();
	I = getI();
	L = getL();
	Lstart = getLstart(L);
	userPoint = getPoint();
	
	output = calculateIntegral(userPoint, Lstart, L, N, I);
	printf("Vector of magnectic Field at (%lf, %lf,%lf):\n", userPoint.x, userPoint.y, userPoint.z);
	printf("X = %.15lf\n",output.x);
	printf("Y = %.15lf\n",output.y);
	printf("Z = %.15lf\n",output.z);
	

}