{
ID:10179811
PROG:skidesign
LANG:PASCAL
#FILE
}

var
	a:array[1..1000] of longint;
	i,j,ans,temp,n:longint;

begin
	assign(input,'skidesign.in'); reset(input);
	assign(output,'skidesign.out'); rewrite(output);

	readln(n);
	for i:=1 to n do readln(a[i]);
	ans:=maxlongint;
	for i:=0 to 83 do
	begin
		temp:=0;
		for j:=1 to n do
		begin
			if i+17<a[j] then temp:=temp+sqr(a[j]-i-17);
			if i>a[j] then temp:=temp+sqr(i-a[j]);
		end;
		if temp<ans then ans:=temp;
	end;
	
	writeln(ans);
	
	close(input);
	close(output);
end.
