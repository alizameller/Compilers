// should return 24
char e;

int main() { 
    int *a;
    *a = g();
    return a;
} 

int g() { 
    int d[6]; 
    int g; 
    g = sizeof(d);
    return g;
}

