#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

typedef struct
{
    char name[30];
    char phone[20];
    char gender[7];
    char email[35];
    char address[100];
    char place[35];
    char district[35];
    char state[35];
    char country[35];
    char pincode[10];
    char password[20];
    char acc[20];
    char bank[50];
    char type[20];
    char ifsc[15];
    char mpin[10];
    int dob[3];
    int balance;
} GOBLIN;

typedef struct
{
    char facc[20],tacc[35];
    int debit,credit,balance;
    int value;
} HISTORY;

char G_acc[20],G_phone[20],G_name[50],G_password[20],G_email[35],G_bank[50],G_ifsc[15],G_mpin[10];
int G_Balance,amount;

char B_name[30],B_ifsc[15],B_bank[35],B_acc[35],B_cvv[5],B_pin[5];
int B_year,B_month;

int length;

void takepassword(char password[50])    // reading the password in asterisk(*) symbol
{
    int i;
    char ch;
    while(1)
    {
        ch=getch();            ///  reading single characters

        if(ch==ENTER || ch==TAB)
        {
            password[i]='\0';
            break;
        }
        else if(ch==BCKSPC)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            password[i++]=ch;
            printf("* \b");
        }
    }
}

void create()    // Creating customers new account and adding into the file
{
    GOBLIN G;
    int n=1,i,z,zz=0,flag=0;
    FILE *fp;
    char password[20];
    fp=fopen("Account","a");

    printf("\n\t%-25s : ","Enter your Full name");
    fflush(stdin);
    scanf("%[^\n]s",G.name);

PHONE:
    {
        printf("\n\t%-25s : ","Enter your Phone Number");
        fflush(stdin);
        scanf("%s",G.phone);
        {
            for(i=0; G.phone[i]!='\0'; i++)
            {
                if((G.phone[i]>=48 && G.phone[i]<=57)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("\n\tOnly Numericals are allowed\n");
                flag=0;
                goto PHONE;
            }
            else
            {
                if(i!=10)
                {
                    printf("\n\t Phone number should be length of 10 \n");
                    goto PHONE;
                }
            }
        }
    }
    duplicate_account(G.phone,1);

EMAIL:
    {
        printf("\n\t%-25s : ","Enter Your E-mail");
        fflush(stdin);
        scanf("%s",G.email);
    }
    length=strlen(G.email);
    for(z=0; G.email[z]!='\0'; z++)
    {
        if(G.email[z]=='@')
            zz=1;
    }
    if(length<=10)
    {
        printf("\n\t Invalid E-mail, Example abc@sit.ac.in or abc@gmail.com \n");
        goto EMAIL;
    }
    if(zz==0)
    {
        printf("\n\t Invalid E-mail, Please put @ symbol in E-mail\n");
        goto EMAIL;
    }

    int j;
    int d,m,y;
    printf("\n\t%-25s : ","Enter date of Birth (dd/mm/yyyy)");
D:
    {
        printf("\n\t Date : ");
        scanf("%d",&d);
    }
    if(d>31 || d<=0)
    {
        printf("\n\t Please enter valid date between 1 - 31\n");
        goto D;
    }
    G.dob[0]=d;

M:
    {
        printf("\n\t Month : ");
        scanf("%d",&m);
    }
    if(m<=0 || m>12 )
    {
        printf("\n\t Please enter valid month between 1 - 12\n");
        goto M;
    }
    G.dob[1]=m;

Y:
    {
        printf("\n\t Year : ");
        scanf("%d",&y);
    }
    if(y<1900 || y<=0 || y>2010)
    {
        if(y>2010)
        {
            y=2022-y;

            printf("\n\t Minimum age is 12\n\n\t You are not eligible to create GOBLIN pay account, because you are just %d years old \n",y);
            main();
        }
        else
        {
            printf("\n\t Please enter a valid year between 1900-2010\n");
            goto Y;
        }
    }
    G.dob[2]=y;

    char gen;
GEN:
    {
        printf("\n\t%-25s : ","Are you a Male or a Female (M/F)");
        fflush(stdin);
        scanf("%c",&gen);
    }
    if(gen!='m' && gen!='M' && gen!='F' && gen!='f')
    {
        printf("\n\tPlease correctly specify the gender\n");
        goto GEN;
    }
    if(gen=='m' || gen=='M')
        strcpy(G.gender,"Male");
    else
        strcpy(G.gender,"Female");

ADDRESS:
    {
        printf("\n\t%-25s\n\n\t","Permanent Address (House no./ Building name/ Road name/ Area/ Colony/ Street/ Landmark)");
        fflush(stdin);
        scanf("%[^\n]s",G.address);
    }
    length=strlen(G.address);
    if(length<10)
    {
        printf("\n\t Address length should be at least 10 characters ** Please provide your complete address \n");
        goto ADDRESS;
    }

    printf("\n\t%-25s: ","City/Village/Town");
    fflush(stdin);
    scanf("%s",G.place);

    printf("\n\t%-25s: ","District");
    fflush(stdin);
    scanf("%s",G.district);

    printf("\n\t%-25s: ","State");
    fflush(stdin);
    scanf("%s",G.state);

    printf("\n\t%-25s: ","Country");
    fflush(stdin);
    scanf("%s",G.country);

    printf("\n\t%-25s: ","Area Pincode");
    fflush(stdin);
    scanf("%s",G.pincode);

    printf("\n\t  %-25s : "," Create Your Goblin Pay Password");
    fflush(stdin);
    takepassword(G.password);

    printf("\n\n\t %-25s : ","Confirm Your Goblin Pay Password");
    takepassword(password);

    if(strcmp(G.password,password)==0)
    {
        printf("\n\n\t--->\"Your Goblin  account has been created successfully\"!!!\n");
        printf("\n\t Add Your Bank Details.....!\n");

ACCOUNT:
        {
            printf("\n\t %-25s : ","Account Number");
            fflush(stdin);
            scanf("%s",G.acc);
            duplicate_account(G.acc,2);
            strcpy(G_acc,G.acc);
            {
                for(i=0; G.acc[i]!='\0'; i++)
                {
                    if((G.acc[i]>=48 && G.acc[i]<=57)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    printf("\n\tOnly Numericals are allowed\n");
                    flag=0;
                    goto ACCOUNT;
                }
                else
                {
                    if(i<11)
                    {
                        printf("\n\t Account number length should minimum 11\n");
                        goto ACCOUNT;
                    }
                }
            }
        }

        printf("\n\t %-25s : ","Bank Name");
        fflush(stdin);
        scanf("%[^\n]s",G.bank);

IFSC:
        {
            printf("\n\t %-25s : ","IFSC Code");
            scanf("%s",G.ifsc);
        }
        length=strlen(G.ifsc);
        if(length<11)
        {
            printf("\n\t IFSC code length should not be less than 11\n");
            goto IFSC;
        }


TYPE:
        printf("\n\t %-25s : "," Savings Account/Current Account (S/C)?");
        fflush(stdin);
        scanf("%c",&gen);
        if(gen!='s' && gen!='S' && gen!='C' && gen!='c')
        {
            printf("\n\tPlease correctly specify the account type\n");
            goto TYPE;
        }
        if(gen=='C' || gen=='c')
            strcpy(G.type,"Current Account");
        else
            strcpy(G.type,"Savings Account");

        printf("\n\n\t--->\"Your Bank Details has been added Successfully\"!!!\n");

        printf("\n\t%-25s : ","Create Your MPIN");
        takepassword(G.mpin);

        printf("\n\n\t %-25s : ","Confirm Your MPIN");
        takepassword(password);

        if(strcmp(G.mpin,password)==0)
        {
            printf("\n\n\t--->\"MPIN Created Successfully\"!!!\n");
            printf("\n\t Congratulations!!! You have got 500$ cash bonus for creating Goblin Pay account\n");
            Sleep(5000);
            G.balance=500;
            G_Balance=500;
            strcpy(G_acc,G.acc);
            strcpy(G_name,G.name);
            strcpy(G_phone,G.phone);
            strcpy(G_email,G.email);
            strcpy(G_password,G.password);
            strcpy(G_bank,G.bank);
            strcpy(G_ifsc,G.ifsc);
            strcpy(G_mpin,G.mpin);

            fwrite(&G,sizeof(GOBLIN),1,fp);
            fclose(fp);
            system("cls");
            account();
        }
        else
        {
            printf("\n\n\t--->\"MPIN not matched\"\n");
            Beep(750,300);
            return;
        }
    }
    else
    {
        printf("\n\n\t--->\"Password doesn't matches \"\n");
        Beep(750,300);
        return;
    }
}

void duplicate_account(char acc[],int value)    // Checking for duplicate account
{
    GOBLIN temp;
    FILE *fp;
    int Found=0;

    fp=fopen("Account","r");

    if(value==2)
    {
        while(fread(&temp,sizeof(GOBLIN),1,fp))
        {
            if(!strcmp(temp.acc,acc))
            {
                printf("\n\t%s - This Account number already exist,Try to Login\n",acc);
                fclose(fp);
                main();
            }
            Found=1;
        }
    }
    else if(value==3)
    {
        while(fread(&temp,sizeof(GOBLIN),1,fp))
        {
            if(!strcmp(temp.acc,acc))
            {
                printf("\n\tYou can't send money to your account\n",acc);
                fclose(fp);
                account();
            }
            Found=1;
        }
    }
    else
    {
        while(fread(&temp,sizeof(GOBLIN),1,fp))
        {
            if(!strcmp(temp.phone,acc))
            {
                printf("\n\t%s - This phone number already exist, Try to Login\n",acc);
                fclose(fp);
                main();
            }
            Found=1;
        }
    }

    fclose(fp);
}

int balance()   // Checking the bank details
{
    FILE *fp;
    GOBLIN G;
    fp=fopen("Account","r");

    while(fread(&G,sizeof(GOBLIN),1,fp))
    {
        if(strcmp(G_acc,G.acc)==0)
        {
            fclose(fp);
            break;
        }
    }
    return G.balance;
}

void account()    // Once user login, main menu will display, different operation will be displayed to the user
{
    system("cls");
    int choice,a;
    printf("\n\n\t\t\t\t\t\t\t\t\t\"%s!!! Welcome to Your Goblin Account!!!\"\n\n",G_name);
    printf("\n\t\t%c International Payments accepted\t\t\t\t     %c All rights are reserved\t\t\t\t     %c ISO 27001 certified",64,251,15);
    printf("\n\n\t\t%c  100%c Secure App \t\t\t\t\t\t     %c  Unified Payments Interface (UPI)\t\t     $ Sponsored by GOBLIN\n",3,37,5);
    while(1)
    {
        printf("\n\t............................................................................................................................................................................\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t     %c Menu\n",240);
        printf("\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
        printf("\n\n\t\t\t\t\t\t\t%-30s %-30s %-30s\n","1. Check Balance","2. Send Money","3. Add Money");
        printf("\n\t\t\t\t\t\t\t%-30s %-30s %-30s\n","4. View Transaction History","5. View Your Profile","6. View Your Bank Details");
        printf("\n\t\t\t\t\t\t\t%-30s\n","7. Logout");

        printf("\n\tEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            a=balance();
            printf("\n\tYour Account Balance : %d$",a);
            break;

        case 2 :
            G_Balance=balance();
            if(G_Balance==0)
            {
                printf("\n\tYou can't send the money, because you have Zero(0) Balance\n");
            }
            else
                send_money(G_phone,G_acc,G_mpin,G_Balance);
            break;

        case 3 :
            add_money();
            break;

        case 4 :
            display_history();
            break;

        case 5 :
            profile();
            break;

        case 6 :
            bank_details();
            break;

        case 7 :
            system("cls");
            main();
            break;

        default :
            printf("\n\tInvalid choice!!!\n");
            break;
        }
    }
}

char ph[35];

void send_money(char G_phone[],char G_acc[],char G_mpin[],int G_Balance)   // User is sending the money through UPI and Bank Transfer
{
    int ch,i,flag=0;
    char pin[10];
    printf("\n\tPay Through.....!\n");
    printf("\n\t1. UPI\t\t 2. Bank Transfer\t 3. Return Back\n");
    printf("\n\tEnter Your Choice : ");
    fflush(stdin);
    scanf("%d",&ch);

    if(ch==1)
    {
PHONE1:
        {
            printf("\n\tEnter UPI ID : ");
            scanf("%s",ph);
        }
        duplicate_account(ph,3);
        length=strlen(ph);
        if(length<10)
        {
            printf("\n\tUPI ID can't less than 10\n");
            goto PHONE1;
        }

        if(!strcmp(ph,G_phone))
        {
            printf("\n\tYou can't send the money to your account,Because you have entered your number\n");
            return;
        }

        else
        {
AMOUNT1:
            {
                printf("\n\tEnter the Amount : $");
                scanf("%d",&amount);
            }
            if(amount==0)
            {
                printf("\n\tAmount can't be zero\n");
                goto AMOUNT1;
            }
            else if(amount<0)
            {
                printf("\n\tAmount can't be negative\n");
                goto AMOUNT1;
            }

            printf("\n\t Enter the MPIN : ");
            takepassword(pin);

            if(!strcmp(pin,G_mpin))
            {
                G_Balance=balance();
                if(G_Balance<amount)
                {
                    printf("\n\n\tInsufficient Balance\n");
                    return;
                }
                else
                {
                    G_Balance=G_Balance-amount;
                    update_balance(G_Balance,G_acc);
                    int n;
                    n=strlen(G_acc);
                    printf("\n\n\tSuccessful :) \n \t\t      %d$ debited @%s from A/C XXXX-XXXX-%c%c%c%c\n",amount,G_bank,G_acc[n-4],G_acc[n-3],G_acc[n-2],G_acc[n-1]);
                    add_history(1);
                    return;
                }
            }
            else
            {
                printf("\n\n\t Wrong!!! MPIN :(\n");
                return;
            }
        }
    }

    else if(ch==2)
    {
        printf("\n\tEnter Bank Account holder name : ");
        fflush(stdin);
        scanf("%[^\n]s",B_name);

ACCOUNT2:
        {
            printf("\n\tEnter Bank Account Number : ");
            fflush(stdin);
            scanf("%[^\n]s",B_acc);
            {
                for(i=0; B_acc[i]!='\0'; i++)
                {
                    if((B_acc[i]>=48 && B_acc[i]<=57)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    printf("\n\tOnly Numericals are allowed\n");
                    flag=0;
                    goto ACCOUNT2;
                }
                else
                {
                    if(i<11)
                    {
                        printf("\n\t Account number length should be minimum 11\n");
                        goto ACCOUNT2;
                    }
                }
            }
        }

        printf("\n\t Enter Bank Name : ");
        fflush(stdin);
        scanf("%[^\n]s",B_bank);

IFSC1:
        {
            printf("\n\t Enter Bank IFSC code : ");
            fflush(stdin);
            scanf("%s",B_ifsc);
        }
        length=strlen(B_ifsc);
        if(length<11)
        {
            printf("\n\t IFSC code length should not be less than 11\n");
            goto IFSC1;
        }

AMOUNT2:
        {
            printf("\n\tEnter the Amount : $");
            scanf("%d",&amount);
        }
        if(amount==0)
        {
            printf("\n\tAmount can't be zero\n");
            goto AMOUNT2;
        }
        else if(amount<0)
        {
            printf("\n\tAmount can't be negative\n");
            goto AMOUNT2;
        }

        printf("\n\t Enter the MPIN : ");
        takepassword(pin);

        if(!strcmp(pin,G_mpin))
        {
            G_Balance=balance();
            if(G_Balance<amount)
            {
                printf("\n\n\tInsufficient Balance\n");
                return;
            }
            else if(!strcmp(G_acc,B_acc))
            {
                printf("\n\n\tYou can't send the money to your account,Because you have entered your account number\n");
                return;
            }
            else
            {
                G_Balance=G_Balance-amount;
                update_balance(G_Balance,G_acc);
                int n;
                n=strlen(G_acc);
                printf("\n\n\tSuccessful :) \n \t\t      %d$ debited @%s from A/C XXXX-XXXX-%c%c%c%c\n",amount,G_bank,G_acc[n-4],G_acc[n-3],G_acc[n-2],G_acc[n-1]);
                add_history(2);
                return;
            }
        }
        else
        {
            printf("\n\t Wrong!!! MPIN :(\n");
            return;
        }
    }
    else
        return;
}

void add_history(int value)    // Updating the customer's transaction history once user made the payment
{
    int i;
    HISTORY temp;
    FILE *fp;
    fp=fopen(G_acc,"a");

    temp.value=value;
    if(value==1)
    {
        strcpy(temp.facc,G_acc);
        strcpy(temp.tacc,ph);
        temp.credit=0;
        temp.debit=amount;
        temp.balance=G_Balance-amount;
        fwrite(&temp,sizeof(HISTORY),1,fp);
    }
    else if(value==2)
    {
        strcpy(temp.facc,G_acc);
        strcpy(temp.tacc,B_acc);
        temp.credit=0;
        temp.debit=amount;
        temp.balance=G_Balance-amount;
        fwrite(&temp,sizeof(HISTORY),1,fp);
    }
    else
    {
        strcpy(temp.facc,B_acc);
        strcpy(temp.tacc,G_acc);
        temp.credit=amount;
        temp.debit=0;
        temp.balance=G_Balance;
        fwrite(&temp,sizeof(HISTORY),1,fp);
    }
    fclose(fp);
}

void display_history()       // Printing the transaction history of the customer
{
    HISTORY temp;
    FILE *fp;

    fp=fopen(G_acc,"r");
    printf("\n\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t  Your Transaction History\n");
    printf("\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
    printf("\n\t\t\t\t\t.................................................................................................................\n");
    printf("\n\t\t\t\t\t    %-25s     %-30s%-15s   %-15s   %-15s\n\t\t\t\t\t%-27s%-35s   %-15s %-15s    %-15s","From","To","Debited","Credited","Balance","Card/Account Number","UPI/Account Number","(Sent)","(Received)","(Total)");
    printf("\n\t\t\t\t\t.. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. ..\n");
    printf("\n\t\t\t\t\t%-25s   %-35s  -$%-15s  +$%-15s $%-15d\n\t\t\t\t\t   (Cash Bonus)\n","Goblin Pay Company.Ltd",G_acc,"0","500",500);
    while(fread(&temp,sizeof(HISTORY),1,fp))
    {
        printf("\n\t\t\t\t\t     -  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  -\n");
        printf("\n\t\t\t\t\t%-25s   %-35s  -$%-15d  +$%-15d $%-15d\n",temp.facc,temp.tacc,temp.debit,temp.credit,temp.balance);
    }
    fclose(fp);
}

void add_money()      // Customer is adding the money through credit card
{
    char ch[1];
    int i,flag=0;
    printf("\n\tYou can add the money through your Credit card only\n\n\t Do you have Credit card? (Y/N) : ");
    scanf("%s",ch);

    if(!strcmp(ch,"Y") || !strcmp(ch,"y"))
    {
        printf("\n\tEnter Card holder name : ");
        fflush(stdin);
        scanf("%[^\n]s",B_name);

CARD:
        {
            printf("\n\tEnter Card Number : ");
            fflush(stdin);
            scanf("%[^\n]s",B_acc);
        }
        {
            for(i=0; B_acc[i]!='\0'; i++)
            {
                if((B_acc[i]>=48 && B_acc[i]<=57)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("\n\tOnly Numericals are allowed\n");
                flag=0;
                goto CARD;
            }
            else
            {
                if(i!=16)
                {
                    printf("\n\tCard number length should be 16 (XXXX-XXXX-XXXX-XXXX)\n");
                    goto CARD;
                }
            }
        }

        printf("\n\tEnter CVV : ");
        fflush(stdin);
        takepassword(B_cvv);

BMONTH:
        {
            printf("\n\t Valid through\n\n\t Month : ");
            fflush(stdin);
            scanf("%d",&B_month);
        }
        if(B_month<=0 || B_month>=13)
        {
            printf("\n\tPlease enter valid month between 1-12\n");
            goto BMONTH;
        }

BYEAR:
        {
            printf("\n\t Year : ");
            fflush(stdin);
            scanf("%d",&B_year);
        }
        if(B_year<=2021)
        {
            printf("\n\tYour credit card is already expired!!!\n");
            return;
        }
        else if(B_year<=2021 || B_year>=2028)
        {
            printf("\n\tPlease enter valid year, card valid through only 5 years\n");
            goto BYEAR;
        }
        else if(B_year==2022 && B_month<=2)
        {
            printf("\n\tYour credit card is already expired!!!\n");
            return;
        }

AMOUNT3:
        {
            printf("\n\t Enter the Amount : $");
            scanf("%d",&amount);
        }
        if(amount==0)
        {
            printf("\n\t Amount can't be zero\n");
            goto AMOUNT3;
        }
        else if(amount<0)
        {
            printf("\n\t Amount can't be negative\n");
            goto AMOUNT3;
        }
        else if(amount>20000)
        {
            printf("\n\t There is Limit with card, Maximum 20,000$ is allowed\n");
            goto AMOUNT3;
        }


        printf("\n\t Enter the Card password : ");
        takepassword(B_pin);

        G_Balance=balance();

        G_Balance=G_Balance+amount;
        update_balance(G_Balance,G_acc);
        int n;
        n=strlen(B_acc);
        printf("\n\n\tSuccessful :) \n \t\t      %d$ Credited from Credit card number XXXX-XXXX-XXXX-%c%c%c%c\n",amount,B_acc[n-4],B_acc[n-3],B_acc[n-2],B_acc[n-1]);
        add_history(3);
        return;
    }
    else
        return;
}

void Login()      // This function makes the Customer to logging into their account
{
    char phone[12],pword[50];
    GOBLIN G;
    int Found=0;
    FILE *fp;
    int choice;

    while(1)
    {
        printf("\n\tEnter Your Registered Mobile Number : ");
        scanf("%s",phone);
        strcpy(G_phone,phone);

        printf("\n\n\t 1. I know password\t 2. I forgot my password\n\n");
        printf("\tEnter Your Choice :  ");
        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            fflush(stdin);
            printf("\n\tEnter Your Goblin Password  :\t");
            takepassword(pword);
            fp=fopen("Account","r");
            while(fread(&G,sizeof(GOBLIN),1,fp))
            {
                if(!strcmp(phone,G.phone))
                {
                    if(!strcmp(G.password,pword))
                    {
                        strcpy(G_acc,G.acc);
                        strcpy(G_name,G.name);
                        strcpy(G_phone,G.phone);
                        strcpy(G_email,G.email);
                        strcpy(G_password,G.password);
                        strcpy(G_bank,G.bank);
                        strcpy(G_ifsc,G.ifsc);
                        strcpy(G_mpin,G.mpin);
                        G_Balance=G.balance;
                        fclose(fp);
                        system("cls");
                        account();

                    }
                    else
                    {
                        printf("\n\n\tOops....! Invalid Password!\n");
                        Beep(800,300);
                    }
                    Found=1;
                }
            }
            if(!Found)
            {
                printf("\n\n\t\t\tUser is not Registered!");
                Beep(800,300);
                return;
            }
            fclose(fp);
            break;

        case 2:
            password(phone);
            break;
        }

    }
}

void password(char phone[])     // Updating a password if user attempt to reset the password
{
    GOBLIN temp;
    FILE *fp,*fp1;
    int Found=0;
    char s_acc[20],pword[20];

    fp=fopen("Account","r");
    fp1=fopen("Temporary","w");

    printf("\n\tEnter Your Valid Account Number : ");
    scanf("%s",s_acc);

    while(fread(&temp,sizeof(GOBLIN),1,fp))
    {
        if(!strcmp(phone,temp.phone))
        {
            if(!strcmp(temp.acc,s_acc))
            {
                //strcpy(G_acc,temp.acc);

                printf("\n\t%-25s : ","Enter new Password");
                takepassword(temp.password);

                printf("\n\t%-25s : ","Confirm new Password");
                takepassword(pword);

                if(strcmp(temp.password,pword)==0)
                {

                }
                else
                {
                    printf("\n\t Password doesn't matched\n");
                    return;
                }
            }
            else
            {
                printf("\n\n\tInvalid Account Number!\n");
                Beep(800,300);
                main();
            }
            Found=1;
        }
        fwrite(&temp,sizeof(GOBLIN),1,fp1);
    }
    if(!Found)
    {
        printf("\n\n\t\t\tUser is not Registered!");
        Beep(800,300);
        main();
    }
    fclose(fp);
    fclose(fp1);
    if(Found)
    {
        fp1=fopen("Temporary","r");
        fp=fopen("Account","w");
        while(fread(&temp,sizeof(GOBLIN),1,fp1))
        {
            fwrite(&temp,sizeof(GOBLIN),1,fp);
        }
        fclose(fp);
        fclose(fp1);

        printf("\n\tYour Password is updated\n");
    }
    else
        printf("\n\t\t\tAccount not Found\n");

}

void update_balance(int Balance,char G_acc[])  //  Updating balance in a account after user made a payment
{
    GOBLIN temp;
    FILE *fp,*fp1;
    int Found=0;

    fp=fopen("Account","r");
    fp1=fopen("Temporary","w");

    while(fread(&temp,sizeof(GOBLIN),1,fp))
    {
        if(!strcmp(temp.acc,G_acc))
        {
            temp.balance=Balance;
        }
        Found=1;
        fwrite(&temp,sizeof(GOBLIN),1,fp1);
    }

    fclose(fp);
    fclose(fp1);
    if(Found)
    {
        fp1=fopen("Temporary","r");
        fp=fopen("Account","w");
        while(fread(&temp,sizeof(GOBLIN),1,fp1))
        {
            fwrite(&temp,sizeof(GOBLIN),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}

void profile()        // Printing the basic information about customer
{
    GOBLIN temp;
    FILE *fp;

    fp=fopen("Account","r");
    while(fread(&temp,sizeof(GOBLIN),1,fp))
    {
        if(!strcmp(G_acc,temp.acc))
        {
            printf("\n\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\tYour Profile\n");
            printf("\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
            printf("\n\t\t\t\t\t\t\t\t\t\tName : %-25s\n",temp.name);
            printf("\n\t\t\t\t\t\t\t\t\t\tPhone Number : %-25s\n",temp.phone);
            printf("\n\t\t\t\t\t\t\t\t\t\tEmail : %-25s\n",temp.email);

            if(strcmp(temp.gender,"Male")==0)
                printf("\n\t\t\t\t\t\t\t\t\t\tGender : (%c)) %-25s\n",11,temp.gender);
            else
                printf("\n\t\t\t\t\t\t\t\t\t\tGender : (%c)) %-25s\n",12,temp.gender);

            printf("\n\t\t\t\t\t\t\t\t\t\tDate of Birth : %d/%d/%d\n",temp.dob[0],temp.dob[1],temp.dob[2]);
            printf("\n\t\t\t\t\t\t\tAddress : %-25s\n",temp.address);
            printf("\n\t\t\t\t\t\t\t\t\t\t%s, %s, %s, %s - %s\n",temp.place,temp.district,temp.state,temp.country,temp.pincode);
        }
    }
    fclose(fp);
}

void bank_details()  // Printing the bank details of customer
{
    GOBLIN temp;
    FILE *fp;

    fp=fopen("Account","r");
    while(fread(&temp,sizeof(GOBLIN),1,fp))
    {
        if(!strcmp(G_acc,temp.acc))
        {
            printf("\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\tYour Bank Details\n");
            printf("\t\t\t\t\t\t\t\t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");
            printf("\n\t\t\t\t\t\t\t\t\t\tAccount Holder Name : %-25s\n",temp.name);
            printf("\n\t\t\t\t\t\t\t\t\t\tAccount Number : %-25s\n",temp.acc);
            printf("\n\t\t\t\t\t\t\t\t\t\tBank Name : %-25s\n",temp.bank);
            printf("\n\t\t\t\t\t\t\t\t\t\tBank IFSC Code : %-25s\n",temp.ifsc);
            printf("\n\t\t\t\t\t\t\t\t\t\tAccount Type : %-25s\n",temp.type);
        }
    }
    fclose(fp);
}

int main()
{
    int choice;
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\"Welcome To Goblin Pay\"\n");
    while(1)
    {
        printf("\n\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n\t\t\t\t\t%-40s %-40s %-30s\n","1. Create Goblin Pay Account","2. Login to Your Goblin Account","Press any key to Exit");
        fflush(stdin);
        printf("\n\tEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1 :
            create();
            break;

        case 2 :
            Login();
            break;

        default :
            exit(0);
        }
    }
    return 0;
}
