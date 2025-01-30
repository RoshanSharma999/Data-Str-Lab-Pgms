#include <stdio.h> 

struct student { 
    char name[50]; 
    char usn[10]; 
    int age; 
    float cgpa; 
}; 

int main() { 
    struct student s[100]; 
    int n; 
    float min_cgpa; 

    printf("Enter number of students: "); 
    scanf("%d", &n); 
    for(int i = 0; i < n; i++) { 
        printf("\nStudent %d details:\n", i+1); 
        printf("Name: "); 
        scanf("%s", s[i].name); 
        printf("USN: "); 
        scanf("%s", s[i].usn); 
        printf("Age: "); 
        scanf("%d", &s[i].age); 
        printf("CGPA: "); 
        scanf("%f", &s[i].cgpa); 
    } 

    printf("\nEnter minimum CGPA to display: "); 
    scanf("%f", &min_cgpa); 
    
    printf("\nStudents with CGPA >= %.2f:\n", min_cgpa); 
    for(int i = 0; i < n; i++) { 
        if(s[i].cgpa >= min_cgpa) { 
            printf("\nName: %s", s[i].name); 
            printf("\nUSN: %s", s[i].usn); 
            printf("\nAge: %d", s[i].age); 
            printf("\ncgpa: %.2f", s[i].cgpa); 
        }
    }
    return 0; 
} 