int reverseBits(int n) {
    unsigned int num = (unsigned int)n; 
    unsigned int rev = 0;
    for (int i = 0; i < 32; i++) {
        rev = rev << 1;      
        if (num & 1) {      
            rev = rev | 1;   
        }
        num = num >> 1;  
    }
    return (int)rev;
}