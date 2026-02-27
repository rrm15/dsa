#include <stdio.h>
#include <string.h>

int main() {
  char myParagraph[2000];
  char wordList[100][50];
  int wordCount[100];
  int totalUniqueWords = 0;
  int i, j;

  printf("Enter a paragraph: ");
  fgets(myParagraph, 2000, stdin);

  int paraLen = strlen(myParagraph);
  if (myParagraph[paraLen - 1] == '\n')
    myParagraph[paraLen - 1] = '\0';

  char currentWord[50];
  int charIdx = 0;
  i = 0;

  while (myParagraph[i] != '\0') {
    if (myParagraph[i] != ' ' && myParagraph[i] != '\t') {
      currentWord[charIdx] = myParagraph[i];
      charIdx++;
    } else {
      if (charIdx > 0) {
        currentWord[charIdx] = '\0';

        int foundAt = -1;
        for (j = 0; j < totalUniqueWords; j++) {
          if (strcmp(wordList[j], currentWord) == 0) {
            foundAt = j;
            break;
          }
        }

        if (foundAt != -1) {
          wordCount[foundAt]++;
        } else {
          strcpy(wordList[totalUniqueWords], currentWord);
          wordCount[totalUniqueWords] = 1;
          totalUniqueWords++;
        }
        charIdx = 0;
      }
    }
    i++;
  }

  if (charIdx > 0) {
    currentWord[charIdx] = '\0';
    int foundAt = -1;
    for (j = 0; j < totalUniqueWords; j++) {
      if (strcmp(wordList[j], currentWord) == 0) {
        foundAt = j;
        break;
      }
    }
    if (foundAt != -1) {
      wordCount[foundAt]++;
    } else {
      strcpy(wordList[totalUniqueWords], currentWord);
      wordCount[totalUniqueWords] = 1;
      totalUniqueWords++;
    }
  }

  printf("\nWord Frequencies:\n");
  for (i = 0; i < totalUniqueWords; i++) {
    printf("%-20s : %d\n", wordList[i], wordCount[i]);
  }

  return 0;
}
