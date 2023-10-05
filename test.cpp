// reference test

#include <stdio.h>

struct test {
	protected:
		int a;
		int b;
		void add_sum() {
			a = a + b;
			printf("%d\n", a);
		}
};

int main() {
	int a = 1;
	int b = 2;

	test *t = new test();
	
	t->a = a;
	t->b = b;
	t->add_sum();
	return 0;
}