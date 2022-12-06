@.strlit = private unnamed_addr constant [4 xi8] c"%s\0A\00",align 1
@.newline = private unnamed_addr constant [2 xi8] c"\0A\00",align 1
@.intlit = private unnamed_addr constant [4 xi8] c"%d\0A\00",align 1
@.reallit = private unnamed_addr constant [7 xi8] c"%.08f\0A\00",align 1
@.boollit = private unnamed_addr constant [4 xi8] c"%d\0A\00",align 1
declare i32 @atoi(...)
declare i32 @printf(i8*,...)

@.strture = private unnamed_addr constant [6 xi8] c"true\0A\00",align 1
@.strfalse = private unnamed_addr constant [7 xi8] c"false\0A\00",align 1
define dso_local void @print_bool(i1) #0 {
	%2 = alloca i1
	store i1 %0, i1* %2
	%3 = load i1, i1* %2
	%4 = icmp ne i1 %3, 0
	br i1 %4, label %true, label %false
true:
	%5 = call i32( i8*,...) @printf(i8* getelementptr inbounds ([6 x i8],[6 x i8]* @.strtrue, i32 0, i32 0))
	br label %end

false:
	%6 = call i32( i8*,...) @printf(i8* getelementptr inbounds ([7 x i8],[7 x i8]* @.strfalse, i32 0, i32 0))
	br label %end

end:
	ret void
}
define i32 @operators(i32 %n) {}
define i32 @main(i32 %argc, i8** argv) {}Line 8, col 17: Operator * cannot be applied to types none, double
Line 8, col 10: Operator = cannot be applied to types double, undef
Line 16, col 9: Cannot find symbol operators()
