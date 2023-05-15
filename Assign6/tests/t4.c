int f() {
    int a;
    int b;
    if (a == 2) {
        return a;
    } else {
        return b;
    }
}

int g() {
    int a; 
    if (a == 2) {
       f();
    }
}

int main() {
    f();
}


