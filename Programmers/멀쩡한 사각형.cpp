using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
long long solution(int w,int h) {
    long long answer = 1;
    
    long long max = w > h ? w : h;
    long long min = w < h ? w : h;
    long long common = gcd(max, min);
    long long noSquare = w/common + h/common - 1;
    answer = (long long)w * h - noSquare * common;
    return answer;
}
