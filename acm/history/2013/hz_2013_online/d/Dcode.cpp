// testJ.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <math.h>

//空间坐标
struct Point3D
{
	float x;
	float y;
	float z;
};


int ntest;
Point3D s1,e1,s2,e2, v1, v2, v12, vn, o1, o2;
float minDist;

//计算向量的摸
float calLengthVector(Point3D &p)
{
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}

//计算两点距离
float calDistance(Point3D &p1, Point3D &p2)
{
	float x = p1.x-p2.x;
	float y = p1.y-p2.y;
	float z = p1.z-p2.z;

	return sqrt(x*x+y*y+z*z);
}

//计算向量
Point3D calVector(Point3D &start, Point3D &end)
{
	Point3D temp;
	temp.x = end.x - start.x;
	temp.y = end.y - start.y;
	temp.z = end.z - start.z;

	return temp;
}

//计算向量叉集
Point3D calCrossVector(Point3D &p1, Point3D &p2)
{
	Point3D temp;
	temp.x = p1.y*p2.z-p1.z*p2.y;
	temp.y = p1.z*p2.x-p1.x*p2.z;
	temp.z = p1.x*p2.y-p1.y*p2.x;
	return temp;
}

float calMulVector(Point3D &p1, Point3D &p2)
{
	return p1.x*p2.x+p1.y*p2.y+p1.z*p2.z;
}

Point3D calFinalPoint(Point3D p1, float coef, Point3D vec)
{
	Point3D temp;

	temp.x = p1.x + coef*vec.x;
	temp.y = p1.y + coef*vec.y;
	temp.z = p1.z + coef*vec.z;

	return temp;
}

void calMinDist()
{
	v1 = calVector(s1, e1);
	v2 = calVector(s2, e2);
	vn = calCrossVector(v1, v2);
	v12 = calVector(s2, s1);

	float vn_s1_s2 = calMulVector(vn, v12);
	float mol_vn = calLengthVector(vn);
	minDist = fabs(vn_s1_s2)/mol_vn;

	if(fabs(minDist) < 0.000001)
	{
		float y34 = v2.y;
		float x34 = v2.x;
		float x12 = v1.x;
		float y12 = v1.y;
		float x13 = s2.x - s1.x;
		float y13 = s2.y - s1.y;

		if(fabs(x12)<0.000001f && fabs(y12)<0.0000001f)
		{
			o1.x = s1.x;
			o1.y = s1.y;
			//
			if(fabs(v2.x)>0.000001f)
			{
				o1.z = (o1.x-s2.x)*v2.z/v2.x + s2.z;
			}
			else if(fabs(v2.y) > 0.000001f)
			{
				o1.z = (o1.y-s2.y)*v2.z/v2.y + s2.z;
			}
			else if(fabs(v2.z) < 0.000001f)
			{
				o1.z = s2.z;

			}
			o2 = o1;
		}
		else
		{
			float t = (y13*x34-x13*y34)/(x12*y34-y12*x34);
			o1.x = s1.x+t*(-x12);
			o1.y = s1.y+t*(-y12);
			o1.z = s1.z+t*(s1.z-e1.z);
			o2 = o1;
		}
		
	}
	else
	{
		//求交点
		Point3D a1_b1 = calVector(s2, s1);
		Point3D v1_v2 = calCrossVector(v1, v2);
		Point3D v2_a1_b1 = calCrossVector(v2, a1_b1);
		Point3D v1_a1_b1 = calCrossVector(v1, a1_b1);

		float na = calMulVector(v2_a1_b1, v1_v2);
		float nb = calMulVector(v1_a1_b1, v1_v2);
		float d = calMulVector(vn, vn);


		o1 = calFinalPoint(s1, na/d, v1);
		o2 = calFinalPoint(s2, nb/d, v2);
	}

}


void handleProcess()
{

	scanf("%d", &ntest);
	for(int i=0; i<ntest; i++)
	{
		scanf("%f%f%f%f%f%f%f%f%f%f%f%f", &s1.x, &s1.y, &s1.z, 
			&e1.x, &e1.y, &e1.z, &s2.x, &s2.y, &s2.z, &e2.x, &e2.y, &e2.z);
		calMinDist();

		printf("%.6f\n", minDist);
		printf("%.6f %.6f %.6f %.6f %.6f %.6f\n", o1.x,o1.y,o1.z, o2.x,o2.y,o2.z);
	}


}

int main()
{
	handleProcess();
	//float temp = 1;
}

