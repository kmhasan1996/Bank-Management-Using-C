#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x,int y);
void rec(int x,int y,int l,int b);
void bank_title();

//Function of Administrator
void administrator();
void add_account();
void search_account();
void deposit();
void show_allaccount();
void modify_account();
void delete_account();

//Function of User
void user_login();
void user();
void witdraw_of_user();
void trans_balance();
void account_record();
void acupdate_of_user();
int i,j;
void fordelay(int j){
    int i,k;
    for(i=0;i<j;i++)
    k=i;
}



struct account{

    int NO;
    char type[8];
    char name[20];
    char age[3];
    char gender[10];
    char address[100];
    float Account;
    char email[20];
    char pass[7];

}acc,add,upd,check,rem,transaction;

int main()
{
    system("cls");
    //system("color 4a");
    int i, select=0, co=0;
    char com,name[10],orname[10]="1";
    bank_title();
    rec(0,4,75,25);
    rec(7,5,67,7);
    gotoxy(33,6);printf("MAIN MENU");
    rec(7,5,67,22);
    gotoxy(25,9);printf("1] Login as Administrator.");
    gotoxy(25,11);printf("2] Login as User.");
    gotoxy(25,13);printf("3] Create New Account.");
    gotoxy(25,15);printf("4] Exit.");
    rec(7,22,67,25);
    gotoxy(25,23); sec:printf("Enter your choice:");scanf("%d",&select);

    system("cls");
    switch(select)

    {
    case 1:
        administrator();

        break;
    case 2:

          user_login();
        break;
    case 3:{
            add_account();
            int m;
            gotoxy(8,34);printf("Enter 1 to login now 2 for exit");
            scanf("%d",&m);
            if(m==1)
                {
                    system("cls");
                    user_login();
                }
            else
                exit(1);
            }
            break;

    case 4:
        exit(1);
    default :
        main();
    }

    return 0;

}

void administrator(){

            system("cls");
            int option;
            Administrator:
            bank_title();
            rec(0,4,75,25);
            rec(7,5,67,7);
            gotoxy(30,6);printf("ADDMINISTATOR MENU");
            rec(7,5,67,22);
            gotoxy(25,8);printf("1] Create New Account.");
            gotoxy(25,10);printf("2] Search Account No.");
            gotoxy(25,12);printf("3] Deposit Money.");
            gotoxy(25,14);printf("4] View All Account.");
            gotoxy(25,16);printf("5] Edit Existing Account.");
            gotoxy(25,18);printf("6] Delete an Account.");
            gotoxy(25,20);printf("7] Exit.");
            rec(7,22,67,25);
            gotoxy(25,23);printf("Choose Your Option[1-8]:");
            scanf("%d",&option);
            system("cls");
            switch(option)
            {

                case 1:
                    add_account();back_administrator();

                    break;
                case 2:
                    search_account();back_administrator();

                    break;
                case 3:
                    deposit();back_administrator();
                    break;
                case 4:
                    show_allaccount();back_administrator();
                    break;
                case 5:
                    modify_account();back_administrator();
                    break;
                case 6:
                    delete_account();back_administrator();
                    break;
                case 7:
                    exit(1);
                default:
                    goto Administrator;


            }



}


void back_administrator(){
    int en=0;
    gotoxy(8,34);printf("Enter 1 to go to Administrator menu or 2 for exit:");
    scanf("%d",&en);
    if(en==1)
        administrator();
    else
        exit(1);


}

