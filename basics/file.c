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

  file = fopen("studentinfo.txt", "w");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  printf("Enter student name: ");
  scanf("%s", s.name);
  printf("Enter student Rollno: ");
  scanf("%d", &s.roll);
  printf("Enter student marks: ");
  scanf("%f", &s.marks);

  fprintf(file, "Name: %s\nRollno: %d\nMarks: %.2f\n", s.name, s.roll, s.marks);

  fclose(file);
  printf("Student information successfully saved to file.\n");

  return 0;
}
