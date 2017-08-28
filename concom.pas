{
ID:10179811
PROG:concom
LANG:PASCAL
#FILE
}

var
	num:array[1..100] of longint;
	t:array[1..100,1..100] of longint;
	f:array[1..100,1..100] of boolean;
	h,s:array[1..10000] of longint;
	v,i,j,k:longint;
	
function judge(x,y:longint):boolean;
var
	sum1,sum2,i:longint;
begin
	if f[x,y] then exit(false);
	//if (t[x,y]=t[y,x]) and (t[x,y]<>0) then exit(true);
	if t[x,y]>50 then exit(true);
	sum1:=t[x,y];
	for i:=1 to v do
		if f[x,num[i]] then
		begin
			sum1:=sum1+t[num[i],y];
			if sum1>50 then 
			begin
				t[x,y]:=sum1;
				exit(true);
			end;
		end;
	{ sum2:=t[y,x];
	for i:=1 to v do
		if f[y,num[i]] then
			sum2:=sum2+t[num[i],x];
	if sum1=sum2 then exit(true); }
	exit(false);
end;

procedure swap(var x:longint;var y:longint);
var
	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;

procedure qsort(head,tail:longint);
var
	i,j,m1,m2:longint;
begin
	m1:=h[(head+tail) div 2];
	m2:=s[(head+tail) div 2];
	i:=head;
	j:=tail;
	repeat
		while (h[i]<m1) or ((h[i]=m1) and (s[i]<m2)) do inc(i);
		while (h[j]>m1) or ((h[j]=m1) and (s[j]>m2)) do dec(j);
		if i<=j then
		begin
			swap(h[i],h[j]);
			swap(s[i],s[j]);
			inc(i);
			dec(j);
		end;
	until i>j;
	if head<j then qsort(head,j);
	if i<tail then qsort(i,tail);
end;

procedure scanner;
var
	flag:array[1..100] of boolean;
	i,j,x,y,n:longint;
begin
	readln(n);
	fillchar(flag,sizeof(flag),false);
	for i:=1 to n do
	begin
		read(x,y);
		flag[x]:=true;
		flag[y]:=true;
		read(t[x,y]);
	end;
	v:=0;
	for i:=1 to 100 do
		if flag[i] then
		begin
			inc(v);
			num[v]:=i;
		end;
end;

begin
	assign(input,'concom.in');
	reset(input);
	assign(output,'concom.out');
	rewrite(output);
	
	fillchar(f,sizeof(f),false);
	fillchar(t,sizeof(t),0);
	scanner;
	
	for i:=1 to v do
	begin
		j:=1;
		while j<=v do
		begin
			if (num[i]<>num[j]) and judge(num[i],num[j]) then
			begin
				f[num[i],num[j]]:=true;
				inc(k);
				h[k]:=num[i];
				s[k]:=num[j];
				j:=0;
			end;
			inc(j);
		end;
	end;
	if k<>0 then 
	begin
		qsort(1,k);
		for i:=1 to k do	writeln(h[i],' ',s[i]);
	end;
	
	close(input);
	close(output);
end.