void add_account(){

    account_no:
    bank_title();
    rec(0,4,75,37);
    rec(7,5,67,7);
    gotoxy(27,6);printf("NEW ACCOUNT OPEN FORM");
    rec(7,5,67,32);
    rec(7,32,67,37);
    char ch[1],sa[4]="1",gender[6]="1";
    int acno=0;
    FILE *fp;
    fp = fopen("record.txt","a+");
    gotoxy(8,9);printf("              Account No: ");fflush(stdin);scanf("%d",& acno);
    while(fread(&acc,sizeof(acc),1,fp) == 1)
        {

            if(acc.NO==acno)
                {
                    gotoxy(9,10);printf("Account no. already in use!");
                    fordelay(1000000000);
                    system("cls");
                    goto account_no;

                }


        }
    acc.NO=acno;

    gotoxy(8,11);printf("A/C Type[ 1.Current/2. Saving]:");fflush(stdin);gets(acc.type);
        {

            if(strcmp(acc.type,sa)==0)
            {
                strcpy(acc.type,"Current");
            }
            else
                 strcpy(acc.type,"Saving");
        }

    gotoxy(8,13);printf("                    Name: ");gets(acc.name);

     gotoxy(8,15);printf("                     Age:");gets(acc.age);

     gotoxy(8,17);printf(" Gender[ 1.Male/2. Female]:");gets(acc.gender);

        {
            if(strcmp(acc.gender,gender)==0)
            {
                strcpy(acc.gender,"Male");
            }
            else
                strcpy(acc.gender,"Female");
        }

     gotoxy(8,19);printf("                 Address:");gets(acc.address);
     gotoxy(8,21);printf("                   Email:");gets(acc.email);
        acc.Account=500.00;
    gotoxy(8,23);printf("                Password: ");gets(acc.pass);

     fwrite(&acc, sizeof(acc), 1, fp);
    gotoxy(8,31);printf("Dear,%s Your Account Opened successfully!\n\n",acc.name);

    fclose(fp);


}

void search_account(){
     char ch[1];
     int a_no=0;
     int test=0;
    bank_title();
    rec(0,4,75,30);
    gotoxy(8,5);printf("A/C No: ");fflush(stdin);
    scanf("%d",&a_no);
    FILE *fp;
    fp = fopen("record.txt","r");
    while(fread(&acc,sizeof(acc),1,fp) == 1)
        {
            if(acc.NO==a_no)
                {
                    test=1;
                    account_record();

                }
        }

    if(test==1)
        {
            back_administrator();
        }
    else
        {
            bank_title();
            rec(0,4,75,25);
            rec(15,11,64,20);
            rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
            gotoxy(27,15);printf("Sorry,No Account Found.");
            back_administrator();

        }



}


void show_allaccount()
{


    FILE *fp ;
    int i,test=0,co=5;
    float ba=0 ,avg=0,max=0,min=0;
    char ch[1];
    fp= fopen("record.txt", "r") ;
    bank_title();

    rec(0,4,75,6);

    gotoxy(1,5);printf("  A/C No\t      Name\t        A/C Type \t   Balance");
    while(fread(&acc,sizeof(acc),1,fp) == 1)

            {
                test=1;

                    gotoxy(0, co++);
                 gotoxy(0,co++);for(i=0;i<74;i++) printf("_");

                printf("\n%5d\t%23s\t%15s\t\t%10.2f",acc.NO,acc.name,acc.type,acc.Account);
                //gotoxy(0, co+
            }
             rec(0,6,75,co+1);
            rec(0,4,13,co+1);
            rec(12,4,35,co+1);
            rec(34,4,50,co+1);
             rec(49,4,75,co+1);

            fclose(fp) ;

        if(test==0)
        {

             system("cls");
             bank_title();
            rec(0,5,75,25);
            rec(15,11,64,13);
            rec(15,13,64,20);
            gotoxy(35,12);printf("MASSAGE");
            gotoxy(35,15);printf("NO RECORDS!!");
            gotoxy(28,17);printf("Any Account Not Create Yet!");

            back_administrator();
        }
}

void account_record()
{
    int i;
    FILE *fp;
    fp = fopen("record.txt","r");

    rec(12,7,61,9);
    gotoxy(23,8);printf(" Account Record");
    rec(12,7,61,27);
    gotoxy(15,10);printf("A/C No:  %d",acc.NO);gotoxy(13,11);for(i=0;i<47;i++) printf("_");
    gotoxy(15,12);printf("Account Type:  %s",acc.type);gotoxy(13,13);for(i=0;i<47;i++) printf("_");
    gotoxy(15,14);printf("Name:  %s",acc.name);gotoxy(13,15);for(i=0;i<47;i++) printf("_");
    gotoxy(15,16);printf("Age:  %s",acc.age);gotoxy(13,17);for(i=0;i<47;i++) printf("_");
    gotoxy(15,18);printf("Gender:  %s",acc.gender);gotoxy(13,19);for(i=0;i<47;i++) printf("_");
    gotoxy(15,20);printf("Address:  %s",acc.address);gotoxy(13,21);for(i=0;i<47;i++) printf("_");
    gotoxy(15,22);printf("Balance:  %.2f",acc.Account);gotoxy(13,23);for(i=0;i<47;i++) printf("_");
    gotoxy(15,24);printf("Email:  %s",acc.email);gotoxy(13,25);for(i=0;i<47;i++) printf("_");
    gotoxy(15,26);printf("Password:  %s",acc.pass);



    fclose(fp);

}

