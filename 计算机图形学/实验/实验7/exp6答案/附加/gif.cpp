#include <Eigen/Core>
#include "ppm.hpp"
#include "camera.hpp"
#include "raytracer.hpp"
#include <windows.h>
#include <vector>
#include <iostream>
#include <Magick++.h>
using namespace Magick;
using namespace std;
vector<PPM> ppm_list;
int n = 150, cnt = 0;//cntΪ���ĵ�������
int width = 640, height = 480;
PPM pre_ppm(width, height), pre_pre_ppm(width, height);
void make_frame(float h, int ii)
{
	PPM outrlt(width, height);
	Camera cam;
	Scene world;
	Sphere sp1(Vector3f(0, h, -2), 1.0);
	Sphere sp2(Vector3f(0, -10000.5, -2), 10000.0);
	Sphere sp3(Vector3f(-2.0, 0, -2), 0.5);
	Sphere sp4(Vector3f(1.0, -0.2, -1.0), 0.3);
	Sphere sp5(Vector3f(3.0, 0, -2.2), 0.4);
	Sphere sp6(Vector3f(-1, 0.0, -0.8), 0.2);

	Material mtl, mtl2, mtl3, mtl4, mtl5;//mLx
	mtl.SetKa(Vector3f(0.5, 0.5, 0.5));//���Ļ�ɫС��
	mtl.SetKd(Vector3f(0.8, 0.6, 0.0));
	mtl.SetKs(Vector3f(0.7, 0.8, 0.8));
	mtl.SetTransparent(false);
	mtl.SetReflective(true);
	mtl.SetShiness(50);

	mtl2.SetKa(Vector3f(0.5, 0.5, 0.5));//Ӧ���ǿ�������
	mtl2.SetKd(Vector3f(0.0, 0.6, 0.2));
	mtl2.SetKs(Vector3f(0.1, 1.0, 0.8));
	mtl2.SetTransparent(false);
	mtl2.SetReflective(false);
	mtl2.SetShiness(10);

	mtl3.SetKa(Vector3f(0.5, 0.5, 0.5));//��ɫС��
	mtl3.SetKd(Vector3f(0.0, 0.3, 0.6));
	mtl3.SetKs(Vector3f(0.0, 0.0, 0.0));
	mtl3.SetTransparent(false);
	mtl3.SetReflective(false);
	mtl3.SetShiness(10);

	mtl4.SetKa(Vector3f(0.1, 0.1, 0.1));//�Ҳ��ɫС��
	mtl4.SetKd(Vector3f(0.0, 0.0, 0.0));
	mtl4.SetKs(Vector3f(0.0, 0.0, 0.0));
	mtl4.SetTransparent(true);
	mtl4.SetReflective(false);
	mtl4.SetRefraction(1.33);
	mtl4.SetShiness(200);

	mtl5.SetKa(Vector3f(0.5, 0.5, 0.5));//�Ҳ��ɫС��
	mtl5.SetKd(Vector3f(0.75, 0.56, 0.0));
	mtl5.SetKs(Vector3f(0.75, 0.56, 0.0));
	mtl5.SetTransparent(false);
	mtl5.SetReflective(false);
	mtl5.SetRefraction(1.33);
	mtl5.SetShiness(100);

	world.Insert(make_pair(sp1, mtl));
	world.Insert(make_pair(sp2, mtl2));
	world.Insert(make_pair(sp3, mtl3));
	world.Insert(make_pair(sp4, mtl4));
	world.Insert(make_pair(sp5, mtl5));

	for (int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			bool test = false;
			//���ɹ���
			float u = float(i) / float(width);
			float v = float(j) / float(height);
			Ray ray = cam.GenerateRay(u, v);
			Vector3f color = RayColor(ray, world, test);

			if (ii == 0)
			{
				outrlt.SetPixel(j, i, int(255.99 * color[0]), int(255.99 * color[1]), int(255.99 * color[2]));
			}
			else if (ii == 1)
			{
				unsigned r, g, b;
				float k = 0.7;
				pre_ppm.GetPixel(j, i, r, g, b);
				outrlt.SetPixel(j, i, int(k * 255.99 * color[0] + (1 - k) * r),
					int(k * 255.99 * color[1] + (1 - k) * g),
					int(k * 255.99 * color[2] + (1 - k) * b));
			}
			else
			{
				unsigned r1, g1, b1;
				unsigned r2, g2, b2;
				float k1 = 0.7, k2 = 0.0, k3 = 0.3;
				pre_ppm.GetPixel(j, i, r1, g1, b1);
				pre_pre_ppm.GetPixel(j, i, r2, g2, b2);
				outrlt.SetPixel(j, i, int(k1 * 255.99 * color[0] + k2 * r1 + k3 * r2),
					int(k1 * 255.99 * color[1] + k2 * g1 + k3 * g2),
					int(k1 * 255.99 * color[2] + k2 * b1 + k3 * b2));
			}
		}
	}
	pre_pre_ppm = pre_ppm;
	pre_ppm = outrlt;
	char path[50];
	sprintf(path, "./Frame//frame%d.ppm", ii);
	outrlt.Write2File(path);
}

int main()
{
	system("rd /s /q Frame");
	system("md Frame");
	float h = 4.0f, g = -0.0098f, v = 0, x = 0, k = 0.6;//kΪ����ϵ��
	for (int i = 0; i <= n; ++i)
	{
		if (cnt <= 8)
		{
			x += v + 1.0 / 2 * g;
			v += g;
			if (x + h < 0.5)
			{

				v = -k * v; cnt++;
			}
		}
		make_frame(x + h, i);

		cout << "Frame " << i << " finished" << endl;
	}
	cout << "Waiting for Gif" << endl;
	vector<Image> frames;
	for (int i = 0; i < n; ++i)
	{
		char path[50];
		sprintf(path, "Frame//frame%d.ppm", i);
		Image image(path);
		frames.push_back(image);
	}

	for (int i = 0; i < frames.size(); i++) {
		frames[i].animationDelay(5);
	}

	string output_file = "outputgif.gif";
	writeImages(frames.begin(), frames.end(), output_file);
	//system("rd /s /q Frame");
	return 0;
}