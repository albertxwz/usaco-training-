{
ID:10179811
PROG:ariprog
LANG:PASCAL
#FILE
}


var
  arith,tol:array[1..10000]of longint;
  flag:array[0..1250000]of boolean;
  n,m,i,j,len,lena,k:longint;

procedure swap(var x:longint;var y:longint);
var
  temp:longint;
begin
  temp:=x;
  x:=y;
  y:=temp;
end;

{function judge(x,y:longint):boolean;
begin
  if tol[x]<tol[y] then exit(true);
  if(tol[x]=tol[y])and(arith[x]<arith[y]) then exit(true);
  exit(false);
end;}

procedure qsort(h,t:longint);
var
  ma,mb,i,j:longint;
begin
  mb:=tol[(h+t) div 2];
  ma:=arith[(h+t) div 2];
  i:=h;
  j:=t;
  repeat
    while (tol[i]<mb) or ((tol[i]=mb)and(arith[i]<ma)) do inc(i);
	while (tol[j]>mb) or ((tol[j]=mb)and(arith[j]>ma)) do dec(j);
	if i<=j then
	begin
	  swap(arith[i],arith[j]);
	  swap(tol[i],tol[j]);
	  inc(i);
	  dec(j);
	end;
  until i>j;
  if h<j then qsort(h,j);
  if i<t then qsort(i,t);
end;

function pd(a,b:longint):boolean;
var
  i:longint;
begin
  for i:=1 to n-1 do
    if flag[a+i*b]=false then exit(false);
  exit(true);
end;

begin
  assign(input,'ariprog.in');
  reset(input);
  assign(output,'ariprog.out');
  rewrite(output);
  readln(n);
  readln(m);
  fillchar(flag,sizeof(flag),false);
  for i:=0 to m do
    for j:=0 to m do
	  flag[i*i+j*j]:=true;
  len:=0;
  for i:=0 to m*m do //枚举开头
  begin
    if flag[i]=false then continue;
    for j:=1 to trunc((m*m+m*m-i)/n)+m do //枚举公差,a+n*b>m*m+m*m b>(m*m+m*m-a)/n
	begin
	  if flag[i+j]=false then continue;
	  if pd(i,j) then
	  begin
	    inc(len);
	    arith[len]:=i;
		tol[len]:=j;
	  end;
	end;
  end;
  if len=0 then writeln('NONE')
  else begin
    qsort(1,len);
	for i:=1 to len do
	  writeln(arith[i],' ',tol[i]);
  end;
  close(input);
  close(output);
end.