void deposit(){

    char ch[1];
    int a_no=0;
    int test=0;
    bank_title();
    rec(0,4,75,25);
    float amount=0;
    gotoxy(15,5);printf("A/C No: ");fflush(stdin);scanf("%d",&a_no);
    FILE *fp;
    fp = fopen("record.txt","r+");
    while(fread(&acc,sizeof(acc),1,fp) == 1)
        {
            if(a_no==acc.NO)
            {   test=1;
                 gotoxy(15,7);printf("Current Balance: %.2f",acc.Account);
                 gotoxy(15,9);printf("Amount: ");
                scanf("%f",& amount);
                acc.Account=acc.Account+amount;
                rec(15,11,64,20);
                 rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                gotoxy(27,15);printf("Amount Added Successfully.");
                fseek(fp,-sizeof(acc),SEEK_CUR);
                fwrite(&acc,sizeof(acc),1,fp);
                  gotoxy(27,17);printf("Current Balance: %.2f",acc.Account);
                fclose(fp);


                }

        }


        if(test==1)
        {
            back_administrator();
        }
        else
        {
            bank_title();
            rec(0,4,75,25);
            rec(15,11,64,20);
            rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
            gotoxy(27,15);printf("Sorry,No Account Found.");
            back_administrator();
        }

}

void modify_account()
{

    int a_no=0,test=0;
    char ch[1],sa[4]="s";;;
    int isFound = 0,option=0;
     bank_title();
    rec(0,4,75,25);
    gotoxy(8,5);printf("A/C No: ");fflush(stdin);scanf("%d",&a_no);

    FILE *fp;
     fp = fopen("record.txt","r+");
    while(fread(&acc,sizeof(acc),1,fp) == 1)
        {
            if(a_no==acc.NO)
                {
                    test=1;
                    break;
                }

        }

        if(test==1 )
        {
            int change=0;
                    gotoxy(15,7);printf("what Do You want to Change:");
                    gotoxy(17,9);printf("1] Email:");
                    gotoxy(17,10);printf("2] Address:");
                    gotoxy(15,12);printf("option:");scanf("%d",& change);


                    switch(change)
                    {



                       case 1:{
                                gotoxy(15,14);printf("Current Email:%s",acc.email);
                                gotoxy(15,15);printf("New Email:");fflush(stdin);gets(acc.email);
                                fseek(fp,-sizeof(acc),SEEK_CUR);
                                fwrite(&acc,sizeof(acc),1,fp);
                                fclose(fp);

                                system("cls");
                                bank_title();
                                rec(0,4,75,25);
                                rec(15,11,64,20);
                                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                gotoxy(27,15);printf("Changed successfully.");
                                gotoxy(27,16);printf("New Email:%s",acc.email);

                               back_administrator();
                                }
                                break;

                      case 2:{
                                gotoxy(15,14);printf("Current Address:%s",acc.address);
                                 gotoxy(15,15);printf("New Address:");fflush(stdin);gets(acc.address);
                                 fseek(fp,-sizeof(acc),SEEK_CUR);
                                fwrite(&acc,sizeof(acc),1,fp);
                                 fclose(fp);
                                 system("cls");
                                bank_title();
                                rec(0,4,75,25);
                                rec(15,11,64,20);
                                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                gotoxy(27,15);printf("Changed successfully.");
                                gotoxy(27,16);printf("New Address:%s",acc.address);

                               back_administrator();
                                }
                                break;

                        default :
                             printf("\n\tAddress:");

                }

        }
        else{
                bank_title();
                rec(0,4,75,25);
                rec(15,11,64,20);
                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                gotoxy(16,15);printf("Sorry, No Account record found in the database.");
                gotoxy(25,17);printf("Please try again");

                back_administrator();

            }


}

