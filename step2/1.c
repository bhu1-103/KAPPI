#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char str1[50], str2[50], str3[50];
    printf("now -> ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {input[len - 1] = '\0';}
    sscanf(input, "%49[^,],%49[^,],%49s", str1, str2, str3);
    printf("%s %s %s\n", str1, str2, str3);
    return 0;
}

