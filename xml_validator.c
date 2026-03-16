#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char tag[]) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], tag);
    }
}

int pop(char tag[]) {
    if (top >= 0) {
        strcpy(tag, stack[top]);
        top--;
        return 1;
    }
    return 0;
}

int validateXML(char xml[]) {

    char tag[MAX], temp[MAX];

    for (int i = 0; xml[i] != '\0'; i++) {

        if (xml[i] == '<') {

            i++;

            int closing = 0;

            if (xml[i] == '/') {
                closing = 1;
                i++;
            }

            int j = 0;
            while (xml[i] != '>' && xml[i] != '\0') {
                tag[j++] = xml[i++];
            }
            tag[j] = '\0';

            if (!closing) {
                push(tag);
            } else {
                if (!pop(temp) || strcmp(temp, tag) != 0)
                    return 0; 
            }
        }
    }

    return (top == -1);
}

int main() {

    FILE *file = fopen("note.xml", "r");

    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    char xml[5000];
    int i = 0;

    while ((xml[i] = fgetc(file)) != EOF) {
        i++;
    }

    xml[i] = '\0';

    fclose(file);

    if (validateXML(xml))
        printf("XML is valid\n");
    else
        printf("XML is invalid\n");

    return 0;
}