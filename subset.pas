{
ID:10179811
PROG:subset
LANG:PASCAL
#FILE
}

var
	f:array[0..39,0..1000] of longint;
	sum,j,i,n,ans:longint;

begin
	assign(input,'subset.in');
	reset(input);
	assign(output,'subset.out');
	rewrite(output);
	readln(n);
	//以下两行为边界
	f[1,1]:=1;
	f[1,0]:=1;
	sum:=n*(n+1) shr 1;
	if  sum mod 2=1 then writeln(0)			//判断有没有划分方案
	else
	begin
		sum:=(n*(n+1) div 2) div 2;
		for i:=2 to n do					//DP一下
			for j:=1 to sum do
				if j>i then f[i,j]:=f[i-1,j]+f[i-1,j-i]
				else f[i,j]:=f[i-1,j];
		writeln(f[n,sum]);
	end;
	close(input);
	close(output);
end.