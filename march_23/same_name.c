void asdf(int x, int x) {
	int y = x;
}

// this is ok:
void f1(int x) {
	// parameter can be accessed by name 'x'
}
void f2(int x) {}

int main() {
	asdf(3, 4);

	return 0;
}
