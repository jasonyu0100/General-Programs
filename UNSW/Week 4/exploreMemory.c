//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//

#include <stdio.h>
#include <stdlib.h>

long add (int x, int y);
void sizeOfValue(char val[], int size);
void addressOfValue(void* address,char name[]);

int main(int argc, const char * argv[]) {
    
    int x;
    int y;
    long total;
    x = 40;
    y = 2;
    
    total = add (x, y);
    
    printf("the sum of %d and %d is %ld\n", x, y, total);
    char c ='a';
    sizeOfValue("c",sizeof(c));
    addressOfValue(&c,"c");
    
    unsigned long ul       = 0;
    unsigned int ui        = 1;
    unsigned long long ull = 2;
    unsigned short us      = 3;
    sizeOfValue("ul",sizeof(ul));
    addressOfValue(&ul,"ul");
    sizeOfValue("ui",sizeof(ui));
    addressOfValue(&ui,"ui");
    sizeOfValue("ull",sizeof(ull));
    addressOfValue(&ull,"ull");
    sizeOfValue("us",sizeof(us));
    addressOfValue(&us,"us");
    
    
    
    signed long sl       = 4;
    signed int si        = 5;
    signed long long sll = 6;
    signed short ss      = 7;
    sizeOfValue("sl",sizeof(sl));
    addressOfValue(&sl,"sl");
    sizeOfValue("si",sizeof(si));
    addressOfValue(&si,"si");
    sizeOfValue("sll",sizeof(sll));
    addressOfValue(&sll,"sll");
    sizeOfValue("ss",sizeof(ss));
    addressOfValue(&ss,"ss");
    
    /* The values on my first run of the program were located around address 0x7ffee2642###
     
     
     */
    
    long l       = 8;
    int i        = 9;
    long long ll = 10;
    short s      = 11;
    sizeOfValue("l",sizeof(l));
    addressOfValue(&l,"l");
    sizeOfValue("i",sizeof(i));
    addressOfValue(&i,"i");
    sizeOfValue("ll",sizeof(ll));
    addressOfValue(&ll,"ll");
    sizeOfValue("s",sizeof(s));
    addressOfValue(&s,"s");
    
    float f = 3.1;
    double d = 3.14;
    
    sizeOfValue("f",sizeof(f));
    addressOfValue(&f,"f");
    sizeOfValue("d",sizeof(d));
    addressOfValue(&d,"d");
    
//     add them all together just to make use of them so the compiler
//     doesn't grumble that they are unused in the program
    
    double grandTotal;
    grandTotal =  c +
    ul + ui + ull + us +
    sl + si + sll + ss +
    l +  i +  ll +  s +
    f + d;
    
    printf ("all these things added together make %f\n", grandTotal);
    //Testing overflow
    c += 31;
    printf("%d\n",c); // Turns into a negative value when passes 128
    us += 100000;
    printf("%hd\n",us); // Turns into a negative value
    
    
    //Testing Unsigned
    ui -= 100;
    printf("%u\n",ui); // Overflows to maximum positive and decreases from there
    ull -=100;
    printf("%llu\n",ull); // Overflows to maximum positive and decreases from there
    return EXIT_SUCCESS;
}

void sizeOfValue(char val[],int size) {
    printf("The size of %s in bytes is %d\n",val,size);
}

void addressOfValue(void* address,char name[]) {
    printf("Pointer of %s is at %p\n",name,address);
}

long add (int x, int y) {
    long answer;
    answer = x + y;
    
    return answer;
}

