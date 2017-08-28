{
ID:10179811
PROG:money
LANG:PASCAL
#FILE
}

var
	dp:array[0..10000] of int64;
	a:array[1..25] of longint;
	i,j,v,n:longint;

begin
	assign(input,'money.in');
	reset(input);
	assign(output,'money.out');
	rewrite(output);

	readln(v,n);
	fillchar(dp,sizeof(dp),0);
	dp[0]:=1;
	for i:=1 to v do read(a[i]);
	for i:=1 to v do
		for j:=a[i] to n do
			dp[j]:=dp[j]+dp[j-a[i]];
	writeln(dp[n]);
	
	close(input);
	close(output);
end.