#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {     // function defined to swap two numbers
    int num;
    num=*a;
    *a = *b;
    *b = num;
}

int main()
{

    int a[28]={1,4,7,10,13,16,19,22,25,28,3,6,9,12,15,18,21,24,27,2,5,8,11,14,17,20,23,26};
    int i,num,num2, position1,position2,triple_cut[28];
    int location_27,location_28, location_3,location_4;
    int top_card,key_stream[20];
    int temp3[30], sum[30];
    int b, length, j=0, c=0;
    char encrypted_seq[20];
    int decoded_numbers[20];
    char decoded_characters[20];
    char str[20];
    char des[30];
    int letters_to_num[30];

    printf("+---------------------+\n");
    printf("| Solitaire Algorithm |\n");
    printf("+---------------------+\n\n");
    printf("Input Message. ");
    gets(str);          // inputs string from user


    printf("\nENCRYPTED PROGRAM:\n\n");
    for (i=0; i<strlen(str); i++) {
            if (str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z') {
            des[j]=str[i];
            j++;
            length=j;
    }
    }
    /* separates alphabetical characters from the input string and stores in another
    array des[] */

    length=j;       // length equals the number of alphabetical characters in string

    printf("Cleaned Message:    ");
    for(j=0;j<length;j++){      //converts all the alphabetical characters to upper case letters
            printf("%c\t", toupper(des[j]));
    }


    printf("\nLetters to Numbers: ");
    for (j=0; j<length; j++){
        if (des[j]>='a' && des[j]<='z') {
            des[j]=des[j]-96;
            letters_to_num[j]=des[j];
            printf("%d\t", des[j]);
        } else {
            des[j]=des[j]-64;
            letters_to_num[j]=des[j];
            printf("%d\t", des[j]);
        }
    }
    /* converts letters to numbers ranging from 1-26 */

    int m=0;
    printf("\nGen. Key streams:   ");

    while (m<length){   // generates key stream values equal to the number of alphabets

    for (i=0; i<28; i++) {
        a[i];
    }

    i=0;
    while (i<28) {
        if (a[i]==27) {
            swap(&a[i],&a[i+1]);
            break;
        }
        i++;
    }
    /* while loop searches for 27 in the array and swaps it with the adjacent number
        */
    for (i=0; i<28; i++) {
        a[i];
    }

    i=0;
    while (i<28) {
        if (a[i]==28) {
            swap(&a[i],&a[i+1]);
            swap(&a[i+1],&a[i+2]);
            break;
        }
        i++;
    }
    // the while loop searches for 28 and moves it two position ahead

    for (i=0; i<28; i++) {
        a[i];
    }

    for (i=0;i<28;i++) {
        if (a[i]==27){
            location_27=i;
        }
        if (a[i]==28) {
            location_28=i;
        }
    }
    // determines the new positions of 27 and 28

    if (location_27>location_28) {
        location_3=location_27;
        location_4=location_28;     // if 28 comes first in the last, make its location equal to location_4
    } else {
        location_4=location_27;     // if 27 comes first in the last, make its location equal to location_4
        location_3=location_28;
    }

    for (i=location_3+1, j=0; i<28; i++,j++) {
        triple_cut[j]=a[i];
    }

    for (i=location_4, j=28-location_3-1; i<=location_3; i++,j++) {
        triple_cut[j]=a[i];
    }

    for (i=0, j=28-location_4;i<location_4, j<28; i++,j++) {
        triple_cut[j]=a[i];
    }

    /* performs triple cut operation by making chunks of the last saved array. And storing it in
       a temporary triple_cut array as desired */

    int last_card= triple_cut[27];  // stores the value of last card in another variable last_card

    for (i=0, j=28-last_card-1; i<last_card; i++,j++) {
        temp3[j]=triple_cut[i];
    }

    for (i=last_card, j=0; i<27; i++,j++) {
        temp3[j]=triple_cut[i];
    }
    temp3[27]=last_card;

    /* divides triple_cut array to two chunks and stores them in a temporary array temp3
       as desired */
    top_card=temp3[0];

    for (i=0;i<28;i++){     // initializes the new array
        a[i]=temp3[i];
    }
    key_stream[m]=temp3[top_card];  // the card number equal to the value of top_card is
                                    // our key stream value
    if (key_stream[m]>26){

    } else {
        printf("%d\t", key_stream[m]);
        m++;
    }
    /* if key stream value is greater than 26, that key stream is destroyed and is
       generated again else key stream value is stored in key_stream array and printed */
}
    printf("\n");

    // encoding process starts below

    printf("Encoded Numbers:    ");
    for (i=0;i<length;i++) {
        sum[i]= letters_to_num[i]+key_stream[i];
        if (sum[i]>26) {
            sum[i]=sum[i]%26;
        }
        printf("%d\t", sum[i]);
    }
    // sums the numerical value of alphabets and key stream values to generate encoded numbers

    printf("\n");
    printf("Encoded Message:    ");
    for (i=0; i<length; i++) {
        encrypted_seq[i]=sum[i]+64;
        printf("%c\t", encrypted_seq[i]);   // prints encrypted sequence from encoded numbers
    }

    // Decryption process starts below
    printf("\n\nDECRYPTED MESSAGE:\n\n");
    printf("Encoded Message:    ");
    for (i=0; i<length; i++) {
        encrypted_seq[i]=sum[i]+64;
        printf("%c\t", encrypted_seq[i]);   // prints encrypted alphabetical sequence
    }
    printf("\n");
    printf("Letters to Numbers: ");
    for (i=0; i<length; i++) {
        sum[i]=encrypted_seq[i]-64;
        printf("%d\t", sum[i]);             // prints encoded numbers from encrypted sequence
    }
    printf("\n");
    printf("Gen. Keystreams:    ");
    for (i=0; i<length; i++) {
        printf("%d\t",key_stream[i]);       // prints key stream values as generated in first task
    }

    printf("\nDecoded Numbers:    ");
    for (i=0;i<length;i++) {
        decoded_numbers[i]=sum[i]-key_stream[i];
        if (decoded_numbers[i]<0) {
            decoded_numbers[i]=decoded_numbers[i]+26;
            printf("%d\t", decoded_numbers[i]);
        } else {
            printf("%d\t", decoded_numbers[i]);
        }
    }
    /* Generates decoded numbers by subtracting key stream values from the sum.
       if the decoded number has negative value, add 26 to it. */

    printf("\nDecoded Message:    ");
    for (i=0;i<length; i++) {
        decoded_characters[i]=decoded_numbers[i]+64;
        printf("%c\t", decoded_characters[i]);
        }
    printf("\n");
}
