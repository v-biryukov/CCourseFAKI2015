typedef struct _vec
{
	float x;
	float y;
	float z;
} vec;

void init_v3(vec * p, int x, int y, int z);
vec add(vec v, vec u);
float scalar_product(vec v, vec u);
float len(vec v);
void read(vec * pv);
void print(vec pv);
