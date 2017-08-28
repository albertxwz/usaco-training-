{
ID:10179811
PROG:lamps
LANG:PASCAL
#FILE
}

type
	arr=array[1..100] of longint;

var
	clo,bright:array[1..100] of longint;
	ans:array[1..100] of arr;
	f:array[1..100] of boolean;
	n,m,i,j,k,l1,l2,x,ci:longint;
	a,b,c,d:longint;

procedure change1;
var
	i:longint;
begin
	for i:=1 to n do
		if f[i] then f[i]:=false
		else f[i]:=true;
end;

procedure change2;
var
	i:longint;
begin
	for i:=1 to n do
		if i mod 2=1 then
			if f[i] then f[i]:=false
			else f[i]:=true;
end;

procedure change3;
var
	i:longint;
begin
	for i:=1 to n do
		if i mod 2=0 then
			if f[i] then f[i]:=false
			else f[i]:=true;
end;

procedure change4;
var
	i:longint;
begin
	for i:=1 to n do
		if (i-1) mod 3=0 then
			if f[i] then f[i]:=false
			else f[i]:=true;
end;

function compare(a,b:arr):boolean;
var
	i:longint;
begin
	for i:=1 to n do
		if a[i]<b[i] then exit(true)
		else if b[i]<a[i] then exit(false);
	exit(false);
end;

procedure qsort(h,t:longint);
var
	temp,m:arr;
	i,j:longint;
begin
	m:=ans[(h+t) div 2];
	i:=h;
	j:=t;
	repeat
		while compare(ans[i],m) do inc(i);
		while compare(m,ans[j]) do dec(j);
		if i<=j then
		begin
			temp:=ans[i];
			ans[i]:=ans[j];
			ans[j]:=temp;
			inc(i); dec(j);
		end;
	until i>j;
	if h<j then qsort(h,j);
	if i<t then qsort(i,t);
end;

function judge:boolean;
var
	i,j:longint;
	flag:boolean;
begin
	for i:=1 to k do
	begin
		flag:=true;
		for j:=1 to n do
			if f[j] then
			begin
				if ans[i,j]=0 then
				begin
					flag:=false;
					break;
				end;
			end
			else if ans[i,j]=1 then
			begin
				flag:=false;
				break;
			end;
		if flag then exit(false);
	end;
	exit(true);
end;

function can:boolean;
var
	i:longint;
begin
	for i:=1 to l1 do
		if f[bright[i]]=false then exit(false);
	for i:=1 to l2 do
		if f[clo[i]] then exit(false);
	exit(true);
end;

begin
	assign(input,'lamps.in');
	reset(input);
	assign(output,'lamps.out');
	rewrite(output);
	readln(n);
	readln(ci);
	ci:=((ci-1) mod 4)+1;
	read(x);
	l1:=0;
	while x<>-1 do
	begin
		inc(l1);
		bright[l1]:=x;
		read(x);
	end;
	l2:=0;
	read(x);
	while x<>-1 do
	begin
		inc(l2);
		clo[l2]:=x;
		read(x);
	end;
	m:=0;
	for a:=0 to 2 do
		for b:=0 to 2 do
			for c:=0 to 2 do
				for d:=0 to 2 do
				begin
					m:=0;
					fillchar(f,sizeof(f),true);
					if (a=1) or (a=2) then 
					begin
						if a<>2 then change1;
						m:=m+a;
					end;
					if (b=1) or (a=2) then 
					begin
						if a<>2 then change2;
						m:=m+b;
					end;
					if (c=1) or (c=2) then 
					begin
						if c<>2 then change3;
						m:=m+c;
					end;
					if (d=1) or (d=2) then 
					begin
						if c<>2 then change4;
						m:=m+d;
					end;
					if (m=ci) and judge and can then
					begin
						inc(k);
						for i:=1 to n do
							if f[i] then ans[k,i]:=1
							else ans[k,i]:=0;
					end;
				end;
	//dfs(1);
	if k<>0 then qsort(1,k);
	for i:=1 to k do
	begin
		for j:=1 to n do
			write(ans[i,j]);
		writeln;
	end;
	if k=0 then writeln('IMPOSSIBLE');
	close(input);
	close(output);
end.