{
ID:1017981911
PROG:pprime
LANG:PASCAL
#FILE
}

var
  //su:array[2..100000000]of boolean;
  su:array[1..100000]of longint;
  a,b,i,j,n,k:longint;
  s,ss:string;

{function palinnum(n:longint):boolean; //判断回文数
var
  i,j:longint;
  s:string;
begin
  str(n,s);
  i:=1;
  j:=length(s);
  while (i<j) and (s[i]=s[j]) do
  begin
    inc(i);
	dec(j);
  end;
  if s[i]<>s[j] then exit(false)
  else exit(true);
end;}

procedure qsort(h,t:longint);
var
  i,j,m,tmp:longint;
begin
  m:=su[(h+t) div 2];
  i:=h;
  j:=t;
  repeat
    while su[i]<m do inc(i);
	while su[j]>m do dec(j);
	if i<=j then
	begin
	  tmp:=su[i];
	  su[i]:=su[j];
	  su[j]:=tmp;
	  inc(i);
	  dec(j);
	end;
  until i>j;
  if h<j then qsort(h,j);
  if i<t then qsort(i,t);
end;

function prime(n:longint):boolean;
var
  i:longint;
begin
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then exit(false);
  exit(true);
end;

begin
  assign(input,'pprime.in');
  reset(input);
  assign(output,'pprime.out');
  rewrite(output);
  
  readln(a,b);
  
  //暴力解题，超时
  {i:=a;
  if i mod 2=0 then i:=i+1;
  while i<=b do
  begin
    if ((i=5)or(i mod 5<>0))and(i mod 3<>0)and(palinnum(i) and prime(i)) then writeln(i);
	i:=i+2;
  end;}
	  
  //产生回文数，再判断是否为素数
  k:=1;
  su[k]:=11;
  for i:=5 to 10000 do
  begin
    str(i,s);
	str(i,ss);
	if (i>5)and(s[1]='5')or(s[1]='2') then continue;	//如果它首位是5，那么产生的回文数也会是5（不是素数）首位为2的也是如此；
    for j:=length(s)-1 downto 1 do
      ss:=ss+s[j];	
	val(ss,n);
	if prime(n) then
	begin
	  inc(k);
	  su[k]:=n;
	end;
  end;
  qsort(1,k);
  for i:=1 to k do
  begin
    if su[i]>b then break;
    if su[i]>=a then 
     writeln(su[i]);  
  end;
  
  close(input);
  close(output);
end.