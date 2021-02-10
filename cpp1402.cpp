;// cpp1402.cpp ====================
startup   jsr main
          halt
;==============================================================
;#include <iostream>
;using namespace std;
a .fill 0							;int a;
;class C
;{
; public:
; void f(int a);
; int x;
;};
									;void C::f(int a)
									;{
@C@f$i		push lr
			push fp
			mov fp,sp
			add sp,sp,-1						; x = a;
			mov r0,0
			push r0
			add sp,sp,-1						; y = a;
			mov r0,0
			push r0
			pop r0						; b = x + y;
			mov r1,r0
			pop r0
			add sp,sp,-1
			
			mov sp,fp
			pop fp
			pop lr
			ret
									;}
main		push lr					;int main()
			push fp
			mov fp,sp
									;{
			add sp,sp,-1    		; C c;
			mov r0,10				; c.f(10, a);
			push r0
			jsr @C@f$i
			add sp,sp,1
			
			ld r0,a						; cout << a << endl;
			dout
			nl
			mov r0,20						; c.f(20, a);
			push r0
			jsr @C@f$i
			add sp,sp,1
			
			ld r0,a						; cout << a << endl;
			dout
			nl
			
			mov r0,0     	;   return 0;
		    mov sp, fp
		    pop fp
            pop lr
            ret             ;}
