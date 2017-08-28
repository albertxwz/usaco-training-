{
ID:10179811
PROG:combo
LANG:PASCAL
#FILE
}

var
	john,mas,a:array[1..3] of longint;
	i,j,k,n,ans:longint;

function judge:boolean;
var
	i:longint;
	flag:boolean;
begin
	flag:=true;
	for i:=1 to 3 do
		//if (abs(a[i]-john[i])>2) and ((a[i]+n-1) mod n+1-john[i]>2) and ((n-a[i]-1) mod n+1-john[i]>2) then
		if (a[i]<>john[i]) and ((john[i]+1) mod n+1<>a[i]) and (john[i] mod n+1<>a[i]) and ((john[i]+n-3) mod n+1<>a[i]) and ((john[i]+n-2) mod n+1<>a[i]) then
		begin
			flag:=false;
			break;
		end;
	if flag then exit(true);
	for i:=1 to 3 do
		//if (abs(a[i]-mas[i])>2) and ((a[i]+n-1) mod n+1-mas[i]>2) and ((n-a[i]-1) mod n+1-mas[i]>2) then exit(false);
		if (a[i]<>mas[i]) and ((mas[i]+1) mod n+1<>a[i]) and (mas[i] mod n+1<>a[i]) and ((mas[i]+n-3) mod n+1<>a[i]) and ((mas[i]+n-2) mod n+1<>a[i]) then exit(false);
	exit(true);
end;

begin
	assign(input,'combo.in'); reset(input);
	assign(output,'combo.out'); rewrite(output);
	readln(n);
	for i:=1 to 3 do read(john[i]); readln;
	for i:=1 to 3 do read(mas[i]); readln;
	ans:=0;
	for i:=1 to n do
		for j:=1 to n do
			for k:=1 to n do
			begin
				a[1]:=i;
				a[2]:=j;
				a[3]:=k;
				if judge then inc(ans);
			end;
	writeln(ans);
	close(input);
	close(output);
end.
