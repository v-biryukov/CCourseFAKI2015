#include <iostream>
#include <cmath>
#include "vec.h"
#include "stb_image_write.h"

#define PI 3.14159265358979323846

using namespace std;

struct Color
{
	unsigned char r, g, b;
};


struct Ray
{
	vec3 origin;
	vec3 direction;
};

int check_if_ray_intersects_sphere(Ray ray, vec3 sphere_position, float sphere_radius, 
									vec3 light_position, float& value)
{
	vec3 a = ray.origin;
	vec3 d = ray.direction;
	vec3 s = sphere_position;
	vec3 m = s - a;
	float R = sphere_radius;

	float D = (m*d)*(m*d) - d*d * (m*m - R*R);
	

	if (D > 0)
	{
		float t1 = (m*d - sqrt(D)) / (d*d);
		vec3 p = a  + t1 * d;

		vec3 n = (p - s) / norm(p - s);
		vec3 l = light_position;

		value = (((l-p)*n) * n) * (a-p) / (norm(l-p) * norm(a-p));

		if (value < 0)
			value = 0;
		return 1;
	}
	else
	{
		value = 0;
		return 0;
	}
}


int main()
{
	vec3 sphere_position = {0, 0, 0};
	vec3 camera_position = {0, 0, 1};
	vec3 camera_direction = {0, 0, -1};
	float sphere_radius = 0.3;

	vec3 light_position = {2, 2, 2};

	vec3 light_positions[3] = {{2, 2, 2}, {-2, 2, 2}, {0, 2, 2}};
	Color light_colors[3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};

	int width = 500;
	int height = 500;
	Color* data = (Color*)malloc(sizeof(Color) * width * height);
	
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			vec3 offset = {-1.0 + 2.0 * i / height, -1.0 + 2.0 * j / width};
			Ray ray = {camera_position, camera_direction + offset};
			float values[3];
			int c[3];
			c[0] = check_if_ray_intersects_sphere(ray, sphere_position, sphere_radius, light_positions[0], values[0]);
			c[1] = check_if_ray_intersects_sphere(ray, sphere_position, sphere_radius, light_positions[1], values[1]);
			c[2] = check_if_ray_intersects_sphere(ray, sphere_position, sphere_radius, light_positions[2], values[2]);
			
			int r = 0, g = 0, b = 0;
			if (c[0] || c[1] || c[2])
			{
				for (int light_id = 0; light_id < 3; ++light_id)
				{
					r += values[light_id] * light_colors[light_id].r;
					g += values[light_id] * light_colors[light_id].g;
					b += values[light_id] * light_colors[light_id].b;
				}
				if (r > 255)
					r = 255;
				if (g > 255)
					g = 255;
				if (b > 255)
					b = 255;
			}

			data[i * width + j].r = r;
			data[i * width + j].g = g;
			data[i * width + j].b = b;
		}


	


	/*
	FILE* file = fopen("rays.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);
	*/

	stbi_write_jpg("res.jpg", width, height, 3, (unsigned char*)data, 90);

	
	for (int k = 0; k < 500; ++k)
	{
		float alpha = k * 0.02;
		light_positions[0] = {sin(alpha), cos(2*alpha), sin(7*alpha + 3.14/4)};
		light_positions[1] = {sin(3*alpha), cos(6*alpha), sin(5*alpha + 3.14/4)};
		light_positions[2] = {sin(11*alpha), cos(3*alpha), sin(8*alpha + 3.14/4)};
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < width; ++j)
			{
				vec3 offset = {-1.0 + 2.0 * i / height, -1.0 + 2.0 * j / width};
				Ray ray = {camera_position, camera_direction + offset};
				float values[3];
				int c[3];
				c[0] = check_if_ray_intersects_sphere(ray, sphere_position, sphere_radius, light_positions[0], values[0]);
				c[1] = check_if_ray_intersects_sphere(ray, sphere_position, sphere_radius, light_positions[1], values[1]);
				c[2] = check_if_ray_intersects_sphere(ray, sphere_position, sphere_radius, light_positions[2], values[2]);
				
				int r = 0, g = 0, b = 0;
				if (c[0] || c[1] || c[2])
				{
					for (int light_id = 0; light_id < 3; ++light_id)
					{
						r += values[light_id] * light_colors[light_id].r;
						g += values[light_id] * light_colors[light_id].g;
						b += values[light_id] * light_colors[light_id].b;
					}
					if (r > 255)
						r = 255;
					if (g > 255)
						g = 255;
					if (b > 255)
						b = 255;
				}

				data[i * width + j].r = r;
				data[i * width + j].g = g;
				data[i * width + j].b = b;
			}


		char image_name[50];
		sprintf(image_name, "result/img%03d.jpg", k);

		stbi_write_jpg(image_name, width, height, 3, (unsigned char*)data, 90);
	}
	






	free(data);
}

