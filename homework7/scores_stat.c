#include <stdio.h>
#include <stdlib.h>
// һЩ����
#define STUDENT_COUNT 5
#define SUBJECTS 3
struct student {
    unsigned int num;
    char name[20];
    unsigned int scores[3];
} ;
struct student stu[STUDENT_COUNT];
// �����Ϣ
void input(struct student *st){
    printf("\n\n");
    printf("\t\tѧ��������");
    gets((*st).name);
    printf("\n\t\tѧ��ѧ�ţ�");
    scanf("%ud", &((*st).num));
    printf("\n\t\tѧ��������");
    scanf("%u%u%u", &((*st).scores[0]), &((*st).scores[1]), &((*st).scores[2]));
    getchar();
}
// ������Ϣ
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