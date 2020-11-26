#include <cstring>
#include <iostream.h>
#include <unistd.h>

class N {
public:
	int 	(N::*f)(N&);
	char 	buf[96];
	int 	val;

	N(int val) {
		val = val;
		f = &N::operator+; <== why ?

//		(gdb) disas
//			Dump of assembler code for function _ZN1NC2Ei:
//				=> 0x080486f6 <+0>:	push   %ebp
//				0x080486f7 <+1>:	mov    %esp,%ebp
//				0x080486f9 <+3>:	mov    0x8(%ebp),%eax
//				0x080486fc <+6>:	movl   $0x8048848,(%eax) <== because
//				0x08048702 <+12>:	mov    0x8(%ebp),%eax
//				0x08048705 <+15>:	mov    0xc(%ebp),%edx
//				0x08048708 <+18>:	mov    %edx,0x68(%eax)
//				0x0804870b <+21>:	pop    %ebp
//				0x0804870c <+22>:	ret
//
//	But this syntax is invalid...
//	When looking at the heap dump, there is an empty word before the buffer :
//	(gdb) x/60wx 0x804b000
//	0x804b000:	0x00000000	0x00000071	0x080486c2	0x00000000
//	0x804b010:	0x6f746f74	0x00000000	0x00000000	0x00000000
//	...

	}

	int operator+(N &other) {
		return val + other.val;
	}

	int operator-(N &other) {
		return val - other.val;
	}

//	(gdb) disas 0x0804870e
//		Dump of assembler code for function _ZN1N13setAnnotationEPc:
//			0x0804870e <+0>:	push   %ebp
//			0x0804870f <+1>:	mov    %esp,%ebp
//			0x08048711 <+3>:	sub    $0x18,%esp
//			0x08048714 <+6>:	mov    0xc(%ebp),%eax <== str
//			0x08048717 <+9>:	mov    %eax,(%esp)
//			0x0804871a <+12>:	call   0x8048520 <strlen@plt>
//			0x0804871f <+17>:	mov    0x8(%ebp),%edx
//			0x08048722 <+20>:	add    $0x4,%edx
//			0x08048725 <+23>:	mov    %eax,0x8(%esp)
//			0x08048729 <+27>:	mov    0xc(%ebp),%eax
//			0x0804872c <+30>:	mov    %eax,0x4(%esp)
//			0x08048730 <+34>:	mov    %edx,(%esp)
//			0x08048733 <+37>:	call   0x8048510 <memcpy@plt>
//			0x08048738 <+42>:	leave
//			0x08048739 <+43>:	ret
//			End of assembler dump.

	void setAnnotation(char *str) {
		memcpy(buf, str, strlen(str));
	}

};

int 	main(int argc, char *argv[]) {
	if (argc < 2)
		_exit(1);

	N	*obj1 = new N(5), *obj2 = new N(6);
	N	&i = *obj1, &j = *obj2;

	i.setAnnotation(argv[1]);

	return i + j; // invalid
	// returns :
	// 	0x0804862c <+136>:	mov    0x1c(%esp),%eax
	//  0x08048630 <+140>:	mov    %eax,0x4(%esp)
	//  0x08048634 <+144>:	mov    0x18(%esp),%eax
	//  0x08048638 <+148>:	mov    %eax,(%esp)
	//  0x0804863b <+151>:	call   0x80486c2 <_ZN1NplERS_>
	//  0x08048640 <+156>:	mov    -0x4(%ebp),%ebx
	// should be :
	//	0x0804867c <+136>:	mov    0x10(%esp),%eax
	//	0x08048680 <+140>:	mov    (%eax),%eax
	//	0x08048682 <+142>:	mov    (%eax),%edx
	//	0x08048684 <+144>:	mov    0x14(%esp),%eax
	//	0x08048688 <+148>:	mov    %eax,0x4(%esp)
	//	0x0804868c <+152>:	mov    0x10(%esp),%eax
	//	0x08048690 <+156>:	mov    %eax,(%esp)
	//	0x08048693 <+159>:	call   *%edx
	//	0x08048695 <+161>:	mov    -0x4(%ebp),%ebx
}
