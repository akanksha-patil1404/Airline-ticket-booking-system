//before adding user[id]

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
int usercounter = 0;
char username[10];
char password[10];
//Defining a struct
struct userdetails {
int id;
int visit;
char name[10];
char email[18];
char passport[10];
char password[10];
struct history {
int d,m,y,flightfare;
char locfrom[15];
char locto[15];
}h[100];
};

struct userdetails user[1000];
#include<string.h>

struct flightdetails{
    int id;
    char flightfrom[15];
    char flightto[15];
    int date[3];
    int distance;
    float basefare;
}; 
struct Date {
  int d, m, y;
};

const int monthDays[12]
  = { 31, 28, 31, 30, 31, 30, 
  31, 31, 30, 31, 30, 31 };

int a,b,c;

int countLeapYears(struct Date d)
{
  int years = d.y;

  // or not
  if (d.m <= 2)
    years--;

  return years / 4 
    - years / 100
    + years / 400;
}

int getDifference(struct Date dt1,struct Date dt2)
{

  long int n1 = dt1.y * 365 + dt1.d;

  // Add days for months in given date
  for (int i = 0; i < dt1.m - 1; i++)
    n1 += monthDays[i];

  n1 += countLeapYears(dt1);

  long int n2 = dt2.y * 365 + dt2.d;
  for (int i = 0; i < dt2.m - 1; i++)
    n2 += monthDays[i];
  n2 += countLeapYears(dt2);
  return abs(n2 - n1);
}
struct flightdetails f[100];
float variablefare = 0;
float discount1 = 0;

