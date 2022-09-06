#include <stdio.h>

int counter(char *c1, char *c2, int size, int size2) {
    int index = 0, cnt2 = 0, cnt = 0;
    for(int i=0; i<size; ++i) {
        if(c2[index]==c1[i]) {
            ++cnt2;
            if(index!=size2) ++index;
        }
        else if(c2[index]!=c1[i]) {
            cnt2 = 0;
            index = 0;
        }
        if(cnt2==size2) {
            ++cnt;
            cnt2 = 0;
            index = 0;
        }
    }
    return cnt;
}

int size(char *c) {
    int cnt = 0;
    while(*c!='\0') {
        ++cnt;
        ++c;
    }
    return cnt;
}

int main() {

    char str[100];
    char p_str[100];
    scanf("%s %s", str, p_str);

    int s = size(str), s2 = size(p_str);

    int p_cnt = counter(str, p_str, s, s2);

    printf("%d\n", p_cnt);

    return 0;

}