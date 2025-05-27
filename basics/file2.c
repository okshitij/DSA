#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[50];
  int roll;
  float marks;
};

int main() {
  struct student s;
  FILE *file;

  file = fopen("studentinfo.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
while (fscanf(file, "Name: %s\nRollno: %d\nMarks: %f\n", s.name, &s.roll, &s.marks) != EOF) {
    printf("Name: %s\n", s.name);
    printf("Rollno: %d\n", s.roll);
    printf("Marks: %.2f\n", s.marks);
    printf("\n");
  }

  fclose(file);

  return 0;
}

