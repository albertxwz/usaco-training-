{
ID:1017981911
PROG:frac1
LANG:PASCAL
#FILE
}

var
  a,b:array[1..10000] of longint;
  frac:array[1..100000] of real;
  i,j,n,k:longint;
  
function judge(a,b:longint):boolean;		//判断a和b是否互素，辗转相除法（递归）
begin
  if b=1 then exit(true)
  else begin
    if a mod b = 0 then exit(false);
    judge:=judge(b,a mod b);
  end;
end;

procedure swapr(var x:real;var y:real);
var
  temp:real;
begin
  temp:=x;
  x:=y;
  y:=temp;
end;

procedure swapl(var x:longint;var y:longint);
var
  temp:longint;
begin
  temp:=x;
  x:=y;
  y:=temp;
end;

procedure qsort(h,t:longint);
var
  i,j:longint;
  m:real;
begin
  m:=frac[(h+t) div 2];
  i:=h;
  j:=t;
  repeat
    while frac[i]<m do inc(i);
	while frac[j]>m do dec(j);
	if i<=j then
	begin
	  swapr(frac[i],frac[j]);
	  swapl(a[i],a[j]);
	  swapl(b[i],b[j]);
	  inc(i);
	  dec(j);
	end;
  until i>j;
  if h<j then qsort(h,j);
  if i<t then qsort(i,t);
end;

begin
  assign(input,'frac1.in');
  assign(output,'frac1.out');
  reset(input);
  rewrite(output);
  readln(n);
  k:=1;
  a[k]:=0;
  b[k]:=1;
  frac[k]:=0;
  for i:=1 to n do
    for j:=1 to n do
	  if (j>=i) and judge(j,i) then
	  begin
	    inc(k);
		frac[k]:=i/j;
		a[k]:=i;
		b[k]:=j;
	  end;
  qsort(1,k);
  for i:=1 to k do
    writeln(a[i],'/',b[i]);
  close(input);
  close(output);
end.