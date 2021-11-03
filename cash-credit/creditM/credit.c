#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    //Functions explicit declarations
    bool is_card_valid(long card_num);

    long card;
    long cc_num;
    int digit;
    bool validation;

    do
    {
        card = get_long("Type in your card number:\n");
    }
    while (card < 0);

    cc_num = card;

    is_card_valid(cc_num);
}

bool is_card_valid(long card_num)
{
    int get_card_len(long card_num);
    int get_flag(long card_num, int cc_len);
    bool checksum(long card_num, int cc_len);


    int card_len;
    int digits_sum;
    int flag;

    card_len = get_card_len(card_num);
    flag = get_flag(card_num, card_len);

    if(card_len != 13 && card_len != 15 && card_len != 16)
    {
        printf("INVALID\n");
        return false;
    } else {
        if(checksum(card_num, card_len)){
            switch(flag)
            {
                case 34:
                case 37:
                    printf("AMEX\n");
                    break;
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    printf("MASTERCARD\n");
                    break;
                case 4:
                    printf("VISA\n");
                    break;
                default:
                    printf("INVALID\n");
            }
            return true;
        } else {
            return false;
        }
    }
}

bool checksum(long card_num, int cc_len)
{
    int digit;
    int first_digit;
    int second_digit;
    int digit_sum;
    int sum = 0;
    long cc = card_num;

    if(cc_len % 2 != 0)
    {
        for(int i = cc_len - 1; i >= 0; i--)
        {
            if(i % 2 != 0)
            {
                digit = 2 * (cc % 10);
                //printf("i: %d\n", i);
                //printf("d: %d\n\n", digit);
                cc /= 10;
                if(digit > 9)
                {
                    first_digit = digit / 10;
                    second_digit = digit % 10;
                    digit_sum = first_digit + second_digit;
                    //printf("dsum: %d\n\n", digit_sum);
                    sum += digit_sum;
                    //printf("csum: %d\n\n", sum);
                } else {
                    sum += digit;
                    //printf("csum: %d\n\n", sum);
                }
            } else {
                digit = cc % 10;
                //printf("i: %d\n", i);
                //printf("d: %d\n\n", digit);
                cc /= 10;
                sum += digit;
                //printf("csum: %d\n\n", sum);
            }
        }
    } else {
        for(int i = cc_len - 1; i >= 0; i--)
        {
            if(i % 2 == 0)
            {
                digit = 2 * (cc % 10);
                //printf("i: %d\n", i);
                //printf("d: %d\n\n", digit);
                cc /= 10;
                if(digit > 9)
                {
                    first_digit = digit / 10;
                    second_digit = digit % 10;
                    digit_sum = first_digit + second_digit;
                    //printf("dsum: %d\n\n", digit_sum);
                    sum += digit_sum;
                    //printf("csum: %d\n\n", sum);
                } else {
                    sum += digit;
                    //printf("csum: %d\n\n", sum);
                }
            } else {
                digit = cc % 10;
                //printf("i: %d\n", i);
                //printf("d: %d\n\n", digit);
                cc /= 10;
                sum += digit;
                //printf("csum: %d\n\n", sum);
            }
        }
    }



    if(sum % 10 == 0){
        return true;
    } else {
        printf("INVALID\n");
        return false;
    }
}

int get_flag(long card_num, int cc_len)
{
    long factor = pow(10, (cc_len - 2));
    int flag = card_num / factor;
    if(flag / 10 == 4)
    {
        return (flag / 10);
    } else {
        return flag;
    }
}

int get_card_len(long card_num)
{
    int length = 0;

    while(card_num != 0)
    {
        card_num /= 10;
        length++;
    }

    return length;
}

// 4003600000000014

// 4 0 0 3 6 0 0 0 0 0  0  0  0  0  1  4
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

// 378282246310005

// 3 7 8 2 8 2 2 4 6 3  1  0  0  0  5
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

// 5105105105105100

// 5 1 0 5 1 0 5 1 0 5  1  0  5  1  0  0
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

// 4222222222222
// 4 2 2 2 2 2 2 2 2 2  2  2  2
// 0 1 2 3 4 5 6 7 8 9 10 11 12