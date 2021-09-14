string kangaroo(int x1, int v1, int x2, int v2) {
    if(v1-v2 != 0 && (x2-x1)/(v1-v2) > 0 && (x2-x1)%(v1-v2)==0) return "YES";
    else return "NO";
}
