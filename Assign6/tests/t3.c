// should return 0
int f() {
    int a;
    int b;
    b = 0;
    a = 3;
    if (a == 2) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int a; 
    a = 2;
    if (a == 2) {
       return f();
    }
}

