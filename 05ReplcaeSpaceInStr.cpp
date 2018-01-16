#include <iostream>

void replaceSpace(char* s, int max_len) {
	int str_len = 0;
	int space_num = 0;
	while (*s != '\0') {
		if (*s == ' ')
			space_num++;
		str_len++;
		s++;
	}
	str_len++;
	if ((str_len + space_num * 2) > max_len)
		return;

	char* s2 = s + space_num * 2;
	int pos = str_len;
	while (pos >= 0) {
		pos--;
		if (*s != ' ')
			*(s2--) = *(s--);
		else {
			*(s2--) = '0';
			*(s2--) = '2';
			*(s2--) = '%';
			s--;
		}
	}
	return;
}

void test() {
	char str[25] = "i have a dream";
	std::cout << sizeof(str) / sizeof(str[0]);
	replaceSpace(str, 25);
	printf("%s", str);
	return ;
}
int main() {
	test();
	return 0;
}
