;// cpp1401.cpp ====================
startup   jsr main
          halt
;==============================================================
							;#include <iostream>
							;using namespace std;
							;class C
							;{
							; public:
							; int f();
							; int x;
							;};
@C@f$       push lr  		;int C::f()
			push fp
			mov fp,sp
							;{
			pop r0  		; return x;
			mov r0,5
			mov sp,fp
			pop fp
			pop lr
			ret
							
							;}
main		push lr			;int main()
			push fp
			mov fp,sp
							;{
			add sp,sp,-1	; C c;
			mov r0,5		; c.x = 5;
			push r0
			add r0,fp,-1
			push r0
			jsr @C@f$
							; cout << C.f() << endl;
			dout
			nl
			mov r0,0     	;   return 0;
		    mov sp, fp
		    pop fp
            pop lr
            ret             ;}
