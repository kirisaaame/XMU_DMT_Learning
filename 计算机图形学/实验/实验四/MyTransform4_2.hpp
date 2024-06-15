#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>
using namespace std;
#define PI 3.1415927

extern Eigen::Matrix4f mModelView;
extern Eigen::Matrix4f mProjection;
extern Eigen::Matrix4f mViewPort;


void Test()
{
	//矩阵用法
	Eigen::Matrix4f m;
	m.setZero();
	m(0, 0) = 1;
	m(3, 3) = 1;
	m(1, 1) = 2.3;   m(1, 2) = 0.99;
	m(2, 1) = 1.1;   m(2, 2) = 0;
	cout << "Matrix:" << endl;
	cout << m << endl;

	//向量用法
	Eigen::Vector4f v;
	v[0] = 1.0;
	v[1] = 2.0;
	v[2] = 3.0;
	v[3] = 1.0;
	//v[4] = 1.0;
	v.normalize();//归一化

	//输出矩阵与向量相乘的结果
	cout << "result:" << endl;
	cout << m * v << endl;
}

vector<Eigen::Vector3f> VertexTransform(vector<Eigen::Vector3f> vertices)
{
	vector<Eigen::Vector3f> rlt(vertices.size());
	Eigen::Vector4f v;

	Eigen::Matrix4f M = mViewPort * mProjection * mModelView;

	for (int i = 0; i < vertices.size(); ++i)
	{
		v[3] = 1.0;
		v.head<3>() = vertices[i];

		v = M * v;
		rlt[i][0] = v[0] / v[3];
		rlt[i][1] = v[1] / v[3];
		rlt[i][2] = v[2] / v[3];
	}
	return rlt;
}

Eigen::Matrix4f myLookAt(float ex, float ey, float ez, float atx, float aty, float atz, float upx, float upy, float upz)
{
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面空白处完成此函数
	
	m.setIdentity();//这句应该去掉

	Eigen::Vector3f eye(ex, ey, ez);
	Eigen::Vector3f at(atx, aty, atz);
	Eigen::Vector3f up(upx, upy, upz);

	Eigen::Vector3f zaxis = (eye - at).normalized();
	Eigen::Vector3f xaxis = up.cross(zaxis).normalized();
	Eigen::Vector3f yaxis = zaxis.cross(xaxis);

	m.block<3, 3>(0, 0) << xaxis, yaxis, zaxis;
	m.block<3, 1>(0, 3) = -m.block<3, 3>(0, 0) * eye;
	//请在上面空白处完成此函数

	mModelView *= m;
	return m;
}

Eigen::Matrix4f myRotateX(float angle)
{
	float theta = angle / 180.0 * PI;
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面粘贴上次实验的代码

	//m.setIdentity();//这句应该去掉
	m(0, 0) = 1;
	m(1, 1) = cos(theta);
	m(1, 2) = -sin(theta);
	m(2, 1) = sin(theta);
	m(2, 2) = cos(theta);
	m(3, 3) = 1;

	//请在上面粘贴上次实验的代码

	mModelView *= m;
	return m;
}

Eigen::Matrix4f myRotateY(float angle)
{
	float theta = angle / 180.0 * PI;
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面粘贴上次实验的代码

	//m.setIdentity();//这句应该去掉
	m(0, 0) = cos(theta);
	m(0, 2) = sin(theta);
	m(1, 1) = 1;
	m(2, 0) = -sin(theta);
	m(2, 2) = cos(theta);
	m(3, 3) = 1;

	//请在上面粘贴上次实验的代码

	mModelView *= m;
	return m;
}

Eigen::Matrix4f myRotateZ(float angle)
{
	float theta = angle / 180.0 * PI;
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面粘贴上次实验的代码

	//m.setIdentity();//这句应该去掉
	m(0, 0) = cos(theta);
	m(0, 1) = -sin(theta);
	m(1, 0) = sin(theta);
	m(1, 1) = cos(theta);
	m(2, 2) = 1;
	m(3, 3) = 1;

	//请在上面粘贴上次实验的代码

	mModelView *= m;
	return m;
}


