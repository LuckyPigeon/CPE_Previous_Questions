/*
 * Author: @1chooo
 * Title: 10420 - List of Conquests
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361
 * Status: AC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
  char *name;
  int count;
} Country;

int main(void) {
  int lines = 0, i = 0;
  char country[MAX_LEN];
  char tmp[MAX_LEN];

  Country countries[MAX_LEN];

  scanf("%d", &lines);
  getchar();

  for (i = 0; i < lines; i++) {
    scanf("%s", country);
    getchar();

    int j, found = 0;
    for (j = 0; j < i; j++) {
      if (strcmp(countries[j].name, country) == 0) {
        countries[j].count++;
        found = 1;
        break;
      }
    }

    if (!found) {
      countries[i].name = malloc(strlen(country) + 1);
      strcpy(countries[i].name, country);
      countries[i].count = 1;
    }

    fgets(tmp, MAX_LEN, stdin);
  }

  for (i = 0; i < lines; i++) {
    printf("%s %d\n", countries[i].name, countries[i].count);
    free(countries[i].name);
  }

  return 0;
}
