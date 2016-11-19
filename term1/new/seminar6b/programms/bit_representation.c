union ufloat {
  float f;
  unsigned int u;
};

void bin(unsigned int n)
{
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}

int main(void)
{
	printf("Integers: \n");
    bin(1);
    bin(40000000);
    bin(-40000000);
    

    printf("Floats: \n");
    union ufloat u1;
	u1.f = 0.0f;
	bin(u1.u);
	u1.f = 0.5f;
	bin(u1.u);
	u1.f = 40000000.0f;
	bin(u1.u);
	u1.f = -40000000.0f;
	bin(u1.u);
}