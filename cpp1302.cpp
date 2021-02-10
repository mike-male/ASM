;// cpp1302.cpp ====================
startup   jsr main
          halt
;==============================================================
							;#include <iostream>
							;using namespace std;
x .fill 0					;int x;
f			push lr			;void f(int &x)
			push fp
			mov fp,sp
							;{
			ldr r0,fp,2		; x = 5;
			ldr r0,r0,0
			add r0,r0,5
			ldr r1,fp,2
			str r0,r1,0
			
			mov sp, fp
		    pop fp
            pop lr
            ret 				
							
							;}
main		push lr			;int main()
			push fp
			mov fp,sp
							;{
			lea r0,x		; f(x);
			push r0
			jsr f
			add sp,sp,1
			
			ld r0,x			;cout << x << endl;
			dout
			nl
			
			mov r0,0     	;   return 0;
		    mov sp, fp
		    pop fp
            pop lr
            ret 
							;}
