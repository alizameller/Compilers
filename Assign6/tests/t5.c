int g() {
    int p;
    p = 1 + 3;
    return p;
}

void main() { 
    int e;
    int f[4][5]; 
    e = sizeof(f);
    e = e + 1; 
    return g();
}

// should return 4