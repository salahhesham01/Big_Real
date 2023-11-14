#include "BigReal.h"

int main()
{
	string n1 = "42.12", n2 = "-10.24", n3 = "-500.244", n4 = "7.351";

	//TEST ONE
	BigReal r1(n1), r2(n2), r3, r4;
	r3 = r1 + r2;
	r4 = r1 - r2;
	cout << r3 << endl;
	cout << r4 << endl;
	cout << (r1 < r2) << endl;
	cout << (r1 > r2) << endl;
	cout << (r1 == r2) << endl;
	cout << r1.Size() << endl;
	cout << r1.Sign() << endl;
	
	//TEST TWO
	BigReal r5, r6, r7(n3), r8(n4);
	r5 = r7 + r8;
	r6 = r7 - r8;
	cout << r5 << endl;
	cout << r6 << endl;
	cout << (r7 < r8) << endl;
	cout << (r7 > r8) << endl;
	cout << (r7 == r8) << endl;
	cout << r7.Size() << endl;
	cout << r7.Sign() << endl;

	string n5 = "43.53", n6 = "-42.231", n7 = "-78.42", n8 = "89.63";
	
	//TEST THREE
	BigReal r9(n5), r10(n6), r11, r12;
	r11 = r9 + r10;
	r12 = r9 - r10;
	cout << r11 << endl;
	cout << r12 << endl;
	cout << (r9 < r10) << endl;
	cout << (r9 > r10) << endl;
	cout << (r9 == r10) << endl;
	cout << r9.Size() << endl;
	cout << r9.Sign() << endl;
	
	//TEST FOUR
	BigReal r13, r14, r15(n7), r16(n8);
	r13 = r15 + r16;
	r14 = r15 - r16;
	cout << r13 << endl;
	cout << r14 << endl;
	cout << (r15 < r16) << endl;
	cout << (r15 > r16) << endl;
	cout << (r15 == r16) << endl;
	cout << r15.Size() << endl;
	cout << r15.Sign() << endl;
	
	string n9 = "65.56", n10 = "12.32", n11 = "-83.65", n12 = "-12.32";
	
	//TEST FIVE
	BigReal r17(n9), r18(n10), r19, r20;
	r19 = r17 + r18;
	r20 = r17 - r18;
	cout << r19 << endl;
	cout << r20 << endl;
	cout << (r17 < r18) << endl;
	cout << (r17 > r18) << endl;
	cout << (r17 == r18) << endl;
	cout << r17.Size() << endl;
	cout << r17.Sign() << endl;
	
	//TEST SIX
	BigReal r21, r22, r23(n11), r24(n12);
	r21 = r23 + r24;
	r22 = r23 - r24;
	cout << r21 << endl;
	cout << r22 << endl;
	cout << (r23 < r24) << endl;
	cout << (r23 > r24) << endl;
	cout << (r23 == r24) << endl;
	cout << r23.Size() << endl;
	cout << r23.Sign() << endl;

}