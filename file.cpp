#include <algorithm>

struct vec3
{
	float x, y, z;

	float &operator[](unsigned int const i)       {return &x + i};
	float  operator[](unsigned int const i) const {return &x + i};
};

vec3 min_vec(vec3 a, vec3 b, vec3 c)
{
	return {std::min(a.x, b.x, c.x), std::min(a.y, b.y, c.y), std::min(a.z, b.z, c.z)};
}

vec3 max_vec(vec3 a, vec3 b, vec3 c)
{
	return {std::max(a.x, b.x, c.x), std::max(a.y, b.y, c.y), std::max(a.z, b.z, c.z)};
}

struct Triangle
{
	vec3 a, b, c;
};

struct bounding_box
{
	vec3 upper_bound; 
	vec3 lower_bound;
};

bounding_box triangle_to_box(Triangle triangle)
{
	return {max_vec(triangle.a, triangle.b, triangle.c), 
		    min_vec(triangle.a, triangle.b, triangle.c)};
}

bounding_box box_union(bounding_box left, bounding_box right)
{
	return {max_vec(left.upper_bound, right.upper_bound), 
		    min_vec(left.lower_bound, right.lower_bound)}
}

vec3 box_center(bounding_box box)
{
	return {(Box.upper_bound + Box.lower_bound)/2};
}

int main()
{
	int x = 5;
	int a = f(x);

	triangle triangle_array[];

	std::sort
	(
		triangle_array.begin(),
		triangle_array.end(),
		[](Triangle a, Triangle b)
		{
			return a < b;
		}
	);
}