/*
Template by Sai Suman Chitturi
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: skynetasspyder
Codechef: suman_18733097
Codeforces: saisumanchitturi
Github: ChitturiSaiSuman
Hackerearth: chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/

//	  _____   _    _   __    __     ____     __    _
//	 / ____| | |  | | |  \  /  |   /    \   |  \  | |
//	 | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//	 \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//	 ____| | | \__/ | | |    | | |   __   | | | \ ` |
//	 |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//
						
#include <stdio.h>			
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

#define and 									&&
#define or 										||
#define not 									!
#define is 										==
#define space									printf(" ")
#define endl									printf("\n")
#define iter(x,a,b) 							for(int x=a;x<=b;x++)
#define FOR(x,N) 								for(int x=0;x<N;x++)
#define For(x,N) 								for(int x=0;x<N;x++)
#define caseprint 								printf("Case #%d: ",test+1)
#define inverse(a) 								power(a,mod-2,mod)
#define scan(a) 								scanf("%d",&a)
#define print(a) 								printf("%lld",((ll)a))
#define println(a)								printf("%lld\n",((ll)a))
#define read(arr,maxN)							FOR(x,maxN) {scan(arr[x]);}
#define write(arr,maxN)							FOR(x,maxN) {print(arr[x]);space;}
#define fill(arr,maxN,value)					FOR(x,maxN) {arr[x] = value;}
#define sort123(arr,maxN)						qsort(arr,maxN,sizeof(int),ascending)
#define sort321(arr,maxN)						qsort(arr,maxN,sizeof(int),descending)
#define reverse(arr,maxN)						FOR(x,maxN/2) {arr[x]=arr[maxN-x-1];}
#define newInt(maxN)							(int*)malloc(sizeof(int)*maxN)
#define newLong(maxN)							(ll *)malloc(sizeof(ll)*maxN)

typedef unsigned long long int ull;
typedef long long int ll;
const ll mod = ((ll)(1e9+7)); // 10**9+7
const ll hell = ((ll)(1e18)); // 10**18

static inline void swapInt(int *a, int *b) 		{int temp=*a;*a=*b;*b=temp;}
static inline void swapChar(char *a, char *b)	{char c=*a;*a=*b;*b=c;}
static inline void swapLong(ll *a, ll *b)		{ll temp=*a;*a=*b;*b=temp;}
static inline int setBitCount(ll n)				{int ans=0;for(;n>0;n/=2,ans+=n%2);return ans;}
static inline ll gcd(ll a, ll b) 				{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll lcm(ll a, ll b) 				{return (a*b)/(gcd(a,b));}
static inline ll max(ll a, ll b) 				{return (a>b?a:b);}
static inline ll min(ll a, ll b) 				{return (a<b?a:b);}
static inline ll mul(ll a, ll b) 				{return ((a%mod*b%mod)%mod);}
static inline ll add(ll a, ll b) 				{return ((a%mod+b%mod)%mod);}
static inline ll sub(ll a, ll b) 				{return ((a%mod-b%mod)+mod)%mod;}
static inline int sumOfDigits(ll n) 			{return n>0?n%10+sumOfDigits(n/10):0;}
static inline int numberOfDigits(ll n)			{return n>0?1+numberOfDigits(n/10):0;}

typedef struct Element
{
    int atomicNumber;
    char name[32];
    char symbol[4];
} Element;

Element *element;

void clear()
{
    system("clear");
}

void newline(int n)
{
    FOR(i,n)
        printf("\n");
}

void tab(int n)
{
    FOR(i,n)
        printf("\t");
}

char input()
{
    system("/bin/stty raw");
    char ch=getchar();
    system("/bin/stty cooked");
    return ch;
}

void gets(char s[])
{
    char ch;
    scanf("%c",&ch);
    if(ch=='\n')
        scanf("%c",&ch);
    int ind = 0;
    while(ch!='\n')
    {
        s[ind++] = ch;
        scanf("%c",&ch);
    }
    s[ind] = '\0';
}

void strlwr(char s[], int length)
{
    FOR(i,length)
        s[i] = tolower(s[i]);
}

void printIntroduction()
{
    FILE *fptr = fopen("Introduction.txt","r");
    char ch;
    clear();
    while(fscanf(fptr,"%c",&ch)!=-1)
        printf("%c",ch);
    fclose(fptr);
    char name[50];
    newline(2);
    tab(3);
    printf("Enter Your Name: ");
    gets(name);
    newline(2);
    tab(3);
    printf("Greetings: %s",name);
    newline(2);
    tab(3);
    printf("Press any key to continue...");
    char trash = input();
    clear();
}

void load()
{
    FILE *file = fopen("Elements.txt","r");
    element = (Element *)malloc(sizeof(Element)*118);
    FOR(i,118)
        fscanf(file,"%s %d %s",element[i].name,&element[i].atomicNumber,element[i].symbol);
    fclose(file);
}

void previewDetails(int atomicNumber)
{
    FILE *file;
    if(numberOfDigits(atomicNumber)==1)
    {
        char path[] = "Info/0.txt";
        path[5] = atomicNumber+'0';
        file = fopen(path,"r");
    }
    else if(numberOfDigits(atomicNumber)==2)
    {
        char path[] = "Info/00.txt";
        int temp = atomicNumber;
        path[6] = temp%10+'0';
        temp/=10;
        path[5] = temp+'0';
        file = fopen(path,"r");
    }
    else
    {
        char path[] = "Info/000.txt";
        int temp = atomicNumber;
        path[7] = temp%10+'0';
        temp/=10;
        path[6] = temp%10+'0';
        temp/=10;
        path[5] = temp%10+'0';
        file = fopen(path,"r");
    }
    char ch;
    while(fscanf(file,"%c",&ch)!=-1)
        printf("%c",ch);
    fclose(file);
}

bool run()
{
    newline(2);
    tab(3);
    printf("Hope you need some Information of an Element");
    newline(2);
    tab(3);
    printf("Choose one among the following to Access the Information of Element");
    newline(2);
    tab(4);
    printf("1. Atomic Number");
    newline(2);
    tab(4);
    printf("2. Name of Element");
    newline(2);
    tab(4);
    printf("3. Symbol of Element");
    newline(2);
    tab(5);
    printf("Integral Choice: ");
    char choice = input();
    if(choice=='1')
    {
        clear();
        newline(2);
        tab(3);
        printf("Enter the Atomic Number of Element: ");
        int atomicNumber;
        scanf("%d",&atomicNumber);
        if(atomicNumber<1 or atomicNumber>118)
        {
            printf("Invalid Atomic Number!");
        }
        else
        {
            previewDetails(atomicNumber);
        }
    }
    else if(choice is '2')
    {
        char name[32];
        clear();
        newline(2);
        tab(3);
        printf("Enter the Name of Element: ");
        scanf("%s",name);
        strlwr(name,strlen(name));
        int ind = -1;
        FOR(i,118)
        {
            char *temp = (char*)malloc(sizeof(char)*strlen(element[i].name));
            strcpy(temp,element[i].name);
            strlwr(temp,strlen(temp));
            if(strcmp(temp,name)==0)
            {
                ind = i;
                free(temp);
                break;
            }
            free(temp);
        }
        previewDetails(ind+1);
    }
    else if(choice is '3')
    {
        char symbol[4];
        clear();
        newline(2);
        tab(3);
        printf("Enter the Symbol of Element: ");
        scanf("%s",symbol);
        strlwr(symbol,strlen(symbol));
        int ind = -1;
        FOR(i,118)
        {
            char *temp = (char*)malloc(sizeof(char)*strlen(element[i].symbol));
            strcpy(temp,element[i].symbol);
            strlwr(temp,strlen(temp));
            if(strcmp(temp,symbol)==0)
            {
                ind = i;
                free(temp);
                break;
            }
            free(temp);
        }
        previewDetails(ind+1);
    }
    else
    {
        newline(2);
        tab(4);
        printf("Invalid choice!");
    }
    newline(3);
    tab(4);
    printf("Do you want to Quit? (Y/N): ");
    choice = input();
    while(choice=='\n')
        choice = input();
    return (choice=='N' or choice=='n');
}

void printConclusion()
{
    FILE *file = fopen("Conclusion.txt","r");
    char ch;
    while(fscanf(file,"%c",&ch)!=-1)
        printf("%c",ch);
    fclose(file);
}

void clearMemory()
{
    free(element);
}

int main()
{
    load();
    printIntroduction();
    bool loop = true;
    while (loop)
    {
        loop = run();
        clear();
    }
    clear();
    printConclusion();
    newline(4);
    tab(5);
    printf("Clearing Memory...");
    newline(1);
    clearMemory();
    sleep(10);
    clear();
    return 0;
}
/*
*   This Application is Developed by Sai Suman Chitturi
*   This is Command line application yet too powerful
*   For any queries or feedback please drop a mail at saisumanchitturi@gmail.com
*/