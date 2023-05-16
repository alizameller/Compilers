// should return 82
int g() {
    int p;
    p = 1;
    return p;
}

void main() { 
    int e;
    int a;
    int f[4][5]; 
    e = sizeof(f);
    e = e + 1; // 81
    a = g();
    a = a + e; 
    return a;
}
