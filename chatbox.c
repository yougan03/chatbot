#include <stdio.h>
#include<string.h>
#include<stdbool.h>

#define min 100
#define max 300
#define size 100

void chatbot(float user,bool offer_deal) 
{
    if (user < min) 
    {
        printf("I'm sorry, but the minimum price is %.2d\n", min);
    }
    else if (user > max)
    {
        printf("That's too high. How about %.2d\n", max);
    } 
    if(offer_deal) 
    {
        printf("Thank you for your offer of %.2f. I can accept that! and offer bonus deals\n", user * 0.95);
    }
	else
	{
		printf("offer of %.2f\n",user);
	}
    
}
bool analyze_sentiment(char *offer)
{
	if(strstr(offer,"average") || strstr(offer,"great") || strstr(offer,"evenmore"))
		return true;
	else
		return false;
}

int main() {
    float user;
    char offer[size];

    printf("\033[31m Welcome to the chatbot! \033[0m\n");
    printf("\033[32m Please enter your desired price:  \033[0m");

    // Get user input using scanf
    scanf("%f", &user);

    while(getchar() != '\n');
    //input for discount deal
    printf("\033[33m Give me your feeling such as average,great,more and evenmore:  \033[0m");
    scanf("%[^\n]",offer);

    bool offer_deal=analyze_sentiment(offer);

    // Call chatbot function
    chatbot(user,offer_deal);

    return 0;
}

