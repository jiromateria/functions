#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


unsigned int puts(char* str);
char* strchr(const char* cs, int c);
unsigned int strlen(const char* cs);
char* strcpy(char* s, const char* cs);
char* strncpy(char* s, const char* ct, size_t n);
char* strcat(char* s, const char* ct);
char* strncat(char* s, const char* ct, size_t n);
//char* fgets(char* line, int maxline, FILE *fp);
char* strdup(char* s);
int getline(char s[], int lim);


int main()
{
    char s1[20] = "812LOL";
    char s2[20] = "5233q";
    puts(s1);
    char k = '8';
    printf("%d\n", *strchr(s1, k));
    printf("%d",strlen(s1));
    printf("\n");
    char* s3 = strcpy(s1,s2);
    puts(s3);
    s3 = strncpy(s1, s2, 4);
    puts(s3);
    s3 = strcat(s1, s2);
    puts(s3);
    char s4[40] = "qqqqq";
    s3 = strncat(s4, s2, 4);
    puts(s3);

    char* s5 = fgets(s3,40, stdin);
    puts(s5);


    return 0;
}

unsigned int puts(char* str)
{
    assert(str != NULL);

    return printf("%s\n", str);

}

char* strchr(const char* cs, int c)
{
    assert(cs != NULL);

    int i = 0;
    while(cs[i] != '\0')
    {
        if(cs[i] == c)
            return (char*)&cs[i];
    }
    return NULL;
}

unsigned int strlen(const char* cs)
{
    assert(cs != NULL);

    int i = 0;
    while(cs[i] != '\0')
        i++;
    return i;
}

char* strcpy(char* s, const char* ct)
{
    assert(s != NULL);
    assert(ct != NULL);

    int i = 0;

    if(strlen(s) < strlen(ct))
        return NULL;
    while(ct[i] != '\0')
    {
        s[i] = ct[i];
        i++;
    }

    s[i] = '\0';
    return s;
}

char* strncpy(char* s, const char* ct, size_t n)
{
    assert(s != NULL);
    assert(ct != NULL);

    if(strlen(s) < strlen(ct))
        return NULL;
    size_t t = 0;
    while(t < n && *(ct + t) != '\0')
    {
        *(s + t) = *(ct+t);
        t++;
    }
    *(s + t) = '\0';
    return s;

}

char* strcat(char* s, const char* ct)
{
    assert(s != NULL);
    assert(ct != NULL);

    size_t Slenght = strlen(s);
    size_t i = 0;
    while(ct[i] != '\0')
    {
        s[Slenght + i] = ct[i];

        i++;
    }

    s[Slenght + i] = '\0';

    return s;
}

char* strncat(char* s, const char* ct, size_t n)
{
    assert(s != NULL);
    assert(ct != NULL);

    size_t Slenght = strlen(s);
    size_t i = 0;
    while( i < n && ct[i] != '\0')
    {
        s[Slenght + i] = ct[i];

        i++;
    }

    s[Slenght + i] = '\0';

    return s;
}

/*char* fgets(char* line, int maxline, FILE *fp)
{
    assert( line != NULL);

    int i = 0;

    while( line[i] != '\n' && i < maxline - 1)
    {
        fscanf(fp , "%c", line[i]);
        i++;
    }
    line[i] = '\n';

    return line;
}*/

char* strdup(char* s)
{
    char* scopy = (char*)malloc(strlen(s)+1);
    if(scopy != NULL)
        strcpy(scopy, s);
    return scopy;
}

int getline(char s[], int lim)
{
    int ch = 0, i = 0;
    while (--lim > 0 && (ch = getchar()) != EOF && ch != '\n' )
        s[i++] = (char)ch;
    if (ch == '\n')
        s[i++] = (char)ch;

    s[i] = '\0';
    return i;
}





