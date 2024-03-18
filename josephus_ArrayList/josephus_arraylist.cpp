#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable: 6031)

#include"arraylist.h"
#include<iostream>

using namespace std;

int main() {
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);
	ArrayList<int> list = ArrayList<int>(n);
	for (int i = 0;i < n;i++) {
		list.appendValue(i + 1);
	}
	int cnt, pos, out;
	pos = s;
	int m1;
	while (list.length() > 1) {
		cnt = 1;
		if (m > list.length()) {
			m1 = m % list.length();
			if (m1 == 0) m1 = list.length();
		}
		else m1 = m;
		while (cnt < m1) {
			cnt++;
			if (pos == list.length()) {
				pos = 1;
			}
			else pos++;
		}
		list.getValue(pos - 1, out);
		printf("%d ", out);
		list.deleteValue(pos - 1);
		if (pos > list.length()) pos = 1;
	}
	list.getValue(0, out);
	printf("%d ", out);
	return 0;
}