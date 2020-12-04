#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
    long n,tri_number,count;
    n=1;
    while(n!=0){
        tri_number=n *(n+1)/2;
        count=2;
        for(int k=2;k<=sqrt(tri_number);k++){
            if((tri_number%k)==0) {count+=2;}
            if(count>=500){
                printf("%d",tri_number);
                return 0;
            }
        }
        n++;
    }
    return 0;
}