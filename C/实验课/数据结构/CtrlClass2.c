#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int status;

typedef struct Student {
    char* name;
    int stu_id;
    int score;
}Student, *ptrStuden;

typedef struct Course {
    char* name;
    int cls_id;
    int num_students;
    int size_students;
    ptrStuden students;
}Course, *ptrCourse;

typedef struct Class {
    ptrCourse courses;
    int num_courses;
    int size_courses;
}Class, *ptrClass;

ptrClass InitClass (int size_courses) {
    // 初始化课程组
    ptrClass class = (ptrClass)malloc(sizeof(Class));
    class->size_courses = size_courses; class->num_courses = 0;
    class->courses = (ptrCourse)malloc(sizeof(Course)*size_courses);
    return class;
}

status addCourse (ptrClass class, char* cls_name, int cls_id, int size_students) {
    // 添加课程
    if (class->num_courses = class->size_courses) {
        class->courses = (ptrCourse)realloc(class->courses, 
        (10+class->size_courses)*sizeof(Course));
        class->size_courses += 10;
    }

    for (int i=0; i<class->num_courses; i++) {
        if (class->courses[i].cls_id<cls_id) continue;
        if (class->courses[i].cls_id==cls_id) return FALSE;
        for (int j=class->num_courses; j>i; j--) class->courses[j] = class->courses[j-1];
        class->courses[i].name = cls_name; class->courses[i].cls_id = cls_id; class->courses[i].num_students = 0;
        class->courses[i].students = (ptrStuden)malloc(size_students*sizeof(Student));
        class->courses[i].size_students = size_students;
        return TRUE;
    }
}

status addScore (ptrClass class, char* cls_name, char* stu_name, int stu_id, int score) {
    for (int i=0; i<class->num_courses; i++) {
        if (strcmp(class->courses[i].name, cls_name)) {
            if (class->courses[i].num_students = class->courses[i].size_students) {
                class->courses[i].students = (ptrStuden)realloc(class->courses[i].students
                , (class->courses[i].size_students+10)*sizeof(Student));
                class->courses[i].size_students += 10;
            }
            for (int j=0; j<class->courses[i].num_students; j++) {
                if (class->courses[i].students[j].stu_id < stu_id) continue;
                for (int k=class->courses[i].num_students; k>j; k--) {
                    class->courses[i].students[k] = class->courses[i].students[k-1];
                }
                class->courses[i].students[j].name = stu_name; class->courses[i].students[j].stu_id = stu_id;
                class->courses[i].students[j].score = score;
                return TRUE;
            }
        }
    }
}

// int Screen () {
//     printf("请输入要初始化的课程数：\n");
//     int num = 0; scanf("%d", &num); getchar();
//     ptrClass class = InitClass(num);
//     while (1) {
        
//     }
// }

int main() {
    ptrClass class = InitClass(10);
    addCourse(class, "English", 2, 20);
    addCourse(class, "Math", 4, 30);
    addScore(class, "English", "YJH", 2020101320, 99);
    printf("%s", class->courses[0].students[0].name);
    return 0;
}