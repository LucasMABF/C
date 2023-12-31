#include <stdio.h>

int main(int argc, char **argv){
    #define TAXRATE 0.2
    float price;
    float tax;
    const float taxrate = 0.175;
    // taxrate = 0.3; cant redefine constant
    float total;

    price = 250;
    tax = price * taxrate;
    total = price + tax;

    printf("The tax on a product of price %5.2f is %5.2f, so the total is %5.2f\n", price, tax, total);
    #define TAXRATE 0.8
    printf("TAXRATE = %f\n", TAXRATE);

    return 0;

}