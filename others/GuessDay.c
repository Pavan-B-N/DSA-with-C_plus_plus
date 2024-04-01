#include <stdio.h>
void printDay(int index){
    switch (index)
    {
    case 1:{
        printf("Sunday\n");
        break;
    }
    
    default:
        break;
    }
}
int main(){
    int year=2005;
    // scanf("%d",year);
    year=year%100-1;// finding diffrence between the entered year and the starting year 
    int leapYear=year/4;
    printf("leapYear: %d\n",leapYear);
    int nonLeapYear=year-leapYear;
    int ans=(leapYear*2+nonLeapYear+1)%7;
    printf("Day Index is : %d \n",ans);
    return 0;
}