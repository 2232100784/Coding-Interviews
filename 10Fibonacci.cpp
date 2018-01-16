#include <iostream>
#include <vector>
//递归实现，经实验n=40以上速度就很慢了
long long Fibonacci_recursion(long long n, long long* count){
	*count = *count+1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return (Fibonacci_recursion(n - 1, count) + Fibonacci_recursion(n - 2, count));
}

//第一反应想到的解法，不是最优（维护了额外的栈空间，空间复杂度是n）
long long Fibonacci_stack(long long n){
	if (n < 0)
		return -1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	std::vector<long long> FB;
	FB.push_back(-1);
	FB.push_back(0);
	FB.push_back(1);
	for (int i = 3; i <= n; ++i) {
		FB.push_back(FB[i - 1] + FB[i - 2]);
	}
	return FB[n];
}
//非递归，效率最高
long long Fibonacci(long long n){
	if (n < 0)
		return -1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	long long pre_pre_result = 0;
	long long pre_result = 1;
	long long result = 0;
	for (int i = 3; i <= n; ++i) {
		result = pre_pre_result + pre_result;
		pre_pre_result = pre_result;
		pre_result = result;
	}
	return result;
}

void test1(){
	long long c = 0;
	long long *count = &c;
	long long result1 = Fibonacci_recursion(42, count);
	std::cout << result1 << std::endl;
	std::cout << *count  << std::endl;
}

void test2(){
	long long result2 = Fibonacci_stack(70);
	std::cout << result2 << std::endl;
}

void test3(){
	long long result2 = Fibonacci(8);
	std::cout << result2 << std::endl;
}

int main() {
	//test1();
	//test2();
	test3();
	return 0;
}
