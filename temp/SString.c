#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define MAXSTRLEN 255

typedef unsigned char SString[MAXSTRLEN+1];

int StrAssign (SString T, char* chars) {
    T[0] = strlen(chars);
    for (int i=1; i<=T[0]; i++) {
        T[i] = chars[i-1];
    }
    T[T[0]+1] = '\0';
    return TRUE;
}

int StrCopy (SString T, SString S) {
    for (int i=0; i<=S[0]+1; i++) {
        T[i] = S[i];
    }
    return TRUE;
}

int StrEmpty (SString S) {
    if (S[0] == 0) return 1;
    else return 0;
}

int StrCompare (SString S, SString T) {
    for (int i=1; i<S[0]&&i<T[0]; i++) {
        if (S[i] != T[i]) return S[i] - T[i];
    }
    return S[0] - T[0];
}

int StrLength (SString S) {
    return S[0];
}

void ClearString (SString S) {
    S[0] = 0;
}

void Concat (SString T, SString S1, SString S2) {
    for (int i=1; i<=S1[0]; i++) {
        T[i] = S1[i];
    }
    for (int i=1; i<=S2[0]+1; i++) {
        T[i+S1[0]] = S2[i];
    }
    T[0] = S1[0] + S2[0];
}

int SubString (SString Sub, SString S, int pos, int len) {
    if (StrEmpty(S)) return 0;
    Sub[0] = len;
    for (int i=1; i<=len; i++) {
        Sub[i] = S[pos+i-1];
    }
    Sub[Sub[0]+1] = '\0';
    return 1;
}

int StrInsert (SString S, int pos, SString T) {
    int len_s = StrLength(S), len_t = StrLength(T);
    if (StrLength(S) + StrLength(T) >= 255) return 0;
    for (int i = len_s+len_t; i>=len_t+pos; i--) {
        S[i] = S[i-len_t];
    }
    for (int i=pos; i<pos+len_t; i++) {
        S[i] = T[i-pos+1];
    }
    S[0] = len_s+len_t;
    S[S[0]+1] = '\0';
    return 1;
}

int StrDelete (SString S, int pos, int len) {
    int len_move = StrLength(S) - len - pos + 1;
    for (int i=pos; i<=len_move; i++) {
        S[i] = S[i+len];
    }
    S[0] = StrLength(S) - len;
    S[S[0]+1] = '\0';
}

int main()
{
    SString S1, S2, T, P;
    StrAssign(S1, "HELLOworld");
    StrAssign(P, "XXX");
    StrCopy(S2,S1);
    SubString(T, S1, 2, 4);
    StrDelete(S1, 1, 5);
    return 0;
}
