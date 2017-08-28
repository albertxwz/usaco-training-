{
ID:10179811
PROG:zerosum
LANG:PASCAL
#FILE
}

var
	s:array[1..9] of char;
	oper:array[1..3] of char;
	a:array[1..9] of integer;
	i,n:longint;

procedure insort;
var
	i,j,x:integer;
	key:char;
begin
	for i:=2 to 3 do
	begin
		key:=oper[i];
		x:=0;
		for j:=i-1 downto 1 do
			if key<oper[j] then
			begin
				oper[j+1]:=oper[j];
				x:=j;
			end
			else break;
		if x<>0 then oper[x]:=key;
	end;
end;

function judge:boolean;
var
	i,temp,sum,j:longint;
	f:array[1..9] of boolean;
begin
	fillchar(f,sizeof(f),true);
	sum:=0;
	for i:=1 to n do
		if f[i] then
		begin
			f[i]:=false;
			j:=i+1;
			temp:=a[i];
			while s[j]=' ' do
			begin
				f[j]:=false;
				temp:=temp*10+a[j];
				inc(j);
			end;
			if s[i]='+' then sum:=sum+temp
			else sum:=sum-temp;
		end;
	if sum=0 then exit(true)
	else exit(false);
end;

procedure print;
var
	i:longint;
begin
	write(a[1]);
	for i:=2 to n do
		write(s[i],a[i]);
	writeln;
end;

procedure dfs(i:longint);
var
	j:longint;
begin
	if i=n+1 then
	begin
		if judge then print;
		exit;
	end;
	for j:=1 to 3 do
	begin
		s[i]:=oper[j];
		dfs(i+1);
	end;
end;

begin
	assign(input,'zerosum.in');
	reset(input);
	assign(output,'zerosum.out');
	rewrite(output);

	readln(n);
	for i:=1 to n do
		a[i]:=i;
	oper[1]:=' ';
	oper[2]:='+';
	oper[3]:='-';
	s[1]:='+';
	insort;
	dfs(2);
	
	close(input);
	close(output);
end.
	