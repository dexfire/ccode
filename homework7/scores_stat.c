#include <stdio.h>
#include <stdlib.h>
// 一些定义
#define STUDENT_COUNT 5
#define SUBJECTS 3
struct student {
    unsigned int num;
    char name[20];
    unsigned int scores[3];
} ;
struct student stu[STUDENT_COUNT];
// 输出信息
void input(struct student *st){
    printf("\n\n");
    printf("\t\t学生姓名：");
    gets((*st).name);
    printf("\n\t\t学生学号：");
    scanf("%ud", &((*st).num));
    printf("\n\t\t学生分数：");
    scanf("%u%u%u", &((*st).scores[0]), &((*st).scores[1]), &((*st).scores[2]));
    getchar();
}
// 输入信息
void print(struct student st){
    printf("\n\t\t");
    for (int i = 0; i < SUBJECTS;i++)
        printf("%u%\t",st.scores[i]);
}

int main(){
    for (int i = 0; i < STUDENT_COUNT; i++){
        input(&stu[i]);
        print(stu[i]);
        printf("\n\n");
    }
    system("pause");
}