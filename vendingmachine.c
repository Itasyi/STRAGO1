#include<stdio.h>
#define max  100

int ans[max];

int findMinCoins(int coins[], int size,  int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        while(value >= coins[i])
        {
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;

    }

    return count;
}

int main()
{
    int price, cash, total;
    total = 0;
    
    printf("Enter price: ");
    scanf("%d", &price);
    
    printf("input cash: ");
    scanf("%d", &cash);
    
    int coins[] = {1000,500,200,100};
    int value = (cash - price), i;

    int size = sizeof(coins)/sizeof(coins[0]);

    int MinCount = findMinCoins(coins,size,value);

    printf("Total Coins: %d\n",MinCount);

    printf("Coins are: ");
    for(i = 0; i < MinCount; i++) {
        total += ans[i];
        printf("%d ", ans[i]);
    }
    printf("\nTotal: %d\n",total);
    return 0;
}
