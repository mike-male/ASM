;// cpp1304.cpp ====================
startup   jsr main
          halt
		  halt
;==============================================================
							;#include <iostream>
							;using namespace std;
y .fill 3					;int y=3;
f			push lr			;void f(int &x)
			push fp
			mov fp,sp
							;{
			ldr r0,fp,2	
			ldr r0,r0,0
			brnz zero		; if (x) {
			lea r0,s1		; cout << "hello\n";
			puts
			nl
			
			ldr r0,fp,2		; x = x - 1;
			ldr r0,r0,0
			add r0,r0,-1
			ldr r1,fp,2
			str r0,r1,0
			
			ldr r0,fp,2		; f(x);
			ldr r0,r0,0
			push r0
			jsr f
			add sp,sp,1
							; }
zero		mov sp, fp
		    pop fp
            pop lr
            ret 			
							;}
main		push lr			;int main()
			push fp
			mov fp,sp
							;{
			lea r0,y		; f(y);
			push r0
			jsr f
			add sp,sp,1
			
			ld r0,y			; cout << y << endl;
			dout
			nl
			
			mov r0,0     	;   return 0;
		    mov sp, fp
		    pop fp
            pop lr
            ret 
							;}
s1 .stringz "hello"
