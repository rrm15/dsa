#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int totalCities, i, j;

  printf("Enter number of cities: ");
  scanf("%d", &totalCities);
  getchar();

  char *cityNames[100];

  for (i = 0; i < totalCities; i++) {
    cityNames[i] = (char *)malloc(100 * sizeof(char));
    printf("Enter city %d: ", i + 1);
    fgets(cityNames[i], 100, stdin);
    int myLen = strlen(cityNames[i]);
    if (cityNames[i][myLen - 1] == '\n')
      cityNames[i][myLen - 1] = '\0';
  }

  for (i = 0; i < totalCities - 1; i++) {
    for (j = 0; j < totalCities - i - 1; j++) {
      if (strcmp(cityNames[j], cityNames[j + 1]) > 0) {
        char *tempCity = cityNames[j];
        cityNames[j] = cityNames[j + 1];
        cityNames[j + 1] = tempCity;
      }
    }
  }

  printf("\nCities in alphabetical order:\n");
  for (i = 0; i < totalCities; i++) {
    printf("%s\n", cityNames[i]);
  }

  for (i = 0; i < totalCities; i++) {
    free(cityNames[i]);
  }
  printf("\nMemory freed successfully\n");

  return 0;
}