Eigen::Matrix4f myTranslate(float x, float y, float z)
{
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面粘贴上次实验的代码

	m.setIdentity();//这句应该去掉
	m(0, 3) = x;
	m(1, 3) = y;
	m(2, 3) = z;

	//请在上面粘贴上次实验的代码

	mModelView *= m;
	return m;
}

Eigen::Matrix4f myRotate(float angle, float x, float y, float z)
{
	float theta = angle / 180.0 * PI;

	Eigen::Matrix4f m;

	//请在下面粘贴上次实验的代码

	m.setIdentity();//这句应该去掉
	Eigen::Vector3f axis(x, y, z);
	axis.normalize();

	Eigen::Matrix3f I = Eigen::Matrix3f::Identity();
	Eigen::Matrix3f axis_skew;
	axis_skew << 0, -axis.z(), axis.y(),
		axis.z(), 0, -axis.x(),
		-axis.y(), axis.x(), 0;

	Eigen::Matrix3f R = cos(theta) * I + sin(theta) * axis_skew + (1 - cos(theta)) * (axis * axis.transpose());

	m.block<3, 3>(0, 0) = R;

	//请在上面粘贴上次实验的代码

	mModelView *= m;

	return m;
}

Eigen::Matrix4f myFrustum(float l, float r, float b, float t, float n, float f)
{
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面空白处完成此函数
	
	//m.setIdentity();//这句应该去掉
	m(0, 0) = 2 * n / (r - l);
    m(0, 2) = (r + l) / (r - l);
    m(1, 1) = 2 * n / (t - b);
    m(1, 2) = (t + b) / (t - b);
    m(2, 2) = -(f + n) / (f - n);
    m(2, 3) = -2 * f * n / (f - n);
    m(3, 2) = -1;
	//请在上面空白处完成此函数

	mProjection *= m;
	return m;
}

Eigen::Matrix4f myOrtho(float l, float r, float b, float t, float n, float f)
{
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面空白处完成此函数

	m.setIdentity();//这句应该去掉
	m(0, 0) = 2 / (r - l);
	m(0, 3) = -(r + l) / (r - l);
	m(1, 1) = 2 / (t - b);
	m(1, 3) = -(t + b) / (t - b);
	m(2, 2) = -2 / (f - n);
	m(2, 3) = -(f + n) / (f - n);

	//请在上面空白处完成此函数

	mProjection *= m;

	return m;
}

Eigen::Matrix4f myViewPort(float x, float y, float w, float h)
{
	Eigen::Matrix4f m;
	m.setZero();

	//请在下面空白处完成此函数

	m.setIdentity();
	//下面这段代码应该删掉
	m(0, 0) = w / 2;
	m(1, 1) = h / 2;
	m(0, 3) = x + w / 2;
	m(1, 3) = y + h / 2;
	m(2, 2) = 0.5;
	m(2, 3) = 0.5;
	//上面这段代码应该删掉

	//请在上面空白处完成此函数

	mViewPort = m;

	return m;
}

Eigen::Matrix4f myPerspective(float fovy, float aspect, float zNear, float zFar)
{
	Eigen::Matrix4f m;
	m.setZero();
	const float pi = 3.1415926535897932384626433832795;

	//请在下面空白处完成此函数

	//m.setIdentity();//这句应该去掉
	float tanHalfFovy = tan(fovy / 2.0 * PI / 180.0);

	m(0, 0) = 1.0 / (aspect * tanHalfFovy);
	m(1, 1) = 1.0 / tanHalfFovy;
	m(2, 2) = (zFar + zNear) / (zFar - zNear);
	m(2, 3) = -(2.0 * zFar * zNear) / (zFar - zNear);
	m(3, 2) = 1.0;
	//请在上面空白处完成此函数

	mProjection *= m;
	return m;
}