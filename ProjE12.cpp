// #include<stdio.h>
// #include<math.h>
// using namespace std;
// int main(){
//     long n,tri_number,count;
//     n=1;
//     while(n!=0){
//         tri_number=n*(n+1)/2;
//         count=2;
//         for(int k=2;k<=sqrt(tri_number);k++){
//             if((tri_number%k)==0) {count+=2;}
//             if(count>=500){
//                 printf("%d",tri_number);
//                 return 0;
//             }
//         }
//         n++;
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned long long sum=0;
    unsigned long long counter=1;
    while(1)
    {
        sum+=counter;
        counter++;

        int num=0;
        unsigned long long i=1;
        while(i*i<=sum)
        {
            if(sum%i==0)
            {
                num+=2;
            }
            i++;
        }
        if(num>=500)
        {
            break;
        }
    }
    printf("%llu\n",sum);
}