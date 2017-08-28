{
ID:10179811
PROG:crypt1
LANG:PASCAL
#FILE
}

var
  a:array[1..5] of integer;
  flag:array[1..9] of boolean;
  i,total,x,n:longint;

//判断结果是否符合题意
function judgem:boolean;
var
  i,a1,a2,x:longint;
begin
  a1:=0;
  a2:=0;
  for i:=1 to 3 do
    a1:=a1*10+a[i];
  a2:=a[4];
  a2:=a2*10+a[5];
  x:=a1*a[4];
  if x div 1000<>0 then exit(false);
  while x<>0 do
  begin
    if (x mod 10=0) or (flag[x mod 10]=false) then exit(false);
    x:=x div 10;
  end;
  x:=a1*a[5];
  if x div 1000<>0 then exit(false);
  while x<>0 do
  begin
    if (x mod 10=0) or (flag[x mod 10]=false) then exit(false);
    x:=x div 10;
  end;
  x:=a1*a2;
  if x div 10000<>0 then exit(false);
  while x<>0 do
  begin
    if (x mod 10=0) or (flag[x mod 10]=false) then exit(false);
    x:=x div 10;
  end;
  judgem:=true;
end;

procedure dfs(i:longint);
var
  j:longint;
begin
  if i=6 then
  begin
    if judgem then inc(total);
	exit;
  end;
  for j:=1 to 9 do
    if flag[j] then
	begin
	  a[i]:=j;
	  dfs(i+1);
	end;
end;

begin
  assign(input,'crypt1.in');
  assign(output,'crypt1.out');
  reset(input);
  rewrite(output);
  readln(n);
  fillchar(flag,sizeof(flag),false);
  for i:=1 to n do
  begin
    read(x);
	flag[x]:=true;
  end;
  total:=0;
  dfs(1);
  writeln(total);
  close(input);
  close(output);
end.
