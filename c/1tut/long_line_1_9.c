#include <stdio.h>

#define NUL '\0'
#define MAXCHAR 100
#define MAXLINE 4
#define TABSTOP 4
#define IN 1
#define OUT 0

int lineCnt(char line[]);
void copy(char from[], char to[]);
void trailRemove(char line[]);
void reverseLine(char line[]);
/* in for deTab and enTab, inplace version is better? NO */
void deTab(char line[]);
void enTab(char line[]);
void longCut(char line[]);
void printLine(char line[], char * note);

int main(int argc, char *argv[])
{
    char char_in;
    char line[MAXCHAR];
    char max_line[MAXCHAR];
    int i = 0;
    int cnt = 0;
    int max_cnt = -1;

    while ((char_in = getchar()) != EOF) {
        line[i++] = char_in;
        if (char_in == '\n') {
            line[--i] = NUL; // '\n' -> NUL
            i = 0;
            //printLine(line, "origin");
            //trailRemove(line);
            //printLine(line, "remove tail");
            longCut(line);
            printLine(line, "long cut");
            //deTab(line);
            //printLine(line, "detab");
            //enTab(line);
            //printLine(line, "entab");
            //reverseLine(line);
            //printLine(line, "reverse");
            cnt = lineCnt(line);
            if (cnt > max_cnt) {
                max_cnt = cnt;
                copy(line, max_line);
                printf("max_line:\n%s\n", max_line);
            }
        }
    }
    printf("max: %d\n", max_cnt);
    printf("max_line: %s\n", max_line);
    return 0;
}

void printLine(char line[], char * note)
{
    printf("%s:\n", note);
    int i = 0;
    while(line[i] != NUL) {
        if(line[i] == ' ')
            printf("\\s");
        else if(line[i] == '\t')
            printf("\\t");
        else if(line[i] == '\n') {
            printf("\\n");
            printf("\n");
        } else
            printf("%c", line[i]);
        i++;
    }
    printf("\n");
}
void reverseLine(char line[])
{
    int i = 0;
    int cnt = 0;
    char swap_tmp;
    cnt = lineCnt(line); // do not swap the last NUL
    for(i=0; i<cnt/2; i++){
        swap_tmp = line[i];
        line[i] = line[cnt-1-i]; // start from zero
        line[cnt-1-i] = swap_tmp;
    }
    return;
}
void trailRemove(char line[])
{
    int i = 0;
    int mark = -1; // in case NUL line
    while(line[i] != NUL) {
        if((line[i] != ' ') && (line[i] != '\t'))
            mark = i;
        i++; 
    }
    line[mark+1] = NUL;
}
int lineCnt(char line[])
{
    int i = 0;
    while(line[i] != NUL) {
        i++;
    };
    return i;
}
void copy(char from[], char to[])
{
    int i = 0;
    while(from[i] != NUL) {
        to[i] = from[i];
        i++;
    }
    to[i] = NUL; /* NULL char!!! */
    return;
}
void deTab(char line[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    char line_copy[MAXCHAR];// *4 for the corner
    copy(line, line_copy);
    while(line_copy[i] != NUL) {
        if(line_copy[i] == '\t') {
            for(j = 0; j<TABSTOP; j++) {
                line[k++] = ' ';
            }
        } else {
            line[k++] = line_copy[i];
        }
        i++;
    }
    line[k] = NUL;
    return;
}
void enTab(char line[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    char line_copy[MAXCHAR];// *4 for the corner
    copy(line, line_copy);
    while(line_copy[i] != NUL) {
        if(line_copy[i] == ' ') {
            j++;
            if(j == TABSTOP) {
                line[k++] = '\t';
                j = 0;
            }
        } else {
            for(l=0; l<j; l++) {
                line[k++] = ' ';
            }
            line[k++] = line_copy[i];
            j = 0;
        }
        i++;
    }
    line[k] = NUL;
    return;
}
void longCut(char line[])
{
    int i = 0;
    int last_s_mark = 0;//space
    int last_l_mark = 0;//line end
    int k = 0;
    int offset = 0;
    int char_num = 0;
    int flag = 0;       // 0:all char 1:get ' ' 2:get NUL
    if (lineCnt(line) < MAXLINE) {
        return;
    }
    char line_copy[MAXCHAR];// *4 for the corner
    copy(line, line_copy);
    while(1) {
        flag = 0;
        for(i=last_l_mark; i<last_l_mark+MAXLINE; i++) {
            if(line_copy[i] == ' ') {
                last_s_mark = i;
                flag = 1;
            } else if(line_copy[i] == NUL) {
                last_s_mark = i;
                flag = 2;
                break;
            }
        }
        if (flag==0) { // no ' ' and NUL
            last_s_mark = i;
        }
        if(flag == 0) {
            last_l_mark = i;
            line[offset+i] = '\n';
            for(k=0; k<MAXLINE; k++) {
                i--;
                line[offset+i] = line_copy[i];
            }
            offset++;
        } else {
            char_num = last_s_mark-last_l_mark;
            if (flag == 2) {
                line[offset+last_s_mark] = NUL;
            } else {
                last_l_mark = last_s_mark + 1; // +1 for space
                line[offset+last_s_mark] = '\n';
            }
            for(k=0; k<char_num; k++) {
                last_s_mark--;
                line[offset+last_s_mark] = line_copy[last_s_mark];
            }
        }
        if(flag == 2) {
            break;
        }
    }
    return;
}
