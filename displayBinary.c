int reverse(x) {
    int reversenum=0;
    int remainder;
    while (x!=0)
    {
        remainder=x%10;
        reversenum=reversenum*10+remainder;
        x=x/10;
    }
    return reversenum;
}
main(){
    int n;
    printf('Enter number to reverse: ');
    scanf('%d',&n);
    int reverse_n=reverse(n);
}
