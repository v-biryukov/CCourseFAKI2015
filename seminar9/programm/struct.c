typedef unsigned long long ull;

struct account {
   int account_number;
   char first_name[30];
   char last_name[50];
   float balance;
};

int main()
{
	ull a = 190000000;
	struct account ac1 = {1, "Ivan", "Ivanov", 1000.0};
	printf("%d\n", sizeof(struct account));
	printf("%d\n", ac1.account_number);
	printf("%f\n", ac1.balance);
	ac1.balance += 100;
	printf("%s has %.2f roubles\n", ac1.last_name, ac1.balance);

}
