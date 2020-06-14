#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

/*ptr 成员指针
* type 结构体 比如struct Stu
* member 成员变量，跟指针对应
* */
#define container_of(ptr, type, member) ({          \
        const typeof( ((type *)0)->member ) *__mptr = (const typeof( ((type *)0)->member ) *)(ptr); \
        (type *)( (char *)__mptr - offsetof(type,member) ); })

typedef struct Stu
{
        int age;
        char name[10];
        int id;
        unsigned long phone_num;
} *p_stu, str_stu;

void print_all(void *p_str)
{

        p_stu m1p_stu = NULL;

        m1p_stu = container_of(p_str, struct Stu, age);

        printf("age:%d\n", m1p_stu->age);
        printf("name:%s\n", m1p_stu->name);
        printf("id:%d\n", m1p_stu->id);
        printf("phone_num:%d\n", m1p_stu->phone_num);
}

void main(void)
{
        p_stu m_stu = (p_stu)malloc(sizeof(str_stu));

        m_stu->age = 25;
        m_stu->id = 1;
        m_stu->name[0] = 'w';
        m_stu->name[1] = 'e';
        m_stu->name[2] = 'i';
        m_stu->name[3] = 'q';
        m_stu->name[4] = 'i';
        m_stu->name[5] = 'f';
        m_stu->name[6] = 'a';
        m_stu->name[7] = '\0';
        m_stu->phone_num = 13267;

        /*传结构体成员指针进去*/
        print_all(&m_stu->age);

        printf("main end\n");

        if (m_stu != NULL)
                free(m_stu);
}