void delete_account(){

    FILE *fp,*ne;
    int test=0;
    int acno;
    fp=fopen("record.txt","r");
    ne=fopen("new.txt","w");
    printf("\tDelete A/C No:");fflush(stdin);
    scanf("%d",&acno);
      while(fread(&acc,sizeof(acc),1,fp) == 1)
     {
         if(acc.NO!=acno)
            {

                fwrite(&acc,sizeof(acc), 1,ne);

            }
        else
            {

                test++;
                rec(15,11,64,20);
                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                gotoxy(27,15);printf("Account Deleted Successfully");
                gotoxy(27,16);printf("No Longer in the Database.");

            }


   }
   fclose(fp);
   fclose(ne);
   system("del record.txt");
   system("ren new.txt record.txt");
   if(test==0)
        {

            rec(15,11,64,20);
            rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
            gotoxy(27,15);printf("Record not found!!\a\a\a");
            back_administrator();

        }
    else
        {
            back_administrator();
        }

        back_administrator();



}



void user_login()
{

    char ch[7]="Saving",pass[10];
    int co=0,test=0,a_no=0;
    int en=0;

    bank_title();
    rec(0,4,75,25);
    rec(7,5,67,7);
    gotoxy(33,6);printf("USER LoGIN");
    rec(7,5,67,22);
    gotoxy(15,8);printf("Please,Enter A/C No & Password to Login");
    upass:
    gotoxy(20,12);printf("A/C No: ");fflush(stdin);scanf("%d",&a_no);
    gotoxy(20,14);printf("Password: ");fflush(stdin);scanf("%s",pass);
    FILE *fp;
    fp = fopen("record.txt","r+");
    while(fread(&acc,sizeof(acc),1,fp) == 1)
            {


                if(a_no==acc.NO && strcmp(acc.pass,pass)==0)//if()
                {
                    user:
                    test=1;
                    system("cls");
                    int option;
                    bank_title();
                    rec(0,4,75,25);
                    rec(7,5,67,7);
                    gotoxy(30,6);printf("USER MENU");
                     rec(7,5,67,22);
                    gotoxy(25,8);printf("1] Withdraw Amount.");
                    gotoxy(25,10);printf("2] Balance Transfer.");
                    gotoxy(25,12);printf("3] View Details. ");
                    gotoxy(25,14);printf("4] Update Account. ");
                    gotoxy(25,16);printf("5] Change Password.");
                    gotoxy(25,18);printf("6] Exit.");
                    rec(7,22,67,25);
                    gotoxy(25,23);printf("Choose Your Option[1-6]:");
                    scanf("%d",&option);
                    system("cls");

                    switch(option)
                    {

                    case 1:{
                            float amount1=0;

                            if(strcmp(ch,acc.type)==0)
                                    {
                                        bank_title();
                                        rec(0,4,75,25);
                                        rec(15,11,64,20);
                                        rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                        gotoxy(27,15);printf("Sorry your account type is saving.");
                                        gotoxy(27,17);printf("You can't Withdraw.");
                                        gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                                        scanf("%d",&en);
                                        if(en==1)
                                            goto user;
                                        else
                                            exit(1);


                                    }

                            bank_title();
                            rec(0,4,75,25);
                            gotoxy(12,6);printf("Available Balance %.2f", acc.Account);
                            gotoxy(12,7);printf("Amount:");scanf("%f",& amount1);
                            if(acc.Account-amount1<=0)
                                {
                                    bank_title();
                                    rec(0,4,75,25);
                                    rec(15,11,64,20);
                                    rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                    gotoxy(27,15);printf("You Don't Have Sufficient Balance.");
                                    gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                                    scanf("%d",&en);
                                    if(en==1)
                                        goto user;

                                    else
                                        exit(1);

                                }

                            else
                                {
                                    acc.Account=acc.Account-amount1;
                                    rec(15,11,64,20);
                                    rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                    gotoxy(27,15);printf("Amount Withdraw Successfully.");
                                    gotoxy(27,17);printf("Current Balance: %.2f",acc.Account);
                                    fseek(fp,-sizeof(acc),1);
                                    fwrite(&acc,sizeof(acc),1,fp);

                                }
                            fclose(fp);

                            gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                            scanf("%d",&en);
                            if(en==1)
                                 goto user;
                            else
                                exit(1);


                        }
                        break;

                case 2:{
                        float amount=0; int trno=0;
                        if(strcmp(ch,acc.type)==0)
                                    {
                                        bank_title();
                                        rec(0,4,75,25);
                                        rec(15,11,64,20);
                                        rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                        gotoxy(27,15);printf("Sorry your account type is saving.");
                                        gotoxy(27,17);printf("You can't Transfer.");
                                        gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                                        scanf("%d",&en);
                                        if(en==1)
                                            goto user;

                                        else
                                            exit(1);

                                    }
                        bank_title();
                        rec(0,4,75,25);
                        gotoxy(12,8);printf("A/C No:");scanf("%d",& trno);

                        if(trno==acc.NO )//&& trno==acc.NO)
                        {
                            system("cls");
                            bank_title();
                            rec(0,4,75,25);
                            rec(15,11,64,20);
                            rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                            gotoxy(27,15);printf("Sorry its your Own A/C no.");
                            gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                            scanf("%d",&en);
                            if(en==1)
                                goto user;
                            else
                                exit(1);
                            break;
                        }


                        gotoxy(12,6);printf("Available Balance %.2f", acc.Account);
                        gotoxy(12,7);printf("Transfer Amount:");scanf("%f",& amount);
                        if(acc.Account-amount<=0)
                            {
                                bank_title();
                                rec(0,4,75,25);
                                rec(15,11,64,20);
                                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                gotoxy(27,15);printf("You Don't Have Sufficient Balance.");
                                gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                                scanf("%d",&en);
                                if(en==1)
                                    goto user;

                                else
                                    exit(1);

                            }


                        else
                            {
                                acc.Account=acc.Account-amount;
                                fseek(fp,-sizeof(acc),SEEK_CUR);
                                fwrite(&acc,sizeof(acc),1,fp);
                                fclose(fp);

                            }


                        FILE *fp;
                        fp = fopen("record.txt","r+");
                        while(fread(&acc,sizeof(acc),1,fp) == 1)
                            {

                                if(trno==acc.NO)
                                {
                                    acc.Account=acc.Account+amount;
                                    rec(15,11,64,20);
                                    rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                    gotoxy(27,15);printf("Balance Transfer Successfully.");
                                    fseek(fp,-sizeof(acc),SEEK_CUR);
                                    fwrite(&acc,sizeof(acc),1,fp);
                                    fclose(fp);
                                    break;

                                }

                            }


                        gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                        scanf("%d",&en);
                        if(en==1)
                            goto user;
                        else
                            exit(1);

                    }
                      break;

            case 3:{
                    bank_title();
                    rec(0,4,75,30);
                    account_record();

                    gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                    scanf("%d",&en);
                    if(en==1)
                        goto user;
                    else
                        exit(1);
                }
                    break;


            case 4:{
                    char ch[1],sa[4]="s";
                    int change=0;
                    bank_title();
                    rec(0,4,75,25);
                    gotoxy(15,7);printf("what Do You want to Change:");
                    gotoxy(17,9);printf("1] Email:");
                    gotoxy(17,10);printf("2] Address:");
                    gotoxy(15,12);printf("option:");scanf("%d",& change);


                    switch(change)
                    {



                       case 1:{
                                gotoxy(15,14);printf("Current Email:%s",acc.email);
                                gotoxy(15,15);printf("New Email:");fflush(stdin);gets(acc.email);
                                fseek(fp,-sizeof(acc),SEEK_CUR);
                                fwrite(&acc,sizeof(acc),1,fp);
                                fclose(fp);
                                }
                                break;

                      case 2:{
                                gotoxy(15,14);printf("Current Address:%s",acc.address);
                                 gotoxy(15,15);printf("New Address:");fflush(stdin);gets(acc.address);
                                 fseek(fp,-sizeof(acc),SEEK_CUR);
                                fwrite(&acc,sizeof(acc),1,fp);
                                 fclose(fp);
                                }
                                break;

                        default :
                             printf("\n\tAddress:");

                }
            system("cls");
            bank_title();
            rec(0,4,75,25);
            rec(15,11,64,20);
            rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
            gotoxy(27,15);printf("Changed successfully.");
            gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");scanf("%d",&en);

                    if(en==1)
                        goto user;
                    else
                        exit(1);


                }
                break;

            case 5:{

                 char npass[10],repass[10],mpass[10];
                int co=6,co1=0;

                bank_title();
                rec(0,4,75,25);
                fflush(stdin);
                pass:
                gotoxy(12,co);printf("Your Current Password:");gets(mpass);
                if(strcmp(acc.pass,mpass)==0)
                    {
                        newpass:
                         gotoxy(12,co+2);printf("New Password:");gets(npass);
                         gotoxy(12,co+3);printf("Re Enter New Password:");gets(repass);
                        if(strcmp(npass,repass)==0)
                            {
                                strcpy(acc.pass,repass);
                                bank_title();
                                rec(15,11,64,20);
                                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                gotoxy(27,15);printf("Password Changed successfully.");
                                gotoxy(27,16);printf("New Password:%s",acc.pass);
                                fseek(fp,-sizeof(acc), 1);
                                fwrite(&acc,sizeof(acc), 1, fp);
                                fclose(fp);

                            }
                        else
                            {
                               co1++;
                                if(co1==2)
                                    {
                                        system("cls");
                                        bank_title();
                                        rec(0,4,75,25);
                                        rec(15,11,64,20);
                                        rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                        gotoxy(17,15);printf("SORRY 2 times Wrong password try again later.");
                                        gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                                        scanf("%d",&en);
                                        if(en==1)
                                            goto user;
                                        else
                                            exit(1);

                                        break;
        ;
                                    }

                        system("cls");
                        bank_title();
                         rec(0,4,75,25);
                        co++;
                        gotoxy(12,co);printf("Password Didn't Match.Try Again");
                        co++;
                        goto newpass;
                            }

                    }
                else
                    {
                        co1++;
                        if(co1==2)
                            {
                                system("cls");
                                bank_title();
                                rec(0,4,75,25);
                                rec(15,11,64,20);
                                rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                                gotoxy(17,15);printf("SORRY 2 times Wrong password try again later.");
                                gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                                scanf("%d",&en);
                                if(en==1)
                                    goto user;
                                else
                                    exit(1);

                                break;
;
                            }

                        system("cls");
                        bank_title();
                         rec(0,4,75,25);
                        co++;
                        gotoxy(12,co);printf("Wrong Password.Try Again");
                        co++;
                        goto pass;
                    }
                    gotoxy(8,34);printf("Enter 1 to go to User Menu or 2 for exit:");
                    scanf("%d",&en);
                    if(en==1)
                        goto user;
                    else
                        exit(1);

            }
            break;

            case 6:exit(1);
            default:goto user;


            }


        }


    }

            if(test==0)
            {
                co++;
            if(co==3)
                {
                    system("cls");
                    bank_title();
                    rec(0,4,75,25);
                    rec(15,11,64,20);
                    rec(15,11,64,13);gotoxy(35,12);printf("MASSAGE");
                    gotoxy(27,15);printf("SORRY 3 times Wrong password!!!");
                    gotoxy(27,16);printf("Try again later.......");
                    gotoxy(12,27);exit(1);

                }
            system("cls");
            bank_title();
            rec(0,4,75,25);
            gotoxy(15,9);printf("Wrong Password.Try Again....\n");
            goto upass;
            }



}

void bank_title()
{
    int i;
    rec(0,0,75,2);
    gotoxy(27,1);printf(" KM Banking Corporation\n");

    gotoxy(0,3); for(i=0;i<75;i++) printf("\xB2");

}


COORD coord = {0, 0};

void gotoxy (int x, int y){

        coord.X = x;
        coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }


void rec(int x,int y,int l,int b){

    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}