int main(){
int auth;
int usercounter = 0;
int useridentifier = 0;
int option = 0;
int numseats = 0;
f[1].distance = f[2].distance = f[3].distance = 264;
f[1].basefare = f[1].distance * 20;
f[2].basefare = f[2].distance * 20;
f[3].basefare = f[3].distance * 20;

printf("Welcome to login auth system");
home:

printf("\n1.Registered User\n2.New Registration\n\n");
scanf("%d",&auth);
printf("\n\t\t*****************\n\n");
printf("Details starts\t\t********************\n\n");
int startflightopt = 0;
if(auth == 2 ){
usercounter++;
int id;
id:
printf("Enter your id: (Limit to 4 digits)\n");
scanf("%d",&user[usercounter].id);
if(user[usercounter].id<=1000){
printf("\n\tGiven id is : %d\n\n",user[usercounter].id);
}
else{
goto id;
}

char name[10];
name:
printf("Enter your name: (Limit to 10 characters)\n");
scanf("%s",user[usercounter].name);
if((strlen(user[usercounter].name)<=10)){
printf("\n\tGiven name is : %s\n\n",user[usercounter].name);
}
else{
goto name;
}


char passport[10];
passport:
printf("Enter your passport number: (Limit to 10 characters)\n");
scanf("%s",user[usercounter].passport);
if((strlen(user[usercounter].passport)<=10)){
printf("\n\tGiven passport number is : %s\n\n",user[usercounter].passport);
}
else{
goto passport;
}
char email[18];
email:
printf("Enter your email: (Limit to 18 characters)\n");
scanf("%s",user[usercounter].email);
if((strlen(user[usercounter].email)<=18)){
printf("\n\tGiven email address is : %s\n\n",user[usercounter].email);
}
else{
goto email;
}

char password[10];
password:
printf("Enter your password: (Limit to 10 characters)\n");
scanf("%s",user[usercounter].password);
if((strlen(user[usercounter].password)<=10)){
printf("\n\tGiven name is : %s\n\n",user[usercounter].password);
}
else{
goto password;
}
printf("\nDetails ends-------------------------\n");
printf("\n\t\t*************\n\t\tStored Detailed are:\n\nuser id : %d\nuser name : %s\nuser email :%s\nuser passport : %s\n",user[usercounter].id,user[usercounter].name,user[usercounter].email,user[usercounter].passport);
// file storing.....
printf("Data stored");
startflightopt = 1;
goto startflight;
}
if(auth==1){
printf("Enter name\n");
scanf("%s",username);
printf("Enter Password\n");
scanf("%s",password);
for(int a=0;a<1000;a++){
if(strcmp(user[a].name,username) == 0 && strcmp(user[a].password,password) ==0){
printf("\n\n%s %s\n\n",user[a].name,user[a].password);
user[a].visit++;
useridentifier = a;
printf("\n\nSuccessful\n\n");
startflightopt = 1;
goto startflight;
//*****
//fread(&user[a],sizeof(struct auth),1,fp);
//*****
}}}

FILE *fp;
fp = fopen("user-details.txt", "ab");
if(fp==NULL){
printf("Cannot open file");
exit(1);
}
fwrite(&user[usercounter],sizeof(struct userdetails),1,fp);


// Flight 
startflight:
if(startflightopt == 1){
printf("Start of flight options/n/n");
int fcounter;
for(fcounter=1;fcounter<5;fcounter++){
        f[fcounter].id=fcounter;
        strcpy(f[fcounter].flightfrom,"vijayawada");
        strcpy(f[fcounter].flightto,"hyderabad");
    }
f[1].date[0] = 20;f[2].date[0] = 21;f[3].date[0] = 23;
f[1].date[1] = 03;f[2].date[1] = 03;f[3].date[1] = 04;
f[1].date[2] = f[2].date[2] = f[3].date[2] = 21;


printf("enter the option\n");
int fdisplaycounter;
    for(fdisplaycounter=1;fdisplaycounter<4;fdisplaycounter++){
        printf("\n\nflight from\t\tto\t\tdate\n");
        printf("\n%d\t%s\t%s\t%d/%d/%d\n\n",f[fdisplaycounter].id,f[fdisplaycounter].flightfrom,f[fdisplaycounter].flightto,f[fdisplaycounter].date[0],f[fdisplaycounter].date[1],f[fdisplaycounter].date[2]);
        printf("-----------------------------------------------\n");
    }
int fdisplayoption;
scanf("%d",&fdisplayoption);
printf("\n\nflight from\t\tto\t\tdate\n");
printf("\n%d\t%s\t%s\t%d/%d/%d\n\n",f[fdisplayoption].id,f[fdisplayoption].flightfrom,f[fdisplayoption].flightto,f[fdisplayoption].date[0],f[fdisplayoption].date[1],f[fdisplayoption].date[2]);

printf("\n\n1 for confirm , 2 for cancel\n\n");


//*****************
// time now
time_t now;
time(&now);
int thisday,thismonth,thisyear;
struct tm *local = localtime(&now);
thisday = local->tm_mday;  
thismonth = local->tm_mon + 1;     
thisyear = local->tm_year + 1900;
//time
//*****************
int histnum;
scanf("%d",&option);
if(option == 1){
numseats++;
printf("\n\nnum seats : : :%d\nbasefare : : : %f\n",numseats,f[fdisplayoption].basefare);
variablefare = (((float)numseats/100) * (5280)) + (5280);
printf("\n\nbase fare : : : %f\nvariable fare : : : %f\n\n",f[fdisplayoption].basefare,variablefare);
histnum = user[useridentifier].visit;
user[useridentifier].h[histnum].d=thisday;
user[useridentifier].h[histnum].m=thismonth;
user[useridentifier].h[histnum].y=thisyear;
}
//today***************
printf("today: : : :\n%d/%d/%d\n",user[useridentifier].h[histnum].d,
user[useridentifier].h[histnum].m,
user[useridentifier].h[histnum].y);
//***********************************
//


printf("\n\ndiscount: : %f",discount1);
int discdatediff=0;
int historyflightcounter = 1;
int flighthistcount=0;
if(histnum>0){
//discount based on number of days between registration and flight date.
struct Date dt1[10];
dt1[0].d = thisday;
dt1[0].m = thismonth;
dt1[0].y = thisyear;
struct Date dt2[100];
dt2[histnum].d = user[useridentifier].h[histnum].d;
dt2[histnum].m = user[useridentifier].h[histnum].m;
dt2[histnum].y = user[useridentifier].h[histnum].y;


discdatediff = getDifference(dt1[0], dt2[histnum]);
printf("\n\ndiscount date difference  : : : : %d\n",discdatediff);

//***************************************
//discount

for(historyflightcounter; historyflightcounter < histnum ;historyflightcounter++){

printf("\n\nget diff if loop: : : :%d\n\n",getDifference(dt1[0], dt2[historyflightcounter]));
printf("\ndiscount : : %f\n",discount1);

if(getDifference(dt1[0], dt2[historyflightcounter]) < 366){
    int count;
    getDifference(dt1[0], dt2[historyflightcounter]);
    count++;
    flighthistcount = count ;
    printf("\nflight hist count %d\n",flighthistcount);
    discount1 = ((float)flighthistcount/12)*100;
    printf("\ndiscount : : %f\n",discount1);
}
}
}
printf("\n\n%f\n\n",discount1);
float finalfare =0;
finalfare = variablefare - discount1;
printf("\n\nflight fare : : : %f\nvariable fare : : : %f\ndiscount : : %f\n\n",finalfare,variablefare,discount1);
user[useridentifier].h[histnum].flightfare=finalfare;
strcpy(user[useridentifier].h[histnum].locfrom,f[fdisplayoption].flightfrom);
strcpy(user[useridentifier].h[histnum].locto,f[fdisplayoption].flightto);

//***************************************
printf("\nBooked flight ticket:\n");
printf("\n\nflight from\t\tto\t\tdate\t\tFlight fare");
printf("\n%d\t%s\t%s\t%d/%d/%d\t\t%d\n\n",f[fdisplayoption].id,f[fdisplayoption].flightfrom,f[fdisplayoption].flightto,f[fdisplayoption].date[0],f[fdisplayoption].date[1],f[fdisplayoption].date[2],user[useridentifier].h[histnum].flightfare);

//***************************************
if(option == 2){
    user[useridentifier].visit--;
    user[useridentifier].h[histnum].d = 0;
    user[useridentifier].h[histnum].m = 0;
    user[useridentifier].h[histnum].y = 0;
}
}
else{
    user[useridentifier].visit--;
}
printf("\n\nuser visit : : : %d\n\n",user[useridentifier].visit);
printf("1 for exit; 2 to continue");
int b;
scanf("%d",&b);

if(b==2){
goto home;
}

}